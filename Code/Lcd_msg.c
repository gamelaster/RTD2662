#define __MESSAGE__

#include "reg52.h"

#include "Header\MAIN_DEF.H"
#include "Header\CONFIG.H"
#include "Header\ACCESS.H"
#include "Header\LCD_FUNC.H"
#include "Header\LCD_MSG.H"
#include "Header\LCD_MAIN.H"
#include "Header\LCD_OSD.H"
#include "Header\MTV512.H"
#include "Header\OSD.H"
#include "Header\FONT.H"
#include "Header\SRC_CTRL.H"
#include "Header\FRAME_SYNC.H"
#include "Header\rgb_echo.H"

unsigned char GetKeyState(void)
{
/*		//anson 050519
#if(MCU_TYPE == MCU_WINBOND)

    unsigned char   ucKeyState;

#if (BOARD_TYPE == QA_PCB || BOARD_TYPE == DEMO_LVDS_A || KINGMICE)

    ucKeyState  = bPOWER_KEY ? P3 | (IR_KEY_MASK | POWER_KEY_MASK) : (P3 | IR_KEY_MASK) & (0xff ^ POWER_KEY_MASK);
#elif(BOARD_TYPE == DEMO1_PCB)
   ucKeyState  = bPOWER_KEY ? P1 | (IR_KEY_MASK | POWER_KEY_MASK) : (P1 | IR_KEY_MASK) & (0xff ^ POWER_KEY_MASK);
#else
        ucKeyState  = (P3 & 0x40) | (P1 & 0x1b) | IR_KEY_MASK;
#endif

#if (IRPOLLING)
    {
    //    unsigned char   ucIR_Curr;
        
        // You cannot respond to ucIR_Cmd[0] when IR command decoding (1 < ucIR_State).
        // Because ucIR_Cmd[0] is not a constant during command decoding.
        Data[0]   = (1 < ucIR_State) ? 0 : ucIR_Cmd[0];

        if (Data[0])
        {
            switch (Data[0])
            {
#if (POWER_KEY_TYPE == TYPE_ONE_TOUCH)
            // Only when power-key is one-touch style, you can use IR remote controller to switch power on/off
            case IR_POWER_KEY :     ucKeyState  &= (0xff ^ POWER_KEY_MASK);     break;
#endif
            // Use IR to implement standard key
            case IR_LEFT_KEY :      ucKeyState  &= (0xff ^ LEFT_KEY_MASK);      break;
            case IR_RIGHT_KEY :     ucKeyState  &= (0xff ^ RIGHT_KEY_MASK);     break;
            case IR_ENTER_KEY :     ucKeyState  &= (0xff ^ ENTER_KEY_MASK);     break;
            // Other IR function key
            default :        
                ucKeyState  &= (0xff ^ IR_KEY_MASK);

#if (TV_CHIP != TV_NONE)
                switch (Data[0])
                {
                case IR_FUNC_SOURCE :   Data[0] = NOTIFY_IR_SOURCE;     break;
                case IR_FUNC_DISP :     Data[0] = NOTIFY_IR_DISP;       break;
                case IR_FUNC_JUMP :     Data[0] = NOTIFY_IR_JUMP;       break;
                case IR_FUNC_CHDEC :    Data[0] = NOTIFY_IR_CHDEC;      break;
                case IR_FUNC_CHINC :    Data[0] = NOTIFY_IR_CHINC;      break;
                case IR_FUNC_VOLINC :   Data[0] = NOTIFY_IR_VOLINC;     break;
                case IR_FUNC_VOLDEC :   Data[0] = NOTIFY_IR_VOLDEC;     break;
                case IR_FUNC_MENU :     Data[0] = NOTIFY_IR_MENU;       break;
                case IR_FUNC_ENTER :    Data[0] = NOTIFY_IR_ENTER;      break;
                case IR_FUNC_MUTE :     Data[0] = NOTIFY_IR_MUTE;       break;
                case IR_FUNC_NUM0 :     Data[0] = NOTIFY_IR_NUM0;       break;
                case IR_FUNC_NUM1 :     Data[0] = NOTIFY_IR_NUM1;       break;
                case IR_FUNC_NUM2 :     Data[0] = NOTIFY_IR_NUM2;       break;
                case IR_FUNC_NUM3 :     Data[0] = NOTIFY_IR_NUM3;       break;
                case IR_FUNC_NUM4 :     Data[0] = NOTIFY_IR_NUM4;       break;
                case IR_FUNC_NUM5 :     Data[0] = NOTIFY_IR_NUM5;       break;
                case IR_FUNC_NUM6 :     Data[0] = NOTIFY_IR_NUM6;       break;
                case IR_FUNC_NUM7 :     Data[0] = NOTIFY_IR_NUM7;       break;
                case IR_FUNC_NUM8 :     Data[0] = NOTIFY_IR_NUM8;       break;
                case IR_FUNC_NUM9 :     Data[0] = NOTIFY_IR_NUM9;       break;
                default :               ucKeyState  |= IR_KEY_MASK;     break;
                }
#endif
                break;
            }
        }
    }
#endif
    
    return ((ucKeyState & ALL_KEY_MASK) | KEY_DISABLED) ^ ALL_KEY_MASK;
#else
*/		//anson 050519
unsigned char ucKeyState=0;

        if(!bRIGHT_KEY)
	          ucKeyState=ucKeyState|RIGHT_KEY_MASK;
        if(!bLEFT_KEY)
	          ucKeyState=ucKeyState|LEFT_KEY_MASK;
        if(!bENTER_KEY)
	          ucKeyState=ucKeyState|ENTER_KEY_MASK;
//        if(!bMENU_KEY)
//	          ucKeyState=ucKeyState|MENU_KEY_MASK;
        if(!bPOWER_KEY)
	          ucKeyState=ucKeyState|POWER_KEY_MASK;
        if(!bAUTO_KEY)
	          ucKeyState=ucKeyState|AUTO_KEY_MASK;

        return ucKeyState;

//#endif			//anson 050519
}

// Key_Trans() is used for generating key related messages, including OSD timout message.
// You can just issue the message or execute system default function, like changing input source.

// BE CAREFUL !! YOU CANNOT CHANGE ANY OSD STATUS REGISTERS OR CALL ANY OSD PROCESS HERE !!
// You should not expect OSD_Proc() can always receive your message.
// Because main program will shield OSD process from been triggered when input signal isn't stable,
// and terminate OSD process when input source is changed.
unsigned char Key_Trans()
{
    static unsigned char    idata   ucP3_Prev       = 0;
    static unsigned char    idata   ucP3_Curr       = 0;
    static unsigned char    idata   ucKey_Repeat    = 0;

    unsigned char   ucNotify    = NOTIFY_NONE;

    // Save the previous key status
    ucP3_Prev   = ucP3_Curr;
    // Sample the current key status
    ucP3_Curr   = GetKeyState();

#if (POWER_KEY_TYPE == TYPE_TWO_STATE)
	// We MUST handle power-key first.
	if (bPower_Status)
	{
		if (ucP3_Curr & POWER_KEY_MASK)
			ucP3_Curr   ^= POWER_KEY_MASK;  // Go further to handle other keys (and mask power-key)
		else
		{
			Delay_Xms(20);

			ucP3_Prev   = ucP3_Curr;
			ucP3_Curr   = GetKeyState();

			if (ucP3_Curr & POWER_KEY_MASK)
				ucP3_Curr   ^= POWER_KEY_MASK;  // Go further to handle other keys (and mask power-key)
			else
				return  NOTIFY_POWERDOWN;
		}
	}
	else
	{
		if (ucP3_Curr & POWER_KEY_MASK)
		{
			ucKey_Issued    = 0;

			Delay_Xms(20);

			ucP3_Prev   = ucP3_Curr;
			ucP3_Curr   = GetKeyState();

			if (ucP3_Curr & POWER_KEY_MASK)
				return NOTIFY_POWERUP;
			else
				return NOTIFY_NONE;
		}
		else
			return NOTIFY_NONE;
	}

#else   // POWER_KEY_TYPE is TYPE_ONE_TOUCH

	if (bPower_Status)
	{
		if (POWER_KEY_MASK & ucP3_Curr)
		{
			if ((ucP3_Prev ^ ucP3_Curr) & POWER_KEY_MASK)
			{
				Delay_Xms(20);

				ucP3_Curr   = GetKeyState();

				if ((ucP3_Prev ^ ucP3_Curr) & POWER_KEY_MASK)   
				{
					if(((stGUD3.TV_SETTING & 0x08)==0x08) || ((stGUD3.TV_SETTING & 0x20)==0x20 ))  //anson	
					{
						stGUD3.TV_SETTING &= 0xF7 ;  //anson Factory bit=0
						Save_GUD3();		//anson
					}
					return NOTIFY_POWERDOWN;
				}
				else
					return NOTIFY_NONE;
			}
		}
	}
	else
	{
		if ((RIGHT_KEY_MASK| POWER_KEY_MASK ) == ucP3_Curr) 		//anson
		{
			stGUD3.TV_SETTING |= 0x08;//Factory mode
			Save_GUD3();
			return NOTIFY_POWERUP;
		}

		else if ((MODE_NOSIGNAL == ucMode_Curr) &&((LEFT_KEY_MASK | POWER_KEY_MASK) == ucP3_Curr))     //anson
		{	//ucNotify    = NOTIFY_BURNIN_KEY;
			stGUD3.TV_SETTING = stGUD3.TV_SETTING | 0x20; //Burning Mode
			Save_GUD3();
			return NOTIFY_POWERUP;
		}         

		else if (POWER_KEY_MASK & ucP3_Curr)
		{
			if ((ucP3_Prev ^ ucP3_Curr) & POWER_KEY_MASK)
			{
				ucKey_Issued    = 0;

				Delay_Xms(20);

				ucP3_Curr   = GetKeyState();

				if ((ucP3_Prev ^ ucP3_Curr) & POWER_KEY_MASK)
					return NOTIFY_POWERUP;
				else
					return NOTIFY_NONE;
			}
			else
				return NOTIFY_NONE;
		}
	}

#endif

    // Generate Key Messages
    switch (ucP3_Curr)
    {
///////////////////////////////////////////////////////////////////////////////////
//anson
///////////////////////////////////////////////////////////////////////////////////

	case FACTORY_KEY_MASK :		//anson 0921
		if ((ucP3_Prev ^ ucP3_Curr) & FACTORY_KEY_MASK)
		{
			do
			{
				ucP3_Curr   = GetKeyState();
			}while(ucP3_Curr != 0x00);

			ucKey_Issued    = 0;
			ucNotify        = NOTIFY_FACTORY_KEY;
		}
		break;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

    case AUTO_KEY_MASK :
        if ((ucP3_Prev ^ ucP3_Curr) & AUTO_KEY_MASK)
        {
            ucKey_Issued    = 0;
            ucNotify        = NOTIFY_AUTO_KEY;
        }
        break;
/*
    case MENU_KEY_MASK :
        if ((ucP3_Prev ^ ucP3_Curr) & MENU_KEY_MASK)
        {
           if (ucOSD_Page_Index)
           {
              ucKey_Issued    = 0;
//            ucNotify        = NOTIFY_MENU_KEY;  //default , now mask for exit function
              ucNotify        = NOTIFY_EXIT_KEY;
           }
           else
           {
              bStable  = 0;
              return NOTIFY_POWERUP;
           }
        }
        break;
*/    
    case ENTER_KEY_MASK :
        if ((ucP3_Prev ^ ucP3_Curr) & ENTER_KEY_MASK)
        {
            ucKey_Issued    = 0;

            //usOSD_Timer     = (unsigned int)stGUD1.OSD_TIMEOUT << 9;    // Reset OSD timeout timer
            usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 51; 
            ucNotify        = NOTIFY_ENTER_KEY;                         // Post enter-key pressed message
            ucKey_Repeat    = KEY_REPEAT_COUNT * 8;
        }
        else
        {
            if (ucKey_Repeat)
                ucKey_Repeat    -= 1;
            else
            {
                if (ucOSD_Page_Index)
                {
                    usOSD_Timer = 0;
                    ucNotify    = NOTIFY_CLEAR_OSD;
                }
            }
        }
        break;
    
    case RIGHT_KEY_MASK :
    case LEFT_KEY_MASK:
        //usOSD_Timer     = (unsigned int)stGUD1.OSD_TIMEOUT << 9;        // Reset OSD timeout timer
//----------------------------------echo add begin
        if (ucOSD_Page_Index)
        {
           usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 51;
        }
        else
        {
           if (b_rgb_VOLUME_STATUS)
              usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 4;
        }
//----------------------------------echo add end;           
        
        if ((ucP3_Prev ^ ucP3_Curr) & ucP3_Curr)
        {
            ucKey_Issued    = 0;

            ucNotify        = (ucP3_Curr == RIGHT_KEY_MASK) ? NOTIFY_RIGHT_KEY : NOTIFY_LEFT_KEY;  // Post right-key pressed message
            ucKey_Repeat    = KEY_REPEAT_COUNT;
        }
        else
        {
            if (ucKey_Repeat)
                ucKey_Repeat    -= 1;
            else
            {
                if (KEY_TURBO_ENABLE > ucKey_Issued)
                {
                    ucKey_Issued    += 1;
                    ucKey_Repeat    = KEY_REPEAT_PERIOD;
                }
                else
                    ucKey_Repeat    = 0;

                ucNotify        = (ucP3_Curr == RIGHT_KEY_MASK) ? NOTIFY_RIGHT_KEY : NOTIFY_LEFT_KEY;  // Post right-key repeat message
            }
        }
        break;
/*    
    case LEFT_KEY_MASK :
        //usOSD_Timer     = (unsigned int)stGUD1.OSD_TIMEOUT << 9;        // Reset OSD timeout timer
        usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 51; 

        if ((ucP3_Prev ^ ucP3_Curr) & LEFT_KEY_MASK)
        {
            ucKey_Issued    = 0;

            ucNotify        = NOTIFY_LEFT_KEY;                          // Post left-key pressed message
            ucKey_Repeat    = KEY_REPEAT_COUNT;
        }
        else
        {
            if (ucKey_Repeat)
                ucKey_Repeat    -= 1;
            else
            {
                if (KEY_TURBO_ENABLE > ucKey_Issued)
                {
                    ucKey_Issued    += 1;
                    ucKey_Repeat    = KEY_REPEAT_PERIOD;
                }
                else
                    ucKey_Repeat    = 0;

                ucNotify        = NOTIFY_LEFT_KEY;                      // Post left-key repeat message
            }
        }
        break;
*/
/*    case IR_KEY_MASK :
        ucKey_Issued    = 0;
        if ((ucP3_Prev ^ ucP3_Curr) & IR_KEY_MASK)
        {
            if (SOURCE_TV == (stGUD1.INPUT_SOURCE & 0x07))
            {
                //usOSD_Timer     = (unsigned int)stGUD1.OSD_TIMEOUT << 9;    // Reset OSD timeout timer
                usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 51; 
            }

            ucNotify        = Data[0];                                      // Post IR-key pressed message
            ucKey_Repeat    = KEY_REPEAT_COUNT;
        }
        else if (NOTIFY_IR_VOLINC == Data[0] || NOTIFY_IR_VOLDEC == Data[0])
        {
            if (ucKey_Repeat)
                ucKey_Repeat    -= 1;
            else
            {
                ucNotify        = Data[0];
                ucKey_Repeat    = KEY_REPEAT_PERIOD;
            }
        }
        break;
 */   
    default :
        // No key or more than 1 key pressed. Post no message and reset key-repeat.
        ucKey_Repeat    = KEY_REPEAT_COUNT;
        ucKey_Issued    = 0;

#if (HIDDEN_PAGE)        
        // For triggering the hidden page
        if (0 == ucOSD_Page_Index && (RIGHT_KEY_MASK | LEFT_KEY_MASK) == ucP3_Curr)     ucNotify    = NOTIFY_LR_KEY;
#endif
        break;
    }

    return ucNotify;
}


void OSD_Dispatcher(unsigned char message)
{
    if (bReload)
    {
        // When bStable and bReload are both 1s, it is the first iteration after input signal becomes stable.
        // bReload will be cleared and user's font will be reloaded.
        bReload = 0;

        RTDSetByte(HOSTCTRL_02, 0x40);          // Wake RTD up
    	RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);	// Disable overlay control
        RTDOSDW(OSD_Reset);                    // Clear OSD
      //  RTDSetBit(OVL_CTRL_6D, 0xff, 0x02);     // Turn back to the original osd display width

       // Load_Font(JAPANESS == (stGUD1.FUNCTION & 0x07) ? Font_East_J : Font_East_C, 0x00, 0x12);
		//Load_Font(Font_Global, 0x00, 0x154);
/*
		Load_VLC_Font(Font_Global, 0x00, 0xa1);
      		if( (stGUD1.FUNCTION & 0x07) == JAPANESS )
      		{
      			Load_VLC_Font(Font_East_J, 0x573, 0x4B);
      		}
      		else
      		{
     		     	Load_VLC_Font(Font_East_C, 0x5a9, 0x45);
      		}
      		Load_VLC_Font(Font_Icons, 0x828, 0x70);
*/
        if (ucOSD_Page_Index)
        {
            message = NOTIFY_SHOW;
        }
        else
        {
            message = NOTIFY_NONE;

		RTDSetBit(OVL_CTRL_6D, 0x3f, 0x00);	//Red
		RTDSetBit(BGCOLOR_CONTROL_6C, 0x00, 0x00);
		RTDSetBit(OVL_CTRL_6D, 0x3f, 0x40);	//Green
		RTDSetBit(BGCOLOR_CONTROL_6C, 0x00, 0x00);
		RTDSetBit(OVL_CTRL_6D, 0x3f, 0x80);	//Blue
		RTDSetBit(BGCOLOR_CONTROL_6C, 0x00, 0x00);
	
           if (BEGIN_MODECHANGE < usTaskCnt)    Show_Note();
        }

        // We always read REG[1F] to see if frame-sync is OK.
        // ucStatus is the OR result of REG[1F] when OSD is open, and clear to 0 when OSD is close.
        //ucStatus    = 0;

    }

    if ((0 == ucOSD_Page_Index) && (!b_rgb_VOLUME_STATUS))
    {
        if ((BEGIN_MODECHANGE == usTaskCnt))
        {
            // Disable and clear input source note text
            RTDSetByte(HOSTCTRL_02, 0x40);
	     RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);     
            RTDOSDW(OSD_Reset);
        }
        else if ((BEGIN_SHOWHINT == usTaskCnt))
        {
           Show_Hint();
        }
		
		
		//else if (1 == usTaskCnt)
		//{
		//    RTDOSDW(OSD_Reset);            // Clear OSD
		//}
    }
    else if (NOTIFY_NONE == message)
    {
//        if (0 == usOSD_Timer && 0 != stGUD1.OSD_TIMEOUT && SOURCE_TV != (stGUD1.INPUT_SOURCE & 0x07))
        if (0 == usOSD_Timer && 0 != stGUD1.OSD_TIMEOUT )
        {
            message = NOTIFY_CLEAR_OSD;
        }
    }

    switch (message)
    {
    case NOTIFY_CLEAR_OSD :
//        if (ucOSD_Page_Index && SOURCE_TV != (stGUD1.INPUT_SOURCE & 0x07))
        if ((ucOSD_Page_Index) || (b_rgb_VOLUME_STATUS))
        {
            // OSD time-out
            ucOSD_Page_Index    = 0;
            ucOSD_Item_Index0   = 0;
            ucOSD_Item_Index1   = 0;
            ucOSD_Item_Index2   = 0;

            b_rgb_VOLUME_STATUS = 0;  // echo add 04/05/18

            RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up

            // Although you can add ending animation here, I don't think it is necessary.
				RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
            RTDOSDW(OSD_Reset);            // Clear OSD
        }
        break;
/*
    case NOTIFY_EXIT_KEY :
            ucOSD_Page_Index    = 0;
            ucOSD_Item_Index0   = 0;
            ucOSD_Item_Index1   = 0;
            ucOSD_Item_Index2   = 0;

            b_rgb_VOLUME_STATUS = 0;  // echo add 04/05/18

            RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up

            // Although you can add ending animation here, I don't think it is necessary.
				RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
            RTDOSDW(OSD_Reset);            // Clear OSD
        break;
*/

/*
    case NOTIFY_EXIT_KEY :
        break;
*/
    case NOTIFY_MENU_KEY :
    case NOTIFY_IR_SOURCE :
        if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07))
        {
#if (TMDS_ENABLE) 
            Change_Source(SOURCE_DVI);
#else
            Change_Source(SOURCE_AV);
#endif
        }
        else if (SOURCE_DVI == (stGUD1.INPUT_SOURCE & 0x07))
            Change_Source(SOURCE_AV);
        else if (SOURCE_AV == (stGUD1.INPUT_SOURCE & 0x07))
            Change_Source(SOURCE_SV);
        else if (SOURCE_SV == (stGUD1.INPUT_SOURCE & 0x07))
        {
#if (VIDEO_CHIP == VDC_SAA7118)
            Change_Source(SOURCE_YUV);
#else
            Change_Source(SOURCE_TV);
#endif
        }
        else if (SOURCE_YUV == (stGUD1.INPUT_SOURCE & 0x07))
        {
            Change_Source(SOURCE_TV);
        }
        else
        {
            Change_Source(SOURCE_VGA);
        }
        break;

    default :
        {
            // Save the current OSD page index
            unsigned char   ucPage_Curr     = ucOSD_Page_Index;

            // Send messages to OSD process
            //(*OSD_Proc[ucOSD_Page_Index][stGUD1.INPUT_SOURCE & 0x07])(message);
            OSD_Proc(message);

            // If OSD page is changed ...
            if (ucPage_Curr != ucOSD_Page_Index)
            {
                if (ucOSD_Page_Index)
                {
                    if (0 == ucPage_Curr)
                    {
                        // ucOSD_Page_Index becomes non-zero value from zero. It is the first show of OSD.
                        // Maybe RTD3001 is still in power-saving mode, or we are showing some text on screen,
                        // like "No Signal". So we must wake up RTD3001 and clear screen before we display OSD.
                        RTDSetByte(HOSTCTRL_02, 0x40);
                        RTDSetBit(VDIS_CTRL_20, 0xff, 0x01);
						RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);     
                        RTDOSDW(OSD_Reset);
                    }

                    //(*OSD_Proc[ucOSD_Page_Index][stGUD1.INPUT_SOURCE & 0x07])(NOTIFY_SHOW);
                    OSD_Proc(NOTIFY_SHOW);

					if (0 == ucPage_Curr)
					{
						//RTDCodeW(OSD_Enable);
						//RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);

						OSD_Opening();
					}
                }
                else
                {
                    // OSD should be cleared when ucOSD_Page_Index becomes 0. 
                    // Clear other OSD status registers for safety
                    ucOSD_Item_Index0   = 0;
                    ucOSD_Item_Index1   = 0;
                    ucOSD_Item_Index2   = 0;

                    RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up

                    OSD_Ending();
					//RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);     
                    //RTDCodeW(OSD_Reset);            // Clear OSD
                }
            }
            else
            {
                // OSD page is not changed
                if (ucOSD_Page_Index)
                {
					if (NOTIFY_SHOW == message)     
					{
						RTDCodeW(OSD_Enable);
						RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
					}

                    // Change H/V Position and ADC clock may cause overflow/underflow temporarily.
                    if (NOTIFY_RIGHT_KEY == message || NOTIFY_LEFT_KEY == message)
                    {

						RTDSetByte(STATUS0_01, 0x00);  // Clear status
                        RTDSetByte(STATUS1_1F, 0x00);  // Clear status

                    }
#if (SHOW_CHECK)
                    // Just for showing debug information
                    OSD_Show_Check();
			if( ucOSD_Item_Index0 == 5 &&  ucOSD_Page_Index == 1 &&  ucOSD_Item_Index1)
			{
				ucOSD_Page_Index = 7;
				OSD_Show_Check();
				ucOSD_Page_Index = 1;

			}
#endif
                }
                else
                {
                    // We always read REG[1F] to see if frame-sync is OK.
                    // ucStatus is the OR result of REG[1F] when OSD is open, and clear to 0 when OSD is close.
                    ucStatus    = 0;
#if (RTDDEBUG)
                    usPE_Sum    = 0;
#endif
                }
            }
        }
        break;
    }
}

