
#define __MODEDETECT__

#include "Header\Lcd_func.h"
#include "Header\Lcd_Main.h"
#include "Header\Access.h"
#include "Header\config.h"
#include "Header\OSD.h"
#include "Header\Lcd_Auto.h"
#include "Header\Frame_Sync.h"
#include "Header\Src_Ctrl.h"
#include "Header\LCD_OSD.h"


/////////////////////////////////////////////////////////
//-------------------  Mode Detector  -----------------//
/////////////////////////////////////////////////////////
void Mode_Detector(void)
{

    switch (stGUD1.INPUT_SOURCE & 0x07)
    {
    case SOURCE_VGA :
	case SOURCE_DVI :
        // Save previous values of ucMode_Curr, bHpole_Curr and bVpole_Curr
        bHpole_Prev = bHpole_Curr;
        bVpole_Prev = bVpole_Curr;
        
        if ((MODE_NOSIGNAL == ucMode_Curr) || (MODE_NOSUPPORT == ucMode_Curr))
            Detect_Input_Mode();
        else
            Check_Input_Mode();
        break;

   default :
        if ((MODE_NOSIGNAL == ucMode_Curr) || (MODE_NOSUPPORT == ucMode_Curr))
            Detect_Video_Mode();        // Set default polarity 
        else
            Check_Video_Mode();         // Set polarity after measure
        break;
    }

    Measure_Mode();     // Measure mode-timing
}

void Measure_Mode(void)
{

    
    switch (stGUD1.INPUT_SOURCE & 0x07)
    {
	    RTDSetByte(SYNC_CTRL_4A,0x00);
	case SOURCE_VGA :
		RTDSetByte(SYNC_POR_4C, (SYNC_SS == ucSync_Type) ? 0x02 : 0x32);
	break;
	
 	case SOURCE_DVI :
/*//eric 0729 test issue:DVI source change 		
#if (TMDS_ENABLE)
        if (0 == ucTMDS_SEARCH_COUNTER && MODE_NOSIGNAL == ucMode_Curr) // V101C modified
        {
            RTDCodeW(TMDS_MANUAL_ON);

            ucTMDS_SEARCH_COUNTER  = 0x08;
        }        
        ucTMDS_SEARCH_COUNTER -= 0x01;
#endif
*/
		RTDSetByte(SYNC_POR_4C, 0x02);
	break;
	
	default :
		RTDSetByte(SYNC_POR_4C, 0x02);
	break;
    }
	
}

#if(SOURCE_AUTO_SCAN)
/////////////////////////////////////////////////////////
//---Detect which source with valid signal-------------//
/////////////////////////////////////////////////////////
void Measure_Source(unsigned char SOURCE)
{
   switch(SOURCE)
   {
   case SOURCE_VGA:
		RTDSetByte(SYNC_CTRL_4A,0x01);
		break;
   case SOURCE_DVI:
		RTDSetByte(SYNC_CTRL_4A,0x03);
		break;
   case SOURCE_AV:
        I2CWrite(V_ENABLE);
        I2CWrite(AV_DETECT);
        break;
   case SOURCE_SV:
        I2CWrite(V_ENABLE);
        I2CWrite(SV_DETECT);
		break;
   }
   //RTDSetByte(SYNC_POR_4C, 0x32);
   //RTDSetByte(SYNC_POR_4C, 0x02);
   //RTDSetByte(SYNC_POR_4C, (stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA ? 0x32 : 0x02);
   
   if(((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) && (SYNC_SS != ucSync_Type))
       RTDSetByte(SYNC_POR_4C,0x32);
   else
       RTDSetByte(SYNC_POR_4C,0x02);
   
   Delay_Xms(35);
   //Delay_Xms(24);
   

}
#endif

unsigned char VGA_Mode_Search(unsigned int HS_Pulse)
{
  unsigned char ucMode_Temp,m;
  Data[0] = HS_Pulse * 12 / usHsync;    // 0 : 720x350; 1 : 640x350;

  ucMode_Temp = MODE_NOSUPPORT;

  // Search for Standard Mode
  m   = MODE_1280x1024x75HZ;		//anson
//  m   = MODE_1600x1200x60HZ;
  do
  {
	  if ((usHsync > VGA_Mode[m][0]) && (usHsync < VGA_Mode[m][1]))
	  {   
		  if ((usVsync >= VGA_Mode[m][2]) && (usVsync <= VGA_Mode[m][3]))
		  {
			  if (MODE_1280x1024x75HZ == m)
			  {
				  if (0 == (bVpole_Curr | bHpole_Curr))   m   = MODE_1280x1024x76HZ;  // SUN 1024-76
			  }                            
			  else if (MODE_1024x0768x75HZ == m)
			  {
				  if (0 == (bVpole_Curr | bHpole_Curr))   m   = MODE_1024x0768x74HZ;  // MAC768-75
			  }         
			  else if (MODE_0640x0480x60HZ == m && bVpole_Curr != bHpole_Curr)
			  {
				  // MODE_VGA350x60Hz         : 640x350 60Hz
				  // MODE_VGA350x60Hz | 0x40  : 720x350 60Hz
				  // MODE_VGA400x60Hz         : 640x400 60Hz
				  // MODE_VGA400x60Hz | 0x40  : 720x400 60Hz
				  if (bHpole_Curr)
					  m   = Data[0] ? MODE_VGA350x60Hz : MODE_VGA350x60Hz | 0x40;
				  else
					  m   = (stGUD1.FUNCTION & 0x10) ? MODE_VGA400x60Hz : MODE_VGA400x60Hz | 0x40;
				  //m   = (stGUD1.INPUT_SOURCE & 0x80) ? MODE_VGA400x60Hz : MODE_VGA400x60Hz | 0x40;
			  }
			  else if (MODE_0640x0480x50HZ == m && bVpole_Curr != bHpole_Curr)
			  {
				  // MODE_VGA350x50Hz         : 640x350 50Hz
				  // MODE_VGA350x50Hz | 0x40  : 720x350 50Hz
				  // MODE_VGA400x50Hz         : 640x400 50Hz
				  // MODE_VGA400x50Hz | 0x40  : 720x400 50Hz
				  if (bHpole_Curr)
					  m   = Data[0] ? MODE_VGA350x50Hz : MODE_VGA350x50Hz | 0x40;
				  else
					  m   = (stGUD1.FUNCTION & 0x10) ? MODE_VGA400x50Hz : MODE_VGA400x50Hz | 0x40;
				  //m   = (stGUD1.INPUT_SOURCE & 0x80) ? MODE_VGA400x50Hz : MODE_VGA400x50Hz | 0x40;
			  }
			  else if (MODE_0720x0400x85HZ == m)
			  {
				  if (1 == bHpole_Curr && 0 == bVpole_Curr)
					  m   = MODE_0640x0350x85HZ;
				  else if (stGUD1.FUNCTION & 0x10)     //else if (stGUD1.INPUT_SOURCE & 0x80)     
					  m   = MODE_0640x0400x85HZ;
			  }
			  else if (MODE_0720x0400x70HZ == m)
			  {
				  if (1 == bHpole_Curr && 0 == bVpole_Curr)
					  m   = Data[0] ? MODE_0640x0350x70HZ : MODE_0720x0350x70HZ;
				  else if ((stGUD1.FUNCTION & 0x10)==0)     //else if (stGUD1.INPUT_SOURCE & 0x80)		//anson
//				  else if (stGUD1.FUNCTION & 0x10)     //else if (stGUD1.INPUT_SOURCE & 0x80)
					  m   = MODE_0640x0400x70HZ;
			  }
			  else if (MODE_1024x0768x59HZ == m)
			  {
				  if(HS_Pulse > 45)
					  m = MODE_1024x0768x60HZ;
			  }
			  else if (MODE_1024x0768x60HZ == m)
			  {
				  if(HS_Pulse <= 45)
					  m = MODE_1024x0768x59HZ;					   
			  }
			  else if(MODE_1024x0768x72HZ == m)			//anson 05_0321
			  {
			  	  if(ucRefresh <= 71)
			  	   m = MODE_1024x0768x70HZ;
			  }

			  ucMode_Temp     = m;
		  }
	  }
  }
  while ((0 != --m) && (MODE_NOSUPPORT == ucMode_Temp));
  
  // Search for User Mode
  if (MODE_NOSUPPORT == ucMode_Temp)
  {
	  usIPV_ACT_LEN   = 0;

	  m   = MODE_USER1280x1024;		//anson
//	  m   = MODE_USER1600x1200;
	  do
	  {
		  if ((usVsync >= VGA_Mode[m][2]) && (usVsync <= VGA_Mode[m][3]))
		  {
			  usIPV_ACT_LEN   = CAP_WIN[m][4];
			  
			  if ((usHsync >= VGA_Mode[m][0]) && (usHsync <= VGA_Mode[m][1]))
			  {
				  ucMode_Temp     = m;    // Support User Mode
			  }
		  }
	  }
	  while ((MODE_USER720x400 <= --m) && (MODE_NOSUPPORT == ucMode_Temp));
  }

  return ucMode_Temp;

}

unsigned char Partial_Display(void)
{
	unsigned char ucMode_Temp;

	if (DISP_LEN < usIPV_ACT_LEN)   // V Scale-down
	{
		// Estimate display clock rate for full screen
		// DCLK = (24.576MHz / usHsync) * DCLK per display line * (display image lines / input image lines)
		((unsigned int *)Data)[0]   = (unsigned long)2458 * Mode_Preset[MODE_UNDEFINED1][0] * DISP_LEN 
			/ ((unsigned long)100 * usIPV_ACT_LEN * usHsync);

		if (MAX_DCLK < ((unsigned int *)Data)[0])
		{
			// If clock rate for full-screen display is too high, we can try partial-V display.
			// Estimate clock for partial-V display
			// DCLK = (24.576MHz / usHsync) * DCLK per display line * (min. display total lines / input total lines)
			((unsigned int *)Data)[1]   = (unsigned long)2458 * Mode_Preset[MODE_UNDEFINED1][0] * MIN_DV_TOTAL
				/ ((unsigned long)100 * (usVsync - 1) * usHsync);

			if (MAX_DCLK < ((unsigned int *)Data)[1])
			{
				// Decrease usIPV_ACT_LEN to DISP_LEN and go further to check if it can be displayed.
				usIPV_ACT_LEN   = DISP_LEN;
			}
			else
			{
				ucMode_Temp     = MODE_UNDEFINED1 | 0x80;   // Scale-down and partial-V display
			}
		}
		else
			ucMode_Temp     = MODE_UNDEFINED1;              // Scale-down and full-V display
	}
	
	if (DISP_LEN >= usIPV_ACT_LEN)  // V Scale-up
	{
		((unsigned int *)Data)[0]   = (unsigned long)2458 * Mode_Preset[MODE_UNDEFINED0][0] * DISP_LEN 
			/ ((unsigned long)100 * usIPV_ACT_LEN * usHsync);

		if (MAX_DCLK < ((unsigned int *)Data)[0])
		{
			if (MIN_DV_TOTAL >= (usVsync - 1))
			{
				((unsigned int *)Data)[1]   = (unsigned long)2458 * Mode_Preset[MODE_UNDEFINED0][0] * MIN_DV_TOTAL
					/ ((unsigned long)100 * (usVsync - 1) * usHsync);
			}
			else
			{
				((unsigned int *)Data)[1]   = (unsigned long)2458 * Mode_Preset[MODE_UNDEFINED0][0]
					/ ((unsigned long)100 * usHsync);
			}
			
			if (MAX_DCLK < ((unsigned int *)Data)[1])   
				ucMode_Temp = MODE_NOSUPPORT;           // Cannot display
			else
				ucMode_Temp = MODE_UNDEFINED0 | 0x80;   // Scale-up and partial-V display
		}
		else
			ucMode_Temp = MODE_UNDEFINED0;              // Scale-up and full-V display
	}

	return ucMode_Temp;

}

void Sync_Type_Switch(void)
{
	if (MODE_NOSIGNAL == ucMode_Curr)
	{
		if (SYNC_CS == ucSync_Type)         // CS->SS
		{
			RTDCodeW(VGA_SET_SS);

			bVpole_Curr = 1;
			bHpole_Curr = 1;
			ucSync_Type = SYNC_SS;
			
		}
		else if (SYNC_SS == ucSync_Type)    // SS->SOG
		{
			RTDCodeW(VGA_SET_SOG);

			bVpole_Curr = 1;
			bHpole_Curr = 1;
			ucSync_Type = SYNC_SOG;
			
			

		}
		else                                // SOG->CS
		{
			RTDCodeW(VGA_SET_CS);

			bVpole_Curr = 1;
			bHpole_Curr = 1;
			ucSync_Type = SYNC_CS;
			
			

		}
	}
}

void Sync_Type_Confirm(void)
{
  
#if(SOURCE_AUTO_SCAN == _FALSE)
unsigned char m;
            
// To prevent from mistaking CS (with VS) for SS, we check SYNC type once when finding a mode in SS.
            
      if (SYNC_SS == ucSync_Type)
	  {           
		  RTDSetByte(SYNC_CTRL_4B, 0x55);

		  RTDSetByte(SYNC_POR_4C, 0x22);

		  m   = (MODE_DETECT_FREQ + 1) * 20;       
		  do
		  {   
			  Delay_Xms(1);
			  RTDRead(SYNC_POR_4C, 0x05, Y_INC);
		  }
		  while ((Data[0] & 0x02) && (--m));
		  
		  Data[5] = Data[3];
		  Data[4] = Data[4] & 0x87;
		  Data[3] = Data[1];
		  Data[2] = Data[2] & 0x8f;

		  if ((0 == ((unsigned int *)Data)[1]) || (0x07ff <= ((unsigned int *)Data)[1]) ||
			  (0 == ((unsigned int *)Data)[2]) || (0x07ff <= ((unsigned int *)Data)[2]) ||
			  (0 == m))
		  {
			  ucSync_Type = SYNC_SS;

			  RTDSetByte(SYNC_CTRL_4B, 0x14);
		  }
		  else
		  {
			  ucSync_Type = SYNC_CS;

			  RTDCodeW(VGA_SET_CS);

			  bVpole_Curr = 1;
			  bHpole_Curr = 1;
		  }
	  }
	  else if (SYNC_SOG == ucSync_Type)
	  {
		  RTDSetByte(SYNC_CTRL_4B, 0x14);
		  Delay_Xms(8);

		  RTDSetByte(SYNC_POR_4C, 0x00);
		  RTDSetByte(SYNC_POR_4C, 0x02);
		  

		  m   = (MODE_DETECT_FREQ + 1) * 20;       
		  do
		  {   
			  Delay_Xms(1);
			  RTDRead(SYNC_POR_4C, 0x05, Y_INC);
		  }
		  while ((Data[0] & 0x02) && (--m));
		  
		  Data[5] = Data[3];
		  Data[4] = Data[4] & 0x87;
		  Data[3] = Data[1];
		  Data[2] = Data[2] & 0x8f;

		  if ((0 == ((unsigned int *)Data)[1]) || (0x07ff <= ((unsigned int *)Data)[1]) ||
			  (0 == ((unsigned int *)Data)[2]) || (0x07ff <= ((unsigned int *)Data)[2]) ||
			  (0 == m))
		  {
			  ucSync_Type = SYNC_SOG;

			  
			  RTDSetByte(SYNC_CTRL_4B, 0x57);
			  //RTDSetByte(VGIP_SIGINV_05, 0x40);
			  Delay_Xms(8);
			  
			  RTDSetByte(SYNC_POR_4C,0x32);
			  Delay_Xms(20);
			  RTDSetByte(SYNC_POR_4C, 0x00);
			  
		  }
		  else
		  {
			  ucSync_Type = SYNC_SS;

			  RTDCodeW(VGA_SET_SS);

			  bVpole_Curr = 1;
			  bHpole_Curr = 1;
		  }
	  }
#endif

}
/////////////////////////////////////////////////////////
//------------  Detect VGA & DVI Mode  ----------------//
/////////////////////////////////////////////////////////
void Detect_Input_Mode(void)
{
    unsigned char   ucMode_Temp;
    unsigned int    usHS_Pulse;

    RTDRead(SYNC_POR_4C, 0x09, Y_INC);

    if (Data[0] & 0x02)
    {
        // Reset Sync Processor when sync signal timeout
        RTDSetByte(SYNC_POR_4C, ((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) ? 0x20 : 0x00);

        // Treat sync signal timeout as no signal
        ucMode_Temp     = MODE_NOSIGNAL;
    }
    else			
    {
          
//        ucMode_Temp = (Data[8] & 0xe0 ) >> 5;

//        if(ucMode_Temp == 0 || ucMode_Temp >=4) //Test which edge of Hsync to latch Vsync will be safe
//		{
//           RTDSetBit(MEAS_VS_HI_54,0xf7,0x08);  //Use positive edge of Hsync to latch Vsync
//		   ucDebug_Value0 = 0x08;
//		}
//		else
//		{
//		   RTDSetBit(MEAS_VS_HI_54,0xf7,0x00);  //Use negtive edge of Hsync to latch Vsync
//		   ucDebug_Value0 = 0x18;
//		}

        
        usStdHS   = usHsync;  // Save previous usHsync in usStdHS
        usStdVS   = usVsync;  // Save previous usVsync in usStdVS

        bVpole_Curr = (bit)(Data[0] & 0x08);    // Save current usVsync polarity
        bHpole_Curr = (bit)(Data[0] & 0x04);    // Save current usHsync polarity

        Data[7] = Data[5];
        Data[6] = Data[6] & 0x0f;
        Data[5] = Data[3];
        Data[4] = Data[4] & 0x87;
        Data[3] = Data[1];
        Data[2] = Data[2] & 0x8f;

        usHsync     = ((unsigned int *)Data)[1];    // Current HSYNC timing
        usVsync     = ((unsigned int *)Data)[2];    // Current VSYNC timing

        if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
            usHS_Pulse  = ((unsigned int *)Data)[3];    // Current HSYNC pulse width

        // Calculate Vertical Refresh Rate
        // Original Formula :
        // ucRefresh = 24.576M / (usHsync * usVsync)
        // Use Data[0~3] as a temporary long variable
        ((unsigned long *)Data)[0]  = (unsigned long)usHsync * usVsync;
        ucRefresh   = (unsigned long)49152000 / ((unsigned long *)Data)[0];
        ucRefresh   = (ucRefresh & 0x01) ? ((ucRefresh + 1) >> 1) : (ucRefresh >> 1);

        // Treat small change of usHsync/usVsync as no change
        if (usStdHS <= usHsync && (usStdHS + 2) >= usHsync)     usHsync = usStdHS;
        if (usStdVS <= usVsync && (usStdVS + 2) >= usVsync)     usVsync = usStdVS;

        // Polarity must be correct
        if ((bVpole_Curr != bVpole_Prev) || (bHpole_Curr != bHpole_Prev))
        {  
            RTDRead(VGIP_SIGINV_05, 0x01, N_INC);
          
            if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
            {
               Data[0] &= 0xd7;  // HS_RAW & VS positive

               if (!bHpole_Curr)    Data[0] |= 0x20;
            
               if (!bVpole_Curr && SYNC_SS == ucSync_Type)     Data[0] |= 0x08;    // Seperate sync

			   ucMode_Temp     = MODE_NOSUPPORT;
            }
            else if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_DVI)
            {
               Data[0] &= 0xf3;  // VS & HS positive

               if (!bVpole_Curr)    Data[0] |= 0x08;
               if (!bHpole_Curr)    Data[0] |= 0x04;
            }            
            RTDSetByte(VGIP_SIGINV_05, Data[0]);

            
        }
        else
        {
            if (0x07ff <= usHsync || 0x07ff <= usVsync || 0 == usHsync || 0 == usVsync)
            {
                ucMode_Temp     = MODE_NOSIGNAL;        // Treat overflow as no signal
            }
            else
            {
                ucMode_Temp = ((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) ? VGA_Mode_Search(usHS_Pulse) : MODE_NOSUPPORT;
				

                if (48 > ucRefresh || MAX_RATE < ucRefresh)
                {
                    ucMode_Temp = MODE_NOSUPPORT;   // We don't support vertical refresh rate lower than 50Hz
                }
                else if (MODE_NOSUPPORT == ucMode_Temp && (0 != usIPV_ACT_LEN) && ((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA))
                {			    
				        ucMode_Temp = Partial_Display();
				}
				else if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_DVI)
				      ucMode_Temp = Seek_DVI_Mode(ucMode_Temp);

//				ucDebug_Value0 = ucMode_Temp;
	        }
        }
    }

	if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
	{
        if (SYNC_SOG == ucSync_Type && 0 != (usHS_Pulse * 7 / usHsync))
        {
          // To prevent from SOG mode mistake
          // HSYNC pulse width will never longer than 1/7*HSYNC period
          ucMode_Temp = MODE_NOSIGNAL;
        }
	}

    //-------------Check result-----------------------------------------
    if (MODE_NOSUPPORT == ucMode_Temp || MODE_NOSIGNAL == ucMode_Temp)
    {
        // Treat illegal signal as no signal when SOG
		if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
		{
           if (SYNC_SOG == ucSync_Type)    
		       ucMode_Temp = MODE_NOSIGNAL;
		 }

        if (MODE_NOSUPPORT != ucMode_Found && MODE_NOSIGNAL != ucMode_Found)    ucMode_Times    = 0;

        ucMode_Found    = ucMode_Temp;

        if (NO_MODE_TIMES > ucMode_Times)
        {
            // Wait for signal stable
            ucMode_Times ++;

			if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_DVI)
			{
			   //Enable the TMDS Hsync & Vsync error correction to improve the long cable image quality
               RTDSetByte(TMDS_CORRECTION_FF,0x03);
			}
        }
        else
        {
		    if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_DVI)
			{
			   //Disable the TMDS Hsync & Vsync error correction
               RTDSetByte(TMDS_CORRECTION_FF,0x00);
			}

            bStable         = (ucMode_Curr == ucMode_Found) ? 1 : 0;    // bStable must be cleared when mode changed
            ucMode_Curr     = ucMode_Found;
            ucMode_Times    = NO_MODE_TIMES - 2;

			if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
			    Sync_Type_Switch();
            
        }
    }
    else
    {
        if (ucMode_Found != ucMode_Temp)
        {
            ucMode_Times    = 1;
            ucMode_Found    = ucMode_Temp;

			if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
			    Sync_Type_Confirm();
        }
        else
        {   
		    Data[0] = ((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) ? VGA_SEARCH_TIMES : DVI_SEARCH_TIMES;
            //if (VGA_SEARCH_TIMES > ucMode_Times)
			if (Data[0] > ucMode_Times)
            {
                ucMode_Times ++;
            }
            else
            {

                bLIGHT_PWR  = LIGHT_OFF;        // Turn off BackLight for reset display
              
                RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
                RTDOSDW(OSD_Reset);            // Clear OSD

                ucMode_Curr     = ucMode_Found; // Supported mode found
                ucMode_Times    = 0;            // Reset mode timer
                bStable         = 0;            // bStable must be cleared when mode changed

				if((stGUD1.INPUT_SOURCE & 0x07)== SOURCE_VGA)
                    Display_VGA_Set();              // Set VGA Mode registers
				else
				    Display_DVI_Set();

				
#if (RTDDEBUG)
                if (ucMode_PrevAct == ucMode_Curr)
                {
                    if (0xff > ucMode_QuitCnt)      ucMode_QuitCnt += 1;
                }
                else
                {
                    ucMode_PrevAct  = ucMode_Curr;
                    ucMode_QuitCnt  = 0;
                    ucDebug         = 0;
                }
#endif                
            }
        }
    }
}

//-------------------  Check VGA & DVI Mode  -------------------//
void Check_Input_Mode(void)
{    
    RTDRead(SYNC_POR_4C, 0x05, Y_INC);

    if (Data[0] & 0x02)
    {
        RTDSetByte(SYNC_POR_4C, ((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) ? 0x20 : 0x00);          // Input signal time-out. Reset sync-processor

        ucMode_Found    = MODE_NOSUPPORT;
    }
    else			
    {
        bVpole_Curr = (bit)(Data[0] & 0x08);    // Current usVsync polarity
        bHpole_Curr = (bit)(Data[0] & 0x04);    // Current usHsync polarity

        Data[5] = Data[3];
        Data[4] = Data[4] & 0x87;
        Data[3] = Data[1];
        Data[2] = Data[2] & 0x8f;
        usHsync = ((unsigned int *)Data)[1];    // Current usHsync timing
        usVsync = ((unsigned int *)Data)[2];    // Current usVsync timing

        // Polarity must be correct
        if ((bVpole_Curr != bVpole_Prev) || (bHpole_Curr != bHpole_Prev))
        {
            RTDRead(VGIP_SIGINV_05, 0x01, N_INC);
            /*
            Data[0] &= 0xd7;    // HS_RAW & VS positive

            if (!bHpole_Curr)   Data[0] |= 0x20;

            if (!bVpole_Curr && SYNC_SS == ucSync_Type)     Data[0] |= 0x08;    // Seperate sync
            */
            

            if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
            {
                 Data[0] &= 0xd7;    // HS_RAW & VS positive

                 if (!bHpole_Curr)   Data[0] |= 0x20;

                 if (!bVpole_Curr && SYNC_SS == ucSync_Type)     Data[0] |= 0x08;    // Seperate sync
            }
            else if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_DVI)
            {
                 Data[0] &= 0xf3;  // VS & HS positive

                 if (!bVpole_Curr)    Data[0] |= 0x08;
                 if (!bHpole_Curr)    Data[0] |= 0x04;
            }

            RTDSetByte(VGIP_SIGINV_05, Data[0]);

            ucMode_Found    = MODE_NOSUPPORT;
        }
        else
        {
            if (0x07ff <= usHsync || 0x07ff <= usVsync || 0 == usHsync || 0 == usVsync)     // Check overflow
            {
                ucMode_Found    = MODE_NOSUPPORT;
            }
            else
            {
                if ((usHsync < (usStdHS - 1)) || (usHsync > (usStdHS + 3)) ||
                    (usVsync < (usStdVS - 1)) || (usVsync > (usStdVS + 3)))
                {   
                    ucMode_Found    = MODE_NOSUPPORT;
                }
                else
                {
                    ucMode_Found    = ucMode_Curr;
                }
            }
        }
    }
    
    if (MODE_NOSUPPORT == ucMode_Found)
	        Reset_Mode();
    else
	{
        bStable = 1;    // Set bStable to 1 when signal timing is stable.
#if(AS_NON_FRAMESYNC)
        RTDSetByte(STATUS0_01, 0x00);  // Clear status
        RTDSetByte(STATUS1_1F, 0x00);  // Clear status

        if(bFrameSync)
           RTDSetBit(ODD_CTRL_8E,0xef,0x10);
#endif
    }

}




unsigned char Seek_DVI_Mode(unsigned char mode)
{
#if(TMDS_ENABLE)
    unsigned char   Wait_Time_Cnt;

    RTDSetByte(SYNC_POR_4C, 0x03);  // Measure data enable width and height

    Wait_Time_Cnt  = 60;       
    do
    {   
        Delay_Xms(1);
        RTDRead(SYNC_POR_4C, 0x07, Y_INC);
    }
    while ((Data[0] & 0x02) && (--Wait_Time_Cnt));

    Data[7] = Data[5];
    Data[6] = Data[6] & 0x0f;
    Data[5] = Data[3];
    Data[4] = Data[4] & 0x87;
    Data[3] = Data[1];
    Data[2] = Data[2] & 0x8f;

    // Measure Failed !!!
    if ((0 == ((unsigned int *)Data)[1]) || (0x07ff <= ((unsigned int *)Data)[1]) ||
        (0 == ((unsigned int *)Data)[2]) || (0x07ff <= ((unsigned int *)Data)[2]) ||
        (0 == Wait_Time_Cnt))
    {
        RTDSetByte(SYNC_POR_4C, 0x00);

        return MODE_NOSUPPORT;
    }

    // Save IH_TOTAL in usADC_Clock
    usADC_Clock     = ((unsigned int *)Data)[1] * 2;

    // Save input data enable width and height
    usIPV_ACT_LEN   = ((unsigned int *)Data)[2];
    usIPH_ACT_WID   = ((unsigned int *)Data)[3] * 2;

    // We don't support input image less than 350 active lines
    if (350 > usIPV_ACT_LEN)    return MODE_NOSUPPORT;

    // We only support 8N active width
    usIPH_ACT_WID   = (2 < (usIPH_ACT_WID & 0x0007)) ? ((usIPH_ACT_WID + 8) & 0xfff8) : (usIPH_ACT_WID & 0xfff8);

    // We only support active width not larger than 1280
    if (1280 < usIPH_ACT_WID)   usIPH_ACT_WID   = 1280;

    // Calculate maximum usIPV_ACT_LEN limitation
    ((unsigned int *)Data)[0]   = (unsigned long)(usVsync - 1) * DISP_LEN / MIN_DV_TOTAL;

    if (((unsigned int *)Data)[0] < usIPV_ACT_LEN)      usIPV_ACT_LEN   = ((unsigned int *)Data)[0];

    mode    = MODE_UNDEFINED0;
  
    if (MODE_UNDEFINED0 == mode)
    {
        // First, we try user-mode to fit the undefined mode for full-screen display.
        Wait_Time_Cnt   = MODE_USER720x400;
        do
        {
            if (Mode_Preset[Wait_Time_Cnt][2] < CAP_WIN[Wait_Time_Cnt][4])   // V scale-down
            {
                // Larger scale-down ratio may need a larger DH_TOTAL. 
                // So usIPV_ACT_LEN should not be too larger than pre-set capture window length
                if (Mode_Preset[Wait_Time_Cnt][2] > usIPV_ACT_LEN || (CAP_WIN[Wait_Time_Cnt][4] + 24) < usIPV_ACT_LEN)   continue;
            }
            else
            {
                if (Mode_Preset[Wait_Time_Cnt][2] < usIPV_ACT_LEN)   continue;
            }

            ((unsigned int *)Data)[0]   = (unsigned long)2458 * Mode_Preset[Wait_Time_Cnt][0] * Mode_Preset[Wait_Time_Cnt][2]
                                        / ((unsigned long)100 * usIPV_ACT_LEN * usHsync);
            
            // Return if we find out a suitable user-mode.
            if (MAX_DCLK > ((unsigned int *)Data)[0])   return Wait_Time_Cnt;
        }
        while (MODE_USER1600x1200 >= ++Wait_Time_Cnt);

		mode = Partial_Display();
        // If failed, we try partial-screen display.

    }
	

    return  mode;
#else
    mode    = MODE_UNDEFINED0;
    return  0;
#endif
}

/////////////////////////////////////////////////////////
//------------------ Detect VIDEO Mode ----------------//
/////////////////////////////////////////////////////////
void Detect_Video_Mode(void)
{
#if(VIDEO_CHIP != VDC_NONE)
    I2CRead(ADDR_VIDEO, 0x1f, 0x01);

    //------ Check Horizontal Lock & Frequency ------
    if (0 == (Data[0] & 0x40))
    {   
        if ((Data[0] & 0x20) && (0x01 != (ucAV_Mode & 0x0f)))
        {
            // Field rate changed to 60Hz
            ucAV_Mode       = 0x01;
            ucMode_Found    = MODE_NOSUPPORT;
            ucMode_Times    = 0;

            Data[0] = 4;
            Data[1] = ADDR_VIDEO;
            Data[2] = 0x0e;
            Data[3] = 0x08;     // Start color search from NTSC-M
            I2CWrite(Data);
        }
        else if ((0 == (Data[0] & 0x20)) && (0x02 != (ucAV_Mode & 0x02)))
        {
            // Field rate changed to 50Hz
            ucAV_Mode       = 0x02; 
            ucMode_Found    = MODE_NOSUPPORT;
            ucMode_Times    = 0;
            
            Data[0] = 4;
            Data[1] = ADDR_VIDEO;
            Data[2] = 0x0e;
            Data[3] = 0x08;     // Start color search from PAL-BDGHI
            I2CWrite(Data);
        }
        else
        {    
            //------ Check Lock Color ------
            if (0x01 == (Data[0] & 0x01))
            {   
                // Lock Color
                if (ucAV_Mode & 0x01)
                {
                    if (MODE_VIDEO60HZ == ucMode_Found)
                    {
                        ucMode_Times ++;
                    }
                    else
                    {
                        ucMode_Found    = MODE_VIDEO60HZ;
                        ucMode_Times    = 0;
                    }
                }
                else
                {
                    if (MODE_VIDEO50HZ == ucMode_Found)
                    {
                        ucMode_Times ++;
                    }
                    else
                    {
                        ucMode_Found    = MODE_VIDEO50HZ;
                        ucMode_Times    = 0;
                    }
                }
            }
            else
            {
                // Non Lock Color
                if (MODE_NOSUPPORT != ucMode_Found)
                {
                    ucMode_Found    = MODE_NOSUPPORT;
                    ucMode_Times    = 0;
                }
                
                Data[0] = 4;
                Data[1] = ADDR_VIDEO;
                Data[2] = 0x0e;
                
                if (0x03 == (ucAV_Mode & 0x03))
                {
                    // SECAM -> PAL-BDGHI(50Hz)
                    Data[3] = 0x08;
                    I2CWrite(Data);                    
                    ucAV_Mode   = 0x02;
                }
                else
                {
                    if (ucMode_Times & 0x01)    // Every 2-times , change color
                    {
                        switch (ucAV_Mode & 0x70)
                        {
                        case 0x00:  
                            Data[3] = 0x18; // NTSC-4.43(50Hz)  // PAL-4.43(60Hz)
                            I2CWrite(Data);
                            ucAV_Mode   = (ucAV_Mode & 0x0f) | 0x10;
                            break;
                        case 0x10:
                            Data[3] = 0x28; // PAL-N(50Hz)      // NTSC-4.43(60Hz)
                            I2CWrite(Data);
                            ucAV_Mode   = (ucAV_Mode & 0x0f) | 0x20;
                            break;
                        case 0x20:
                            Data[3] = 0x38; // NTSC-N(50Hz)     // PAL-M(60Hz)
                            I2CWrite(Data);
                            ucAV_Mode   = (ucAV_Mode & 0x0f) | 0x30;
                            break;
                        case 0x30:
                            if (ucAV_Mode & 0x02)
                            {
                                // NTSC-N -> SECAM (50Hz)
                                Data[3]     = 0x5c;
                                I2CWrite(Data);
                                ucAV_Mode   = 0x03;
                            }
                            else
                            {	
                                // PAL-M -> NTSC_M (60Hz)
                                Data[3]     = 0x08;
                                I2CWrite(Data);
                                ucAV_Mode   = ucAV_Mode & 0x0f | 0x00;
                            }    
                        default:
                            break;
                        }//end of "switch (ucAV_Mode & 0x70)"
                    }//end of "if (ucMode_Times & 0x01)"	
                }//end of "if (0x03 == (ucAV_Mode & 0x03)) else"
            }//end of "Non Lock color
        }//end of "Check Lock Color"
    }//end of "if (0==(Data[0] & 0x40))"
    else
    {   
        // Non Horizontal Lock
        ucAV_Mode   = 0;
        
        if (ucMode_Found != MODE_NOSUPPORT)
        {
            ucMode_Found    = MODE_NOSUPPORT;
            ucMode_Times    = 0;
        }
    }
    
    //-------------Check result--------------
    if (MODE_NOSUPPORT != ucMode_Found)
    {   
        if (VIDEO_SEARCH_TIMES < ucMode_Times)
        {

            bLIGHT_PWR  = LIGHT_OFF;        // Turn off BackLight for reset display
            
            RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
            RTDOSDW(OSD_Reset);            // Clear OSD
            
            if (SOURCE_YUV == (stGUD1.INPUT_SOURCE & 0x07))
                ucMode_Curr = (ucAV_Mode & 0x02) ? MODE_YUV50HZ : MODE_YUV60HZ;
            else
                ucMode_Curr = ucMode_Found;
                    
            ucMode_Times    = 0;
            bStable         = 0;            // bStable must be cleared when mode changed

            Display_Video_Set();            
        }
    }
    else
    {
        ucMode_Times ++;
        
        if (ucAV_Mode)
        {
            // Force to display although we cannot lock color
            if (VIDEO_SEARCH_TIMES < ucMode_Times 
                && (NO_COLOR_TIMES < ucMode_Times || SOURCE_YUV == (stGUD1.INPUT_SOURCE & 0x07)))
            {

                bLIGHT_PWR  = LIGHT_OFF;        // Turn off BackLight for reset display

                RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
                RTDOSDW(OSD_Reset);            // Clear OSD
                
                ucAV_Mode       = (ucAV_Mode & 0x02) ? 0x82 : 0x81;

                if (SOURCE_YUV != (stGUD1.INPUT_SOURCE & 0x07))
                    ucMode_Curr = (ucAV_Mode & 0x02) ? MODE_VIDEO50HZ : MODE_VIDEO60HZ;
                else
                    ucMode_Curr = (ucAV_Mode & 0x02) ? MODE_YUV50HZ : MODE_YUV60HZ;

                ucMode_Times    = 0;
                bStable         = 0;    // bStable must be cleared when mode changed

                Display_Video_Set();
            }
        }
        else
        {
            if (NO_MODE_TIMES < ucMode_Times)
            {
                bStable         = 1;    // Set bStable to 1 when signal timing is stable.

                ucMode_Times    = NO_MODE_TIMES - 1;
            }
        }
    }
#else
    Display_Video_Set();
#endif
}


//-------------------  Check AV Mode  -------------------//
void Check_Video_Mode(void)
{   
#if(VIDEO_CHIP != VDC_NONE)
    I2CRead(ADDR_VIDEO, 0x1f, 0x01);
    
    // Check color
    if (0 == (ucAV_Mode & 0x80))
    {
        if (0 == (Data[0] & 0x01))      ucMode_Curr = MODE_NOSIGNAL;    // Color standard changed
    }
    else
    {
        if (0 == (Data[0] & 0x01))
        {
            ucMode_Times    = 0;
        }
        else
        {
            // When we cannot lock color, we set color standard to PAL-BDGHI if field rate is 50Hz, 
            // and to NTSC-M if it is 60Hz.
            // If we find color is locked, we should update ucAV_Mode to indicate we now get color.
            if (VIDEO_SEARCH_TIMES < ++ucMode_Times)    ucAV_Mode = ucAV_Mode & 0x0f;
        }
    }

    // Check field rate
    if (Data[0] & 0x40)
    {
        ucMode_Curr = MODE_NOSIGNAL;
    }
    else
    {
        if (ucAV_Mode & 0x02)       // 50Hz
        {   
            if (0x00 != (Data[0] & 0x20))   ucMode_Curr = MODE_NOSIGNAL;
        } 
        else                        // 60Hz
        {
            if (0x00 == (Data[0] & 0x20))   ucMode_Curr = MODE_NOSIGNAL;
        }
    }
   
    // Check result
    if (MODE_NOSIGNAL == ucMode_Curr)
        Reset_Mode();
    else
        bStable = 1;    // Set bStable to 1 when signal timing is stable.
#endif
}


void Calculate_IVS2DVS_Delay(unsigned char integer, unsigned char fraction, unsigned int DVStart)
{
       if ((usIPV_ACT_STA + integer) < (DVStart >> 6))
        {
            // You should never get into this code ....
            usIPV_ACT_STA   = ( DVStart >> 6) - integer;

            RTDSetByte(IPV_ACT_STA_0A, (unsigned char)usIPV_ACT_STA);
            RTDSetByte(IPV_ACT_STA_0A + 1, (unsigned char)(usIPV_ACT_STA >> 8));
        }

        ((unsigned int*)Data)[0] = ((usIPV_ACT_STA + integer) << 6) + ((unsigned int)fraction << 6)/10 - DVStart;

        
		ucDV_Delay = (unsigned char)(((unsigned int*)Data)[0] >> 6);

		Data[6] = ((unsigned int*)Data)[0] - (ucDV_Delay << 6);

		Data[6] = (unsigned long)usADC_Clock * Data[6] / 1024;//512;

		RTDSetByte(FS_FT_DELAY_1E, Data[6]);

       
}

void Set_Dclk(unsigned int DispLen)
{
    if (Mode_Preset[ucMode_Curr][3])
    {
        // Use preset DCLK M/N code
        Data[0] = 6;
        Data[1] = Y_INC;
        Data[2] = DPLL_CTRL_D0;
        Data[3] = 0x11;
        Data[4] = (unsigned char)(Mode_Preset[ucMode_Curr][3] >> 8);
        Data[5] = (unsigned char)Mode_Preset[ucMode_Curr][3];
        Data[6] = 0;
        RTDWrite(Data);
    }
    else
    {
     
//        if (VGA_Mode[ucMode_Curr][4])
//        {
//            ((unsigned int *)Data)[0]   = (unsigned long)8 * usDH_Total * USER_MODE_NCODE * usDispLen 
//                                        / ((unsigned long)usIPV_ACT_LEN * VGA_Mode[ucMode_Curr][4]);
//        }
//        else
//        {

            ((unsigned int *)Data)[0]   = (unsigned long)8 * usDH_Total * USER_MODE_NCODE * DispLen 
                                        / ((unsigned long)usIPV_ACT_LEN * usHsync);
//        }


        //Original Formula : DPM/Ich = 17.6 must be constant
		//Ich = DPM * 10 / 176
		//2*Ich = DPM * 20 / 176 , set D0[0] to 0, then I = 2 * Ich
		//I  = 2 * Ich = 2.5u + D0[3]*2.5u + D0[4]*5u + D0[5]*10u + D0[6]*20u + D0[7]*30u(A)
		//2I = 4 * Ich = 5u + D0[3]*5u + D0[4]*10u + D0[5]*20u + D0[6]*40u + D0[7]*60u(A)
        Data[15] = ((unsigned int *)Data)[0] >> 2;
		Data[5] = (unsigned int)Data[15] * 40 / 176 - 5; //Calculate the 4*Ich,
		Data[6] = 0x00;
		if(Data[5] > 60)
		{
		    Data[5] -= 60;
			Data[6] |= 0x80; 
		}

		if(Data[5] > 40)
		{
		    Data[5] -= 40;
			Data[6] |= 0x40;
		}
		 
   	    if(Data[5] > 20)
		{
		    Data[5] -= 20;
			Data[6] |= 0x20;
		}

		if(Data[5] > 10)
		{
		    Data[5] -= 10;
			Data[6] |= 0x10;
		}

		if(Data[5] > 5)
		{
		    Data[5] -= 5;
			Data[6] |= 0x08;
		}
		

		Data[0] = 7;
		Data[1] = Y_INC;
		Data[2] = DPLL_CTRL_D0;
		Data[3] = Data[6];
		Data[4] = Data[15] - 2;
		Data[5] = 0x10 | (USER_MODE_NCODE - 2);//Offset Frequency Direction set to Downward
		//Data[5] = (USER_MODE_NCODE - 2);//Offset Frequency Direction set to Downward
		Data[6] = 0x04;
		Data[7] = 0;
		RTDWrite(Data);

 
//        ucDebug_Value0 = Data[4];
   //     ucDebug_Value1 = Data[5];
       
        //More precise Dclk in KHz
		((unsigned long*)Data)[0] = (unsigned long)24576000 / usIPV_ACT_LEN * DispLen / usHsync * usDH_Total ;
        //((unsigned long*)Data)[0] = (unsigned long)49152000 / usIPV_ACT_LEN * usDispLen / usHsync * usDH_Total ;
		//set M/N code Dclk
		((unsigned long*)Data)[1] = (unsigned long)12288000 * (Data[15] + 1) / USER_MODE_NCODE;
        //((unsigned long*)Data)[1] = (unsigned long)24576000 * (Data[15] + 1) / USER_MODE_NCODE;
		((unsigned long*)Data)[2] = ((unsigned long*)Data)[1] - ((unsigned long*)Data)[0]; //Dclk offset
		((unsigned long*)Data)[3] = ((unsigned long*)Data)[1] >> 15; //Offset resolution equal to (Dclk / 2^15)
        
		((unsigned long*)Data)[3] = ((((unsigned long*)Data)[2] << 1)/ ((unsigned long*)Data)[3]) & 0x00000fff; //Calculate the Dclk offset
        //((unsigned long*)Data)[3] = (((unsigned long*)Data)[2] / ((unsigned long*)Data)[3]) & 0x00000fff; //Calculate the Dclk offset

		RTDSetByte(DCLK_OFFSET_LSB_9A,(unsigned char)((unsigned long*)Data)[3]);  //Set the Dclk offset
//        ucDebug_Value0 = (unsigned char)(((unsigned long*)Data)[3]);
		//RTDSetBit(DCLK_OFFSET_MSB_9B,0xf0,(unsigned char)(((unsigned long*)Data)[3] >> 8) | 0x20);
		RTDSetBit(DCLK_OFFSET_MSB_9B,0xf0,(unsigned char)(((unsigned long*)Data)[3] >> 8) | 0x20);
//        ucDebug_Value1 = (unsigned char)((((unsigned long*)Data)[3] >> 8) | 0x20);
        RTDSetBit(FX_LST_LEN_H_5A,0xff,0x08); //Enable DDS Spread Spectrum Output Function
		RTDSetBit(DPLL_N_D2,0xff,0x20); //DPLL Spread Spectrum Enable
		RTDSetBit(DPLL_FILTER_D3,0x7f,0x00); //Enable DPll output
	}
}

void Initial_Mode(void)
{
    unsigned char   ucOption;
    unsigned int    usDispLen;

    // bit 7 of ucMode_Curr : partial-V display.
    // bit 6 of ucMode_Curr : select 720x350 or 720x400 for VGA-50Hz and VGA-60Hz
    ucOption    = ucMode_Curr & 0xc0;
    ucMode_Curr = ucMode_Curr & 0x3f;

    
	RTDSetBit(SD_CTRL_70, 0xf9, VGA_ICLK_DELAY);
    if (SOURCE_DVI == (stGUD1.INPUT_SOURCE & 0x07))
    {
        RTDSetBit(SD_CTRL_70, 0xf9, TMDS_ICLK_DELAY);

        usIPH_ACT_STA   = CAP_WIN[ucMode_Curr][1];
    }
    else
    {

	if (ucOption & 0x40)
	{
		// Only VGA-50Hz and VGA-60Hz mode will set bit 6 of ucMode_Curr to indicate 720-pixel capture width
		// In these case, we should use 720 horizontal settings instead of 640 horizontal settings in table.
		usADC_Clock     = CAP_WIN[MODE_0720x0400x70HZ][0];
		usIPH_ACT_STA   = CAP_WIN[MODE_0720x0400x70HZ][1];
		usIPH_ACT_WID   = CAP_WIN[MODE_0720x0400x70HZ][2];
	}
	else
	{
		usADC_Clock     = CAP_WIN[ucMode_Curr][0];
		usIPH_ACT_STA   = CAP_WIN[ucMode_Curr][1];
		usIPH_ACT_WID   = CAP_WIN[ucMode_Curr][2];

		// Calculate pixel clock rate (round to MHz)
		usDispLen   = (unsigned long)24576 * usADC_Clock / ((unsigned long)usHsync * 500);
		usDispLen   = (usDispLen >> 1) + (usDispLen & 0x01);

		// Use ADC to do H scale-down if pixel clock rate is over spec.
		if (MAX_ADC_FREQ < usDispLen && MODE_USER1152x864 <= ucMode_Curr && MODE_USER1600x1200 >= ucMode_Curr)
		{
			usADC_Clock     = ADC_SD_SET[ucMode_Curr - MODE_USER1152x864][0];
			usIPH_ACT_STA   = ADC_SD_SET[ucMode_Curr - MODE_USER1152x864][1];
			usIPH_ACT_WID   = ADC_SD_SET[ucMode_Curr - MODE_USER1152x864][2];
		}

	} //if (ucOption & 0x40)

	// Calculate pixel clock rate (round to MHz)
	usDispLen   = (unsigned long)24576 * usADC_Clock / ((unsigned long)usHsync * 500);
	usDispLen   = (usDispLen >> 1) + (usDispLen & 0x01);


	// To improve ADC performance ,when the data rate is slow, use single channel,otherwise, use dual channel
	RTDSetBit(ADC_REG_CLK_EA,0xe0,(45 > usDispLen) ? 0x10 | (ADC_RED_PHASE_FT & 0x0c) |( ADC_BLUE_PHASE_FT & 0x03): 
	                                                 0x00 | (ADC_RED_PHASE_FT & 0x0c) |( ADC_BLUE_PHASE_FT & 0x03)); 


	// To imporve the FIFO efficiency only when input data rate is slow, and display data rate is high.
//	RTDSetBit(VGIP_CTRL_04, 0xe3, (40 > usDispLen) ? 0x14 : 0x00);
    RTDSetBit(VGIP_CTRL_04, 0xf3, (60 > usDispLen) ? 0x08 : 0x00);

	RTDSetByte(PE_CONTROL_3C, 0x00);    // HSYNC positive/negtive tracking
	
    RTDSetByte(ADC_FRAME_MODULE_EB,0x06);
//  RTDSetByte(ADC_FRAME_MODULE_EB,(usIPH_ACT_WID == 1280) ? 0x04 : 0x00);


  // Set ADC bandwidth to reduce high frequency noise
//  RTDSetByte(ADC_REG_TEST_E9, (35 > usDispLen) ? 0x08 : (150 > usDispLen) ? 0x10 : 0x18);
	


#if(ADC_DEFFERENTIAL)
    RTDSetBit(ADC_DIFF_MODE_EC,0xff,0x40); //Differential mode
#else
    RTDSetBit(ADC_DIFF_MODE_EC,0xbf,0x00); //Single endded mode
#endif




	RTDSetByte(ADC_REG_CUR_H_E8, 0x0d | (ADC_GREEN_PHASE_FT & 0x30));



    RTDSetBit(ADC_FRAME_MODULE_EB,0xc7, ((ADC_RED_PHASE_FT & 0x10) << 1) | ((ADC_GREEN_PHASE_FT & 0x40) << 2) 
	                                   |((ADC_BLUE_PHASE_FT & 0x04) << 1));



    RTDSetBit(TMDS_CORRECTION_FF,0xff,0x04); //Enable the ADC digital filter


    if(ucMode_Curr < MODE_1024x0768x70HZ)
    	RTDSetByte(ADC_REG_TEST_E9, 0x08);
    else 
        RTDSetByte(ADC_REG_TEST_E9, 0x10);


	// Get usIPV_ACT_LEN
	if (MODE_UNDEFINED0 > ucMode_Curr)
	{
		// We've already decided usIPV_ACT_LEN in Detect_VGA_Mode() for undefined SU/SD mode.
		// Only defined modes need to decide usIPV_ACT_LEN here.
		usIPV_ACT_LEN   = CAP_WIN[ucMode_Curr][4];
	}
    
    } //if (SOURCE_DVI == (stGUD1.INPUT_SOURCE & 0x07))

    // Get standard usIPV_ACT_STA 

    RTDSetByte(IVS_DELAY_8C, PROGRAM_VDELAY);

    usIPV_ACT_STA   = CAP_WIN[ucMode_Curr][3] - PROGRAM_VDELAY - 1;


    RTDSetByte(IHS_DELAY_8D, PROGRAM_HDELAY);

//    usIPH_ACT_STA   = usIPH_ACT_STA + CAPTURE_HDELAY - PROGRAM_HDELAY;
    if(ucMode_Curr < MODE_0800x0600x75HZ)
		Data[0] = 2;
    else if(ucMode_Curr < MODE_1280x1024x75HZ)
		Data[0] = 5;
    else
		Data[0] = 3;

//    Data[0] = 5;
    usIPH_ACT_STA   = usIPH_ACT_STA + Data[0] - PROGRAM_HDELAY;

    // Decide display length (height) and store to usDispLen

    usDispLen   = Mode_Preset[ucMode_Curr][2];

    if (MODE_UNDEFINED0 == ucMode_Curr)         // partical-screen scale-up mode
    {
        if (ucOption & 0x80)    // partial-V
        {           
			if (MIN_DV_TOTAL > (usVsync - 1))
                usDispLen   = (unsigned long)usIPV_ACT_LEN * MIN_DV_TOTAL / (usVsync - 1);
            else
                usDispLen   = usIPV_ACT_LEN;    // No V scale-up
        }
    }
    else if (MODE_UNDEFINED1 == ucMode_Curr)    // partial-screen scale-down mode
    {
        if (ucOption & 0x80)    // partial-V
        {
            usDispLen   = (unsigned long)usIPV_ACT_LEN * MIN_DV_TOTAL / (usVsync - 1);
        }
    } //if (MODE_UNDEFINED0 == ucMode_Curr)         // partical-screen scale-up mode

    if (Mode_Preset[ucMode_Curr][2] < usDispLen)    usDispLen   = Mode_Preset[ucMode_Curr][2];

    // This F/W do not support V scale-up(or bypass) and H scale-down simultaneously
    if (usDispLen >= usIPV_ACT_LEN && Mode_Preset[ucMode_Curr][1] < usIPH_ACT_WID)
    {
        usIPH_ACT_WID   = Mode_Preset[ucMode_Curr][1];
    }

    if (usDispLen > usIPV_ACT_LEN)                      ucOption    |= 0x01;    // bit 0 : V scale-up
    if (usDispLen < usIPV_ACT_LEN)                      ucOption    |= 0x02;    // bit 1 : V scale-down
    if (Mode_Preset[ucMode_Curr][1] > usIPH_ACT_WID)    ucOption    |= 0x04;    // bit 2 : H scale-up
    if (Mode_Preset[ucMode_Curr][1] < usIPH_ACT_WID)    ucOption    |= 0x08;    // bit 3 : H scale-down

    // Set capture window
    Data[0]     = 11;
    Data[1]     = Y_INC;
    Data[2]     = IPH_ACT_STA_06;
    Data[3]     = (unsigned char)usIPH_ACT_STA;
    Data[4]     = (unsigned char)(usIPH_ACT_STA >> 8);
    Data[5]     = (unsigned char)usIPH_ACT_WID;
    Data[6]     = (unsigned char)(usIPH_ACT_WID >> 8);
    Data[7]     = (unsigned char)usIPV_ACT_STA;
    Data[8]     = (unsigned char)(usIPV_ACT_STA >> 8);
    Data[9]     = (unsigned char)usIPV_ACT_LEN;
    Data[10]    = (unsigned char)(usIPV_ACT_LEN >> 8);
    Data[11]    = 0;
    RTDWrite(Data);

    // Set window size before scale-up
    Data[0] = 7;
    Data[1] = Y_INC;
    Data[2] = DRW_BSU_40;

    if (ucOption & 0x08)
    {
        // H scale-down
        Data[3] = (unsigned char)Mode_Preset[ucMode_Curr][1];
        Data[4] = (unsigned char)(Mode_Preset[ucMode_Curr][1] >> 8);
    }
    else
    {
        // No H scale-down
        Data[3] = Data[5];  // (unsigned char)usIPH_ACT_WID;
        Data[4] = Data[6];  // (unsigned char)(usIPH_ACT_WID >> 8);
    }

    if (ucOption & 0x02)
    {
        // V scale-down
        Data[5] = (unsigned char)usDispLen;
        Data[6] = (unsigned char)(usDispLen >> 8);
    }
    else
    {
        // No V scale-down
        Data[5] = Data[9];  // (unsigned char)usIPV_ACT_LEN;
        Data[6] = Data[10]; // (unsigned char)(usIPV_ACT_LEN >> 8);
    }
    Data[7] = 0;
    RTDWrite(Data);

    // Config scaling
    if (ucOption & 0x0a)
        RTDSetBit(SD_CTRL_70, 0xff, 0x01);      // Turn on scale-down
    else
        RTDSetBit(SD_CTRL_70, 0xfe, 0x00);      // Turn off scale-down

    if (ucOption & 0x01)
        RTDSetBit(SCALE_CTRL_15, 0xff, 0x02);   // Turn on V scale-up
    else
        RTDSetBit(SCALE_CTRL_15, 0xfd, 0x00);   // Turn off V scale-up

    if (ucOption & 0x04)
        RTDSetBit(SCALE_CTRL_15, 0xff, 0x01);   // Turn on H scale-up
    else
        RTDSetBit(SCALE_CTRL_15, 0xfe, 0x00);   // Turn off H scale-up

    // Set scale-down coefficient
    Data[0] = 7;
    Data[1] = Y_INC;
    Data[2] = H_SCALE_DL_71;

    if (ucOption & 0x08)    // H scale-down
    {
        // Data[12~15]
        ((unsigned long *)Data)[3]  = (unsigned long)256 * 4096 * usIPH_ACT_WID / Mode_Preset[ucMode_Curr][1];

        // Data[4~5]
        ((unsigned int *)Data)[2]   = (((unsigned long *)Data)[3] >> 8) + 2;

        // H scale-down factor is stored in Data[4] (high-byte) and Data[5] (low-byte)
        Data[3] = Data[5];

        RTDSetBit(VGIP_CTRL_04, 0xff, 0x40);    // Enable H scale-down compensation
    }
    else
    {
        Data[3] = 0x00;
        Data[4] = 0x10;

        RTDSetBit(VGIP_CTRL_04, 0xbf, 0x00);    // Diable H scale-down compensation
    }

    if (ucOption & 0x02)    // V scale-down
    {
        // Data[12~15]
        ((unsigned long *)Data)[3]  = (unsigned long)256 * 4096 * usIPV_ACT_LEN / usDispLen;

        // Data[6~7]
        ((unsigned int *)Data)[3]   = (((unsigned long *)Data)[3] >> 8);

        if (0 == Data[15])      ((unsigned int *)Data)[3]   = ((unsigned int *)Data)[3] - 1;

        // V scale-down factor is stored in Data[6] (high-byte) and Data[7] (low-byte)
        Data[5] = Data[7];

        RTDSetBit(VGIP_CTRL_04, 0xff, 0x80);    // Enable V scale-down compensation
    }
    else
    {
        Data[5] = 0x00;
        Data[6] = 0x10;

        RTDSetBit(VGIP_CTRL_04, 0x7f, 0x00);    // Diable V scale-down compensation
    }
    Data[7] = 0;
    RTDWrite(Data);

    // Set scale-up coefficient
    Data[0] = 8;
    Data[1] = Y_INC;
    Data[2] = HOR_SCA_16;

    if (ucOption & 0x04)    // H scale-up
    {
        // Data[12~15]
        ((unsigned long *)Data)[3]  = (unsigned long)2 * 262144 * usIPH_ACT_WID / Mode_Preset[ucMode_Curr][1];
        ((unsigned long *)Data)[3]  = ((((unsigned long *)Data)[3] >> 1) + (((unsigned long *)Data)[3] & 0x01)) << 6;

        Data[3] = Data[14];
        Data[4] = Data[13];
        Data[7] = Data[15];
    }
    else
    {
        Data[3] = 0xff;
        Data[4] = 0xff;
        Data[7] = 0;
    }

    if (ucOption & 0x01)    // V scale-up
    {
        // Data[12~15]
        ((unsigned long *)Data)[3]  = (unsigned long)2 * 262144 * usIPV_ACT_LEN / usDispLen;
        ((unsigned long *)Data)[3]  = ((((unsigned long *)Data)[3] >> 1) + (((unsigned long *)Data)[3] & 0x01)) << 6;

        Data[5] = Data[14];			//anson 05_0315
//        Data[5] = 0x90;
        Data[6] = Data[13];
//        Data[6] = 0xc0;
        Data[7] = Data[7] | (Data[15] >> 4);
    }
    else
    {
        Data[5] = 0xff;
        Data[6] = 0xff;
    }
    Data[8] = 0;
    RTDWrite(Data);

    // Set RTD display

    // Switch to FrameSync 1 mode and diable display
    RTDSetByte(VDIS_CTRL_20, 0x28 | DISP_BIT | DISPLAY_PORT);

    Data[0]     = 5;
    Data[1]     = Y_INC;

#if (DISP_ALIGN)

    Data[2]     = DH_ACT_STA_27;

    // DH_ACT_STA store in Data[4~5] (H~L)
    ((unsigned int *)Data)[2]   = (unsigned int)DH_ACT_END_POS - Mode_Preset[ucMode_Curr][1];

    Data[3]     = Data[5];

#else

    Data[2]     = DH_ACT_END_29;

    // DH_ACT_STA store in Data[4~5] (H~L)
    ((unsigned int *)Data)[2]   = (unsigned int)DH_ACT_STA_POS + Mode_Preset[ucMode_Curr][1];

    Data[3]     = Data[5];

#endif

    Data[5]     = 5;
    Data[6]     = Y_INC;
    Data[7]     = DV_ACT_END_34;

    // DV_ACT_END store in Data[10~11] (H~L)
    ((unsigned int *)Data)[5]   = (unsigned int)DV_ACT_STA_POS + usDispLen;

    Data[8]     = Data[11];
    Data[9]     = Data[10];
    Data[10]    = 0;
    RTDWrite(Data);

    // Get standard DH_TOTAL
    usDH_Total  = Mode_Preset[ucMode_Curr][0];

    // Switch to FrameSync 1 mode and enable display
//    if (PANEL_OFF == bPANEL_PWR)
    if (_OFF == bPanel_Status)
        RTDSetByte(VDIS_CTRL_20, 0x29 | DISP_BIT | DISPLAY_PORT);
    else
        RTDSetByte(VDIS_CTRL_20, 0x2b | DISP_BIT | DISPLAY_PORT);

	Set_Dclk(usDispLen);
   
    //usDH_Total  = usDH_Total - 2;

    // Set DH_TOTAL
    Data[0] = 5;
    Data[1] = Y_INC;
    Data[2] = DH_TOTAL_22;
    Data[3] = (unsigned char)(usDH_Total - 2);
    Data[4] = (unsigned char)((usDH_Total - 2) >> 8);
    Data[5] = 0;
    RTDWrite(Data);



    //Calculate DV_TOTAL
	if((ucOption & 0x01) || (ucOption & 0x02))    // V scale up or scale down
	{

#if(DISP_SIZE == DISP_800x600)		
			usDV_Total = (unsigned long)usVsync * 600 / (unsigned long)usIPV_ACT_LEN + 64;
#endif

#if(DISP_SIZE == DISP_1024x768)		
			usDV_Total = (unsigned long)usVsync * 768 / (unsigned long)usIPV_ACT_LEN + 64;
#endif

#if(DISP_SIZE == DISP_1280x1024)		

			usDV_Total = (unsigned long)usVsync * 1024 / (unsigned long)usIPV_ACT_LEN + 64;
#endif
		
		
	}
	else
		usDV_Total = usVsync + 64;

    //Set DV_TOTAL
	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = DV_TOTAL_2D;
	Data[3] = (unsigned char)usDV_Total;
	Data[4] = (unsigned char)((usDV_Total >> 8) & 0x07);
	Data[5] = 0;
	RTDWrite(Data);




    // Calculate suitable IVS to DVS delay
    // CR[38] : IVS to DVS delay in IHS lines
    // CR[1E] : IVS to DVS delay in ICLK * 16
    //((unsigned int *)Data)[0]   = (unsigned long)64 * DV_ACT_STA_POS * usIPV_ACT_LEN / usDispLen;
	((unsigned int *)Data)[0]   = (unsigned long)64 * DV_ACT_STA_POS * usIPV_ACT_LEN / usDispLen;

    if (ucOption & 0x01)
    {
	    Calculate_IVS2DVS_Delay(2,5,((unsigned int*)Data)[0]);  // V scale-up. Target 2.5~2.6 IHS delay

    }
    else
    {
#if (FULL_LINE_BUFFER)
        Calculate_IVS2DVS_Delay(3,8,((unsigned int*)Data)[0]);  // V no scale-up. Target 3.8~4.0 IHS delay
#else
        if (ucOption & 0x02)
        {
		    // V scale-down            
		    Calculate_IVS2DVS_Delay(2,6,((unsigned int*)Data)[0]);   // V scale-down. Target 2.5~2.6 IHS delay
		}
        else
        {

            Calculate_IVS2DVS_Delay(1,9,((unsigned int*)Data)[0]);                  // V no scale-up. Target 1.9 IHS delay
        }

#endif
    }

#if (FULL_LINE_BUFFER)
    // Turn on full-line buffer when no V scale-up
    RTDSetBit(OP_CRC_CTRL_68, 0xfc, (ucOption & 0x01) ? 0x00 : 0x02);
#else
    RTDSetBit(OP_CRC_CTRL_68, 0xfc, 0x00);
#endif

    // Set ucDV_Delay
    RTDSetByte(IV_DV_LINES_38, ucDV_Delay);

	RTDSetByte(STATUS0_01, 0x00);  // Clear status
    RTDSetByte(STATUS1_1F, 0x00);  // Clear status

    // Switch to FrameSync 1 mode and enable display
//    if (PANEL_OFF == bPANEL_PWR)
//        RTDSetByte(VDIS_CTRL_20, 0x29 | DISP_BIT | DISPLAY_PORT);
//    else
//        RTDSetByte(VDIS_CTRL_20, 0x2b | DISP_BIT | DISPLAY_PORT);

    // Input Run Enable
    RTDSetBit(VGIP_CTRL_04, 0xff, 0x01);

}

void Display_VGA_Set(void)
{
    unsigned char   Wait_Time_Cnt;
//	unsigned char   ucI_Corr0,ucI_Corr1;


    Initial_Mode();
	Sharpness();

    if((usIPH_ACT_WID == 1280) && (DISP_SIZE == DISP_1280x1024) && (stGUD1.FILTER == 0x02))
         RTDSetBit(SCALE_CTRL_15, 0xff, 0x01);   // Turn on H scale-up
    

    PowerDown_ADC();
    //Device_Power(ADC_POWER,OFF);

    // Set user's ADC gain and offset settings
    SetADC_GainOffset();

    Set_Gamma();
    Set_Dithering();
    Set_Bright_Contrast();
//    Sharpness();

    Load_MUD(ucMode_Curr);      // Read mode default settings from 24C04

    // For jitter adjust
    ucPE_Level      = 0;
//    ucPE_Count      = 0;

    // Check Clock
    if (28 > stMUD.CLOCK || 228 < stMUD.CLOCK)      stMUD.CLOCK = 128;

    
    // Update Clock Twice
    Set_Clock();
// Calculate the P correction and I correction according to the CE value
    Delay_Xms(6);
	
    if(ucCE_Value ==  0)
    {
       RTDRead(I_CODE_MB_CA,1,N_INC);
	   RTDSetByte(I_CODE_MB_CA, 0x0d);
	   Delay_Xms(4);
	   RTDRead(PLL_CALIBRATION_CE,1,N_INC);
	   ucP_Corr = (unsigned char)((unsigned int)(Data[0] * 200) >> (29 - P_Code));
	   ucCE_Value = Data[0];  //CE value  

	}

	if(ucI_Code == 0)
	   Adjust_I_Code();
    
	
    Set_Clock();


    // Check Phase
//    stMUD.PHASE &= 0x7c;    // Phase 0~31

    // Update Phase
//    Set_Phase(stMUD.PHASE);

    ucH_Max_Margin  = 128 + 50;
    ucH_Min_Margin  = 128 - 50;
	
	//Read the usIPH_ACT_STA offset
    I2CRead(ADDR_EROM1,(ucMode_Curr - 1),0x01);
	if(Data[0] > 228)
	   Data[0] = 0;

    usIPH_ACT_STA   = (Data[0] & 0x80) ? usIPH_ACT_STA - 50 - (Data[0] - 0x80) : usIPH_ACT_STA + Data[0] - 50;
        
    Data[0] = 5;
    Data[1] = Y_INC;
    Data[2] = IPH_ACT_STA_06;
    Data[3] = (unsigned char)usIPH_ACT_STA;
    Data[4] = (unsigned char)(usIPH_ACT_STA >> 8);
    Data[5] = 0;    
    RTDWrite(Data);

    // Check H-Position
    if (ucH_Max_Margin < stMUD.H_POSITION)
        stMUD.H_POSITION    = ucH_Max_Margin;
    else if (ucH_Min_Margin > stMUD.H_POSITION)
        stMUD.H_POSITION    = ucH_Min_Margin;

    // Update H-Position
    Set_H_Position();

       // Check Phase
    stMUD.PHASE &= 0x7c;    // Phase 0~31

    // Update Phase
    Set_Phase(stMUD.PHASE);

    // Start auto-tracking function once
    RTDSetByte(AUTO_ADJ_CTRL_7F, 0x01);
    Delay_Xms(40);

    // Force to stop auto-tracking function
    RTDSetByte(AUTO_ADJ_CTRL_7F, 0x00);
    Delay_Xms(40);

    // Measure actual number of scan line in each frame
    Data[0]     = 14;
    Data[1]     = Y_INC;
    Data[2]     = H_BND_STA_L_75;
    Data[3]     = 0x00;
    Data[4]     = 0xff;
    Data[5]     = 0x07;
    Data[6]     = 0x00;
    Data[7]     = 0x00;
    Data[8]     = 0x00;
    Data[9]     = 0x00;
    Data[10]    = 0x00;
    Data[11]    = 0x00;
    Data[12]    = 0x00;
    Data[13]    = 0x01;
    Data[14]    = 0;
    RTDWrite(Data);

    Wait_Time_Cnt  = 60;    // Tracking timeout 60ms        
    do
    {   
        Delay_Xms(1);
        RTDRead(AUTO_ADJ_CTRL_7F, 0x01, N_INC);
    }
    while ((Data[0] & 0x01) && (--Wait_Time_Cnt));

    RTDSetByte(AUTO_ADJ_CTRL_7F, 0x00);
    
    if (Wait_Time_Cnt)
    {
        RTDRead(VER_START_80, 0x04, Y_INC);
        Data[0] = Data[3] & 0x0f;
        Data[1] = Data[2];

        usVer_End   = (usVsync < ((unsigned int *)Data)[0]) ? ((unsigned int *)Data)[0] : usVsync;
    }
    else
    {
        usVer_End   = usVsync;
    }

    // Update to reasonable usIPV_ACT_STA for user mode
    if (MODE_USER720x400 <= ucMode_Curr)
    {
        ((unsigned int *)Data)[0]   = usVer_End - VGA_Mode[ucMode_Curr][2];

        if (254 < ((unsigned int *)Data)[0] + ucDV_Delay)   ((unsigned int *)Data)[0]   = 254 - ucDV_Delay;

        usIPV_ACT_STA   += ((unsigned int *)Data)[0];
        ucDV_Delay      += ((unsigned int *)Data)[0];
    }

    // Set the ucV_Min_Margin/ucV_Max_Margin
    ucV_Min_Margin  = (128 < usIPV_ACT_STA) ? 0 : 128 - usIPV_ACT_STA + 1;

    if ((128 - 50) > ucV_Min_Margin)    ucV_Min_Margin  = 128 - 50;

    ((unsigned int *)Data)[0]   = (usVer_End + 128 - 2) - (usIPV_ACT_STA + usIPV_ACT_LEN);

    ucV_Max_Margin  = (((unsigned int *)Data)[0] > 0x00ff) ? 0xff : ((unsigned int *)Data)[0];

    // Check ucV_Min_Margin/ucV_Max_Margin :
    // ucDV_Delay can only range from 0 to 254
    // Original Formula :
    // 128 - ucV_Min_Margin >= ucDV_Delay
    // ucV_Max_Margin - 128 >= 254 - ucDV_Delay

    if ((unsigned int)128 > ((unsigned int)ucV_Min_Margin + ucDV_Delay))    ucV_Min_Margin  = 128 - ucDV_Delay;
    if ((unsigned int)382 < ((unsigned int)ucV_Max_Margin + ucDV_Delay))    ucV_Max_Margin  = 382 - ucDV_Delay;

    if ((128 + 50) < ucV_Max_Margin)    ucV_Max_Margin  = 128 + 50;

    // Check V-Position
    if (ucV_Min_Margin > stMUD.V_POSITION)
        stMUD.V_POSITION    = ucV_Min_Margin;
    else if ((unsigned int)256 - ucV_Min_Margin < stMUD.V_POSITION)
        stMUD.V_POSITION    = (unsigned int)256 - ucV_Min_Margin;

    // Update V-Position
    Set_V_Position();

    // Re-calculate actual refresh rate
    ((unsigned long *)Data)[0]  = (unsigned long)usHsync * usVer_End;
    ucRefresh   = (unsigned long)49152000 / ((unsigned long *)Data)[0];
    ucRefresh   = (ucRefresh & 0x01) ? ((ucRefresh + 1) >> 1) : (ucRefresh >> 1);
    
	if(ucRefresh > V_OVERSPEC_FREQ)
	    bOverSpec = _TRUE;

	if((unsigned int)24576/usHsync > H_OVERSPEC_FREQ)
	    bOverSpec = _TRUE;

    Data[0] = Frame_Sync();

    if (1 == Data[0])
    {
       Delay_Xms(10);
       Data[0] = Frame_Sync();     // Fail. Try again	   	  
    }

    bFrameSync      = Data[0] ? 0 : 1;              // 0 : fail, 1 : pass
    ucSyncErrorCnt  = 0;

    RTDSetBit(OVL_CTRL_6D,0x3f,0x00);
    RTDSetByte(BGCOLOR_CONTROL_6C,0x00);
	RTDSetBit(OVL_CTRL_6D,0x3f,0x40);
    RTDSetByte(BGCOLOR_CONTROL_6C,0x00);
	RTDSetBit(OVL_CTRL_6D,0x3f,0x80);
    RTDSetByte(BGCOLOR_CONTROL_6C,0x00);

//    RTDSetBit(VDIS_CTRL_20, 0x5f, DHS_MASK);        // Normal display
      RTDSetBit(VDIS_CTRL_20, 0x7f, 0x20 | DHS_MASK);        // Normal display

#if(AS_PLL_NONLOCK)
   if(bFrameSync)
        RTDSetBit(ODD_CTRL_8E,0xdf,0x20);
#endif

    //anson 05_0314
    ucfrist = (ucMode_Curr - 1 ) / 8 ;
    I2CRead(ADDR_EROM1, ucfrist , 1);
    ucfrist = ucMode_Curr - (ucfrist*8) ;
    ucfrist  = Data[0] >> (ucfrist-1) ;
    ucfrist  = ucfrist & 0x01;
    stGUD1.OSD_INPUT = stGUD1.OSD_INPUT | 0x20; //First Time Into This Mode


}

void Display_DVI_Set(void)
{
#if(TMDS_ENABLE)
    unsigned char   Wait_Time_Cnt;

    Initial_Mode();

    // Set the ucV_Min_Margin/ucV_Max_Margin
    ucV_Min_Margin  = (128 < usIPV_ACT_STA) ? 0 : 128 - usIPV_ACT_STA + 1;

    // Use Data[8],Data[9] as a temporary 16-bit variable.
    ((unsigned int *)Data)[4]   = (usVsync + 128 - 2) - (usIPV_ACT_STA + usIPV_ACT_LEN);

    ucV_Max_Margin  = (0x00ff <  ((unsigned int *)Data)[4]) ? 0xff :  ((unsigned int *)Data)[4];

    // Check ucV_Min_Margin/ucV_Max_Margin :
    // ucDV_Delay can only range from 0 to 254
    // Original Formula :
    // 128 - ucV_Min_Margin <= ucDV_Delay
    // ucV_Max_Margin - 128 <= 254 - ucDV_Delay

    if ((unsigned int)128 > ((unsigned int)ucV_Min_Margin + ucDV_Delay))    ucV_Min_Margin  = 128 - ucDV_Delay;
    if ((unsigned int)382 < ((unsigned int)ucV_Max_Margin + ucDV_Delay))    ucV_Max_Margin  = 382 - ucDV_Delay;

    // Read mode default settings from 24C04
    Load_MUD(ucMode_Curr);

    Set_Gamma();
    Set_Dithering();
    Set_Bright_Contrast();
    Sharpness();

    // Issac :
    // RTD controller can support both digital mode and analog mode to capture input image data.
    // In digital mode, input image data is captured according to input data enable (IDEN) signal;
    // In analog mode, input image data is captured according to capture window settings;
    // Although can support both of them, I always use analog mode to capture input image in this F/W.
    // Because RTD controller can measure the position and size of IDEN signal, we can just set our
    // capture window to be the same size and position as IDEN.

    Data[0]     = 14;
    Data[1]     = Y_INC;
    Data[2]     = H_BND_STA_L_75;
    Data[3]     = 0x02;
    Data[4]     = usADC_Clock - 2;
    Data[5]     = (usADC_Clock - 2) >> 8;
    Data[6]     = 0x02;
    Data[7]     = usVsync - 2;
    Data[8]     = (usVsync - 2) >> 8;
    Data[9]     = 0;
    Data[10]    = 0;
    Data[11]    = 0;
    Data[12]    = 0;
    Data[13]    = 0x81;     // Measure IDEN position
    Data[14]    = 0;


    RTDWrite(Data);

    Wait_Time_Cnt  = 60;    // Tracking timeout 60ms        
    do
    {   
        Delay_Xms(1);
        RTDRead(AUTO_ADJ_CTRL_7F, 0x01, N_INC);
    }
    while ((Data[0] & 0x01) && (--Wait_Time_Cnt));
    
    if (0 == Wait_Time_Cnt)
    {
        RTDSetByte(AUTO_ADJ_CTRL_7F, 0x00);
        Reset_Mode();
    }
    else
    {
        // Read IDEN position information
        RTDRead(VER_START_80, 0x08, Y_INC);
        
        // IDEN horizontal Start
        usIPH_ACT_STA   = (unsigned int)Data[4] + ((unsigned int)Data[5] << 8) - 2;

        // IDEN vertical Start
        ((unsigned int *)Data)[0]   = (unsigned int)Data[0] + ((unsigned int)Data[1] << 8) - 1;

        if (((unsigned int *)Data)[0] > (usIPV_ACT_STA + ucV_Max_Margin - 0x80))
        {
            ((unsigned int *)Data)[1]   = (usVsync + 128 - 2) - (usIPV_ACT_STA + usIPV_ACT_LEN);    // Actual V max. Margin

            ucDV_Delay      = (unsigned char)((unsigned int)ucDV_Delay + ucV_Max_Margin - 0x80);
            usIPV_ACT_STA   = usIPV_ACT_STA + ucV_Max_Margin - 0x80;

            if (ucV_Max_Margin < ((unsigned int *)Data)[1])
            {
                // We have to increase IVS delay to fix ucV_Max_Margin
                if ((((unsigned int *)Data)[1] - ucV_Max_Margin) >= (((unsigned int *)Data)[0] - usIPV_ACT_STA))
                    ((unsigned int *)Data)[1]   = ((unsigned int *)Data)[0] - usIPV_ACT_STA + PROGRAM_VDELAY;
                else
                    ((unsigned int *)Data)[1]   = usIPV_ACT_STA + ((unsigned int *)Data)[1] - ucV_Max_Margin + PROGRAM_VDELAY;

                if (126 < ((unsigned int *)Data)[1])    ((unsigned int *)Data)[1]  = 126;

                RTDSetByte(IVS_DELAY_8C, 0x80 | ((unsigned int *)Data)[1]);
            }
        }
        else if (((unsigned int *)Data)[0] < (usIPV_ACT_STA + ucV_Min_Margin - 0x80))
        {
            ucDV_Delay      = (unsigned char)((unsigned int)ucDV_Delay + ucV_Min_Margin - 0x80);
            usIPV_ACT_STA   = usIPV_ACT_STA + ucV_Min_Margin - 0x80;

            ((unsigned int *)Data)[1]   = usIPV_ACT_STA - ((unsigned int *)Data)[0];

            // We have to decrease IVS delay to fix ucV_Min_Margin
            if (PROGRAM_VDELAY <= ((unsigned int *)Data)[1])
                RTDSetByte(IVS_DELAY_8C, 0x00);
            else
                RTDSetByte(IVS_DELAY_8C, 0x80 | (PROGRAM_VDELAY - ((unsigned int *)Data)[1]));
        }
        else
        {
            ucDV_Delay      = ((unsigned int *)Data)[0] + ucDV_Delay - usIPV_ACT_STA ;
            usIPV_ACT_STA   = ((unsigned int *)Data)[0];
        }

		RTDRead(TMDS_CORRECTION_FF,0x01,N_INC);

		if(Data[0] & 0x03)
		    usIPH_ACT_STA -= 14;//if TMDS error correction enable, then compensate the IPH_ACT_STA offset.

        Data[0]     = 5;
        Data[1]     = Y_INC;
        Data[2]     = IPH_ACT_STA_06;
        Data[3]     = (unsigned char)(usIPH_ACT_STA & 0x00ff);
        Data[4]     = (unsigned char)((usIPH_ACT_STA >> 8) & 0x00ff);
        Data[5]     = 5;
        Data[6]     = Y_INC;
        Data[7]     = IPV_ACT_STA_0A;
        Data[8]     = (unsigned char)(usIPV_ACT_STA & 0x00ff);
        Data[9]     = (unsigned char)((usIPV_ACT_STA >> 8) & 0x00ff);
        Data[10]    = 4;
        Data[11]    = N_INC;
        Data[12]    = IV_DV_LINES_38;
        Data[13]    = ucDV_Delay;
        Data[14]    = 0;
        RTDWrite(Data);

        Wait_For_Event(EVENT_DVS);

        Data[0] = Frame_Sync();
        
        if (1 == Data[0])   Data[0] = Frame_Sync();     // Fail. Try again

        bFrameSync      = Data[0] ? 0 : 1;              // 0 : fail, 1 : pass
        ucSyncErrorCnt  = 0;

        //RTDSetBit(VDIS_CTRL_20, 0x5f, DHS_MASK);        // Normal display
		RTDSetBit(VDIS_CTRL_20, 0x7f, 0x20 | DHS_MASK);        // Normal display
    }
#else
    Seek_DVI_Mode(0);
#endif
}

void Set_Video_Mode(void)
{
#if(VIDEO_CHIP != VDC_NONE)

#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)
    I2CWrite(V_DISABLE);
    I2CWrite(VIDEO_ALL);
    I2CWrite((ucAV_Mode & 0x02) ? VIDEO_50 : VIDEO_60);
#endif

    RTDCodeW((ucAV_Mode & 0x02) ? RTD_VIDEO_50 : RTD_VIDEO_60);

//    if (PANEL_OFF == MCU_ReadPanelPower())
    if (OFF == bPanel_Status)
    {

        RTDSetByte(VDIS_SIGINV_21, 0x00 | DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP);       // DHS, DVS, DEN, DCLK MUST NOT be inverted.

        RTDSetBit(VDIS_CTRL_20, 0xfd, 0x01);    // DHS, DVS, DEN, DCLK and data are clamped to 0
    }


#if (VIDEO_CHIP == VDC_SAA7118)
    if (SOURCE_YUV == (stGUD1.INPUT_SOURCE & 0x07))
    {
        I2CWrite(VIDEO_YUV);
    }
    else
#endif
    {
        Data[0] = (SOURCE_SV == (stGUD1.INPUT_SOURCE & 0x07)) ? 0 : 1;

        switch (ucAV_Mode)
        {
        case 0x01:          //(60Hz) NTSC-M, JAPAN(7111A)
        case 0x81:          //(60Hz) Default
            I2CWrite(Data[0] ? AV_60_0 : SV_60_0);
            break;
        case 0x11:          //(60Hz) PAL-4.43
            I2CWrite(Data[0] ? AV_60_1 : SV_60_1);
            break;
        case 0x21:          //(60Hz) NTSC-4.43
            I2CWrite(Data[0] ? AV_60_2 : SV_60_2);
            break;
        case 0x31:          //(60Hz) PAL-M
            I2CWrite(Data[0] ? AV_60_3 : SV_60_3);
            break;
        case 0x41:          //(60Hz) NTSC-JAPAN(7114)
            I2CWrite(Data[0] ? AV_60_4 : SV_60_4);
            break;
        case 0x02:          //(50Hz) PAL-BGHI
        case 0x82:          //(50Hz) Default
            I2CWrite(Data[0] ? AV_50_0 : SV_50_0);
            RTDSetBit(VGIP_SIGINV_05,0xff,0x10);
            break;
        case 0x12:          //(50Hz) NTSC-4.43
            I2CWrite(Data[0] ? AV_50_1 : SV_50_1);
            break;
        case 0x22:          //(50Hz) PAL-N
            I2CWrite(Data[0] ? AV_50_2 : SV_50_2);
            break;
        case 0x32:          //(50Hz) NTSC-N
            I2CWrite(Data[0] ? AV_50_3 : SV_50_3);
            break;
        case 0x42:          //Reserved
            I2CWrite(Data[0] ? AV_50_4 : SV_50_4);
            break;
        case 0x03:          //(50Hz) SECAM
            I2CWrite(Data[0] ? AV_SECAM : SV_SECAM);
			RTDSetBit(VGIP_SIGINV_05,0xff,0x10);
            break;
        default:    
            break;
        }
    }
#endif
}

void Display_Video_Set(void)
{    
#if(VIDEO_CHIP != VDC_NONE)
    unsigned char ucCounter;

    Load_MUD(ucMode_Curr);      // Read mode default settings from 24C04

    Set_Video_Mode();

    if (SOURCE_TV == (stGUD1.INPUT_SOURCE & 0x07))      I2CWrite(TV_SOURCE_SEL);

    // Read H,V Standard Start Position and H Width
    RTDRead(IPH_ACT_STA_06, 0x08, Y_INC);
    usIPH_ACT_STA   = (unsigned int)Data[0] + ((unsigned int)Data[1] << 8);
    usIPH_ACT_STA   = usIPH_ACT_STA & 0x07ff;
    usIPH_ACT_WID   = (unsigned int)Data[2] + ((unsigned int)Data[3] << 8);
    usIPH_ACT_WID   = usIPH_ACT_WID & 0x07ff;
    usIPV_ACT_STA   = (unsigned int)Data[4] + ((unsigned int)Data[5] << 8);
    usIPV_ACT_STA   = usIPV_ACT_STA & 0x07ff;
    usIPV_ACT_LEN   = (unsigned int)Data[6] + ((unsigned int)Data[7] << 8);
    usIPV_ACT_LEN   = usIPV_ACT_LEN & 0x07ff;

    // Read ucDH_TOTAL
    RTDRead(DH_TOTAL_22, 2, Y_INC);
    usDH_Total  = ((unsigned int)(Data[1] & 0x07) << 8) + Data[0];
    
    // Read ucDV_Delay
    RTDRead(IV_DV_LINES_38, 1, N_INC);
    ucDV_Delay  = Data[0];

    ucV_Max_Margin  = 0x80;
    ucV_Min_Margin  = 0x80;

    Set_Gamma();
    Set_Dithering();
    Set_Bright_Contrast();
    Sharpness();

    // Update VDC's Contrast/Brightness/Hue/Saturation
    SetVDC_Color();

    ucCounter   = 28;
    do
    {
        RTDSetByte(SYNC_POR_4C, 0x00);  // Reset Sync Processor

        Measure_Mode();

        Delay_Xms(80);

        RTDRead(SYNC_POR_4C, 0x05, Y_INC);

        if (Data[0] & 0x02)
        {
            usHsync = 0;
            usVsync = 0;
        }
        else
        {
            Data[5] = Data[3];
            Data[4] = Data[4] & 0x87;
            Data[3] = Data[1];
            Data[2] = Data[2] & 0x8f;

            usHsync = ((unsigned int *)Data)[1];    // Current usHsync timing
            usVsync = ((unsigned int *)Data)[2];    // Current usVsync timing

            if (0x07ff <= usHsync || 0x07ff <= usVsync || 0 == usHsync || 0 == usVsync)
            {
                usHsync = 0;
                usVsync = 0;
            }
            else
            {
                break;
            }
        }
    }
    while (--ucCounter);

	RTDSetByte(STATUS0_01, 0x00);  // Clear status  
    RTDSetByte(STATUS1_1F, 0x00);  // Clear status
	
	Data[0] = Frame_Sync();

    if (1 == Data[0])   Data[0] = Frame_Sync();     // Fail. Try again

    bFrameSync      = Data[0] ? 0 : 1;              // 0 : fail, 1 : pass
   	

    ucSyncErrorCnt  = 0;

//	RTDSetBit(VDIS_CTRL_20, 0x5f, DHS_MASK);        // Normal display
    RTDSetBit(VDIS_CTRL_20, 0x7f, 0x20 | DHS_MASK);        // Normal display
#else
    Set_Video_Mode();
#endif
}

void Input_Mode_Detector(void)
{
 RTDRead(SYNC_POR_4C, 0x01, N_INC);
            
            if (0 == (Data[0] & 0x02))      ucModeCnt   = 0;

            if (ucModeCnt)
            {                  
		    	ucModeCnt   -= 1;
            }
            else
            {
                ucModeCnt   = MODE_DETECT_FREQ;

#if(SOURCE_AUTO_SCAN) 
                Source_Auto_Scan();
#else
                Mode_Detector();
#endif				
				
                if (!bStable)
                {
                    bReload     = 1;            // Reload user's font

                    Set_Task(STATE_MODECHANGE); // Notify Task State Machine
                }
            }
}

///////////////////////////////////////////////////////////////////////////////////
//anson 05_0314
///////////////////////////////////////////////////////////////////////////////////
void New_Mode_Auto(void)
{

	if	(bStable && 
		bFrameSync && 
		((stGUD1.OSD_INPUT & 0x20) == 0x20) && 
		(MODE_NOSIGNAL != ucMode_Curr) &&
		(MODE_NOSUPPORT != ucMode_Curr) && 
		ucfrist 
		)
	{
		OSD_Position(OSD_ENABLE);
		OSD_Position(OSD_ENABLE);
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
		RTDOSDW(OSD_Reset);
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
		RTDOSDW(OSD_AUTO);
		RTDOSDW(strTabAuto_Atb[stGUD1.FUNCTION & 0x07]);		//anson
		Auto_Config();
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
		RTDOSDW(OSD_Reset);

		stGUD1.OSD_INPUT &= 0xdf;//Clear "First Time Into Mode" Bit
		Save_GUD1();
		ucfrist = (ucMode_Curr - 1 ) / 8 ;                
		I2CRead(ADDR_EROM1, ucfrist , 1);
		Data[1] = 0x01;
		Data[1] = Data[1] << (ucMode_Curr - 1 - (ucfrist*8)) ; 
		Data[3] = Data[0] & ~Data[1];
		
		Data[0] = 4;
		Data[1] = ADDR_EROM1;
		Data[2] = ucfrist;                                                                             
		I2CWrite(Data);
		Delay_Xms(SET_2404_DELAY);
		ucfrist = 0;
	}

}

