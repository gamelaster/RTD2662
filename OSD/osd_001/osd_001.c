#include "Core\Header\Include.h"

#if(_001_OSD)
//-----------------------------------------------------------
void Clear(void)
{
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x00, BYTE_DISPLAY);

    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x8c, BYTE_ATTRIB);
   
    OSDClear(0, 1, 0, COL_WIDTH, 0xf0, BYTE_COLOR);
    //OSDClear(4, 11, 0, COL_WIDTH, 0x00,BYTE_COLOR);
    OSDClear(1,0,2,COL_WIDTH,0xe0,BYTE_COLOR);

}

//---------------------------------------------------------------------------
void Draw001Menu(void)
{
    InitOsdFrame();
    //COsdFxDisableOsd();
    SetOSDDouble(0);
    COsdFxCodeWrite(ucCloseAllWindow);

    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x00, BYTE_DISPLAY);
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x8c, BYTE_ATTRIB);
    
    OSDClear(0,1,0,COL_WIDTH,0xf0,BYTE_COLOR);
    
    OSDClear(1,0,2,COL_WIDTH,0xe0,BYTE_COLOR);
    
    OSDPosition(348,72,100,90,0x01);

    ucOsdState = _MI_001_CONTRAST;
    CCenterTextout(sContrast[GET_LANGUAGE()], ROW(0), 0, 28);
    OSDSlider1(ROW(2), 3, 16, stConBriData.Contrast, 100,0xe0);
    
    COsdFxDrawWindow(XSTART(0), YSTART(0), XEND(348), YEND(72), tOSD_WINDOW0_STYLE);


    OSDPosition(70,20,39,85,0x03);

	COsdFxEnableOsd();
	//CTimerReactiveTimerEvent(SEC(15), COsdFxDisableOsd);

	while(0)
    {
		CGetADCValue(&pData[3]);
		Gotoxy(5, 10, BYTE_DISPLAY);
		CShowNumber(2,2,pData[3]);
    }
}
//---------------------------------------------------------------------------

void Draw001MainMenu(void)
{
    COsdFxDisableOsd();
    COsdFxCodeWrite(ucCloseAllWindow);
    
    OSDClear(0, 15, 0 , 30, 0x00, BYTE_DISPLAY);  
    OSDClear(0, 15, 0 , 30, 0x8c, BYTE_ATTRIB);
    OSDClear(0, 15, 0,  30, 0x10, BYTE_COLOR);
    COsdFxDrawWindow(XSTART(0), YSTART(0), XEND(348), YEND(72), tOSD_WINDOW0_STYLE);

    OSDPosition(70,20,39,85,0x03);

	COsdFxEnableOsd();
	bOSDTimeOut = 0;

}

//---------------------------------------------------------------------------
void M001MenuAdj(BYTE ucMode)
{   
    BYTE ucNewItem = AdjustMenuItem(_MI_001_CONTRAST,_MI_001_EXIT,ucMode);

    if(ucNewItem == ucOsdState)
    {
    	return;
    }

    // 1. Clear Current Menu
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x00, BYTE_DISPLAY);
    OSDClear(0, ROW_COUNT, 0 , COL_WIDTH, 0x8c, BYTE_ATTRIB);
       
    OSDClear(0, 1, 0, COL_WIDTH, 0xf0, BYTE_COLOR);
    OSDClear(1,0,2,COL_WIDTH,0xe0,BYTE_COLOR);

    //OSDClear(4, 11, 0, COL_WIDTH, 0x00,BYTE_COLOR);

    if(ucNewItem == _MI_001_EXIT)
    {
    	ucOsdState = _MI_MENU_NONE;
    	COsdFxDisableOsd();
    	return;
    }

    // 2. Change ucOsdState
    ucOsdState = ucNewItem;
    
    // 3. Draw New Item
    Draw001MenuItem(ucOsdState,_ST_SELECT);   
}

//---------------------------------------------------------------------------
void M001ValueAdj(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    switch(ucOsdState)
    {
	    case _MI_001_CONTRAST:  			Adjust001Contrast(ucMode);    			break;
	    case _MI_001_BRIGHTNESS:    		Adjust001Brightness(ucMode);         	break;  
		case _MI_001_HUE:  	    			Adjust001Hue(ucMode);  					break;
	    case _MI_001_SATURATION:  			Adjust001Saturation(ucMode);    		break;         
	    case _MI_001_AV1_AV2:     			Adjust001Source(ucMode);          		break;
	    case _MI_001_LEFT_RIGHT:			Adjust001LeftRight(ucMode);				break;
	    case _MI_001_UP_DOWN:				Adjust001UpDown(ucMode);				break;
	    case _MI_001_DISPLAY_RATIO:			Adjust001DisplayRatio(ucMode);			break;
	    case _MI_001_RESET:    				ResetAdjustLeftRight(1);       			break;
	    case _MI_001_EXIT:                  Exit001Menu();							break;
    }
}
//---------------------------------------------------------------------------
void M001Proc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_ADJ_INC:  				M001ValueAdj(_INC);   					break;        
        case _OE_ADJ_DEC:   		 	M001ValueAdj(_DEC);      				break;    
        case _OE_RETURN_UPMENU: 		M001MenuAdj(_NEXT);  					break;
        case _OE_ENTER_RESET:           ResetMenuProc();                        break;
    }    
}
//------------------------------------------------------------------------------

void ResetItemProc()
{
    switch(ucKeyMessage)
    {
	    case _OE_ENTER_SUBMENU:        	ResetMenuProc();       					break;
	    case _OE_ADJ_INC:        		ResetAdjustLeftRight(1);       			break;
	    case _OE_ADJ_DEC:       		ResetAdjustLeftRight(0);       			break;
	    default:                 												break; 
    }
}
//------------------------------------------------------------------------------

void ResetAdjustLeftRight(BYTE LR)
{
     LR = 1;
	if(_GET_RESET_SELECT_STATE() == _RESET_SELECT_STATE)
	{
		Gotoxy(14,2,BYTE_DISPLAY);
		OutputChar(0x56);

		Gotoxy(4,2,BYTE_DISPLAY);
		OutputChar(0x00);

		_SET_RESET_SELECT_STATE(_RESET_NO_STATE);
	}
	else 
	{
		Gotoxy(14,2,BYTE_DISPLAY);
		OutputChar(0x00);

		Gotoxy(4,2,BYTE_DISPLAY);
		OutputChar(0x56);

		_SET_RESET_SELECT_STATE(_RESET_SELECT_STATE);

	}   

}
//------------------------------------------------------------------------------

void ResetMenuProc(void)
{

    if(_GET_RESET_SELECT_STATE() == _RESET_SELECT_STATE)
    {
	    if(_GET_RESET_SELECT_STATE() == _RESET_SELECT_STATE)
	    {
	    	CDoReset();
	    }
    }
    
    CLR_KEYREPEATENABLE();
    COsdFxDisableOsd();
    ucOsdState = _MI_MENU_NONE;

    //CTimerDelayXms(500);

}
//------------------------------------------------------------------------------

void DrawContrastMenu(void)
{
	Clear();  
	CCenterTextout(sContrast[GET_LANGUAGE()], ROW(0), 0, 28);
	OSDSlider1(ROW(2), 3, 16, GET_CONTRAST(), 100,0xe0);
}
//------------------------------------------------------------------------------

void DrawBrightnessMenu(void)
{
	Clear(); 
	CCenterTextout(sBrightness[GET_LANGUAGE()], ROW(0), 0, 28);
	OSDSlider1(ROW(2), 3, 16, stConBriData.Brightness, 100,0xe0);
}

//------------------------------------------------------------------------------
void DrawSaturationMenu(void)
{
	Clear();
	CCenterTextout(sSaturation[GET_LANGUAGE()], ROW(0), 0, 28);
	OSDSlider1(ROW(2), 3, 16, GET_SATURATION(), 100,0xe0);
}
//------------------------------------------------------------------------------

void DrawHueMenu(void)
{
	Clear();
	CCenterTextout(sHue[GET_LANGUAGE()], ROW(0), 0, 25);
	OSDSlider1(ROW(2), 3, 16, GET_HUE(), 100,0xe0);
}


//------------------------------------------------------------------------------
void DrawSourceA1A2Menu(void)
{
    Clear();
    CCenterTextout(sSource, ROW(0), 0, 27);
    CTextOutEx(sAV,COL(6),ROW(2));
    CTextOutEx(sSVideo,COL(18),ROW(2));
    if(stSystemData.InputSource == _SOURCE_VIDEO_AV)
	{


	    //Gotoxy(8,2,BYTE_DISPLAY);         
		//OutputChar(0x00);
		Gotoxy(4,2,BYTE_DISPLAY);
		OutputChar(0x56);

	}
	else if(stSystemData.InputSource == _SOURCE_VIDEO_SV)
	{
	    //Gotoxy(4,2,BYTE_DISPLAY);
		//OutputChar(0x56);
		Gotoxy(15,2,BYTE_DISPLAY);
		//OutputChar(0x00);
        OutputChar(0x56);
	}
}
//------------------------------------------------------------------------------
void DrawLeftRightChangeMenu()
{
    Clear();
    CCenterTextout(sLeftRight, ROW(0), 0, 27);
	CTextOutEx(sLeft,COL(6),ROW(2));
	CTextOutEx(sRight,COL(16),ROW(2));
    if(bLR)
    {
		Gotoxy(4,2,BYTE_DISPLAY);
		OutputChar(0x56);
    }
    else
    {
		Gotoxy(15,2,BYTE_DISPLAY);
        OutputChar(0x56);
    }
}
//------------------------------------------------------------------------------
void DrawUpDownChangeMenu()
{
    Clear();
    CCenterTextout(sUpDown, ROW(0), 0, 27);
	CTextOutEx(sUp,COL(6),ROW(2));
	CTextOutEx(sDown,COL(16),ROW(2));
    if(bUD)
    {
		Gotoxy(4,2,BYTE_DISPLAY);
		OutputChar(0x56);
    }
    else
    {
		Gotoxy(15,2,BYTE_DISPLAY);
        OutputChar(0x56);
    }
}
//------------------------------------------------------------------------------
void DrawDisplayRadioMenu()
{
    Clear();
    CCenterTextout(sDisplayRatio[GET_LANGUAGE()], ROW(0), 0, 27);
	CTextOutEx(s16_9,COL(6),ROW(2));
	CTextOutEx(s4_3,COL(16),ROW(2));
    if(GET_DISPLAYMODE() == _DISPMODE_FULL)
    {
		Gotoxy(4,2,BYTE_DISPLAY);
		OutputChar(0x56);
    }
    else
    {
		Gotoxy(15,2,BYTE_DISPLAY);
        OutputChar(0x56);
    }

}
//------------------------------------------------------------------------------

/*
void DrawVolumeMenu(void)
{
    Clear();
   	CCenterTextout(sVolume[GET_LANGUAGE()], ROW(1), 0, 23);
	OSDSlider1(ROW(2), 3, 16, GET_VOLUME(), 100,0xe0);

}
*/
//------------------------------------------------------------------------------
void DrawResetMenu(void)
{
    Clear();   
    CCenterTextout(sReset[GET_LANGUAGE()], ROW(0), 0, 25);
    CTextOutEx(sYes,COL(6),ROW(2));
    CTextOutEx(sNo,COL(16),ROW(2));

    Gotoxy(14,2,BYTE_DISPLAY);
    OutputChar(0x56);
}
//------------------------------------------------------------------------------

void DrawExitMenu(void)
{
	Clear();
	CCenterTextout(sExit[GET_LANGUAGE()], ROW(0), 0, 25);
}
//------------------------------------------------------------------------------
void Draw001MenuItem(BYTE ucItem,BYTE ucState)
{
    ucState = ucState;
    // draw menu item     
    switch(ucItem)
    {
    case _MI_001_BRIGHTNESS: 				DrawBrightnessMenu();				break;
    case _MI_001_CONTRAST: 					DrawContrastMenu();					break;
    case _MI_001_HUE: 						DrawHueMenu();         				break;
    case _MI_001_SATURATION: 				DrawSaturationMenu();				break;
    case _MI_001_AV1_AV2: 					DrawSourceA1A2Menu();				break;
    case _MI_001_LEFT_RIGHT:				DrawLeftRightChangeMenu();			break;
    case _MI_001_UP_DOWN:					DrawUpDownChangeMenu();				break;
    case _MI_001_DISPLAY_RATIO:				DrawDisplayRadioMenu();				break;
    case _MI_001_RESET: 					DrawResetMenu(); 					break;
    case _MI_001_EXIT:						DrawExitMenu();						break;
    }
} 
//------------------------------------------------------------------------------
void Adjust001Contrast(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stConBriData.Contrast = ValueInRangeChange(0, 100, stConBriData.Contrast, _NON_LOOP | ucMode);
    CAdjustContrast();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
    OSDSlider1(ROW(2), 3, 16, stConBriData.Contrast, 100,0xe0);
}
//------------------------------------------------------------------------------
void Adjust001Brightness(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stConBriData.Brightness = ValueInRangeChange(0, 100, stConBriData.Brightness, _NON_LOOP | ucMode);
    CAdjustBrightness();
    ucOsdEventMsg = _SAVE_EE_COLORPROC0_MSG;
    OSDSlider1(ROW(2), 3, 16, stConBriData.Brightness, 100,0xe0);

}
//------------------------------------------------------------------------------
void Adjust001Hue(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stHueSatData.Hue = ValueInRangeChange(0, 100, stHueSatData.Hue, _NON_LOOP | ucMode);

    if(bSourceVideo())
    {
        gmi_CAdjustVDCHue(GET_HUE());
    }
    else
    {
        CAdjustYpbprhue(GET_HUE());
    }
    ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;   

    OSDSlider1(ROW(2), 3, 16, GET_HUE(), 100,0xe0);
}
//------------------------------------------------------------------------------
void Adjust001Saturation(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stHueSatData.Saturation = ValueInRangeChange(0, 100, stHueSatData.Saturation, _NON_LOOP | ucMode);

    if(bSourceVideo())
    {
        CVideoSetSaturation(GET_SATURATION());
    }
    else
    {
        CAdjustYpbprSaturation(GET_SATURATION());
    }

    ucOsdEventMsg = _SAVE_EE_HUE_SAT_DATA_MSG;
    OSDSlider1(ROW(2), 3, 16, GET_SATURATION(), 100,0xe0);
}


void Adjust001Source(BYTE ucMode)
{   
    // ucMode : _INC or _DEC
	ucMode = ucMode;
    CChangeSourceAvSv();
}
//------------------------------------------------------------------------------
void Adjust001LeftRight(ucMode)
{
	ucMode = ucMode;
	if(GET_SCREEN_LR())
	{	
		bLR = 0;
		SET_SCREEN_LR(0); 
	}
	else
	{
        bLR = 1;
		SET_SCREEN_LR(1); 
	}
	CEepromSaveSystemData();
	DrawLeftRightChangeMenu();
	
}
//------------------------------------------------------------------------------
void Adjust001UpDown(ucMode)
{
	ucMode = ucMode;
	if(GET_SCREEN_UD())
	{	
		bUD = 0;
		SET_SCREEN_UD(0);
	}
	else
	{
        bUD= 1;
		SET_SCREEN_UD(1);
	}
	CEepromSaveSystemData();
	DrawUpDownChangeMenu();

}
//------------------------------------------------------------------------------
void Adjust001DisplayRatio(ucMode)
{
	ucMode = ucMode ;
	switch(GET_DISPLAYMODE())
	{
	case _DISPMODE_FULL:
	    SET_DISPLAYMODE(_DISPMODE_43);
	    break;
	case _DISPMODE_43:
	    SET_DISPLAYMODE(_DISPMODE_FULL);
	    break;
	}
	//CLR_CLEAR_OSD_EN();
    COsdDispOsdTimerEvent();
	CEepromSaveSystemData();
	ucTVSyncFailCount = 250;
	CModeResetMode();
	DrawDisplayRadioMenu();
}
//------------------------------------------------------------------------------

void Exit001Menu(void)
{
	COsdDispOsdTimerEvent();
	bOSDTimeOut = 1;
}
//---------------------------------------------------------------------------
/*
void Adjust001Volume(BYTE ucMode)
{
    // ucMode : _INC or _DEC
    SET_KEYREPEATENABLE();
    stAudioData.Volume = ValueInRangeChange(0, 100, stAudioData.Volume, _NON_LOOP | ucMode);
    CSetVolume();
    ucOsdEventMsg = _SAVE_EE_AUDIO_DATA_MSG;
    
    OSDSlider1(ROW(2), 3, 16, stAudioData.Volume, 100,0xe0);
}
*/
//---------------------------------------------------------------------------
void OSDSlider1(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color)
{
    unsigned int bound;
    unsigned char i,c;
    OSDLine(row, col, length + 8, color, THE_BYTE2);   // Set Slider Attribute. 4 extra columns for space/numbers/space
    bound   = length * value;
    Gotoxy(col,row,THE_BYTE1);
    OutputChar(0x0f);
    OutputChar(0x04);          // Left Border
    
  //  OutputChar(0x21);          // Left Border
    for (i = 1; i <= length; i++)
    {
        if (bound)
        {
            if(bound >= range)
            {
                c       = 0x0B;
                bound   = bound - range;
            }
            else
            {
                color   = (bound << 4) / range;
                bound   = 0;
                if (4 > color)                    c = 0x06;
                else if (7 > color)               c = 0x07;
                else if (10 > color)              c = 0x08;
                else if (13 > color)              c = 0x09;
                else                              c = 0x0a;
            }
        }
        else
        {
            c = 0x05;
        }
        OutputChar(c);
    }
    OutputChar(0x0C);    // Right Border
    CShowNumber2(value, 0);    //值显示在右边
    OutputChar(0x0D);
    if (value < 100)
    OutputChar(0x00);

}
//----------------------------------------------------------- 
//  ucNumber:      0~65535
//  ucUserDefLong: 0   --> 自动计算ucNumber长度，有几位输出几位
//                 1~5 --> 输出1~5位，不足用0补
//  exp:           ucNumber = 12
//                 ucUserDefLong = 0    Output:  12
//                 ucUserDefLong = 3    Output:  012
//----------------------------------------------------------- 
void CShowNumber2(const WORD ucNumber, BYTE ucUserDefLong)
{
    BYTE uctemp[5];
    
    uctemp[4] = (ucNumber / 10000) % 10;
    uctemp[3] = (ucNumber / 1000) % 10;
    uctemp[2] = (ucNumber / 100) % 10;
    uctemp[1] = (ucNumber / 10) % 10;
    uctemp[0] = ucNumber  % 10;
    
    if (ucUserDefLong)
        ucUserDefLong -= 1;     
    else    
    {
        for(pData[15] = 4; pData[15]>0;pData[15]--)
        {
            if(uctemp[pData[15]] != 0)
                break;          
        }
        
        ucUserDefLong = pData[15];
    }
    
    CScalerSendAddr(_OSD_DATA_PORT_92 , _NON_AUTOINC);
    do
    {
        *(&MCU_SCA_INF_DATA_FFF5) = (uctemp[ucUserDefLong]+'0');
    }
    while(ucUserDefLong--);
} 
//---------------------------------------------------------------------------

#endif



