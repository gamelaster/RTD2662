//**************************************程式更新步驟
/*
1.Lcd_main.c  <add>  #include "Uart.h"

2.Lcd_main.c  <add>  after main()~ UART_Initialize(); ~Firmware_Init();

3.Lcd_main.c  <add>  ISP_Check_Sum();~ PutStringToScr("\nMain Loop.."); ~Delay_Xms(250);

4.Lcd_main.c  <add>  if (bNotify_Timer0_Int) //20ms start~
        {            

		if(fTest==1)
		{
		fTest=0;
		DebugModeLoop();
		}
5.Lcd_func.h  <add> after unsigned char idata ucH_Min_Margin  = 0;
	unsigned char   idata   UartNum        = 0;
	unsigned char idata  UartData[4];	// data array for RTD/I2C R/W
	

6.Lcd_func.h  <add> after extern unsigned char idata  ucH_Min_Margin;
	extern unsigned char   idata   UartNum;
	extern unsigned char   idata   UartData[4];	
	

//**************************************Test
2.lcd_osd.h <add>  extern void OSD_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);

*/
//**************************************

#include "Header\Uart.h"
#include "reg52.h"
//#include "w78e365.h"
#include "Header\main_def.h"
#include "Header\Lcd_func.h"

#include "Header\osd.h"
#include "Header\access.h"
#include "Header\lcd_osd.h"
//#include "PCB\qa_pcb.h"
/*
#include "Header\Uart.h"
#include "reg52.h"
#include "intrins.h"

#include "Header\MAIN_DEF.H"
#include "Header\CONFIG.H"
#include "Header\ACCESS.H"
#include "Header\OSD.H"
#include "Header\LCD_COEF.H"
#include "Header\LCD_MAIN.H"
#include "Header\LCD_AUTO.H"
#include "Header\LCD_FUNC.H"
*/
//*******************************************************************
#if(RS232_DEBUG)
//unsigned char   idata   UartNum        = 0;
//unsigned char idata  UartData[4];	// data array for RTD/I2C R/W

unsigned char bdata byflag20 _at_ 0x20;
sbit    fTest = byflag20 ^ 0;

unsigned char bdata byflag21 _at_ 0x21;
sbit    fUart_Start = byflag21 ^ 0;
sbit    fUartStart   = byflag21 ^ 1;
sbit    fDebugModeEnable 	= byflag21 ^ 2;
//*******************************************************************

void UART_Initialize(void)
{
	EA    = 0;
//UartNum        = 0;
	//CHPENR  = 0x87;
	//CHPENR  = 0x59;
	//CHPCON |= 0x10;		// enable on-chip aux-ram
	//CHPENR  = 0x00;

	SCON  = 0x50;
	
	ES    = 1;
	PS    = 1;
        
	T2CON = 0x34;
//	RCAP2L = 0xb0;		//65536 - (crystal / baud * 32))
						// crystal = 24.576 MHZ
						// 9600 bps
	RCAP2L = 0xd8;					
	RCAP2H = 0xff;		
						
	EA  = 1;
}
// *************************************************************** //
void UART(void) interrupt 4 using 1
{
	ES = 0; // disable uart interrupt.
	if (TI)
    {
    	TI = 0;
	}
    else if (RI)
    {
    if(fUartStart==0)
    	{
	//m_RXBuffer[UartNum] = SBUF;
	UartData[0] = SBUF;
	
	switch(UartData[0])
		{
		case 0x5a: //進入debug
		case 0x5b://進入debug
		case 0x5c://進入debug
		case 0x5d://進入debug
		
			UartNum=1;
			fUartStart=1;
			break;
		default :
			fUartStart=0;
			break;
		}
				
    	}
    else
    	{
    	if(UartNum<=4)
    		{
    		UartData[UartNum] = SBUF;
    		UartNum++;
    		if(UartNum>4)
    			{
    			fTest=1;
    			fUartStart=0;
    			}
    		}
    	}
	//		}
	//	}
		RI = 0;
	}
	ES = 1;	// enable uart interrupt.
}
/*
{
	ES = 0; // disable uart interrupt.
	if (TI)
    {
    	TI = 0;
	}
    else if (RI)
    {
    if(fUartStart==0)
    	{
		UartData[0] = SBUF;
		//fTest=1;//debug
		switch(UartData[0])
			{
			case 0x5a: //進入debug
			case 0x5b://進入debug
			case 0x5c://進入debug
			case 0x5d://進入debug
		
				UartNum=1;
				fUartStart=1;
			break;
			default :
				fUartStart=0;
			break;	
			}
				
    	}
    else
    	{
    	if(UartNum<=4)
    		{
    		UartData[UartNum] = SBUF;
    		UartNum++;
    		if(UartNum>4)
    			{
    			fTest=1;
    			//UartNum=0;
    			fUartStart=0;
    			}
    		}
    	}
	
		RI = 0;
	}
	ES = 1;	// enable uart interrupt.
}
*/
// *************************************************************** //
/*
void UART(void) interrupt 4 using 1
{
	ES = 0; // disable uart interrupt.
	if (TI)
    {
    	TI = 0;
	}
    else if (RI)
    {
	//	const unsigned char incWRXIndex = m_WRXIndex + 1;
	//	if (incWRXIndex != m_RRXIndex)
	//	{
	//		if ((m_RRXIndex != -1) || (incWRXIndex < BUFFER_LEN/2))
	//		{	
	//			m_WRXIndex = incWRXIndex & (BUFFER_LEN/2-1);
	//			m_RXBuffer[m_WRXIndex] = SBUF;
				ATest=SBUF;
				fUart_Start=1;
	//			DispOSD_TestMessage();
	//		}
	//	}
		RI = 0;
	}
	ES = 1;	// enable uart interrupt.
}
*/
// *************************************************************** //不知為何需加這段程式才能工作
const unsigned char PutStringToScr(const unsigned char code* pstr)
{
	unsigned char idata StrIndex;
	for (StrIndex=0x00; *(pstr+StrIndex)!='\0'; StrIndex++)
	{
		if (*(pstr+StrIndex) == '\n')
			PutCharToScr('\r');
		PutCharToScr(*(pstr+StrIndex));
	}
	return StrIndex;
}

// *************************************************************** //
void PutCharToScr(const unsigned char ch)
{
	ES = 0;

 	SBUF = ch; // transfer UART

	while (!TI)
	{
		// wait buffer completing.
	}

	ES = 1;
	
	while (TI)
	{
		// wait transfer completing.
	}
}
// *************************************************************** //
void HexToBin(unsigned int HexData)
{
	unsigned long a;
	//HexData=0x1234;
 	 Data[12]=(HexData)&0x0F;
 	 Data[13]=(HexData>>4)&0x0F;
 	 Data[14]=(HexData>>8)&0x0F;
 	 Data[15]=(HexData>>12)&0x0F;
 	 a=(Data[14]*256)+(Data[13]*16)+Data[12];
 	 Data[0]=a%10;
 	 Data[1]=(a/10)%10;
 	 Data[2]=(a/100)%10;
 	 Data[3]=(a/1000)%10;
 	 Data[4]=(a/10000)%10;
 	 Data[5]=(a/100000)%10;
}

void DispOSD_TestMessage(void)
{

	int a=0,b=0;
	//RTDCodeW(OSD_Reset);
	 //RTDCodeW(OSD_Enable);
    //****************************************
    Data[0]     = 5;
    Data[1]     = Y_INC;
    Data[2]     = OSD_ROW_90;
    Data[3]     = 0xaf;
    Data[4]     = 0x0c;
    Data[5]     = 5;
    Data[6]     = N_INC;
    Data[7]     = OSD_DATA_92;
    Data[8]     = 0x30;//stGUD1.OSD_POSV; alantest
    Data[9]     = 0x30;//stGUD1.OSD_POSH; alantest
    Data[10]    = 0;
    RTDWrite(Data);  
    //**************************************** Set_osd_position
    OSD_Clear(2, 10, 2, 24);
    OSD_Window(3, 0, 14, 0, 29, OSD_WINDOW_ENABLE | OSD_WINDOW_SHADOWING, COLOR_YELLOW);  // Main OSD window
   //**************************************** Set OSD Window 
   
  #define TestFunction  0
  #if (TestFunction == 1)
  //*********************************
   for(a=0;a<15;a++)
   	{
   	 bRTD_SCSB   = 0;  
   	RTDSendAddr(OSD_ROW_90, 0, Y_INC);  
   	RTDSendByte(0x80|a);
   	RTDSendByte(2);
   	bRTD_SCLK   = 0; 
   	bRTD_SCLK   = 1;
   	bRTD_SCSB   = 1;
   
    	bRTD_SCSB   = 0; 
   	RTDSendAddr(OSD_DATA_92, 0, N_INC);
   	for(b=0;b<=15;b++)
   		RTDSendByte((a*16)+b);

   	bRTD_SCLK   = 0; 
    	bRTD_SCLK   = 1;
    	bRTD_SCSB   = 1;
   	}
  //*********************************
  #else
  //******************************* DISP ucMode_Curr
  	 bRTD_SCSB   = 0;  
   	RTDSendAddr(OSD_ROW_90, 0, Y_INC);  
   	RTDSendByte(0x82);
   	RTDSendByte(2);
   	bRTD_SCLK   = 0; 
   	bRTD_SCLK   = 1;
   	bRTD_SCSB   = 1;
   	
       bRTD_SCSB   = 0; 
   	RTDSendAddr(OSD_DATA_92, 0, N_INC);
   	HexToBin(UartData[0]);

	RTDSendByte(Data[5]+1);
	RTDSendByte(Data[4]+1);
   	RTDSendByte(Data[3]+1);
   	RTDSendByte(Data[2]+1);
   	RTDSendByte(Data[1]+1);
   	RTDSendByte(Data[0]+1);

   	bRTD_SCLK   = 0; 
    	bRTD_SCLK   = 1;
    	bRTD_SCSB   = 1;
   //******************************* DISP ucMode_Curr
  	 bRTD_SCSB   = 0;  
   	RTDSendAddr(OSD_ROW_90, 0, Y_INC);  
   	RTDSendByte(0x83);
   	RTDSendByte(2);
   	bRTD_SCLK   = 0; 
   	bRTD_SCLK   = 1;
   	bRTD_SCSB   = 1;
   	
       bRTD_SCSB   = 0; 
   	RTDSendAddr(OSD_DATA_92, 0, N_INC);
   	HexToBin(UartData[1]);

	RTDSendByte(Data[5]+1);
	RTDSendByte(Data[4]+1);
   	RTDSendByte(Data[3]+1);
   	RTDSendByte(Data[2]+1);
   	RTDSendByte(Data[1]+1);
   	RTDSendByte(Data[0]+1);

   	bRTD_SCLK   = 0; 
    	bRTD_SCLK   = 1;
    	bRTD_SCSB   = 1;
    	
  //******************************* DISP ucMode_Curr
  	 bRTD_SCSB   = 0;  
   	RTDSendAddr(OSD_ROW_90, 0, Y_INC);  
   	RTDSendByte(0x84);
   	RTDSendByte(2);
   	bRTD_SCLK   = 0; 
   	bRTD_SCLK   = 1;
   	bRTD_SCSB   = 1;
   	
       bRTD_SCSB   = 0; 
   	RTDSendAddr(OSD_DATA_92, 0, N_INC);
   	HexToBin(UartData[2]);

	RTDSendByte(Data[5]+1);
	RTDSendByte(Data[4]+1);
   	RTDSendByte(Data[3]+1);
   	RTDSendByte(Data[2]+1);
   	RTDSendByte(Data[1]+1);
   	RTDSendByte(Data[0]+1);

   	bRTD_SCLK   = 0; 
    	bRTD_SCLK   = 1;
    	bRTD_SCSB   = 1;
    	 //******************************* DISP ucMode_Curr
  	 bRTD_SCSB   = 0;  
   	RTDSendAddr(OSD_ROW_90, 0, Y_INC);  
   	RTDSendByte(0x85);
   	RTDSendByte(2);
   	bRTD_SCLK   = 0; 
   	bRTD_SCLK   = 1;
   	bRTD_SCSB   = 1;
   	
       bRTD_SCSB   = 0; 
   	RTDSendAddr(OSD_DATA_92, 0, N_INC);
   	HexToBin(UartData[3]);

	RTDSendByte(Data[5]+1);
	RTDSendByte(Data[4]+1);
   	RTDSendByte(Data[3]+1);
   	RTDSendByte(Data[2]+1);
   	RTDSendByte(Data[1]+1);
   	RTDSendByte(Data[0]+1);

   	bRTD_SCLK   = 0; 
    	bRTD_SCLK   = 1;
    	bRTD_SCSB   = 1;
    	 //******************************* DISP ucMode_Curr
  	 bRTD_SCSB   = 0;  
   	RTDSendAddr(OSD_ROW_90, 0, Y_INC);  
   	RTDSendByte(0x86);
   	RTDSendByte(2);
   	bRTD_SCLK   = 0; 
   	bRTD_SCLK   = 1;
   	bRTD_SCSB   = 1;
   	
       bRTD_SCSB   = 0; 
   	RTDSendAddr(OSD_DATA_92, 0, N_INC);
   	HexToBin(UartData[4]);

	RTDSendByte(Data[5]+1);
	RTDSendByte(Data[4]+1);
   	RTDSendByte(Data[3]+1);
   	RTDSendByte(Data[2]+1);
   	RTDSendByte(Data[1]+1);
   	RTDSendByte(Data[0]+1);

   	bRTD_SCLK   = 0; 
    	bRTD_SCLK   = 1;
    	bRTD_SCSB   = 1;
    	
  
  #endif
    
}

// *************************************************************** //
/*
1.into  debug mode  0x5a,0x01,0x02,0x03,0x04
2.exit  debug mode  0x5b,0x04,0x03,0x02,0x01
3.read  RTD         0x5c,0x74,address,count,index
4.read  other       0x5c,slave address,address,count,index
5.write rtd 	    0x5d,0x74,address,value,rever	
6.write other 	    0x5d,slave address,address,value,rever	
*/
// *************************************************************** //

void DebugModeLoop(void)
{
//DispOSD_TestMessage();
if(fDebugModeEnable==0)
	if(UartData[0]==0x5a)
		if(UartData[1]==0x01)
			if(UartData[2]==0x02)
				if(UartData[3]==0x03)
					if(UartData[4]==0x04)
						{
						fDebugModeEnable=1;
						DispOSD_TestMessage();
						}
	

while(fDebugModeEnable==1)
{
	if(fTest==1)
	{
	fTest=0;
		if(UartData[0]==0x5b)
			if(UartData[1]==0x04)
				if(UartData[2]==0x03)
					if(UartData[3]==0x02)
						if(UartData[4]==0x01)
							{
							fDebugModeEnable=0;
							  RTDOSDW(OSD_Reset);
							  RTDCodeW(OSD_Enable);
							break;
							}

		//****************debug mode main loop Start
		DispOSD_TestMessage();
		switch(UartData[0])
			{
			case 0x5c:
				if(UartData[1]==0x74)//read scaler    
					RTDRead(UartData[2], UartData[3], UartData[4]);  // Get status
				else 
					I2CRead(UartData[1], UartData[2] ,UartData[3]);

				PutCharToScr(UartData[3]);  //send 各數
				for(UartData[0]=0;UartData[0]<=UartData[3];UartData[0]++)//send data
					PutCharToScr(Data[UartData[0]]);
			break;
			case 0x5d:
				if(UartData[1]==0x74)//read scaler    
					RTDSetByte(UartData[2], UartData[3]);
				else
					{
					Data[0] = 4;
        			Data[1] = UartData[1];
        			Data[2] = UartData[2];
        			Data[3] = UartData[3];
        			I2CWrite(Data);
					}
			break;	
			}
					
		//****************debug mode main loop END
		
	}
	
}

}

// ***************************************************************//
#endif

