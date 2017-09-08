#define EVEN    0
#define ODD     1

//------ERROR message : SUCCESS(MSB=0)
#define ERROR_SUCCEED       0x00
#define ERROR_SUCCESS_1     0x01
#define ERROR_SUCCESS_2     0x02
#define ERROR_SUCCESS_4     0x04
#define ERROR_SUCCESS_8     0x08
#define ERROR_SUCCESS_16    0x10
#define ERROR_SUCCESS_32    0x20
#define ERROR_SUCCESS_64    0x40
//------ERROR message : ERROR(MSB=1)
#define ERROR_NOTACTIVE     0xf8
#define ERROR_NOISE_TOO_BIG 0xf9
#define ERROR_TOO_SMALL     0xfa
#define ERROR_TOO_BIG       0xfb
#define ERROR_INPUT         0xfc
#define ERROR_TIMEOUT       0xfd
#define ERROR_ABORT         0xff


//------------------------------------------------------------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_TOO_SMALL : Measure Result << ACT_WIDTH  //
//                   ERROR_TOO_BIG   : Measure Result >> ACT_WIDTH  //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                                     Process Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//
//------------------------------------------------------------------//
// Return Message => ERROR_SUCCESS   : Success                      //
//                   ERROR_SUCCESS_1 : Vertical Start > Max         //
//                   ERROR_SUCCESS_2 : Vertical Start < Min         //
//                   ERROR_SUCCESS_4 : Vertical Start/End Fail      //
//                   ERROR_SUCCESS_8 : Horizontal Start > Max       //
//                   ERROR_SUCCESS_16: Horizontal Start < Min       //
//                   ERROR_SUCCESS_32: Horizontal Start/End Fail    //
//                   ERROR_INPUT     : 1. IVS or IHS changed        //
//                                     2. underflow or overflow     //
//                   ERROR_TIMEOUT   : Measure Time_Out             //
//                   ERROR_NOTACTIVE : No Avtive Image              //
//------------------------------------------------------------------//

#define VERTICAL_MARGIN     0x30
#define HORIZONTAL_MARGIN   0x30
#define SELECT_RED          0x01
#define SELECT_GREEN        0x02
#define SELECT_BLUE         0x04
#define SELECT_RGB          (SELECT_RED | SELECT_GREEN | SELECT_BLUE)

#define COLORS_RED          0x02
#define COLORS_GREEN        0x01
#define COLORS_BLUE         0x00
#define COLOR_MAX           0x20
#define COLOR_MIN           0x00

#define PIXEL_1             0x00
#define PIXEL_2             0x01
#define PIXEL_4             0x02
#define PIXEL_8             0x03

#define DEFAULT_BLANK_LINE  0x06

#define IC_REVERSION        0       // 0: For RTD2020 Ver-B and before
                                    // 1: For RTD2020 Ver-C and after

#ifdef	__AUTO__

unsigned char code  ADC_DEFAULT[] =
{   
    9,  Y_INC,   REDGAIN_E0, 0x78, 0x78, 0x78, 0x80, 0x80, 0x80,
    0
};

bit bAutoInProgress = 0;

unsigned int idata  usVer_Start = 0;    // Vertical Start
unsigned int idata  usVer_End   = 0;    // Vertical End
unsigned int idata  usH_Start   = 0;    // Horizontal Start
unsigned int idata  usH_End     = 0;    // Horizontal End

void Wait_Finish(void);
unsigned char Auto_Phase(void);
unsigned char Auto_Phase_Do(unsigned char NM);
//unsigned char Auto_Clock(void);
unsigned char Auto_Clock_Do(unsigned char NM);
unsigned char Auto_Position(void);
unsigned char Auto_Position_Do(unsigned char NM);
unsigned char Auto_Config(void);
unsigned char Auto_Balance(void);

unsigned char Measure_PositionV(unsigned char NM_V);
unsigned char Measure_PositionH(unsigned char NM_H);
unsigned char Measure_PositionN(unsigned char NM);

unsigned char Min_Noise_Margin(void);

unsigned char Tune_Balance(void);
unsigned char Measure_Color(unsigned char color, unsigned char margin);
unsigned char Change_ADC_Gain(unsigned char color, unsigned char delta, unsigned char inc);
unsigned char Change_ADC_Offset(unsigned char color, unsigned char delta, unsigned char inc);

#else

extern bit bAutoInProgress;

extern unsigned int idata   usVer_Start;
extern unsigned int idata   usVer_End;
extern unsigned int idata   usH_Start;
extern unsigned int idata   usH_End;

extern unsigned char Auto_Phase(void);
//extern unsigned char Auto_Clock(void);
extern unsigned char Auto_Position(void);
extern unsigned char Auto_Config(void);
extern unsigned char Auto_Balance(void);

extern unsigned char Measure_Color(unsigned char color, unsigned char margin);

#endif
