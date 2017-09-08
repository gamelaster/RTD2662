
#line 1 "Code\Lcd_auto.c" /0
 
 
  
#line 1 "C:\KEIL\C51\INC\REG52.H" /0






 
 
 
 
 
 
 sfr P0    = 0x80;
 sfr P1    = 0x90;
 sfr P2    = 0xA0;
 sfr P3    = 0xB0;
 sfr PSW   = 0xD0;
 sfr ACC   = 0xE0;
 sfr B     = 0xF0;
 sfr SP    = 0x81;
 sfr DPL   = 0x82;
 sfr DPH   = 0x83;
 sfr PCON  = 0x87;
 sfr TCON  = 0x88;
 sfr TMOD  = 0x89;
 sfr TL0   = 0x8A;
 sfr TL1   = 0x8B;
 sfr TH0   = 0x8C;
 sfr TH1   = 0x8D;
 sfr IE    = 0xA8;
 sfr IP    = 0xB8;
 sfr SCON  = 0x98;
 sfr SBUF  = 0x99;
 
 
 sfr T2CON  = 0xC8;
 sfr RCAP2L = 0xCA;
 sfr RCAP2H = 0xCB;
 sfr TL2    = 0xCC;
 sfr TH2    = 0xCD;
 
 
 
 
 sbit CY    = PSW^7;
 sbit AC    = PSW^6;
 sbit F0    = PSW^5;
 sbit RS1   = PSW^4;
 sbit RS0   = PSW^3;
 sbit OV    = PSW^2;
 sbit P     = PSW^0;  
 
 
 sbit TF1   = TCON^7;
 sbit TR1   = TCON^6;
 sbit TF0   = TCON^5;
 sbit TR0   = TCON^4;
 sbit IE1   = TCON^3;
 sbit IT1   = TCON^2;
 sbit IE0   = TCON^1;
 sbit IT0   = TCON^0;
 
 
 sbit EA    = IE^7;
 sbit ET2   = IE^5;  
 sbit ES    = IE^4;
 sbit ET1   = IE^3;
 sbit EX1   = IE^2;
 sbit ET0   = IE^1;
 sbit EX0   = IE^0;
 
 
 sbit PT2   = IP^5;
 sbit PS    = IP^4;
 sbit PT1   = IP^3;
 sbit PX1   = IP^2;
 sbit PT0   = IP^1;
 sbit PX0   = IP^0;
 
 
 sbit RD    = P3^7;
 sbit WR    = P3^6;
 sbit T1    = P3^5;
 sbit T0    = P3^4;
 sbit INT1  = P3^3;
 sbit INT0  = P3^2;
 sbit TXD   = P3^1;
 sbit RXD   = P3^0;
 
 
 sbit SM0   = SCON^7;
 sbit SM1   = SCON^6;
 sbit SM2   = SCON^5;
 sbit REN   = SCON^4;
 sbit TB8   = SCON^3;
 sbit RB8   = SCON^2;
 sbit TI    = SCON^1;
 sbit RI    = SCON^0;
 
 
 sbit T2EX  = P1^1;  
 sbit T2    = P1^0;  
 
 
 sbit TF2    = T2CON^7;
 sbit EXF2   = T2CON^6;
 sbit RCLK   = T2CON^5;
 sbit TCLK   = T2CON^4;
 sbit EXEN2  = T2CON^3;
 sbit TR2    = T2CON^2;
 sbit C_T2   = T2CON^1;
 sbit CP_RL2 = T2CON^0;
 
 
#line 3 "Code\Lcd_auto.c" /0
 
 
  
#line 1 "Header\MAIN_DEF.h" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\MAIN_DEF.h" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 "Header\MAIN_DEF.h" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 "Header\MAIN_DEF.h" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "Header\MAIN_DEF.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 "Header\MAIN_DEF.h" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 "Header\MAIN_DEF.h" /0
 
 
#line 157 "Header\MAIN_DEF.h" /1
  
 
#line 159 "Header\MAIN_DEF.h" /0
 
 
 
 
#line 163 "Header\MAIN_DEF.h" /1
  
 
#line 165 "Header\MAIN_DEF.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 "Header\MAIN_DEF.h" /1
  
 
#line 272 "Header\MAIN_DEF.h" /0
 
#line 273 "Header\MAIN_DEF.h" /1
  
 
#line 275 "Header\MAIN_DEF.h" /0
 
#line 276 "Header\MAIN_DEF.h" /1
  
 
#line 278 "Header\MAIN_DEF.h" /0
 
#line 279 "Header\MAIN_DEF.h" /1
  
 
#line 281 "Header\MAIN_DEF.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 5 "Code\Lcd_auto.c" /0
 
  
#line 1 "Header\ACCESS.H" /0
 
 
 
#line 4 "Header\ACCESS.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 90 "Header\ACCESS.H" /0
 
 
 extern unsigned char data Data[16];
 
 
 extern void BitDly(void);
 extern void SetPortBit(unsigned char port, unsigned char and, unsigned char or);
 extern void SetSFRPort(unsigned char port, unsigned char Data);
 extern unsigned char GetSFRPort(unsigned char port);
 
 extern unsigned char I2CGetByte(unsigned char ack);
 extern void I2CSendByte(unsigned char send);
 extern void I2CSendAddr(unsigned char addr, unsigned char index ,unsigned char rd);
 extern void I2CSendStop(void);
 extern void I2CRead(unsigned char addr, unsigned char index, unsigned char count);
 extern void I2CWrite(unsigned char *array);
 
 extern unsigned char RTDGetByte(void);
 extern void RTDSendByte(unsigned char send);                                     
 extern void RTDSendAddr(unsigned char addr, unsigned char rd, unsigned char inc); 
 extern void RTDRead(unsigned char index, unsigned char count, unsigned char inc);
 extern void RTDWrite(unsigned char data *array);
 extern void RTDCodeW(unsigned char code *array);
 extern void RTDOSDW(unsigned char code *array);
 extern void RTDOSDW(unsigned char code *array);
 
 extern void RTDSetBit(unsigned char addr,unsigned char and, unsigned char or); 
 extern void RTDSetByte(unsigned char addr, unsigned char val);
 
 
 extern void Load_Font(unsigned char code *array, unsigned int start, unsigned int length);
 extern void Load_VLC_Font(unsigned char code *array, unsigned int start, unsigned int length);
 
 
#line 124 "Header\ACCESS.H" /1
 
 
#line 126 "Header\ACCESS.H" /0
 
 
#line 128 "Header\ACCESS.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 






 
 
 
 
 
 
 
#line 159 "Header\ACCESS.H" /0
 
 
#line 6 "Code\Lcd_auto.c" /0
 
  
#line 1 "Header\LCD_MAIN.H" /0
  
#line 1 "HEADER\Timer.h" /0
  
#line 1 "HEADER\Main_def.h" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 "HEADER\Main_def.h" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 "HEADER\Main_def.h" /0
 
 
#line 157 "HEADER\Main_def.h" /1
  
 
#line 159 "HEADER\Main_def.h" /0
 
 
 
 
#line 163 "HEADER\Main_def.h" /1
  
 
#line 165 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 "HEADER\Main_def.h" /1
  
 
#line 272 "HEADER\Main_def.h" /0
 
#line 273 "HEADER\Main_def.h" /1
  
 
#line 275 "HEADER\Main_def.h" /0
 
#line 276 "HEADER\Main_def.h" /1
  
 
#line 278 "HEADER\Main_def.h" /0
 
#line 279 "HEADER\Main_def.h" /1
  
 
#line 281 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "HEADER\Timer.h" /0
 
 
 
 
 
 
 
 
#line 9 "HEADER\Timer.h" /1
 
  
  
 
#line 13 "HEADER\Timer.h" /0
 
 
 
 
 
 
 
#line 20 "HEADER\Timer.h" /1
 
  
  
 
 
#line 25 "HEADER\Timer.h" /0
 
 
 
 
 
 
 
 
 
 
#line 35 "HEADER\Timer.h" /1
 
  
  
  
 
 
#line 41 "HEADER\Timer.h" /0
 
 
#line 43 "HEADER\Timer.h" /1
 
 
 
 
 

















 
 
 
#line 68 "HEADER\Timer.h" /0
 
 extern bit bNotify_Timer0_Int;
 extern bit bNotify_Timer1_Int;
 extern void Delay_Xms(unsigned char x);     
 
#line 1 "Header\LCD_MAIN.H" /0
 
  
#line 1 "HEADER\Power_Ctrl.h" /0
 
 
 
 
 
 
 
 
 
 
 
#line 12 "HEADER\Power_Ctrl.h" /1
 
 
 
 
 
 
 
 
#line 20 "HEADER\Power_Ctrl.h" /0
 
 extern bit bPower_Status;     
 extern bit bPanel_Status;
 
 extern void PowerDown_ADC(void);
 extern void PowerUp_ADC(void);
 extern void PowerDown_VDC(void);
 extern void PowerUp_VDC(void);
 extern void PowerDown_LVDS(void);
 extern void PowerUp_LVDS(void);
 extern void PowerDown_TMDS(void);
 extern void PowerUp_TMDS(void);
 
 extern void Set_Panel(unsigned char status);
 extern bit Power_Control(unsigned char Notify);
 
 
 
 
#line 2 "Header\LCD_MAIN.H" /0
 
  
#line 1 "HEADER\Mode_Detect.h" /0
 
#line 2 "HEADER\Mode_Detect.h" /1






 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 64 "HEADER\Mode_Detect.h" /0
 
 extern bit bVpole_Curr;
 extern bit bHpole_Curr;
 extern bit bStable;     
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
 
 extern void New_Mode_Auto(void);		 
 extern unsigned int    idata   ucfrist ;			 
 
 
#line 3 "Header\LCD_MAIN.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 






 
 
 
#line 32 "Header\LCD_MAIN.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 86 "Header\LCD_MAIN.H" /0
 
 
 extern bit bReload;
 
 
#line 91 "Header\LCD_MAIN.H" /1
 
 
 
#line 94 "Header\LCD_MAIN.H" /0
 
 extern unsigned int     idata   usOSD_Timer;
 extern unsigned int     idata   usTaskCnt;
 extern unsigned char    idata   ucID_Code;
 
 
 
 
 extern void ISP_Check_Sum(void);
 extern void Set_Task(unsigned char state);
 
 
 
#line 7 "Code\Lcd_auto.c" /0
 
  
#line 1 "Header\CONFIG.H" /0
 
 
 
 
 
 
 
 
 
 
#line 11 "Header\CONFIG.H" /1
  
  
  
 
#line 15 "Header\CONFIG.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 30 "Header\CONFIG.H" /1
  
 
#line 32 "Header\CONFIG.H" /0
 
 
#line 34 "Header\CONFIG.H" /1
 
 
  
 
 
 
  
 
 
 
#line 44 "Header\CONFIG.H" /0
 
 
 
 
#line 48 "Header\CONFIG.H" /1
 
 
  
 
 
 
  
 
 
 
  
 
 
 
  
 
 
 
  
 
 
 
#line 70 "Header\CONFIG.H" /0
 
 
#line 72 "Header\CONFIG.H" /1
  
 
#line 74 "Header\CONFIG.H" /0
 
#line 75 "Header\CONFIG.H" /1
  
 
#line 77 "Header\CONFIG.H" /0
 
#line 78 "Header\CONFIG.H" /1
  
 
#line 80 "Header\CONFIG.H" /0
 
 
#line 82 "Header\CONFIG.H" /1
  
 
#line 84 "Header\CONFIG.H" /0
 
 
#line 86 "Header\CONFIG.H" /1
  
 
#line 88 "Header\CONFIG.H" /0
 
 
  
#line 1 "Display\DISP_B6.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
















 
 
 
 
 
#line 92 "Display\DISP_B6.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
 
 
 
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 562 "Display\DISP_B6.H" /0
 
 extern unsigned char code RTD_PWUP_INI[];
 extern unsigned char code RTD_DDC_TABLE[];
 extern unsigned char code RTD_IO_INI[];
 
 extern unsigned char code FreeV[];
 extern unsigned char code OSD_PWUP_INI[];
 
 extern unsigned int code VGA_Mode[][6];
 extern unsigned int code Mode_Preset[][5];
 
 extern unsigned char code RTD_VIDEO_60[];
 extern unsigned char code RTD_VIDEO_50[];
 
 
#line 90 "Header\CONFIG.H" /0
 
 
 
 
#line 94 "Header\CONFIG.H" /1
  
 
#line 96 "Header\CONFIG.H" /0
 
 
 
 
 
 
#line 102 "Header\CONFIG.H" /1
  
 
#line 104 "Header\CONFIG.H" /0
 
 
#line 106 "Header\CONFIG.H" /1
  
 
#line 108 "Header\CONFIG.H" /0
 
 
  
#line 1 "PCB\2523d1_pcb.h" /0
  
#line 1 "Header\main_def.h" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\main_def.h" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 "Header\main_def.h" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 "Header\main_def.h" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "Header\main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 "Header\main_def.h" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 "Header\main_def.h" /0
 
 
#line 157 "Header\main_def.h" /1
  
 
#line 159 "Header\main_def.h" /0
 
 
 
 
#line 163 "Header\main_def.h" /1
  
 
#line 165 "Header\main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 "Header\main_def.h" /1
  
 
#line 272 "Header\main_def.h" /0
 
#line 273 "Header\main_def.h" /1
  
 
#line 275 "Header\main_def.h" /0
 
#line 276 "Header\main_def.h" /1
  
 
#line 278 "Header\main_def.h" /0
 
#line 279 "Header\main_def.h" /1
  
 
#line 281 "Header\main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "PCB\2523d1_pcb.h" /0
 
 
 
  
#line 1 "Header\MTV512.h" /0
  
#line 1 "HEADER\Main_def.h" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 "HEADER\Main_def.h" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 "HEADER\Main_def.h" /0
 
 
#line 157 "HEADER\Main_def.h" /1
  
 
#line 159 "HEADER\Main_def.h" /0
 
 
 
 
#line 163 "HEADER\Main_def.h" /1
  
 
#line 165 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 "HEADER\Main_def.h" /1
  
 
#line 272 "HEADER\Main_def.h" /0
 
#line 273 "HEADER\Main_def.h" /1
  
 
#line 275 "HEADER\Main_def.h" /0
 
#line 276 "HEADER\Main_def.h" /1
  
 
#line 278 "HEADER\Main_def.h" /0
 
#line 279 "HEADER\Main_def.h" /1
  
 
#line 281 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\MTV512.h" /0
 
 
 
 
 
 
 
 
 
 extern unsigned char xdata byMTV512_DDCRAMA[128];   
 extern unsigned char xdata byMTV512_DDCRAMB[128];   
 
 
 
 
 
 extern   unsigned char xdata M512_PadMode0;      
 extern   unsigned char xdata M512_PadMode1;      
 extern   unsigned char xdata M512_PadMode2;      
 extern   unsigned char xdata M512_PadMode3;      
 extern   unsigned char xdata M512_PadMode4;      
 extern   unsigned char xdata M512_PadMode5;      
 extern   unsigned char xdata M512_Option1;
 extern   unsigned char xdata M512_PadMode6; 
 extern   unsigned char xdata M512_PadMode7; 
 
 extern   unsigned char xdata M512_Port40;      
 extern   unsigned char xdata M512_Port41;      
 extern   unsigned char xdata M512_Port42;      
 
 
 
 
 
 
 
 extern   unsigned char xdata M512_Port50;      
 extern   unsigned char xdata M512_Port51;      
 extern   unsigned char xdata M512_Port52;      
 extern   unsigned char xdata M512_Port53;      
 extern   unsigned char xdata M512_Port54;      
 extern   unsigned char xdata M512_Port55;      
 extern   unsigned char xdata M512_Port56;      
 
 extern   unsigned char xdata M512_Port60;      
 extern   unsigned char xdata M512_Port61;      
 extern   unsigned char xdata M512_Port62;      
 extern   unsigned char xdata M512_Port63;      
 extern   unsigned char xdata M512_Port64;      
 extern   unsigned char xdata M512_Port65;      
 extern   unsigned char xdata M512_Port66;      
 extern   unsigned char xdata M512_Port67;      
 
 extern   unsigned char xdata M512_Port76;	  
 extern   unsigned char xdata M512_Port77;	  
 
 extern   unsigned char xdata M512_DA0;      
 extern   unsigned char xdata M512_DA1;      
 extern   unsigned char xdata M512_DA2;      
 extern   unsigned char xdata M512_DA3;      
 extern   unsigned char xdata M512_DA4;      
 extern   unsigned char xdata M512_DA5;      
 extern   unsigned char xdata M512_DA6;      
 extern   unsigned char xdata M512_DA7;      
 extern   unsigned char xdata M512_DA8;      
 extern   unsigned char xdata M512_DA9;      
 extern   unsigned char xdata M512_DA10;      
 extern   unsigned char xdata M512_DA11;      
 extern   unsigned char xdata M512_DA12;      
 extern   unsigned char xdata M512_DA13;      
 
 
 extern   unsigned char xdata M512_HVSTUS;      
 extern   unsigned char xdata M512_HCNTH;      
 extern   unsigned char xdata M512_HCNTL;      
 extern   unsigned char xdata M512_VCNTH;      
 extern   unsigned char xdata M512_VCNTL;      
 extern   unsigned char xdata M512_INTFLG;      
 extern   unsigned char xdata M512_INTEN;      
 
 
 
 extern   unsigned char xdata M512_IIC_CTR;      
 extern   unsigned char xdata M512_IIC_STUS1;      
 extern   unsigned char xdata M512_IIC_STUS2;      
 extern   unsigned char xdata M512_IIC_INTFLG;      
 extern   unsigned char xdata M512_IIC_INTEN;      
 extern   unsigned char xdata M512_IIC_MBUF;      
 extern   unsigned char xdata M512_IIC_TXRCABUF;      
 extern   unsigned char xdata M512_IIC_SLVAADR;      
 extern   unsigned char xdata M512_IIC_TXRCBBUF;      
 extern   unsigned char xdata M512_IIC_SLVBADR;      
 
 extern   unsigned char xdata M512_ISPSLV;      
 extern   unsigned char xdata M512_ISPEN;      
 
 
 
 
 extern   unsigned char xdata M512_ADC;      
 extern   unsigned char xdata M512_WDT;      
 extern   unsigned char xdata EINT1PEN ;    
 
 
#line 105 "Header\MTV512.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 130 "Header\MTV512.h" /0
 
 
 
 
 
 
 
 
#line 4 "PCB\2523d1_pcb.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
#line 16 "PCB\2523d1_pcb.h" /1
  
  
 
#line 19 "PCB\2523d1_pcb.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 33 "PCB\2523d1_pcb.h" /1























































 
 
#line 90 "PCB\2523d1_pcb.h" /0
 
 





























































 
 
 sbit bRTD_SDIO_0	= 0x90;
 
 
#line 158 "PCB\2523d1_pcb.h" /1
 
 
 
 
#line 162 "PCB\2523d1_pcb.h" /0
 
 sbit bRTD_SCLK		= 0x94;
 sbit bRTD_SCSB		= 0x95;
 sbit bIIC_SCL			= 0x96;
 sbit bIIC_SDA		= 0x97;
 
 sbit bDDC_SCL		= 0xb0;
 sbit bDDC_SDA		= 0xb1;
 
 sbit bRTD_RST		= 0xb2;
 sbit bRIGHT_KEY		= 0xb4;
 sbit bLEFT_KEY		= 0xb5;
 
 
 
 
 
 
 
 
#line 182 "PCB\2523d1_pcb.h" /1
  
  
 
#line 185 "PCB\2523d1_pcb.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 217 "PCB\2523d1_pcb.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
 
  
 
  
  
  
  
 
  
  
 
 
 
 
 
 
 
  
 
 
  
 
 
  
 
 
  
 
 
  
 
 
  
 
 
  
 
 
 
#line 282 "PCB\2523d1_pcb.h" /0
 
 
#line 110 "Header\CONFIG.H" /0
 
 
 
 
#line 114 "Header\CONFIG.H" /1
  
 
#line 116 "Header\CONFIG.H" /0
 
 
#line 118 "Header\CONFIG.H" /1
  
 
#line 120 "Header\CONFIG.H" /0
  
#line 1 "HEADER\VDC_CFG.H" /0
 
#line 2 "HEADER\VDC_CFG.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1229 "HEADER\VDC_CFG.H" /0
 
 extern unsigned char code V_NOWORK[];
 extern unsigned char code V_DISABLE[];
 extern unsigned char code V_ENABLE[];
 
 extern unsigned char code AV_DETECT[];
 extern unsigned char code SV_DETECT[];
 
 extern unsigned char code YUV_DETECT[];
 
 extern unsigned char code AV_60_0[];
 extern unsigned char code AV_60_1[];
 extern unsigned char code AV_60_2[];
 extern unsigned char code AV_60_3[];
 extern unsigned char code AV_60_4[];
 extern unsigned char code AV_50_0[];
 extern unsigned char code AV_50_1[];
 extern unsigned char code AV_50_2[];
 extern unsigned char code AV_50_3[];
 extern unsigned char code AV_50_4[];
 extern unsigned char code AV_SECAM[];
 
 extern unsigned char code SV_60_0[];
 extern unsigned char code SV_60_1[];
 extern unsigned char code SV_60_2[];
 extern unsigned char code SV_60_3[];
 extern unsigned char code SV_60_4[];
 extern unsigned char code SV_50_0[];
 extern unsigned char code SV_50_1[];
 extern unsigned char code SV_50_2[];
 extern unsigned char code SV_50_3[];
 extern unsigned char code SV_50_4[];
 extern unsigned char code SV_SECAM[];
 
 extern unsigned char code VIDEO_ALL[];
 extern unsigned char code VIDEO_YUV[];
 extern unsigned char code VIDEO_60[];
 extern unsigned char code VIDEO_50[];
 
 extern unsigned char code TV_SOURCE_SEL[];
 extern unsigned char code TV_SCAN_GAIN[];
 extern unsigned char code TV_DISP_GAIN[];
 
 
#line 120 "Header\CONFIG.H" /0
 
 
 
 
#line 124 "Header\CONFIG.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 435 "Header\CONFIG.H" /0
 
 extern unsigned int code CAP_WIN[][5];
 extern unsigned int code ADC_SD_SET[][3];
 
 extern unsigned char code VGA_INI_SS[];
 extern unsigned char code VGA_INI_CS[];
 extern unsigned char code VGA_INI_SOG[];
 extern unsigned char code VIDEO_INI[];
 extern unsigned char code DVI_INI[];
 extern unsigned char code VGA_SET_SS[];
 extern unsigned char code VGA_SET_CS[];
 extern unsigned char code VGA_SET_SOG[];
 extern unsigned char code LVDS_POWERUP[];
 extern unsigned char code LVDS_POWERDOWN[];
 extern unsigned char code Palette_Open[];
 extern unsigned char code Palette_Close[]; 
 extern unsigned char code Palette_1[];
 extern unsigned char code Palette_2[];
 extern unsigned char code Palette_3[];
 extern unsigned char code Palette_4[];
 extern unsigned char code Palette_5[];
 extern unsigned char code Palette_6[];
 extern unsigned char code Palette_7[];
 extern unsigned char code DCLK_OFFSET[16];
 
 
#line 8 "Code\Lcd_auto.c" /0
 
  
#line 1 "Header\LCD_FUNC.H" /0
  
#line 1 "HEADER\Main_def.h" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 "HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 "HEADER\Main_def.h" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 "HEADER\Main_def.h" /0
 
 
#line 157 "HEADER\Main_def.h" /1
  
 
#line 159 "HEADER\Main_def.h" /0
 
 
 
 
#line 163 "HEADER\Main_def.h" /1
  
 
#line 165 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 "HEADER\Main_def.h" /1
  
 
#line 272 "HEADER\Main_def.h" /0
 
#line 273 "HEADER\Main_def.h" /1
  
 
#line 275 "HEADER\Main_def.h" /0
 
#line 276 "HEADER\Main_def.h" /1
  
 
#line 278 "HEADER\Main_def.h" /0
 
#line 279 "HEADER\Main_def.h" /1
  
 
#line 281 "HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\LCD_FUNC.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef struct _GLOBAL_USER_DATA0
 {
 unsigned char CONTRAST;          
 unsigned char BRIGHT;            
 unsigned char RTD_R_CONTRAST;    
 unsigned char RTD_G_CONTRAST;    
 unsigned char RTD_B_CONTRAST;    
 unsigned char RTD_R_BRIGHT;      
 unsigned char RTD_G_BRIGHT;      
 unsigned char RTD_B_BRIGHT;      
 }
 GLOBAL_USER_DATA0, *LP_GLOBAL_USER_DATA0;
 
 typedef struct _GLOBAL_USER_DATA1
 {
 unsigned char FUNCTION;          
 
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char INPUT_SOURCE;      
 
 
 
 
 
 
 
 
 
 
 unsigned char FILTER;            
 unsigned int  OSD_POSH;          
 unsigned char OSD_POSV;          
 unsigned char OSD_TIMEOUT;       
 
 unsigned char OSD_INPUT;	     
 
 
 
 }
 GLOBAL_USER_DATA1, *LP_GLOBAL_USER_DATA1;
 
 
 typedef struct _GLOBAL_USER_DATA2
 {
 unsigned char AD_R_GAIN;         
 unsigned char AD_G_GAIN;         
 unsigned char AD_B_GAIN;         
 unsigned char AD_R_OFFSET;       
 unsigned char AD_G_OFFSET;       
 unsigned char AD_B_OFFSET;       
 }
 GLOBAL_USER_DATA2, *LP_GLOBAL_USER_DATA2;
 
 typedef struct _GLOBAL_USER_DATA3
 {
 unsigned char VOLUME;            
 unsigned char CURR_CHANNEL;      
 unsigned char PREV_CHANNEL;      
 unsigned char TV_SETTING;        
 
 
 
 
 
 
 
 
 
 
 
 unsigned char SPREAD;			 
 }
 GLOBAL_USER_DATA3, *LP_GLOBAL_USER_DATA3;
 
 typedef struct _GLOBAL_USER_DATA4     
 {
 unsigned char C1_R;               
 unsigned char C1_G;               
 unsigned char C1_B;               
 unsigned char C2_R;               
 unsigned char C2_G;               
 unsigned char C2_B;               
 unsigned char C3_R;               
 unsigned char C3_G;               
 unsigned char C3_B;               
 }
 GLOBAL_USER_DATA4, *LP_GLOABL_USER_DATA4;
 
 typedef struct _RGB_MODE_USER_DATA       
 {
 unsigned char H_POSITION;    
 unsigned char V_POSITION;    
 unsigned char CLOCK;         
 unsigned char PHASE;         
 }
 RGB_MODE_USER_DATA, *LP_RGB_MODE_USER_DATA;
 
 typedef struct _VIDEO_MODE_USER_DATA     
 {
 unsigned char VBRIGHT;       
 unsigned char VCONTRAST;     
 unsigned char VSATURATION;   
 unsigned char VHUE;          
 }
 VIDEO_MODE_USER_DATA, *LP_VIDEO_MODE_USER_DATA;
 
 
 
#line 134 "Header\LCD_FUNC.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 313 "Header\LCD_FUNC.H" /0
 
 
 
 
 extern GLOBAL_USER_DATA0    data    stGUD0;
 extern GLOBAL_USER_DATA1    data    stGUD1;
 extern GLOBAL_USER_DATA2    data    stGUD2;
 extern GLOBAL_USER_DATA3    data    stGUD3;
 extern GLOBAL_USER_DATA4    data    stGUD4;
 extern RGB_MODE_USER_DATA   data    stMUD;
 
 extern unsigned int  idata  usIPH_ACT_STA;
 extern unsigned int  idata  usIPV_ACT_STA;
 extern unsigned int  idata  usIPH_ACT_WID;
 extern unsigned int  idata  usIPV_ACT_LEN;
 
 extern unsigned int  idata  usADC_Clock;
 extern unsigned int  idata  usDH_Total;
 extern unsigned int  idata  usDV_Total;
 extern unsigned char idata  ucDV_Delay;
 
 extern unsigned char idata  ucV_Max_Margin;
 extern unsigned char idata  ucV_Min_Margin;
 extern unsigned char idata  ucH_Max_Margin;
 extern unsigned char idata  ucH_Min_Margin;
 extern unsigned char   idata   UartNum;
 extern unsigned char   idata   UartData[4];	
 
 
 
 extern void SetMute(bit val);
 extern void SetVolume();
 
 extern void WriteGamma(unsigned char code *arrayR, unsigned char code *arrayG, unsigned char code *arrayB);
 extern void WriteDither(unsigned char code *array);
 extern void WriteSU_COEF(unsigned char code *arrayH, unsigned char code *arrayV);
 
 extern void Set_H_Position(void);
 extern void Set_V_Position(void);
 extern void Set_Clock(void);
 extern void Set_Phase(unsigned char phase);
 extern void Set_Bright_Contrast(void);
 extern void Set_Gamma(void);
 extern void Set_Dithering(void);
 extern void Sharpness(void);
 extern void Set_Mode_Params(void);
 
 extern void SetADC_VCO(unsigned char ucRate);
 extern void SetADC_Gain(void);
 extern void SetADC_Offset(void);
 extern void SetADC_GainOffset(void);
 
#line 365 "Header\LCD_FUNC.H" /1
 
 
#line 367 "Header\LCD_FUNC.H" /0
 
 extern void Wait_For_Event(unsigned char event);
 
 
 
 extern void Save_GUD0(void);
 extern void Load_GUD0(void);
 extern void Save_GUD1(void);
 extern void Load_GUD1(void);
 extern void Save_GUD2(void);
 extern void Load_GUD2(void);
 extern void Save_GUD3(void);
 extern void Load_GUD3(void);
 extern void Save_GUD4(void);	 
 extern void Load_GUD4(void);	 
 extern void Save_MUD(unsigned char mode_num);
 extern void Load_MUD(unsigned char mode_num);
 extern void Init_GUD(void);
 extern void Init_MUD(void);
 extern void Check_EEPROM(void);
 extern unsigned char code INIT_EEPROM2[]; 
 extern void RTD_Test(void);
 extern void Free_Background(void);
 extern void Reset_Mode(void);
 
 
 
 extern void Set_Spread(void);
 extern void Init_FACTORY(void);
 extern void Init_FRecall(void);
 
 
 
 
 
#line 402 "Header\LCD_FUNC.H" /1
 
 
 
 
#line 406 "Header\LCD_FUNC.H" /0
 
 
#line 9 "Code\Lcd_auto.c" /0
 
  
#line 1 "Header\LCD_AUTO.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char code  ADC_DEFAULT[] =
 {   
 9,  0,   0xE0, 0x78, 0x78, 0x78, 0x80, 0x80, 0x80,
 0
 };
 
 bit bAutoInProgress = 0;
 
 unsigned int idata  usVer_Start = 0;     
 unsigned int idata  usVer_End   = 0;     
 unsigned int idata  usH_Start   = 0;     
 unsigned int idata  usH_End     = 0;     
 
 void Wait_Finish(void);
 unsigned char Auto_Phase(void);
 unsigned char Auto_Phase_Do(unsigned char NM);
 
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
 
 
#line 107 "Header\LCD_AUTO.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 10 "Code\Lcd_auto.c" /0
#line 10 "Code\Lcd_auto.c" /0
 
  
#line 1 "Header\LCD_OSD.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 24 "Header\LCD_OSD.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 90 "Header\LCD_OSD.H" /0
 
 extern unsigned char    idata   ucOSD_Page_Index;
 extern unsigned char    idata   ucOSD_Item_Index0;
 extern unsigned char    idata   ucOSD_Item_Index1;
 extern unsigned char    idata   ucOSD_Item_Index2;
 
 extern unsigned char   idata   ucOSD_Pre_Page_Index;
 
#line 98 "Header\LCD_OSD.H" /1
 
 
 
 
#line 102 "Header\LCD_OSD.H" /0
 
 
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
 
 
 
 extern void OSD_Fact_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate); 
 extern void OSD_Fact_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width); 
 extern void OSD_Position(unsigned char para);				 
 extern void Value_Adjust(unsigned char *Var, unsigned char Key, unsigned char VMax, unsigned char VMin); 
 
 
 
 
 
#line 11 "Code\Lcd_auto.c" /0
 
 
 
 void Wait_Finish(void)
 {
 unsigned char   Wait_Time_Cnt, IVS_Event;
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 
 
 Wait_Time_Cnt   = 60;            
 IVS_Event       = 25;            
 do
 {  
 Delay_Xms(1);
 






















































 
 RTDRead(0x7F, 1, 1);
 }
 while ((Data[0] & 0x01) && (--Wait_Time_Cnt));
 
 RTDRead(0x01, 1, 1);   
 
 
 if(Data[0])
 RTDSetByte(0x01,0x00);  
 
 
 
 
 
 
 
 Data[0] = (Data[0] & 0x63) ? 0xfc : (0 == Wait_Time_Cnt) ? 0xfd : 0x00;
 }
 
 
 void Wait_For_IVS(void)
 {
 unsigned char t;
 
 t = 50;
 
 RTDSetByte(0x1f,0x00);
 do
 {
 RTDRead(0x1f, 1, 0);
 Data[0] = Data[0] & 0x01;
 
 Delay_Xms(1);
 }while((Data[0] == 0) && (t--));
 }
 
 
 
 
 
 
 
 
 
 unsigned char Measure_PositionV(unsigned char NM_V)
 {
 unsigned int    usLBound, usRBound;
 
 RTDRead(0x51, 0x02, 0);
 Data[2] = Data[1] & 0x0f;
 Data[3] = Data[0];
 
 usRBound    = usADC_Clock + (unsigned int)stMUD.CLOCK - 128;
 usLBound    = (unsigned long)usRBound * ((unsigned int *)Data)[1] / usStdHS;
 
 
 
 
 
 usRBound    = usRBound - 2 + 10 - 6 + ucH_Min_Margin - stMUD.H_POSITION;
 usLBound    = usLBound + 20 + ucH_Min_Margin + 10;
 usLBound    = usLBound > ((unsigned int)stMUD.H_POSITION + 6) ? (usLBound - 6 - stMUD.H_POSITION) : 1;
 
 NM_V        = NM_V & 0xfc;
 
 Data[0]     = 6;
 Data[1]     = 0;
 Data[2]     = 0x75;
 Data[3]     = (unsigned char)usLBound;
 Data[4]     = (unsigned char)usRBound;
 Data[5]     = ((unsigned char)(usLBound >> 4) & 0x70) | ((unsigned char)(usRBound >> 8) & 0x0f);    
 Data[6]     = 8;
 Data[7]     = 0;
 Data[8]     = 0x7B;
 Data[9]     = NM_V;
 Data[10]    = NM_V | 0x00;
 Data[11]    = NM_V;
 Data[12]    = 0x00;
 Data[13]    = 0x01;
 Data[14]    = 0;
 RTDWrite(Data);
 
 Wait_Finish();
 
 
 if (0x00 != Data[0])   return Data[0];
 
 RTDRead(0x80, 4, 0);
 
 
 Data[6] = Data[1] & 0x0f;
 Data[7] = Data[0];
 Data[8] = Data[3] & 0x0f;
 Data[9] = Data[2];
 
 
 usVer_Start     = ((unsigned int *)Data)[3] ? ((unsigned int *)Data)[3] - 1 : 0;
 usVer_End       = ((unsigned int *)Data)[4] ? ((unsigned int *)Data)[4] - 1 : 0;
 
 
 if (0x0000 == usVer_End)    return  0xf8;
 









 
 if ((9 - 3) > usVer_Start)
 {
 ((unsigned int *)Data)[3]	= 9 - 3;
 }
 else
 {
 
 if (usVer_End > (usVer_Start + usIPV_ACT_LEN - 1))
 {
 usVer_End   = usVer_Start + usIPV_ACT_LEN - 1;
 
 ((unsigned int *)Data)[4]   = usVer_End;
 }
 }
 
 
 Data[0] = 6;
 Data[1] = 0;
 Data[2] = 0x78;
 Data[3] = Data[7];    
 Data[4] = Data[9];
 Data[5] = (Data[6] << 4) + Data[8];
 Data[6] = 0;
 RTDWrite(Data);
 
 return 0x00;
 }
 
 
 
 
 
 
 
 
 unsigned char Measure_PositionH(unsigned char NM_H)
 {
 unsigned int    usLBound, usRBound;
 
 RTDRead(0x51, 0x02, 0);
 Data[2] = Data[1] & 0x0f;
 Data[3] = Data[0];
 
 usRBound    = usADC_Clock + (unsigned int)stMUD.CLOCK - 128;
 usLBound    = (unsigned long)usRBound * ((unsigned int *)Data)[1] / usStdHS;
 
 usRBound    = usRBound - 2 + 10 - 6 + ucH_Min_Margin - stMUD.H_POSITION;
 
 usLBound    = usLBound + 20 + ucH_Min_Margin + 10;
 usLBound    = usLBound > ((unsigned int)stMUD.H_POSITION + 6) ? (usLBound - 6 - stMUD.H_POSITION) : 1;
 
 NM_H        = NM_H & 0xfc;
 
 Data[0]     = 6;
 Data[1]     = 0;
 Data[2]     = 0x75;
 Data[3]     = (unsigned char)usLBound;
 Data[4]     = (unsigned char)usRBound;
 Data[5]     = ((unsigned char)(usLBound >> 4) & 0x70) | ((unsigned char)(usRBound >> 8) & 0x0f);    
 Data[6]     = 8;
 Data[7]     = 0;
 Data[8]     = 0x7B;
 Data[9]     = NM_H;
 Data[10]    = NM_H;
 Data[11]    = NM_H;
 Data[12]    = 0x00;
 Data[13]    = 0x01;
 Data[14]    = 0;
 RTDWrite(Data);
 
 Wait_Finish();
 
 if (0x00 != Data[0])   return Data[0];
 
 RTDRead(0x84, 4, 0);
 
 
 Data[4] = Data[3] & 0x0f;
 Data[5] = Data[2];
 Data[2] = Data[1] & 0x0f;
 Data[3] = Data[0];
 
 if (0x07FF <= ((unsigned int *)Data)[1])     return  0xf8;
 
 
 RTDRead(0x04, 1, 1);
 
 
 if (0x08 == (Data[0] & 0x0c))
 {
 ((unsigned int *)Data)[1]   += 0x03;
 ((unsigned int *)Data)[2]   += 0x03;
 }
 






 
 
 usH_Start   = (((unsigned int *)Data)[1] + stMUD.H_POSITION) >= (128 + (10 - 3))
 ? (((unsigned int *)Data)[1] + stMUD.H_POSITION) - (128 + (10 - 3)) : 0x0000;
 usH_End     = (((unsigned int *)Data)[2] + stMUD.H_POSITION) >= (128 + (10 - 3 + 1))
 ? (((unsigned int *)Data)[2] + stMUD.H_POSITION) - (128 + (10 - 3 + 1)) : 0x0fff;
 
 return 0x00;
 }
 
 
 
 
 
 
 
 
 unsigned char Measure_PositionN(unsigned char NM)
 {
 unsigned char Result;
 
 Result  = Measure_PositionV(NM);
 
 if (0x00 == Result)    
 {
 Result  = Measure_PositionH(NM);
 }
 
 return Result;
 }
 




























































































 
 void Read_Auto_Info(unsigned char index)
 {
 if(index == 0) return;
 
 RTDRead(0x88, 4, 0);
 
 Data[index << 2] = Data[3];
 Data[(index << 2) + 1] = Data[2];
 Data[(index << 2) + 2] = Data[1];
 Data[(index << 2) + 3] = Data[0];
 
 }
 
 unsigned char FindColor()
 {
 unsigned long ulTemp0;
 unsigned char ucDetect,ucResult,ucPhase;
 
 RTDSetByte(0x7E, 0x28);
 
 ulTemp0     = 0;
 ucDetect    = 0x77;
 do
 {
 ucResult    = 0x00;
 ucPhase     = 0x00;
 do
 {
 RTDSetByte(0x7D, ucPhase);
 RTDSetByte(0x7F, ucDetect);
 
 Wait_Finish();
 if (0x00 != Data[0])   return Data[0];
 
 Read_Auto_Info(1);
 
 if (ulTemp0 < ((unsigned long *)Data)[1])
 {
 ulTemp0     = ((unsigned long *)Data)[1];
 ucResult    = ucPhase;
 
 if (0x8000 < ulTemp0)   break;
 }
 
 if (0x00 == ucPhase)
 ucPhase = 0x01;
 else if (0x01 == ucPhase)
 ucPhase = 0x02;
 else
 break;
 }
 while (1);
 
 if (0 != ulTemp0 || 0x7b != ucDetect)   break;
 
 ucDetect    = 0x77;
 }
 while (1);
 
 return 0x00;
 }
 unsigned long GetMaxSum(unsigned char select)
 {
 unsigned char ucPhase,ucDetect;
 unsigned long ulTemp0;
 ucPhase = 0;  
 ulTemp0 = 0;
 Set_Phase(ucPhase);
 ucDetect    = (select == 0) ? 0x77 : 0x7b;
 
 
 
 RTDSetByte(0x9e,0x07);   
 Wait_For_IVS();
 
 RTDSetByte(0x7F, ucDetect);   
 
 Wait_For_IVS();
 for(ucPhase = 0;ucPhase < 4; ucPhase++)
 {
 
 Wait_For_IVS();
 Read_Auto_Info(1);
 
 if(ulTemp0 < ((unsigned long *)Data)[1])
 {
 ulTemp0   = ((unsigned long *)Data)[1] & 0xffffff00;
 }
 }
 RTDSetByte(0x9e,0x00);   
 Wait_Finish();
 if(0x00 != Data[0])     return (Data[0] & 0x000000ff);
 
 
#line 513 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 532 "Code\Lcd_auto.c" /0
 return ulTemp0;
 }
 
 
 
 
 
 
 
 
 
 
 unsigned char Auto_Clock_Do(unsigned char NM)
 {
 
#line 547 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 918 "Code\Lcd_auto.c" /0
 unsigned char   Result;
 unsigned char   count, delta, stop,start;    
 unsigned long   ulSum,ulCompare;
 ulCompare = 0;
 ulSum = 0;
 
 
 
 
 Result  = Measure_PositionV(NM);
 
 if (0x00 != (Result & 0x80))   return Result;
 
 NM      = NM + 0x10;     
 
 count   = 10;
 do
 {
 
 
 
 
 Result  = Measure_PositionH(NM);
 
 if (0x00 != (Result & 0x80))    return Result;
 
 usH_End = usH_End + 1 - usH_Start;
 
 
 if (usH_End < usIPH_ACT_WID)
 delta = (usIPH_ACT_WID - usH_End > 0x00ff) ? 0xff : (unsigned char)(usIPH_ACT_WID - usH_End);
 else 
 delta = (usH_End - usIPH_ACT_WID > 0x00ff) ? 0xff : (unsigned char)(usH_End - usIPH_ACT_WID);
 
 
 if((usIPH_ACT_WID/3) < delta)   
 {
 return (usH_End < usIPH_ACT_WID) ? 0xfa : 0xfb;
 }
 
 if (1 >= delta)     break;   
 
 delta   = delta + (delta >> 2); 
 
 
 
 if (usH_End < usIPH_ACT_WID)     
 {
 if ((178 - stMUD.CLOCK) < delta)    return 0xfa;
 
 stMUD.CLOCK  += delta;
 
 Set_Clock();
 Set_H_Position();
 }
 else                             
 {
 if ((stMUD.CLOCK - 78) < delta)     return 0xfb;
 
 stMUD.CLOCK -= delta;
 
 Set_H_Position();
 Set_Clock();
 }   
 
 
#line 984 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1005 "Code\Lcd_auto.c" /0
 }
 while (--count);
 
 
 
 if (0 == count)  return 0xfd;
 
 stop    = 0;
 
 while (1)
 {
 count   = 0x10;      
 delta   = 0xff;
 
 while (1)
 {
 
 
 Set_Phase(count);
 
 
 Result  = Measure_PositionH(NM);
 
 if (0x00 != (Result & 0x80))
 {
 if (0xf8 == Result)
 {
 
 if (0x70 == count)
 {
 Set_Phase(stMUD.PHASE);  
 break;
 }
 else
 {
 count += 0x20;
 continue;
 }
 }
 
 Set_Phase(stMUD.PHASE);  
 
 return Result;
 }
 
 usH_End = usH_End + 1 - usH_Start;
 
 Result  = (usH_End < usIPH_ACT_WID)
 ? 0x80 - (unsigned char)(usIPH_ACT_WID - usH_End)
 : 0x80 + (unsigned char)(usH_End - usIPH_ACT_WID);
 
 if (Result < delta)
 {
 delta   = Result;        
 }
 
 if (0x70 == count)
 {
 Set_Phase(stMUD.PHASE);  
 break;
 }
 
 count += 0x10;
 }
 
 if (0x81 < delta)
 {
 stMUD.CLOCK -= 1;
 
 Set_H_Position();
 Set_Clock();
 
 stop    = 1;
 }
 else if (0x80 > delta)
 {
 if (stop && (0x7f == delta))    break; 
 
 stMUD.CLOCK += 1;
 
 Set_Clock();
 Set_H_Position();
 
 if (stop)   break;
 }
 else    
 break;
 }
 
 count = stMUD.PHASE;   
 start = stMUD.CLOCK ;
 
 
 if(FindColor() != 0x00) return 0xff;
 
 RTDSetByte(0x7E, 0x30);
 
 ulSum = GetMaxSum(1);  
 ulCompare = GetMaxSum(0);
 
 
 
 if((ulSum > 460000) || ((ulSum < 460000) && (ulCompare > 2000000)) )
 {
 
 ulCompare = 0;    
 
 
 if(0x80 < (start - 2) || 0x80 > start)
 {
 stMUD.CLOCK = 0x80;
 Set_H_Position();
 Set_Clock();
 ulSum = GetMaxSum(0);
 
 if(ulCompare < ulSum)
 {
 ulCompare = ulSum;
 Result = stMUD.CLOCK;
 }
 
 stMUD.CLOCK = start + 1;
 }
 else
 {
 stMUD.CLOCK = start;
 Set_H_Position();
 Set_Clock();
 ulSum = GetMaxSum(0);
 }
 
 
 
 while(1)
 {
 if(ulCompare < ulSum)
 {
 ulCompare = ulSum;
 Result = stMUD.CLOCK;
 }
 if(stMUD.CLOCK == start - 2)
 break;    
 
 stMUD.CLOCK -= 1;
 Set_Clock();
 Set_H_Position();
 ulSum = GetMaxSum(0);        
 }
 
 stMUD.CLOCK = Result;
 stMUD.PHASE = count;
 Set_Clock();
 Set_H_Position();
 Set_Phase(stMUD.PHASE);
 }  
 
 
 
 
 return (28 > stMUD.CLOCK) ? 0xfb : (228 < stMUD.CLOCK) ? 0xfa : 0x00;
 }
 
 
 
 
 unsigned char Auto_Position(void)
 {
 unsigned char   Result, Curr_PosH, Curr_PosV;
 
 bAutoInProgress = 1;
 
 Curr_PosH   = stMUD.H_POSITION;      
 Curr_PosV   = stMUD.V_POSITION;      
 
 if (ucV_Max_Margin < stMUD.V_POSITION)
 {
 stMUD.V_POSITION    = ucV_Max_Margin;
 Set_V_Position();
 }
 
 RTDCodeW(ADC_DEFAULT);
 
 
 
 
 Result  = Min_Noise_Margin();
 
 if (0x00 == (Result & 0x80))
 {   
 
 
 
 Result  = Auto_Position_Do(Data[0]);     
 }
 
 if (0x00 == (Result & 0x80))
 {
 Save_MUD(ucMode_Curr);
 }
 else
 {
 stMUD.H_POSITION    = Curr_PosH;
 stMUD.V_POSITION    = Curr_PosV;
 
 Set_H_Position();
 Set_V_Position();
 }
 
 
 SetADC_GainOffset();
 
 bAutoInProgress = 0;
 
 return Result;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char Auto_Position_Do(unsigned char NM)
 {
 unsigned char   Result; 
 
 





















 
 Result      = Measure_PositionN(NM);
 
 if (0x00 != (Result & 0x80))   return Result;
 Result  = 0x00;
 
 
 
 
 NM  = 1;
 while (1)
 {
 if ((usIPV_ACT_STA + ucV_Max_Margin - 128) >= usVer_Start)
 {
 if ((usIPV_ACT_STA + ucV_Min_Margin - 128) <= usVer_Start)
 {
 stMUD.V_POSITION = (usVer_Start + 128) - usIPV_ACT_STA;
 Set_V_Position();
 
 break;   
 }
 else
 Result  |= 0x02;
 }
 else
 Result  |= 0x01;
 
 
 if (NM && usVer_End > usIPV_ACT_LEN)
 {
 usVer_Start = usVer_End - usIPV_ACT_LEN + 1;
 NM          = 0;
 }
 else
 {
 Result  |= 0x04;
 break;
 }
 }
 
 
 
 
 NM  = 1;
 while (1)
 {
 
 
 if ((usIPH_ACT_STA + (stMUD.CLOCK >> 2) + ucH_Max_Margin - 32 - 128) >= usH_Start)
 {
 
 
 if(ucH_Min_Margin  <= 128 )
 ((unsigned int*)Data)[0] = usH_Start + 128 - stMUD.H_POSITION + 50; 
 else
 ((unsigned int*)Data)[0] = usH_Start; 
 
 
 if ((usIPH_ACT_STA + (stMUD.CLOCK >> 2) + ucH_Min_Margin - 32 - 128) <= ((unsigned int*)Data)[0])
 {
 
 stMUD.H_POSITION    = usH_Start + 128 + 32 - usIPH_ACT_STA - (stMUD.CLOCK >> 2);
 Set_H_Position();
 
 break;   
 }
 else
 Result  |= 0x10;
 }
 else
 Result  |= 0x08;
 
 
 
#line 1334 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1359 "Code\Lcd_auto.c" /0
 
 if (NM && usH_End > usIPH_ACT_WID)
 {
 usH_Start   = usH_End - usIPH_ACT_WID + 1;
 NM          = 0;
 }
 else
 {
 Result  |= 0x20;
 break;
 }
 }
















 
 return Result;
 }
 
 unsigned char Min_Noise_Margin(void)
 {
 unsigned char   Result, Noise;
 unsigned int    Curr_StartH, Curr_EndH;
 
 Result  = Measure_PositionV(0x30);
 
 if (0x00 != (Result & 0x80))   return Result;
 
 if (0 == usVer_Start)
 {
 Result  = Measure_PositionV(0x30 + 0x20);
 if (0x00 != (Result & 0x80))   return Result;
 }
 
 Noise   = 0x00;
 Result  = Measure_PositionH(Noise);
 if (0x00 != (Result & 0x80))   return Result;
 
 Curr_StartH = usH_Start;     
 Curr_EndH   = usH_End;       
 
 do
 {
 Noise   = Noise + 0x10;
 Result  = Measure_PositionH(Noise);
 
 if (0x00 != (Result & 0x80))   return Result;
 
 if (Curr_StartH >= usH_Start)
 {
 Curr_StartH = usH_Start;
 }
 else if (0x08 < (usH_Start - Curr_StartH))
 {
 break;   
 }
 }
 while (0x90 > Noise);
 
 if (0x80 < Noise)   return 0xf9;      
 
 while (1)
 {   
 Curr_StartH = usH_Start;
 Curr_EndH   = usH_End;
 
 Result  = Measure_PositionH(Noise + 0x28);
 
 if (0x00 != (Result & 0x80))   return Result;
 
 if ((Curr_EndH - Curr_StartH) == (usH_End - usH_Start) || (Curr_EndH - Curr_StartH) >= (usH_End - usH_Start + 3))
 {
 break;   
 }
 
 if (0xa0 <= Noise)
 {
 break;   
 }
 
 Noise   = Noise + 0x10;        
 Result  = Measure_PositionH(Noise);
 
 if (0x00 != (Result & 0x80))   return Result;
 };
 
 Data[0] = Noise + 0x10;
 
 return 0x00;
 }
 
 unsigned char Auto_Phase(void)
 {
 unsigned char   Result, Curr_PosV;
 
 bAutoInProgress = 1;
 
 Curr_PosV   = stMUD.V_POSITION;      
 
 if (ucV_Max_Margin < stMUD.V_POSITION)
 {
 stMUD.V_POSITION    = ucV_Max_Margin;
 Set_V_Position();
 }
 
 
 RTDCodeW(ADC_DEFAULT);
 
 
 
 
 Result  = Min_Noise_Margin();
 
 if (0x00 == (Result & 0x80))
 {   
 Result      = Auto_Phase_Do(Data[0]);    
 }
 
 if (0x00 != (Result & 0x80))
 {
 
 Set_Phase(stMUD.PHASE);
 }
 else
 {
 Save_MUD(ucMode_Curr);
 }
 
 
 SetADC_GainOffset();
 
 
 if (Curr_PosV != stMUD.V_POSITION)
 {
 stMUD.V_POSITION    = Curr_PosV;
 Set_V_Position();
 }
 
 bAutoInProgress = 0;
 
 return Result;
 }
 
 
 unsigned char Auto_Phase_Do(unsigned char NM)
 {
 unsigned char idata ucDetect, ucPhase, ucResult;
 unsigned long idata ulTemp0, ulTemp1, ulTemp2;
 








 
 
 if (0x00 != Measure_PositionN(NM))    return 0xff;
 
 
 Data[0]     = 6;
 Data[1]     = 0;
 Data[2]     = 0x75;
 Data[3]     = (unsigned char)(usH_Start + (10 - 3) - 2);
 Data[4]     = (unsigned char)(usH_End + (10 - 3 + 1) + 1);
 Data[5]     = ((unsigned char)((usH_Start + (10 - 3) - 2) >> 4) & 0x70) | ((unsigned char)((usH_End + (10 - 3 + 1) + 1) >> 8) & 0x0f);
 Data[6]     = 0;
 RTDWrite(Data);
 
 RTDSetByte(0x7E, 0x30);
 
 ulTemp0     = 0;
 ucDetect    = 0x7b;
 do
 {
 ucResult    = 0x01;
 ucPhase     = 0x01;
 do
 {
 RTDSetByte(0x7D, ucPhase);
 RTDSetByte(0x7F, ucDetect);
 
 Wait_Finish();
 if (0x00 != Data[0])   return Data[0];
 
 Read_Auto_Info(1);
 if (ulTemp0 < ((unsigned long *)Data)[1])
 {
 ulTemp0     = ((unsigned long *)Data)[1];
 ucResult    = ucPhase;
 
 if (0x8000 < ulTemp0)   break;
 }
 
 if (0x01 == ucPhase)
 ucPhase = 0x00;
 else if (0x00 == ucPhase)
 ucPhase = 0x02;
 else
 break;
 }
 while (1);
 
 if (0 != ulTemp0 || 0x7b != ucDetect)   break;
 
 ucDetect    = 0x77;
 }
 while (1);
 
 
 if (0 == ulTemp0)   return 0xf8;
 
 
 RTDSetByte(0x7D, NM | ucResult);
 
 
 
 NM = 100;
 
#line 1593 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1650 "Code\Lcd_auto.c" /0
 
 RTDSetByte(0x7E, NM);
 
 
 
 Set_Phase(0x78);
 Delay_Xms(1);
 
 RTDSetByte(0x7F, 0x77);
 
 Wait_Finish();
 if (0x00 != Data[0])   return Data[0];
 
 Read_Auto_Info(1);
 
 ulTemp1     = ((unsigned long *)Data)[1];
 
 
 
 ulTemp2     = ulTemp1;
 ulTemp0     = 0;
 RTDSetByte(0x9e,0x05);   
 
 Wait_For_IVS();
 RTDSetByte(0x7F,0x77);  
 
 Wait_For_IVS();
 for(ucDetect = 0;ucDetect < 16; ucDetect++)
 {
 
 Wait_For_IVS();
 Read_Auto_Info(3);










 
 
 if(ulTemp0 < ((unsigned long *)Data)[3])
 {
 ulTemp0   = ((unsigned long *)Data)[3] & 0xffffff00;  
 ulTemp1   = ulTemp2;                                  
 ucResult  = ucDetect << 3;                            
 }
 ulTemp2 = ((unsigned long*)Data)[3] & 0xffffff00;
 
 }
 Wait_Finish();
 if (0x00 != Data[0])   return Data[0];
 
 RTDSetByte(0x9e,0x00);   
 
 
#line 1709 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1763 "Code\Lcd_auto.c" /0
 
 ucPhase = ucResult == 0x00 ? 0x7c : (ucResult - 0x04 );
 ulTemp2 = 0;
 ucDetect = 2;
 
 
 Set_Phase(ucPhase);  
 Delay_Xms(1);
 
 RTDSetByte(0x7F, 0x77);
 
 Wait_Finish();
 if (0x00 != Data[0])   return Data[0];
 Read_Auto_Info(1);
 ulTemp2 = ((unsigned long*)Data)[1];    
 
 ((unsigned long*)Data)[0] 
 = ulTemp1 + ulTemp2 + ulTemp0 
 -((ulTemp1 > ulTemp2 ? ulTemp1 - ulTemp2 : ulTemp2 - ulTemp1)/2)
 -((ulTemp2 > ulTemp0 ? ulTemp2 - ulTemp0 : ulTemp0 - ulTemp2)/2);
 
 ulTemp1 = ((unsigned long*)Data)[0];
 ucPhase = ucResult; 
 ucResult = ucResult == 0x00 ? 0x7c : ucResult - 0x04;
 
 do  
 {
 ucPhase = (ucPhase == 0x7c) ? 0x00 : ucPhase + 0x04;
 Set_Phase(ucPhase);
 Delay_Xms(1);
 
 RTDSetByte(0x7F, 0x77);
 
 Wait_Finish();
 if (0x00 != Data[0])   return Data[0];
 
 Read_Auto_Info(3);
 
 ((unsigned long *)Data)[0]  
 = ulTemp2 + ulTemp0 + ((unsigned long *)Data)[3]
 - ((ulTemp0 > ulTemp2 ? ulTemp0 - ulTemp2 : ulTemp2 - ulTemp0) / 2)
 - ((ulTemp0 > ((unsigned long *)Data)[3] ? ulTemp0 - ((unsigned long *)Data)[3] : ((unsigned long *)Data)[3] - ulTemp0) / 2);
 
 if(((unsigned long*)Data)[0] > ulTemp1)
 {
 ulTemp1 = ((unsigned long*)Data)[0];
 ucResult = (ucPhase == 0x00) ? 0x7c : ucPhase - 0x04;
 }
 ucDetect -= 1;
 
 ulTemp2 = ulTemp0;
 ulTemp0 = ((unsigned long *)Data)[3];
 
 }while(ucDetect);
 
 
 
#line 1820 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1975 "Code\Lcd_auto.c" /0
 
 stMUD.PHASE = ucResult;
 Set_Phase(stMUD.PHASE);
 






 
 
 return 0x00;
 }
 
 unsigned char Auto_Config(void)
 {
 unsigned char   Result, Noise, Curr_PosH, Curr_PosV, Curr_Clock, Curr_Phase;
 
 unsigned char ucTemp1;
 unsigned int usTemp;
 
 
 bAutoInProgress = 1;
 
 Curr_PosH   = stMUD.H_POSITION;      
 Curr_PosV   = stMUD.V_POSITION;      
 Curr_Clock  = stMUD.CLOCK;           
 Curr_Phase  = stMUD.PHASE;           
 
 if (ucV_Max_Margin < stMUD.V_POSITION)
 {
 stMUD.V_POSITION    = ucV_Max_Margin - 1;
 Set_V_Position();
 }
 
 
 
 
 





















 
 
 
 
 
 
 stMUD.H_POSITION = 128; 
 
 
 
 
 if(stMUD.CLOCK > 128)
 ucTemp1 = 128;
 else
 ucTemp1 = stMUD.CLOCK;
 
 
 ucH_Min_Margin = 128 - (64 - (ucTemp1 >> 1));
 
 
 usIPH_ACT_STA   = CAP_WIN[ucMode_Curr][1];
 
 if(ucMode_Curr < 23)
 Data[0] = 2;
 else if(ucMode_Curr < 44)
 Data[0] = 5;
 else
 Data[0] = 3;
 
 
 
 
 usIPH_ACT_STA = CAP_WIN[ucMode_Curr][1] + Data[0] - 6 - (64 - (ucTemp1 >> 1));
 
 usTemp = usIPH_ACT_STA;
 
 Set_H_Position();
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 
 
 
 
 
 
 
 
 Result  = Min_Noise_Margin();   
 Noise   = Data[0];
 
 
 
 
 
 if (0x00 == (Result & 0x80))
 {   
 stMUD.CLOCK = (stMUD.CLOCK) & 0xfc;  
 
 if (stMUD.CLOCK != Curr_Clock)  Set_Clock();
 
 
 
 
 Result  = Auto_Clock_Do(Noise);
 
 
 if (0x00 != (Result & 0x80))
 {
 if (stMUD.CLOCK != Curr_Clock)
 {
 
 stMUD.H_POSITION    = Curr_PosH;
 stMUD.CLOCK         = Curr_Clock;
 
 Set_Clock();
 Set_H_Position();
 }
 }
 else
 {
 stMUD.H_POSITION    = usH_Start + 128 + 64 - usIPH_ACT_STA - (stMUD.CLOCK >> 1);
 
 if (ucH_Max_Margin < stMUD.H_POSITION)
 stMUD.H_POSITION    = ucH_Max_Margin;
 else if (ucH_Min_Margin > stMUD.H_POSITION)
 stMUD.H_POSITION    = ucH_Min_Margin;
 
 Set_H_Position();
 }
 }
 
 
 if (0x00 == (Result & 0x80))
 {   
 Result      = Auto_Phase_Do(Noise);
 
 if (0x00 != (Result & 0x80))
 {
 
 stMUD.PHASE = Curr_Phase;
 Set_Phase(stMUD.PHASE);
 
 if (0xf8 == Result)      Result  = 0x00;
 }
 }
 
 
 if (0x00 == (Result & 0x80))    
 {   
 
 
 
 Result  = Auto_Position_Do(Noise);
 
 
 }
 else
 {
 stMUD.V_POSITION    = Curr_PosV;
 Set_V_Position();
 }
 
 
 
 
















 
 
 
 
 
 if(ucH_Min_Margin == (128 - (64 - (ucTemp1 >> 1))))
 {
 if(usTemp != usIPH_ACT_STA)
 {   
 
 
 stMUD.H_POSITION = stMUD.H_POSITION - (usTemp - usIPH_ACT_STA);
 usIPH_ACT_STA = usTemp - 50 + (64 - (ucTemp1 >> 1));
 Data[3] = 0x80 | (78 - stMUD.H_POSITION);	    
 
 }
 else
 {
 usIPH_ACT_STA   = usIPH_ACT_STA - 50 + (64 - (ucTemp1 >> 1));
 Data[3] = 0;
 }
 
 
 Data[0] = 4;
 Data[1] = 0xAE;
 Data[2] = (ucMode_Curr - 1);          
 
 
 
 if(0x80 < stMUD.H_POSITION)
 {
 if(stMUD.H_POSITION - 0x80 < 10)
 {
 usIPH_ACT_STA += (stMUD.H_POSITION - 0x80);
 Data[3] += (stMUD.H_POSITION - 0x80);
 stMUD.H_POSITION = 0x80;                            
 }
 
 }
 else if(0x80 > stMUD.H_POSITION)
 {
 if(0x80 - stMUD.H_POSITION < 10)
 {
 usIPH_ACT_STA -= (0x80 - stMUD.H_POSITION);
 
 Data[3] = (0x80 - stMUD.H_POSITION ) | 0x80;
 stMUD.H_POSITION = 0x80;
 
 }
 }
 
 I2CWrite(Data);
 Delay_Xms(0x10);
 
 ucH_Min_Margin  = 128 - 50;   
 Set_H_Position();
 
 }
 Set_Phase(stMUD.PHASE);
 if (0x00 == (Result & 0x80))   Save_MUD(ucMode_Curr);
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 
 
 
 
 
 
 bAutoInProgress = 0;
 Set_Phase(stMUD.PHASE);
 
 return Result;
 }
 
 unsigned char Auto_Balance(void)
 {
 unsigned char Result, Curr_PosV;
 
 bAutoInProgress = 1;
 
 Curr_PosV   = stMUD.V_POSITION;      
 
 if (ucV_Max_Margin < stMUD.V_POSITION)
 {
 stMUD.V_POSITION    = ucV_Max_Margin;
 Set_V_Position();
 }
 
 
 Result  = Tune_Balance();
 
 
 if (Curr_PosV != stMUD.V_POSITION)
 {
 stMUD.V_POSITION    = Curr_PosV;
 Set_V_Position();
 }
 
 if (0x00 != Result)
 {
 
 Load_GUD2();
 SetADC_GainOffset();
 }
 else
 {
 stGUD0.CONTRAST         = 50;
 stGUD0.RTD_R_CONTRAST   = 50;
 stGUD0.RTD_G_CONTRAST   = 50;
 stGUD0.RTD_B_CONTRAST   = 50;
 stGUD0.RTD_R_BRIGHT     = 50;
 stGUD0.RTD_G_BRIGHT     = 50;
 stGUD0.RTD_B_BRIGHT     = 50;
 Set_Bright_Contrast();
 
 
 SetADC_Gain();
 
 
 Save_GUD0();







 
 Save_GUD2();
 }
 
 bAutoInProgress = 0;
 
 return Result;
 }
 
 unsigned char Tune_Balance(void)
 {
 unsigned char   Color, Count, Result, Margin, FineTune, Offset_Stop,ucTemp = 0;
 
 FineTune    = 0;
 
 
 ucTemp = stGUD0.CONTRAST;
 stGUD0.CONTRAST = 50;
 SetADC_Gain();
 
 
 RTDCodeW(ADC_DEFAULT);
 
 
 if (0x00 != Measure_PositionN(0x40))   return 0xff;
 
 if (0x00 != Measure_Color(0x01, 0x20))      return 0xff;
 if (0x60 > Data[0])     return 0xff;
 
 Margin  = Data[0];
 
 if (0x00 != Measure_Color(0x02, 0x20))    return 0xff;
 if (0x60 > Data[0])     return 0xff;
 
 Margin  = Margin > Data[0] ? Data[0] : Margin;
 
 if (0x00 != Measure_Color(0x04, 0x20))     return 0xff;
 if (0x60 > Data[0])     return 0xff;
 
 Margin  = Margin > Data[0] ? Data[0] : Margin;
 
 Margin  = (Margin - 0x20) & 0xfc;
 
 
 if (0x00 != Measure_PositionN(Margin))   return 0xff;
 
 
 
#line 2354 "Code\Lcd_auto.c" /1
 
 
#line 2356 "Code\Lcd_auto.c" /0
 SetADC_GainOffset();
 
 
 Offset_Stop = 0;
 Color   = 0x04;
 do
 {
 Count   = 0x30;
 
 do
 {
 
#line 2368 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 2441 "Code\Lcd_auto.c" /0
 
 
 
 
 
 
 if (0x00 != Measure_Color(Color, 0x20))   return 0xff;
 Margin  = Data[0];
 
 if (0xf2 < Margin)
 {
 Result  = Margin - 0xf2;
 
 
 if (Change_ADC_Gain(Color, Result, 0))               
 {
 if (Change_ADC_Offset(Color, 4, 0))     break;   
 }
 }
 else if (0xf2 > Margin)
 {
 Result  = 0xf2 - Margin;
 
 
 if (Change_ADC_Gain(Color, Result, 1))               
 {
 if (Change_ADC_Offset(Color, 4, 1))     break;   
 }
 }
 
 Result  = Margin;
 
 
 
 
 
 if (0x00 != Measure_Color(Color, 0x00))   return 0xff;
 Margin  = Data[0];
 
 if (0x0a < Margin)
 {
 Change_ADC_Offset(Color, 0x08, 0);           
 }
 else if (0x02 < Margin)
 {
 Change_ADC_Offset(Color, Margin - 0x02, 0);  
 }
 else if (0x02 > Margin)
 {
 if (0x00 == Margin && 0 == FineTune)
 Change_ADC_Offset(Color, 0x06, 1);               
 else
 Change_ADC_Offset(Color, 0x02 - Margin, 1);      
 
 }
 else if (0xf2 == Result)
 {
 break;
 }
 
 
 if (8 < Count && 0xf3 >= Result && 0xf1 <= Result && 0x03 >= Margin && 0x01 <= Margin)
 {
 FineTune    = 1;
 Count       = 8;
 }
 
 
 
#line 2510 "Code\Lcd_auto.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 2573 "Code\Lcd_auto.c" /0
 
 }
 while (--Count);
 
 Color   = Color >> 1;
 }
 while (Color);
 
 
 stGUD0.CONTRAST = ucTemp;
 SetADC_Gain();
 
 return 0x00; 
 }
 
 unsigned char Measure_Color(unsigned char color, unsigned char margin)
 {
 RTDSetByte(0x7D, (0x01 == color) ? 0x02 : (0x02 == color) ? 0x01 : 0x00);
 
 
 Data[0] = 9;
 Data[1] = 0;
 Data[2] = 0x75;
 
 Data[3] = (unsigned char)(usH_Start + (10 - 3) - 1);
 Data[4] = (unsigned char)(usH_End + (10 - 3 + 1));
 Data[5] = ((unsigned char)((usH_Start + (10 - 3) - 1) >> 4) & 0x70) | ((unsigned char)((usH_End + (10 - 3 + 1)) >> 8) & 0x0f);
 
 if (0x00 == margin)
 {
 Data[3] = 0x80;
 Data[4] = 0x00;
 Data[5] = 0x12;
 
 Data[6] = 9 < usVer_Start ? 9 : usVer_Start - 1;
 Data[7] = Data[6] + 1;
 Data[8] = 0;
 }
 else
 {
 Data[6] = (unsigned char)(usVer_Start + 1);
 Data[7] = (unsigned char)(usVer_End + 1);
 Data[8] = ((unsigned char)((usVer_Start + 1) >> 4) & 0x70) | ((unsigned char)((usVer_End + 1) >> 8) & 0x0f);
 }
 
 Data[9] = 0;
 RTDWrite(Data);
 
 if (0x00 == margin)
 RTDSetByte(0x7F, 0x00 | 0x01);  
 else
 RTDSetByte(0x7F, 0x20 | 0x01);  
 
 Wait_Finish();
 
 if (0x00 != Data[0])   return 0xff;
 
 RTDRead(0x88, 1, 1);   
 
 if (0x00 == margin)	Data[0]	^= 0xff;
 
 
 
 return 0x00;
 }
 
 unsigned char Change_ADC_Gain(unsigned char color, unsigned char delta, unsigned char inc)
 {
 if (inc)
 {
 inc = 0;
 
 if (color & 0x01)
 {
 if (stGUD2.AD_R_GAIN > delta)
 stGUD2.AD_R_GAIN    -= delta;
 else
 {
 stGUD2.AD_R_GAIN    = 0;
 inc |= 0x01;
 }
 }
 if (color & 0x02)
 {
 if (stGUD2.AD_G_GAIN > delta)
 stGUD2.AD_G_GAIN    -= delta;
 else
 {
 stGUD2.AD_G_GAIN    = 0;
 inc |= 0x02;
 }
 }
 if (color & 0x04)
 {
 if (stGUD2.AD_B_GAIN > delta)
 stGUD2.AD_B_GAIN    -= delta;
 else
 {
 stGUD2.AD_B_GAIN    = 0;
 inc |= 0x04;
 }
 }
 }
 else
 {
 if (color & 0x01)
 {
 if ((0xff - stGUD2.AD_R_GAIN) > delta)
 stGUD2.AD_R_GAIN    += delta;
 else
 {
 stGUD2.AD_R_GAIN    = 0xff;
 inc |= 0x01;
 }
 }
 if (color & 0x02)
 {
 if ((0xff - stGUD2.AD_G_GAIN) > delta)
 stGUD2.AD_G_GAIN    += delta;
 else
 {
 stGUD2.AD_G_GAIN    = 0xff;
 inc |= 0x02;
 }
 }
 if (color & 0x04)
 {
 if ((0xff - stGUD2.AD_B_GAIN) > delta)
 stGUD2.AD_B_GAIN    += delta;
 else
 {
 stGUD2.AD_B_GAIN    = 0xff;
 inc |= 0x04;
 }
 }
 }
 
 SetADC_Gain();
 
 return inc;
 }
 
 unsigned char Change_ADC_Offset(unsigned char color, unsigned char delta, unsigned char inc)
 {
 if (inc)
 {
 inc = 0;
 
 if (color & 0x01)
 {
 if (stGUD2.AD_R_OFFSET > delta)
 stGUD2.AD_R_OFFSET  = stGUD2.AD_R_OFFSET - delta;
 else
 {
 stGUD2.AD_R_OFFSET  = 0;
 inc |= 0x01;
 }
 }
 if (color & 0x02)
 {
 if (stGUD2.AD_G_OFFSET > delta)
 stGUD2.AD_G_OFFSET  = stGUD2.AD_G_OFFSET - delta;
 else
 {
 stGUD2.AD_G_OFFSET  = 0;
 inc |= 0x02;
 }
 }
 if (color & 0x04)
 {
 if (stGUD2.AD_B_OFFSET > delta)
 stGUD2.AD_B_OFFSET  = stGUD2.AD_B_OFFSET - delta;
 else
 {
 stGUD2.AD_B_OFFSET  = 0;
 inc |= 0x04;
 }
 }
 }
 else
 {
 if (color & 0x01)
 {
 if ((0xff - delta) > stGUD2.AD_R_OFFSET)
 stGUD2.AD_R_OFFSET  = stGUD2.AD_R_OFFSET + delta;
 else
 {
 stGUD2.AD_R_OFFSET  = 0xff;
 inc |= 0x01;
 }
 
 }
 if (color & 0x02)
 {
 if ((0xff - delta) > stGUD2.AD_G_OFFSET)
 stGUD2.AD_G_OFFSET  = stGUD2.AD_G_OFFSET + delta;
 else
 {
 stGUD2.AD_G_OFFSET  = 0xff;
 inc |= 0x02;
 }
 
 }
 if (color & 0x04)
 {
 if ((0xff - delta) > stGUD2.AD_B_OFFSET)
 stGUD2.AD_B_OFFSET  = stGUD2.AD_B_OFFSET + delta;
 else
 {
 stGUD2.AD_B_OFFSET  = 0xff;
 inc |= 0x04;
 }
 }
 }
 
 SetADC_Offset();
 
 return inc;
 }
 
