//#include "Main_def.h"

#define COLOR_BLACK     0
#define COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_CYAN      3
#define COLOR_RED       4
#define COLOR_MAGENTA   5
#define COLOR_YELLOW    6
#define COLOR_WHITE     7

#define OSD_WINDOW_ENABLE       0x04
#define OSD_WINDOW_HIGHLIGHT    0x02
#define OSD_WINDOW_SHADOWING    0x01

#define OSD_GLOBAL_BLINK     0x10
#define OSD_DISP_ZONE_LEFT   0x04
#define OSD_DISP_ZONE_RIGHT  0x08
#define OSD_ROTATE           0x02
#define OSD_ENABLE           0x01


#ifdef __OSD__

unsigned char   idata   ucOSD_Page_Index    = 0;
unsigned char   idata   ucOSD_Item_Index0   = 0;
unsigned char   idata   ucOSD_Item_Index1   = 0;
unsigned char   idata   ucOSD_Item_Index2   = 0;

unsigned char   idata   ucOSD_Pre_Page_Index    = 0;
#if(SHOW_CHECK)
unsigned char   idata   ucDebug_Value0  = 0;
unsigned char   idata   ucDebug_Value1  = 0;
unsigned char   idata   ucDebug_Value2  = 0;
#endif

unsigned char GetNextPageIdx(unsigned char ucPageCurr);
unsigned char GetPrevPageIdx(unsigned char ucPageCurr);


void OSD_Window(unsigned char win_no, unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end,
                unsigned char width, unsigned char height, unsigned char color, unsigned char color_sb, unsigned char gradient,
				unsigned char gra_level,unsigned char attr);
void OSD_Position(unsigned char para);
void OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color, unsigned char color_slider);

void Get_OSD_Margin(void);

void OSD_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate);
void OSD_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);

//////////////////////////////////////////////////////////////////////////////////////
//anson
//////////////////////////////////////////////////////////////////////////////////////
void OSD_Fact_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate);//anson
void OSD_Fact_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);	//anson
void Value_Adjust(unsigned char *Var, unsigned char Key, unsigned char VMax, unsigned char VMin);//anson
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

void Show_Mode(void);
void Init_Page(unsigned char index);
void OSD_Proc(unsigned char action);
void OSD_Proc_B(unsigned char action);


void OSD_TV_Proc(unsigned char action);
void OSD_TV_Menu(unsigned char action);
void Show_TV_Info(unsigned channel, unsigned char option);
void Show_TV_Number(unsigned char num, unsigned char row, unsigned char col, unsigned char option);

void TV_AutoScan(void);

void OSD_Opening(void);
void OSD_Ending(void);

// Show 'No Signal', 'Not Support', 'No Cable' ...
void Show_Note(void);
void Show_Hint(void);

#if (SHOW_CHECK)
void OSD_Show_Check(void);
void OSD_Show_Num(unsigned char column, unsigned char no);
#endif



#else

extern unsigned char    idata   ucOSD_Page_Index;
extern unsigned char    idata   ucOSD_Item_Index0;
extern unsigned char    idata   ucOSD_Item_Index1;
extern unsigned char    idata   ucOSD_Item_Index2;

extern unsigned char   idata   ucOSD_Pre_Page_Index;
#if(SHOW_CHECK)
extern unsigned char   idata   ucDebug_Value0;
extern unsigned char   idata   ucDebug_Value1;
extern unsigned char   idata   ucDebug_Value2;
#endif

//extern code void (*OSD_Proc[][SOURCE_MAX + 1])(unsigned char action);
extern void OSD_Proc(unsigned char action);


extern void OSD_Window(unsigned char win_no, unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end,
                unsigned char width, unsigned char height, unsigned char color, unsigned char color_sb, unsigned char gradient,
				unsigned char gra_level,unsigned char attr);


extern void OSD_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate);

extern void Get_OSD_Margin(void);

extern void OSD_Opening(void);
extern void OSD_Ending(void);

extern void Show_Note(void);
extern void Show_Hint(void);
extern void OSD_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);

extern void OSD_Show_Check(void);
extern void rgb_OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color, unsigned char color_slider);
//////////////////////////////////////////////////////////////////////////////////////
//anson
//////////////////////////////////////////////////////////////////////////////////////
extern void OSD_Fact_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate);//anson
extern void OSD_Fact_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);//anson
extern void OSD_Position(unsigned char para);				//anson 05_0314
extern void Value_Adjust(unsigned char *Var, unsigned char Key, unsigned char VMax, unsigned char VMin);//anson
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

#endif

