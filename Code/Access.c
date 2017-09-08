#define __ACCESS__

#include "reg52.h"
#include "intrins.h"

#include "Header\MAIN_DEF.H"
#include "Header\ACCESS.h"
#include "Header\CONFIG.H"
#include "Header\MTV512.H"
#include "Header\OSD.H"
#include "Header\Power_Ctrl.h"

#if(MCU_TYPE == MCU_MTV512)
///////////////////////////////////////////////////////////////////////
// SCL Processor                                                                                                //
///////////////////////////////////////////////////////////////////////
void MCU_WriteI2cScl(bit Status)
{
       bIIC_SCL = Status;
}	
///////////////////////////////////////////////////////////////////////
// SDA Processor                                                                                               //
///////////////////////////////////////////////////////////////////////
void MCU_WriteI2cSda(bit Status)
{
       bIIC_SDA = Status;
}	

bit MCU_ReadI2cSda(void)
{
       return(bIIC_SDA);
}		
///////////////////////////////////////////////////////////////////////
// RTD Reset Processor                                                                                      //
///////////////////////////////////////////////////////////////////////
#if(RESET_TYPE == RESET_IN)
void MCU_WriteRtdReset(bit Status)
{
       bRTD_RST = Status;
}

bit MCU_ReadRtdReset(void)
{
       return(bRTD_RST);
}	
#endif

	
///////////////////////////////////////////////////////////////////////
// RTD SDIO Processor                                                                                       //
///////////////////////////////////////////////////////////////////////
/*
void MCU_WriteRtdSdio(bit Status)
{
       bRTD_SDIO_0 = Status;
}	

bit MCU_ReadRtdSdio(void)
{
       return(bRTD_SDIO_0);
}	
*/
///////////////////////////////////////////////////////////////////////
// RTD Sclk Processor                                                                                        //
///////////////////////////////////////////////////////////////////////
void MCU_WriteRtdSclk(bit Status)
{
       bRTD_SCLK = Status;
}	
///////////////////////////////////////////////////////////////////////
// RTD Scsb Processor                                                                                       //
///////////////////////////////////////////////////////////////////////
void MCU_WriteRtdScsb(bit Status)
{
       bRTD_SCSB = Status;
}	
///////////////////////////////////////////////////////////////////////
// VIDEO POWER Processor                                                                                //
///////////////////////////////////////////////////////////////////////
#if (VIDEO_CHIP != VDC_NONE)
void MCU_WriteVideoPower(bit Status)
{
       bVDC_PWR = Status;
}	
#endif

///////////////////////////////////////////////////////////////////////
// PANEL POWER Processor                                                                                 //
///////////////////////////////////////////////////////////////////////
void MCU_WritePanelPower(bit Status)
{
       bPANEL_PWR = Status;
       bPanel_Status = Status ? 1 : 0;
}	
/*
bit MCU_ReadPanelPower(void)
{
       return(bPANEL_PWR);
}
*/	
///////////////////////////////////////////////////////////////////////
// BACKLIGHT POWER Processor                                                                         //
///////////////////////////////////////////////////////////////////////
void MCU_WriteBacklightPower(bit Status)
{	
       bLIGHT_PWR = (Status);
}


///////////////////////////////////////////////////////////////////////
// VGA CONNECT Processor                                                                                //
///////////////////////////////////////////////////////////////////////
bit MCU_ReadVgaConnect(void)
{
       return(bVGA_CONNECT);
}

#endif

void BitDly(void)
{
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
}

void I2CRead(unsigned char addr, unsigned char index, unsigned char count)
{
    unsigned char   n;

    if (count)
    {
        I2CSendAddr(addr, index, 0);
        
        I2CSendAddr(addr, 0, 1);

        count   = count - 1;

        for (n = 0; n < count; n++)     Data[n] = I2CGetByte(0);

        Data[count] = I2CGetByte(1);

        I2CSendStop();
    }
}

void I2CWrite(unsigned char *array)
{
    unsigned char   n, len;

    if (3 <= array[0])
    {
        len     = array[0];
        I2CSendAddr(array[1], array[2], 0);     

        for (n = 3; n < len; n++)   I2CSendByte(array[n]);

        I2CSendStop();
    }
}


unsigned char I2CGetByte(unsigned char ack) 
{
    unsigned char   r, m;

    r = 0;
#if(MCU_TYPE == MCU_WINBOND)
    for (m = 0; m < 8; m++)         // Each bit at a time, MSB first
    {
        bIIC_SCL    = 1;
        BitDly();                   // Delay

        r   = (r << 1) | bIIC_SDA;

        bIIC_SCL    = 0;
        BitDly();                   // Delay
    }  

    // Send ACK according to 'ack'
    bIIC_SDA    = (bit)(ack & 0x01);
    BitDly();                       // Delay
    
    bIIC_SCL    = 1; 
    BitDly();                       // Delay
    
    bIIC_SCL    = 0; 
    BitDly();                       // Delay
    
    bIIC_SDA    = 1;
#else
   
    for (m = 0; m < 8; m++)         // Each bit at a time, MSB first
    {
        MCU_WriteI2cScl(_HIGH);
        BitDly();                   // Delay
        r   = (r << 1) | MCU_ReadI2cSda();
        MCU_WriteI2cScl(_LOW);
        BitDly();                   // Delay
    }  
    // Send ACK according to 'ack'
    MCU_WriteI2cSda((bit)(ack & 0x01));
    BitDly();                       // Delay
    MCU_WriteI2cScl(_HIGH);
    BitDly();                       // Delay
    MCU_WriteI2cScl(_LOW);
    BitDly();                       // Delay
    MCU_WriteI2cSda(_HIGH);

#endif

    return (r);
}

void I2CSendByte(unsigned char send)
{
    unsigned char   m;
#if(MCU_TYPE == MCU_WINBOND)    
    for (m = 0; m < 8; m++)
    {
        bIIC_SDA    = (bit)(send & 0x80);   // Send each bit, MSB first
        BitDly();

        bIIC_SCL    = 1;
        BitDly();

        bIIC_SCL    = 0;

        send    = send << 1;
    }

    bIIC_SDA    = 1;
    bIIC_SCL    = 1;
    BitDly();

    bIIC_SCL    = 0;
    BitDly();
#else
    for (m = 0; m < 8; m++)
    {
        MCU_WriteI2cSda((bit)(send & 0x80));   // Send each bit, MSB first
        BitDly();
        MCU_WriteI2cScl(_HIGH);
        BitDly();
        MCU_WriteI2cScl(_LOW);;
        send    = send << 1;
    }
    MCU_WriteI2cSda(_HIGH);
    MCU_WriteI2cScl(_HIGH);
    BitDly();
    MCU_WriteI2cScl(_LOW);;
    BitDly();

#endif
} 

void I2CSendAddr(unsigned char addr, unsigned char index, unsigned char rd)
{         
#if(MCU_TYPE == MCU_WINBOND)         
    bIIC_SCL    = 1;
    bIIC_SDA    = 0;    // Start
    BitDly();

    bIIC_SCL    = 0;
    I2CSendByte(addr + rd);             // Send address byte

    if (0 == rd)    I2CSendByte(index); // Send index byte  
#else
    MCU_WriteI2cScl(_HIGH);
    MCU_WriteI2cSda(_LOW);    // Start
    BitDly();
    MCU_WriteI2cScl(_LOW);;
    I2CSendByte(addr + rd);             // Send address byte
    if (0 == rd)    I2CSendByte(index); // Send index byte 
#endif
}

void I2CSendStop(void)
{
#if(MCU_TYPE == MCU_WINBOND)
    bIIC_SDA    = 0; 
    BitDly();

    bIIC_SCL    = 1;
    BitDly();

    bIIC_SDA    = 1;
    BitDly();
#else
    MCU_WriteI2cSda(_LOW); 
    BitDly();
    MCU_WriteI2cScl(_HIGH);
    BitDly();
    MCU_WriteI2cSda(_HIGH);
    BitDly();
#endif
}

unsigned char RTDGetByte(void) 
{

#if(PARALLEL_PORT)

#if(1)
   bRTD_SCLK = 1;
   bRTD_SCLK = 0;
   r0        = bRTD_SDIO_0;
   r1        = bRTD_SDIO_1;
   r2        = bRTD_SDIO_2;
   r3        = bRTD_SDIO_3;

   bRTD_SCLK = 1;
   bRTD_SCLK = 0;
   r4        = bRTD_SDIO_0;
   r5        = bRTD_SDIO_1;
   r6        = bRTD_SDIO_2;
   r7        = bRTD_SDIO_3;

   bRTD_SCLK   = 1;
#else

   bRTD_SCLK = 1;
   bRTD_SCLK = 0;

   Reg = P0 & 0x0f;

   bRTD_SCLK = 1;
   bRTD_SCLK = 0;

   Reg = Reg | ((P0 & 0x0f) << 4);

   bRTD_SCLK   = 1;

#endif

#else //serial port
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r0          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r1          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r2          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r3          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r4          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r5          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r6          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    r7          = bRTD_SDIO_0;

    bRTD_SCLK   = 1;

#endif


    return Reg;
}

void RTDSendByte(unsigned char send)
{


#if(PARALLEL_PORT)

#if(1)
    bRTD_SDIO_0 = (bit)(send & 0x01);
	bRTD_SDIO_1 = (bit)(send & 0x02);
	bRTD_SDIO_2 = (bit)(send & 0x04);
	bRTD_SDIO_3 = (bit)(send & 0x08);
	bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

	bRTD_SDIO_0 = (bit)(send & 0x10);
	bRTD_SDIO_1 = (bit)(send & 0x20);
	bRTD_SDIO_2 = (bit)(send & 0x40);
	bRTD_SDIO_3 = (bit)(send & 0x80);
	bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

	bRTD_SDIO_0 = 1;
	bRTD_SDIO_1 = 1;
	bRTD_SDIO_2 = 1;
	bRTD_SDIO_3 = 1;
	bRTD_SCLK   = 1;
#else
    unsigned char ucTemp;

	ucTemp = P0 & 0xf0;

    P0 = ucTemp | (send & 0x0f);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    P0 = ucTemp | (send >> 4);

   	bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    P0 = ucTemp | 0x0f;
   	bRTD_SCLK   = 1;

#endif

#else //serial port
    bRTD_SDIO_0 = (bit)(send & 0x01);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x02);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x04);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x08);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x10);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x20);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x40);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = (bit)(send & 0x80);
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;

    bRTD_SDIO_0 = 1;
    bRTD_SCLK   = 1;

#endif


}

void RTDSendAddr(unsigned char addr, unsigned char rd, unsigned char inc)   // rd   : 0 - Write, 1 - Read
{

#if(PARALLEL_PORT)

    RTDSendByte(addr);

	bRTD_SDIO_0 = (bit)(rd & 0x01);
	bRTD_SDIO_1 = (bit)(inc & 0x01);
	
	bRTD_SCLK = 0;

	bRTD_SDIO_0 = 1;
	bRTD_SDIO_1 = 1;
	bRTD_SCLK = 1;
#else // serial port
    RTDSendByte(addr);

    bRTD_SDIO_0 = 1;
    bRTD_SCLK   = 1;        
    bRTD_SDIO_0 = (bit)(rd & 0x01); 
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    bRTD_SDIO_0 = (bit)(inc & 0x01); 
    bRTD_SCLK   = 1;
    bRTD_SCLK   = 0;
    bRTD_SDIO_0 = 1;
#endif


}

void RTDSendStop(void)
{

        bRTD_SCLK   = 0;
        bRTD_SCLK   = 1; 
        bRTD_SCSB   = 1;

}

void RTDRead(unsigned char index, unsigned char count, unsigned char inc)
{
    if (count)
    {
        bRTD_SCSB   = 0;

        RTDSendAddr(index, 1, inc);

        index   = 0;
        do
        {
            Data[index++]   = RTDGetByte();
        }
        while (--count);

		RTDSendStop();

    }
}

void RTDWrite(unsigned char data *array)
{

    unsigned char   len, m;

    do
    {
        if (0 == (array[0] & 0xfc))     return;

        len     = array[0] - 3;
        array   = array + 1;
        bRTD_SCSB   = 0;


        if (BURST == array[0])
        {
            RTDSendAddr(array[1], 0, N_INC);

            array   = array + 2;
            m       = array[0];

            do
            {
                RTDSendByte(m);
            }
            while (--len);

            array   = array + 1;
        }
        else
        {
            RTDSendAddr(array[1], 0, array[0]);

            array   = array + 2;
            do
            {
                RTDSendByte(*array++);
            }
            while (--len);
        }
		RTDSendStop();
    }
    while (1);
}

void RTDCodeW(unsigned char code *array)
{
    unsigned char   len, m;

    do
    {
        if (0 == (array[0] & 0xfc))     return;

        len     = array[0] - 3;
        array   = array + 1;
        bRTD_SCSB   = 0;

        if (BURST == array[0])
        {
            RTDSendAddr(array[1], 0, N_INC);

            array   = array + 2;
            m       = array[0];
            
            do
            {
                RTDSendByte(m);
            }
            while (--len);

            array   = array + 1;
        }
        else
        {
            RTDSendAddr(array[1], 0, array[0]);

            array   = array + 2;
            do
            {
                RTDSendByte(*array++);
            }
            while (--len);
        }
		RTDSendStop();

    }
    while (1);
}

void RTDOSDW(unsigned char code *array)
{
    unsigned char   len;
    do
    {
        if (array[0] == _end_)     return;
		    
		bRTD_SCSB   = 0;
        RTDSendAddr(OSD_ROW_90,WRITE,Y_INC);
        RTDSendByte(*array++);
        RTDSendByte(*array++);

		RTDSendStop();

		bRTD_SCSB   = 0;
        RTDSendAddr(OSD_DATA_92,WRITE,N_INC);
        do
		{
           if(array[0] == _ext_)
           {
               if(array[2] == _bb_)
               {
                  do
                  {
                     len = array[3] - 1;
                     RTDSendByte(_ext_ + array[1]);
                   }while(len--);

                   array += 4;
               }
               else
               {
                   RTDSendByte(_ext_ + array[1]);
                   array += 2;
               }
           }
           else if(array[1] == _bb_)
		   {
		       len = array[2] - 1;
			   do
			   {
			      RTDSendByte(*array);
			   }while(len--);
		       
			   array += 3;
		   }
		   else
		       RTDSendByte(*array++);


		}while(array[0] != _nn_);
		array +=1 ;
		RTDSendStop();

    }
    while (1);

}


void RTDSetByte(unsigned char addr, unsigned char val)
{
    // Set Write Address
    bRTD_SCSB   = 0;   

    RTDSendAddr(addr, 0, 1);

    // Write one Byte
    RTDSendByte(val);

	RTDSendStop();

}

void RTDSetBit(unsigned char addr, unsigned char and, unsigned char or)
{
    // Set Read Address
    bRTD_SCSB   = 0;
    RTDSendAddr(addr, 1, 1);

    // Read 1 Byte
    or      = (RTDGetByte() & and) | or;

	RTDSendStop();

    // Set Write Address
    bRTD_SCSB   = 0;   
    RTDSendAddr(addr, 0, 1);

    // Write one Byte
    RTDSendByte(or);

	RTDSendStop();


}

#if(VLC_COMPRESS)
void Load_VLC_Font(unsigned char code *array, unsigned int start, unsigned int length)
{
	unsigned char n,m;
	unsigned char ucTemp[3];
	unsigned char idata ucTemp_VLD[3];
	
#if(PARALLEL_PORT)
//	unsigned char ucTemp1;
#endif

	start += FONT_BASE_ADDRESS;

	bRTD_SCSB   = 0;   
	RTDSendAddr(OSD_ROW_90, WRITE, Y_INC);
	ucTemp[0] = (unsigned char)((start >> 8) & 0x000f) | 0xd0;
	RTDSendByte(ucTemp[0]);
	ucTemp[0] = (unsigned char)(start & 0x00ff);
	RTDSendByte(ucTemp[0]);

	RTDSendStop();

	bRTD_SCSB   = 0;   
	RTDSendAddr(OSD_DATA_92, WRITE, N_INC);

	ucCnt = 0;
	uiCount = 0;
	bBit = 0;
	ucByte_Temp = 0;

	do
	{
		for(m=0; m<9; m++)
		{

			ucTemp_VLD[0] = Get_VLD(array) << 4;
			ucTemp_VLD[0] |= Get_VLD(array);
			ucTemp_VLD[1] = Get_VLD(array) << 4;
			ucTemp_VLD[1] |= Get_VLD(array);
			ucTemp_VLD[2] = Get_VLD(array) << 4;
			ucTemp_VLD[2] |= Get_VLD(array);
			
			//Rearrange the byte order
			ucTemp[0] = (ucTemp_VLD[1] << 4) | (ucTemp_VLD[2] & 0x0f);
			ucTemp[1] = (ucTemp_VLD[2] & 0xf0) | (ucTemp_VLD[0] & 0x0f);
			ucTemp[2] = (ucTemp_VLD[0] & 0xf0) | (ucTemp_VLD[1] >> 4);

			for(n=0;n<3;n++)
			{
#if(PARALLEL_PORT)
				
#if(KINGMICE)
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x01);
				bRTD_SDIO_1 = (bit)(ucTemp[n] & 0x02);
				bRTD_SDIO_2 = (bit)(ucTemp[n] & 0x04);
				bRTD_SDIO_3 = (bit)(ucTemp[n] & 0x08);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x10);
				bRTD_SDIO_1 = (bit)(ucTemp[n] & 0x20);
				bRTD_SDIO_2 = (bit)(ucTemp[n] & 0x40);
				bRTD_SDIO_3 = (bit)(ucTemp[n] & 0x80);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = 1;
				bRTD_SDIO_1 = 1;
				bRTD_SDIO_2 = 1;
				bRTD_SDIO_3 = 1;
				bRTD_SCLK   = 1;
#else
				ucTemp1 = P0 & 0xf0;

				P0 = ucTemp1 | (ucTemp[n] & 0x0f);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				P0 = ucTemp1 | (ucTemp[n] >> 4);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				P0 = ucTemp1 | 0x0f;
				bRTD_SCLK   = 1;
#endif

#else
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x01);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x02);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x04);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x08);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x10);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x20);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x40);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x80);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = 1;
				bRTD_SCLK   = 1;
#endif
			}
		}
	}
	while (--length);

	RTDSendStop();
	
}

unsigned char Get_VLD(unsigned char code *array)
{
	unsigned char data ucZero_Cnt = 0;
	bit bSec_Part = 0;
	
	while(1)
	{
		if( ucCnt == 0 )
		{
			ucByte_Temp = *(array + uiCount);
			ucCnt = 0x80;
			uiCount++;
		}

		while( ucCnt > 0 )
		{
			bBit = (bit)(ucByte_Temp & ucCnt);
			ucCnt >>= 1;

			if( (bBit) && (bSec_Part == 0) )
			{
				bSec_Part = 1;
			}
			else	
			{
				ucZero_Cnt++;
			}

			if( bSec_Part == 1 )
			{
				switch(ucZero_Cnt)
				{
					case 0:
						bSec_Part = 0;
						ucZero_Cnt = 0;
						return 0;
	
					case 1:
						Getbit(array);
						bSec_Part = 0;
						ucZero_Cnt = 0;

						if(!bBit)
						{
							return 1;
						}
						else
						{
							return 15;
						}

					case 2:
						Getbit(array);
						bSec_Part = 0;
						ucZero_Cnt = 0;
						
						if(!bBit)
						{
							return 2;
						}
						else
						{
							return 8;
						}

					case 3:
						Getbit(array);
						bSec_Part = 0;
						ucZero_Cnt = 0;

						if(!bBit)
						{
							return 12;
						}
						else
						{
							return 7;
						}

					case 4:
						Getbit(array);
						bSec_Part = 0;
						ucZero_Cnt = 0;

						if(bBit)
						{
							Getbit(array);

							if(!bBit)
							{
								return 4;
							}
							else
							{
								return 9;
							}
						}
						else
						{
							Getbit(array);
	
							if(!bBit)
							{
								Getbit(array);

								if(!bBit)
								{
									return 3;
								}
								else
								{
									return 11;
								}

							}
							else
							{
								Getbit(array);
								
								if(!bBit)
								{
									return 10;
								}
								else
								{
									return 5;
								}

							}
						}

					case 5:
						Getbit(array);
						bSec_Part = 0;
						ucZero_Cnt = 0;

						if(bBit)
						{
							Getbit(array);

							if(!bBit)
							{
								return 14;
							}
							else
							{
								return 13;
							}
						}
						else
						{
							Getbit(array);
							if(bBit)
							{
								return 6;
							}
						}
				}
			}
		}
	}
}

void Getbit(unsigned char code *array)
{
	if( ucCnt == 0 )
	{
		ucByte_Temp = *(array + uiCount);
		ucCnt = 0x80;
		uiCount++;
	}
							
	bBit = (bit)(ucByte_Temp & ucCnt);
	ucCnt >>= 1;

}
#else
//length represent the number of character
// character number of 1 bit font  = 1
// character number of 2 bit font  = 2
// character number of 4 bit font  = 4
// length = (1 bit font amount) x 1 + (2 bit font amount) x 2 + (4 bit font amount) x 4
void Load_Font(unsigned char code *array, unsigned int start, unsigned int length)
{
    unsigned char   n,m;
    unsigned char   ucTemp[3];
#if(PARALLEL_PORT)
//	unsigned char ucTemp1;
#endif

    start = start * 9;
    start += FONT_BASE_ADDRESS;

	bRTD_SCSB   = 0;   
	RTDSendAddr(OSD_ROW_90, WRITE, Y_INC);
	ucTemp[0] = (unsigned char)((start >> 8) & 0x000f) | 0xd0;
	RTDSendByte(ucTemp[0]);
	ucTemp[0] = (unsigned char)(start & 0x00ff);
	RTDSendByte(ucTemp[0]);

	RTDSendStop();

	bRTD_SCSB   = 0;   
	RTDSendAddr(OSD_DATA_92, WRITE, N_INC);

    do
    {
        for(m=0; m<9; m++)
        {
			//Rearrange the byte order

            ucTemp[0] = (*(array + 1) << 4) | (*(array + 2) & 0x0f);
			ucTemp[1] = (*(array + 2) & 0xf0) | (*array & 0x0f);
			ucTemp[2] = (*array & 0xf0) | (*(array + 1) >> 4);

			for(n=0;n<3;n++)
			{
#if(PARALLEL_PORT)
				
#if(1)
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x01);
				bRTD_SDIO_1 = (bit)(ucTemp[n] & 0x02);
				bRTD_SDIO_2 = (bit)(ucTemp[n] & 0x04);
				bRTD_SDIO_3 = (bit)(ucTemp[n] & 0x08);
                bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x10);
				bRTD_SDIO_1 = (bit)(ucTemp[n] & 0x20);
				bRTD_SDIO_2 = (bit)(ucTemp[n] & 0x40);
				bRTD_SDIO_3 = (bit)(ucTemp[n] & 0x80);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = 1;
				bRTD_SDIO_1 = 1;
				bRTD_SDIO_2 = 1;
				bRTD_SDIO_3 = 1;
				bRTD_SCLK   = 1;
#else
				ucTemp1 = P0 & 0xf0;

				P0 = ucTemp1 | (ucTemp[n] & 0x0f);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				P0 = ucTemp1 | (ucTemp[n] >> 4);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				P0 = ucTemp1 | 0x0f;
				bRTD_SCLK   = 1;
#endif

#else
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x01);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x02);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x04);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x08);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x10);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x20);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x40);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = (bit)(ucTemp[n] & 0x80);
				bRTD_SCLK   = 1;
				bRTD_SCLK   = 0;
				bRTD_SDIO_0 = 1;
				bRTD_SCLK   = 1;
#endif
            }
            array += 3;
        }
    }
    while (--length);

	RTDSendStop();
}
#endif


#if(HDCP_ENABLE)
void KEYCodeW(unsigned char code *array)
{
    unsigned int m;  

   RTDSetBit(DVI_CTRL1_AF, 0x7f,0x00);  //Reset the HDCP key download index
   RTDSetBit(DVI_CTRL1_AF, 0x7f,0x80);
	
    for(m = 0; m < 320; m++)   //Key 0 ~ Key39   
    {
		RTDSetByte(0xb1,array[m]);
    }	

    RTDSetBit(DVI_CTRL1_AF, 0x7f,0x00);  //Disable the Key Access Download port
    RTDSetBit(TMDS_INPUT_ENA_A1, 0x7f, 0x00);   // Turn on HDCP DDC channel  
}
#endif
