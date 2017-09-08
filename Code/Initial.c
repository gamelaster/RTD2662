#define __INITIAL__

#include "Header\Lcd_main.h"
#include "reg52.h"
#include "Header\Access.h"
#include "Header\config.h"
#include "intrins.h"
#include "Header\Lcd_func.h"
#include "Header\Initial.h"
#include "Header\OSD.h"
#include "Header\Src_Ctrl.h"
#include "Header\Frame_Sync.h"
//#include "Power_Ctrl.h"

void MCU_Init(void)
{
#if(MCU_TYPE == MCU_WINBOND)
    IE      = 0x00;                 // Disable all interrupts
    TMOD    = 0x11;                 // Program Timer0 & Timer1 to Mode#1
    TR0     = 0;                    // Stop Timer0
    TF0     = 0;                    // Clear Timer0 Overflow Bit
    TL0     = TIME0_COUNTER_LBYTE;  // Load Timer0 low-byte   (for 20ms)
    TH0     = TIME0_COUNTER_HBYTE;  // Load Timer0 high-byte  (for 20ms)
    TR1     = 0;                    // Stop Timer1
    TF1     = 0;                    // Clear Timer1 Overflow Bit
    TL1     = TIME1_COUNTER_LBYTE;  // Load Timer1 low-byte   (for 1ms)
    TH1     = TIME1_COUNTER_HBYTE;  // Load Timer1 hifh-byte  (for 1ms)
    IE      = 0x8a;                 // Enable interrupts of Timer0 and Timer1
//anson 050519    
    M512_PadMode0=0x00;		//
    M512_PadMode1=0xff;		//
    M512_PadMode2=0xb0;		//
    M512_PadMode3=0xcf;		//
    M512_PadMode4=0xf2;		//
    M512_PadMode5=0x00;		//
//    M512_PadMode6=0xbf;		//
    M512_PadMode7=0x3f;		//
    M512_Option1=0x01;
#else
    IE      = 0x00;                 // Disable all interrupts
    TMOD    = 0x11;             // Program Timer0 & Timer1 to Mode#1
    TR0     = 0;                    // Stop Timer0
    TF0     = 0;                    // Clear Timer0 Overflow Bit
    TL0     = TIME0_COUNTER_LBYTE;  // Load Timer0 low-byte   (for 20ms)
    TH0     = TIME0_COUNTER_HBYTE;  // Load Timer0 high-byte  (for 20ms)
    TR1     = 0;                    // Stop Timer1
    TF1     = 0;                    // Clear Timer1 Overflow Bit
    TL1     = TIME1_COUNTER_LBYTE;  // Load Timer1 low-byte   (for 1ms)
    TH1     = TIME1_COUNTER_HBYTE;  // Load Timer1 hifh-byte  (for 1ms)
    
    IE      = 0x86;                 // Enable interrupts of Timer0 and Timer1
    TR0            = 1;
//anson 050519    
    M512_PadMode0=0x00;		//
    M512_PadMode1=0xff;		//
    M512_PadMode2=0xb0;		//
    M512_PadMode3=0xcf;		//
    M512_PadMode4=0xf2;		//
    M512_PadMode5=0x00;		//
//    M512_PadMode6=0xbf;		//
    M512_PadMode7=0x3f;		//
    M512_Option1=0x01;

#endif
}

void Firmware_Init(void)
{

#if(MCU_TYPE == MCU_WINBOND)
    bLIGHT_PWR  = LIGHT_OFF;
    bPANEL_PWR  = PANEL_OFF;
    bPanel_Status = _OFF;
#else
    MCU_WriteBacklightPower(LIGHT_OFF);
    MCU_WritePanelPower(PANEL_OFF);
	    bPanel_Status = _OFF;
#endif

     MCU_Init();
     RTDSetBit(HOSTCTRL_02,0xfb,0x00);    // RTD turn on
#if(MCU_TYPE == MCU_WINBOND)

#if(RESET_TYPE == RESET_IN)
    bRTD_RST    = 0;
    Delay_Xms(10);
    do
    {
        // Wait for reset complete
        bRTD_RST    = 1;
        Delay_Xms(2);
    }
    while (!bRTD_RST);
#endif

#else

#if(RESET_TYPE == RESET_IN)
    MCU_WriteRtdReset(LOW);
    Delay_Xms(10);
    do
    {
        // Wait for reset complete
        MCU_WriteRtdReset(HIGH);
        Delay_Xms(10);
    }
    while (MCU_ReadRtdReset()!=HIGH);
#endif


#endif

    RTDRead(ID_REG_00,1,N_INC);
	ucID_Code = Data[0];


    RTDCodeW(RTD_PWUP_INI);
	
#if(HDCP_ENABLE)
    RTDCodeW(BKSV);
    KEYCodeW(HDCP_KEY_A_Port);
#endif

    RTDSetByte(HOSTCTRL_02, 0x40);          // Wake RTD up
    RTDSetByte(DPLL_CTRL_D0, 0x11);         // Enable DPLL

    RTDSetByte(VDIS_SIGINV_21, 0x00 | DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP);       // DHS, DVS, DEN, DCLK MUST NOT be inverted.

    RTDSetBit(VDIS_CTRL_20, 0xfd, 0x21);    // DHS, DVS, DEN, DCLK and data are clamped to 0

    RTDSetBit(DIS_TIMING0_3A, 0xff, 0x20);  // Force display timing enable
    RTDSetBit(DIS_TIMING0_3A, 0xdf, 0x00);  // Stop forcing

    _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();

    RTDSetBit(VDIS_CTRL_20, 0xfe, 0x00);    // Stop display timing

    RTDSetByte(HOSTCTRL_02, 0x42);          // Put RTD2020 back into power-saving mode
    RTDSetByte(DPLL_CTRL_D0, 0x10);         // Disable DPLL

    RTDCodeW(RTD_DDC_TABLE);
    RTDCodeW(RTD_IO_INI);

#if(!SOURCE_AUTO_SCAN)
    PowerDown_VDC();
    //Device_Power(VDC_POWER,OFF);
#endif

	PowerDown_TMDS();
    PowerDown_LVDS();
    //Device_Power(TMDS_POWER,OFF);
    //Device_Power(LVDS_POWER,OFF);

    Delay_Xms(10);

    // Check and initial EEPROM if necessary
    Delay_Xms(10);
    Check_EEPROM();
    Delay_Xms(10);

    // Turn timer0 on. Let's go ~~~
    TR0     = 1;


}

void Power_Up_Init(void)    // Do once when power up
{
   
     RTDSetBit(HOSTCTRL_02,0xfb,0x00);    // RTD turn on


    Reset_RTD();            // Initial RTD3000 & OSD



#if(ADC_DEFFERENTIAL)
    RTDSetBit(ADC_DIFF_MODE_EC,0xff,0x40); //Differential mode
#else
    RTDSetBit(ADC_DIFF_MODE_EC,0xbf,0x00); //Single endded mode
#endif



#if(MCU_TYPE == MCU_WINBOND)
    bLIGHT_PWR  = LIGHT_OFF;
    bPANEL_PWR  = PANEL_OFF;
	bPanel_Status = _OFF;
#else
    MCU_WriteBacklightPower(LIGHT_OFF);
    MCU_WritePanelPower(PANEL_OFF);
    bPanel_Status = _OFF;
#endif


#if(TUNE_APLL)
	ucPE_Max = 0;
	RTDSetByte(DV_TOTAL_STATUS_3D,0x40); //clear PE Max value
#endif

#if(!SOURCE_AUTO_SCAN)
    PowerDown_VDC();
	//Device_Power(VDC_POWER,OFF);
#endif

    PowerDown_LVDS();
	//Device_Power(LVDS_POWER,OFF);

#if(TMDS_ENABLE)
RTDSetByte(ANG_PERFORMANCE2_A3, 0x26); //Go about the TMDS impedence match
RTDSetByte(ANG_PERFORMANCE2_A3, 0x36);		
#endif

    //RTDSetBit(OVL_CTRL_6D, 0x3f, (stGUD1.FUNCTION & 0x10) ? 0x80 : 0x00);

    RTDSetBit(OVL_CTRL_6D, 0xc7, (stGUD1.INPUT_SOURCE & 0xe0) >> 2);


#if (SPREAD_SPECTRUM)

//    RTDSetBit(SPREAD_SPECTRUM_99,0x03,0x00);
    RTDSetBit(DPLL_N_D2,0xff,0x20); //DPLL spread spectrum Enable

#endif

    Init_Input_Source();    // Initial Mode & OSD
}

void Reset_RTD(void)
{
#if(MCU_TYPE == MCU_WINBOND)

#if(RESET_TYPE == RESET_IN)
    bRTD_RST    = 0;
	Delay_Xms(10);
    do
    {
        // Wait for reset complete
        bRTD_RST    = 1;
        Delay_Xms(6);
    }
    while (!bRTD_RST);
#endif

#else

#if(RESET_TYPE == RESET_IN)
    MCU_WriteRtdReset(LOW);
	 Delay_Xms(10);
    do
    {
        // Wait for reset complete
        MCU_WriteRtdReset(HIGH);
        Delay_Xms(6);
    }
    while (MCU_ReadRtdReset()!=HIGH);
#endif

#endif
    


    // Initial RTD3000 & free background display
    RTDCodeW(RTD_PWUP_INI);
#if(HDCP_ENABLE)
    RTDCodeW(BKSV);
    KEYCodeW(HDCP_KEY_A_Port);
#endif

    RTDCodeW(RTD_DDC_TABLE);
    RTDCodeW(RTD_IO_INI);

    RTDSetByte(HOSTCTRL_02, 0x40);          // Wake RTD up

    RTDCodeW(FreeV);

    RTDSetByte(VDIS_SIGINV_21, 0x00 | DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP);       // DHS, DVS, DEN, DCLK MUST NOT be inverted.


    RTDSetBit(VDIS_CTRL_20, 0xfd, 0x01);    // DHS, DVS, DEN, DCLK and data are clamped to 0

    // Initial RTD3000-OSD
    RTDCodeW(OSD_PWUP_INI);
    RTDOSDW(OSD_Reset);

    // Initial OSD palette
    RTDCodeW(Palette_Open);
    RTDCodeW(Palette_7);
    RTDCodeW(Palette_Close);




    // Check and initial EEPROM if necessary
//    Delay_Xms(10);
//    Check_EEPROM();
//    Delay_Xms(10);

    Set_Gamma();
    Set_Dithering();
    Set_Bright_Contrast();
}

void Init_Input_Source(void)
{       
    ucMode_Found    = MODE_NOSUPPORT;
    ucMode_Curr     = MODE_NOSIGNAL;
    ucMode_Times    = 0;
    ucAV_Mode       = 0;
    bVpole_Curr     = 1;                // The initial set of polarity is positive
    bHpole_Curr     = 1;                // The initial set of polarity is positive

    // Unknown signal source
    if (SOURCE_MAX < (stGUD1.INPUT_SOURCE & 0x07))
        stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | SOURCE_VGA;

#if (TMDS_ENABLE == _FALSE)
    if (SOURCE_DVI == (stGUD1.INPUT_SOURCE & 0x07))
        stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | SOURCE_VGA;
#endif

#if (VIDEO_CHIP == VDC_NONE)
    if (SOURCE_AV == (stGUD1.INPUT_SOURCE & 0x07) || SOURCE_SV == (stGUD1.INPUT_SOURCE & 0x07))
        stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | SOURCE_VGA;
#endif
#if (VIDEO_CHIP != VDC_SAA7118)
    if (SOURCE_YUV == (stGUD1.INPUT_SOURCE & 0x07))
        stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | SOURCE_VGA;
#endif
#if (TV_CHIP == TV_NONE)
    if (SOURCE_TV == (stGUD1.INPUT_SOURCE & 0x07))
        stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | SOURCE_VGA;
#endif

    // Because internal ADC power state will not affect VGA mode detection,
    // we always turn off ADC when source changed, and turn it on again only 
    // when a valid VGA mode is going to display.
    PowerDown_ADC();
    //Device_Power(ADC_POWER,OFF);

#if(SOURCE_AUTO_SCAN)
	PowerUp_VDC();
	Delay_Xms(10);
#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)
        I2CWrite(V_ENABLE);         // VIDEO ENABLE
        I2CWrite(VIDEO_ALL);
#endif
    bSourceScanEnable = _TRUE;
#endif

    switch (stGUD1.INPUT_SOURCE & 0x07)
    {
    case SOURCE_VGA:
#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)
        I2CWrite(V_DISABLE);        // VIDEO DISABLE
#endif
        I2CWrite(V_NOWORK);         // VIDEO No Work

#if(!SOURCE_AUTO_SCAN)
    PowerDown_VDC();
	PowerDown_TMDS();
	//Device_Power(VDC_POWER,OFF);
	//Device_Power(TMDS_POWER,OFF);
#else
    PowerUp_VDC();
	PowerUp_TMDS();
	//Device_Power(VDC_POWER,ON);
	//Device_Power(TMDS_POWER,ON);
#endif

#if(TMDS_ENABLE)
        RTDSetBit(TMDS_CORRECTION_FF,0xfc,0x00);
#endif
        // Set user's ADC gain and offset settings
        SetADC_GainOffset();

        ucInputSrc  = SOURCE_VGA;        
        ucSync_Type = SYNC_SS;

        RTDCodeW(VGA_INI_SS);
        break;
  case SOURCE_DVI:
#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)
        I2CWrite(V_DISABLE);        // VIDEO DISABLE
#endif
        I2CWrite(V_NOWORK);         // VIDEO No Work

#if(!SOURCE_AUTO_SCAN)
    PowerDown_VDC();
	//Device_Power(VDC_POWER,OFF);
#else
    PowerUp_VDC();
	//Device_Power(VDC_POWER,ON);
#endif

#if(TMDS_ENABLE)
        RTDSetBit(TMDS_CORRECTION_FF,0xfc,0x00);
#endif
        PowerUp_TMDS();
        //Device_Power(TMDS_POWER,ON);

        ucInputSrc  = SOURCE_DVI;        
        RTDCodeW(DVI_INI);
        break;      
    case SOURCE_AV:
    case SOURCE_TV:
#if(SOURCE_AUTO_SCAN)
        if((SOURCE_AV != MASTER_SOURCE) && (SOURCE_AV != SLAVE_SOURCE) && (SOURCE_AV != THIRD_SOURCE))
		   bSourceScanEnable = _FALSE;
#endif	 
        PowerUp_VDC();

#if(TMDS_ENABLE)
        RTDSetBit(TMDS_CORRECTION_FF,0xfc,0x00);
#endif
        //Device_Power(VDC_POWER,ON);

        // PCB rev.C
        // For PCB rev.C, turning down TMDS will turning on video decoder.
        // However, video decoder needs times to wake up.
        Delay_Xms(10);

#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)
        I2CWrite(V_ENABLE);         // VIDEO ENABLE
        I2CWrite(VIDEO_ALL);
#endif
        I2CWrite(AV_DETECT);        // VIDEO Detect(AV)

        if (SOURCE_AV == (stGUD1.INPUT_SOURCE & 0x07))
        {
            ucInputSrc  = SOURCE_AV;
        }
        else
        {
            ucInputSrc  = SOURCE_TV;

#if (TV_CHIP != TV_NONE)
            // Set TV channel
            Set_TV_Channel();
#endif
            // Select TV signal input pin and disable AGC of video decoder
            I2CWrite(TV_SOURCE_SEL);
            I2CWrite(TV_SCAN_GAIN);
        }

        RTDCodeW(VIDEO_INI);
        I2CRead(ADDR_VIDEO, 0x1f, 0x01);
        break;
        
    case SOURCE_SV:
#if(SOURCE_AUTO_SCAN)
        if((SOURCE_SV != MASTER_SOURCE) && (SOURCE_SV != SLAVE_SOURCE) && (SOURCE_SV != THIRD_SOURCE))
		   bSourceScanEnable = _FALSE;
#endif	 

	 PowerUp_VDC();
	 //Device_Power(VDC_POWER,ON);


       Delay_Xms(10);

#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)
        I2CWrite(V_ENABLE);         // VIDEO ENABLE
        I2CWrite(VIDEO_ALL);
#endif
        I2CWrite(SV_DETECT);        // VIDEO Detect(SV)

        ucInputSrc  = SOURCE_SV;
        RTDCodeW(VIDEO_INI);
        I2CRead(ADDR_VIDEO, 0x1f, 0x01);
        break;

    case SOURCE_YUV:
#if(SOURCE_AUTO_SCAN)
        if((SOURCE_YUV != MASTER_SOURCE) && (SOURCE_YUV != SLAVE_SOURCE) && (SOURCE_YUV != THIRD_SOURCE))
		   bSourceScanEnable = _FALSE;
#endif	 

	    PowerUp_VDC();
		//Device_Power(VDC_POWER,ON);

        
        Delay_Xms(10);

        I2CWrite(V_ENABLE);         // VIDEO ENABLE
        I2CWrite(VIDEO_ALL);
        I2CWrite(VIDEO_YUV);

        I2CWrite(YUV_DETECT);       // VIDEO Detect(YUV)

        ucInputSrc  = SOURCE_YUV;
        RTDCodeW(VIDEO_INI);
        I2CRead(ADDR_VIDEO, 0x1f, 0x01);
        break;
    }

#if (AUDIO_TYPE != AUDIO_NONE)
    SetVolume();
#endif
}
void Power_Status_Init(void)
{
#if (POWER_KEY_TYPE == TYPE_ONE_TOUCH)

#if (KEY_DISABLED == POWER_KEY_MASK)

    // Force system to power up when no power-key

    bPower_Status   = 1;

    Power_Up_Init();

    bStable     = 0;                    // Assume input signal is not stable when power up
    bReload     = 1;                    // Always reload font when power up
    bFrameSync  = 0;                    // Not sync yet
    ucModeCnt   = MODE_DETECT_FREQ;     // Reset Input Mode Detector
    
    Measure_Mode();                     // Measure mode-timing
    Set_Task(STATE_POWERUP);            // Notify Task State Machine

#else

    // Restore previous power status

    if (0 == (stGUD1.FUNCTION & 0x08))
    {
        bPower_Status   = 1;

         	if(((stGUD3.TV_SETTING & 0x08)==0x08) || ((stGUD3.TV_SETTING & 0x20)==0x20))	//anson
                {
	                 stGUD3.TV_SETTING &= 0xF7 ;  
	                 Save_GUD3();
                }

        Power_Up_Init();

        
        bStable     = 0;                    // Assume input signal is not stable when power up
        bReload     = 1;                    // Always reload font when power up
        bFrameSync  = 0;                    // Not sync yet
        ucModeCnt   = MODE_DETECT_FREQ;     // Reset Input Mode Detector
    
        Measure_Mode();                     // Measure mode-timing
        Set_Task(STATE_POWERUP);            // Notify Task State Machine
    }
    else
    {
        bPower_Status   = 0;
    }

#endif

#else

    // Do nothing when power-key is two-state type.
    bPower_Status   = 0;

#endif
}
