#ifdef __MODEDETECT__
/*
unsigned char code TMDS_MANUAL_ON[] = 
{
    7, Y_INC, TMDS_OUTPUT_ENA_A0, 0x8f, 0xef, 0x8b, 0x36, 
    0
};
*/
void Mode_Detector(void);
void Measure_Mode(void);
void Detect_Input_Mode(void);
void Check_Input_Mode(void);
void Detect_Video_Mode(void);
void Check_Video_Mode(void);

void New_Mode_Auto(void);					//anson 05_0314
unsigned char    idata   ucfrist         = 0;				//anson 05_0314

unsigned int    idata   usHsync         = 0;
unsigned int    idata   usVsync         = 0;
unsigned int    idata   usStdHS         = 0;
unsigned int    idata   usStdVS         = 0;
unsigned char   idata   ucRefresh       = 0;

bit bVpole_Prev         = 0;
bit bHpole_Prev         = 0;
bit bVpole_Curr         = 0;
bit bHpole_Curr         = 0;
bit bStable             = 0;    // 0 - input not stable, 1 - input stable
bit bOverSpec           = 0;


unsigned char   idata   ucSync_Type = SYNC_SS;

unsigned char   idata   ucAV_Mode   = 0;            // AV/S-Video mode, 0x00:Not Detect Frequency
                                                    //                  0x01:NTSC  60 Hz(bit 0)
				                        //                  0x02:PAL   50 Hz(bit 1)
                                                    //                  0x03:SECAM 50 Hz(bit 1)
                                                    // Color standard   0x00/0x10/0x20/0x30/0x40
                                                    //                  0x80 : color unlocked 

unsigned char   idata   ucMode_Curr     = MODE_NOSIGNAL;
unsigned char   idata   ucMode_Found    = MODE_NOSIGNAL;
unsigned char   idata   ucMode_Times    = 0;
unsigned char   idata   ucInputSrc  = SOURCE_VGA;   // Used to change input source. You can only set ucInputSrc through
                                                    // Change_Source() outside lcd_main.c

unsigned char   idata   ucModeCnt;
unsigned char   idata   ucPE_Level      = 0;
unsigned char   idata   ucCE_Value      = 0;

unsigned char Seek_DVI_Mode(unsigned char mode);

void Initial_Mode(void);

void Display_VGA_Set(void);
void Display_DVI_Set(void);
void Display_Video_Set(void);
void Set_Video_Mode(void);

unsigned char Seek_DVI_Mode(unsigned char mode);

#else

extern bit bVpole_Curr;
extern bit bHpole_Curr;
extern bit bStable;    // 0 - input not stable, 1 - input stable
extern bit bOverSpec;

extern unsigned int idata          usHsync;
extern unsigned int idata          usStdHS;
extern unsigned int idata          usVsync;
extern unsigned char   idata   ucMode_Curr;
extern unsigned char   idata   ucMode_Found;
extern unsigned char   idata   ucMode_Times;
extern unsigned char   idata   ucAV_Mode;
extern unsigned char   idata   ucInputSrc;
extern unsigned char   idata   ucRefresh;
extern unsigned char   idata   ucModeCnt;
extern unsigned char   idata    ucSync_Type;
extern void Mode_Detector(void);
extern void Measure_Mode(void);
extern void Measure_Source(unsigned char SOURCE);
extern void Input_Mode_Detector(void);
extern unsigned char   idata   ucPE_Level;
extern unsigned char   idata   ucCE_Value;

extern void New_Mode_Auto(void);		//anson 05_0314
extern unsigned int    idata   ucfrist ;			//anson 05_0314

#endif
