//----------------------------------------------------------------------------------------------------
// ID Code      : Video.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#define __VIDEO__

#include "Core\Header\Include.h"
//#include "Core\Header\Tv.h"

#if(_VIDEO_SUPPORT == _ON)

BYTE ucSearchCount = 0;

/**
 * CVideoInitial
 * initial video source
 * set saturation,hue,backlight,sharpness, only called by CVideoIsExist
 * @param <none>
 * @return {none}
 *
*/
//================================================================================================
/////////////////////////////////////////////////
void CVideoInitial(void)
{       
//    gmi_CI2CWriteIfPllDM(_TV_PAL_I, _TUNER_MUTE_OFF, _NORMAL_MODE);
//    gmi_CSetTuner(_ADDR_TUNER, 4300);
 //   CTimerDelayXms(200);
          

	CScalerSetBit(_SYNC_CTRL_49, ~(_BIT1 | _BIT0), _BIT0);		// Measure HS/VS source select Video8/Video16
	CScalerCodeW(VideoInit);
	CScalerCodeW(VideoAdcInit);

    gmi_CInitialVDC();
    CScalerPageSelect(_PAGE8); 
    CScalerSetBit(_P8_VIDEO_CTRL1_A1, ~_BIT0, 0x00);  
    CScalerSetBit(_P8_INOUT_CTRL_A4, ~(_BIT1|_BIT4|_BIT5), _BIT4|_BIT5); // Force Only 4:2:2 Format Output for 3580 !!  

    CInitInputSource();
    CVideoSoftReset();    
//	CVideoSelectInput(_GET_INPUT_SOURCE());
}


//--------------------------------------------------
void CVideoSetVDCConBriCustomer(void)
{
	CVideoSetContrast(GET_CONTRAST());
#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
	CVideoSetVDCBrightness(GET_VDC_OFFSET());
#else
	CVideoSetVDCBrightness(0x88);
#endif	
}

void CSetVideoParameter(void)
{
    switch (ucVideoType)
	{
		case ZNTSC:
			CScalerCodeW(RTD2610_NTSC_M_ini);
			break;

		case ZPAL_I:
			CScalerCodeW(RTD2610_PAL_I_ini);
			break;

		case ZPAL_M:
			CScalerCodeW(RTD2610_PAL_M_ini);
			break;

		case ZPAL_N:
			CScalerCodeW(RTD2610_PAL_CN_ini);
			break;

		case ZNTSC_443:
			CScalerCodeW(RTD2610_NTSC_443_ini);
			break;

		case ZSECAM:
			CScalerCodeW(RTD2610_SECAM_ini);
			break;

		case ZPAL_60:
			CScalerCodeW(RTD2610_PAL_60_ini);
			break;

		case ZNTSC_50:
			//CScalerCodeW(RTD2610_NTSC_50_ini);
			break;
	}
	if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_SV)
	{

		CScalerPageSelect(_PAGE8);		
		CScalerSetByte(_P8_YCSEP_CTRL_E0, 0x03); 	// YC Seperate Control:1D			
	}

	if((ucVideoType == ZSECAM )&&(_SOURCE_VIDEO_SV == _GET_INPUT_SOURCE()))
		CScalerSetBit(_P8_OUTPUT_CTRL_A7, 0xf0, 0x08);	//set bit0-3 as 0x8
	else
		CScalerSetBit(_P8_OUTPUT_CTRL_A7, 0xf0, 0x00);	//set bit0-3 as 0x0		
	if (ucVideoType == ZPAL_60)	// willy added for pal 60 only
		CScalerSetBit(_P9_VS_TC_E7, 0xbf, 0x40);	
	else
		CScalerSetBit(_P9_VS_TC_E7, 0xbf, 0x00);	
	if(ucVideoType == ZNTSC_50)
		CScalerSetBit(_P8_YCSEP_CTRL_E0, 0xF8, 0x03);		
}

//--------------------------------------------------
// Description  : Check if video signal is locked
// Input Value  : None
// Output Value : Return _TRUE if video signal is locked
//--------------------------------------------------
bit CVdcIsLocked(void)
{
	return gmi_CModeLocked();
}

//--------------------------------------------------
// Description  : Disable 2610 output
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoOutputDisable(void)
{

}

//--------------------------------------------------
// Description  : Eisable 2610 output
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoOutputEnable(void)
{
}

//--------------------------------------------------
// Description  : Soft Reset 2610
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoSoftReset(void)
{
	CScalerPageSelect(_PAGE8);
	CScalerSetByte(_P8_SOFT_RESET_CF, 0x01); 
	CTimerDelayXms(10);    
	CScalerSetByte(_P8_SOFT_RESET_CF, 0x00);

}


//--------------------------------------------------
// Description  : Set  2610 Saturation
// Input Value  : saturationNone
// Output Value : None
//--------------------------------------------------
void CVideoSetVDCSaturation(BYTE ucValue)
{	
	CScalerPageSelect(_PAGE8);
#if(1)

	CScalerSetByte(_P8_SATURATION1_AA, ucValue);	  

#else

	BYTE moderesult;
	WORD temp;
	
	CScalerRead(_P8_MODE_DET_STATUS_D3, 1, &moderesult, _NON_AUTOINC);
    CTimerDelayXms(20);
	moderesult &=0x07;	
	//for PAL sat/1.414
	temp =((WORD)(ucValue*100));	
	if(ucVideoType >= ZPAL_M &&  ucVideoType <= ZPAL_I)
	{		
		ucValue=(temp/141);
	}	
	CScalerSetByte(_P8_SATURATION1_AA,ucValue);	  

#endif
}

//--------------------------------------------------
// Description  : Set  2610 Contrast
// Input Value  : ucValue
// Output Value : None
//--------------------------------------------------
void CVideoSetVDCContrast(BYTE ucValue)
{
	CScalerPageSelect(_PAGE8);
	CScalerSetByte(_P8_CONTRAST1_A8,ucValue);	  
}

//--------------------------------------------------
// Description  : Set  2610 Brightness
// Input Value  : ucValue
// Output Value : None
//--------------------------------------------------
void CVideoSetVDCBrightness(BYTE ucValue)
{
	CScalerPageSelect(_PAGE8);
	CScalerSetByte(_P8_BRIGHTNESS1_A9,ucValue);	  
}

//--------------------------------------------------
#if(_VIDEO_TV_SUPPORT)
void CSetTvColor(BYTE ucColorMode)
{
	if(_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
       return;

    switch(ucColorMode)
    {
    case _TV_NTSC_M:
    case _TV_NTSC_4_BG:
    case _TV_NTSC_4_DK:
    case _TV_NTSC_4_I:
        ucColorMode = 0x00;
        break;

    case _TV_PAL_M:
        ucColorMode = 0x01;
        break;

    case _TV_PAL_BG:
    case _TV_PAL_I:
    case _TV_PAL_DK:
        ucColorMode = 0x06;
        break;

    case _TV_PAL_N:
        ucColorMode = 0x03;
        break;

    case _TV_SECAM_BG:
    case _TV_SECAM_DK:
    case _TV_SECAM_L:
    case _TV_SECAM_LL:
        ucColorMode = 0x07;
        break;
    }

    CScalerPageSelect(_PAGE8);   // TV disable auto mode
    CScalerSetByte(0xD2, ucColorMode); 
}
#endif // #if(_VIDEO_TV_SUPPORT)

//--------------------------------------------------
// Description  : Display video set color process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CSetVideoColor(void)
{
	// Setup color conversion
	CModeSetupColorConversion();//jerry20070605
    CEepromLoadColorTempData();
    CEepromLoadBriConData();
    CEepromLoadHueSatData();

    //adjust customer color mode
#if(_AdjustCustomerColorMode == _ENABLE)
	CAdjustCustomerColorMode();
#endif
    CAdjustContrast();
    CAdjustBrightness();
    CAdjustBacklight();
	CAdjustPeakingCoding();
	CVideoSetSaturation(GET_SATURATION());
	gmi_CAdjustVDCHue(GET_HUE());
	CVideoSetVDCConBriCustomer();
	stSystemData.Sharpness &= 0xF0;
	CAdjustSharpnessForScaleUp();

    CPowerADCAPLLOff();
    CVideoSetVDCBrightness(0x88);
    if (_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
        CVideoSetVDCContrast(0x5C);
    else
    CVideoSetVDCContrast(0x90);
	CAccAdjust(GET_DCC_MODE());  // set DCC mode

#if(_ICM_FUNC)
    // ICM on
	CScalerPageSelect(_PAGE7);
	CScalerSetByte(_P7_ICM_CTRL_D0, 0xdc);
	SET_ICM_SAT_R(12);
	CAdjustMZHueSat(0);
	SET_ICM_SAT_G(12);
	CAdjustMZHueSat(1);
    SET_ICM_SAT_B(12);
	CAdjustMZHueSat(2);
	SET_ICM_SAT_Y(8);
	CAdjustMZHueSat(3);
	SET_ICM_SAT_C(8);
	CAdjustMZHueSat(4);
#endif
}

/**
 * CVideoDisplaySet
 * Setup VGA display
 * set video display
 * @param <none>
 * @return {none}
 *
*/
/*
void SetDHToal(void)
{
	//BYTE ucDHTotalL;
	//CScalerSetByte(_DISP_ACCESS_PORT_2A, 0x01);
	//CScalerRead(_DISP_DATA_PORT_2B, 1, &ucDHTotalL, _NON_AUTOINC);
	//ucDHTotalL += 1;
	//CScalerSetByte(_DISP_ACCESS_PORT_2A, 0x01);
	//CScalerSetByte(_DISP_DATA_PORT_2B, ucDHTotalL);

	CScalerSetByte(_DISP_ACCESS_PORT_2A, 0x01);
	CScalerRead(_DISP_DATA_PORT_2B, 1, &pData[1], _NON_AUTOINC);
	pData[0] = 0x01;
	pData[1] = pData[1] + 1;
	CScalerWrite(_DISP_ACCESS_PORT_2A, 2, pData, _AUTOINC); 

}*/
//--------------------------------------------------
// Description  : Display video set process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoDisplaySet(void)
{
	BYTE field;//, temp;                         
    BYTE ucScale = 0;
    WORD iDHTotal;
	WORD ustemp;
         
  //  CPowerLightPowerOff();        
    CVideoOutputEnable();
    CScalerCodeW(tVIDEO_TABLE_SET_SCALER);
	CScalerSetByte(_IPH_ACT_WID_H_16, 0x8A);//double clk input & Swap V8/V6-C-port MSB to LSB sequence into LSB to MSB
    CSetVideoParameter();
	CVideoSoftReset();

	if(CTimerPollingEventProc(60, CMiscModeMeasurePollingEvent))
		CModeMeasureData();
		
#if(_VIDEO_TV_SUPPORT)
    if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV)
    {
        // No signal show snow noise
        CScalerPageSelect(_PAGE8);      
        CScalerSetBit(_P8_OUTPUT_CTRL_A7, ~(_BIT4|_BIT5), 0x80);

        CScalerPageSelect(_PAGE9);      
        CScalerSetByte(_P9_C_LOCK_CONF_B6, (ucVideoType == ZSECAM) ? 0xFB : 0x6B);

        CSetTvColor(ucTVType);

        // add for tv
        CScalerPageSelect(_PAGE8);  
        CScalerSetByte(0xE1, 0x65); 
        CScalerSetByte(0xE2, 0x00); 
    }
    else
#endif

    {
        CScalerPageSelect(_PAGE8);   // TV enable auto mode
        CScalerSetByte(0xD2, 0x80);  
    	CScalerPageSelect(_PAGE9);		
        CScalerSetByte(_P9_C_LOCK_CONF_B6, 0x6B);
    }
	//#endif
	
	  // 	ucAV_Mode_Curr = (ucMode_Curr_2610 > 0x04) ? 50 : 60; 
	if(ucVideoType > ZPAL_60)
    {
		field = _VIDEO_50HZ;
		
        iDHTotal = Panel[ucPanelSelect]->PalDHTotal;
      //  CTimerDelayXms(100);	//HLD1104
		
      //  CScalerSetByte(_DISP_ACCESS_PORT_2A,0x0f);//DOU
        //CScalerSetByte(_DISP_DATA_PORT_2B,0x25);
        
        //CScalerSetByte(_DISP_ACCESS_PORT_2A,0x11);
        //CScalerSetByte(_DISP_DATA_PORT_2B,0x2b);

        //CScalerSetByte(_DISP_ACCESS_PORT_2A,0x13);
        //CScalerSetByte(_DISP_DATA_PORT_2B,0xE9);

      //  CScalerSetByte(_DISP_ACCESS_PORT_2A,0x22);//DOU
        //CScalerSetByte(_DISP_DATA_PORT_2B,0xa4);
		
    }
	else
    {
		field = _VIDEO_60HZ;
		
        iDHTotal = Panel[ucPanelSelect]->NtscDHTotal;
/*
        CScalerSetByte(_DISP_ACCESS_PORT_2A,0x0f);
        CScalerSetByte(_DISP_DATA_PORT_2B,0x28);//0x2c
        CScalerSetByte(_DISP_ACCESS_PORT_2A,0x11);
        CScalerSetByte(_DISP_DATA_PORT_2B,0x28);//0x2c
        CScalerSetByte(_DISP_ACCESS_PORT_2A,0x13);
        CScalerSetByte(_DISP_DATA_PORT_2B,0xe9);//0x84
        CScalerSetByte(_DISP_ACCESS_PORT_2A,0x22);
        CScalerSetByte(_DISP_DATA_PORT_2B,0xa4);
*/		
    }
          
    stModeInfo.IHTotal      = tVIDEO_TABLE_INPUT_INFO[field][0];
    stModeInfo.IHStartPos   = tVIDEO_TABLE_INPUT_INFO[field][1];
    stModeInfo.IHWidth      = tVIDEO_TABLE_INPUT_INFO[field][2];
    stModeInfo.IVStartPos   = tVIDEO_TABLE_INPUT_INFO[field][3];
    stModeInfo.IVHeight     = tVIDEO_TABLE_INPUT_INFO[field][4];
    stModeInfo.IHFreq       = 157;    // For PAL and NTSC. We can use sync processor to measure the actual value.

    stDisplayInfo.DHWidth   = CCalcPanelWdith();//Panel[ucPanelSelect]->DHWidth;
    stDisplayInfo.DVHeight  = Panel[ucPanelSelect]->DVHeight;
    stDisplayInfo.DVStartPos = Panel[ucPanelSelect]->DVStartPos;
    stDisplayInfo.DHTotal   = iDHTotal;//Panel[ucPanelSelect]->DHTotal;

    // Get scaling information
    ucScale = 0;
    if(stModeInfo.IVHeight < stDisplayInfo.DVHeight)        ucScale |= _BIT0;    // bit 0 : V scale-up
    if(stModeInfo.IVHeight > stDisplayInfo.DVHeight)        ucScale |= _BIT1;    // bit 1 : V scale-down
    if(stModeInfo.IHWidth < stDisplayInfo.DHWidth)          ucScale |= _BIT2;    // bit 2 : H scale-up
    if(stModeInfo.IHWidth > stDisplayInfo.DHWidth)          ucScale |= _BIT3;    // bit 3 : H scale-down
                                                                             
  	ucHStartBias = 100;
    ucVStartBias = 0;
    ucVStartBias = CAdjustIVS2DVSDelay(ucScale);

    if(ucVStartBias > stModeInfo.IVStartPos)
       	ucVStartBias = stModeInfo.IVStartPos;

    //Set Capture Window
    ustemp = stModeInfo.IHStartPos + _CAPTURE_HDELAY - (ucHStartBias + _PROGRAM_HDELAY);

    CScalerSetBit(_IPH_ACT_STA_H_14, ~(_BIT2 | _BIT1 | _BIT0), HIBYTE(ustemp) & (_BIT2 | _BIT1 | _BIT0));
    CScalerSetByte(_IPH_ACT_STA_L_15, LOBYTE(ustemp));
    CScalerSetBit(_IPH_ACT_WID_H_16, ~(_BIT2 | _BIT1 | _BIT0), HIBYTE(stModeInfo.IHWidth) & (_BIT2 | _BIT1 | _BIT0));
    CScalerSetByte(_IPH_ACT_WID_L_17, LOBYTE(stModeInfo.IHWidth));

    ustemp = stModeInfo.IVStartPos - (ucVStartBias + _PROGRAM_VDELAY);

    CScalerSetBit(_IPV_ACT_STA_H_18, ~(_BIT2 | _BIT1 | _BIT0), HIBYTE(ustemp) & (_BIT2 | _BIT1 | _BIT0));
    CScalerSetByte(_IPV_ACT_STA_L_19, LOBYTE(ustemp));
    CScalerSetBit(_IPV_ACT_LEN_H_1A, ~(_BIT2 | _BIT1 | _BIT0), HIBYTE(stModeInfo.IVHeight) & (_BIT2 | _BIT1 | _BIT0));
    CScalerSetByte(_IPV_ACT_LEN_L_1B, LOBYTE(stModeInfo.IVHeight));

	CScalerSetBit(_IPH_ACT_WID_H_16, ~_BIT7, 0x00);//Video8 C-port MSB & LSB Swap(Normal)

	// Display horizontal start/end
    ((WORD *)pData)[4] = CCalcPanelDHSta();
    ((WORD *)pData)[5] = CCalcPanelDHEnd(); 
    //((WORD *)pData)[4] = (Panel[ucPanelSelect]->DHWidth - stDisplayInfo.DHWidth) / 2 + Panel[ucPanelSelect]->DHStartPos;
    //((WORD *)pData)[5] = ((WORD *)pData)[4] + stDisplayInfo.DHWidth;
	
    pData[0] = HIBYTE(((WORD *)pData)[4]);
    pData[1] = LOBYTE(((WORD *)pData)[4]);
    pData[2] = HIBYTE(((WORD *)pData)[5]);
    pData[3] = LOBYTE(((WORD *)pData)[5]);
	
    CScalerSetByte(_DISP_ACCESS_PORT_2A, _DISP_DH_ACT_STA_H_05);
    CScalerWrite(_DISP_DATA_PORT_2B, 4, pData, _NON_AUTOINC);

    //Set DH_TOTAL
    pData[0] = (HIBYTE(stDisplayInfo.DHTotal - 4) & 0x0f);
    pData[1] = (LOBYTE(stDisplayInfo.DHTotal - 4));

    CScalerSetByte(_DISP_ACCESS_PORT_2A, _DISP_DH_TOTAL_H_00);
    CScalerWrite(_DISP_DATA_PORT_2B, 2, pData, _NON_AUTOINC);

    if(field == _VIDEO_60HZ)  // hill added to avoid framesync error
		stModeInfo.IVTotal = 264;   // set 60HZ 525 lines
    else if(field == _VIDEO_50HZ)
		stModeInfo.IVTotal = 312;  // set 50Hz 625 lines

    // Calculate DV_TOTAL setting for watchdog
    ((WORD *)pData)[2] = (DWORD)stModeInfo.IVTotal * (DWORD)(stDisplayInfo.DVHeight) / stModeInfo.IVHeight + 64;
	pData[0] = (HIBYTE(((WORD *)pData)[2]) & 0x0f);
	pData[1] = (LOBYTE(((WORD *)pData)[2]));
    CScalerSetByte(_DISP_ACCESS_PORT_2A, _DISP_DV_TOTAL_H_0B);
    CScalerWrite(_DISP_DATA_PORT_2B, 2, pData, _NON_AUTOINC);

    // Set internal input H sync delay
    CAdjustIHSDelay(ucHStartBias + _PROGRAM_HDELAY);

    // Set internal input V sync delay
    CAdjustIVSDelay(ucVStartBias + _PROGRAM_VDELAY);


    // Calculate and set display clock frequency
    stModeInfo.IHFreq = 157;    // For PAL and NTSC. We can use sync processor to measure the actual value.
    ((DWORD *)pData)[0] = (DWORD)(stDisplayInfo.DHTotal) * (DWORD)stModeInfo.IHFreq * (DWORD)(stDisplayInfo.DVHeight) / stModeInfo.IVHeight / 10;    // uint Khz   Ken

    CAdjustDPLL(((DWORD *)pData)[0]);

    CModeSetScaling(ucScale);          // 0x05: ALL SCALE UP

	// ok here

    // Turn off full-line buffer
    CScalerSetBit(_SCALE_CTRL_32, ~_BIT4, 0x00);

    CAdjustIVS2DVSDelay(ucScale);      // 0x05: ALL SCALE UP

    // Enable display timing
    CScalerSetBit(_VDISP_CTRL_28, ~(_BIT5 | _BIT3 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT1 | _BIT0));

   	// Disable SRGB
    CScalerSetBit(_COLOR_CTRL_62, ~(_BIT2), 0x00);

    CSetVideoColor();


#if(_DE_INTERLACE_SUPPORT == _ON)
  #if(_DE_INTERLACE_TEST_OPTION==_ENABLE)	
	if(!bDIstatus)
		CModeDeInterlaceSetting();
	else
    {
		CScalerSetBit(_SCALE_CTRL_32, ~(_BIT7 ), _BIT7); 			//video mode compensation enable
		CScalerPageSelect(_PAGE6);
		CScalerSetBit(_P6_ENABLE_BIST_CTRL_A0, ~_BIT3, 0x00);	//Disable De-interlace Mode		
 	}			
  #else
	CModeDeInterlaceSetting();	
  #endif		
#endif
	
	//fjyang20070712 for Video8 can do CFrameSyncDetect.
	#if 1
	CAdjustInterlaceIVS2DVSDelay();
	#else
	// Change to even/odd field frame sync
	CScalerSetByte(_IPV_ACT_STA_L_19, CScalerGetBit(_IPV_ACT_STA_L_19, 0xff) + 1);
	CScalerRead(_IV_DV_DELAY_CLK_ODD_41, LENGTH(1), &temp, _NON_AUTOINC);
	ustemp = (WORD)temp * 16 + 16;
	ustemp += stModeInfo.IHTotal;

	CScalerSetByte(_IV_DV_DELAY_CLK_ODD_41, (ustemp - 16) / 16);
	ustemp -= stModeInfo.IHTotal / 2; //forster modified 060424 for frame sync issue

	CScalerSetByte(_IV_DV_DELAY_CLK_EVEN_42, (ustemp - 16) / 16);
//	CScalerSetBit(_FS_DELAY_FINE_TUNING_43, ~(_BIT1), _BIT1|_BIT0);
	CScalerSetBit(_FS_DELAY_FINE_TUNING_43, ~(_BIT1), _BIT1);
	#endif
    CTimerDelayXms(100);
	pData[0] = CFrameSyncDo();
	    /*
	if(0)//ucOsdState != _AUTOSCANCHANNEL_STATE)	// TV autoscan not to check frame sync fail,hill 20070503
	{
		if (pData[0] == 2) 
		{
			CModeResetMode();
			return;
		}
	} */

    SET_MODESTABLE();


	CTimerDelayXms(100);
	CModeSetupEtcs(_FUNCTION_DISABLE);    

	CScalerSetDataPortByte(_DISP_ACCESS_PORT_2A, _DISP_NEW_DV_CTRL_22, 0x00);
	
	CScalerPageSelect(_PAGE7);
	CScalerSetByte(0xAF,0x80);
	CScalerSetByte(0xB0,0x80);
	//CTimerActiveTimerEvent(SEC(2), SetDHToal);



	    //CScalerSetByte(_DISP_ACCESS_PORT_2A,0x0f);
        //CScalerSetByte(_DISP_DATA_PORT_2B,0x04);




}
  /*
//-->fjyang20070712 add to fix FHFV bug
UINT8	dto_check_count = 0;
UINT32	dto_diff_sum = 0;

void CVideoFixedFHFVBug(void)
{
	UINT16	EVEN_LINE,ODD_LINE;
	UINT8	VLINE;

	UINT8	do_dto_sum;
	UINT16	hdto_msb_tmp;

	UINT32	dto_diff_avg;
	UINT32	cdto_tmp, hdto_tmp, diff_tmp;
                           
	if ((ucMode_Curr_2610 == ZPAL_I)||(ucMode_Curr_2610 == ZNTSC))
	{
		//Start of FV +/-3 hz
		CScalerPageSelect(_PAGEA);
		CScalerRead(_PA_MEAS_1ST_V_HI_D3, 4, pData, _AUTOINC);

		EVEN_LINE= (((UINT16)(pData[0])<<8)+(UINT16)pData[1]);
		ODD_LINE= (((UINT16)(pData[2])<<8)+(UINT16)pData[3]);
			
		if (ucMode_Curr_2610 == ZPAL_I)
		{
			if((EVEN_LINE+ODD_LINE)>625)
				VLINE=0xc1+(EVEN_LINE+ODD_LINE-625);
			else if ((EVEN_LINE+ODD_LINE)<625)
				VLINE=0xc1-(625-(EVEN_LINE+ODD_LINE));
			else
				VLINE=0xc1;
		}
		else if (ucMode_Curr_2610 == ZNTSC)
		{
			if((EVEN_LINE+ODD_LINE)>525)
				VLINE=0x61+(EVEN_LINE+ODD_LINE-525);
			else if ((EVEN_LINE+ODD_LINE)<525)
				VLINE=0x61-(525-(EVEN_LINE+ODD_LINE));
			else
				VLINE=0x61;
		}

		CScalerPageSelect(_PAGE8);
		CScalerSetBit(_P8_ZORAN_REG_EN_D7, ~_BIT1, _BIT1);
		
		CScalerPageSelect(_PAGE9);
		CScalerRead(_P9_VACT_HEIGHT_E1, 1, pData, _NON_AUTOINC);
		if(pData[0]!=VLINE)
			CScalerWrite(_P9_VACT_HEIGHT_E1, 1, &VLINE, _NON_AUTOINC);
		//End of FV +/-3 hz

		//Start of FH +/-400 hz
		CScalerPageSelect(_PAGE8);
		CScalerRead(_P8_HDTO_INC_STATUS4_C0, 8, pData, _AUTOINC);
		hdto_tmp = (((UINT32)(pData[0])<<24)+((UINT32)(pData[1])<<16)+((UINT32)(pData[2])<<8)+((UINT32)pData[3]));
		cdto_tmp = (((UINT32)(pData[4])<<24)+((UINT32)(pData[5])<<16)+((UINT32)(pData[6])<<8)+((UINT32)pData[7]));	

		hdto_msb_tmp = (((UINT16)(pData[0])<<8)+(UINT16)(pData[1]));
		do_dto_sum = 1;
		
		if( hdto_msb_tmp > 0x2000 )
		{	
			if( hdto_msb_tmp - 0x2000 > 0xD0)
				do_dto_sum =0;
		}
		else
		{
			if(  0x2000 - hdto_msb_tmp > 0xE0)
				do_dto_sum =0;
		}
				
		dto_diff_avg = 0;
		
		if(do_dto_sum)
		{
			diff_tmp = cdto_tmp-hdto_tmp;
			dto_diff_sum += diff_tmp;
			dto_check_count ++;

			if(dto_check_count == 16)
			{
				dto_diff_avg = dto_diff_sum >> 4;
				dto_check_count = 0;
				dto_diff_sum = 0;
			}
		}

		if(dto_diff_avg!=0)
		{			
			if (ucMode_Curr_2610 == ZNTSC)
			{
				if((dto_diff_avg <= 0x01D18000) || (dto_diff_avg >= 0x020f6000))
				{
					CScalerSetByte(_P8_YCSEP_CTRL_E0, 0x03);
					if(CFrameSyncDetect())
					{
						SET_MODESTABLE();
						CModeResetMode();
					}
				}
				else
				{
					CScalerSetByte(_P8_YCSEP_CTRL_E0, 0x00);
				}
			}
			else if (ucMode_Curr_2610 == ZPAL_I)
			{
				if((dto_diff_avg <= 0x09EA0000) || (dto_diff_avg >= 0x0A23F2EF))
				{
					CScalerSetByte(_P8_YCSEP_CTRL_E0, 0x03);
					if(CFrameSyncDetect())
					{
						SET_MODESTABLE();
						CModeResetMode();
					}
				}
				else
				{
					CScalerSetByte(_P8_YCSEP_CTRL_E0, 0x02);
				}	
			 }
		}
		//End of FH +/-400 hz
	}
} */

      
/**
 * CVideoProcess
 * The VDC input's state machine.
 * If the input source is throught VDC, it will call this function to
 * process display state. There are 4 states here.
 * @param <none>
 * @return {none}
 *
*/     
//--------------------------------------------------
// Description  : The VDC input's state machine.
// If the input source is throught VDC, it will call this function to
// process display state. There are 4 states here.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CVideoProcess(void)
{
	switch (ucCurrState) 
	{
		case _SEARCH_STATE:	
	        if(GET_SCREEN_LR())
	            bLR = 1;  //jokerxie 08-05-05 for chuangfeng Screen 90 270
	        else
	            bLR = 0;//0//TX//1//UD
	        if(GET_SCREEN_UD())   
	            bUD = 1;  //jokerxie for chuangfeng Screen 0 180
	        else 
	            bUD = 0;//0//TX//1//RL
			if(gmi_CVideoModeChange())
			{
				CTimerCancelTimerEvent(CModeNoSignalEvent);
				SET_READYFORDISPLAY();
				CVideoDisplaySet();                         
                CLR_LIGHTPOWERSTATUS();
                ucSearchCount     = 1;
                ucTVSyncFailCount = 0;
/*
                if(GET_SCREEN_LR())
                    MCU_PORT75_PIN_REG_FFD4 = 1;  //jokerxie 08-05-05 for chuangfeng Screen 90 270
                else
                    MCU_PORT75_PIN_REG_FFD4 = 0;
                if(GET_SCREEN_UD())   
                    MCU_PORT74_PIN_REG_FFD3 = 1;  //jokerxie for chuangfeng Screen 0 180
                else 
                    MCU_PORT74_PIN_REG_FFD3 = 0;
*/
//$$ Modified by AndyLiu 20080618
/*                if(GET_SCREEN_LR())
				{
					bLR = 0;
                    SET_SCREEN_LR(0);
				}
                else
				{
					bLR = 1;
                    SET_SCREEN_LR(1);
				}
                if(GET_SCREEN_UD())
				{
					bUD = 0;
                    SET_SCREEN_UD(0);
				}
                else
				{
					bUD = 1;
                    SET_SCREEN_UD(1);
				}
				CEepromSaveSystemData();
*/

//$$ ~Modified by AndyLiu 20080618
				ucCurrState       = _ACTIVE_STATE;
			} 
			else 
            {
				ucCurrState = _NOSIGNAL_STATE;
                SET_READYFORDISPLAY();
            }
			break;

		case _ACTIVE_STATE:
			if (!gmi_CVideoIsExist())
			{
			   	CModeResetMode();  
				break;
			}
                        
           // CVideoFixedFHFVBug();                       
			if (GET_READYFORDISPLAY() == _TRUE) 
			{
                CPowerPanelOn();
				CLR_READYFORDISPLAY();
                SET_OSD_READYFORDISPLAY();
			}    

            if (ucSearchCount)
                ucSearchCount++;

            if (ucSearchCount < 100)  
                break;

            ucSearchCount = 0;
			if (GET_LIGHTPOWERSTATUS() == _OFF) 
			{
                CScalerSetBit(_VDISP_CTRL_28, ~(_BIT5), (0x00));
				CPowerLightPowerOn();
                
                /*
                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
			#if(_VIDEO_TV_SUPPORT)
	            else if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bChangeChannel)
	               CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE); 
			#endif
                */

			#if(_VIDEO_TV_SUPPORT)
	            if(_GET_INPUT_SOURCE() == _SOURCE_VIDEO_TV && bChangeChannel)
	               CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE); 
			     else
            #endif

                ucOsdEventMsg = _DO_SHOW_NOTE;

			}
			break;

		case _NOSIGNAL_STATE:
			if (GET_READYFORDISPLAY()) 
			{
                CLR_READYFORDISPLAY();
				CModeSetFreeRun();  
                SET_OSD_READYFORDISPLAY();
			}    

            if (gmi_CModeLocked())
			{
                COsdDispOsdTimerEvent();
                ucTVSyncFailCount = 250;
			   	CModeResetMode();
			}
			else
			{
                CScalerSetByte(_DISP_ACCESS_PORT_2A,0x22);
                CScalerSetByte(_DISP_DATA_PORT_2B,0xa0);
			}
			break;

		case _SLEEP_STATE:
            if (gmi_CModeLocked())
			{      
                ucTVSyncFailCount = 250;
			   	CModeResetMode();
			}
			break;

		default:
			break;
	}
}


#endif  // End of #if(_VIDEO_SUPPORT == _ON)
