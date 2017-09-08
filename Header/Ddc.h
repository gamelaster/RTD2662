//***********************************************************************
//                                      Myson Addition DDCRAM 
//***********************************************************************
#include "HEADER\Main_def.h"

#define	WslvA1I		0x04
//#ifndef _DDC_
#if(USE_MCU_DDC)

#ifdef _DDC_

void EnableDDC(void);
//void EnableDDCWriter();
void MovEEPROM(unsigned char *array,unsigned char index);
//extern void MovEEPROM_2(unsigned char *array);
void EDID_Process();

#else

#define _DDC_



extern void EnableDDC(void);
//extern void EnableDDCWriter();
extern void MovEEPROM(unsigned char *array,unsigned char index);
//extern void MovEEPROM_2(unsigned char *array);
extern void EDID_Process();
extern unsigned char code EDID_DATA1[128];

#endif

#endif
