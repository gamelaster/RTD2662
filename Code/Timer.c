#define __TIMER__

#include "reg52.h"
#include "Header\Lcd_main.h"
#include "Header\Lcd_auto.h"

/////////////////////////////////////////////////////////////
// Interrupt Service Routine for Timer0 (Fired every 20ms) //
/////////////////////////////////////////////////////////////
void IntProc_Timer0(void) interrupt 1
{
#if (IRPOLLING)

    static unsigned char    ucIR_Seq    = 0xff;
    static unsigned char    ucTimerCnt  = 0x00;

    TL0         = TIME0_COUNTER_LBYTE;  // Reload Timer0 low-byte
    TH0         = TIME0_COUNTER_HBYTE;  // Reload Timer0 high-byte

    if (ucIR_State)
    {
        if (bIR_GPIO)
        {
            ucIR_Seq    = (ucIR_Seq << 1) | 0x01;

            if ((0xff == ucIR_Seq) && (ucIR_State & 0xfe))
            {
                ucIR_State  = 0;    // Command timeout; Back to idle state
                
                ((unsigned int *)ucIR_Cmd)[0]   = 0;
            }
        }
        else
        {
            if (1 < ucIR_State)
            {
                if (ucIR_Seq & 0x01)
                {
                    ((unsigned int *)ucIR_Cmd)[0]   = (((unsigned int *)ucIR_Cmd)[0] << 1) 
                                                    | (0x07 != (ucIR_Seq & 0x07) ? 1 : 0);

                    if (23 == ++ucIR_State && CUSTOM_CODE != ((unsigned int *)ucIR_Cmd)[0])
                    {
                        ucIR_State  = 0;    // Customer code error; Back to idle state

                        ((unsigned int *)ucIR_Cmd)[0]   = 0;
                    }
                    else if (39 == ucIR_State)
                    {
                        ucIR_State  = 0;    // Command complete; Back to idle state

                        ucIR_Cmd[1] = 8;    // Set command timer to 8 (7*20 = 140ms)
                    }
                }
                else if (0x00 == (ucIR_Seq & 0xfe))
                {
                    ucIR_State  = 0;    // Command crashed; Back to idle state
    
                    ((unsigned int *)ucIR_Cmd)[0]   = 0;
                }
            }
            else                        // ucIR_State is 1
            {
                if (0xff == ucIR_Seq)
                {
                    ucIR_State  = 0x07; // Start to decode new command and clear old command
    
                    ((unsigned int *)ucIR_Cmd)[0]   = 0;
                }
                else
                {
                    ucIR_State  = 0;    // Fire repeat command and reset to idle

                    ucIR_Cmd[1] = ucIR_Cmd[0] ? 8 : 0;
                }
            }
            
            ucIR_Seq    = ucIR_Seq << 1;
        }
    }
    else
    {
        ucIR_Seq    = (ucIR_Seq << 1) | bIR_GPIO;

        if (0x07 == ucIR_Seq)   ucIR_State  = 1;    // Leader code detected
    }

    if (54 <= ++ucTimerCnt)        // 0.375ms*54 = 20.25ms passed
    {
        ucTimerCnt          = 0;

        bNotify_Timer0_Int  = 1;    // Post Timer0's timeout message

        if (usOSD_Timer)    usOSD_Timer -= 1;   // For OSD Timeout

        // Clear command after 144ms if not repeat code
        if (0 == ucIR_State)
        {
            if (ucIR_Cmd[1] && 0 == --ucIR_Cmd[1])      ucIR_Cmd[0] = 0;
        }
    }

#else

// mega #if(MCU_TYPE == MCU_WINBOND)					//anson 050519
    TL0         = TIME0_COUNTER_LBYTE;  // Reload Timer0 low-byte
    TH0         = TIME0_COUNTER_HBYTE;  // Reload Timer0 high-byte

    bNotify_Timer0_Int  = 1;    // Post Timer0's timeout message

    if (usOSD_Timer)    usOSD_Timer -= 1;   // For OSD Timeout
 /*   mega			//anson 050519
#else
	 TL0 = TIME1_COUNTER_LBYTE;  // Reload Timer1 low-byte
     TH0 = TIME1_COUNTER_HBYTE;  // Reload Timer1 hifh-byte
	 TR0 = 1;                    // Stop Timer1
     bNotify_Timer1_Int  = 1;    // Post Timer1's timeout message  

     ucTimerCounter++;
   	 if(ucTimerCounter>20)
     {
    	ucTimerCounter=0;
    	bNotify_Timer0_Int  = 1;    // Post Timer0's timeout message
        if (usOSD_Timer)    usOSD_Timer -= 1;   // For OSD Timeout
     }
#endif
*/
#endif
}

///////////////////////////////////////////////////////////////////////
// Interrupt Service Routine for Timer1 (Fired in 1ms after restart) //
///////////////////////////////////////////////////////////////////////
//mega #if(MCU_TYPE == MCU_WINBOND) //Use the standard MCU			//anson 050519
void IntProc_Timer1(void) interrupt 3
{   
    TR1 = 0;                    // Stop Timer1
    TL1 = TIME1_COUNTER_LBYTE;  // Reload Timer1 low-byte

    TH1 = (bAutoInProgress == 1) ? TIME1_COUNTER_HHBYTE : TIME1_COUNTER_HBYTE;  // Reload Timer1 hifh-byte

    bNotify_Timer1_Int  = 1;    // Post Timer1's timeout message    
}

/////////////////////////////////////////////////////////////////////////////////
// Function Routines
/////////////////////////////////////////////////////////////////////////////////
void Delay_Xms(unsigned char x)     // For delay 0 ~ 255 ms
{
    if (x)
    {
        bNotify_Timer1_Int  = 0;    // Clear timer1's timeout message

//        TL1 = TIME1_COUNTER_LBYTE;  // Reload Timer1 low-byte
//        TH1 = TIME1_COUNTER_HBYTE;  // Reload Timer1 hifh-byte

        TR1 = 1;                    // Start timer1
        
        while (1)
        {
            if (bNotify_Timer1_Int)
            {
                bNotify_Timer1_Int  = 0;    // Clear timer1's timeout message

                if (--x)    TR1 = 1;        // Restart timer1 if not timeout
                else        return;         // Timeout for X ms.
            }
        }
    }
}
/*mega 			//anson 050519
#else //Use just one timer

/////////////////////////////////////////////////////////////////////////////////
// Function Routines
/////////////////////////////////////////////////////////////////////////////////
void Delay_Xms(unsigned char x)     // For delay 0 ~ 255 ms
{
//    unsigned char i;    
    if (x)
    {
        bNotify_Timer1_Int  = 0;    // Clear timer1's timeout message
        //TR1 = 1;                    // Start timer1
        while (1)
        {
            if (bNotify_Timer1_Int)
            {
                bNotify_Timer1_Int  = 0;    // Clear timer1's timeout message
                if (--x)    x=x;//TR1 = 1;        // Restart timer1 if not timeout
                else        return;         // Timeout for X ms.
            }
        }
    }
}


#endif
*/
