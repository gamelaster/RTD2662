//----------------------------------------------------------------------------------------------------
// ID Code      : Int.c No.0002
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#include "Core\Header\Include.h"

#if defined(CONFIG_VBI_ENABLE)
void VBI_GetData();
#else
#define	VBI_GetData();
#endif
//--------------------------------------------------
// Timer0 Interrupt (375 us)
//--------------------------------------------------
void IntProcTimer0(void) interrupt 1
{
#if(0)
	static BYTE data ucTimer0Cnt = 0x00;

    TR0 = _ON;
    TL0 = _TIMER0_COUNT_LBYTE;
    TH0 = _TIMER0_COUNT_HBYTE;

    bNotifyTimer0Int = _TRUE;

    if(--ucTimer0Cnt)
    {

    }
    else
    {
        if(bTimer0Ctrl == _FALSE)
        {
            CTimerDecreaseTimerCnt();
        }
        ucTimer0Cnt = 10;
    }

#else
	static BYTE data ucTimer0Cnt = 0x00;
	static BYTE data ucTimerCnt = 10;

	
	EA = 0;
	TR0 = _ON;

	TL0 = _TIMER0_COUNT_LBYTE;	
	TH0 = _TIMER0_COUNT_HBYTE;
	
	
	if((++ucTimer0Cnt) >= _EVENT_PERIOD) 
	{
		ucTimer0Cnt = 0;
		bNotifyTimer0Int = _TRUE;
		if(ucTimerCnt)
			ucTimerCnt--;
			
		else if(bTimer0Ctrl == _FALSE) 
		{

			CTimerDecreaseTimerCnt();
			ucTimerCnt = 0x0a; 	//including the above 1.125ms, this will
								//give about 5 sec delay before OSD
								//menu/channel# got turn off
		}

#if(_VIDEO_TV_SUPPORT)
#if(_SLEEP_FUNC)
	    if (0xff != ucAutoPowerDownTime && 0x00 != ucAutoPowerDownTime)
	    {
	        ucMinuteCount++;
           if(ucMinuteCount == 1000)
               ucAutoPowerDownTime--;
           if (ucMinuteCount == _ONE_MINUTE_COUNT)  // 1 minute
               ucMinuteCount = 0;
       }
#endif
#endif
		}
		EA = 1;
#endif	

}




void IntProcDdcci(void)  interrupt 2
{
    BYTE tempbuf;
    
    EA=0;
    MCU_I2C_IRQ_CTRL2_FF2A  &= 0xDF; //host write/read enable
    if(!bRunCommand)
    {
        tempbuf = MCU_I2C_STATUS_FF27;   

        if(tempbuf & 0x08)
            MCU_I2C_DATA_OUT_FF26 = TxBUF;       

        if(tempbuf & 0x01) 
            ucDdcciCommandNumber = 0;

        if(tempbuf & 0x02) 
            ucDdcciCommandNumber=0;
        		
        if(tempbuf & 0x04)
        {
            if(ucDdcciCommandNumber==0)
                ucDdcciData[ucDdcciCommandNumber] = MCU_I2C_SUB_IN_FF24;

            ucDdcciCommandNumber++;
            ucDdcciData[ucDdcciCommandNumber] = MCU_I2C_DATA_IN_FF25;
            bRunCommand=_TRUE; 
        }

        MCU_I2C_STATUS_FF27 = tempbuf & 0xc0;
    }

    EA=1;
}

#if defined(CONFIG_VBI_ENABLE)

void IntProc_Timer1(void) interrupt 3
{
	ET1 = 0;  	// Disable Timer 1 interrupt
	VBI_GetData();
	TL1 = _TIMER1_COUNT_LBYTE;  // (for 1ms)
	TH1 = _TIMER1_COUNT_HBYTE;  // Load Timer1 hifh-byte  (for 1ms)
	TR1 = 1;    // Start Timer1
	ET1 = 1;	// Enable Timer 1 interrupt
}

/**
 * The VBI interrupt service routine.
 */
void VBI_GetData(void) //VBI INTERRUPT handler
{
	ClearVerLineCompSts();
}

#endif

