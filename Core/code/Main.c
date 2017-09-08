//----------------------------------------------------------------------------------------------------
// Copyright of Realtek SemiConductor Corp.
// Model   : RTD2553V
// Version : V0.00c (08.31.2005)
//
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// ID Code      : Main.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __MAIN__

#include "Core\Header\Include.h"


/**
 * CMainUserInitial
 * Setting some flags for user when initial
 * @param <none>
 * @return {none}
 *
 */
void CMainUserInitial(void)
{
	// User can make some initial settings at firmware startup
	CLR_PANELPOWERSTATUS();
	CLR_LIGHTPOWERSTATUS();
	CLR_FRAMESYNCSTATUS();
	CLR_POWERSWITCH();
	CLR_FIRST_ADCCLOCK();
    CLR_OSD_READYFORDISPLAY();
#if(_HDMI_SUPPORT == _ON)
    CLR_HDMIINPUT();
#endif
	SET_FIRST_LOADFONT();
#if defined(CONFIG_VBI_ENABLE)
	CLR_OSDVBI_INITIAL();
#endif
	//SET_SOURCE_AUTOCHANGE();
	CLR_SOURCE_AUTOCHANGE();
	SET_PRE_VGA_CONNECT(bVGACONNECT);
#if(_TMDS_SUPPORT == _ON)
#if (_HDMI_SUPPORT == _ON)
	SET_PRE_HDMI_CONNECT(bHDMICONNECT);
#else
	SET_PRE_DVI_CONNECT(bDVICONNECT);
#endif
#endif
	CLR_USE_TRANSITION_RESULT();
    CheckLanguage();
}

/**
 * CMainSystemInitial
 * Initial the system for once when power up
 * @param <none>
 * @return {none}
 *
 */
void CMainSystemInitial(void)
{
#if(_VIDEO_TV_SUPPORT)
        ucAddrIfPllDM = _ADDR_IfPllDM;
#endif


    // Initial MCU
	CMcuInitial();
    CMuteOn();

    CPowerLightPowerOff();
    CPowerPanelPowerOff();
 	CScalerPageSelect(_PAGE0);//eric 20070529
	CScalerSetByte(_P0_POWER_ON_RESET_F3,_BIT7|_BIT6);		

    // Initial timer events
	CTimerInitialTimerEvent();

    // Check eeprom and load eeprom settings
	CEepromStartupCheck();
    if (GET_PNL_OUTPUT_BUS() == _PANEL_TTL)  // ericlee add for ttl panel
       SET_GAMMA(0);
    else
       SET_GAMMA(3);
//   _SET_INPUT_SOURCE(_SOURCE_VIDEO_AV);

//    CLR_POWERSTATUS();       
    // Initial scaler settings
	CScalerInitial();

    // Initial key scan status
	CKeyInitial();

    // Initial source input port settings
//	CSourceInitialInputPort();

    // Initial user settings
	CMainUserInitial();


#if(_VIDEO_SUPPORT == _ON)
    // Initial video settings
  #if(_VIDEO_TV_SUPPORT)
	if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
        CInitTV();
  #endif
   	CVideoInitial();
	CTimerDelayXms(10);			//CTimerDelayXms(200);
	CVideoOutputDisable();
#endif  // End of #if(_VIDEO_SUPPORT == _ON)



#if defined(CONFIG_VBI_ENABLE)
	// Init VBI data structure
	CCcInitial();
#endif

	//only for test mcu access ok...
	CScalerRead(_ID_REG_00, 1, pData, _NON_AUTOINC);
	MCU_THRESHOLD_VALUE_FF0F = pData[0];

	CDdcciInitial();

#if(_FAST_READ == _ON)
	CMCUSetFlashClk();
#endif
	 
    CIrdaInitial();

	//_SET_INPUT_SOURCE(_SOURCE_VIDEO_SV);
	if(GET_POWERSTATUS())
	{
		CPowerLenOn();	
	}

	//SET_FM_TYPE(GET_FM_TYPE());
    if(0 == GET_FM_STATE())
    {
	    bD0 = 1;
	    bD1 = 1;
	    bD2 = 1;
	    bD3 = 1;
	    bD4 = 1;
	    SET_FM_TYPE(0x10);
	    return;
     }
     else
     {
		switch(GET_FM_TYPE())
		{
		    case 0x00:
		        bD0 = 0;
		        bD1 = 0;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 0;
		        SET_FM_TYPE(0x00);
		        break;
		    case 0x01:
		        bD0 = 1;
		        bD1 = 0;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 0;
		        SET_FM_TYPE(0x01);
		        break;
		    case 0x02:
		        bD0 = 0;
		        bD1 = 0;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 1;//880
		        SET_FM_TYPE(0x02);
		        break;
		    case 0x03:
		        bD0 = 0;
		        bD1 = 1;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 0;//881
		        SET_FM_TYPE(0x03);
		        break;
		    case 0x04:
		        bD0 = 1;
		        bD1 = 0;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 1;//882
		        SET_FM_TYPE(0x04);
		        break;
		    case 0x05:
		        bD0 = 1;
		        bD1 = 1;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 0;//883
		        SET_FM_TYPE(0x05);
		        break;
		    case 0x06:
		        bD0 = 0;
		        bD1 = 1;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 1;//884
		        SET_FM_TYPE(0x06);
		        break;
		    case 0x07:
		        bD0 = 0;
		        bD1 = 0;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 0;//885
		        SET_FM_TYPE(0x07);
		        break;
		    case 0x08:
		        bD0 = 1;
		        bD1 = 1;
		        bD2 = 0;
		        bD3 = 0;
		        bD4 = 1;//886
		        SET_FM_TYPE(0x08);
		        break;
		    case 0x09:
		        bD0 = 1;
		        bD1 = 0;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 0;//887
		        SET_FM_TYPE(0x09);
		        break;
		    case 0x0A:
		        bD0 = 0;
		        bD1 = 0;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 1;//888
		        SET_FM_TYPE(0x0a);
		        break;
		    case 0x0B:
		        bD0 = 0;
		        bD1 = 1;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 0;//889
		        SET_FM_TYPE(0x0b);
		        break;
		    case 0x0C:
		        bD0 = 1;
		        bD1 = 0;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 1;//890
		        SET_FM_TYPE(0x0c);
		        break;
		    case 0x0D:
		        bD0 = 1;
		        bD1 = 1;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 0;//891
		        SET_FM_TYPE(0x0d);
		        break;
		    case 0x0E:
		        bD0 = 0;
		        bD1 = 1;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 1;//892
		        SET_FM_TYPE(0x0e);
		        break;
		    case 0x0F:
		        bD0 = 1;
		        bD1 = 1;
		        bD2 = 1;
		        bD3 = 0;
		        bD4 = 1;//894
		        SET_FM_TYPE(0x0f);
		        break;
		    case 0x10:
		        bD0 = 1;
		        bD1 = 1;
		        bD2 = 1;
		        bD3 = 1;
		        bD4 = 1;//894
		        SET_FM_TYPE(0x10);
		        break;
		}
	}

	bLR = GET_SCREEN_LR();
	bUD = GET_SCREEN_UD();


}


/**
 * main
 * main process
 * first system initial, then main loop
 * @param <none>
 * @return {none}
 *
*/
//sbit bP30 = P3^0;
//sbit bP31 = P3^1;
  
void main(void)
{            
    bit fTest = 1;
    CMainSystemInitial();
    
/*    CTimerDelayXms(4000);
	
	while(fTest)
    {
        bP30 = 1;
        bP31 = 1;
        CTimerDelayXms(50);
        bP30 = 0;
        bP31 = 0;
        CTimerDelayXms(50);    
    }
*/
	do
	{
		CMiscIspDebugProc();                                         
		CTimerHandler();
        CKeyHandler();
		CModeHandler();

#if defined(CONFIG_VBI_ENABLE)			
		CCcDecoder();			// vbi decode & display
#endif			
		COsdHandler(); 
	}

    while(_TRUE);

}

