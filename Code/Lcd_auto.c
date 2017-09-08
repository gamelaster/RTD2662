#define __AUTO__

#include "reg52.h"

#include "Header\MAIN_DEF.h"
#include "Header\ACCESS.H"
#include "Header\LCD_MAIN.H"
#include "Header\CONFIG.H"
#include "Header\LCD_FUNC.H"
#include "Header\LCD_AUTO.H"
#include "Header\LCD_OSD.H"


void Wait_Finish(void)
{
    unsigned char   Wait_Time_Cnt, IVS_Event;

	RTDSetByte(STATUS0_01, 0x00);  // Clear status  
    RTDSetByte(STATUS1_1F, 0x00);  // Clear status

    
    Wait_Time_Cnt   = 60;           // Auto-Phase timeout 60ms
    IVS_Event       = 25;           // IVS timeout 25ms 
    do
    {  
         Delay_Xms(1);
     
/*
#if(AS_NON_FRAMESYNC == 0)

         RTDRead(STATUS0_01, 1, N_INC);  // Get status        

        if (Data[0] & 0x63)
        {

#if(MCU_TYPE == MCU_WINBOND)
        bLIGHT_PWR  = LIGHT_OFF;
#else
        MCU_WriteBacklightPower(LIGHT_OFF);
#endif

            RTDCodeW(FreeV);

            Data[0] = ERROR_INPUT;
            RTDSetByte(STATUS0_01, 0x00);  // Clear status  

            return;
			
        }
#endif
      //Delay_Xms(2);
#if(MCU_TYPE == MCU_MTV512)
      RTDSetByte(STATUS1_1F, 0x00);  // Clear status
#endif

#if(AS_NON_FRAMESYNC == 0 || AS_DV_TOTAL == 0)
        RTDRead(STATUS1_1F, 1, N_INC);  // Get status
        

        if ((Data[0] & (EVENT_UNDERFLOW | EVENT_OVERFLOW)) || (0 == --IVS_Event))
        {
         
#if(MCU_TYPE == MCU_WINBOND)
        bLIGHT_PWR  = LIGHT_OFF;
#else
        MCU_WriteBacklightPower(LIGHT_OFF);
#endif
            RTDCodeW(FreeV);

            Data[0] = ERROR_INPUT;
			RTDSetByte(STATUS1_1F,0x00); //Event happened, write once to clear the status

            return;
        }
        else if (Data[0] & (EVENT_IVS | EVENT_IEN_START))
        {
            IVS_Event   = 25;       // IVS timeout 25ms 
			RTDSetByte(STATUS1_1F,0x00); //Event happened, write once to clear the status
        }
		
#endif
*/
        RTDRead(AUTO_ADJ_CTRL_7F, 1, N_INC);
    }
    while ((Data[0] & 0x01) && (--Wait_Time_Cnt));
    
    RTDRead(STATUS0_01, 1, N_INC);  // Get status


	if(Data[0])
		RTDSetByte(STATUS0_01,0x00); //Event happened, write once to clear the status


    // Return non-zero value in Data[0] if :
    // 1. IVS or IHS changed
    // 2. Buffer underflow or overflow
    // 3. Auto-Phase Tracking timeout
	
    Data[0] = (Data[0] & 0x63) ? ERROR_INPUT : (0 == Wait_Time_Cnt) ? ERROR_TIMEOUT : ERROR_SUCCEED;
}

#if(HARDWARE_AUTO)
void Wait_For_IVS(void)
{
   unsigned char t;

	t = 50;

	RTDSetByte(0x1f,0x00);
   	do
	{
	   	RTDRead(0x1f, 1, Y_INC);
		Data[0] = Data[0] & EVENT_IVS;
		//t--;
		Delay_Xms(1);
   	}while((Data[0] == 0) && (t--));
}
#endif

//--------------------Measure Vertical Position---------------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//
unsigned char Measure_PositionV(unsigned char NM_V)
{
    unsigned int    usLBound, usRBound;

    RTDRead(MEAS_HI_51, 0x02, Y_INC);
    Data[2] = Data[1] & 0x0f;
    Data[3] = Data[0];

    usRBound    = usADC_Clock + (unsigned int)stMUD.CLOCK - 128;
    usLBound    = (unsigned long)usRBound * ((unsigned int *)Data)[1] / usStdHS;

    // Original formula : 
    // usRBound    = usRBound - 2 - (PROGRAM_HDELAY - MEASURE_HDEALY) - (stMUD.H_POSITION - ucH_Min_Margin);
    // usLBound    = usLBound + 20 - (PROGRAM_HDELAY - MEASURE_HDEALY) - (stMUD.H_POSITION - ucH_Min_Margin);

    usRBound    = usRBound - 2 + MEASURE_HDEALY - PROGRAM_HDELAY + ucH_Min_Margin - stMUD.H_POSITION;
    usLBound    = usLBound + 20 + ucH_Min_Margin + MEASURE_HDEALY;
    usLBound    = usLBound > ((unsigned int)stMUD.H_POSITION + PROGRAM_HDELAY) ? (usLBound - PROGRAM_HDELAY - stMUD.H_POSITION) : 1;

    NM_V        = NM_V & 0xfc;

    Data[0]     = 6;
    Data[1]     = Y_INC;
    Data[2]     = H_BND_STA_L_75;
    Data[3]     = (unsigned char)usLBound;
    Data[4]     = (unsigned char)usRBound;
    Data[5]     = ((unsigned char)(usLBound >> 4) & 0x70) | ((unsigned char)(usRBound >> 8) & 0x0f);    
    Data[6]     = 8;
    Data[7]     = Y_INC;
    Data[8]     = MARGIN_R_7B;
    Data[9]     = NM_V;
    Data[10]    = NM_V | PIXEL_1;
    Data[11]    = NM_V;
    Data[12]    = 0x00;
    Data[13]    = 0x01;
    Data[14]    = 0;
    RTDWrite(Data);
    
	Wait_Finish();


    if (ERROR_SUCCEED != Data[0])   return Data[0];

    RTDRead(VER_START_80, 4, Y_INC);

    // Translate byte order : RTD little indian -> 8051 big indian
    Data[6] = Data[1] & 0x0f;
    Data[7] = Data[0];
    Data[8] = Data[3] & 0x0f;
    Data[9] = Data[2];

    // V Start/End should subtract 1
    usVer_Start     = ((unsigned int *)Data)[3] ? ((unsigned int *)Data)[3] - 1 : 0;
    usVer_End       = ((unsigned int *)Data)[4] ? ((unsigned int *)Data)[4] - 1 : 0;

    // Check all black
    if (0x0000 == usVer_End)    return  ERROR_NOTACTIVE;

/*
    // Issac 2002/10/15
    // To prevent from noise induced by VSYNC
    if (usVer_End > (usVer_Start + usIPV_ACT_LEN - 1))
    {
        usVer_End   = usVer_Start + usIPV_ACT_LEN - 1;

        ((unsigned int *)Data)[4]   = usVer_End;
    }
*/
	if ((9 - PROGRAM_VDELAY) > usVer_Start)
	{
	    ((unsigned int *)Data)[3]	= 9 - PROGRAM_VDELAY;
	}
	else
	{
        // To prevent from noise induced by VSYNC
        if (usVer_End > (usVer_Start + usIPV_ACT_LEN - 1))
        {
            usVer_End   = usVer_Start + usIPV_ACT_LEN - 1;

            ((unsigned int *)Data)[4]   = usVer_End;
        }
	}

    // Update auto-tracking window vertical range
    Data[0] = 6;
    Data[1] = Y_INC;
    Data[2] = V_BND_STA_L_78;
    Data[3] = Data[7];    
    Data[4] = Data[9];
    Data[5] = (Data[6] << 4) + Data[8];
    Data[6] = 0;
    RTDWrite(Data);

    return ERROR_SUCCEED;
}

//--------------------Measure Horizontal Position-------------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//
unsigned char Measure_PositionH(unsigned char NM_H)
{
    unsigned int    usLBound, usRBound;

    RTDRead(MEAS_HI_51, 0x02, Y_INC);
    Data[2] = Data[1] & 0x0f;
    Data[3] = Data[0];

    usRBound    = usADC_Clock + (unsigned int)stMUD.CLOCK - 128;
    usLBound    = (unsigned long)usRBound * ((unsigned int *)Data)[1] / usStdHS;

    usRBound    = usRBound - 2 + MEASURE_HDEALY - PROGRAM_HDELAY + ucH_Min_Margin - stMUD.H_POSITION;

    usLBound    = usLBound + 20 + ucH_Min_Margin + MEASURE_HDEALY;
    usLBound    = usLBound > ((unsigned int)stMUD.H_POSITION + PROGRAM_HDELAY) ? (usLBound - PROGRAM_HDELAY - stMUD.H_POSITION) : 1;

    NM_H        = NM_H & 0xfc;

    Data[0]     = 6;
    Data[1]     = Y_INC;
    Data[2]     = H_BND_STA_L_75;
    Data[3]     = (unsigned char)usLBound;
    Data[4]     = (unsigned char)usRBound;
    Data[5]     = ((unsigned char)(usLBound >> 4) & 0x70) | ((unsigned char)(usRBound >> 8) & 0x0f);    
    Data[6]     = 8;
    Data[7]     = Y_INC;
    Data[8]     = MARGIN_R_7B;
    Data[9]     = NM_H;
    Data[10]    = NM_H;
    Data[11]    = NM_H;
    Data[12]    = 0x00;
    Data[13]    = 0x01;
    Data[14]    = 0;
    RTDWrite(Data);

    Wait_Finish();

    if (ERROR_SUCCEED != Data[0])   return Data[0];

    RTDRead(HOR_START_84, 4, Y_INC);

    // Translate byte order : RTD little indian -> 8051 big indian
    Data[4] = Data[3] & 0x0f;
    Data[5] = Data[2];
    Data[2] = Data[1] & 0x0f;
    Data[3] = Data[0];
    
    if (0x07FF <= ((unsigned int *)Data)[1])     return  ERROR_NOTACTIVE;
    

    RTDRead(VGIP_CTRL_04, 1, N_INC);

    //if (0x14 == (Data[0] & 0x1c))
	if (0x08 == (Data[0] & 0x0c))
    {
        ((unsigned int *)Data)[1]   += 0x03;
        ((unsigned int *)Data)[2]   += 0x03;
    }

/*  
    usH_Start   = MEAS_H_STA_OFFSET < ((unsigned int *)Data)[1] ? ((unsigned int *)Data)[1] - MEAS_H_STA_OFFSET : 0x0000;
    usH_End     = MEAS_H_END_OFFSET < ((unsigned int *)Data)[2] ? ((unsigned int *)Data)[2] - MEAS_H_END_OFFSET : 0x0fff;

    if (0x0000 != usH_Start)    usH_Start   = usH_Start + stMUD.H_POSITION - 128;
    if (0x0fff != usH_End)      usH_End     = usH_End + stMUD.H_POSITION - 128;
*/        

    usH_Start   = (((unsigned int *)Data)[1] + stMUD.H_POSITION) >= (128 + MEAS_H_STA_OFFSET)
                ? (((unsigned int *)Data)[1] + stMUD.H_POSITION) - (128 + MEAS_H_STA_OFFSET) : 0x0000;
    usH_End     = (((unsigned int *)Data)[2] + stMUD.H_POSITION) >= (128 + MEAS_H_END_OFFSET)
                ? (((unsigned int *)Data)[2] + stMUD.H_POSITION) - (128 + MEAS_H_END_OFFSET) : 0x0fff;

    return ERROR_SUCCEED;
}

//---------------Measure Vertical & Horizontal Position-------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//
unsigned char Measure_PositionN(unsigned char NM)
{
    unsigned char Result;
    
    Result  = Measure_PositionV(NM);

    if (ERROR_SUCCEED == Result)    
    {
        Result  = Measure_PositionH(NM);
    }
        
    return Result;
}

/*
//------------------------------------------------------------------//
//                           Auto Clock                             //
//------------------------------------------------------------------//
unsigned char Auto_Clock(void)
{
    unsigned char   Result, Curr_PosH, Curr_PosV, Curr_Clock, Curr_Phase;   
    
    bAutoInProgress = 1;
    
    Curr_PosH   = stMUD.H_POSITION;     // Save current stMUD.H_POSITION
    Curr_PosV   = stMUD.V_POSITION;     // Save current stMUD.V_POSITION
    Curr_Clock  = stMUD.CLOCK;          // Save current stMUD.CLOCK 
    Curr_Phase  = stMUD.PHASE;          // Save current stMUD.PHASE

    if (ucV_Max_Margin < stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = ucV_Max_Margin;
        Set_V_Position();
    }

    RTDCodeW(ADC_DEFAULT);

    ///////////////////////////////
    //   Measure  NOISE_MARGIN   //
    ///////////////////////////////
    Result      = Min_Noise_Margin();   // Data[0] : Noise Margin
    
    if (ERROR_SUCCEED == (Result & 0x80))
    {
        Result  = Data[0];

        stMUD.CLOCK &= 0xfc;    // stMUD.CLOCK must be times of 4

        if (stMUD.CLOCK != Curr_Clock || 28 > stMUD.CLOCK || 228 < stMUD.CLOCK)
        {
            Set_Clock();
        }
        
        ///////////////////////////////
        //       Adjust Clock        //
        ///////////////////////////////
        Result  = Auto_Clock_Do(Result);
        
        if (ERROR_SUCCEED != (Result & 0x80))
        {
            if (stMUD.CLOCK != Curr_Clock)
            {   
                // Fail to find out suitable clock. Restore original clock and H position.
                stMUD.CLOCK         = Curr_Clock;
                stMUD.H_POSITION    = Curr_PosH;

                Set_Clock();
                Set_H_Position();
            }
        }
        else
        {
            if (stMUD.CLOCK != Curr_Clock)
            {
                stMUD.H_POSITION    = usH_Start + 128 + 64 - usIPH_ACT_STA - (stMUD.CLOCK >> 1);

                if (ucH_Max_Margin < stMUD.H_POSITION)
                    stMUD.H_POSITION    = ucH_Max_Margin;
                else if (ucH_Min_Margin > stMUD.H_POSITION)
                    stMUD.H_POSITION    = ucH_Min_Margin;
				
                Set_H_Position();

                Save_MUD(ucMode_Curr);
            }
        }
    }

    // Restore ADC Gain/Offset
    SetADC_GainOffset();
    
    // Restore ADC phase 
    stMUD.PHASE = Curr_Phase;
    Set_Phase(stMUD.PHASE);

    // Restore vertical position
    if (Curr_PosV != stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = Curr_PosV;
        Set_V_Position();
    }

    bAutoInProgress = 0;

    return Result;
}
*/
void Read_Auto_Info(unsigned char index)
{
     if(index == 0) return;

	 RTDRead(AUTO_PHASE0_88, 4, Y_INC);

      Data[index << 2] = Data[3];
      Data[(index << 2) + 1] = Data[2];
      Data[(index << 2) + 2] = Data[1];
      Data[(index << 2) + 3] = Data[0];

}

unsigned char FindColor()
{
unsigned long ulTemp0;
unsigned char ucDetect,ucResult,ucPhase;

RTDSetByte(DIFF_THRED_7E, 0x28);

    ulTemp0     = 0;
    ucDetect    = 0x77;
    do
    {
        ucResult    = COLORS_BLUE;
        ucPhase     = COLORS_BLUE;
        do
        {
            RTDSetByte(MARGIN_B_7D, ucPhase);
            RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);

            Wait_Finish();
            if (ERROR_SUCCEED != Data[0])   return Data[0];

            Read_Auto_Info(1);

            if (ulTemp0 < ((unsigned long *)Data)[1])
            {
                ulTemp0     = ((unsigned long *)Data)[1];
                ucResult    = ucPhase;

                if (0x8000 < ulTemp0)   break;
            }

            if (COLORS_BLUE == ucPhase)
                ucPhase = COLORS_GREEN;
            else if (COLORS_GREEN == ucPhase)
                ucPhase = COLORS_RED;
            else
                break;
        }
        while (1);

        if (0 != ulTemp0 || 0x7b != ucDetect)   break;

        ucDetect    = 0x77;
    }
    while (1);

    return ERROR_SUCCEED;
}
unsigned long GetMaxSum(unsigned char select)
{
   unsigned char ucPhase,ucDetect;
   unsigned long ulTemp0;
   ucPhase = 0; //0,8,16,24
   ulTemp0 = 0;
   Set_Phase(ucPhase);
   ucDetect    = (select == 0) ? 0x77 : 0x7b;
   
#if(HARDWARE_AUTO)

   RTDSetByte(HW_AUTO_PHASE_9E,0x07);  //Step 8 auto phase
   Wait_For_IVS();
   //Wait_For_Event(EVENT_IVS);
   RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);  //Auto start
   //Wait_For_Event(EVENT_IVS);
   Wait_For_IVS();
   for(ucPhase = 0;ucPhase < 4; ucPhase++)
   {
       //Wait_For_Event(EVENT_IVS);
	   Wait_For_IVS();
       Read_Auto_Info(1);

       if(ulTemp0 < ((unsigned long *)Data)[1])
       {
         ulTemp0   = ((unsigned long *)Data)[1] & 0xffffff00;
       }
   }
   RTDSetByte(HW_AUTO_PHASE_9E,0x00);  //Switch back to software auto phase
   Wait_Finish();
   if(ERROR_SUCCEED != Data[0])     return (Data[0] & 0x000000ff);
   
#else
   while(1)
   {
      RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);
      Wait_Finish();
      if (ERROR_SUCCEED != Data[0])   return Data[0];

      Read_Auto_Info(1);

	   if (ulTemp0 < ((unsigned long *)Data)[1])
       {
                ulTemp0     = ((unsigned long *)Data)[1];
       }
	   ucPhase += 0x20;
	   if(ucPhase > 0x60)
	        break;

	   Set_Phase(ucPhase);
	}
#endif
    return ulTemp0;
}
//------------------------------------------------------------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_TOO_SMALL : Measure Result << ACT_WIDTH  //
//                   ERROR_TOO_BIG   : Measure Result >> ACT_WIDTH  //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                                     Process Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//
unsigned char Auto_Clock_Do(unsigned char NM)
{
#if(0)

    unsigned char   ucResult;
    unsigned char   count, delta, stop;    
        
    ///////////////////////////////
    //  Measure (V) Start & End  //
    ///////////////////////////////
    ucResult    = Measure_PositionV(NM);

    if (ERROR_SUCCEED != (ucResult & 0x80))
    {
        if (ERROR_NOTACTIVE == ucResult)
        {
            if (0x80 < stMUD.CLOCK)
            {
                stMUD.CLOCK = 0x80;
                Set_H_Position();
                Set_Clock();
            }
            else
            {
                stMUD.CLOCK = 0x80;
                Set_Clock();
                Set_H_Position();
            }

            ucResult    = Measure_PositionV(NM);
            
            if (ERROR_SUCCEED != (ucResult & 0x80))     return ucResult;
        }
        else
            return ucResult;
    }

    NM      = NM + 0x10;    // See Min_Noise_Margin(). Horizontal Measure Result is the same when applying (NM + 0x10)

    count   = 10;
    do
    {
        ///////////////////////////////
        //  Measure (H) Start & End  //
        ///////////////////////////////
        ucResult    = Measure_PositionH(NM);

        if (ERROR_SUCCEED != (ucResult & 0x80))     return ucResult;
        
        usH_End = usH_End + 1 - usH_Start;
          
        // H_Active Delta
        if (usH_End < usIPH_ACT_WID)
            delta = (usIPH_ACT_WID - usH_End > 0x00ff) ? 0xff : (unsigned char)(usIPH_ACT_WID - usH_End);
        else 
            delta = (usH_End - usIPH_ACT_WID > 0x00ff) ? 0xff : (unsigned char)(usH_End - usIPH_ACT_WID);

        if (0xc8 < delta)       // The difference is too large to fine-tune.
        {
            if (10 == count)
            {
                if (0x80 < stMUD.CLOCK)
                {
                    stMUD.CLOCK = 0x80;
                    Set_H_Position();
                    Set_Clock();
                }
                else
                {
                    stMUD.CLOCK = 0x80;
                    Set_Clock();
                    Set_H_Position();
                }

                continue;
            }
            else
                return (usH_End < usIPH_ACT_WID) ? ERROR_TOO_SMALL : ERROR_TOO_BIG;
        }
        
        if (2 >= delta)     break;  // 1023,1024,1025,1026,1027
        
        delta   = (delta + (delta >> 2) + 2) & 0xfc;  // 4n number
#if(ALIGN_LEFT == CLOCK_ALIGN)
        // Adjust Clock
        if (usH_End < usIPH_ACT_WID)    // delta < 0, Measure < Active
        {
            if ((178 - stMUD.CLOCK) < delta)    return ERROR_TOO_SMALL;
    
            stMUD.CLOCK  += delta;
                
            Set_Clock();
            Set_H_Position();
        }
        else                            // delta >= 0, Measure >= Active
        {
            if ((stMUD.CLOCK - 78) < delta)     return ERROR_TOO_BIG;
    
            stMUD.CLOCK -= delta;
                
            Set_H_Position();
            Set_Clock();
        }   

#else
        // Adjust Clock
        if (usH_End < usIPH_ACT_WID)    // delta < 0, Measure < Active
        {
            if ((228 - stMUD.CLOCK) < delta)    return ERROR_TOO_SMALL;
    
            stMUD.CLOCK += delta;
                
            Set_Clock();
            Set_H_Position();
        }
        else                            // delta >= 0, Measure >= Active
        {
            if ((stMUD.CLOCK - 28) < delta)     return ERROR_TOO_BIG;
    
            stMUD.CLOCK -= delta;
                
            Set_H_Position();
            Set_Clock();
        }   
#endif
    }
    while (--count);

    if (0 == count)  return ERROR_TIMEOUT;

    stop    = 0;

    while (1)
    {
        count   = 0x10;     // Phase 4 ~ 28 step 8 (4,12,20,28)
        delta   = 0x00;

        while (1)
        {
            Set_Phase(count);
            
            // Measure usH_Start & usH_End
            ucResult    = Measure_PositionH(NM);

            if (ERROR_SUCCEED != (ucResult & 0x80))
            {
                if (ERROR_NOTACTIVE == ucResult)
                {
                    // Input pattern is black/white vertical lines.
                    if (0x70 == count)
                    {
                        Set_Phase(stMUD.PHASE); // Restore phase
                        break;
                    }
                    else
                    {
                        count += 0x20;
                        continue;
                    }
                }

                Set_Phase(stMUD.PHASE); // Restore phase

                return ucResult;
            }
            
            usH_End     = usH_End + 1 - usH_Start;

            ucResult    = (usH_End < usIPH_ACT_WID)
                    ? 0x80 - (unsigned char)(usIPH_ACT_WID - usH_End)
                    : 0x80 + (unsigned char)(usH_End - usIPH_ACT_WID);
            
            if (ucResult > delta)
            {
                delta   = ucResult;     // Save the biggest width
            }

            if (0x70 == count)
            {
                Set_Phase(stMUD.PHASE); // Restore phase
                break;
            }

            count += 0x20;
        }

        if (0x82 < delta)
        {
            stMUD.CLOCK -= 4;

            Set_H_Position();
            Set_Clock();

            stop    = 1;
        }
        else if (0x80 > delta)
        {
            if (stop && (0x7f == delta))    break; 

            stMUD.CLOCK += 4;

            Set_Clock();
            Set_H_Position();

            delta   += 3;

            if (stop)   break;
        }
        else    
            break;
    }

#if (MORE_CLOCK)
    if (0x84 > delta && 0x7c < delta)
    {
        unsigned long   ulTemp0, ulMaxVal;
        unsigned char   ucPhase, ucDetect;

        if (ERROR_SUCCEED != Measure_PositionN(NM))    return ERROR_ABORT;

        // Set auto-tracking window
        Data[0]     = 6;
        Data[1]     = Y_INC;
        Data[2]     = H_BND_STA_L_75;
        Data[3]     = (unsigned char)(usH_Start + MEAS_H_STA_OFFSET - 2);
        Data[4]     = (unsigned char)(usH_End + MEAS_H_END_OFFSET + 1);
        Data[5]     = ((unsigned char)((usH_Start + MEAS_H_STA_OFFSET - 2) >> 4) & 0x70) | ((unsigned char)((usH_End + MEAS_H_END_OFFSET + 1) >> 8) & 0x0f);
        Data[6]     = 0;
        RTDWrite(Data);

        RTDSetByte(DIFF_THRED_7E, 0x50);
        
        ulTemp0     = 0;
        ucDetect    = 0x7b;
        ucResult    = COLORS_GREEN;
        ucPhase     = COLORS_GREEN;
        do
        {
            RTDSetByte(MARGIN_B_7D, ucPhase);
            RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);

            Wait_Finish();
            if (ERROR_SUCCEED != Data[0])   return Data[0];

            Read_Auto_Info(1);

            if (ulTemp0 < ((unsigned long *)Data)[1])
            {
                ulTemp0     = ((unsigned long *)Data)[1];
                ucResult    = ucPhase;

                if (0x10000 < ulTemp0)   break;
            }

            if (COLORS_GREEN == ucPhase)
                ucPhase = COLORS_BLUE;
            else if (COLORS_BLUE == ucPhase)
                ucPhase = COLORS_RED;
            else
            {
                if (0x10000 <= ulTemp0 || 0x77 == ucDetect)      break;

                ulTemp0     = 0;
                ucDetect    = 0x77;
                ucPhase     = COLORS_GREEN;
                ucResult    = COLORS_GREEN;

                RTDSetByte(DIFF_THRED_7E, 0x70);
            }
        }
        while (1);
        
        // Abort if no suitable color is found
        if (0x8000 > ulTemp0)
        {
            return (28 > stMUD.CLOCK) ? ERROR_TOO_BIG : (228 < stMUD.CLOCK) ? ERROR_TOO_SMALL : ERROR_SUCCEED;
        }

        // Save 4N clock
        stop    = stMUD.CLOCK;

        if (0x81 > delta)
        {
            stMUD.CLOCK = stMUD.CLOCK + 4;
            Set_Clock();
            Set_H_Position();
        }

        ulMaxVal    = 0;
        delta       = 4;
        do
        {
		
            if (ERROR_SUCCEED != Measure_PositionN(NM))    return ERROR_ABORT;

            // Set auto-tracking window
            Data[0] = 6;
            Data[1] = Y_INC;
            Data[2] = H_BND_STA_L_75;
            Data[3] = (unsigned char)(usH_Start + MEAS_H_STA_OFFSET - 2);
            Data[4] = (unsigned char)(usH_End + MEAS_H_END_OFFSET + 1);
            Data[5] = ((unsigned char)((usH_Start + MEAS_H_STA_OFFSET - 2) >> 4) & 0x70) | ((unsigned char)((usH_End + MEAS_H_END_OFFSET + 1) >> 8) & 0x0f);
            Data[6] = 0;
            RTDWrite(Data);
            
            // Select color for auto-phase tracking
            RTDSetByte(MARGIN_B_7D, ucResult);

            // Set threshold
            RTDSetByte(DIFF_THRED_7E, (0x7b == ucDetect) ? 0x50 : 0x70);

            ulTemp0 = 0;
            ucPhase = 0x00;
            do
            {
                Set_Phase(ucPhase);

                RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);

                Wait_Finish();
                if (ERROR_SUCCEED != Data[0])   return Data[0];

                 Read_Auto_Info(1);
                if (ulTemp0 < ((unsigned long *)Data)[1])   ulTemp0 = ((unsigned long *)Data)[1];

                ucPhase += 0x10;
            }
            while (0x80 > ucPhase);

            if (ulMaxVal < ulTemp0)
            {
                ulMaxVal    = ulTemp0;
                count       = stMUD.CLOCK;
            }

            if (0x00 == delta)
            {
                if (128 < stMUD.CLOCK)
                {
                    // See if default clock is the best
                    delta       = 0xff;
                    stMUD.CLOCK = 128;
                    Set_H_Position();
                    Set_Clock();
                    
                    continue;
                }
                else
                    break;
            }
            else if (0xff == delta)
            {
                break;
            }

            delta       -= 1;
            stMUD.CLOCK -= 1;
            Set_H_Position();
            Set_Clock();
        }
        while (1); 

        if (0x7b == ucDetect)
            stMUD.CLOCK = ((unsigned long)0x38000 < ulMaxVal) ? count : stop;
        else
            stMUD.CLOCK = ((unsigned long)0x48000 < ulMaxVal) ? count : stop;

        Set_Clock();
        Set_H_Position();
        Set_Clock();
    }
#endif

#else
    unsigned char   Result;
    unsigned char   count, delta, stop,start;    
    unsigned long   ulSum,ulCompare;
	ulCompare = 0;
	ulSum = 0;
        
    ///////////////////////////////
    //  Measure (V) Start & End  //
    ///////////////////////////////
    Result  = Measure_PositionV(NM);

    if (ERROR_SUCCEED != (Result & 0x80))   return Result;

    NM      = NM + 0x10;    // See Min_Noise_Margin(). Horizontal Measure Result is the same when applying (NM + 0x10)

    count   = 10;
    do
    {
	   
        ///////////////////////////////
        //  Measure (H) Start & End  //
        ///////////////////////////////
        Result  = Measure_PositionH(NM);

        if (ERROR_SUCCEED != (Result & 0x80))    return Result;
        
        usH_End = usH_End + 1 - usH_Start;
          
        // H_Active Delta
        if (usH_End < usIPH_ACT_WID)
            delta = (usIPH_ACT_WID - usH_End > 0x00ff) ? 0xff : (unsigned char)(usIPH_ACT_WID - usH_End);
        else 
            delta = (usH_End - usIPH_ACT_WID > 0x00ff) ? 0xff : (unsigned char)(usH_End - usIPH_ACT_WID);

        //if (0xc0 < delta)       // The difference is too large to fine-tune.
        if((usIPH_ACT_WID/3) < delta)  //modified 2003/02/25
        {
            return (usH_End < usIPH_ACT_WID) ? ERROR_TOO_SMALL : ERROR_TOO_BIG;
        }
        
        if (1 >= delta)     break;  // 1023,1024,1025,1026,1027
        
        delta   = delta + (delta >> 2);//& 0xfe;  // 4n number

#if(ALIGN_LEFT == CLOCK_ALIGN)
        // Adjust Clock
        if (usH_End < usIPH_ACT_WID)    // delta < 0, Measure < Active
        {
            if ((178 - stMUD.CLOCK) < delta)    return ERROR_TOO_SMALL;
    
            stMUD.CLOCK  += delta;
                
            Set_Clock();
            Set_H_Position();
        }
        else                            // delta >= 0, Measure >= Active
        {
            if ((stMUD.CLOCK - 78) < delta)     return ERROR_TOO_BIG;
    
            stMUD.CLOCK -= delta;
                
            Set_H_Position();
            Set_Clock();
        }   

#else
        // Adjust Clock
        if (usH_End < usIPH_ACT_WID)    // delta < 0, Measure < Active
        {
            if ((228 - stMUD.CLOCK) < delta)    return ERROR_TOO_SMALL;
    
            stMUD.CLOCK  += delta;
                
            Set_Clock();
            Set_H_Position();
        }
        else                            // delta >= 0, Measure >= Active
        {
            if ((stMUD.CLOCK - 28) < delta)     return ERROR_TOO_BIG;
    
            stMUD.CLOCK -= delta;
                
            Set_H_Position();
            Set_Clock();
        }   
    
#endif
    }
    while (--count);

	

    if (0 == count)  return ERROR_TIMEOUT;

    stop    = 0;

    while (1)
    {
        count   = 0x10;     // Phase 4 ~ 28 step 4 (4,8,12,16,20,24,28)
        delta   = 0xff;

        while (1)
        {
		  

            Set_Phase(count);
            
            // Measure usH_Start & usH_End
            Result  = Measure_PositionH(NM);

            if (ERROR_SUCCEED != (Result & 0x80))
            {
                if (ERROR_NOTACTIVE == Result)
                {
                    // Input pattern is black/white vertical lines.
                    if (0x70 == count)
                    {
                        Set_Phase(stMUD.PHASE); // Restore phase
                        break;
                    }
                    else
                    {
                        count += 0x20;
                        continue;
                    }
                }

                Set_Phase(stMUD.PHASE); // Restore phase

                return Result;
            }
            
            usH_End = usH_End + 1 - usH_Start;

            Result  = (usH_End < usIPH_ACT_WID)
                    ? 0x80 - (unsigned char)(usIPH_ACT_WID - usH_End)
                    : 0x80 + (unsigned char)(usH_End - usIPH_ACT_WID);
            
            if (Result < delta)
            {
                delta   = Result;       // Save the smallest width
            }

            if (0x70 == count)
            {
                Set_Phase(stMUD.PHASE); // Restore phase
                break;
            }

            count += 0x10;
        }
        
        if (0x81 < delta)
        {
            stMUD.CLOCK -= 1;

            Set_H_Position();
            Set_Clock();

            stop    = 1;
        }
        else if (0x80 > delta)
        {
            if (stop && (0x7f == delta))    break; 

            stMUD.CLOCK += 1;

            Set_Clock();
            Set_H_Position();

            if (stop)   break;
        }
        else    
            break;
    }
    
    count = stMUD.PHASE;  // Record Current Phase
    start = stMUD.CLOCK ;
	
	
	if(FindColor() != ERROR_SUCCEED) return ERROR_ABORT;
// Set threshold
    RTDSetByte(DIFF_THRED_7E, 0x30);

	ulSum = GetMaxSum(1); //judge if pulse information large enough
    ulCompare = GetMaxSum(0);

	

   	if((ulSum > 460000) || ((ulSum < 460000) && (ulCompare > 2000000)) )
	{
		
		ulCompare = 0;    
		//    ulSum = 0;//GetMaxSum(0);
		//////////////////////////////////////////////
		if(0x80 < (start - 2) || 0x80 > start)
		{
			stMUD.CLOCK = 0x80;
			Set_H_Position();
			Set_Clock();
			ulSum = GetMaxSum(0);
			
			if(ulCompare < ulSum)
			{
				ulCompare = ulSum;
				Result = stMUD.CLOCK;
			}

			stMUD.CLOCK = start + 1;
		}
		else
		{
			stMUD.CLOCK = start;
			Set_H_Position();
			Set_Clock();
			ulSum = GetMaxSum(0);
		}
		////////////////////////////////////////////////
	

		while(1)
		{
			if(ulCompare < ulSum)
			{
				ulCompare = ulSum;
				Result = stMUD.CLOCK;
			}
			if(stMUD.CLOCK == start - 2)
				break;    

			stMUD.CLOCK -= 1;
			Set_Clock();
			Set_H_Position();
			ulSum = GetMaxSum(0);        
		}

		stMUD.CLOCK = Result;
		stMUD.PHASE = count;
		Set_Clock();
		Set_H_Position();
		Set_Phase(stMUD.PHASE);
    }  



#endif
    return (28 > stMUD.CLOCK) ? ERROR_TOO_BIG : (228 < stMUD.CLOCK) ? ERROR_TOO_SMALL : ERROR_SUCCEED;
}

//------------------------------------------------------------------//
//                          Auto Position                           //
//------------------------------------------------------------------//
unsigned char Auto_Position(void)
{
    unsigned char   Result, Curr_PosH, Curr_PosV;

    bAutoInProgress = 1;

    Curr_PosH   = stMUD.H_POSITION;     // Save current stMUD.H_POSITION
    Curr_PosV   = stMUD.V_POSITION;     // Save current stMUD.V_POSITION

    if (ucV_Max_Margin < stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = ucV_Max_Margin;
        Set_V_Position();
    }

    RTDCodeW(ADC_DEFAULT);

    ///////////////////////////////
    //   Measure  NOISE_MARGIN   //
    ///////////////////////////////
    Result  = Min_Noise_Margin();

    if (ERROR_SUCCEED == (Result & 0x80))
    {   
        ///////////////////////////////
        //    Adjust (H/V)Position   //
        ///////////////////////////////
        Result  = Auto_Position_Do(Data[0]);    // Noise margin returned by Min_Noise_Margin() is saved in Data[0];
    }

    if (ERROR_SUCCEED == (Result & 0x80))
    {
        Save_MUD(ucMode_Curr);
    }
    else
    {
        stMUD.H_POSITION    = Curr_PosH;
        stMUD.V_POSITION    = Curr_PosV;

        Set_H_Position();
        Set_V_Position();
    }
    
    // Restore ADC Gain/Offset
    SetADC_GainOffset();

    bAutoInProgress = 0;

    return Result;
}

//------------------------------------------------------------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_SUCCESS_1 : Vertical Start > Max         //
//                   ERROR_SUCCESS_2 : Vertical Start < Min         //
//                   ERROR_SUCCESS_4 : Vertical Start/End Fail      //
//                   ERROR_SUCCESS_8 : Horizontal Start > Max       //
//                   ERROR_SUCCESS_16: Horizontal Start < Min       //
//                   ERROR_SUCCESS_32: Horizontal Start/End Fail    //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//
unsigned char Auto_Position_Do(unsigned char NM)
{
    unsigned char   Result;//,ucTemp,ucTemp1;
//	unsigned int    usTemp;

/*
    
///////////////////////////////////////////////////////////
	stMUD.H_POSITION = 128;
    
	if(128 >= stMUD.H_POSITION)
    {
    ucTemp = 128 - stMUD.H_POSITION;
    
	if(stMUD.CLOCK > 128)
	   ucTemp1 = 128;
	else
	   ucTemp1 = stMUD.CLOCK;

	ucH_Min_Margin = 128 - ucTemp - (64 - (ucTemp1 >> 1));
	usIPH_ACT_STA = usIPH_ACT_STA + 50 - ucTemp - (64 - (ucTemp1 >> 1));
	usTemp = usIPH_ACT_STA;

	Set_H_Position();
    }
///////////////////////////////////////////////////////////////////    
*/
    Result      = Measure_PositionN(NM);

    if (ERROR_SUCCEED != (Result & 0x80))   return Result;
    Result  = ERROR_SUCCEED;

    /////////////////////////////////
    // Calculate Vertical Position //
    /////////////////////////////////
    NM  = 1;
    while (1)
    {
        if ((usIPV_ACT_STA + ucV_Max_Margin - 128) >= usVer_Start)
        {
            if ((usIPV_ACT_STA + ucV_Min_Margin - 128) <= usVer_Start)
            {
                stMUD.V_POSITION = (usVer_Start + 128) - usIPV_ACT_STA;
                Set_V_Position();

                break;  // Success
            }
            else
                Result  |= ERROR_SUCCESS_2;
        }
        else
            Result  |= ERROR_SUCCESS_1;

        // If we can't align upper bound, we try to align lower bound.
        if (NM && usVer_End > usIPV_ACT_LEN)
        {
            usVer_Start = usVer_End - usIPV_ACT_LEN + 1;
            NM          = 0;
        }
        else
        {
            Result  |= ERROR_SUCCESS_4;
            break;
        }
    }
    
    ///////////////////////////////////
    // Calculate Horizontal Position //
    ///////////////////////////////////
    NM  = 1;
    while (1)
    {
#if(ALIGN_LEFT == CLOCK_ALIGN)

        if ((usIPH_ACT_STA + (stMUD.CLOCK >> 2) + ucH_Max_Margin - 32 - 128) >= usH_Start)
        {

			//if(ucH_Min_Margin  == (128 - 10))
            if(ucH_Min_Margin  <= 128 )
			  ((unsigned int*)Data)[0] = usH_Start + 128 - stMUD.H_POSITION + 50;//((unsigned int*)Data)[0] = usH_Start + ucTemp + 100;//((unsigned int*)Data)[0] = usH_Start + 10;
			else
			  ((unsigned int*)Data)[0] = usH_Start;// + (stMUD.H_POSITION - 128) + 10;

            //if ((usIPH_ACT_STA + (stMUD.CLOCK >> 1) + ucH_Min_Margin - 64 - 128) <= (usH_Start + 50))
			if ((usIPH_ACT_STA + (stMUD.CLOCK >> 2) + ucH_Min_Margin - 32 - 128) <= ((unsigned int*)Data)[0])
            {
                //usH_Start is the actual distance from Hsync to active image
	            stMUD.H_POSITION    = usH_Start + 128 + 32 - usIPH_ACT_STA - (stMUD.CLOCK >> 2);
				Set_H_Position();
                
                break;  // Success
            }
            else
                Result  |= ERROR_SUCCESS_16;
        }
        else
            Result  |= ERROR_SUCCESS_8;


#else
        if ((usIPH_ACT_STA + (stMUD.CLOCK >> 1) + ucH_Max_Margin - 64 - 128) >= usH_Start)
        {

			//if(ucH_Min_Margin  == (128 - 10))
            if(ucH_Min_Margin  <= 128 )
			  ((unsigned int*)Data)[0] = usH_Start + 128 - stMUD.H_POSITION + 100;//((unsigned int*)Data)[0] = usH_Start + ucTemp + 100;//((unsigned int*)Data)[0] = usH_Start + 10;
			else
			  ((unsigned int*)Data)[0] = usH_Start;// + (stMUD.H_POSITION - 128) + 10;

            //if ((usIPH_ACT_STA + (stMUD.CLOCK >> 1) + ucH_Min_Margin - 64 - 128) <= (usH_Start + 50))
			if ((usIPH_ACT_STA + (stMUD.CLOCK >> 1) + ucH_Min_Margin - 64 - 128) <= ((unsigned int*)Data)[0])
            {
                //usH_Start is the actual distance from Hsync to active image
	            stMUD.H_POSITION    = usH_Start + 128 + 64 - usIPH_ACT_STA - (stMUD.CLOCK >> 1);
				Set_H_Position();
                
                break;  // Success
            }
            else
                Result  |= ERROR_SUCCESS_16;
        }
        else
            Result  |= ERROR_SUCCESS_8;

#endif
        // If we can't align upper bound, we try to align lower bound.
        if (NM && usH_End > usIPH_ACT_WID)
        {
            usH_Start   = usH_End - usIPH_ACT_WID + 1;
            NM          = 0;
        }
        else
        {
            Result  |= ERROR_SUCCESS_32;
            break;
        }
    }
/*
//////////////////////////////////////////////////////////////////////////////
    if(ucH_Min_Margin == (128 - ucTemp))
	{
        if(usTemp != usIPH_ACT_STA)
		{
		   stMUD.H_POSITION = stMUD.H_POSITION - (usTemp - usIPH_ACT_STA);
		   usIPH_ACT_STA = usTemp - 50 + ucTemp + (64 - (ucTemp1 >> 1));
		}
		else
		    usIPH_ACT_STA   = usIPH_ACT_STA - 50 + ucTemp + (64 - (ucTemp1 >> 1));

		ucH_Min_Margin  = 128 - 50;   
		Set_H_Position();
	}
////////////////////////////////////////////////////////////////////////////////
*/
    return Result;
}

unsigned char Min_Noise_Margin(void)
{
    unsigned char   Result, Noise;
    unsigned int    Curr_StartH, Curr_EndH;

    Result  = Measure_PositionV(VERTICAL_MARGIN);
    
    if (ERROR_SUCCEED != (Result & 0x80))   return Result;
	    
    if (0 == usVer_Start)
    {
        Result  = Measure_PositionV(VERTICAL_MARGIN + 0x20);
        if (ERROR_SUCCEED != (Result & 0x80))   return Result;
    }
    
    Noise   = 0x00;
    Result  = Measure_PositionH(Noise);
    if (ERROR_SUCCEED != (Result & 0x80))   return Result;
        
    Curr_StartH = usH_Start;    // Save H start position at noise margin = 0
    Curr_EndH   = usH_End;      // Save H end position at noise margin = 0

    do
    {
        Noise   = Noise + 0x10;
        Result  = Measure_PositionH(Noise);

        if (ERROR_SUCCEED != (Result & 0x80))   return Result;
    
        if (Curr_StartH >= usH_Start)
        {
            Curr_StartH = usH_Start;
        }
        else if (0x08 < (usH_Start - Curr_StartH))
        {
            break;  // A large gap of H start position is found.
        }
    }
    while (0x90 > Noise);

    if (0x80 < Noise)   return ERROR_NOISE_TOO_BIG;      

    while (1)
    {   
        Curr_StartH = usH_Start;
        Curr_EndH   = usH_End;

        Result  = Measure_PositionH(Noise + 0x28);
        
        if (ERROR_SUCCEED != (Result & 0x80))   return Result;

        if ((Curr_EndH - Curr_StartH) == (usH_End - usH_Start) || (Curr_EndH - Curr_StartH) >= (usH_End - usH_Start + 3))
        {
            break;  // We got noise margin with stable horizontal start/end position.
        }
        
        if (0xa0 <= Noise)
        {
            break;  // No stable horizontal start/end position are found.
        }

        Noise   = Noise + 0x10;        
        Result  = Measure_PositionH(Noise);

        if (ERROR_SUCCEED != (Result & 0x80))   return Result;
    };

    Data[0] = Noise + 0x10;

    return ERROR_SUCCEED;
}

unsigned char Auto_Phase(void)
{
    unsigned char   Result, Curr_PosV;

    bAutoInProgress = 1;

    Curr_PosV   = stMUD.V_POSITION;     // Save current stMUD.V_POSITION

    if (ucV_Max_Margin < stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = ucV_Max_Margin;
        Set_V_Position();
    }

    // Set ADC to default
    RTDCodeW(ADC_DEFAULT);

    ///////////////////////////////
    //   Measure  NOISE_MARGIN   //
    ///////////////////////////////
    Result  = Min_Noise_Margin();

    if (ERROR_SUCCEED == (Result & 0x80))
    {   
        Result      = Auto_Phase_Do(Data[0]);   // Noise margin returned by Min_Noise_Margin() is saved in Data[0];
    }

    if (ERROR_SUCCEED != (Result & 0x80))
    {
        // Restore Phase
        Set_Phase(stMUD.PHASE);
    }
    else
    {
        Save_MUD(ucMode_Curr);
    }

    // Restore ADC Gain/Offset
    SetADC_GainOffset();

    // Restore vertical position
    if (Curr_PosV != stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = Curr_PosV;
        Set_V_Position();
    }

    bAutoInProgress = 0;

    return Result;
}


unsigned char Auto_Phase_Do(unsigned char NM)
{
    unsigned char idata ucDetect, ucPhase, ucResult;
    unsigned long idata ulTemp0, ulTemp1, ulTemp2;

/*	
    //reduce the bandwidth of ADC to prevent overshoot
    if(ucMode_Curr <= MODE_1280x1024x75HZ)
       RTDSetByte(ADC_REG_TEST_E9, 0x08);
    else if(ucMode_Curr < MODE_1024x0768x70HZ)
       RTDSetByte(ADC_REG_TEST_E9, 0x00);
    else
       RTDSetByte(ADC_REG_TEST_E9, 0x10);
*/

    if (ERROR_SUCCEED != Measure_PositionN(NM))    return ERROR_ABORT;

    // Set auto-tracking window
    Data[0]     = 6;
    Data[1]     = Y_INC;
    Data[2]     = H_BND_STA_L_75;
    Data[3]     = (unsigned char)(usH_Start + MEAS_H_STA_OFFSET - 2);
    Data[4]     = (unsigned char)(usH_End + MEAS_H_END_OFFSET + 1);
    Data[5]     = ((unsigned char)((usH_Start + MEAS_H_STA_OFFSET - 2) >> 4) & 0x70) | ((unsigned char)((usH_End + MEAS_H_END_OFFSET + 1) >> 8) & 0x0f);
    Data[6]     = 0;
    RTDWrite(Data);

    RTDSetByte(DIFF_THRED_7E, 0x30);

    ulTemp0     = 0;
    ucDetect    = 0x7b;
    do
    {
        ucResult    = COLORS_GREEN;
        ucPhase     = COLORS_GREEN;
        do
        {
            RTDSetByte(MARGIN_B_7D, ucPhase);
            RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);

            Wait_Finish();
            if (ERROR_SUCCEED != Data[0])   return Data[0];

            Read_Auto_Info(1);
            if (ulTemp0 < ((unsigned long *)Data)[1])
            {
                ulTemp0     = ((unsigned long *)Data)[1];
                ucResult    = ucPhase;

                if (0x8000 < ulTemp0)   break;
            }

            if (COLORS_GREEN == ucPhase)
                ucPhase = COLORS_BLUE;
            else if (COLORS_BLUE == ucPhase)
                ucPhase = COLORS_RED;
            else
                break;
        }
        while (1);

        if (0 != ulTemp0 || 0x7b != ucDetect)   break;

        ucDetect    = 0x77;
    }
    while (1);

    // Abort if no suitable color is found
    if (0 == ulTemp0)   return ERROR_NOTACTIVE;
   // NM = COLORS_GREEN;
    // Select color for auto-phase tracking
    RTDSetByte(MARGIN_B_7D, NM | ucResult);

#if(1)
    //NM = 136;
	NM = 100;
#else
    // Find suitable threshold
    // We use phase 8 and 24 to find out it

    ucPhase = 0x20;
    Set_Phase(ucPhase);

    ucResult    = 0x28;
    NM          = 0x00;
    do
    {
        do
        {
            ucResult    += 0x20;

            RTDSetByte(DIFF_THRED_7E, ucResult);
            RTDSetByte(AUTO_ADJ_CTRL_7F, ucDetect);

            Wait_Finish();
            if (ERROR_SUCCEED != Data[0])   return Data[0];

            Read_Auto_Info(1);

            if ((unsigned long)0x1000 > ((unsigned long *)Data)[1])
            {
                ucResult    -= 0x20;
                break;
            }
        }
        while (0x88 > ucResult);

        if (0x88 == ucResult)
        {
            NM  = ucResult;
            break;
        }
        else
        {
            if (0x20 == ucPhase)
            {
                NM  = ucResult;

                ucPhase = 0x60;
                Set_Phase(ucPhase);
            }
            else
            {
                if (NM < ucResult)      NM  = ucResult;
                
                break;
            }
        }
    }
    while (1);

    // Set threshold
    if(NM < 136) NM = 136;
#endif

    RTDSetByte(DIFF_THRED_7E, NM);

#if(1)  //FAST_AUTO method 1
        // Set phase 30
		Set_Phase(0x78);
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];

		Read_Auto_Info(1);
      
		ulTemp1     = ((unsigned long *)Data)[1];


#if(HARDWARE_AUTO)
        ulTemp2     = ulTemp1;
		ulTemp0     = 0;
        RTDSetByte(HW_AUTO_PHASE_9E,0x05);  //Step 2 auto phase
		//Wait_For_Event(EVENT_IVS);
		Wait_For_IVS();
		RTDSetByte(AUTO_ADJ_CTRL_7F,0x77); // Auto start
		//Wait_For_Event(EVENT_IVS);
		Wait_For_IVS();
        for(ucDetect = 0;ucDetect < 16; ucDetect++)
        {
               //Wait_For_Event(EVENT_IVS);
			   Wait_For_IVS();
               Read_Auto_Info(3);
            /*   
			   Data[0]     = 7;
               Data[1]     = ADDR_EROM1;
               Data[2]     = 0x40 + (ucDetect << 2);
               Data[3]     = (unsigned char)(((unsigned long *)Data)[3] >> 12);
               Data[4]     = (unsigned char)(((unsigned long *)Data)[3] >> 8);
               Data[5]     = (unsigned char)(((unsigned long *)Data)[3] >> 4);
               Data[6]     = 0x00;
               
			   I2CWrite(Data);
			  */ 

              if(ulTemp0 < ((unsigned long *)Data)[3])
              {
                   ulTemp0   = ((unsigned long *)Data)[3] & 0xffffff00; //Store the SOD of phase(n)
				   ulTemp1   = ulTemp2;                                 //Store the SOD of phase(n-2)
				   ucResult  = ucDetect << 3;                           //Save the phase
              }
              ulTemp2 = ((unsigned long*)Data)[3] & 0xffffff00;
			  
        }
			Wait_Finish();
			if (ERROR_SUCCEED != Data[0])   return Data[0];

        RTDSetByte(HW_AUTO_PHASE_9E,0x00);  //Switch back to software auto phase

#else
		// Set phase 0
		Set_Phase(0x00);
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];

		Read_Auto_Info(1);
      
		ulTemp0     = ((unsigned long *)Data)[1];
		ulTemp2     = ulTemp0;


		ucResult    = 0x00;

		ucPhase     = 0x08;//2 step rought scan
		do
		{
			Set_Phase(ucPhase);
			Delay_Xms(1);

			RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);
			
			Wait_Finish();
			if (ERROR_SUCCEED != Data[0])   return Data[0];

            Read_Auto_Info(3);
       
//			((unsigned long *)Data)[0]  = ulTemp1 + ulTemp2 + ((unsigned long *)Data)[1];

			if (ulTemp0 < ((unsigned long *)Data)[3])
			{
				ulTemp0     = ((unsigned long *)Data)[3];  //Save the SOD of phase(n)
				ulTemp1     = ulTemp2;                     //Save the SOD of phase(n-2)
				ucResult    = ucPhase;
			}
			

			ulTemp2 = ((unsigned long *)Data)[3];

			ucPhase = ucPhase + 0x08;
		}
		while (0x78 != ucPhase);


		if((ucResult == 0x00) && (ulTemp1 > ulTemp2))//Compare the value of phase 28 & phase 30
		{
		     ucResult = 0x78;  //The maximum equal to phase 30
			 ulTemp0 = ulTemp1; //Save the value of phase 30
			 ulTemp1 = ulTemp2; //Save the value of phase 28
		}
#endif

        ucPhase = ucResult == 0x00 ? 0x7c : (ucResult - 0x04 );
        ulTemp2 = 0;
        ucDetect = 2;
		

        Set_Phase(ucPhase); //set Phase(n-1)
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];
        Read_Auto_Info(1);
        ulTemp2 = ((unsigned long*)Data)[1];   //Save the SOD of  phase(n-1)
		
        ((unsigned long*)Data)[0] 
		= ulTemp1 + ulTemp2 + ulTemp0 
        -((ulTemp1 > ulTemp2 ? ulTemp1 - ulTemp2 : ulTemp2 - ulTemp1)/2)
		-((ulTemp2 > ulTemp0 ? ulTemp2 - ulTemp0 : ulTemp0 - ulTemp2)/2);

		ulTemp1 = ((unsigned long*)Data)[0];
		ucPhase = ucResult; 
        ucResult = ucResult == 0x00 ? 0x7c : ucResult - 0x04;

        do //detail scan by one step from phase(n-2) ~ pnase (n+2)
        {
           ucPhase = (ucPhase == 0x7c) ? 0x00 : ucPhase + 0x04;
           Set_Phase(ucPhase);
	       Delay_Xms(1);
		
		   RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

           Wait_Finish();
		   if (ERROR_SUCCEED != Data[0])   return Data[0];

           Read_Auto_Info(3);

          ((unsigned long *)Data)[0]  
           = ulTemp2 + ulTemp0 + ((unsigned long *)Data)[3]
           - ((ulTemp0 > ulTemp2 ? ulTemp0 - ulTemp2 : ulTemp2 - ulTemp0) / 2)
           - ((ulTemp0 > ((unsigned long *)Data)[3] ? ulTemp0 - ((unsigned long *)Data)[3] : ((unsigned long *)Data)[3] - ulTemp0) / 2);

           if(((unsigned long*)Data)[0] > ulTemp1)
           {
               ulTemp1 = ((unsigned long*)Data)[0];
               ucResult = (ucPhase == 0x00) ? 0x7c : ucPhase - 0x04;
           }
           ucDetect -= 1;
           
           ulTemp2 = ulTemp0;
           ulTemp0 = ((unsigned long *)Data)[3];

        }while(ucDetect);


#else   //FAST AUTO method 2
		// Set phase 30
		Set_Phase(0x78);
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];

		Read_Auto_Info(1);
      
		ulTemp2     = ((unsigned long *)Data)[1];

		// Set phase 0
		//Set_Phase(0x00 | ucDetect);
        Set_Phase(0x00);
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];

		Read_Auto_Info(2);
       

		ulTemp1 = ((unsigned long *)Data)[2];

		ulTemp0     = 0;
		ucResult    = 0x08;
		ucPhase     = 0x08;//2 step rought scan
		do
		{
			Set_Phase(ucPhase);
			Delay_Xms(1);

			RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);
			
			Wait_Finish();
			if (ERROR_SUCCEED != Data[0])   return Data[0];

            Read_Auto_Info(3);
       
//			((unsigned long *)Data)[0]  = ulTemp1 + ulTemp2 + ((unsigned long *)Data)[1];

           ((unsigned long *)Data)[0]  
		   = ulTemp2 + ulTemp1 + ((unsigned long *)Data)[3]
            - ((ulTemp1 > ulTemp2 ? ulTemp1 - ulTemp2 : ulTemp2 - ulTemp1) / 2)
            - ((ulTemp1 > ((unsigned long *)Data)[3] ? ulTemp1 - ((unsigned long *)Data)[3] : ((unsigned long *)Data)[3] - ulTemp1) / 2);


			if (ulTemp0 < ((unsigned long *)Data)[0])
			{
				ulTemp0     = ((unsigned long *)Data)[0];
				ucResult    = ucPhase - 0x08;
			}

			ulTemp2 = ulTemp1;
			ulTemp1 = ((unsigned long *)Data)[3];

			ucPhase = ucPhase + 0x08;
		}
		while (0x78 != ucPhase);


//		((unsigned long *)Data)[0]  = ulTemp1 + ulTemp2 + ((unsigned long *)Data)[3];
//		((unsigned long *)Data)[1]  = ((unsigned long *)Data)[3] + ulTemp1 + ((unsigned long *)Data)[2];


       ((unsigned long *)Data)[0]//phase26+phase28+phase30
        = ulTemp2 + ulTemp1 + ((unsigned long *)Data)[1]
        - ((ulTemp1 > ulTemp2 ? ulTemp1 - ulTemp2 : ulTemp2 - ulTemp1) / 2)
        - ((ulTemp1 > ((unsigned long *)Data)[1] ? ulTemp1 - ((unsigned long *)Data)[1] : ((unsigned long *)Data)[1] - ulTemp1) / 2);
       
		

       ((unsigned long *)Data)[3]//phase28+phase30+phase0
        = ulTemp1 + ((unsigned long *)Data)[1] + ((unsigned long *)Data)[2]
        - ((((unsigned long *)Data)[1] > ulTemp1 ? ((unsigned long *)Data)[1] - ulTemp1 : ulTemp1 - ((unsigned long *)Data)[1]) / 2)
        - ((((unsigned long *)Data)[1] > ((unsigned long *)Data)[2] ? ((unsigned long *)Data)[1] - ((unsigned long *)Data)[2] : ((unsigned long *)Data)[2] - ((unsigned long *)Data)[1]) / 2);


		if (ulTemp0 < ((unsigned long *)Data)[0])
		{
			ulTemp0     = ((unsigned long *)Data)[0];
			ucResult    = 0x70;  //ucResult = phase28
		}

		if (ulTemp0 < ((unsigned long *)Data)[3])
		{
			ulTemp0     = ((unsigned long *)Data)[3];
			ucResult    = 0x78;  //ucResult = phase30
		}


        ucPhase = ucResult >= 0x08 ? (ucResult - 0x08) : (ucResult + 0x80 - 0x08);
        ulTemp0 = 0;
        ulTemp1 = 0;
        ulTemp2 = 0;
        ucDetect = 3;

        Set_Phase(ucPhase); //set Phase(n-2)
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];
        Read_Auto_Info(1);
        ulTemp1 = ((unsigned long*)Data)[1];

        ucPhase = (ucPhase == 0x7c) ? 0x00 : ucPhase + 0x04; //set Phase(n-1)
        Set_Phase(ucPhase);
		Delay_Xms(1);
		
		RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

		Wait_Finish();
		if (ERROR_SUCCEED != Data[0])   return Data[0];
        Read_Auto_Info(2);
        ulTemp2 = ((unsigned long*)Data)[2];


        do //detail scan by one step from phase(n-2) ~ pnase (n+2)
        {
           ucPhase = (ucPhase == 0x7c) ? 0x00 : ucPhase + 0x04;
           Set_Phase(ucPhase);
	       Delay_Xms(1);
		
		   RTDSetByte(AUTO_ADJ_CTRL_7F, 0x77);

           Wait_Finish();
		   if (ERROR_SUCCEED != Data[0])   return Data[0];

           Read_Auto_Info(3);

          ((unsigned long *)Data)[0]  
           = ulTemp1 + ulTemp2 + ((unsigned long *)Data)[3]
           - ((ulTemp1 > ulTemp2 ? ulTemp1 - ulTemp2 : ulTemp2 - ulTemp1) / 2)
           - ((ulTemp2 > ((unsigned long *)Data)[3] ? ulTemp2 - ((unsigned long *)Data)[3] : ((unsigned long *)Data)[3] - ulTemp2) / 2);

           if(((unsigned long*)Data)[0] > ulTemp0)
           {
               ulTemp0 = ((unsigned long*)Data)[0];
               ucResult = (ucPhase == 0x00) ? 0x7c : ucPhase - 0x04;
           }
           ucDetect -= 1;
           
           ulTemp1 = ulTemp2;
           ulTemp2 = ((unsigned long *)Data)[3];

        }while(ucDetect);
        
//        ucDebug_Value1 = ucResult;
#endif        

		stMUD.PHASE = ucResult;
		Set_Phase(stMUD.PHASE);
	
/*
    //restore the bandwidth setup of ADC
    if(ucMode_Curr < MODE_1024x0768x70HZ)
    	RTDSetByte(ADC_REG_TEST_E9, 0x08);
    else 
        RTDSetByte(ADC_REG_TEST_E9, 0x10);
*/
   
    return ERROR_SUCCEED;
}

unsigned char Auto_Config(void)
{
    unsigned char   Result, Noise, Curr_PosH, Curr_PosV, Curr_Clock, Curr_Phase;

    unsigned char ucTemp1;
	unsigned int usTemp;


    bAutoInProgress = 1;
    
    Curr_PosH   = stMUD.H_POSITION;     // Save current stMUD.H_POSITION
    Curr_PosV   = stMUD.V_POSITION;     // Save current stMUD.V_POSITION
    Curr_Clock  = stMUD.CLOCK;          // Save current stMUD.CLOCK
    Curr_Phase  = stMUD.PHASE;          // Save current stMUD.PHASE

    if (ucV_Max_Margin < stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = ucV_Max_Margin - 1;
        Set_V_Position();
    }

//   RTDCodeW(ADC_DEFAULT);

/////////original formula////////////////////////////////////////////
    //Set the H Position center(without IHS_Delay)
/*
   	stMUD.H_POSITION = 128; 
    
	if(128 >= stMUD.H_POSITION)
    {
    ucTemp = 128 - stMUD.H_POSITION; 
    
	if(stMUD.CLOCK > 128)
	   ucTemp1 = 128;
	else
	   ucTemp1 = stMUD.CLOCK;

    //According to the H_Position adjust the IHS pre-delay
	ucH_Min_Margin = 128 - ucTemp - (64 - (ucTemp1 >> 1));
    //Return the IPH_ACT_STA to the original one first,and compensate the IHS pre-delay
    //The h position must be equal after change the IHS delay and IPH_ACT_STA
	usIPH_ACT_STA = usIPH_ACT_STA + 50 - ucTemp - (64 - (ucTemp1 >> 1));
	usTemp = usIPH_ACT_STA;

	Set_H_Position();
    }
	*/
///////////////////////////////////////////////////////////////////    

////////////////////////////////////////////////////////////////////
    //Set the H Position center(without IHS_Delay)

   	stMUD.H_POSITION = 128; 
    
	
    //ucTemp = 128 - stMUD.H_POSITION; 
    
	if(stMUD.CLOCK > 128)
	   ucTemp1 = 128;
	else
	   ucTemp1 = stMUD.CLOCK;

    //According to the H_Position adjust the IHS pre-delay
	ucH_Min_Margin = 128 - (64 - (ucTemp1 >> 1));
    //Return the IPH_ACT_STA to the original one first,and compensate the IHS pre-delay
    //The h position must be equal after change the IHS delay and IPH_ACT_STA
    usIPH_ACT_STA   = CAP_WIN[ucMode_Curr][1];
    
    if(ucMode_Curr < MODE_0800x0600x75HZ)
		Data[0] = 2;
    else if(ucMode_Curr < MODE_1280x1024x75HZ)
		Data[0] = 5;
    else
		Data[0] = 3;

//    usIPH_ACT_STA   = usIPH_ACT_STA + Data[0] - PROGRAM_HDELAY;

	//usIPH_ACT_STA = usIPH_ACT_STA + 50 - (64 - (ucTemp1 >> 1));
    usIPH_ACT_STA = CAP_WIN[ucMode_Curr][1] + Data[0] - PROGRAM_HDELAY - (64 - (ucTemp1 >> 1));
	
    usTemp = usIPH_ACT_STA;

	Set_H_Position();
        
    RTDSetByte(STATUS0_01, 0x00);  // Clear status
    RTDSetByte(STATUS1_1F, 0x00);  // Clear status

    
///////////////////////////////////////////////////////////////////    

    ///////////////////////////////
    //   Measure  NOISE_MARGIN   //
    ///////////////////////////////

    Result  = Min_Noise_Margin();   
    Noise   = Data[0];

    

    
    //--------Auto_Clock-----------
    if (ERROR_SUCCEED == (Result & 0x80))
    {   
        stMUD.CLOCK = (stMUD.CLOCK) & 0xfc; // stMUD.CLOCK must be times of 4

        if (stMUD.CLOCK != Curr_Clock)  Set_Clock();

        ///////////////////////////////
        //       Adjust Clock        //
        ///////////////////////////////
        Result  = Auto_Clock_Do(Noise);

 	        
        if (ERROR_SUCCEED != (Result & 0x80))
        {
            if (stMUD.CLOCK != Curr_Clock)
            {
                // Fail to find out suitable clock. Restore original clock and H position.
                stMUD.H_POSITION    = Curr_PosH;
                stMUD.CLOCK         = Curr_Clock;

                Set_Clock();
                Set_H_Position();
            }
        }
        else
        {
            stMUD.H_POSITION    = usH_Start + 128 + 64 - usIPH_ACT_STA - (stMUD.CLOCK >> 1);

            if (ucH_Max_Margin < stMUD.H_POSITION)
                stMUD.H_POSITION    = ucH_Max_Margin;
            else if (ucH_Min_Margin > stMUD.H_POSITION)
                stMUD.H_POSITION    = ucH_Min_Margin;

            Set_H_Position();
        }
    }
    
    //---------Auto_Phase-----------
    if (ERROR_SUCCEED == (Result & 0x80))
    {   
        Result      = Auto_Phase_Do(Noise);

        if (ERROR_SUCCEED != (Result & 0x80))
        {
            // Restore Phase
            stMUD.PHASE = Curr_Phase;
            Set_Phase(stMUD.PHASE);

            if (ERROR_NOTACTIVE == Result)      Result  = ERROR_SUCCEED;
        }
    }

    //---------Auto_Position-----------
    if (ERROR_SUCCEED == (Result & 0x80))    
    {   
        ///////////////////////////////
        //    Adjust (H/V)Position   //
        ///////////////////////////////
        Result  = Auto_Position_Do(Noise);

        // Because Auto_Position_Do() never returns bit-7 error, we don't have to check here.
    }
    else
    {
        stMUD.V_POSITION    = Curr_PosV;
        Set_V_Position();
    }
    
//    if (ERROR_SUCCEED == (Result & 0x80))   Save_MUD(ucMode_Curr);

//////////////////////////////////////////////////////////////////////////////
/*
    if(ucH_Min_Margin == (128 - ucTemp - (64 - (ucTemp1 >> 1))))
	{
        if(usTemp != usIPH_ACT_STA)
		{  //if usIPH_ACT_STA has been modified, turn back to original set value
           //stMUD.H_POSIITON also have to follow up the change of usIPH_ACT_STA
		   stMUD.H_POSITION = stMUD.H_POSITION - (usTemp - usIPH_ACT_STA);
		   usIPH_ACT_STA = usTemp - 50 + ucTemp + (64 - (ucTemp1 >> 1));
		}
		else
		    usIPH_ACT_STA   = usIPH_ACT_STA - 50 + ucTemp + (64 - (ucTemp1 >> 1));

		ucH_Min_Margin  = 128 - 50;   
		Set_H_Position();
	}
	Set_Phase(stMUD.PHASE);
	*/
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////

    if(ucH_Min_Margin == (128 - (64 - (ucTemp1 >> 1))))
	{
        if(usTemp != usIPH_ACT_STA)
		{  //if usIPH_ACT_STA has been modified, turn back to original set value
           //stMUD.H_POSIITON also have to follow up the change of usIPH_ACT_STA
		   //Data[3] = 78 - usIPH_ACT_STA; Save the usIPH_ACT_STA compensate value
		   stMUD.H_POSITION = stMUD.H_POSITION - (usTemp - usIPH_ACT_STA);
		   usIPH_ACT_STA = usTemp - 50 + (64 - (ucTemp1 >> 1));
		   Data[3] = 0x80 | (78 - stMUD.H_POSITION);	    
         
		}
		else
		{
		    usIPH_ACT_STA   = usIPH_ACT_STA - 50 + (64 - (ucTemp1 >> 1));
			Data[3] = 0;
		}

		// Save Frame-Sync Settings
           Data[0] = 4;
           Data[1] = ADDR_EROM1;
           Data[2] = (ucMode_Curr - 1);          
		   
           

		 if(0x80 < stMUD.H_POSITION)
         {
             if(stMUD.H_POSITION - 0x80 < 10)
             {
                 usIPH_ACT_STA += (stMUD.H_POSITION - 0x80);
                 Data[3] += (stMUD.H_POSITION - 0x80);
                 stMUD.H_POSITION = 0x80;                            
              }

         }
         else if(0x80 > stMUD.H_POSITION)
         {
              if(0x80 - stMUD.H_POSITION < 10)
              {
                 usIPH_ACT_STA -= (0x80 - stMUD.H_POSITION);

			     Data[3] = (0x80 - stMUD.H_POSITION ) | 0x80;
                 stMUD.H_POSITION = 0x80;

              }
         }

		I2CWrite(Data);
        Delay_Xms(SET_2404_DELAY);

		ucH_Min_Margin  = 128 - 50;   
		Set_H_Position();
        
	}
	Set_Phase(stMUD.PHASE);
    if (ERROR_SUCCEED == (Result & 0x80))   Save_MUD(ucMode_Curr);

    RTDSetByte(STATUS0_01, 0x00);  // Clear status
    RTDSetByte(STATUS1_1F, 0x00);  // Clear status

/////////////////////////////////////////////////////////////////////////////////

    // Restore ADC Gain/Offset
//  SetADC_GainOffset();
   
    bAutoInProgress = 0;
    Set_Phase(stMUD.PHASE);
	
    return Result;
}

unsigned char Auto_Balance(void)
{
    unsigned char Result, Curr_PosV;

    bAutoInProgress = 1;

    Curr_PosV   = stMUD.V_POSITION;     // Save current stMUD.V_POSITION

    if (ucV_Max_Margin < stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = ucV_Max_Margin;
        Set_V_Position();
    }

    // Do ADC gain/offset adjust
    Result  = Tune_Balance();

    // Restore vertical position
    if (Curr_PosV != stMUD.V_POSITION)
    {
        stMUD.V_POSITION    = Curr_PosV;
        Set_V_Position();
    }

    if (ERROR_SUCCEED != Result)
    {
        // Restore ADC Gain/Offset
        Load_GUD2();
        SetADC_GainOffset();
    }
    else
    {
        stGUD0.CONTRAST         = 50;
        stGUD0.RTD_R_CONTRAST   = 50;
        stGUD0.RTD_G_CONTRAST   = 50;
        stGUD0.RTD_B_CONTRAST   = 50;
        stGUD0.RTD_R_BRIGHT     = 50;
        stGUD0.RTD_G_BRIGHT     = 50;
        stGUD0.RTD_B_BRIGHT     = 50;
        Set_Bright_Contrast();

#if(ANALOG_CONTRAST)
        SetADC_Gain();
#endif

        Save_GUD0();
/*
        if (0 != stGUD2.AD_G_GAIN && 255 != stGUD2.AD_G_GAIN && 0 != stGUD2.AD_G_OFFSET && 255 != stGUD2.AD_G_OFFSET)
        {
            stGUD2.AD_G_GAIN    += 1;
            stGUD2.AD_G_OFFSET  += 1;
        }
        SetADC_GainOffset();
*/
        Save_GUD2();
    }

    bAutoInProgress = 0;

    return Result;
}

unsigned char Tune_Balance(void)
{
    unsigned char   Color, Count, Result, Margin, FineTune, Offset_Stop,ucTemp = 0;
    
    FineTune    = 0;

#if(ANALOG_CONTRAST)
    ucTemp = stGUD0.CONTRAST;
    stGUD0.CONTRAST = 50;
	SetADC_Gain();
#endif

    RTDCodeW(ADC_DEFAULT);
    
    // Get usVer_Start, usVer_End, usH_Start, usH_Start
    if (ERROR_SUCCEED != Measure_PositionN(0x40))   return ERROR_ABORT;

    if (ERROR_SUCCEED != Measure_Color(SELECT_RED, COLOR_MAX))      return ERROR_ABORT;
    if (0x60 > Data[0])     return ERROR_ABORT;
    
    Margin  = Data[0];

    if (ERROR_SUCCEED != Measure_Color(SELECT_GREEN, COLOR_MAX))    return ERROR_ABORT;
    if (0x60 > Data[0])     return ERROR_ABORT;

    Margin  = Margin > Data[0] ? Data[0] : Margin;

    if (ERROR_SUCCEED != Measure_Color(SELECT_BLUE, COLOR_MAX))     return ERROR_ABORT;
    if (0x60 > Data[0])     return ERROR_ABORT;

    Margin  = Margin > Data[0] ? Data[0] : Margin;

    Margin  = (Margin - 0x20) & 0xfc;

    // Get usVer_Start, usVer_End, usH_Start, usH_Start
    if (ERROR_SUCCEED != Measure_PositionN(Margin))   return ERROR_ABORT;


#if(0)
    SetADC_Offset();
#else
	SetADC_GainOffset();
#endif

	Offset_Stop = 0;
    Color   = SELECT_BLUE;
    do
    {
        Count   = 0x30;
        
        do
        {
#if (0)
            
           if(Offset_Stop == 0)
           { 
			   ///////////////////////////////
			   // Minimum Adjustment (0x02) //
			   ///////////////////////////////
			   if (ERROR_SUCCEED != Measure_Color(Color, COLOR_MIN))   return ERROR_ABORT;
			   Margin  = Data[0];

			   if (0x0a < Margin)
			   {
				   Change_ADC_Offset(Color, 0x08, 0);          // Increase Offset; Decrease Brightness
			   }
			   else if (0x02 < Margin)
			   {
				   Change_ADC_Offset(Color, Margin - 0x02, 0); // Increase Offset; Decrease Brightness
			   }
			   else if (0x02 > Margin)
			   {
				   if (0x00 == Margin && 0 == FineTune)
					   Change_ADC_Offset(Color, 0x06, 1);              // Decrease Offset; Increase Brightness
				   else
				   {
					   Change_ADC_Offset(Color, 0x02 - Margin, 1);     // Decrease Offset; Increase Brightness

					   if(Color == SELECT_RED)
					   {
						   Offset_Stop = 1;
						   SetADC_Gain();
						   Color   = SELECT_BLUE << 1;
					   }
					   break;
				   }
			   }
		   }
		   else
		   {
			   ///////////////////////////////
			   // Maximum Adjustment (0xf2) //
			   ///////////////////////////////
			   if (ERROR_SUCCEED != Measure_Color(Color, COLOR_MAX))   return ERROR_ABORT;
			   Margin  = Data[0];

			   if (0xf2 < Margin) 
			   {
				   Result  = Margin - 0xf2;
				   
				   // Non-zero return value of Change_ADC_Gain() means ADC gain reaches maximum.
				   if (Change_ADC_Gain(Color, Result, 0))              // Increase Gain; Decrease Contrast
				   {
					   if (Change_ADC_Offset(Color, 4, 0))     break;  // Increase Offset; Decrease Brightness
				   }
			   }
			   else if (0xf2 > Margin)
			   {
				   Result  = 0xf2 - Margin;

				   // Non-zero return value of Change_ADC_Gain() means ADC gain reaches minimum.                
				   if (Change_ADC_Gain(Color, Result, 1)) 		   // Decrease Gain; Increase Contrast
				   {
					   if (Change_ADC_Offset(Color, 4, 1))     break;  // Decrease Offset; Increase Brightness
				   }
			   }
			   else
				   break;
		   }

		   if (8 < Count && 0xf3 >= Result && 0xf1 <= Result && 0x03 >= Margin && 0x01 <= Margin)
		   {
			   FineTune    = 1;
			   Count       = 8;
		   }
#endif
			

#if(1)
            ///////////////////////////////
            // Maximum Adjustment (0xf2) //
            ///////////////////////////////
            if (ERROR_SUCCEED != Measure_Color(Color, COLOR_MAX))   return ERROR_ABORT;
            Margin  = Data[0];

            if (0xf2 < Margin)
            {
                Result  = Margin - 0xf2;
                
                // Non-zero return value of Change_ADC_Gain() means ADC gain reaches maximum.
                if (Change_ADC_Gain(Color, Result, 0))              // Increase Gain; Decrease Contrast
                {
                    if (Change_ADC_Offset(Color, 4, 0))     break;  // Increase Offset; Decrease Brightness
                }
            }
            else if (0xf2 > Margin)
            {
                Result  = 0xf2 - Margin;

                // Non-zero return value of Change_ADC_Gain() means ADC gain reaches minimum.
                if (Change_ADC_Gain(Color, Result, 1))              // Decrease Gain; Increase Contrast
                {
                    if (Change_ADC_Offset(Color, 4, 1))     break;  // Decrease Offset; Increase Brightness
                }
            }

            Result  = Margin;

            ///////////////////////////////
            // Minimum Adjustment (0x02) //
            ///////////////////////////////
            
            if (ERROR_SUCCEED != Measure_Color(Color, COLOR_MIN))   return ERROR_ABORT;
            Margin  = Data[0];

            if (0x0a < Margin)
            {
                Change_ADC_Offset(Color, 0x08, 0);          // Increase Offset; Decrease Brightness
            }
            else if (0x02 < Margin)
            {
                Change_ADC_Offset(Color, Margin - 0x02, 0); // Increase Offset; Decrease Brightness
            }
            else if (0x02 > Margin)
            {
                if (0x00 == Margin && 0 == FineTune)
                    Change_ADC_Offset(Color, 0x06, 1);              // Decrease Offset; Increase Brightness
                else
                    Change_ADC_Offset(Color, 0x02 - Margin, 1);     // Decrease Offset; Increase Brightness

            }
            else if (0xf2 == Result)
            {
                break;
            }

            // Prevent redundant fine tune
            if (8 < Count && 0xf3 >= Result && 0xf1 <= Result && 0x03 >= Margin && 0x01 <= Margin)
            {
                FineTune    = 1;
                Count       = 8;
            }
#endif

#if(0)
            ///////////////////////////////
            // Maximum Adjustment (0xfd) //
            ///////////////////////////////
            if (ERROR_SUCCEED != Measure_Color(Color, COLOR_MAX))   return ERROR_ABORT;
            Margin  = Data[0];

            if (0xfd < Margin)
            {
                Result  = (0xff == Margin && 0 == FineTune) ? 0x06 : Margin - 0xfd;
                
                // Non-zero return value of Change_ADC_Gain() means ADC gain reaches maximum.
                if (Change_ADC_Gain(Color, Result, 0))              // Increase Gain; Decrease Contrast
                {
                    if (Change_ADC_Offset(Color, 4, 0))     break;  // Increase Offset; Decrease Brightness
                }
            }
            else if (0xfd > Margin)
            {
                Result  = (0xf1 > Margin) ? 0x0c : 0xfd - Margin;

                // Non-zero return value of Change_ADC_Gain() means ADC gain reaches minimum.
                if (Change_ADC_Gain(Color, Result, 1))              // Decrease Gain; Increase Contrast
                {
                    if (Change_ADC_Offset(Color, 4, 1))     break;  // Decrease Offset; Increase Brightness
                }
            }

            Result  = Margin;

            ///////////////////////////////
            // Minimum Adjustment (0x02) //
            ///////////////////////////////
            
            if (ERROR_SUCCEED != Measure_Color(Color, COLOR_MIN))   return ERROR_ABORT;
            Margin  = Data[0];

            if (0x0a < Margin)
            {
                Change_ADC_Offset(Color, 0x08, 0);          // Increase Offset; Decrease Brightness
            }
            else if (0x02 < Margin)
            {
                Change_ADC_Offset(Color, Margin - 0x02, 0); // Increase Offset; Decrease Brightness
            }
            else if (0x02 > Margin)
            {
                if (0x00 == Margin && 0 == FineTune)
                    Change_ADC_Offset(Color, 0x06, 1);              // Decrease Offset; Increase Brightness
                else
                    Change_ADC_Offset(Color, 0x02 - Margin, 1);     // Decrease Offset; Increase Brightness
            }
            else if (0xfd == Result)
            {
                break;
            }

            // Prevent redundant fine tune
            if (8 < Count && 0xfe >= Result && 0xfc <= Result && 0x03 >= Margin && 0x01 <= Margin)
            {
                FineTune    = 1;
                Count       = 8;
            }
#endif

        }
        while (--Count);

        Color   = Color >> 1;
    }
    while (Color);

#if(ANALOG_CONTRAST)
    stGUD0.CONTRAST = ucTemp;
    SetADC_Gain();
#endif 
    return ERROR_SUCCEED; 
}

unsigned char Measure_Color(unsigned char color, unsigned char margin)
{
    RTDSetByte(MARGIN_B_7D, (SELECT_RED == color) ? COLORS_RED : (SELECT_GREEN == color) ? COLORS_GREEN : COLORS_BLUE);


    Data[0] = 9;
    Data[1] = Y_INC;
    Data[2] = H_BND_STA_L_75;

    Data[3] = (unsigned char)(usH_Start + MEAS_H_STA_OFFSET - 1);
    Data[4] = (unsigned char)(usH_End + MEAS_H_END_OFFSET);
    Data[5] = ((unsigned char)((usH_Start + MEAS_H_STA_OFFSET - 1) >> 4) & 0x70) | ((unsigned char)((usH_End + MEAS_H_END_OFFSET) >> 8) & 0x0f);

    if (COLOR_MIN == margin)
    {
        Data[3] = 0x80;
        Data[4] = 0x00;
        Data[5] = 0x12;

        Data[6] = 9 < usVer_Start ? 9 : usVer_Start - 1;
        Data[7] = Data[6] + 1;
        Data[8] = 0;
    }
    else
    {
        Data[6] = (unsigned char)(usVer_Start + 1);
        Data[7] = (unsigned char)(usVer_End + 1);
        Data[8] = ((unsigned char)((usVer_Start + 1) >> 4) & 0x70) | ((unsigned char)((usVer_End + 1) >> 8) & 0x0f);
    }

    Data[9] = 0;
    RTDWrite(Data);

    if (COLOR_MIN == margin)
    	RTDSetByte(AUTO_ADJ_CTRL_7F, COLOR_MIN | 0x01); // Start the auto-adjust
	else
    	RTDSetByte(AUTO_ADJ_CTRL_7F, COLOR_MAX | 0x01); // Start the auto-adjust

    Wait_Finish();

    if (ERROR_SUCCEED != Data[0])   return ERROR_ABORT;

    RTDRead(AUTO_BAL_RESULT_88, 1, N_INC);  // Store result in Data[0]
   
    if (COLOR_MIN == margin)	Data[0]	^= 0xff;



    return ERROR_SUCCEED;
}

unsigned char Change_ADC_Gain(unsigned char color, unsigned char delta, unsigned char inc)
{
    if (inc)
    {
        inc = 0;

        if (color & SELECT_RED)
        {
            if (stGUD2.AD_R_GAIN > delta)
                stGUD2.AD_R_GAIN    -= delta;
            else
            {
                stGUD2.AD_R_GAIN    = 0;
                inc |= SELECT_RED;
            }
        }
        if (color & SELECT_GREEN)
        {
            if (stGUD2.AD_G_GAIN > delta)
                stGUD2.AD_G_GAIN    -= delta;
            else
            {
                stGUD2.AD_G_GAIN    = 0;
                inc |= SELECT_GREEN;
            }
        }
        if (color & SELECT_BLUE)
        {
            if (stGUD2.AD_B_GAIN > delta)
                stGUD2.AD_B_GAIN    -= delta;
            else
            {
                stGUD2.AD_B_GAIN    = 0;
                inc |= SELECT_BLUE;
            }
        }
    }
    else
    {
        if (color & SELECT_RED)
        {
            if ((0xff - stGUD2.AD_R_GAIN) > delta)
                stGUD2.AD_R_GAIN    += delta;
            else
            {
                stGUD2.AD_R_GAIN    = 0xff;
                inc |= SELECT_RED;
            }
        }
        if (color & SELECT_GREEN)
        {
            if ((0xff - stGUD2.AD_G_GAIN) > delta)
                stGUD2.AD_G_GAIN    += delta;
            else
            {
                stGUD2.AD_G_GAIN    = 0xff;
                inc |= SELECT_GREEN;
            }
        }
        if (color & SELECT_BLUE)
        {
            if ((0xff - stGUD2.AD_B_GAIN) > delta)
                stGUD2.AD_B_GAIN    += delta;
            else
            {
                stGUD2.AD_B_GAIN    = 0xff;
                inc |= SELECT_BLUE;
            }
        }
    }

    SetADC_Gain();
    
    return inc;
}

unsigned char Change_ADC_Offset(unsigned char color, unsigned char delta, unsigned char inc)
{
    if (inc)
    {
        inc = 0;

        if (color & SELECT_RED)
        {
            if (stGUD2.AD_R_OFFSET > delta)
                stGUD2.AD_R_OFFSET  = stGUD2.AD_R_OFFSET - delta;
            else
            {
                stGUD2.AD_R_OFFSET  = 0;
                inc |= SELECT_RED;
            }
        }
        if (color & SELECT_GREEN)
        {
            if (stGUD2.AD_G_OFFSET > delta)
                stGUD2.AD_G_OFFSET  = stGUD2.AD_G_OFFSET - delta;
            else
            {
                stGUD2.AD_G_OFFSET  = 0;
                inc |= SELECT_GREEN;
            }
        }
        if (color & SELECT_BLUE)
        {
            if (stGUD2.AD_B_OFFSET > delta)
                stGUD2.AD_B_OFFSET  = stGUD2.AD_B_OFFSET - delta;
            else
            {
                stGUD2.AD_B_OFFSET  = 0;
                inc |= SELECT_BLUE;
            }
        }
    }
    else
    {
        if (color & SELECT_RED)
        {
            if ((0xff - delta) > stGUD2.AD_R_OFFSET)
                stGUD2.AD_R_OFFSET  = stGUD2.AD_R_OFFSET + delta;
            else
            {
                stGUD2.AD_R_OFFSET  = 0xff;
                inc |= SELECT_RED;
            }

        }
        if (color & SELECT_GREEN)
        {
            if ((0xff - delta) > stGUD2.AD_G_OFFSET)
                stGUD2.AD_G_OFFSET  = stGUD2.AD_G_OFFSET + delta;
            else
            {
                stGUD2.AD_G_OFFSET  = 0xff;
                inc |= SELECT_GREEN;
            }

        }
        if (color & SELECT_BLUE)
        {
            if ((0xff - delta) > stGUD2.AD_B_OFFSET)
                stGUD2.AD_B_OFFSET  = stGUD2.AD_B_OFFSET + delta;
            else
            {
                stGUD2.AD_B_OFFSET  = 0xff;
                inc |= SELECT_BLUE;
            }
        }
    }

    SetADC_Offset();
    
    return inc;
}

