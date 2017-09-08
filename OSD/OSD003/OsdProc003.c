

#define __OSDPROC003__

#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD003)

#if(_VIDEO_TV_SUPPORT)
BYTE ucNoSigCount = 0;
#endif

//--------------------------------------------------
void COsdHandler(void)
{
    bit fTest = 0;

    bOSDTimeOut = 1;

    COsdSystemFlowProc();
    
    COsdEventMsgProc();

    if (_PWOFF_STATE == ucCurrState)
        return;

    if(_NOSIGNAL_STATE == ucCurrState && GET_BURNIN_STATE() == _BURNIN_ON)
    {
		BurnInRun();		
		return;
    }


    CKeyOSDMsgCover();

    // 执行当前菜单的私有处理函数
    if(CURRENT_MENU_ITEM.Proc != NULL)
    {
        CURRENT_MENU_ITEM.Proc();
    }

    
    if (ucKeyMessage != _NONE_KEY_MESSAGE)
    {            
        CTimerReactiveTimerEvent(SEC(10), COsdDispOsdTimerEvent);
    }

	DbgShowOSDState();

#if(_VIDEO_TV_SUPPORT)
#if(_SLEEP_FUNC)
  #if(_SHOW_TV_NO_SIGNAL)
    if (!ucOsdState && !bOSDOnScreen && !bTVNoSignal)
  #else
    if (!ucOsdState && !bOSDOnScreen)
  #endif
    {
        if((0xff != ucAutoPowerDownTime) && (0 != _GET_POWER_DOWN_TIME()))
           CShowTimer();
    }
#endif
#endif


	if(fTest)
	{
 		CNotUse();
	}

    if (bDrawMute)
    {
        bDrawMute = 0;
        if (GET_AUDIO_MUTE()) // Mute on 
           CDrawMuteState();
    }
}

//--------------------------------------------------
void CKeyOSDMsgCover(void)
{
    // Key Message -> Osd Message
    if(ucCurrState == _ACTIVE_STATE)
    {
        CCoverKeyMsgToOsdEvent(CURRENT_MENU_ITEM.KeyMsgToOsdEvnet,CURRENT_MENU_ITEM.Option & _EN_PUB_KEYEVENT);
    }
    else
    {	
    	if(CURRENT_MENU_ITEM.Option & _KEYMAP_EN_IN_NOSIGNAL)
		{
        	CCoverKeyMsgToOsdEvent(CURRENT_MENU_ITEM.KeyMsgToOsdEvnet,CURRENT_MENU_ITEM.Option & _EN_PUB_KEYEVENT);
		}
		else
		{
    	    CCoverKeyMsgToOsdEvent(tKONoSignal, 0x00);
    	}
	}
}
//--------------------------------------------------

void DbgShowOSDState(void)
{
/*
	CShowNumber(0, 0, ucOsdState);
	CShowNumber(0, 1, _MI_001_RESET);

	if(ucKeyMessage != 0)
	{
	 	CShowNumber(0, 2, ucKeyMessage);
		CShowNumber(0, 3, ucOsdEventMsg);
	}
*//*
    static BYTE ucMenuItemIndexBak = 0;

	if(ucMenuItemIndexBak != ucOsdState)
	{
		ucMenuItemIndexBak = ucOsdState;
		CUartPrintf("Osd State:",ucOsdState);
	}

    // debug info
    if(ucKeyMessage != _NONE_KEY_MESSAGE)
		CUartPrintf("Osd Event:",ucOsdEventMsg);
*/
}
//--------------------------------------------------
void COsdSystemFlowProc(void)
{
    switch(ucCurrState)
    {         
        case _PWOFF_STATE:
            break;
            
        case _INITIAL_STATE:
            break;
            
        case _SEARCH_STATE:
            break;
            
        case _ACTIVE_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
            	CPowerLenOn();

                if (!bSourceVideo())
                    COsdDispOsdTimerEvent();

                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0x00, 0x00, 0x00);
                
			#if(_VIDEO_TV_SUPPORT)
            	ucNoSigCount = 0;
 				#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
                	if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
 					#endif
				#endif
                CSetVolume();
            }
                            
			#if(_VIDEO_TV_SUPPORT)
 				#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
                	CAudioCtrl(); 
 				#endif
                
 				#if(_SHOW_TV_NO_SIGNAL)
            		CCheckTVSignal();
 				#endif
			#endif

            break;
            
        case _NOSUPPORT_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
                
                CTimerReactiveTimerEvent(SEC(1), CModeNoSupportEvent);
            }
            
            break;
            
        case _NOSIGNAL_STATE:
            /*if (ucOsdState >= _MI_SOURCE_VGA && ucOsdState <= _MI_SOURCE_TV)
            {
            	CTimerCancelTimerEvent(CModeNoSignalEvent);
            	CTimerCancelTimerEvent(CModePowerSavingEvent);
                SET_OSD_READYFORDISPLAY();
                return;
            }*/

            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {    
                CLR_OSD_READYFORDISPLAY(); 
    
                if (bSourceVideo())
                   CAdjustBackgroundColor(0x00, 0x00, (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV) ? ((_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00) : 0x00);

                if (GET_FIRST_SHOW_NOTE())
                {
                    ucOsdEventMsg = _DO_SHOW_NOTE;
                    CPowerPanelOn();
                    CPowerLightPowerOn();
                }
                
     			CAdjustBackgroundColor(0x00, 0x00, 0xFF);

    			if (_GET_INPUT_SOURCE() == _SOURCE_YPBPR) 
    			{
    				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    				break;
    			}
    
    #if (_HDMI_SUPPORT == _ON)
    			if (_GET_INPUT_SOURCE() == _SOURCE_HDMI) 
    			{
    				CTimerReactiveTimerEvent(SEC(5), CModeNoSignalEvent);
    				break;
    			}		
		        
    #endif
    			// here comes for VGA, DVI input only
    #if(_TMDS_SUPPORT == _ON)
    			if (_GET_INPUT_SOURCE() == _SOURCE_DVI) 
    			{
                    if (bDVICONNECT)
        				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
                    else
    			    	CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    			}		
    #endif


    			if (_GET_INPUT_SOURCE() == _SOURCE_VGA) 
    			{
        			if (bVGACONNECT)
        				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
        			else       
        				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    	        }

                if (bSourceVideo())
        			CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);

				if(stSystemData.InputSource == _SOURCE_VGA ||
					stSystemData.InputSource == _SOURCE_DVI)
				{	
    				CTimerReactiveTimerEvent(SEC(6), CModePowerSavingEvent);
				}
				else
				{
					CTimerCancelTimerEvent(CModePowerSavingEvent);
				}
            }
            
            break;
            
        case _SLEEP_STATE:
            break;
            
        default:
            break;
    }
}

//==========================================================================
//                          ChangeSourceState
//==========================================================================
void ChangeSourceState(void)
{
    CMuteOn();
#if(_VIDEO_TV_SUPPORT)
        if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
           CAdjustBackgroundColor(0x00, 0x00, (_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00);
        else
#endif
           CAdjustBackgroundColor(0x00, 0x00, 0x00);
        CScalerSetBit(_VDISP_CTRL_28, 0xff, 0x20);
        CScalerSetBit(_VDISP_CTRL_28, ~_BIT3, _BIT5);
        CInitInputSource();
    
#if(_VIDEO_TV_SUPPORT)
 #if(_FM_DEVICE)  
        bFM = 0; // Close FM
 #endif
#endif


    if (_SLEEP_STATE == ucCurrState)
        CPowerLVDSOn();
                  
	// close OSD first to avoid dirty screen.
	COsdFxDisableOsd();
	switch(_GET_INPUT_SOURCE())
	{
		case _SOURCE_VGA:
		case _SOURCE_YPBPR:
			CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT5, 0x00);
			CVideoOutputDisable();
			break;
	#if((_TMDS_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))			
		case _SOURCE_DVI:
        case _SOURCE_HDMI:
			CVideoOutputDisable();
			break;
	#endif
		    break;
#if(_VIDEO_TV_SUPPORT)
		case _SOURCE_VIDEO_TV:
            CInitTV();
#endif
		case _SOURCE_VIDEO_AV:
		case _SOURCE_VIDEO_SV:
			CVideoOutputEnable();
			break;
	}
   
	COsdFxDisableOsd();
}

//-----------------------------------------------------------
void COsdEventMsgProc(void)
{                  
    if(ucOsdEventMsg > _OE_USER_CMD)
    {    
         ucOsdEventMsg = _NONE_MSG;
         return;
    }

    switch(ucOsdEventMsg)
    {
        case _SHOW_NOSIGNAL_MSG:
        case _SHOW_NOCABLE_MSG:
        case _SHOW_NOSUPPORT_MSG:
            if(GET_BURNIN_STATE() == _BURNIN_ON)
            {				
				CTimerCancelTimerEvent(CModePowerSavingEvent);				
				InitBurnIn();
            }
            else
            {            
            	//LoadCHIFont(_LF_OTHER);
            	LoadLanguageFont();
            	#if(LNG_CHI_S_EN)
    				if(GET_LANGUAGE() == LNG_CHI_S)
    					COsdLoad1BitFontWidth12(FntCH_S,0x80,48);      
				#endif
				#if(LNG_CHI_S_EN)
			    	if(GET_LANGUAGE() == LNG_CHI_T)
			    		COsdLoad1BitFontWidth12(FntCH_T,0x80,48);      
				#endif
			COsdDispFirstTimeLoadFont();//$$ Added by AndyLiu20080619
   			CShowNoSignal();
//                COsdDispFirstTimeLoadFont();//$$ Added by AndyLiu20080619
//                CDrawLogo(0x03);//$$ Added by AndyLiu20080619
    		}    		
            break;
            
        case _SAVE_EE_MODEUSERDATA_MSG:
            CEepromSaveModeData(stModeInfo.ModeCurr);
            break;
            
        case _SAVE_EE_SYSTEMDATA_MSG:
            CEepromSaveSystemData();
            break;
            
        case _SAVE_EE_OSDUSERDATA_MSG:
            CEepromSaveOsdUserData();
            break;
            
        case _SAVE_EE_ADCDATA_MSG:
            CEepromSaveAdcData();
            break;
            
        case _SAVE_EE_COLORPROC0_MSG:
            CEepromSaveBriConData();
            break;
            
        case _SAVE_EE_COLORPROC1_MSG:
            CEepromSaveColorTempData();
            break;

        case _SAVE_EE_AUDIO_DATA_MSG:
            CEepromSaveAudioData();
            break;

        case _SAVE_EE_HUE_SAT_DATA_MSG:
            CEepromSaveHueSatData();
            break;

        case _SAVE_EE_TV_DATA_MSG:
            CEepromSaveTvData();
            break;

        case _ENTER_FACTORY_MODE_MSG:
            break;
            
        case _CHANGE_SOURCE_MSG:
            ChangeSourceState();
            ucTVSyncFailCount = 250;
            CModeResetMode();
        	CLR_SOURCE_AUTOCHANGE();
        	CEepromSaveSystemData();
            CShowNote();
            SET_FIRST_SHOW_NOTE();
            break;
            
        case _DO_AUTO_CONFIG:
        	if(stSystemData.InputSource == _SOURCE_VGA)
        	{
				CShowAutoAdjust();
        	}
        	break;
        	
        case _DO_SHOW_NOTE:
            CLR_FIRST_SHOW_NOTE();
            CShowNote();
            break;
            
        case _OE_PIC_CHANGE_U_D:
            ChangePicUD();
            break;
        
        case _OE_PIC_CHANGE_L_R:
            ChangePicLR();
            break;
            
		case _OE_SC_TIMER_CHANGE:
		    COsdDispOsdTimerEvent();
		    if(_GET_POWER_DOWN_TIME() == 0x04)
		    {
		        _SET_POWER_DOWN_TIME(0x00);
		    }
		    else
		    {
		        _SET_POWER_DOWN_TIME(_GET_POWER_DOWN_TIME()+1);
		    }   
		    CEepromSaveTvData();//ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
		    
		    ucAutoPowerDownTime = _GET_POWER_DOWN_TIME() * 30;//andyliu
		    if (0 == ucAutoPowerDownTime) // Auto power down time off
		    {
		        ucAutoPowerDownTime = 0xff;
		    }

		    CShowTimerMode();
		    ucMinuteCount = 0;  // Reset count
		    break;


        default:
            break;
    }
    
    ucOsdEventMsg = _NONE_MSG;
}

//----------------------------------------------------------------------------------------------------
void COsdDispFirstTimeLoadFont(void)
{       
    COsdFxDisableOsd();
    COsdColorPalette(tPALETTE_0);
    
    SetOsdMap(tUserMenuOsdMap);
    
    // Load global font 
    // insert code to here 
    COsdLoad1BitFont(FntGlobal,0x00,0x5F,tGlobalCharWidth);
    CScalerLoadHardwareVLCFont(FntMainIcon,0x80 * 2);
    
	//Load Languege Font
	LoadLanguageFont();

}
//----------------------------------------------------------
void LoadLanguageFont()
{
    // load language font

	switch(GET_LANGUAGE())
	{
/*#if(LNG_CHI_S_EN)
            //if(GET_LANGUAGE() == LNG_CHI_S)
    case LNG_CHI_S:
    	COsdLoad1BitFontWidth12(FntCH_S,0x80,44);
        break;
#endif*/

#if(LNG_JAP_EN)
	case LNG_JAP:
        COsdLoad1BitFont(FntJap,0x80,0x57,tFntJapCharWidth);
        break;
#endif
#if(LNG_KOR_EN)
    case LNG_KOR:
        COsdLoad1BitFont(FntKor,0x80,0x69,tFntKorCharWidth);
        break;
#endif
#if(LNG_RUS_EN)
	case LNG_RUS:
		COsdLoad1BitFont(FntRus,0x80,0x21,tFntRusCharWidth);
        break;
#endif
	}
	

}  

//-----------------------------------------------------------
void COsdLoad1BitFontWidth12(BYTE *pFont,WORD usOffset,BYTE ucFntCount)
{
     BYTE i;
     CScalerLoadHardwareVLCFont(pFont, usOffset);

     if(usOffset > 0x100)		return;

     if(usOffset + ucFntCount > 0x100)
        ucFntCount = 0x100 - usOffset; 


     for(i=0;i<ucFntCount;i++)
     {
         SetCharWdith(usOffset,12);
         usOffset ++;
     }
     
}

//---------------------------------------------------------------------------

void LoadCHI_S_Font(BYTE ucPage)
{

	BYTE *pFont;
	COsdLoad1BitFontWidth12(FntPublic_CHI_S,0x80,0x20);	
	switch(ucPage)
	{

		case _LF_COLOR_PAGE:		pFont = FntColorPage_S;		break;
		case _LF_ADJUST_PAGE:		pFont = FntAdjustPage_S;	break;
		case _LF_TV_PAGE:			pFont = FntTVPage_S;		break;
		case _LF_OSD_PAGE:			pFont = FntOSDPage_S;		break;
		case _LF_FUNC_PAGE:			pFont = FntFuncPage_S;		break;
		case _LF_SOUND_PAGE:		pFont = FntSoundPage_S;		break;
		case _LF_OTHER:				pFont = FntOther_CHI_S;		break;
	}

	COsdLoad1BitFontWidth12(pFont,0xA0,0x22);	

}
//-----------------------------------------------------------

void LoadCHI_T_Font(BYTE ucPage)
{

	BYTE *pFont;
	COsdLoad1BitFontWidth12(FntPublic_CHI_T,0x80,0x20);	
	
	switch(ucPage)
	{

		case _LF_COLOR_PAGE:		pFont = FntColorPage_T;		break;
		case _LF_ADJUST_PAGE:		pFont = FntAdjustPage_T;	break;
		case _LF_TV_PAGE:			pFont = FntTVPage_T;		break;
		case _LF_OSD_PAGE:			pFont = FntOSDPage_T;		break;
		case _LF_FUNC_PAGE:			pFont = FntFuncPage_T;		break;
		case _LF_SOUND_PAGE:		pFont = FntSoundPage_T;		break;
		case _LF_OTHER:				pFont = FntOther_CHI_T;		break;
	}
	COsdLoad1BitFontWidth12(pFont,0xA0,0x22);


}
//-----------------------------------------------------------
void LoadCHIFont(BYTE ucPage)
{
	if(GET_LANGUAGE() == LNG_CHI_S)
	{
		LoadCHI_S_Font(ucPage);
	}
	else if(GET_LANGUAGE() == LNG_CHI_T)
	{
		LoadCHI_T_Font(ucPage);
	}

}
//-----------------------------------------------------------
void COsdDispOsdTimerEvent(void)
{

        COsdFxDisableOsd();
        ucOsdState = _MI_MENU_NONE;
            
#if(_VIDEO_TV_SUPPORT)
 #if(_SLEEP_FUNC)
        bOSDOnScreen = 0;
 #endif
             
 #if(_SLEEP_FUNC)
        if(_ACTIVE_STATE == ucCurrState && (0xff == ucAutoPowerDownTime) || (0 == _GET_POWER_DOWN_TIME()))
 #endif 
#else
        if(_ACTIVE_STATE == ucCurrState)
#endif 
        {
             bDrawMute = 1;
        }

}

//-----------------------------------------------------------
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable)
{
     BYTE i;

     if(ucKeyMessage == _NONE_KEY_MESSAGE)
     {
          //ucOsdEventMsg = _NONE_MSG;
          return 0;
     }
                        
     i = 0;
     while(1)
     {
         if(tMsgTable[i].KeyMessage == _NONE_KEY_MESSAGE)
         {
              //ucOsdEventMsg = _NONE_MSG;
              // End flag
              return 1;
         }
         if(ucKeyMessage == tMsgTable[i].KeyMessage)
         {
              ucOsdEventMsg = tMsgTable[i].OsdEvent;
              return 0;
         }

         i++;
     }
     return 1;
}                                        
//---------------------------------------------------------------------------

void CShortCutKeyMsg(void)
{
    if (ucOsdEventMsg >= _OE_CHANGE_SOURCE)
    {
        if (!CTVEnable() && ucOsdEventMsg >= _OE_SC_CH_DEC) // Only for TV
            ucOsdEventMsg = _NONE_MSG;
        else
            COsdDispOsdTimerEvent();
    }
}

//---------------------------------------------------------------------------
void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet)
{
     bit bFoundPublic = 1;

     if(tMsgTable != NULL)
         bFoundPublic = CFoundKeyMsgToOsdEvent(tMsgTable);

     if(bFoundPublic && bUserPublicKeyEvnet)
     {
         CFoundKeyMsgToOsdEvent(tKOPublic);
         CShortCutKeyMsg();
     }
}
//---------------------------------------------------------------------------
void InitOsdFrame(void)
{
    COsdFxDisableOsd();

    SetOsdMap(tUserMenuOsdMap);
    COsdFxCodeWrite(ucCloseAllWindow);

	CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((stOsdUserData.OsdBlending & 0x07) << 2));
    
    // Init osd
    // insert code to here
    OSDClear(ROW(0), HEIGHT(18), COL(0), WIDTH(46), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(0), HEIGHT(18), COL(0), WIDTH(46), 0x00, BYTE_DISPLAY);
	OSDClear(ROW(0), HEIGHT(18), COL(0), WIDTH(46), 0x40, BYTE_COLOR);
}     

//----------------------------------------------------------------------------------------------------
#define _SLIDER_BEGIN				0x04
void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color)
{
    unsigned int bound;
    unsigned char i,c;
    OSDLine(row, col, length + 6, color, THE_BYTE2);   // Set Slider Attribute. 4 extra columns for space/numbers/space
    bound   = length * value;
    
    Gotoxy(col,row,THE_BYTE1);
    OutputChar(_SLIDER_BEGIN);          // Left Border
    for (i = 1; i <= length; i++)
    {
        if (bound)
        {
            if(bound >= range)
            {
                c       = _SLIDER_BEGIN + 7;
                bound   = bound - range;
            }
            else
            {
                color   = (bound << 4) / range;
                bound   = 0;
                if (4 > color)                    c = _SLIDER_BEGIN + 2;
                else if (7 > color)               c = _SLIDER_BEGIN + 3;
                else if (10 > color)              c = _SLIDER_BEGIN + 4;
                else if (13 > color)              c = _SLIDER_BEGIN + 5;
                else                              c = _SLIDER_BEGIN + 6;
            }
        }
        else
        {
            c = _SLIDER_BEGIN + 1;
        }
        OutputChar(c);
    }
    OutputChar(_SLIDER_BEGIN + 8);    // Right Border
    CShowNumber(col + length + 2, row,value);
}

//---------------------------------------------------------------------------
void CShowNoSignal(void)
{
    COsdFxDisableOsd();
    SetOSDDouble(0);
    COsdFxCodeWrite(ucCloseAllWindow);
    COsdFxDrawWindow(XSTART(0), YSTART(0), XEND(348), YEND(72), tOSD_WINDOW0_STYLE);
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x8c, BYTE_ATTRIB);
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x00, BYTE_DISPLAY);
    OSDClear(0,ROW_COUNT,0,COL_WIDTH,0x00,BYTE_COLOR);
    OSDClear(1,1,0,COL_WIDTH,0xF0,BYTE_COLOR);
    OSDPosition(348,72,50,50,0x01);

    


    CCenterTextout(sNoSignal[GET_LANGUAGE()], ROW(1), 1, 24);

    COsdFxDrawWindow(XSTART(0), YSTART(0), XEND(348), YEND(72), tOSD_WINDOW7_STYLE);
    OSDPosition(344, 122, 53, 55, 0x03);

	COsdFxEnableOsd();

//$$ Added by AndyLiu20080619
//    COsdFxDisableOsd();
//    COsdDispFirstTimeLoadFont();
//    CDrawLogo(0x03);
//    COsdFxEnableOsd();
//$$ Added by AndyLiu20080619

}
//---------------------------------------------------------------------------
/*
void CShowReset(void)
{
	InitOsdFrame();
	SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   

	// Draw Top Line
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	// Draw Bottom Line
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	OSDLine(ROW(3), COL(1), LENGTH(45), 0x10, BYTE_COLOR);

	// Draw Window
	COsdFxDrawWindow(0,0,                               //WORD usXStart,WORD usYStart,  
	                _DIALOG_WIDTH,_DIALOG_HEIGHT,       //WORD usXEnd,WORD usYEnd,  
	                tMainWindowStyle);                  //BYTE *pStyle)
	 
	//  OSDPosition(_DIALOG_WIDTH,_DIALOG_HEIGHT,50,50,0x03);
	if (GET_OSD_SIZE())
	    OSDPosition(_OSD_DOUBLE_WIDTH(_DIALOG_WIDTH), _OSD_DOUBLE_HEIGHT(_DIALOG_HEIGHT), 50, 50, 0x03);
	else
	    OSDPosition(_DIALOG_WIDTH, _DIALOG_HEIGHT, 50, 50, 0x03);

	CCenterTextout(sReset[GET_LANGUAGE()],ROW(3),1,25);

	COsdFxEnableOsd();


	COsdFxDisableOsd();

	SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);

	SetOsdMap(t001MenuOsdMap);
	COsdFxCodeWrite(ucCloseAllWindow);

	OSDClear(ROW(0), HEIGHT(4), COL(0), WIDTH(25), 0x8C, BYTE_ATTRIB);
	OSDClear(ROW(0), HEIGHT(4), COL(0), WIDTH(25), 0x00, BYTE_DISPLAY);
	OSDClear(ROW(0), HEIGHT(4), COL(0), WIDTH(25), 0x40, BYTE_COLOR);


	CTextOutEx(sReset[GET_LANGUAGE()],COL(10),ROW(1));

	COsdFxDrawWindow(0,0,       //0,0,                      //WORD usXStart,WORD usYStart,  
	              300,65,    //450,150,                  //WORD usXEnd,WORD usYEnd,  
	              tMainWindowStyle);                     //BYTE *pStyle)

	OSDPosition(70,20,31,83,0x03);

	COsdFxEnableOsd();
	bOSDTimeOut = 0;
	CTimerReactiveTimerEvent(SEC(1), COsdDispOsdTimerEvent);


}
*/


void CShowAutoAdjust(void)
{
	InitOsdFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   
	
	// Draw nosignal & set osd position

	// Draw Top Line
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(1), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	// Draw Bottom Line
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA6, THE_BYTE0);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0xA4, THE_BYTE1);
	OSDLine(ROW(5), COL(1), LENGTH(25), 0x11, THE_BYTE2);

	OSDLine(ROW(3), COL(1), LENGTH(45), 0x10, BYTE_COLOR);

	// Draw Window
	COsdFxDrawWindow(0,0,								//WORD usXStart,WORD usYStart,  
					_DIALOG_WIDTH,_DIALOG_HEIGHT,		//WORD usXEnd,WORD usYEnd,  
					tMainWindowStyle);					//BYTE *pStyle)

    if (GET_OSD_SIZE())
        OSDPosition(_OSD_DOUBLE_WIDTH(_DIALOG_WIDTH), _OSD_DOUBLE_HEIGHT(_DIALOG_HEIGHT), 50, 50, 0x03);
    else
        OSDPosition(_DIALOG_WIDTH, _DIALOG_HEIGHT, 50, 50, 0x03);
	
	LoadCHIFont(_LF_ADJUST_PAGE);

	CCenterTextout(sAutoConfig[GET_LANGUAGE()],ROW(3),1,25);
	
	COsdFxEnableOsd();

	CAutoDoAutoConfig();

	COsdFxDisableOsd();	
}
//---------------------------------------------------------------------------
#define _NOTE_WIDTH						(8 * 13)//(8 * 12)	
#define _NOTE_HEIGHT					(4 * 18)

void CShowNote(void)
{
	BYTE code *pStr; 
    
    ucOsdState = _MI_MENU_NONE;
    InitOsdFrame();
    SetOSDDouble(0x01);   


	// TextOut
	switch(stSystemData.InputSource)
	{
		case _SOURCE_VGA:			pStr = sVGA;		break;
		case _SOURCE_DVI:			pStr = sDVI;		break;
		case _SOURCE_HDMI:			pStr = sHDMI;		break;
        case _SOURCE_YPBPR:         pStr = sYPBPR;      break;
		case _SOURCE_VIDEO_SV:		pStr = sSVideo;		break;
		case _SOURCE_VIDEO_AV:		pStr = sAV;			break;
		case _SOURCE_VIDEO_TV:		pStr = sTV;			break;
	}
	
	CCenterTextout(pStr,ROW(0),0,10);   
    if (GET_OSD_SIZE())
        OSDPosition(_OSD_DOUBLE_WIDTH(_NOTE_WIDTH), _OSD_DOUBLE_HEIGHT(_NOTE_HEIGHT), 0, 0, 0x03);
    else
        OSDPosition(_NOTE_WIDTH, _NOTE_HEIGHT, 0, 0, 0x03);  	
	
    COsdFxEnableOsd();
    CPowerPanelOn();  

    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut = 0;
#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
#endif
}
//---------------------------------------------------------------------------



#if(_VIDEO_TV_SUPPORT)
//---------------------------------------------------------------------------
void CShowTVNumber(BYTE ucNumber, BYTE ucOption)
{ 
    BYTE PosX = 0;

    ucOsdState     = _MI_MENU_NONE;
    bChangeChannel = 0;
    COsdFxDisableOsd();
    SetOSDDouble(0x03);
    SetOsdMap(tMsgOsdMap);
                         
    // Init OSD Ram
    OSDClear(0, 8, 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 8, 0, 30, 0x00, BYTE_DISPLAY);
    OSDClear(0, 8, 0, 30, 0xF0, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);

    OSDPosition(_MAINMENU_WIDTH,_MAINMENU_HEIGHT,64,1,0x03);
                        
    if (ucOption & _SHOW_CH_TV_NUMBER) 
        CShowNumber(0, 0, ucNumber);


    if (_SHOW_CH_TV_TYPE & ucOption)
    {
    	BYTE *pStr;

    	switch(ucTVType)
    	{
    		case _TV_NTSC_M:		pStr = sNTSC_M;			break;
    		case _TV_NTSC_4_BG:		pStr = sNTSC_4_BG;		break;
    		case _TV_NTSC_4_DK:		pStr = sNTSC_4_DK;		break;
    		case _TV_NTSC_4_I:		pStr = sNTSC_4_I;		break;
    		case _TV_PAL_M:		    pStr = sPAL_M;			break;
    		case _TV_PAL_BG:		pStr = sPAL_BG;			break;
    		case _TV_PAL_I:			pStr = sPAL_I;			break;
    		case _TV_PAL_DK:		pStr = sPAL_DK;			break;
    		case _TV_PAL_N:			pStr = sPAL_N;			break;
    		case _TV_SECAM_BG:		pStr = sSECAM_BG;		break;
    		case _TV_SECAM_DK:		pStr = sSECAM_DK;		break;
    		case _TV_SECAM_L:		pStr = sSECAM_L;		break;
    		case _TV_SECAM_LL:		pStr = sSECAM_L;		break;
        }

        CTextOutEx(pStr, 0, 1);  
    }

   
    COsdFxEnableOsd();
    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut  = 0;
#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
#endif

}
#endif // #if(_VIDEO_TV_SUPPORT)

//---------------------------------------------------------------------------

void CShowPictureMode()
{	
	BYTE *pStr;
	//ucOsdState = _MI_MENU_NONE;
    COsdFxDisableOsd();

    InitOsdFrame(); 
    SetOSDDouble(0x03);

    OSDClear(0, 8, 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 8, 0, 30, 0x00, BYTE_DISPLAY);
    OSDClear(0, 1, 0, 30, 0xc0, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow);

	// TextOut
	switch(GET_Picture_Mode())
	{
		case 0:			pStr = sStandard_Eng;		break;
		case 1:			pStr = sSoft_Eng;			break;
		case 2:			pStr = sVivid_Eng;		   break;
        case 3:         pStr = sPersonal_Eng;      break;
	}
	
	
	CCenterTextout(pStr,0,0,8);
    OSDClear(0, 8, 0, 30, 0xc0, BYTE_COLOR);
	
	// Draw Window
	//COsdFxDrawWindow(0,8,								//WORD usXStart,WORD usYStart,  
	//				_NOTE_WIDTH,_NOTE_HEIGHT,		//WORD usXEnd,WORD usYEnd,  
	//				tMainWindowStyle);					//BYTE *pStyle)
	 
    //if (GET_OSD_SIZE())
      //  OSDPosition(_OSD_DOUBLE_WIDTH(_NOTE_WIDTH), _OSD_DOUBLE_HEIGHT(_NOTE_HEIGHT), 0, 0, 0x03);
    //else
    OSDPosition(_NOTE_WIDTH, _NOTE_HEIGHT, 41, 0, 0x03);   
	CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    COsdFxEnableOsd();
    bOSDTimeOut = 0;
    bOSDOnScreen = 1;

    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut  = 0;
//    bOSDOnScreen = 0;
    
    
}



//---------------------------------------------------------------------------
void Draw2bit3x2Icon(BYTE *tIcon,BYTE x,BYTE y)
{

     Gotoxy(x,y,ALL_BYTE);

     pData[0] = tIcon[0]; 
     pData[1] = tIcon[1];
     pData[2] = tIcon[2];
     
     pData[3] = tIcon[0];
     pData[4] = tIcon[1] + 1;
     pData[5] = tIcon[2];

     pData[6] = tIcon[0];
     pData[7] = tIcon[1] + 2;
     pData[8] = tIcon[2];     
     
     CScalerWrite(_OSD_DATA_PORT_92, 9, pData, _NON_AUTOINC);
   

     Gotoxy(x,y + 1,ALL_BYTE);

     pData[0] = tIcon[0]; 
     pData[1] = tIcon[1] + 3;
     pData[2] = tIcon[2];
     
     pData[3] = tIcon[0];
     pData[4] = tIcon[1] + 4;
     pData[5] = tIcon[2];

     pData[6] = tIcon[0];
     pData[7] = tIcon[1] + 5;
     pData[8] = tIcon[2];
     
     CScalerWrite(_OSD_DATA_PORT_92, 9, pData, _NON_AUTOINC);
}

       
//---------------------------------------------------------------------------
BYTE AdjustMenuItem(BYTE ucBeginItem,BYTE ucEndItem,BYTE ucMode)
{
     BYTE i;
     BYTE ucCount;
     BYTE ucNewItem;

     CLR_KEYREPEATENABLE();

     //如果菜单只有一项,直接返回
     ucCount = ucEndItem - ucBeginItem;
     if(ucCount < 1)
     {
          return ucOsdState;
     }

     // 计算下一项菜单，或是上一菜单
     i = 0;

     ucNewItem = ucOsdState;

     while(i < ucCount)
     {

         ucNewItem = ValueInRangeChange(ucBeginItem, ucEndItem, ucNewItem, ucMode | _LOOP);

         if(g_tMenuItem[ucNewItem].Enable())
         {
             break;
         }

         i++;
     }

     return ucNewItem;

}
//----------------------------------------------------------------------------------------------------
BYTE GetShowIndex(BYTE ucMenuItem,BYTE ucBeginItem,BYTE ucEndItem)
{
     BYTE Index;

     bit fEnable;
     bit fDisableNoShow;

     Index = 0;

     while(ucBeginItem <= ucEndItem)
     {
     	fEnable = g_tMenuItem[ucBeginItem].Enable();
		if((g_tMenuItem[ucBeginItem].Option & _DISABLE_NOT_SHOW) != _DISABLE_NOT_SHOW)
			fDisableNoShow = 0;
		else
			fDisableNoShow = 1;

			
     	if(ucBeginItem == ucMenuItem)
     	{
     		if(fEnable)		
     		{
     			return Index;
     		}
     		else
     		{
				if(fDisableNoShow)
					return _NOT_SHOW;
				else
					return Index;
     		}
     	}

     	if(ucBeginItem > ucMenuItem)
     		return _NOT_SHOW;
     		
       	if(!fDisableNoShow)
       	{	
        	Index++;
        }
        else
        {
        	if(fEnable)
        	{
            	Index++;
            }
		}
        ucBeginItem++;
     }

     return _NOT_SHOW;     
}
//----------------------------------------------------------------------------------------------------
BYTE GetShowCount(BYTE ucBeginItem,BYTE ucEndItem)
{
     BYTE ucCount;

     bit fEnable;
     bit fDisableNoShow;


     ucCount = 0;

     while(ucBeginItem <= ucEndItem)
     {
     	fEnable = g_tMenuItem[ucBeginItem].Enable();
     	
		if((g_tMenuItem[ucBeginItem].Option & _DISABLE_NOT_SHOW) != _DISABLE_NOT_SHOW)
			fDisableNoShow = 0;
		else
			fDisableNoShow = 1;
     		
       	if(!fDisableNoShow)
       	{	
        	ucCount++;
        }
        else
        {
        	if(fEnable)
        	{
            	ucCount++;
            }
		}
        ucBeginItem++;
     }

     return ucCount;     
}
//----------------------------------------------------------------------------------------------------
void TextOutCalcWidth(BYTE *pStr,BYTE row,BYTE col,BYTE ucMaxLength,BYTE ucDisplayPixcel)
{
     BYTE ucPixLen = CTextOutBase(pStr, col, row);
     BYTE i = StrLen(pStr);

     ucMaxLength -= 1;

     CScalerSendAddr(_OSD_DATA_PORT_92, _NON_AUTOINC);

     for(;i<ucMaxLength;i++)
     {
         *(&MCU_SCA_INF_DATA_FFF5) = (0x80 | 4);
         ucPixLen += 4;
     }
     
     //CScalerSendWriteStop();

     // 计算 Blank 宽度
     ucPixLen = ucDisplayPixcel - ucPixLen;

     //设置 Blank                                                       
     Gotoxy(col + ucMaxLength,row,ALL_BYTE);

     pData[0] = 0x00;
     pData[1] = ucPixLen;
     //pData[2] = ucBlankColor;
     CScalerWrite(_OSD_DATA_PORT_92, 2, pData, _NON_AUTOINC);
}
//---------------------------------------------------------------------------


void CSetMuteState(void)
{
    if (GET_AUDIO_MUTE()) // Mute on 
        CLR_AUDIO_MUTE();
    else
        SET_AUDIO_MUTE();

    CDrawMuteState();

#if(_VIDEO_TV_SUPPORT)
 #if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
    if ((_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && gmi_CModeLocked()) || _GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
 #endif
#endif

       CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
}

//-----------------------------------------------------------------------
void CDrawMuteState(void)
{           
    ucOsdState     = _MI_MENU_NONE;
#if(_VIDEO_TV_SUPPORT)
        bChangeChannel = 0;
#endif
    COsdFxDisableOsd();
    //SetOSDDouble(0x03);
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);
    SetOsdMap(tMsgOsdMap);
                         
    // Init OSD Ram
    OSDClear(0, 8, 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, 8, 0, 30, 0x00, BYTE_DISPLAY);
    OSDClear(0, 8, 0, 30, 0xF0, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow); 
 

    OSDPosition(6 * 12-39, 4 * 18, 10, 0, 0x03);
    if (GET_AUDIO_MUTE()) // Mute on 
       COsdLoad1BitFont(FntMute, 0x7A, 6, tFntVolumeCharWidth);
    else
       COsdLoad1BitFont(FntVolume, 0x7A, 6, tFntVolumeCharWidth);  
                                              
    // Display Volume/Mute icon
    Gotoxy(0, 1, BYTE_DISPLAY);
    OutputChar(0x7A);
    OutputChar(0x7B);
    OutputChar(0x7C);
    Gotoxy(0, 2, BYTE_DISPLAY);
    OutputChar(0x7D);
    OutputChar(0x7E);
    OutputChar(0x7F);
    COsdFxDrawWindow(0,16,                               //WORD usXStart,WORD usYStart,  
                        54,52,       //WORD usXEnd,WORD usYEnd,  
                        tMainWindowStyle);                  //BYTE *pStyle)

    COsdFxEnableOsd();
    bOSDTimeOut  = 0;
 //   ucAudioState = 1;
    if (GET_AUDIO_MUTE()) // Mute on  
    {
       	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
    }
    else             
    {
       CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    } 

    bOSDTimeOut  = 0;
    bOSDOnScreen = 1;
}

//-----------------------------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
#if(_SHOW_TV_NO_SIGNAL)
#define _H_POS_MAX         ((DWORD)((Panel[ucPanelSelect]->DHWidth - _DIALOG_WIDTH)/4 - 12))
#define _V_POS_MAX         ((DWORD)((Panel[ucPanelSelect]->DVHeight - _DIALOG_HEIGHT)/4 - 6))
#define _H_DOUBLE_POS_MAX  ((DWORD)((Panel[ucPanelSelect]->DHWidth - _OSD_DOUBLE_WIDTH(_DIALOG_WIDTH))/4 - 12))
#define _V_DOUBLE_POS_MAX  ((DWORD)((Panel[ucPanelSelect]->DVHeight - _OSD_DOUBLE_HEIGHT(_DIALOG_HEIGHT))/4 - 6))

void OSDMove(WORD usOsdActWidth, WORD usOsdActHeight, WORD ucHPos, WORD ucVPos, BYTE ucPar)
{              
    usOsdActWidth  = _OSD_HPOSITION_OFFSET + 
                    (DWORD)(Panel[ucPanelSelect]->DHStartPos / 4) + ucHPos;

    usOsdActHeight = _OSD_VPOSITION_OFFSET + 
                    (DWORD)(Panel[ucPanelSelect]->DVStartPos / 4) + ucVPos;


    CScalerSetBit(_OSD_SCRAMBLE_93, 0xf8, 0x02);

    pData[0] = CScalerGetBit(_OVERLAY_CTRL_6C, _BIT0);

    pData[0] = (pData[0] == 0x00) ? 0xc0 : 0xe0;
    pData[1] = 0x00;
    CScalerWrite(_OSD_ADDR_MSB_90, 2, pData, _AUTOINC);

	pData[0] = usOsdActHeight >> 1;
	pData[1] = (UINT8) (usOsdActWidth >> 2);
	pData[2] = ((UINT8) (usOsdActWidth & 0x0003) << 6) |	((usOsdActHeight & 0x01) << 5) | ucPar;
	CScalerWrite(_OSD_DATA_PORT_92, 3, pData, _NON_AUTOINC);
 
    CTimerWaitForEvent(_EVENT_DEN_STOP);
    CTimerWaitForEvent(_EVENT_DEN_STOP);
    CScalerSetBit(_OSD_SCRAMBLE_93, 0xf8, 0x05);
}
//---------------------------------------------------------------------------
void DispIcon(BYTE x, BYTE y, BYTE ucIconBaseAddr)
{
    Gotoxy(x,y,BYTE_DISPLAY);
    
    pData[0] = ucIconBaseAddr;
    pData[1] = ucIconBaseAddr + 1;
    pData[2] = ucIconBaseAddr + 2;
    CScalerWrite(_OSD_DATA_PORT_92,3,pData,_NON_AUTOINC);
    
    Gotoxy(x,y + 1,BYTE_DISPLAY);
    pData[0] = ucIconBaseAddr + 3;
    pData[1] = ucIconBaseAddr + 4;
    pData[2] = ucIconBaseAddr + 5;
    CScalerWrite(_OSD_DATA_PORT_92,3,pData,_NON_AUTOINC);
}
//-----------------------------------------------------------------------
#define _ON_SCREEN_STATE    1
#define _MOVE_STATE         2
void CCheckTVSignal(void)
{
    static WORD ucPosX  = 0;
    static WORD ucPosY  = 0;
    static BYTE ucCount = 0;
    static BYTE ucDir   = 0;

    ucCount++;
    if (ucCount > 50)
        ucCount = 0;
    else
        return;

    if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV || bOSDOnScreen == 1 || ucOsdState != _MI_MENU_NONE)
        return;

    if (bTVNoSignal)
    {         
        switch(ucSignalOSDState)
        {
        case 0:
            LoadCHIFont(_LF_OTHER);
            CShowNoSignal();
            CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
            ucSignalOSDState = _ON_SCREEN_STATE;
            break;

        case _ON_SCREEN_STATE:
            if (GET_OSD_SIZE())
            {
                ucPosX = _H_DOUBLE_POS_MAX/2;
                ucPosY = _V_DOUBLE_POS_MAX/2;
            }
            else
            {
                ucPosX = _H_POS_MAX/2;
                ucPosY = _V_POS_MAX/2;
            }
            ucDir  = _BIT1;
            ucDir  |= _BIT5;
            ucSignalOSDState = _MOVE_STATE;
            break;

        case _MOVE_STATE:
            if (GET_OSD_SIZE())
            {
                if (ucPosX >= _H_DOUBLE_POS_MAX)   ucDir = (ucDir & 0xf0) | _BIT0; // --
                if (ucPosY >= _V_DOUBLE_POS_MAX)   ucDir = (ucDir & 0x0f) | _BIT4; // --
            }
            else
            {
                if (ucPosX >= _H_POS_MAX)   ucDir = (ucDir & 0xf0) | _BIT0; // --
                if (ucPosY >= _V_POS_MAX)   ucDir = (ucDir & 0x0f) | _BIT4; // --
            }
            if (ucPosX == 0)            ucDir = (ucDir & 0xf0) | _BIT1; // ++           
            if (ucPosY == 0)            ucDir = (ucDir & 0x0f) | _BIT5; // ++
            
            if (ucDir & _BIT0)          ucPosX--;
            if (ucDir & _BIT1)          ucPosX++;
            if (ucPosY < 2)             ucPosY = 2;
            if (ucDir & _BIT4)          ucPosY-=2;
            if (ucDir & _BIT5)          ucPosY+=2;

            if (GET_OSD_SIZE())
                OSDMove(_OSD_DOUBLE_WIDTH(_DIALOG_WIDTH), _OSD_DOUBLE_HEIGHT(_DIALOG_HEIGHT), ucPosX, ucPosY, 0x03);
            else
                OSDMove(_DIALOG_WIDTH, _DIALOG_HEIGHT, ucPosX, ucPosY, 0x03);
	        break;
        }
    }
    else
    {
        if (ucSignalOSDState)
            COsdFxDisableOsd();
    }
}
#endif // #if(_SHOW_TV_NO_SIGNAL)
#endif // #if(_VIDEO_TV_SUPPORT)

//$$ Added by AndyLiu20080619
/*
#if(_LOGO_ENABLE)
BYTE code tLogoOsdMap[] =
{ 
    10,         // Row Count
    LOBYTE(0x300),HIBYTE(0x300),
	36,   // Row 1 char count
	36,   // Row 2 char count
	36,   // Row 3 char count
	36,   // Row 4 char count
	36,   // Row 5 char count
	36,   // Row 6 char count
	36,   // Row 7 char count
	36,   // Row 8 char count
	36,   // Row 9 char count
	36,   // Row 10 char count

};
//----------------------------------------------------------------
BYTE code tLogo[] =
{
    
  
//Charcter command Byte 1
  0x50,0x0B,   //Row : 0
  0x00,0x01,0x02,0x00,_bb_,33,_nn_,   // 1_02_0                                 
  0x50,0x2F,   //Row : 1
  0x00,0x03,0x04,0x05,0x00,0x06,0x07,0x79,0x08,0x00,_bb_,27,_nn_,   // 1_12_13_1 5_16_1NONE8_1                           
  0x50,0x53,   //Row : 2
  0x00,0x00,0x09,0x0A,0x00,0x00,0x0B,0x79,0x08,0x00,_bb_,27,_nn_,   //  2_23_2  6_2NONE8_1                           
  0x50,0x77,   //Row : 3
  0x00,_bb_,6,0x0B,0x79,0x08,0x00,_bb_,27,_nn_,   //      6_2NONE8_1                           
  0x50,0x9B,   //Row : 4
  0x0C,0x0D,0x0E,0x0F,0x00,0x00,0x0B,0x79,0x08,0x10,0x11,0x12,0x13,0x14,0x15,0x00,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x00,0x00,_nn_,   //0_41_42_43_4  6_2NONE8_19_410_411_412_413_414_4 16_417_418_419_420_421_422_423_424_424_426_427_428_429_430_431_432_433_4  
  0x50,0xBF,   //Row : 5
  0x00,0x00,0x27,0x28,0x00,0x00,0x0B,0x79,0x08,0x29,0x2A,0x2B,0x2C,0x00,0x00,0x00,0x2D,0x2E,0x2F,0x00,0x00,0x30,0x31,0x00,_bb_,4,0x79,0x32,0x33,0x00,0x34,0x35,0x36,0x00,0x00,_nn_,   //  2_53_5  6_2NONE8_19_510_511_512_5   16_517_518_5  21_522_5    NONE28_529_5 31_532_533_5  
  0x50,0xE3,   //Row : 6
  0x00,0x00,0x37,0x28,0x00,0x00,0x0B,0x79,0x38,0x39,0x3A,0x3B,0x00,_bb_,4,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x00,_bb_,4,0x79,0x43,0x00,0x00,0x00,0x44,0x45,0x00,0x00,_nn_,   //  2_63_5  6_2NONE8_69_610_611_6    16_617_618_619_620_621_622_6    NONE28_6   32_633_6  
  0x51,0x07,   //Row : 7
  0x00,0x00,0x37,0x28,0x00,0x00,0x0B,0x79,0x46,0x47,0x48,0x49,0x4A,0x00,0x00,0x00,0x4B,0x4C,0x4D,0x4E,0x00,0x4F,0x42,0x00,_bb_,4,0x79,0x50,0x00,0x00,0x00,0x44,0x79,0x00,0x00,_nn_,   //  2_63_5  6_2NONE8_79_710_711_712_7   16_717_718_719_7 21_722_6    NONE28_7   32_6NONE  
  0x51,0x2B,   //Row : 8
  0x00,0x00,0x37,0x28,0x00,0x00,0x0B,0x79,0x08,0x00,0x51,0x52,0x53,0x54,0x00,0x00,0x55,0x56,0x00,0x00,0x57,0x58,0x59,0x00,_bb_,4,0x79,0x5A,0x00,0x00,0x00,0x44,0x79,0x00,0x00,_nn_,   //  2_63_5  6_2NONE8_1 10_811_812_813_8  16_817_8  20_821_822_8    NONE28_8   32_6NONE  
  0x51,0x4F,   //Row : 9
  0x5B,0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x62,0x67,0x68,0x60,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x5B,0x72,0x62,0x73,0x74,0x00,0x75,0x76,0x62,0x77,0x78,_nn_,   //0_91_92_93_94_95_96_97_98_99_910_911_97_913_914_95_916_917_918_919_920_921_922_923_924_90_926_97_928_929_9 31_932_97_934_935_9
  0x51,0x73,   //Row : 21
  0x00,_bb_,52,   //                                                    
  _end_,
  

};
//----------------------------------------------------------------
void CDrawLogo(BYTE ucDouble)
{
//    BYTE x;
//    BYTE y;
    BYTE ucFont = 0x00;
	
	COsdFxDisableOsd();	
    CAdjustBackgroundColor(0x00,0x00,0xff);

    SetOsdMap(tLogoOsdMap);
    COsdColorPalette(tPALETTE_0);
    COsdFxCodeWrite(ucCloseAllWindow);
    COsdLoad1BitFontWidth12(FntLogo, 0x00, 0x80);

	CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((0x00) << 2));
    
    // Init osd
    // insert code to here
    OSDClear(ROW(0), HEIGHT(10), COL(0), WIDTH(36), 0x8C, BYTE_ATTRIB);
    OSDClear(ROW(0), HEIGHT(10), COL(0), WIDTH(36), 0x80, BYTE_COLOR);
	
    OSDPosition(_LOGO_WIDTH, _LOGO_HEIGHT, 45, 54, 0x03);

	COsdFxCodeWrite(tLogo);

	COsdFxEnableOsd();
    CPowerPanelOn();

    CTimerCancelTimerEvent(COsdDispOsdTimerEvent); //andy 080604
    //CPowerLightPowerOn();
    //CTimerDelayXms(100);
//    CTimerDelayXms(1000);
//    CTimerDelayXms(1000);
//    CTimerDelayXms(1000);
//    CTimerDelayXms(1000);
}
//-------------------------------------------------------------------------------------------------------------

void CPattenChange(void)
{
	BYTE ucPatten[9];
    BYTE ucTemp;

    // 0x0A
    ucPatten[0] = tPALETTE_0[30];//0x33;
    ucPatten[1] = tPALETTE_0[31];//0x6A;
    ucPatten[2] = tPALETTE_0[32];//0xA5;
    // 0x0B
    ucPatten[3] = tPALETTE_0[33];//0x94;
    ucPatten[4] = tPALETTE_0[34];//0xBD;
    ucPatten[5] = tPALETTE_0[35];//0x35;
    // 0x0C
    ucPatten[6] = tPALETTE_0[36];//0xF3;
    ucPatten[7] = tPALETTE_0[37];//0x94;
    ucPatten[8] = tPALETTE_0[38];//0x28;

    for(ucTemp = 0; ucTemp < 9; ucTemp++)
    {
        ucPatten[ucTemp] -= 0x28;
    }

    while(ucPatten[6] != 0xFF)
    {
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x80 | 0x1E);
    	CScalerWrite(_COLOR_LUT_PORT_6F, 3, &ucPatten, _NON_AUTOINC);
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x00);
        CTimerDelayXms(30);

        for(ucTemp = 0; ucTemp < 9; ucTemp++)
        {
            ucPatten[ucTemp]++;
        }
    }

    while(ucPatten[8])
    {
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x80 | 0x1E);
    	CScalerWrite(_COLOR_LUT_PORT_6F, 3, &ucPatten, _NON_AUTOINC);
    	CScalerSetByte(_OVERLAY_LUT_ADDR_6E, 0x00);
        CTimerDelayXms(30);

        for(ucTemp = 0; ucTemp < 9; ucTemp++)
        {
            ucPatten[ucTemp]--;
        }
    }
}

#endif
*/
//$$ Added by AndyLiu20080619

//----------------------------------------------------------------------------------------------------
void CNotUse(void)
{
     CChangeSourceAvSv();


	CAdjustMZHueSat(0);
	CEepromSaveHueSatData();
	CKeyScanReadyTimerEvent();
	CKeyRepeatEnableTimerEvent();
	CAutoDoAutoConfig();

	CAutoDoWhiteBalance();
	CVdcIsLocked();
	CEepromSaveOsdUserData();
	CEepromSaveBriConData();
	CEepromSaveColorTempData();
	CEepromSaveTvData();
	CScalerWriteAmount(0,0,0,0);

	SetOsdMap(0);
	SetOSDRamAddress();
	DirectWOSDRam(0, 0, 0, 0);
	SetRowCmds();
	Gotoxy(0, 0, 0);
	OutputChar(0);

	COsdFxCloseWindow(0);
	ValueInRangeChange(0, 0, 0, 0);
	Textout(0);
	StrLen(0);
	OSDPosition(0, 0, 0, 0, 0);
	OSDClear(0, 0, 0, 0, 0,0);
	COsdFxCodeWrite(0);
	COsdFxEnableOsd();
	COsdFxDisableOsd();
	COsdFxDrawWindow(0, 0, 0, 0, 0);
	COsdFxGetAdcClockRange(0);
	InitBurnIn();
	BurnInRun();
    CKeyScanReady();
    ChangeSourceHandler();

    CSetPWM(0, 0);
    CTextOutRightAlign(0,0,0);
    //OSDSlider(0, 0, 0, 0, 0,0);


	COsdCtrlGetHPosition();
	COsdCtrlGetVPosition();
	COsdCtrlGetClock();
	COsdCtrlGetPhase();
    GetNextLanguage(0);
	GetPrevLanguage(0);
    //CDoReset();

    AdjustMenuItem(0,0,0);

	CEnable();
	CVideoEnable();
	CVgaEnable();
	CHDMIEnable();
	CDviEnable();
	CTVEnable();
   
    Draw2bit3x2Icon(0,0,0);
    
#if(_VIDEO_TV_SUPPORT)
	CSaveChannelSkip(0,0);
	CSaveChannelColorType(0,0);
	CChangeChannel(0);
	CTuningCurrentChannel(0,0);
	CTvAutoSearch();
	CManualSearch(0,0);

    #if(_FM_DEVICE)
        CChangeFM();
    #endif
        CShowTimer();
        CSaveChannelSoundType(stTvInfo.CurChn, 0);
        CSaveChannelSoundType(stTvInfo.CurChn, 0);
#endif

    CCenterTextout(0,ROW(1),COL(0),0);
    //COsdLoad1BitFont(0, 0x00, 123, 0);
	CYPbPrPorch_LevelCheck();



	//CShowNumber(0,0,0);
    MMenuNoneEnterSubMenu();
    Exit001Menu();
    DrawSourceMenu();
	CShortCutBright();
	Draw001MainMenu();
    DispIcon(0,0,0);
}
//--------------------------------------------------

#endif			//#if(_OSD_TYPE == _OSD003)
