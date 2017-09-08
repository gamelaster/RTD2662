
///////////////////////////////////////////////////////////////////
// Definitions for Display Port
#define SINGLE_PORT         0x00    // Single port (Single pixel output)
#define DOUBLE_PORT         0x04    // Double port (Double pixel output)

#define DISPLAY_PORT        DOUBLE_PORT

///////////////////////////////////////////////////////////////////
// Definitions for Display Color
#define DISP_18BIT          0x10    // 18-bit RGB output
#define DISP_24BIT          0x00    // 24-bit RGB output 

#define DISP_BIT            DISP_24BIT

///////////////////////////////////////////////////////////////////
// Definitions for Display Timing Feature
#define MASK_FIRST_DHS      0x80    // Mask 1st DHS
#define NO_MASKING          0x00    // No masking 

#define DHS_MASK            NO_MASKING    

///////////////////////////////////////////////////////////////////
// Definitions for Display Signal
#define DISP_INV            0x0C    // DVS : neg , DHS : neg , DEN : pos
#define DCLK_INV            0x08    // DCLK : pos
#define DCLK_DELAY          0x01    // 1.0ns delay for DCLK

///////////////////////////////////////////////////////////////////
// Definitions for Display Settings

#define MAX_DCLK            138     // Maximum display clock(MHz) that panel can support
#define MAX_RATE            76      // Maximum display refresh rate in Hz that panel can support

#define DH_ACT_STA_POS      0x0020  // DH_ACT_STA_POS should be as small as possible !!!
#define DH_ACT_END_POS      0x0520

#define DV_ACT_STA_POS      0x000c  // DV_ACT_STA_POS should be as small as possible !!!
#define DV_ACT_END_POS      0x040c

#define DISP_WID            (DH_ACT_END_POS - DH_ACT_STA_POS)   // 0x0500 = 1280 pixels
#define DISP_LEN            (DV_ACT_END_POS - DV_ACT_STA_POS)   // 0x0400 = 1024 lines

#define STD_DH_TOTAL        0x0580  // Standard display clock number in one display horizontal line
#define STD_DV_TOTAL        0x0480  // Standard display horizontal line in one display frame
#define STD_HSYNC_WIDTH     0x10    // Display HSYNC clock width
#define STD_VSYNC_LENGTH    0x03    // Display VSYNC line length

#define MIN_DV_TOTAL        0x0410  // Minimum VSYNC that panel can support


#define FIX_LAST_DHT        0//0x1f4

#define MIN_LAST_DHT        0       // Must set to 0 if you don't care last-line length
#define MAX_LAST_DHT        0       // Set it to 0 if you don't care the maximum last-line length
#define VIDEO_ML_DHT        0       // Minimum last-line length for video


#define USER_MODE_NCODE     16      // NEVER change this setting !!!

#define DISP_ALIGN          0       // 0-Left alignment, 1-Right alignment


#define AUTO_SWITCH        0x60      // Auto Switch to freerun mode

#define DISP_EO_SWAP       0x00//0x80      // Display Even/Odd Data Swap
#define DISP_RB_SWAP       0x00//0x40      // Display Red/Blue Data Swap
#define DISP_ML_SWAP       0x00//0x20      // Display MSB/LSB Data Swap


/*
///////////////////////////////////////////////////////////////////
// Definitions for RTD3001
#define All_LINE_BUF        0x02    // Turn on all line buffers
#define REQ_DELAY           0x40    // 0.5ns delay for request
#define V_MAC_DELAY         0x10    // 0.5ns delay for Vertical MAC
#define H_MAC_DELAY         0x04    // 0.5ns delay for Horizontal MAC
#define DCLK_DELAY          0x01    // 1.0ns delay for DCLK

#define HINIT_COEFF         0x00    // Horizontal initial coefficient = 0xc000
#define REQMODE_00B         0x00    // Imporved mode 1 : REG[28]-bit3 = 0
#define REQMODE_01B         0x80    // Imporved mode 1 : REG[31]-bit7 = 1
#define ODDCTRL_VGA         0x38    // REG[31]-bit5  : Odd signal for V inital toggle. (0 : inverse)
                                    // REG[31]-bit4  : Odd signal to control FS_DELAY_FINE_TUNING. (0 : enable)
                                    // REG[31]-bit3  : Odd signal to enable FS_DELAY_FINE_TUNING. (1 : inverse)
#define ODDCTRL_VIDEO       0x28
*/

//---------------------------------- 1280x1024 ---------------------------------
///////////////////////////////////////////////////////////////////////////
#ifdef __MAIN__

unsigned char code RTD_PWUP_INI[]   =
{ 
    5,      Y_INC,  HOSTCTRL_02,        0x42,0x00,

    4,      N_INC,  TC_ADDR_PORT_95,    0x00,
    8,      N_INC,  TC_DATA_PORT_96,    0x04,0x10,0x11,0x80,0xfc,//0x00,0x00,0x00,0x00,
    9,      Y_INC,  GP1_ODOCTRL_F6,     0x00,0x00,0x00,0x00,0x00,0x00,

    6,      Y_INC,  IRQ_CTRL1_0E,       0x00,0x80,0x00,

    4,      N_INC,  INT_FLD_DETECT_14,  0x00,

    25,		Y_INC,	DH_TOTAL_22,		0x08,0x00,0x02,0x04,0x00,0x04,0x00,0x06,0x00,0x06,0x00,
										0x06,0x00,0x01,0x02,0x00,0x02,0x00,0x04,0x00,0x04,0x00,

    6,      Y_INC,  YUV2RGB_39,         0x00,0x00,0x00,
    
    5,      Y_INC,  DUTY_FINE_TUNE_3E,  0xc0,0x0e,          // For improving display speed
    
    4,      N_INC,  MEAS_HS_LATCH_4E,   0x00,

    5,      Y_INC,  CLAMP_55,           0x04,0x10,

    4,      N_INC,  COLOR_CTRL_5D,      0x03,

    4,      N_INC,  OP_CRC_CTRL_68,     0x88,               // For improving display speed

    6,      Y_INC,  PATTERN_GEN_6C,     0x00,0x83,0x00,

    4,      N_INC,  SD_CTRL_70,         0x00,

	4,      N_INC,  FX_LST_LEN_H_5A,     0x00,              // Disable fix last line function

    6,      Y_INC,  IVS_DELAY_8C,       0x00,0x00,0x00,

    7,      Y_INC,  PLL_DIV_CTRL0_C8,   0x04,0x00,0x20,0x18,


    4,      N_INC,  HS_SCHMITT_TRIG_ED, 0xe3,                       //Set the Schmitt Trigger threshold voltage from 1.0 ~ 1.6V
    4,      N_INC,  SPREAD_SPECTRUM_99, 0x00,                       //Disable Spread Spectrum
    7,      Y_INC,  DPLL_CTRL_D0,       0x28,0x37,0x35,0x04,        //DCLK = 100MHz

    13,     Y_INC,  PLL1_CTRL_D6,       0xf2,0x11,0x00,0x7f,0x30,0x0a,0x04,0x3f,0xff,0x81,

    //4,      N_INC,  ADC_CTRL_E6,        0xb0,
    4,      N_INC,  ADC_CTRL_E6,        0x40,

    4,      N_INC,  DV_BKGD_STA_31,     0x60,

    4,      N_INC,  ADC_FRAME_MODULE_EB, 0x06,

    4,      N_INC,  TMDS_CORRECTION_FF, 0x00,

    9,      Y_INC,  TMDS_OUTPUT_ENA_A0, 0x0f, 0xef,0x8b,0x26,0x35,0x2f,


    0
};

unsigned char code RTD_DDC_TABLE[]  =
{
    5,      Y_INC,  DDC_ENABLE_FC,      0x00,0x00,  // Disable the DDC channel of VGA

    131,    N_INC,  DDC_ACCESS_P_FE,    0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
                                        0x4a,0x8b,0x00,0x00,0x01,0x01,0x01,0x01,
                                        0x1e,0x0c,0x01,0x01,0x0e,0x24,0x1b,0x78,
                                        0xe8,0x8a,0x01,0x9a,0x58,0x52,0x8b,0x28,
                                        0x1e,0x50,0x54,0xff,0xff,0x80,0x61,0x40,
                                        0x61,0x4f,0x61,0x59,0x71,0x4f,0x81,0x40,
                                        0x81,0x59,0x81,0x99,0xa9,0x40,0x00,0x00,
                                        0x00,0xfc,0x00,0x31,0x37,0x27,0x27,0x20,
                                        0x4c,0x43,0x44,0x0a,0x20,0x20,0x20,0x20,
                                        0x00,0x00,0x00,0xfc,0x00,0x4d,0x6f,0x6e,
                                        0x69,0x74,0x6f,0x72,0x0a,0x20,0x20,0x20,
                                        0x20,0x20,0x00,0x00,0x00,0xfd,0x00,0x2b,
                                        0x55,0x14,0x5c,0x0e,0x00,0x0a,0x20,0x20,
                                        0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xff,
                                        0x00,0x30,0x30,0x30,0x30,0x30,0x31,0x0a,
                                        0x20,0x20,0x20,0x20,0x20,0x20,0x00,0xbd,

    4,  N_INC,  DDC_ENABLE_FC,          0x05,       // Enable the DDC channel of VGA
    
#if(TMDS_ENABLE)
    5,      Y_INC,  DDC_ENABLE_BC,      0x00,0x00,  // Disable the DDC channel  of DVI

    131,    N_INC,  DDC_ACCESS_PORT_BE, 0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
                                        0x26,0xCD,0x68,0x46,0x00,0x00,0x00,0x00,
                                        0x23,0x0c,0x01,0x03,0x81,0x24,0x1D,0x78,
                                        0xeF,0x0D,0xC2,0xa0,0x57,0x47,0x98,0x27,                                        
                                        0x12,0x48,0x4F,0xBF,0xEF,0x00,0x81,0x80,
                                        0x81,0x8F,0x61,0x40,0x61,0x59,0x45,0x40,
                                        0x45,0x59,0x31,0x40,0x31,0x59,0xBC,0x34,
                                        0x00,0x98,0x51,0x00,0x2A,0x40,0x10,0x90,

                                        0x13,0x00,0x68,0x22,0x11,0x00,0x00,0x1e,
                                        0x00,0x00,0x00,0xFF,0x00,0x30,0x0A,0x20,
                                        0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
                                        0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x41,
                                        0x53,0x34,0x36,0x33,0x37,0x20,0x20,0x20,
                                        0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFD,
                                        0x00,0x38,0x55,0x18,0x50,0x0E,0x00,0x0A,
  					0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x06,

    4,  N_INC,  DDC_ENABLE_BC,          0x05,       // Enable the DDC channel of DVI
#endif

    0
};

unsigned char code RTD_IO_INI[]  =
{
    4,      N_INC,  TC_ADDR_PORT_95,    0x00,

#if(OUTPUT_BUS == LVDS_TYPE)

#if(BOARD_TYPE == DEMO1_PCB)
    8,      N_INC,  TC_DATA_PORT_96,    0x04,0x10,0x11,0x80,0xfc,
#else
    7,      N_INC,  TC_DATA_PORT_96,    0x04,0x10,0x11,0x80,
#endif
//    7,      N_INC,  TC_DATA_PORT_96,    0x40,0x10,0x11,0x08,
#endif


#if(OUTPUT_BUS == LVDS_TYPE)

#if(LVDS_MAP1 == LVDS_MAP)
   9,      Y_INC,  LVDS_CTRL0_C0,      0x00,0xa3,0x22,0x80,0x80,0x68,
#else
   9,      Y_INC,  LVDS_CTRL0_C0,      0x00,0xa3,0x23,0x80,0x80,0x68,
#endif

#endif


    0
};

// Be Careful !!
// Display window setting in FreeV[] MUST follow the definition of
// 1. DISP_WID and DISP_LEN
// 2. DH_ACT_STA_POS and DH_ACT_END_POS
// 3. DV_ACT_STA_POS and DV_ACT_END_POS
// 4. Background window must be the same as active window.

unsigned char code FreeV[]  =
{

    27, Y_INC,  VDIS_CTRL_20,       0x20 | DISP_BIT | DISPLAY_PORT,                 // Disable display timing

                                    DISP_INV | DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP,
                                    (STD_DH_TOTAL & 0xff), (STD_DH_TOTAL >> 8),     // DH_TOTAL
                                    STD_HSYNC_WIDTH,                                // DH_HS_END
                                    (DH_ACT_STA_POS & 0xff), (DH_ACT_STA_POS >> 8), // DH_BKGD_STA
                                    (DH_ACT_STA_POS & 0xff), (DH_ACT_STA_POS >> 8), // DH_ACT_STA
                                    (DH_ACT_END_POS & 0xff), (DH_ACT_END_POS >> 8), // DH_ACT_END
                                    (DH_ACT_END_POS & 0xff), (DH_ACT_END_POS >> 8), // DH_BKGD_END
                                    (STD_DV_TOTAL & 0xff), (STD_DV_TOTAL >> 8),     // DV_TOTAL
                                    STD_VSYNC_LENGTH,                               // DV_VS_END
                                    (DV_ACT_STA_POS & 0xff), (DV_ACT_STA_POS >> 8) | AUTO_SWITCH, // DV_BKGD_STA
                                    (DV_ACT_STA_POS & 0xff), (DV_ACT_STA_POS >> 8), // DV_ACT_STA
                                    (DV_ACT_END_POS & 0xff), (DV_ACT_END_POS >> 8), // DV_ACT_END
                                    (DV_ACT_END_POS & 0xff), (DV_ACT_END_POS >> 8), // DV_BKGD_END

    4,  N_INC,  VDIS_CTRL_20,       0x23 | DISP_BIT | DISPLAY_PORT,                 // Enable free-run background

    // Force display timing start
    6,  Y_INC,  YUV2RGB_39,         0x00, 0x20 | DCLK_DELAY, 0x04 | DCLK_INV,
    4,  N_INC,  DIS_TIMING0_3A,     0x00 | DCLK_DELAY,

    4,  N_INC,  INT_FLD_DETECT_14,  0x00,
    5,  Y_INC,  IVS_DELAY_8C,       0x00, 0x00,

	4,  N_INC,  SCALE_CTRL_15,      0x00,

    4,  N_INC,  FILTER_CTRL0_1B,    0xc4,


    0
};

unsigned char code OSD_PWUP_INI[]   =
{

    5,  Y_INC,  OSD_ADDR_MSB_90, 0xc0,0x02,
	6,  N_INC,  OSD_DATA_92,     0x03,0x08,0x00,

    0
};


///////////////////////////////////////////////////////////////////////////
//VGA mode detect range
unsigned int code VGA_Mode[][6] =
{
//      HF_min, HF_max, VL_min, VL_max, HF_std, VS+1
    {   0,      0,      0,      0,      0,      0       }, //00:No Signal

    {   764,    806,    620,    636,    781,    2+1     }, //01:VGA [640/720]*350*50Hz
    {   764,    806,    620,    636,    781,    2+1     }, //02:VGA [640/720]*400*50Hz
    {   764,    806,    516,    532,    781,    2+1     }, //03:VGA [640/720]*350*60Hz
    {   764,    806,    516,    532,    781,    2+1     }, //04:VGA [640/720]*400*60Hz

    {   969,    1021,   431,    447,    990,    8+1     }, //05:640*400*56hz
    {   768,    810,    440,    456,    785,    2+1     }, //06:640*350*70hz
    {   764,    806,    440,    456,    781,    2+1     }, //07:720*350*70hz
    {   764,    806,    440,    456,    781,    2+1     }, //08:640*400*70hz
    {   764,    806,    440,    456,    781,    2+1     }, //09:700*400*70hz
    {   635,    670,    436,    452,    649,    3+1     }, //10:640*350*85hz
    {   635,    670,    436,    452,    649,    3+1     }, //11:640*400*85hz
    {   634,    669,    437,    453,    648,    3+1     }, //12:720*400*85hz
    {   764,    806,    620,    636,    781,    2+1     }, //13:640*480*50hz
    {   764,    806,    516,    532,    781,    2+1     }, //14:640*480*60hz
    {   687,    724,    516,    532,    702,    3+1     }, //15:640*480*66hz
    {   635,    670,    511,    527,    649,    3+1     }, //16:640*480*72hz
    {   641,    676,    495,    507,    655,    3+1     }, //17:640*480*75hz
    {   556,    586,    500,    516,    568,    3+1     }, //18:640*480*85hz
    {   684,    721,    616,    632,    699,    2+1     }, //19:800*600*56hz
    {   635,    670,    619,    635,    649,    4+1     }, //20:800*600*60hz
    {   492,    519,    721,    737,    503,    6+1     }, //21:800*600*66hz
    {   500,    527,    657,    673,    511,    6+1     }, //22:800*600*72hz
    {   513,    541,    616,    632,    524,    3+1     }, //23:800*600*75hz
    {   448,    473,    622,    638,    458,    3+1     }, //24:800*600*85hz
    {   483,    510,    658,    674,    494,    3+1     }, //25:832*624*75hz
    {   497,    524,    797,    813,    508,    6+1     }, //26:1024*768*60hz
    {   493,    520,    810,    826,    504,    6+1     }, //27:1024*768*59hz
    {   445,    470,    807,    823,    455,    4+1     }, //28:1024*768*66hz
    {   428,    449,    797,    813,    435,    6+1     }, //29:1024*768*70hz
    {   399,    421,    795,    811,    408,    3+1     }, //30:1024*768*74hz
    {   400,    422,    791,    807,    409,    3+1     }, //31:1024*768*75hz
    {   350,    370,    799,    815,    358,    3+1     }, //32:1024*768*85hz
    {   339,    358,    834,    850,    347,    8+1     }, //33:1024*800*84hz
    {   356,    376,    891,    907,    364,    3+1     }, //34:1152*864*75hz
    {   350,    370,    906,    922,    358,    3+1     }, //35:1152*870*75hz
    {   389,    411,    928,    944,    398,    4+1     }, //36:1152*900*66hz
    {   335,    354,    934,    950,    343,    8+1     }, //37:1152*900*76hz
    {   401,    423,    991,    1007,   410,    3+1     }, //38:1280*960*60hz
    {   280,    295,    1002,   1018,   286,    3+1     }, //39:1280*960*85hz
    {   376,    396,    1057,   1073,   384,    3+1     }, //40:1280*1024*60hz
    {   312,    329,    1060,   1076,   319,    3+1     }, //41:1280*1024*72hz
    {   296,    313,    1057,   1073,   303,    8+1     }, //42:1280*1024*76hz
    {   300,    317,    1057,   1073,   307,    3+1     }, //43:1280*1024*75hz
    {   264,    279,    1063,   1079,   270,    3+1     }, //44:1280*1024*85hz
    {   321,    339,    1241,   1257,   328,    3+1     }, //45:1600*1200*60hz

    {   0,      0,      0,      0,      0,      0       }, //46:Mode reserved 00
    {   0,      0,      0,      0,      0,      0       }, //47:Mode reserved 01
    {   0,      0,      0,      0,      0,      0       }, //48:Mode reserved 02
    {   0,      0,      0,      0,      0,      0       }, //49:Mode reserved 03

    {   642,    1230,   418,    497,    0,      2+1     }, //50:NewMode720x400
    {   535,    1025,   498,    637,    0,      2+1     }, //51:NewMode640x480
    {   428,    820,    618,    785,    0,      2+1     }, //52:NewMode800x600
    {   334,    641,    786,    881,    0,      2+1     }, //53:NewMode1024x768
    {   297,    570,    882,    917,    0,      2+1     }, //54:NewMode1152x864
    {   285,    547,    918,    977,    0,      2+1     }, //55:NewMode1152x900
    {   267,    513,    978,    1041,   0,      2+1     }, //56:NewMode1280x960
    {   251,    481,    1042,   1217,   0,      2+1     }, //57:NewMode1280x1024
    {   292,    559,    1218,   1328,   0,      2+1     }, //58:NewMode1600x1200
};

unsigned int code Mode_Preset[][5]   =
{
    //  DH_TOTAL    DH_ACT_WID  DV_ACT_LEN      DCLK_M/N    IVS_DELAY
    {   1408,       1280,       1024,           0,          0       }, //00:No Signal

    //  VGA confused mode
    {   1408,       1280,       1024,           0,          63      }, //01:VGA [640/720]*350*50Hz
    {   1408,       1280,       1024,           0,          31      }, //02:VGA [640/720]*400*50Hz
    {   1408,       1280,       1024,           0,          63      }, //03:VGA [640/720]*350*60Hz
    {   1408,       1280,       1024,           0,          31      }, //04:VGA [640/720]*400*60Hz

    //  Standard mode
    {   1568,       1280,       1024,           0,          7       }, //05:640*400*56hz
    {   1408,       1280,       1024,           0,          7       }, //06:640*350*70hz
    {   1408,       1280,       1024,           0,          7       }, //07:720*350*70hz
    {   1408,       1280,       1024,           0,          7       }, //08:640*400*70hz
    {   1408,       1280,       1024,           0,          7       }, //09:700*400*70hz
    {   1408,       1280,       896,            0,          7       }, //10:640*350*85hz
    {   1408,       1280,       1024,           0,          7       }, //11:640*400*85hz
    {   1376,       1280,       1024,           0,          7       }, //12:720*400*85hz
    {   1408,       1280,       1024,           0,          31      }, //13:640*480*50hz
    {   1408,       1280,       1024,           0,          7       }, //14:640*480*60hz
    {   1504,       1280,       1024,           0,          7       }, //15:640*480*66hz
    {   1456,       1280,       1024,           0,          7       }, //16:640*480*72hz
    {   1472,       1280,       1024,           0,          3       }, //17:640*480*75hz
    {   1408,       1280,       1024,           0,          7       }, //18:640*480*85hz
    {   1632,       1280,       1024,           0,          3       }, //19:800*600*56hz
    {   1640,       1280,       1024,           0,          7       }, //20:800*600*60hz
    {   1408,       1280,       1024,           0,          7       }, //21:800*600*66hz
    {   1408,       1280,       1024,           0,          7       }, //22:800*600*72hz
    {   1408,       1280,       1024,           0,          3       }, //23:800*600*75hz
    {   1408,       1280,       1024,           0,          7       }, //24:800*600*85hz
    {   1568,       1280,       1024,           0,          7       }, //25:832*624*75hz
    {   1408,       1280,       1024,           0,          7       }, //26:1024*768*60hz
    {   1408,       1280,       1024,           0,          7       }, //27:1024*768*59hz
    {   1408,       1280,       1024,           0,          7       }, //28:1024*768*66hz
    {   1632,       1280,       1024,           0,          7       }, //29:1024*768*70hz
    {   1408,       1280,       1024,           0,          7       }, //30:1024*768*74hz
    {   1408,       1280,       1024,           0,          7       }, //31:1024*768*75hz
    {   1408,       1280,       1024,           0,          7       }, //32:1024*768*85hz
    {   1408,       1280,       1024,           0,          7       }, //33:1024*800*84hz
    {   1408,       1280,       1024,           0,          7       }, //34:1152*864*75hz
    {   1408,       1280,       1024,           0,          7       }, //35:1152*870*75hz
    {   1408,       1280,       1024,           0,          7       }, //36:1152*900*66hz
    {   1408,       1280,       1024,           0,          7       }, //37:1152*900*76hz
    {   1408,       1280,       1024,           0,          7       }, //38:1280*960*60hz
    {   1408,       1280,       1024,           0,          7       }, //39:1280*960*85hz
    {   1408,       1280,       1024,           0,          7       }, //40:1280*1024*60hz
    {   1408,       1280,       1024,           0,          7       }, //41:1280*1024*72hz
    {   1408,       1280,       1024,           0,          7       }, //42:1280*1024*76hz
    {   1408,       1280,       1024,           0,          7       }, //43:1280*1024*75hz
    {   1408,       1280,       1024,           0,          7       }, //44:1280*1024*85hz
    {   1408,       1280,       1024,           0,          7       }, //45:1600*1200*60hz

    //  Reserved mode
    {   1408,       1280,       1024,           0,          0       }, //46:Mode reserved 00
    {   1408,       1280,       1024,           0,          0       }, //47:Mode reserved 01
    {   1408,       1280,       1024,           0,          0       }, //48:Mode reserved 02
    {   1408,       1280,       1024,           0,          0       }, //49:Mode reserved 03

    //  Unknown user mode
    {   1408,       1280,       1024,           0,          3       }, //50:NewMode720x400
    {   1408,       1280,       1024,           0,          3       }, //51:NewMode640x480
    {   1408,       1280,       1024,           0,          3       }, //52:NewMode800x600
    {   1408,       1280,       1024,           0,          3       }, //53:NewMode1024x768
    {   1408,       1280,       1024,           0,          3       }, //54:NewMode1152x864
    {   1408,       1280,       1024,           0,          3       }, //55:NewMode1152x900
    {   1408,       1280,       1024,           0,          3       }, //56:NewMode1280x960
    {   1408,       1280,       1024,           0,          3       }, //57:NewMode1280x1024
    {   1408,       1280,       1024,           0,          3       }, //58:NewMode1600x1200
    
    //  Safe display mode
    {   1408,       1280,       1024,           0,          3       }, //59:Undefined SU mode
    {   1408,       1280,       1024,           0,          3       }, //60:Undefined SD mode
};

///////////////////////////////////////////////////////////////////////////////
//Video Setting
#if (VIDEO_CHIP == VDC_NONE)
// No Video Decoder
unsigned char code RTD_VIDEO_60[]   = { 0 };
unsigned char code RTD_VIDEO_50[]   = { 0 };

#else

#if (VIDEO_CHIP == VDC_SAA7114 || VIDEO_CHIP == VDC_SAA7115 || VIDEO_CHIP == VDC_SAA7118)

#define H_60    0x91//0x70    // For SAA7114/7118
#define H_50    0x97//0x7c    // For SAA7114/7118

#else

#define H_60    0x56    // For SAA7111A
#define H_50    0x5e    // For SAA7111A

#endif

unsigned char code RTD_VIDEO_60[]   =
{
    11, Y_INC,  IPH_ACT_STA_06,     H_60, 0x00, 0xb8, 0x02,
                                    0x14, 0x00, 0xed, 0x00,

    10, Y_INC,  INT_FLD_DETECT_14,  0x14, 0x03, 0x33, 0x8b, 0x40, 0x3b, 0x00,

    4,  N_INC,  FS_FT_DELAY_1E,     0x0f,//0x1a,
    
    7,  Y_INC,  DRW_BSU_40,         0xb8, 0x02, 0xed, 0x00,

    4,  N_INC,  OP_CRC_CTRL_68,     0x48,

    4,  N_INC,  SD_CTRL_70,         0x00 | VIDEO_ICLK_DELAY,

    5,  Y_INC,  IVS_DELAY_8C,       0x00, 0x00,

    29, Y_INC,  VDIS_CTRL_20,       0x28 | DISP_BIT | DISPLAY_PORT | DHS_MASK,

                                    DISP_INV | DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP,
 
                                    0x7e, 0x05,
                                    0x10,
                                    0x20, 0x00,
                                    0x20, 0x00,
                                    0x20, 0x05,
                                    0x20, 0x05,
                                    0x80, 0x04,
                                    0x03,
                                    0x0f, 0x00,
                                    0x0f, 0x00,
                                    0x0f, 0x04,
                                    0x0f, 0x04,
                                    0x13, 0x20,

	7,  Y_INC,  DPLL_CTRL_D0,       0x18, 0x62, 0x3a,0x07,

	5,  Y_INC, DCLK_OFFSET_LSB_9A,  0x70, 0x29,

	4,  N_INC, FX_LST_LEN_H_5A,     0x08,

    4,  N_INC,  VDIS_CTRL_20,       0x2b | DISP_BIT | DISPLAY_PORT | DHS_MASK,

    5,  Y_INC,  VGIP_CTRL_04,       0x0d, 0x00 | VIDEO_LATCH,

    0
};

unsigned char code RTD_VIDEO_50[]=
{
    11, Y_INC,  IPH_ACT_STA_06,     H_50, 0x00, 0xb8, 0x02,
                                    0x18, 0x00, 0x1a, 0x01,

    10, Y_INC,  INT_FLD_DETECT_14,  0x14, 0x03, 0x33, 0x8b, 0x80, 0x46, 0x00,

    4,  N_INC,  FS_FT_DELAY_1E,     0x13,
    
    7,  Y_INC,  DRW_BSU_40,         0xb8, 0x02, 0x1a, 0x01,

    4,  N_INC,  OP_CRC_CTRL_68,     0x48,

    4,  N_INC,  SD_CTRL_70,         0x00 | VIDEO_ICLK_DELAY,

    5,  Y_INC,  IVS_DELAY_8C,       0x00, 0x00,



//  6,  Y_INC,  DPLL_CTRL_D0,       0x11, 0x75, 0x07,

    29, Y_INC,  VDIS_CTRL_20,       0x28 | DISP_BIT | DISPLAY_PORT | DHS_MASK,
                                    DISP_INV | DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP,
                                    0x7e, 0x05,
                                    0x10,
                                    0x20, 0x00,
                                    0x20, 0x00,
                                    0x20, 0x05,
                                    0x20, 0x05,
                                    0x80, 0x04,
                                    0x03,
                                    0x0d, 0x00,
                                    0x0d, 0x00,
                                    0x0d, 0x04,
                                    0x0d, 0x04,
                                    0x17, 0x20,

	7,  Y_INC,  DPLL_CTRL_D0,       0x10, 0x52, 0x3a,0x07,

	5,  Y_INC, DCLK_OFFSET_LSB_9A,  0xc2, 0x29,

	4,  N_INC, FX_LST_LEN_H_5A,     0x08,


    4,  N_INC,  VDIS_CTRL_20,       0x2b | DISP_BIT | DISPLAY_PORT | DHS_MASK,

    5,  Y_INC,  VGIP_CTRL_04,       0x0d, 0x00 | VIDEO_LATCH,

    0
};

#endif

#else 

extern unsigned char code RTD_PWUP_INI[];
extern unsigned char code RTD_DDC_TABLE[];
extern unsigned char code RTD_IO_INI[];

extern unsigned char code FreeV[];
extern unsigned char code OSD_PWUP_INI[];

extern unsigned int code VGA_Mode[][6];
extern unsigned int code Mode_Preset[][5];

extern unsigned char code RTD_VIDEO_60[];
extern unsigned char code RTD_VIDEO_50[];

#endif
