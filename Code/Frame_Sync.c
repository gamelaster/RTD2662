#define __FRAMESYNC__

#include "Header\Frame_Sync.h"
#include "Header\Lcd_func.h"
#include "Header\Access.h"
#include "Header\Main_def.h"
#include "Header\Config.h"
#include "Header\Lcd_main.h"
#include "Header\LCD_OSD.h"



        /////////////////////////
        // Frame-Sync Detector //
        /////////////////////////
bit Frame_Sync_Detector(void)
{
        if (bPower_Status && bStable && MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
        {
            if (bFrameSync)
            {
                RTDRead(STATUS1_1F, 1, N_INC);
                ucStatus    |= (Data[0] >> 6);

				if(Data[0])
					RTDSetByte(STATUS1_1F,0x00);

                if (Data[0] & 0xc0)
                {
                    ucSyncErrorCnt  += 1;
#if (RTDDEBUG)
                    if (0xff > ucDebug)     ucDebug ++; 
#endif
                }

//#if (DISP_BIT == DISP_18BIT)
//                else if (Data[0] & 0x04)
//                {
//                    bDitherToggle   = !bDitherToggle;

//                    if (bDitherToggle)
//                    {
//                        bDitherTable    = !bDitherTable;
//                        WriteDither(bDitherTable ? DITHER_1 : DITHER_2);
//                    }
//                }
//#endif

            }

            if (SYNC_FAIL_TIMES >= ucSyncErrorCnt)
            {
                RTDRead(STATUS0_01, 1, N_INC);
                ucStatus    |= (Data[0] & 0xfc);


				if(Data[0])
					RTDSetByte(STATUS0_01,0x00); //if some event happened, write once to clear status
               
                if (Data[0] & 0x60)     ucSyncErrorCnt  += (SYNC_FAIL_TIMES + 1);

                if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07))
                {
                    if (Data[0] & 0x80)
                    {
                        ucSyncErrorCnt  += 1;
#if (RTDDEBUG)
                        if (0xff > ucDebug)     ucDebug ++;                       
#endif
                    }
                    else
                    {

#if(TUNE_APLL)

                  RTDSetBit(DV_TOTAL_STATUS_3D, 0x7f, 0x20); //Enable PE Max Measurement
				  Delay_Xms(1);
	              RTDRead(DV_TOTAL_STATUS_3D, 1, N_INC);
	              ucPE_Max = Data[0] & 0x1f;
				  if((ucPE_Max > 0x10) && (ucPE_Level == 0))
				  {
				      ucPE_Level = 1;
					  Adjust_I_Code();
                      if((ucI_Code & 0x80) == 0x80)
                         RTDSetBit(I_CODE_MB_CA,0xdf,0x20);  //Set the I_Code[13] to 1;
                      else
                         RTDSetBit(I_CODE_MB_CA,0xdf,0x00);  //Set the I_Code[13] to 0;
                      
                      ucI_Code = ucI_Code & 0x7f;
	                  RTDSetByte(I_CODE_LB_C9,0x1c | ((ucI_Code & 0x07) << 5));
	                  RTDSetBit(I_CODE_MB_CA,0xfc,0x04 | ((ucI_Code & 0x18) >> 3));

					  RTDSetBit(DV_TOTAL_STATUS_3D, 0xdf, 0x00);//Disable PE Max Measurement
                      RTDSetByte(DV_TOTAL_STATUS_3D,0x40); //clear PE Max value
					  ucPE_Max = 0;
				  }
				  
#endif
                    }
                }
            }

            if (SYNC_FAIL_TIMES < ucSyncErrorCnt)
            {
                Reset_Mode();

                Set_Task(STATE_MODECHANGE);     // Notify Task State Machine

                bNotify_Timer0_Int  = 0;

                return _TRUE;
                //continue;                       // leave current iteration.
            }

            if (bNotify_Timer0_Int && MODE_DETECT_FREQ == ucModeCnt)
            {
                if (ucSyncErrorCnt)     ucSyncErrorCnt  -= 1;

            }
        }
        return _FALSE;
}

/////////////////////////////////////////////////////////////////////////////////
// FrameSync fine-tune routines
/////////////////////////////////////////////////////////////////////////////////
void AbortSync(void)
{
    Data[0] = 5;
    Data[1] = Y_INC;
    Data[2] = DH_TOTAL_22;
    Data[3] = (unsigned char)usDH_Total;
    Data[4] = (unsigned char)(usDH_Total >> 8);
    Data[5] = 0;
    RTDWrite(Data);

    RTDSetBit(DV_TOTAL_H_2E, 0x07, 0x00);
}

unsigned char TestSync(unsigned int offset)     // 0 - Success; Otherwise - Fail
{

	RTDSetByte(DCLK_OFFSET_LSB_9A,(unsigned char)offset);
	RTDSetBit(DCLK_OFFSET_MSB_9B,0xf0,(unsigned char)((offset >> 8) & 0x0f) | 0x20);

    //RTDSetBit(DV_TOTAL_H_2E, 0x07, fine & 0xf8);

    Wait_For_Event(EVENT_DVS);          // Wait for Frame End
    //Delay_Xms(10);

	RTDSetByte(STATUS0_01,0x00);

    Wait_For_Event(EVENT_DVS);          // Wait for Frame End

    //RTDSetByte(STATUS0_01,0x00);////
/*
    if (SOURCE_VGA != (stGUD1.INPUT_SOURCE & 0x07))
    {
        Wait_For_Event(EVENT_DVS);      // Wait for Frame End
    }
*/
    Wait_For_Event(EVENT_DVS);          // Wait for Frame End

	//RTDSetByte(STATUS0_01,0x00);////
	//Delay_Xms(10);

    RTDRead(STATUS0_01, 1, N_INC);      // Get status


	if(Data[0])
	    RTDSetByte(STATUS0_01,0x00);


    if (Data[0] & 0x60) // Mode Changed
    {
        AbortSync();
        return 1;
    }

    Data[0] &= 0x03;

    return 0;   // Success
}



//Returned value
// 0 : Succeed(Frame-sync settings returned in Data[3] and Data[4])
// 1 : Fail
// 2 : Abort
#define Offset_Step      32//16 //This value should better larger then 16
unsigned char Frame_Sync(void)
{
   unsigned int idata usBuffer,usDelta;
   unsigned char idata  ucFine,ucTemp=0;

#if(FIX_LAST_DHT)
   unsigned int idata usMax_Last_Line,usMin_Last_Line;
#endif



   RTDRead(DCLK_OFFSET_LSB_9A , 2, Y_INC);
   Data[2] = Data[1] & 0x0f;
   Data[3] = Data[0];
   usBuffer = ((unsigned int*)Data)[1];//get the DCLK offset
   //usDelta = ((unsigned int*)Data)[1];//get the DCLK offset
   usDelta = usBuffer;
//   ucFine = 0;

   if(((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) || ((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_DVI))
   {

   //while(usDelta < Offset_Step * 14) 
   while(usBuffer < (1228 + 14 * Offset_Step))
   //while(usBuffer < (1228 + 24 * Offset_Step))	//eric 0729 issue: dvi flash
   {
	   RTDRead(DPLL_M_D1,2,Y_INC);
	   RTDSetByte(DPLL_M_D1,Data[0]+1);
	   RTDSetByte(DPLL_N_D2,Data[1]);
//     Forster :
//     if the DCLK offset too small, then set the M_Code = M_Code + 1
//     And reculculate the offset
//     Original formula:
//     24.576M * M/N - 24.576M*M/N/2^15*old_offset = 24.576M*(M+1)/N - 24.576M*(M+1)/N/2^15*new_offset
//     => new_offset = (2^15 + M*old_offset) / (M+1);
	   usBuffer = (unsigned int)((unsigned long)(32768 + (unsigned long)(Data[0] + 2) * usBuffer)/(unsigned long)(Data[0] + 3));
	   //usBuffer = (32768 + (Data[0] + 2) * usDelta)/(Data[0] + 3);
	   usDelta = usBuffer;
       
   }


/*   //Below spend more code size
   ((unsigned int*)Data)[1] = 1228 + 14 * Offset_Step;

   if(usBuffer < ((unsigned int*)Data)[1])
   {
	   RTDRead(DPLL_M_D1,1,N_INC);
	   
	   ucFine =(unsigned char)((unsigned long)(Data[0] + 2) * (((unsigned int*)Data)[1] - usBuffer)/(unsigned long)(32768 - ((unsigned int*)Data)[1]));

	   usBuffer = (unsigned int)(((unsigned long)32768 * (ucFine + 1) + (unsigned long)(Data[0] + 2) * usBuffer)/(unsigned long)(Data[0] + 2 + (ucFine + 1)));

	   RTDSetByte(DPLL_M_D1,Data[0] + ucFine + 1);
	   RTDSetBit(DPLL_N_D2,0xf8,USER_MODE_NCODE - 2);
   }

   usDelta = usBuffer;
*/   
   usDelta -= 128; //Clk offset fine-tune
   }

   usBuffer = usDelta;
  

   for(ucFine =0;ucFine < 14;ucFine++)
   {
	   if (TestSync(usDelta))    return 2;

	   if(Data[0] & 0x03)
	   {
		   usDelta = (Data[0] & 0x02) ? usDelta - Offset_Step : usDelta + Offset_Step;
		   ucTemp += 1;
	   }
	   else if((Data[0] & 0x03) == 0)
		   break;
   }

   if(Data[0] & 0x03)
          return 1;   // Frame sync fail  
#if(SPREAD_SPECTRUM)
   else if(usDelta < usBuffer) //Get more margin of Framesync
   {
	   //usDelta -= 2;
	   if(TestSync(usDelta - 4))    return 2;

	   if(Data[0] & 0x03)
	       TestSync(usDelta);
	   else
	       usDelta -= 2;
	   
   }
   else//(usDelta > usBuffer) //Get more margin of Framesync
   {
	   //usDelta += 2;
	   if(TestSync(usDelta + 4))    return 2;

	   if(Data[0] & 0x03)
	       TestSync(usDelta);
	   else 
	       usDelta += 2;
   }
#endif   

//   ucDebug_Value0 = ucTemp;
#if(FIX_LAST_DHT)

   //Disable spread spectrum
#if(SPREAD_SPECTRUM)
    RTDSetBit(SPREAD_SPECTRUM_99,0x0f,0x00);
	RTDSetBit(DCLK_OFFSET_MSB_9B,0xff,0x20);
#endif
 
       //Read the last line information , read back data equal to half last line length
	   RTDRead(LAST_LINE_H_2C, 1, N_INC);
       usMax_Last_Line = (unsigned int)(Data[0] & 0xf8) << 2;

       RTDRead(LAST_LINE_L_26, 1, N_INC);
       usMax_Last_Line = usMax_Last_Line + (Data[0] / 8);
        
	    
	   	
	   //Read the last line information when frequency offset set one more step
	   RTDSetByte(DCLK_OFFSET_LSB_9A,(unsigned char)(usDelta + 1));
	   RTDSetBit(DCLK_OFFSET_MSB_9B,0xf0,(unsigned char)(((usDelta + 1) >> 8) & 0x07) | 0x20);

	   Wait_For_Event(EVENT_IVS);
	   Wait_For_Event(EVENT_IVS);

	   RTDRead(LAST_LINE_H_2C, 1, N_INC);
       usMin_Last_Line = (unsigned int)(Data[0] & 0xf8) << 2;
       RTDRead(LAST_LINE_L_26, 1, N_INC);
       usMin_Last_Line = usMin_Last_Line + (Data[0] / 8);

	    

	   //Calculate the difference of last line when increase one offset step
	   if(usMin_Last_Line < usMax_Last_Line)
		   usMin_Last_Line = usMax_Last_Line - usMin_Last_Line;
	   else
		   usMin_Last_Line = usDH_Total/2 - usMin_Last_Line + usMax_Last_Line;

	   if(FIX_LAST_DHT > usMax_Last_Line)
	   {
           if((FIX_LAST_DHT - usMax_Last_Line) > (usDH_Total / 4)) 
		   {   //decrease the last line, decrease the DClk
			   Data[0] = (unsigned int)(usMax_Last_Line + (usDH_Total / 2 - FIX_LAST_DHT)) / usMin_Last_Line;
			   usDelta = usDelta + Data[0];
		   }
		   else
		   {   //increase the last line, increase the DClk
			   Data[0] = (unsigned int)(FIX_LAST_DHT - usMax_Last_Line) / usMin_Last_Line; 
			   usDelta = usDelta - (Data[0] + 1);
		   }
	   }
	   else
	   {
		   if((usMax_Last_Line - FIX_LAST_DHT) > (usDH_Total / 4)) 
		   {   //increase the last line, increase the DClk
			   Data[0] = (unsigned int)(FIX_LAST_DHT + (usDH_Total / 2 - usMax_Last_Line)) / usMin_Last_Line;
			   usDelta = usDelta - (Data[0] + 1);
		   }
		   else
		   {   //decrease the last line, decrease the DClk
			   Data[0] = (usMax_Last_Line - FIX_LAST_DHT) / usMin_Last_Line; 
			   Data[11] = Data[0];
			   usDelta += Data[0];
			   
		   }
	   }


	 //Enable the apread spectrum again
#if (SPREAD_SPECTRUM)
    RTDSetBit(SPREAD_SPECTRUM_99,0x0f,(DCLK_SPRED_RANGE << 4));
    if(TestSync(usDelta + DCLK_OFFSET[DCLK_SPRED_RANGE]))    
	   return 2;
	
	if(Data[0] & 0x03)
	{
       if(TestSync((Data[0] & 0x02) ? (usDelta + DCLK_OFFSET[DCLK_SPRED_RANGE] - 1)
	                                : (usDelta + DCLK_OFFSET[DCLK_SPRED_RANGE] + 1)))  //Fine tune Dclk offset 
	      return 2;
	   else
	   {
	          if(Data[0] & 0x03)
			     return 1; //frame sync fail!
			  else
                 return 0;
	   }
	}
#else
    if(TestSync(usDelta))    return 2;
#endif


	   RTDSetByte(FX_LST_LEN_L_59,(unsigned char)(FIX_LAST_DHT << 1));
	   RTDSetBit(FX_LST_LEN_H_5A,0x08,(unsigned char)((FIX_LAST_DHT >> 7) & 0x07));

        RTDRead(DV_ACT_END_34, 2, Y_INC);
        Data[2] = Data[1] & 0x07;
        Data[3] = Data[0];

        Data[4] = ((Data[1] & 0xf0) >> 4); //Measure result of last 16 line of DVTotal, including the un-complete last line
    
        // Get Output_Active Height
        ((unsigned int *)Data)[1]   = ((unsigned int *)Data)[1] - DV_ACT_STA_POS;

        // Original Idea :
        // DVTotal  = Output_Active_Line * (Input_Total_Line / Input_Active_Line) 
        usDelta = (unsigned long)usVsync * ((unsigned int *)Data)[1] / usIPV_ACT_LEN;	
        usDelta = (usDelta & 0xfff0 | Data[4]); 

		RTDSetByte(FIX_DVTOTAL_LSB_97,(unsigned char)usDelta);
		RTDSetByte(FIX_DVTOTAL_MSB_98,(unsigned char)((usDelta >> 8) & 0x07));

        RTDSetBit(SPREAD_SPECTRUM_99,0xfc,0x03); //Frequency Synthesis select N = 4
		RTDSetBit(DCLK_OFFSET_MSB_9B,0xff,0x20);

	
//	    RTDSetBit(FX_LST_LEN_H_5A,0xff,0x10); //Enable the Fixed DVTOTAL & Last Line Lenghth Fucntion
//	    RTDSetBit(FX_LST_LEN_H_5A,0xff,0x10); //Enable the Fixed DVTOTAL & Last Line Lenghth Fucntion
	   
	   return 0;
#else

#if (SPREAD_SPECTRUM)
    RTDSetBit(SPREAD_SPECTRUM_99,0x0f,(DCLK_SPRED_RANGE << 4));
    if(TestSync(usDelta + DCLK_OFFSET[DCLK_SPRED_RANGE]))    
	   return 2;
	
	if(Data[0] & 0x03)
	{
       if(TestSync((Data[0] & 0x02) ? (usDelta + DCLK_OFFSET[DCLK_SPRED_RANGE] - 1)
	                                : (usDelta + DCLK_OFFSET[DCLK_SPRED_RANGE] + 1)))   //Fine tune Dclk offset 
	   	      return 2;
	   else 
	   {
	          if(Data[0] & 0x03)
			     return 1; //frame sync fail!
			  else
                 return 0;
	   }
	   
	}
#else
       return 0;   
#endif
       return 0;
#endif

}




void Adjust_I_Code(void)
{
   // Calculate the IHF in KHz
	   ((unsigned int*)Data)[0] = 24576/usHsync; //Input Horizontal Frequency
	   //Formula: I_Correction = CE * 2 * Fav(253687) * 100 / IHF / 2^(I_Code - 34)
	   //Data[2] : I_Code = 14; I_Code[13] = 0;

	   ucI_Code = 14;
	   Data[2] = ((unsigned long)ucCE_Value * 50737400 / (unsigned long)((unsigned int*)Data)[0]) >> 20;
	   Data[3] = (I_Correction == 0) ? (ucPE_Level ? (Correct_Amount - ucP_Corr) : ((ucP_Corr >> 2) + 10)) : 
                                         I_Correction;

	   while(1)
	   {
		   
		   if(Data[2] > Data[3])
		   {
			   Data[2] = Data[2] >> 1;
			   ucI_Code -= 1;

			   if(Data[2] <= Data[3])
				   break;
		   }
		   else
		   {
			   if((Data[2] << 1) > Data[3])
				   break;
			   else
			   {
				   Data[2] = Data[2] << 1;
				   ucI_Code += 1;
			   }
		   }
	   }
//             ucDebug_Value1 = ucP_Corr;
	
	   
       if((unsigned char)((unsigned int)Data[2]*3/2) <= Data[3]) // Judge if I_Code[13] set to 1 will more close to 155
	   {	         
             ucI_Code |= 0x80;
//			 ucDebug_Value2 = ((unsigned char)((unsigned int)Data[2]*3) >> 1);   
	   }
	   else
	   {
//	   		 ucDebug_Value2 = Data[2];   
		}
		

}
