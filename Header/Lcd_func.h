#include "HEADER\Main_def.h"
// Definitions for Wait_For_Event Function
#define EVENT_IVS               0x01
#define EVENT_IEN_START         0x02
#define EVENT_IEN_STOP          0x04
#define EVENT_DVS               0x08
#define EVENT_DEN_START         0x10
#define EVENT_DEN_STOP          0x20
#define EVENT_UNDERFLOW         0x40
#define EVENT_OVERFLOW          0x80

#define EVENT_INPUT             EVENT_IVS | EVENT_IEN_START | EVENT_IEN_STOP
#define EVENT_DISPLAY           EVENT_DVS | EVENT_DEN_START | EVENT_DEN_STOP

typedef struct _GLOBAL_USER_DATA0
{
    unsigned char CONTRAST;         //E0H
    unsigned char BRIGHT;           //E1H
    unsigned char RTD_R_CONTRAST;   //E2H
    unsigned char RTD_G_CONTRAST;   //E3H
    unsigned char RTD_B_CONTRAST;   //E4H
    unsigned char RTD_R_BRIGHT;     //E5H
    unsigned char RTD_G_BRIGHT;     //E6H
    unsigned char RTD_B_BRIGHT;     //E7H
}
GLOBAL_USER_DATA0, *LP_GLOBAL_USER_DATA0;

typedef struct _GLOBAL_USER_DATA1
{
    unsigned char FUNCTION;         //E8H   //bit 7     [ Reserved        ]
                                            //bit 6~5   [ Gamma           ]
                                            //bit 4     [ Mode Select   0:720x400  1:640x400 ] 
                                            //bit 3     [ Power status    ]
                                            //bit 2~0   [ Language        ]
                                            //            0-English
                                            //            1-German
                                            //            2-French
                                            //            3-Italian
                                            //            4-Spanish
                                            //            5-Traditional Chinese
                                            //            6-Simple Chinese
                                            //            7-Japaness

    unsigned char INPUT_SOURCE;     //E9H   //bit 7~5   [ Osd translucent]
                                            //          [ 000 :          Disable               ]
  										    //          [ 001 ~ 111 :    level 1/8 ~ 7/8       ] 
                                            //bit 6     [ Reserved  ]
											//bit 5     [ Reserved  ]
											//bit 4~3   [ 00 :          C1    9300             ]
											//          [ 01 :          C2    6500             ]
											//          [ 02 :          C3    5800             ]
                                            //          [ 03 :          user mode              ]
                                            //bit 2~0   [ Input Source  0:RGB  1:AV  2:S-VIDEO ]
                                            //          [               3:YUV  4:TV            ] 
    unsigned char FILTER;           //EAH    
    unsigned int  OSD_POSH;         //EBH	
    unsigned char OSD_POSV;         //ECH
    unsigned char OSD_TIMEOUT;      //EDH  

    unsigned char OSD_INPUT;	    //EEH										//anson 05_0314
									// bit 7~6   [ Reserved  ]
									// bit 5     [ New_Mode :  0-->NO , 1-->YES ]
									// bit 4~0   [ Reserved  ]
}
GLOBAL_USER_DATA1, *LP_GLOBAL_USER_DATA1;


typedef struct _GLOBAL_USER_DATA2
{
    unsigned char AD_R_GAIN;        //F0H   //ADC Color Gain R
    unsigned char AD_G_GAIN;        //F1H   //ADC Color Gain G
    unsigned char AD_B_GAIN;        //F2H   //ADC Color Gain B
    unsigned char AD_R_OFFSET;      //F3H   //ADC Color Offset R
    unsigned char AD_G_OFFSET;      //F4H   //ADC Color Offset G
    unsigned char AD_B_OFFSET;      //F5H   //ADC Color Offset B
}
GLOBAL_USER_DATA2, *LP_GLOBAL_USER_DATA2;

typedef struct _GLOBAL_USER_DATA3
{
    unsigned char VOLUME;           //F8H
    unsigned char CURR_CHANNEL;     //F9H
    unsigned char PREV_CHANNEL;     //FAH
    unsigned char TV_SETTING;       //FBH  
								//bit 7~6   Reserved
								//bit 5     Burning mode			//anson
								//bit 4     Reserved
								//bit 3     factory mode			//anson
								//bit 2     [ SOUND     0: Stereo   ]
								//          [           1: SAP      ]
								//bit 1     [           0: Normal   ]
								//          [           1: Mute     ]
								//bit 0     [ SYSTEM    0: Air TV   ]
								//          [           1: CATV     ]

    unsigned char SPREAD;			//FCH			//anson
}
GLOBAL_USER_DATA3, *LP_GLOBAL_USER_DATA3;

typedef struct _GLOBAL_USER_DATA4    //Color temperature 9300¡B6500¡B5800
{
	unsigned char C1_R;              //D0H      Color temperature 9300 Red
	unsigned char C1_G;              //D1H      Color temperature 9300 Green
	unsigned char C1_B;              //D2H      Color temperature 9300 Blue
	unsigned char C2_R;              //D3H      Color temperature 6500 Red
	unsigned char C2_G;              //D4H      Color temperature 6500 Green
	unsigned char C2_B;              //D5H      Color temperature 6500 Blue
	unsigned char C3_R;              //D6H      Color temperature 5800 Red
	unsigned char C3_G;              //D7H      Color temperature 5800 Green
	unsigned char C3_B;              //D8H      Color temperature 5800 Blue
}
GLOBAL_USER_DATA4, *LP_GLOABL_USER_DATA4;

typedef struct _RGB_MODE_USER_DATA      //RGB MODE
{
    unsigned char H_POSITION;   //(0)
    unsigned char V_POSITION;   //(1)
    unsigned char CLOCK;        //(2)
    unsigned char PHASE;        //(3)
}
RGB_MODE_USER_DATA, *LP_RGB_MODE_USER_DATA;

typedef struct _VIDEO_MODE_USER_DATA    //VIDEO MODE
{
    unsigned char VBRIGHT;      //(0)
    unsigned char VCONTRAST;    //(1)
    unsigned char VSATURATION;  //(2)
    unsigned char VHUE;         //(3)
}
VIDEO_MODE_USER_DATA, *LP_VIDEO_MODE_USER_DATA;


#ifdef	__FUNC__

// Global Variable

// Private :

unsigned char code INIT_EEPROM0[]    =
{
    19, ADDR_EROM1, 0xE0,   0x32,           // E0H : CONTRAST
                            0x3c,           // E1H : BRIGHT
                            0x32,           // E2H : RTD_R_CONTRAST
                            0x32,           // E3H : RTD_G_CONTRAST
                            0x32,           // E4H : RTD_B_CONTRAST
                            0x32,           // E5H : RTD_R_BRIGHT
                            0x32,           // E6H : RTD_G_BRIGHT
                            0x32,           // E7H : RTD_B_BRIGHT

                            0x00,           // E8H : FUNCTION
                            0x38,           // E9H : INPUT_SOURCE
                            0x02,           // EAH : FILTER
                            OSD_HMID,       // EBH : OSD_POSH
                            OSD_VMID,       // ECH : OSD_POSV
                            0x14,           // EDH : OSD_TIMEOUT
                            0x00,           // EEH : OSD_INPUT		//anson 05_0314
                            0x00,           // EFH : Reserved
};

unsigned char code INIT_EEPROM1[]    =
{
    19, ADDR_EROM1, 0xF0,		0x80,           // F0H : AD_R_GAIN 
							0x80,           // F1H : AD_G_GAIN 
							0x80,           // F2H : AD_B_GAIN 
							0x80,           // F3H : AD_R_OFFSET 
							0x80,           // F4H : AD_G_OFFSET 
							0x80,           // F5H : AD_B_OFFSET 
							0x00,           // F6H : Reserved
							0x00,           // F7H : Reserved

							0x0a,           // F8H : VOLUME
							0x07,           // F9H : CURR_CHANNEL 
							0x07,           // FAH : PREV_CHANNEL
							0x00,           // FBH : TV_SETTING
							0x06,           // FCH : SPREAD		//anson
							0x00,           // FDH : Reserved
							0x03,           // FEH : Version Code
							0x22,           // FFH : Release Code
};

unsigned char code INIT_EEPROM2[]    =
{
    19, ADDR_EROM1, 0xD0,		0x33,	     // D0H : Color temperature 9300 Red
							0x2e,           // D1H : Color temperature 9300 Green
							0x2e,           // D2H : Color temperature 9300 Blue
							0x2a,           // D3H : Color temperature 6500 Red
							0x34,           // D4H : Color temperature 6500 Green
							0x32,           // D5H : Color temperature 6500 Blue
							0x28,           // D6H : Color temperature 5800 Red
							0x36,           // D7H : Color temperature 5800 Green

							0x36,           // D8H : Color temperature 5800 Blue
							0x00,           // D9H : Reserved
							0x00,           // DAH : Reserved
							0x00,           // DBH : Reserved
							0x00,           // DCH : Reserved
							0x00,           // DDH : Reserved
							0x00,           // DEH : Reserved
							0x00,           // DFH : Reserved
};

// Public :
GLOBAL_USER_DATA0   data    stGUD0;
GLOBAL_USER_DATA1   data    stGUD1;
GLOBAL_USER_DATA2   data    stGUD2;
GLOBAL_USER_DATA3   data    stGUD3;
GLOBAL_USER_DATA4   data    stGUD4;
RGB_MODE_USER_DATA  data    stMUD;

unsigned int  idata usIPH_ACT_STA   = 0;
unsigned int  idata usIPV_ACT_STA   = 0;
unsigned int  idata usIPH_ACT_WID   = 0;
unsigned int  idata usIPV_ACT_LEN   = 0;

unsigned int  idata usADC_Clock     = 0;
unsigned int  idata usDH_Total      = 0;
unsigned int  idata usDV_Total      = 0;
unsigned char idata ucDV_Delay      = 0;

unsigned char idata ucV_Max_Margin  = 0;
unsigned char idata ucV_Min_Margin  = 0;
unsigned char idata ucH_Max_Margin  = 0;
unsigned char idata ucH_Min_Margin  = 0;
unsigned char   idata   UartNum        = 0;
unsigned char idata  UartData[4];	// data array for RTD/I2C R/W


// Function Prototype
void SetMute(bit val);
void SetVolume();

void WriteGamma(unsigned char code *arrayR, unsigned char code *arrayG, unsigned char code *arrayB);
void WriteDither(unsigned char code *array,bit new_dither);
void WriteSU_COEF(unsigned char code *arrayH, unsigned char code *arrayV);

void Set_H_Position(void);
void Set_V_Position(void);
void Set_Clock(void);
void Set_Phase(unsigned char phase);
void Set_Bright_Contrast(void);
void Set_Gamma(void);
void Set_Dithering(void);
void Sharpness(void);
void Set_Mode_Params(void);

void SetADC_VCO(unsigned char ucRate);
void SetADC_Gain(void);
void SetADC_Offset(void);
void SetADC_GainOffset(void);
#if(VIDEO_CHIP != VDC_NONE)
void SetVDC_Color(void);
#endif

void Wait_For_Event(unsigned char event);

//unsigned char Get_PE_Info(unsigned int lines);

void Save_GUD0(void);
void Load_GUD0(void);
void Save_GUD1(void);
void Load_GUD1(void);
void Save_GUD2(void);
void Load_GUD2(void);
void Save_GUD3(void);
void Load_GUD3(void);
void Load_GUD4(void);
void Save_GUD4(void);

void Save_MUD(unsigned char mode_num);
void Load_MUD(unsigned char mode_num);
void Init_GUD(void);
void Init_MUD(void);
void Check_EEPROM(void);
void Free_Background(void);
void Reset_Mode(void);

////////////////////////////////////////////////////////////////////////////////////////////
//	anson add
////////////////////////////////////////////////////////////////////////////////////////////
void Set_Spread(void);
void Init_FACTORY(void);
void Init_FRecall(void);
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

#if (TV_NONE != TV_CHIP)
void Set_TV_Channel();
void Prev_Channel();
void Next_Channel();
#endif

#if (KINGMICE)
unsigned char code  ucROM_A0    _at_ 0xffa0;    // Internal ROM
unsigned char code  ucROM_A1    _at_ 0xffa1;    // Internal ROM
unsigned char code  ucROM_A2    _at_ 0xffa2;    // Internal ROM
unsigned char code  ucROM_A3    _at_ 0xffa3;    // Internal ROM
unsigned char code  ucROM_A4    _at_ 0xffa4;    // Internal ROM
unsigned char code  ucROM_A5    _at_ 0xffa5;    // Internal ROM
unsigned char xdata ucPRN_7     _at_ 0xffaa;    // External RAM

#endif

#if (GETREGISTER)
unsigned char data  ucGETCHIP   _at_ 0x7c;      //READ: 01:RTD 02:ADC 03:VIDEO 04:EEPROM0 05:EEPROM1
                                                //Write:11:RTD 12:ADC 13:VIDEO 14:EEPROM0 15:EEPROM1
unsigned char data  ucGETADDR   _at_ 0x7d;      //Register Address
unsigned char data  ucGETDATA0  _at_ 0x7e;      //data0(write only 1 data)
unsigned char data  ucGETDATA1  _at_ 0x7f;      //data1(read 2 data)
#endif


#else

// Global Variable

// Public :
extern GLOBAL_USER_DATA0    data    stGUD0;
extern GLOBAL_USER_DATA1    data    stGUD1;
extern GLOBAL_USER_DATA2    data    stGUD2;
extern GLOBAL_USER_DATA3    data    stGUD3;
extern GLOBAL_USER_DATA4    data    stGUD4;
extern RGB_MODE_USER_DATA   data    stMUD;

extern unsigned int  idata  usIPH_ACT_STA;
extern unsigned int  idata  usIPV_ACT_STA;
extern unsigned int  idata  usIPH_ACT_WID;
extern unsigned int  idata  usIPV_ACT_LEN;

extern unsigned int  idata  usADC_Clock;
extern unsigned int  idata  usDH_Total;
extern unsigned int  idata  usDV_Total;
extern unsigned char idata  ucDV_Delay;

extern unsigned char idata  ucV_Max_Margin;
extern unsigned char idata  ucV_Min_Margin;
extern unsigned char idata  ucH_Max_Margin;
extern unsigned char idata  ucH_Min_Margin;
extern unsigned char   idata   UartNum;
extern unsigned char   idata   UartData[4];	


// Function Prototype
extern void SetMute(bit val);
extern void SetVolume();

extern void WriteGamma(unsigned char code *arrayR, unsigned char code *arrayG, unsigned char code *arrayB);
extern void WriteDither(unsigned char code *array);
extern void WriteSU_COEF(unsigned char code *arrayH, unsigned char code *arrayV);

extern void Set_H_Position(void);
extern void Set_V_Position(void);
extern void Set_Clock(void);
extern void Set_Phase(unsigned char phase);
extern void Set_Bright_Contrast(void);
extern void Set_Gamma(void);
extern void Set_Dithering(void);
extern void Sharpness(void);
extern void Set_Mode_Params(void);

extern void SetADC_VCO(unsigned char ucRate);
extern void SetADC_Gain(void);
extern void SetADC_Offset(void);
extern void SetADC_GainOffset(void);
#if(VIDEO_CHIP != VDC_NONE)
extern void SetVDC_Color(void);
#endif

extern void Wait_For_Event(unsigned char event);

//extern unsigned char Get_PE_Info(unsigned int lines);

extern void Save_GUD0(void);
extern void Load_GUD0(void);
extern void Save_GUD1(void);
extern void Load_GUD1(void);
extern void Save_GUD2(void);
extern void Load_GUD2(void);
extern void Save_GUD3(void);
extern void Load_GUD3(void);
extern void Save_GUD4(void);	//ANSON
extern void Load_GUD4(void);	//ANSON
extern void Save_MUD(unsigned char mode_num);
extern void Load_MUD(unsigned char mode_num);
extern void Init_GUD(void);
extern void Init_MUD(void);
extern void Check_EEPROM(void);
extern unsigned char code INIT_EEPROM2[]; 
extern void RTD_Test(void);
extern void Free_Background(void);
extern void Reset_Mode(void);
////////////////////////////////////////////////////////////////////////////////////////////
//	anson add
////////////////////////////////////////////////////////////////////////////////////////////
extern void Set_Spread(void);
extern void Init_FACTORY(void);
extern void Init_FRecall(void);
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


#if (TV_NONE != TV_CHIP)
extern void Set_TV_Channel();
extern void Prev_Channel();
extern void Next_Channel();
#endif

#endif
