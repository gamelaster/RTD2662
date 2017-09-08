#define NEG_LATCH           0x01
#define POS_LATCH           0x00

#define VGA_ICLK_DELAY      0x02

#define TMDS_LATCH          NEG_LATCH
#define TMDS_HS_LATCH       (NEG_LATCH * 0x10)
#define TMDS_ICLK_DELAY     0x00

#if (VIDEO_CHIP == VDC_SAA7115)
#define VIDEO_LATCH         POS_LATCH
#define VIDEO_HS_LATCH      (POS_LATCH * 0x10)
#define VIDEO_ICLK_DELAY    0x00
#else
#define VIDEO_LATCH         NEG_LATCH
#define VIDEO_HS_LATCH      (POS_LATCH * 0x10)
#define VIDEO_ICLK_DELAY    0x00
#endif


#define MAX_ADC_FREQ    140
#define LOW_SPEED_DELAY 3
#define H_OVERSPEC_FREQ 90 // unit : KHz
#define V_OVERSPEC_FREQ 78 // unit : Hz

#define DCLK_SPRED_RANGE    6 //DCLK Spreading range : 0~15


#if (DISP_SIZE == DISP_800x600)
#include "DISP_S1.H"                // Not ready yet
#endif

#if (DISP_SIZE == DISP_1024x768)

#if (PANEL_TYPE == PANEL_CHIMEI)
#include "Display\DISP_N1.H"
#endif 

#if (PANEL_TYPE == PANEL_ACER)
#include "Display\DISP_N2.H"
#endif

#endif  //#if (DISP_SIZE == DISP_1024x768)

#if (DISP_SIZE == DISP_1280x1024)

#if(OUTPUT_BUS == RSDS_TYPE)

#if (PANEL_TYPE == PANEL_CHIMEI)
#include "DISP_BR1.H"
#endif

#if (PANEL_TYPE == PANEL_ACER)
#include "Display\DISP_BR2.H"
#endif

#if (PANEL_TYPE == PANEL_QDI)
#include "Display\DISP_BR3.H"
#endif

#if (PANEL_TYPE == PANEL_HYUNDAI)
#include "Display\DISP_BR4.H"
#endif

#if (PANEL_TYPE == PANEL_INNOUX)
#include "Display\DISP_BR5.H"
#endif

#else //OUTPUT_BUS == LVDS or TTL

#if (PANEL_TYPE == PANEL_CHIMEI)
#include "Display\DISP_B1.H"
#endif
#if (PANEL_TYPE == PANEL_ACER)
#include "Display\DISP_B2.H"
#endif
#if (PANEL_TYPE == PANEL_QDI)
#include "Display\DISP_B5.H"
#endif

#if (PANEL_TYPE == PANEL_HYUNDAI)
#include "Display\DISP_B4.H"
#endif

#if (PANEL_TYPE == PANEL_SHARP)
#include "Display\DISP_B3.H"
#endif

#if (PANEL_TYPE == PANEL_HANNSTAR)
#include "Display\DISP_B6.H" //Handstar 17" 19"
#endif 

#if (PANEL_TYPE == PANEL_CPT)
#include "Display\DISP_B7.H"
#endif

#endif //#if(OUTPUT_BUS == RSDS_TYPE)
#endif //#if (DISP_SIZE == DISP_1280x1024)


#if(BOARD_TYPE == QA_PCB)
#include "PCB\Qa_pcb.h"
#endif

#if(BOARD_TYPE == DEMO_LVDS_A)
#include "PCB\Lvds_pcb.h"
#endif

#if(BOARD_TYPE == DEMO1_PCB)
#include "PCB\2523d1_pcb.h"
#endif

#if(BOARD_TYPE == DEMO2_PCB)
#include "PCB\2523d2_pcb.h"
#endif

#if(BOARD_TYPE == DEMO3_PCB)
#include "PCB\2523d3_pcb.h"
#endif
#include "HEADER\VDC_CFG.H"


#ifdef __MAIN__


unsigned int code   CAP_WIN[][5]    =
{
//      IH_TOTAL    IPH_STA     IPH_WID     IPV_STA     IPV_LEN
    {   0,          0,          0,          0,          0       },  //  0: No signal

    {   800,        144,        640,        152,        350     },  //  1: VGA Mode 350-50Hz
    {   800,        144,        640,        127,        400     },  //  2: VGA Mode 400-50Hz
    {   800,        144,        640,        100,        350     },  //  3: VGA Mode 350-60Hz
    {   800,        144,        640,        75,         400     },  //  4: VGA Mode 400-60Hz

    {   848,        148,        640,        40,         400     },  //  5: Mode 640*400 56Hz     // VGA
    {   800,        144,        640,        61,         350     },  //  6: Mode 640*350 70Hz     // VGA
    {   900,        162,        720,        62,         350     },  //  7: Mode 720*350 70Hz     // VGA
    {   800,        144,        640,        37,         400     },  //  8: Mode 640*400 70Hz     // VGA
    {   900,        162,        720,        36,         400     },  //  9: Mode 720*400 70Hz     // VGA
    {   832,        160,        640,        63,         350     },  // 10: Mode 640*350 85Hz     // VESA
    {   832,        160,        640,        44,         400     },  // 11: Mode 640*400 85Hz     // VESA
    {   936,        180,        720,        45,         400     },  // 12: Mode 720*400 85Hz     // VESA
    {   800,        144,        640,        87,         480     },  // 13: Mode 640*480 50Hz     // VGA
    {   800,        144,        640,        35,         480     },  // 14: Mode 640*480 60Hz     // VESA
    {   864,        160,        640,        42,         480     },  // 15: Mode 640*480 66Hz     // MAC 480-66A
    {   832,        168,        640,        31,         480     },  // 16: Mode 640*480 72Hz     // VESA
    {   840,        184,        640,        19,         480     },  // 17: Mode 640*480 75Hz     // VESA
    {   832,        136,        640,        28,         480     },  // 18: Mode 640*480 85Hz     // VESA
    {   1024,       200,        800,        24,         600     },  // 19: Mode 800*600 56Hz     // VESA
    {   1056,       216,        800,        27,         600     },  // 20: Mode 800*600 60Hz     // VESA
    {   1024,       176,        800,        82,         600     },  // 21: Mode 800*600 66Hz     // MAC 600-66
    {   1040,       184,        800,        29,         600     },  // 22: Mode 800*600 72Hz     // VESA
    {   1056,       240,        800,        24,         600     },  // 23: Mode 800*600 75Hz     // VESA    
    {   1048,       216,        800,        30,         600     },  // 24: Mode 800*600 85Hz     // VESA
    {   1152,       288,        832,        42,         624     },  // 25: Mode 832*624 75Hz     // MAC 624-75
    {   1344,       296,        1024,       35,         768     },  // 26: Mode 1024*768 60Hz    // VESA
    {   1312,       224,        1024,       39,         768     },  // 27: Mode 1024*768 59Hz    // MAC768-60
    {   1328,       288,        1024,       40,         768     },  // 28: Mode 1024*768 66Hz    // COMPAQ 1024
    {   1328,       280,        1024,       35,         768     },  // 29: Mode 1024*768 70Hz    // VESA
//      IH_TOTAL    IPH_STA     IPH_WID     IPV_STA     IPV_LEN
    {   1328,       275,        1024,       25,         768     },  // 30: Mode 1024*768 72Hz    // VESA	//anson 05_0321 add
    {   1328,       272,        1024,       33,         768     },  // 31: Mode 1024*768 74Hz    // MAC 768-75
//      IH_TOTAL    IPH_STA     IPH_WID     IPV_STA     IPV_LEN
    {   1312,       272,        1024,       31,         768     },  // 32: Mode 1024*768 75Hz    // VESA
    {   1376,       304,        1024,       39,         768     },  // 33: Mode 1024*768 85Hz    // VESA
    {   1312,       264,        1024,       41,         800     },  // 34: Mode 1024*800 84Hz    // SUN 800-84
    {   1600,       384,        1152,       35,         864     },  // 35: Mode 1152*864 75Hz    // VESA
    {   1456,       272,        1152,       42,         870     },  // 36: Mode 1152*870 75Hz    // MAC 870-75
    {   1504,       322,        1152,       35,         900     },  // 37: Mode 1152*900 66Hz    // SUN 900-66
    {   1472,       304,        1152,       41,         900     },  // 38: Mode 1152*900 76Hz    // SUN 900-76
    {   1800,       424,        1280,       39,         960     },  // 39: Mode 1280*960 60Hz    // VESA
    {   1512,       336,        1120,       50,         960     },  // 40: Mode 1280*960 85Hz    // VESA (Capture width 1280->1120, H Total 1728->1512, pixel clock 148.5M -> 129.9M)
    {   1688,       360,        1280,       41,         1024    },  // 41: Mode 1280*1024 60Hz   // VESA
    {   1728,       380,        1280,       42,         1024    },  // 42: Mode 1280*1024 72Hz   // WS-SGI
    {   1664,       352,        1280,       40,         1024    },  // 43: Mode 1280*1024 76Hz   // SUN 1024-76
    {   1688,       392,        1280,       41,         1024    },  // 44: Mode 1280*1024 75Hz   // VESA
    {   1512,       336,        1120,       47,         1024    },  // 45: Mode 1280*1024 85Hz   // VESA (Capture width 1280->1120, H Total 1728->1512, pixel clock 157.5M -> 137.8M)
    {   1728,       396,        1280,       49,         1200    },  // 46: Mode 1600*1024 60Hz   // VESA (Capture width 1600->1280, H Total 2160->1728, pixel clock 162.0M -> 129.6M)

    {   0,          0,          0,          0,          0       },  // 47: Mode reserved 00
    {   0,          0,          0,          0,          0       },  // 48: Mode reserved 01
    {   0,          0,          0,          0,          0       },  // 49: Mode reserved 02
    {   0,          0,          0,          0,          0       },  // 50: Mode reserved 03

    {   900,        162,        720,        17,         400     },  // 51: User Mode 720*400
    {   840,        180,        640,        17,         480     },  // 52: User Mode 640*480
    {   1056,       240,        800,        17,         600     },  // 53: User Mode 800*600
    {   1344,       296,        1024,       17,         768     },  // 54: User Mode 1024*768
    {   1536,       352,        1152,       17,         864     },  // 55: User Mode 1152*864
    {   1472,       304,        1152,       17,         900     },  // 56: User Mode 1152*900
    {   1728,       396,        1280,       17,         960     },  // 57: User Mode 1280*960
    {   1688,       380,        1280,       17,         1024    },  // 58: User Mode 1280*1024
    {   1728,       396,        1280,       17,         1200    },  // 59: User Mode 1600*1200
    {   1312,       272,        1024,       17,         0       },  // 60: Undefined SU mode (59)
    {   1312,       272,        1024,       17,         0       },  // 61: Undefined SD mode (60)
};

// For user-mode whose ADC setting may be over-speed
// 0 : User mode 1152x864
// 1 : User mode 1152x900
// 2 : User mode 1280x960
// 3 : User mode 1280x1024
// 4 : User mode 1600x1200
unsigned int code   ADC_SD_SET[][3] =
{
//      ADC_CLOCK   IPH_STA     IPH_WID
    {   1248,       286,        936     },  // Capture width 1152->936, H Total 1536->1248
    {   1196,       247,        936     },  // Capture width 1152->936, H Total 1472->1196
    {   1296,       288,        960     },  // Capture width 1280->960, H Total 1728->1296
    {   1296,       288,        960     },  // Capture width 1280->960, H Total 1728->1296 (*Not 1688->1296)
    {   1512,       347,        1120    },  // Capture width 1600->1120, H Total 2160->1512
};
/////////////////////////////////////////////////////////////////////////////////////////
// When enable the DCLK spread spectrum, due to the different spreading range will result the different DCLK offset
// Acoording to the spreading range to make the below DCLK offset compensation

unsigned char code  DCLK_OFFSET[16] =
{   0, 1, 1, 1, 2, 3, 3, 4, 5, 7, 7, 7, 11, 13, 14, 17  };

/////////////////////////////////////////////////////////////////////////////////////////

unsigned char code VGA_INI_SS[]     =   //VGA SS
{
    5,  Y_INC,  VGIP_CTRL_04,       0x00,0x40,
    6,  Y_INC,  SYNC_CTRL_4A,       0x00,0x14,0x00,
    0
};

unsigned char code VGA_INI_CS[]     =   //VGA CS
{
    5,  Y_INC,  VGIP_CTRL_04,       0x00,0x40,
    6,  Y_INC,  SYNC_CTRL_4A,       0x00,0x55,0x20,
    4,  N_INC,  MEAS_HI_52,         0x80,
    0
};

unsigned char code VGA_INI_SOG[]    =   //VGA SOG
{
    5,  Y_INC,  VGIP_CTRL_04,       0x00,0x40,
    6,  Y_INC,  SYNC_CTRL_4A,       0x00,0x57,0x20,
    4,  N_INC,  MEAS_HI_52,         0x80,
    0
};

unsigned char code DVI_INI[]        =   //DVI
{
    5,  Y_INC,  VGIP_CTRL_04,       0x10,0x00 | TMDS_LATCH,
    6,  Y_INC,  SYNC_CTRL_4A,       0x00,0x10,0x00,
    4,  N_INC,  MEAS_HS_LATCH_4E,   TMDS_HS_LATCH,
    4,  N_INC,  ANG_PERFORMANCE2_A3, 0x36,
    4,  N_INC,  TMDS_TEST_MODE1_B3,  0x0f,
    0
};

unsigned char code VIDEO_INI[]      =   //VIDEO
{
    5,  Y_INC,  VGIP_CTRL_04,       0x0c,0x00 | VIDEO_LATCH,
    4,  N_INC,  INT_FLD_DETECT_14,  0x1e,
    6,  Y_INC,  SYNC_CTRL_4A,       0x00,0x10,0x00,
    4,  N_INC,  MEAS_HS_LATCH_4E,   VIDEO_HS_LATCH,
    0
};

unsigned char code VGA_SET_SS[]     =   //VGA SS
{

    4,  N_INC,  VGIP_CTRL_04,       0x00,
    4,  N_INC,  VGIP_SIGINV_05,     0x40,
    5,  Y_INC,  SYNC_CTRL_4A,       0x00,0x14,

    4,  N_INC,  MEAS_HI_52,      0x00,

    0
};

unsigned char code VGA_SET_CS[]     =   //VGA CS
{
//    4,  N_INC,  VGIP_CTRL_04,       0x04,
    4,  N_INC,  VGIP_SIGINV_05,     0x40,
    5,  Y_INC,  SYNC_CTRL_4A,       0x00,0x55,

    4,  N_INC,  MEAS_HI_52,      0x80,

    0
};

unsigned char code VGA_SET_SOG[]    =   //VGA SOG
{
//    4,  N_INC,  VGIP_CTRL_04,       0x04,
    4,  N_INC,  VGIP_SIGINV_05,     0x40,
    5,  Y_INC,  SYNC_CTRL_4A,       0x00,0x57,

    4,  N_INC,  MEAS_HI_52,      0x80,

    0
};


#if(LVDS_TYPE == OUTPUT_BUS)
unsigned char code LVDS_POWERUP[]      =
{
#if(DOUBLE_PORT == DISPLAY_PORT)
     4, N_INC, LVDS_CTRL0_C0,      0xe0,
#else  //LVDS from even port, if from odd port, the below value should be 0xa0
     4, N_INC, LVDS_CTRL0_C0,      0xc0,
#endif

    0
};
unsigned char code LVDS_POWERDOWN[]  =
{
     4, N_INC, LVDS_CTRL0_C0,       0x00,
	 	
     0
};
#endif

/////////////////////////////////////////////////////////////////////////////////////////

unsigned char code Palette_Open[]   =
{
    4,  N_INC,  OVL_LUT_ADDR_6E,    0x80,   // Enable LUT access
    0
};
unsigned char code Palette_Close[]  =
{
    4,  N_INC,  OVL_LUT_ADDR_6E,    0x00,   // Disable LUT access
    0
};

#if (0)

// For OSD animetion

unsigned char code Palette_1[]  =
{
    51, N_INC,  OVL_PORT_6F,    0x00,0x00,0x00, 0x00,0x00,0xa8,     // 0000/0001
                                0x00,0x98,0x00, 0x20,0x60,0x80,     // 0010/0011
                                0x98,0x00,0x00, 0x60,0x00,0x00,     // 0100/0101
                                0x98,0x98,0x00, 0xa8,0xa8,0xa8,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xd8,     // 1000/1001
                                0x00,0xd8,0x00, 0x38,0xd8,0xd8,     // 1010/1011
                                0xd8,0x00,0x00, 0xd8,0x00,0xd8,     // 1100/1101
                                0xd8,0xd8,0x00, 0xd8,0xd8,0xd8,     // 1110/1111
    0
};
unsigned char code Palette_2[]  =
{
    51, N_INC,  OVL_PORT_6F,    0x00,0x00,0x00, 0x00,0x00,0xac,     // 0000/0001
                                0x00,0x9c,0x00, 0x28,0x68,0x88,     // 0010/0011
                                0x9c,0x00,0x00, 0x68,0x08,0x08,     // 0100/0101
                                0x9c,0x9c,0x00, 0xac,0xac,0xac,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xdc,     // 1000/1001
                                0x00,0xdc,0x00, 0x3c,0xdc,0xdc,     // 1010/1011
                                0xdc,0x00,0x00, 0xdc,0x00,0xdc,     // 1100/1101
                                0xdc,0xdc,0x00, 0xdc,0xdc,0xdc,     // 1110/1111
    0
};
unsigned char code Palette_3[]  =
{
    51, N_INC,  OVL_PORT_6F,    0x00,0x00,0x00, 0x00,0x00,0xb0,     // 0000/0001
                                0x00,0xa0,0x00, 0x30,0x70,0x90,     // 0010/0011
                                0xa0,0x00,0x00, 0x70,0x10,0x10,     // 0100/0101
                                0xa0,0xa0,0x00, 0xb0,0xb0,0xb0,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xe0,     // 1000/1001
                                0x00,0xe0,0x00, 0x40,0xe0,0xe0,     // 1010/1011
                                0xe0,0x00,0x00, 0xe0,0x00,0xe0,     // 1100/1101
                                0xe0,0xe0,0x00, 0xe0,0xe0,0xe0,     // 1110/1111
    0
};
unsigned char code Palette_4[]  =
{
    51, N_INC,  OVL_PORT_6F,    0x00,0x00,0x00, 0x00,0x00,0xb8,     // 0000/0001
                                0x00,0xa8,0x00, 0x36,0x76,0x96,     // 0010/0011
                                0xa8,0x00,0x00, 0x74,0x14,0x14,     // 0100/0101
                                0xa8,0xa8,0x00, 0xb8,0xb8,0xb8,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xe8,     // 1000/1001
                                0x00,0xe8,0x00, 0x48,0xe8,0xe8,     // 1010/1011
                                0xe8,0x00,0x00, 0xe8,0x00,0xe8,     // 1100/1101
                                0xe8,0xe8,0x00, 0xe8,0xe8,0xe8,     // 1110/1111
    0
};
unsigned char code Palette_5[]  =
{
    51, N_INC,  OVL_PORT_6F,    0x00,0x00,0x00, 0x00,0x00,0xc0,     // 0000/0001
                                0x00,0xb0,0x00, 0x3c,0x7c,0x9c,     // 0010/0011
                                0xb0,0x00,0x00, 0x78,0x18,0x18,     // 0100/0101
                                0xb0,0xb0,0x00, 0xc0,0xc0,0xc0,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xf0,     // 1000/1001
                                0x00,0xf0,0x00, 0x50,0xf0,0xf0,     // 1010/1011
                                0xf0,0x00,0x00, 0xf0,0x00,0xf0,     // 1100/1101
                                0xf0,0xf0,0x00, 0xf0,0xf0,0xf0,     // 1110/1111
    0
};
unsigned char code Palette_6[]  =
{
    51, N_INC,  OVL_PORT_6F,    0x00,0x00,0x00, 0x00,0x00,0xc8,     // 0000/0001
                                0x00,0xb8,0x00, 0x42,0x82,0xa2,     // 0010/0011
                                0xb8,0x00,0x00, 0x7c,0x1c,0x1c,     // 0100/0101
                                0xb8,0xb8,0x00, 0xc8,0xc8,0xc8,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xf8,     // 1000/1001
                                0x00,0xf8,0x00, 0x58,0xf8,0xf8,     // 1010/1011
                                0xf8,0x00,0x00, 0xf8,0x00,0xf8,     // 1100/1101
                                0xf8,0xf8,0x00, 0xf8,0xf8,0xf8,     // 1110/1111
    0
};

#endif

unsigned char code Palette_7[]  =
{
    51, N_INC,  OVL_PORT_6F,    /*0x00,0x00,0x00, 0x00,0x00,0xd0,     // 0000/0001
                                0x00,0xc0,0x00, 0x48,0x88,0xa8,     // 0010/0011
                                0xc0,0x00,0x00, 0x80,0x20,0x20,     // 0100/0101
                                0xc0,0xc0,0x00, 0xd0,0xd0,0xd0,     // 0110/0111
                                0x00,0x00,0x00, 0x00,0x00,0xff,     // 1000/1001
                                0x00,0xff,0x00, 0x60,0xff,0xff,     // 1010/1011
                                0xff,0x00,0x00, 0xff,0x00,0xff,     // 1100/1101
                                0xff,0xff,0x00, 0xff,0xff,0xff,     // 1110/1111
*/
    0x9F,0xED,0xAB,0xFF,0xFF,0xFF,
    0xFF,0x00,0x00,0x00,0x00,0xFF,
    0x00,0x00,0x00,0xFF,0xFF,0x00,
    0x00,0xFF,0xFF,0xFF,0x00,0xFF,
    0xFF,0x80,0x00,0xC0,0xC0,0xC0,
    0x80,0x80,0x80,0x7A,0xB4,0x81,
    0x56,0xF0,0x6D,0xCD,0xF8,0xD4,
    0x9F,0xED,0xAB,0xB4,0xF1,0xBF,
    0
};


#else   // #else of #ifdef __MAIN__

extern unsigned int code CAP_WIN[][5];
extern unsigned int code ADC_SD_SET[][3];

extern unsigned char code VGA_INI_SS[];
extern unsigned char code VGA_INI_CS[];
extern unsigned char code VGA_INI_SOG[];
extern unsigned char code VIDEO_INI[];
extern unsigned char code DVI_INI[];
extern unsigned char code VGA_SET_SS[];
extern unsigned char code VGA_SET_CS[];
extern unsigned char code VGA_SET_SOG[];
extern unsigned char code LVDS_POWERUP[];
extern unsigned char code LVDS_POWERDOWN[];
extern unsigned char code Palette_Open[];
extern unsigned char code Palette_Close[]; 
extern unsigned char code Palette_1[];
extern unsigned char code Palette_2[];
extern unsigned char code Palette_3[];
extern unsigned char code Palette_4[];
extern unsigned char code Palette_5[];
extern unsigned char code Palette_6[];
extern unsigned char code Palette_7[];
extern unsigned char code DCLK_OFFSET[16];

#endif
