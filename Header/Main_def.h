#include "HEADER\CHAR_DEF.H"
#include "HEADER\MODE_DEF.H"
#include "HEADER\RTD_DEF.H"
#include "HEADER\CODE_DEF.H"


#define _TRUE            1
#define _FALSE           0
#define _HIGH            1
#define _LOW             0
#define _ON              1
#define _OFF             0

///////////////////////////////////////////////////////////////////
// Definitions for debug
#define ISPACK          0   // Using ISPACK.                This definition must be disabled when not using ISPACK
#define KINGMICE        0   // Using KingMice for debug.    This definition must be disabled when not using KINGMICE
#define GETREGISTER     0   // Using ICE for debug.         This definition must be disabled when not using KINGMICE
#define GETSFR          0   // Get the Status of SFR.       This definition must be disabled when not using KINGMICE
#define RTDDEBUG        0   // Status check for debug.
#define SHOW_CHECK      0   // Show debug message on OSD.
#define RS232_DEBUG     0   // DEBUG enable through the rs232 & external MCU

//////////////////////////////////////////////////////////////////////
//Definitions for Auto Switch(Auto Switch to freerun and background when some event occur)
#define AS_DV_TOTAL      _TRUE   // When line number of Display HS is equal to Display Vertical Total
#define AS_PLL_NONLOCK   _TRUE   // When ADC-PLL non-lock
#define AS_NON_FRAMESYNC _FALSE   // When overflow or underflow

// Issac :
// The definition of KINGMICE must be 0 when you want to use flash ROM instead of KINGMICE debug board

///////////////////////////////////////////////////////////////////
// Definitions for advance function
#define TUNE_APLL               _TRUE    // Do PLL fine-tune according to PE         1 : Enabled, 0 : Disabled
#define MORE_CLOCK              _FALSE   // Do Auto-clock in clock step 1            1 : Enabled, 0 : Disabled
#define FULL_LINE_BUFFER        _FALSE   // Enable full-line buffer                  1 : Enabled, 0 : Disabled
#define HIDDEN_PAGE             _FALSE   //_TRUE    // Hidden OSD control page                  1 : Enabled, 0 : Disabled
#define SPREAD_SPECTRUM         _TRUE    // Turn on spread spectrum function         1 : Enabled, 0 : Disabled
#define NEW_PI_CODE             _TRUE    // PLL setting method                       1 : NEW    , 0 : Old
#define BURNIN_MODE             _TRUE   // Burn-In mode activation                  1 : Enable,  0 : Disable
#define SOURCE_AUTO_SCAN        _TRUE   // Auto scan input source                   1 : Enable,  0 : Disable
#define ANALOG_CONTRAST         _TRUE    // Adjust the contrast with analog gain     1 : Enable,  0 : Disable
#define ADC_DEFFERENTIAL        _TRUE    // ADC use the defferential mode            1 : Defferential   0: Single ended,only effect after ver C of 2522
#define PARALLEL_PORT           _FALSE   // Use the parallel port to access RTD      1 : Parallel  0 : Serial
#define HARDWARE_AUTO           _TRUE    // Enable the hardware auto funciton        1 : Enable    0 : Disable
#define MORE_PHASE              _FALSE    // Enable 128 phase selection               1 : Enable    0 : Disable
#define ANTI_FLICKER            _FALSE    // Anti flicker function activation         1 : Enable,   0 : Disable
#define VLC_COMPRESS            _TRUE     // Use VLC to compress the OSD table        1 : Enable,   0 : Disable
#define NEW_DITHER              _FALSE     // Use new ditherring algorithm             1 : Enable,   0 : Disable
#define USE_MCU_DDC             _FALSE     //Use DDC on MCU just for MTV512             1 : Enable,   0 : Disable

/////////////////////////////////////////////////////////////////////////////////////////////
//Source search prioirty, just if SOURCE_AUTO_SCAN function enable, below definition is valid
#define MASTER_SOURCE   SOURCE_VGA
#define SLAVE_SOURCE    SOURCE_DVI
#define THIRD_SOURCE    SOURCE_SV

/////////////////////////////////////////////////////////////////////////////////////////////
//Clock adjust align
#define ALIGN_CENTER    0
#define ALIGN_LEFT      1

#define CLOCK_ALIGN     ALIGN_LEFT

//////////////////////////////////////////////////////////////////////////////////////////////
// Two reset types are avaiable below:
//    RESET_IN  : RTD2523 can be reset by input signal or also firmware.
//    RESET_OUT : RTD2523 can output the reset signal to micron and also reset itself.

#define RESET_IN        0
#define RESET_OUT       1

#define RESET_TYPE      RESET_OUT
///////////////////////////////////////////////////////////////////
// For remote control
#define IRPOLLING       0   // Remote control function                  1 : Enabled, 0 : Disabled

#define CUSTOM_CODE     0x9e29

#define IR_ENTER_KEY    0x97
#define IR_RIGHT_KEY    0xe7
#define IR_LEFT_KEY     0xd7
#define IR_POWER_KEY    0xb7

#define IR_FUNC_SOURCE  0x0f
#define IR_FUNC_DISP    0x37
#define IR_FUNC_JUMP    0xf7
#define IR_FUNC_CHDEC   0x87
#define IR_FUNC_CHINC   0xa7
#define IR_FUNC_VOLINC  0x27
#define IR_FUNC_VOLDEC  0x07
#define IR_FUNC_MENU    0x77
#define IR_FUNC_ENTER   0x17
#define IR_FUNC_MUTE    0xcf

#define IR_FUNC_NUM0    0xff
#define IR_FUNC_NUM1    0x7f
#define IR_FUNC_NUM2    0xbf
#define IR_FUNC_NUM3    0x3f
#define IR_FUNC_NUM4    0xdf
#define IR_FUNC_NUM5    0x5f
#define IR_FUNC_NUM6    0x9f
#define IR_FUNC_NUM7    0x1f
#define IR_FUNC_NUM8    0xef
#define IR_FUNC_NUM9    0x6f

///////////////////////////////////////////////////////////////////
// Definition for MCU type
#define MCU_WINBOND     0
#define MCU_MTV512      1

#define MCU_TYPE        MCU_WINBOND

///////////////////////////////////////////////////////////////////
// Definitions for demo board version
#define QA_PCB           0
#define DEMO_LVDS_A      1
#define DEMO1_PCB        2
#define DEMO2_PCB        3 //with audio chip
#define DEMO3_PCB        4

#define BOARD_TYPE      DEMO1_PCB

//////////////////////////////////////////////////////////////////
// Definitions for brightness PWM
#define PWM0             0
#define PWM1             1
#define PWM2             2

#define BRIGHTNESS_PWM   PWM2

/*
///////////////////////////////////////////////////////////////////
// Definitions for 8051 style
#define INT_8051        0
#define EXT_8051        1

#define TYPE_OF_8051    EXT_8051
*/


#if (GETSFR)
sfr  DPL1           = 0x84;
sfr  DPH1           = 0x85;
sfr  DPS            = 0x86;
sfr  CKCON          = 0x8e;
sfr  SPC_FNC        = 0x8f;
sfr  EXIF           = 0x91;
sfr  MPAGE          = 0x92;
sfr  SBUF0          = 0x99;
sfr  SCON1          = 0xc0;
sfr  SBUF1          = 0xc1;
#endif

#if((MCU_TYPE == MCU_WINBOND) && (KINGMICE == _TRUE))
#define IR_KEY_MASK         0x04    // It is a "pseudo" mask for IR message
#else
#define IR_KEY_MASK         0x80    // It is a "pseudo" mask for IR message
#endif

#if (IRPOLLING)
#define ALL_KEY_MASK        (MENU_KEY_MASK | ENTER_KEY_MASK | RIGHT_KEY_MASK | LEFT_KEY_MASK | POWER_KEY_MASK | IR_KEY_MASK)
#else
#define ALL_KEY_MASK        (ENTER_KEY_MASK | RIGHT_KEY_MASK | LEFT_KEY_MASK | POWER_KEY_MASK |AUTO_KEY_MASK | FACTORY_KEY_MASK)	//anson
#endif

// Note :
// When using KingMice on PCB Rev-C for debugging, power-key must be disabled.
// That is, KEY_DISABLED must be POWER_KEY_MASK, and POWER_KEY_TYPE must be TYPE_ONE_TOUCH.

#define KEY_DISABLED        0   // Disabled key must be in the range of ALL_KEY_MASK

#define TYPE_TWO_STATE      0x00
#define TYPE_ONE_TOUCH      0x01

#define POWER_KEY_TYPE      TYPE_ONE_TOUCH

//////////////////////////////////////////////////////////////////
// Definitions for EEPROM 2404
#define ADDR_EDID1      0xA2
#define ADDR_EROM0      0xAC    // EEPROM 2401 (Page 0)
#define ADDR_EROM1      0xAE    // EEPROM 2401 (Page 1)
#define ADDR_EROM2      0xAA    // EEPROM 2401 (Page 1)
#define ADDR_EROM3      0xA0
#define SET_2404_DELAY  0x10    // Delay in ms for EEPROM R/W

///////////////////////////////////////////////////////////////////
// Definitions for display size and type

#define DISP_800x600        0   // 0: 800x600
#define DISP_1024x768       1   // 1: 1024x768
#define DISP_1280x1024      2   // 2: 1280X1024   

#define DISP_SIZE           DISP_1280x1024

#define PANEL_CHIMEI		0
#define PANEL_ACER			1
#define PANEL_HYUNDAI		2
#define PANEL_QDI			3
#define PANEL_INNOUX		4
#define PANEL_SHARP			5
#define PANEL_HANNSTAR		6
#define PANEL_CPT			7

#define PANEL_TYPE          PANEL_HANNSTAR//HSD190ME12

#define PANEL_SIZE		_1_,_7_
#define FW_VERSION		_0_,_0_,_1_

#define TTL_TYPE            0
#define LVDS_TYPE           1
#define RSDS_TYPE           2

#define OUTPUT_BUS          LVDS_TYPE

#if(OUTPUT_BUS == LVDS_TYPE)
#define LVDS_MAP1           0               //LVDS Bit-Mapping Table 1
#define LVDS_MAP2           1               //LVDS Bit-Mapping Table 2

#define LVDS_MAP            LVDS_MAP1


#endif


#define TMDS_ENABLE         _TRUE           //  TRUE  : Enable TMDS function
                                           //  FALSE : Disable TMDS function

#define HDCP_ENABLE         _FALSE          //  TRUE  : Enable HDCP function
                                           //  FALSE : Disable HDCP fucntion
////////////////////////////////////////////////////////////////////////////////
// Definitions for Brightness and ADC Color

#define MAX_BRIGHTNESS  255     // Maximum Setting of Brightness
#define MIN_BRIGHTNESS  0       // Minimum Setting of Brightness
#define INV_BRIGHTNESS  1       // 0 : Normal; 1 : Invert.
#define SWAP_RED_BLUE   0       // 0 : Normal; 1 : Swap Red and Blue


///////////////////////////////////////////////////////////////////
// Definitions for EEPROM 2404

#define ADDR_EROM0      0xAC    // EEPROM 2401 (Page 0)
#define ADDR_EROM1      0xAE    // EEPROM 2401 (Page 1)
#define SET_2404_DELAY  0x10    // Delay in ms for EEPROM R/W


///////////////////////////////////////////////////////////////////
// Definitions for Vedio Decoder

#define VDC_NONE        0   // 0:No vedio decoder available
#define VDC_SAA7111     1   // 1:SAA7111 chip
#define VDC_SAA7113     3   // 3:SAA7113 chip
#define VDC_SAA7114     4   // 4:SAA7114 chip
#define VDC_SAA7115     5   // 4:SAA7115 chip
#define VDC_SAA7118     8   // 5:SAA7118 chip

#define VIDEO_CHIP      VDC_NONE

#define ADDR_7111A      0x48    // Video decoder SAA7111A
#define ADDR_7114       0x42    // Video decoder SAA7114
#define ADDR_7115       0x42    // Video decoder SAA7115
#define ADDR_7118       0x42    // Video decoder SAA7118

#if (VIDEO_CHIP == VDC_NONE)
#define ADDR_VIDEO  ADDR_7114
#endif
#if (VIDEO_CHIP == VDC_SAA7111)
#define ADDR_VIDEO  ADDR_7111A
#endif
#if (VIDEO_CHIP == VDC_SAA7114)
#define ADDR_VIDEO  ADDR_7114
#endif
#if (VIDEO_CHIP == VDC_SAA7115)
#define ADDR_VIDEO  ADDR_7115
#endif
#if (VIDEO_CHIP == VDC_SAA7118)	
#define ADDR_VIDEO  ADDR_7118
#endif

#define VDC_BRIGHT_CTRL     0x0a
#define VDC_CONTRAST_CTRL   0x0b
#define VDC_SATURATION_CTRL 0x0c
#define VDC_HUE_CTRL        0x0d
#define VDC_BRIGHT_YUV_CTRL 0x2a


////////////////////////////////////////////////////////////////////////////////
// Definitions for audio device
#define AUDIO_NONE      0
#define AUDIO_LM4832    1
#define AUDIO_PWM2      2
#define AUDIO_PWM0      3

#define AUDIO_TYPE      AUDIO_PWM0

#define ADDR_LM4832     0x80    // Volume device LM4832

#define INV_VOLUME      0       // 0 : Normal; 1 : Invert. Only useful for PWM volume control


///////////////////////////////////////////////////////////////////
// Definitions for TV system and tuner
#define TV_NTSC         0
#define TV_PAL          1
#define TV_SECAM        2

#define TV_SYSTEM       TV_NTSC

#define TV_NONE         0       // 0:No TV tuner available
#define TV_FI1236       1       // 1:Philips FIL1236    for NTSC
#define TV_FQ1216       2       // 2:Philips FQ1216ME   for PAL

#define TV_CHIP         TV_NONE

#define ADDR_TUNER      0xC6    // Philips FI1236/FQ1216 TV tuner


