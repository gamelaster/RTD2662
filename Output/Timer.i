
#line 1 "Code\Timer.c" /0
 
 
  
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
 
 
#line 3 "Code\Timer.c" /0
 
  
#line 1 "Header\Lcd_main.h" /0
  
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
 
 
 
 bit bNotify_Timer0_Int  = 0;
 bit bNotify_Timer1_Int  = 0;
 unsigned char   idata   ucTimerCounter = 0;
 void Delay_Xms(unsigned char x);     

















 
 
 
#line 68 "HEADER\Timer.h" /1
 
 
 
 
 
#line 1 "Header\Lcd_main.h" /0
#line 1 "Header\Lcd_main.h" /0
 
  
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
 
 
 
 
#line 2 "Header\Lcd_main.h" /0
 
  
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
 
 
#line 3 "Header\Lcd_main.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 






 
 
 
#line 32 "Header\Lcd_main.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 86 "Header\Lcd_main.h" /0
 
 
 extern bit bReload;
 
 
#line 91 "Header\Lcd_main.h" /1
 
 
 
#line 94 "Header\Lcd_main.h" /0
 
 extern unsigned int     idata   usOSD_Timer;
 extern unsigned int     idata   usTaskCnt;
 extern unsigned char    idata   ucID_Code;
 
 
 
 
 extern void ISP_Check_Sum(void);
 extern void Set_Task(unsigned char state);
 
 
 
#line 4 "Code\Timer.c" /0
 
  
#line 1 "Header\Lcd_auto.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 71 "Header\Lcd_auto.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 107 "Header\Lcd_auto.h" /0
 
 extern bit bAutoInProgress;
 
 extern unsigned int idata   usVer_Start;
 extern unsigned int idata   usVer_End;
 extern unsigned int idata   usH_Start;
 extern unsigned int idata   usH_End;
 
 extern unsigned char Auto_Phase(void);
 
 extern unsigned char Auto_Position(void);
 extern unsigned char Auto_Config(void);
 extern unsigned char Auto_Balance(void);
 
 extern unsigned char Measure_Color(unsigned char color, unsigned char margin);
 
 
#line 5 "Code\Timer.c" /0
 
 
 
 
 
 void IntProc_Timer0(void) interrupt 1
 {
 
#line 13 "Code\Timer.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 104 "Code\Timer.c" /0
 
 
 TL0         = 0xFF;   
 TH0         = 0x5F;   
 
 bNotify_Timer0_Int  = 1;     
 
 if (usOSD_Timer)    usOSD_Timer -= 1;    















 
 
 }
 
 
 
 
 
 void IntProc_Timer1(void) interrupt 3
 {   
 TR1 = 0;                     
 TL1 = 0xFF;   
 
 TH1 = (bAutoInProgress == 1) ? 0xFB : 0xF7;   
 
 bNotify_Timer1_Int  = 1;     
 }
 
 
 
 
 void Delay_Xms(unsigned char x)      
 {
 if (x)
 {
 bNotify_Timer1_Int  = 0;     
 
 
 
 
 TR1 = 1;                     
 
 while (1)
 {
 if (bNotify_Timer1_Int)
 {
 bNotify_Timer1_Int  = 0;     
 
 if (--x)    TR1 = 1;         
 else        return;          
 }
 }
 }
 }



























 
