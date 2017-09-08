#include "HEADER\Timer.h"
#include "HEADER\Power_Ctrl.h"
#include "HEADER\Mode_Detect.h"

#define MODE_DETECT_FREQ        2   // Detect Mode every (2 + 1) * 20ms = 60ms
#define VGA_SEARCH_TIMES        3
#define DVI_SEARCH_TIMES        3
#define VIDEO_SEARCH_TIMES      5
#define NO_MODE_TIMES           5
#define NO_COLOR_TIMES          20
#define SYNC_FAIL_TIMES         1

#define STATE_POWERUP           0       // Reserved for system use
#define STATE_SOURCECHANGE      1       // Reserved for system use
#define STATE_MODECHANGE        2       // Reserved for system use
#define STATE_POWERDOWN         3       // Reserved for system use

#define BEGIN_POWERUP           350     // Task State0 Period : (500 - 350) * 20ms = 3sec
#define BEGIN_SOURCECHANGE      350       // Task State0 Period : (500 - 350) * 20ms = 3sec
#define BEGIN_MODECHANGE        200     // Task State1 Period : (350 - 250) * 20ms = 2sec
#define BEGIN_SHOWHINT          100      // Task State2 Period : (250 -   0) * 20ms = 5sec
#define OSD_TO_HINT_DELAY       5       // The delay from OSD window closed to 'No Signal' hint text shown
/*   //anson
#define BEGIN_POWERUP           500     // Task State0 Period : (500 - 350) * 20ms = 3sec
#define BEGIN_SOURCECHANGE      500       // Task State0 Period : (500 - 350) * 20ms = 3sec
#define BEGIN_MODECHANGE        350     // Task State1 Period : (350 - 250) * 20ms = 2sec
#define BEGIN_SHOWHINT          50      // Task State2 Period : (250 -   0) * 20ms = 5sec
#define OSD_TO_HINT_DELAY       5       // The delay from OSD window closed to 'No Signal' hint text shown
*/

#ifdef __MAIN__

#if (IRPOLLING)
unsigned char data  ucIR_Cmd[2] = { 0x00, 0x00  };
unsigned char data  ucIR_State  = 0x00;
#endif

// Global Variables

bit bReload             = 0;    // 1 - reload user's font

#if (DISP_BIT == DISP_18BIT)
//bit bDitherTable        = 0;
//bit bDitherToggle       = 0;
#endif

#if(BURNIN_MODE)
unsigned char code BurnInColor[3][5] = 
{
//     	¬õ   ºñ   ÂÅ     ¥Õ  ¶Â  
	{ 255,	0,	0, 255,  0},	//R
	{	0, 255,	0, 255,  0},	//G
	{	0,	0, 255 ,255,  0},	//B
//	{  32,  64,   96, 128, 160, 196, 228, 255},
//	{255, 228, 196, 160, 128,  96,   64,   32},
//	{196,   64, 128,   32,  96, 255, 228, 160},
};
#endif
unsigned int    idata   usOSD_Timer = 0;

unsigned int    idata   usTaskCnt       = BEGIN_POWERUP;    // For Task State Machine

unsigned char   idata   ucID_Code       = 0;

// Function Prototype

#if (GETREGISTER)
void RTD_Get_Set(void);
#endif

#if (RTDDEBUG)
unsigned char   idata   ucMode_PrevAct  = 0;
unsigned char   idata   ucMode_QuitCnt  = 0;
unsigned char   idata   ucDebug         = 0;
unsigned int    idata   usPE_Sum        = 0;
#endif

void ISP_Check_Sum(void);


void Set_Task(unsigned char state);
void Run_Task(void);


#else   // __MAIN__


extern bit bReload;
// Public Global Variables
#if (IRPOLLING)
extern unsigned char    data    ucIR_Cmd[2];
extern unsigned char    data    ucIR_State;
#endif

extern unsigned int     idata   usOSD_Timer;
extern unsigned int     idata   usTaskCnt;
extern unsigned char    idata   ucID_Code;


// Function Prototype

extern void ISP_Check_Sum(void);
extern void Set_Task(unsigned char state);


#endif
