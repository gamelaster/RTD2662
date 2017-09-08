#include "HEADER\Main_def.h"



// For 24.576MHz crystal
// Timer Freq.      : 24.576MHz / 12 = 2.048MHz -> 0.488us

#if (IRPOLLING)
// Timer0 Period    : (0xffff - 0xfcff) / 2.048 = 375us -> 0.375ms
#define TIME0_COUNTER_LBYTE     0xFF
#define TIME0_COUNTER_HBYTE     0xFC
#else
// Timer0 Period    : (0xffff - 0x5fff) / 2.048 = 20000us -> 20ms
#if(MCU_TYPE == MCU_WINBOND)

#define TIME0_COUNTER_LBYTE     0xFF
#define TIME0_COUNTER_HBYTE     0x5F

#else

#define TIME0_COUNTER_LBYTE     0xFF//0xDF
#define TIME0_COUNTER_HBYTE     0x5F//0xB1

#endif
#endif

// Timer1 Period    : (0xffff - 0xf7ff) / 2.048 =  1000us ->  1ms
#if(MCU_TYPE == MCU_WINBOND)

#define TIME1_COUNTER_LBYTE     0xFF
#define TIME1_COUNTER_HBYTE     0xF7
#define TIME1_COUNTER_HHBYTE    0xFB

#else

#define TIME1_COUNTER_LBYTE     0x80//0xFF//0x17
#define TIME1_COUNTER_HBYTE     0xF8//0xF7//0xFC
#define TIME1_COUNTER_HHBYTE    0xFB				//anson 050519

#endif

#ifdef __TIMER__

bit bNotify_Timer0_Int  = 0;
bit bNotify_Timer1_Int  = 0;
unsigned char   idata   ucTimerCounter = 0;
void Delay_Xms(unsigned char x);    // For delay 0 ~ 255 ms
/*
// For 24MHz crystal
// Timer Freq.      : 24MHz / 12 = 2MHz -> 0.5us

#if (IRPOLLING)
// Timer0 Period    : (0xffff - 0xfd11) * 0.5 = 375us -> 0.375ms
#define TIME0_COUNTER_LBYTE     0x11
#define TIME0_COUNTER_HBYTE     0xFD
#else
// Timer0 Period    : (0xffff - 0x63bf) * 0.5 = 20000us -> 20ms
#define TIME0_COUNTER_LBYTE     0xBF
#define TIME0_COUNTER_HBYTE     0x63
#endif

// Timer1 Period    : (0xffff - 0xf82f) * 0.5 =  1000us ->  1ms
#define TIME1_COUNTER_LBYTE     0x2F
#define TIME1_COUNTER_HBYTE     0xF8
*/

#else

extern bit bNotify_Timer0_Int;
extern bit bNotify_Timer1_Int;
extern void Delay_Xms(unsigned char x);    // For delay 0 ~ 255 ms
#endif
