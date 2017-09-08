
#line 1 "Code\Lcd_func.c" /0
 
 
  
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
 
 
#line 3 "Code\Lcd_func.c" /0
 
  
#line 1 "C:\KEIL\C51\INC\INTRINS.H" /0






 
 
 
 
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 
 
 
#line 4 "Code\Lcd_func.c" /0
 
 
  
#line 1 "Header\MAIN_DEF.H" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\MAIN_DEF.H" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 "Header\MAIN_DEF.H" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 "Header\MAIN_DEF.H" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 "Header\MAIN_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 "Header\MAIN_DEF.H" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 "Header\MAIN_DEF.H" /0
 
 
#line 157 "Header\MAIN_DEF.H" /1
  
 
#line 159 "Header\MAIN_DEF.H" /0
 
 
 
 
#line 163 "Header\MAIN_DEF.H" /1
  
 
#line 165 "Header\MAIN_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 "Header\MAIN_DEF.H" /1
  
 
#line 272 "Header\MAIN_DEF.H" /0
 
#line 273 "Header\MAIN_DEF.H" /1
  
 
#line 275 "Header\MAIN_DEF.H" /0
 
#line 276 "Header\MAIN_DEF.H" /1
  
 
#line 278 "Header\MAIN_DEF.H" /0
 
#line 279 "Header\MAIN_DEF.H" /1
  
 
#line 281 "Header\MAIN_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 6 "Code\Lcd_func.c" /0
 
  
#line 1 "Header\MTV512.H" /0
  
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\MTV512.H" /0
 
 
 
 
 
 
 
 
 
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
 
 
#line 105 "Header\MTV512.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 130 "Header\MTV512.H" /0
 
 
 
 
 
 
 
 
#line 7 "Code\Lcd_func.c" /0
 
  
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
 
 
#line 8 "Code\Lcd_func.c" /0
 
  
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
 
 
#line 9 "Code\Lcd_func.c" /0
 
  
#line 1 "Header\OSD.H" /0
  
#line 1 ".\HEADER\Main_def.h" /0
  
#line 1 "HEADER\CHAR_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 ".\HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\MODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
#line 2 ".\HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\RTD_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 































































































 
#line 3 ".\HEADER\Main_def.h" /0
 
  
#line 1 "HEADER\CODE_DEF.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4 ".\HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 144 ".\HEADER\Main_def.h" /1
 
 
 
 
 
 
 
 
 
 
 
#line 155 ".\HEADER\Main_def.h" /0
 
 
#line 157 ".\HEADER\Main_def.h" /1
  
 
#line 159 ".\HEADER\Main_def.h" /0
 
 
 
 
#line 163 ".\HEADER\Main_def.h" /1
  
 
#line 165 ".\HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 270 ".\HEADER\Main_def.h" /1
  
 
#line 272 ".\HEADER\Main_def.h" /0
 
#line 273 ".\HEADER\Main_def.h" /1
  
 
#line 275 ".\HEADER\Main_def.h" /0
 
#line 276 ".\HEADER\Main_def.h" /1
  
 
#line 278 ".\HEADER\Main_def.h" /0
 
#line 279 ".\HEADER\Main_def.h" /1
  
 
#line 281 ".\HEADER\Main_def.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1 "Header\OSD.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 27 "Header\OSD.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


































































































































































































































































































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 










 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 










 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 5116 "Header\OSD.H" /0
 
 
 extern unsigned char code Row_Info[][19];
 extern unsigned char code FactRow_Info[][20];    
 
 extern unsigned char code OSD_Window_Setting[];
 
 extern unsigned char code Page_All_Atb[];
 extern unsigned char code Page_All_ENG[];
 extern unsigned char code Page_All_GER[];
 extern unsigned char code Page_All_FRE[];
 extern unsigned char code Page_All_ITA[];
 extern unsigned char code Page_All_SPA[];
 extern unsigned char code Page_All_CHI_T[];
 extern unsigned char code Page_All_CHI_S[];
 extern unsigned char code Page_All_JAP[];
 
 extern unsigned char code Page1_Atb[];
 extern unsigned char code Page1_ENG[];
 extern unsigned char code Page1_GER[];
 extern unsigned char code Page1_FRE[];
 extern unsigned char code Page1_ITA[];
 extern unsigned char code Page1_SPA[];
 extern unsigned char code Page1_CHI_T[];
 extern unsigned char code Page1_CHI_S[];
 extern unsigned char code Page1_JAP[];
 
 extern unsigned char code Page2_Atb[];
 extern unsigned char code Page2_ENG[];
 extern unsigned char code Page2_GER[];
 extern unsigned char code Page2_FRE[];
 extern unsigned char code Page2_ITA[];
 extern unsigned char code Page2_SPA[];
 extern unsigned char code Page2_CHI_T[];
 extern unsigned char code Page2_CHI_S[];
 extern unsigned char code Page2_JAP[];
 
 extern unsigned char code Page3_Atb[];
 extern unsigned char code Page3_ENG[];
 extern unsigned char code Page3_GER[];
 extern unsigned char code Page3_FRE[];
 extern unsigned char code Page3_ITA[];
 extern unsigned char code Page3_SPA[];
 extern unsigned char code Page3_CHI_T[];
 extern unsigned char code Page3_CHI_S[];
 extern unsigned char code Page3_JAP[];
 
 extern unsigned char code Page4_Atb[];
 extern unsigned char code Page4_ENG[];
 extern unsigned char code Page4_GER[];
 extern unsigned char code Page4_FRE[];
 extern unsigned char code Page4_ITA[];
 extern unsigned char code Page4_SPA[];
 extern unsigned char code Page4_CHI_T[];
 extern unsigned char code Page4_CHI_S[];
 extern unsigned char code Page4_JAP[];
 
 extern unsigned char code Page5_Atb[];
 extern unsigned char code Page5_ENG[];
 extern unsigned char code Page5_GER[];
 extern unsigned char code Page5_FRE[];
 extern unsigned char code Page5_ITA[];
 extern unsigned char code Page5_SPA[];
 extern unsigned char code Page5_CHI_T[];
 extern unsigned char code Page5_CHI_S[];
 extern unsigned char code Page5_JAP[];
 
 extern unsigned char code Page6_Atb[];
 extern unsigned char code Page6_ENG[];
 extern unsigned char code Page6_GER[];
 extern unsigned char code Page6_FRE[];
 extern unsigned char code Page6_ITA[];
 extern unsigned char code Page6_SPA[];
 extern unsigned char code Page6_CHI_T[];
 extern unsigned char code Page6_CHI_S[];
 extern unsigned char code Page6_JAP[];
 
 extern unsigned char code Page7_Atb[];
 extern unsigned char code Page7_ENG[];
 extern unsigned char code Page7_GER[];
 extern unsigned char code Page7_FRE[];
 extern unsigned char code Page7_ITA[];
 extern unsigned char code Page7_SPA[];
 extern unsigned char code Page7_CHI_T[];
 extern unsigned char code Page7_CHI_S[];
 extern unsigned char code Page7_JAP[];
 
 extern unsigned char code OSD_Version[];
 
 extern unsigned char code NoCable_ENG[];
 extern unsigned char code NoCable_GER[];
 extern unsigned char code NoCable_FRE[];
 extern unsigned char code NoCable_ITA[];
 extern unsigned char code NoCable_SPA[];
 extern unsigned char code NoCable_CHI_T[];
 extern unsigned char code NoCable_CHI_S[];
 extern unsigned char code NoCable_JAP[];
 
 extern unsigned char code NoSignal_ENG[];
 extern unsigned char code NoSignal_FRA[];
 extern unsigned char code NoSignal_DEU[];
 extern unsigned char code NoSignal_ESP[];
 extern unsigned char code NoSignal_ITA[];
 extern unsigned char code NoSignal_CHI_T[];
 extern unsigned char code NoSignal_CHI_S[];
 extern unsigned char code NoSignal_JAP[];
 
 extern unsigned char code NoSupport_ENG[];
 extern unsigned char code NoSupport_GER[];
 extern unsigned char code NoSupport_FRE[];
 extern unsigned char code NoSupport_ITA[];
 extern unsigned char code NoSupport_SPA[];
 extern unsigned char code NoSupport_CHI_T[];
 extern unsigned char code NoSupport_CHI_S[];
 extern unsigned char code NoSupport_JAP[];
 
 extern unsigned char code rgb_OSD_VOLUME[];
 extern unsigned char code OSD_VOLUME_ENG[];			 
 extern unsigned char code OSD_VOLUME_ESP[];			 
 extern unsigned char code OSD_VOLUME_JAP[];			 
 extern unsigned int code  strTabVOLUME_Atb[];			 
 
 extern unsigned char code OSD_AUTO[];
 extern unsigned char code OSD_Auto_ENG[];			 
 extern unsigned char code OSD_Auto_DEU[];			 
 extern unsigned char code OSD_Auto_FRA[];			 
 extern unsigned char code OSD_Auto_ESP[];			 
 extern unsigned char code OSD_Auto_ITA[];			 
 extern unsigned char code OSD_Auto_CHI_T[];		 
 extern unsigned char code OSD_Auto_JAP[];			 
 extern unsigned int code  strTabAuto_Atb[];			 
 
 extern unsigned char code OSD_RGB[];
 extern unsigned char code OSD_DVI[];
 extern unsigned char code OSD_AV[];
 extern unsigned char code OSD_SV[];
 extern unsigned char code OSD_YUV[];
 extern unsigned char code OSD_TV[];
 
 extern unsigned char code FactoryPageAtbFont[];		 
 extern unsigned char code OSD_Clean_All[];			 
 extern unsigned char code Version_Panel[];			 
 extern unsigned char code RecallOK[];				 
 extern unsigned char code AutoOK[];				 
 
 extern unsigned char code OSD_Reset[]; 
 extern unsigned char code OSD_Enable[];
 





 
 extern unsigned char code Page8_Atb[];
 extern unsigned char code Page8_Title_ENG[];
 extern unsigned char code Page8_Title_GER[];
 extern unsigned char code Page8_Title_FRE[];
 extern unsigned char code Page8_Title_ITA[];
 extern unsigned char code Page8_Title_SPA[];
 extern unsigned char code Page8_Title_CHI_T[];
 extern unsigned char code Page8_Title_CHI_S[];
 extern unsigned char code Page8_Title_JAP[];
 extern unsigned char code Page8_Content[];
 
 extern unsigned char code Page9_Atb[];
 extern unsigned char code Page9_Title_ENG[];
 extern unsigned char code Page9_Title_GER[];
 extern unsigned char code Page9_Title_FRE[];
 extern unsigned char code Page9_Title_ITA[];
 extern unsigned char code Page9_Title_SPA[];
 extern unsigned char code Page9_Title_CHI_T[];
 extern unsigned char code Page9_Title_CHI_S[];
 extern unsigned char code Page9_Title_JAP[];
 extern unsigned char code Page9_Content[];
 
 extern unsigned char code PageADC_Atb[];
 extern unsigned char code PageADC_ENG[];
 extern unsigned char code PageVDC_Atb[];
 extern unsigned char code PageVDC_ENG[];
 





 
 
 
#line 5305 "Header\OSD.H" /1
 
 
 
 
 
 
 
#line 5312 "Header\OSD.H" /0
 
 
 extern unsigned int code OSD_HINT_TABLE[][8];
 extern unsigned int code OSD_REMK_TABLE[][8];
 extern unsigned int code OSD_PAGE_TABLE[][8];
 extern unsigned int code OSD_PAGE_All_TABLE[][8];
 
 
 
#line 10 "Code\Lcd_func.c" /0
 
  
#line 1 "Header\LCD_COEF.H" /0
 
#line 2 "Header\LCD_COEF.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


















 


















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 111 "Header\LCD_COEF.H" /0
 
 extern unsigned char code GAMMA_1[];
 extern unsigned char code GAMMA_2[];	
 extern unsigned char code GAMMA_3[];	
 
 
 
 
 extern unsigned char code DITHER_1[];
 extern unsigned char code DITHER_2[];
 extern unsigned char code NEW_DITHER_TABLE[];
 extern unsigned char code SU_COEF_1[];
 extern unsigned char code SU_COEF_2[];
 extern unsigned char code SU_COEF_3[];
 extern unsigned char code SU_COEF_4[];
 extern unsigned char code SU_COEF_5[];
 extern unsigned char code SU_COEF_6[];
 extern unsigned char code SU_COEF_7[];
 
#line 11 "Code\Lcd_func.c" /0
 
  
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
 
 
 
#line 12 "Code\Lcd_func.c" /0
 
  
#line 1 "Header\LCD_AUTO.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 71 "Header\LCD_AUTO.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 107 "Header\LCD_AUTO.H" /0
 
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
 
 
#line 13 "Code\Lcd_func.c" /0
 
  
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
 
 
 
 
 
 
 
 
 unsigned char code INIT_EEPROM0[]    =
 {
 19, 0xAE, 0xE0,   0x32,            
 0x3c,            
 0x32,            
 0x32,            
 0x32,            
 0x32,            
 0x32,            
 0x32,            
 
 0x00,            
 0x38,            
 0x02,            
  (((((0x0520 - 544) / 4) + 1) + (((0x0520 - (0x0520 - 0x0020)) / 4) + 1)) / 2),        
  ((3 + (((0x040c - 0x000c) - 250 - 14) / 4)) / 2),        
 0x14,            
 0x00,            
 0x00,            
 };
 
 unsigned char code INIT_EEPROM1[]    =
 {
 19, 0xAE, 0xF0,		0x80,            
 0x80,            
 0x80,            
 0x80,            
 0x80,            
 0x80,            
 0x00,            
 0x00,            
 
 0x0a,            
 0x07,            
 0x07,            
 0x00,            
 0x06,            
 0x00,            
 0x03,            
 0x22,            
 };
 
 unsigned char code INIT_EEPROM2[]    =
 {
 19, 0xAE, 0xD0,		0x33,	      
 0x2e,            
 0x2e,            
 0x2a,            
 0x34,            
 0x32,            
 0x28,            
 0x36,            
 
 0x36,            
 0x00,            
 0x00,            
 0x00,            
 0x00,            
 0x00,            
 0x00,            
 0x00,            
 };
 
 
 GLOBAL_USER_DATA0   data    stGUD0;
 GLOBAL_USER_DATA1   data    stGUD1;
 GLOBAL_USER_DATA2   data    stGUD2;
 GLOBAL_USER_DATA3   data    stGUD3;
 GLOBAL_USER_DATA4   data    stGUD4;
 RGB_MODE_USER_DATA  data    stMUD;
 
 unsigned int  idata usIPH_ACT_STA   = 0;
 unsigned int  idata usIPV_ACT_STA   = 0;
 unsigned int  idata usIPH_ACT_WID   = 0;
 unsigned int  idata usIPV_ACT_LEN   = 0;
 
 unsigned int  idata usADC_Clock     = 0;
 unsigned int  idata usDH_Total      = 0;
 unsigned int  idata usDV_Total      = 0;
 unsigned char idata ucDV_Delay      = 0;
 
 unsigned char idata ucV_Max_Margin  = 0;
 unsigned char idata ucV_Min_Margin  = 0;
 unsigned char idata ucH_Max_Margin  = 0;
 unsigned char idata ucH_Min_Margin  = 0;
 unsigned char   idata   UartNum        = 0;
 unsigned char idata  UartData[4];	 
 
 
 
 void SetMute(bit val);
 void SetVolume();
 
 void WriteGamma(unsigned char code *arrayR, unsigned char code *arrayG, unsigned char code *arrayB);
 void WriteDither(unsigned char code *array,bit new_dither);
 void WriteSU_COEF(unsigned char code *arrayH, unsigned char code *arrayV);
 
 void Set_H_Position(void);
 void Set_V_Position(void);
 void Set_Clock(void);
 void Set_Phase(unsigned char phase);
 void Set_Bright_Contrast(void);
 void Set_Gamma(void);
 void Set_Dithering(void);
 void Sharpness(void);
 void Set_Mode_Params(void);
 
 void SetADC_VCO(unsigned char ucRate);
 void SetADC_Gain(void);
 void SetADC_Offset(void);
 void SetADC_GainOffset(void);
 
#line 251 "Header\LCD_FUNC.H" /1
 
 
#line 253 "Header\LCD_FUNC.H" /0
 
 void Wait_For_Event(unsigned char event);
 
 
 
 void Save_GUD0(void);
 void Load_GUD0(void);
 void Save_GUD1(void);
 void Load_GUD1(void);
 void Save_GUD2(void);
 void Load_GUD2(void);
 void Save_GUD3(void);
 void Load_GUD3(void);
 void Load_GUD4(void);
 void Save_GUD4(void);
 
 void Save_MUD(unsigned char mode_num);
 void Load_MUD(unsigned char mode_num);
 void Init_GUD(void);
 void Init_MUD(void);
 void Check_EEPROM(void);
 void Free_Background(void);
 void Reset_Mode(void);
 
 
 
 
 void Set_Spread(void);
 void Init_FACTORY(void);
 void Init_FRecall(void);
 
 
 
 
#line 287 "Header\LCD_FUNC.H" /1
 
 
 
 
#line 291 "Header\LCD_FUNC.H" /0
 
 
#line 293 "Header\LCD_FUNC.H" /1
 
 
 
 
 
 
 
 
 
#line 302 "Header\LCD_FUNC.H" /0
 
 
#line 304 "Header\LCD_FUNC.H" /1
 
 
 
 
 
 
#line 310 "Header\LCD_FUNC.H" /0
 
 
 
#line 313 "Header\LCD_FUNC.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 14 "Code\Lcd_func.c" /0
#line 14 "Code\Lcd_func.c" /0
 
  
#line 1 "Header\FRAME_SYNC.H" /0
 
#line 2 "Header\FRAME_SYNC.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 21 "Header\FRAME_SYNC.H" /0
 
 extern bit bFrameSync;     
 extern unsigned char   idata   ucSyncErrorCnt;
 extern unsigned char   idata   ucPE_Max;
 extern unsigned char   idata   ucStatus;
 extern unsigned char   idata   ucI_Code;
 extern unsigned char   idata   ucP_Corr;
 
 extern unsigned char Frame_Sync(void);
 extern bit Frame_Sync_Detector(void);
 extern void Adjust_I_Code(void);
 
 
#line 15 "Code\Lcd_func.c" /0
 
  
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
 
 
 
 
 
#line 16 "Code\Lcd_func.c" /0
 
 
 
 void SetMute(bit val)
 {
 
 if(val == 0)    
 {
  M512_Port61 = 0;			 
  M512_Port64 = 1;
 }
 else 		 
 {
  M512_Port61 = 1;
  M512_Port64 = 0;
 }
 
 











 
 }
 
 
#line 49 "Code\Lcd_func.c" /1
  
 
#line 51 "Code\Lcd_func.c" /0
 
 void SetVolume()
 {
 stGUD3.VOLUME   &= 0x1f;
 
 
#line 57 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 73 "Code\Lcd_func.c" /0
 
 
#line 75 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 88 "Code\Lcd_func.c" /0
 
 
 
 
 Data[0] = 6;
 Data[1] = 0;
 Data[2] = 0x90;
 Data[3] = 0x00;
 Data[4] = 0x01;
 
#line 98 "Code\Lcd_func.c" /1
 
 
#line 100 "Code\Lcd_func.c" /0
 Data[5] = (stGUD3.VOLUME << 3);
 
 Data[6] = 0;
 RTDWrite(Data);
 
 }
 
 void WriteGamma(unsigned char code *arrayR, unsigned char code *arrayG, unsigned char code *arrayB)
 {
 unsigned char   n   = 0;
 
 RTDSetBit(0x5D, 0xfb, 0x10);    
 
 
 
 bRTD_SCSB   = 0;
 RTDSendAddr(0x64, 0, 1);
 do
 {
 RTDSendByte(arrayR[n]);
 }
 while (++n);     
 
 
 bRTD_SCLK   = 0; 
 bRTD_SCLK   = 1;           
 bRTD_SCSB   = 1;
 
 
 bRTD_SCSB   = 0;
 
#line 131 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
#line 138 "Code\Lcd_func.c" /0
 
 RTDSendAddr(0x65, 0, 1);
 do
 {
 RTDSendByte(arrayG[n]);
 }
 while (++n);
 
 bRTD_SCLK   = 0; 
 bRTD_SCLK   = 1;           
 bRTD_SCSB   = 1;
 
 
 bRTD_SCSB   = 0;
 
#line 153 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
#line 160 "Code\Lcd_func.c" /0
 RTDSendAddr(0x66, 0, 1);
 do
 {
 RTDSendByte(arrayB[n]);
 }
 while (++n);
 
 
 bRTD_SCLK   = 0; 
 bRTD_SCLK   = 1;           
 bRTD_SCSB   = 1;
 
#line 172 "Code\Lcd_func.c" /1
 
 
 
 
#line 176 "Code\Lcd_func.c" /0
 
 
 RTDSetBit(0x5D, 0xef, 0x04);    
 }
 
 void WriteDither(unsigned char code *array , bit new_dither)
 {
 unsigned char   n;
 if(new_dither)
 RTDSetBit(0x5A,0xff,0x80);
 else
 RTDSetBit(0x5A,0x7f,0x00);
 
 RTDSetBit(0x5D, 0xb7, 0x68);    
 
 
 bRTD_SCSB   = 0;
 RTDSendAddr(0x67, 0, 1);
 
 for (n = 0; n < 8; n++)     RTDSendByte(array[n]);
 
 bRTD_SCLK   = 0; 
 bRTD_SCLK   = 1;           
 bRTD_SCSB   = 1;
 
#line 201 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
#line 210 "Code\Lcd_func.c" /0
 
 
 RTDSetBit(0x5D, 0x1f, 0x88);    
 }
 
 void WriteSU_COEF(unsigned char code *arrayH, unsigned char code *arrayV)
 {
 unsigned char   n;
 
 
 
 RTDSetBit(0x1C, 0xfc, 0x01);      
 
 bRTD_SCSB   = 0;
 RTDSendAddr(0x1D, 0, 1);
 for (n = 0; n < 128; n++)    RTDSendByte(arrayH[n]);
 
 bRTD_SCLK   = 0; 
 bRTD_SCLK   = 1;           
 bRTD_SCSB   = 1;
 
 RTDSetBit(0x1C, 0xfc, 0x03);      
 
 bRTD_SCSB   = 0;
 RTDSendAddr(0x1D, 0, 1);
 for (n = 0; n < 128; n++)    RTDSendByte(arrayV[n]);
 
 bRTD_SCLK   = 0; 
 bRTD_SCLK   = 1;           
 bRTD_SCSB   = 1;
 
 
#line 242 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 261 "Code\Lcd_func.c" /0
 
 RTDSetBit(0x1C, 0xfc, 0xc4);      
 }
 
 void Set_H_Position(void)
 {
 
#line 268 "Code\Lcd_func.c" /1
 
 
#line 270 "Code\Lcd_func.c" /0
 
 
 
 
 
 if(stMUD.H_POSITION < ucH_Min_Margin)
 {
 usIPH_ACT_STA = usIPH_ACT_STA - (ucH_Min_Margin - stMUD.H_POSITION);
 stMUD.H_POSITION = ucH_Min_Margin;
 }
 
 
 ((unsigned int*)Data)[4] = usIPH_ACT_STA + (stMUD.CLOCK >> 2) - 32;
 
#line 284 "Code\Lcd_func.c" /1
 
 
#line 286 "Code\Lcd_func.c" /0
 
 
 Wait_For_Event(0x04);
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x06;
 Data[3] = (unsigned char)((unsigned int*)Data)[4];
 Data[4] = (unsigned char)(((unsigned int*)Data)[4] >> 8);
 Data[5] = 0;    
 RTDWrite(Data);
 
 
 
 
 Data[12] = (stMUD.H_POSITION - ucH_Min_Margin) + 6;
 
 RTDSetByte(0x8D, Data[12]);
 
 
 
#line 307 "Code\Lcd_func.c" /1
 
 
 
#line 310 "Code\Lcd_func.c" /0
 }
 
 
#line 313 "Code\Lcd_func.c" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 344 "Code\Lcd_func.c" /0
 void Set_V_Position(void)
 
 
 {
 unsigned int    usIV_Temp, usDV_Temp;
 
 
 
#line 352 "Code\Lcd_func.c" /1
 
 
#line 354 "Code\Lcd_func.c" /0
 
 
 RTDSetBit(0x31,0x7f,0x00);
 
 
 if ((ucV_Max_Margin - 1)  < stMUD.V_POSITION)
 {
 
 RTDSetByte(0x8C, (3 + stMUD.V_POSITION - (ucV_Max_Margin - 1)));
 
 
 usIV_Temp   = usIPV_ACT_STA + (ucV_Max_Margin - 1) - 128;
 usDV_Temp   = (unsigned int)ucDV_Delay + (ucV_Max_Margin - 1) - 128;
 }
 else
 {
 
 RTDSetByte(0x8C, 3);
 
 
 usIV_Temp   = usIPV_ACT_STA + stMUD.V_POSITION - 128;
 usDV_Temp   = (unsigned int)ucDV_Delay + stMUD.V_POSITION - 128;
 }
 
 Wait_For_Event(0x02);
 
 Data[0] = 4;
 Data[1] = 1;
 Data[2] = 0x38;
 Data[3] = (unsigned char)usDV_Temp;
 Data[4] = 5;    
 Data[5] = 0;
 Data[6] = 0x0A;
 Data[7] = (unsigned char)usIV_Temp;
 Data[8] = (unsigned char)(usIV_Temp >> 8);
 Data[9] = 0;
 RTDWrite(Data);
 
 Wait_For_Event(0x02);
 
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 
 
 
#line 400 "Code\Lcd_func.c" /1
 
 
 
#line 403 "Code\Lcd_func.c" /0
 
 
 if(bFrameSync && bStable)
 {
 RTDSetByte(0x3D,0x00);   
 RTDSetBit(0x31,0x7f,0x80);
 }
 
 
 
#line 413 "Code\Lcd_func.c" /1
 
 
#line 415 "Code\Lcd_func.c" /0
 }
 




















































































































 
 void Set_Clock(void)
 {
 unsigned char   ucM_Code, ucN_Code, ucTemp0, ucTemp1, ucResult;
 
 
 
 
 
 
 
 
 unsigned int    usClock = usADC_Clock + (unsigned int)stMUD.CLOCK - 128;     
 unsigned long   ulRate  = (unsigned long)24576 * usClock / usStdHS;          
 
 
 RTDSetBit(0x8E,0xdf,0x00);
 
 
 
#line 553 "Code\Lcd_func.c" /1
 
 
#line 555 "Code\Lcd_func.c" /0
 
 
 RTDSetBit(0x3D, 0xdf, 0x00); 
 RTDSetByte(0x3D,0x40);  
 ucPE_Max = 0;
 
 





















































































































































 
 
 ((unsigned int *)Data)[0]  = 500;
 
 ucM_Code    = 0;
 ucN_Code    = 0;
 ucResult    = 0;
 ucTemp0     = 7;
 do
 {
 
 
 
 ucTemp1 = ulRate * ucTemp0 / 215634; 
 
 if (2 <= ucTemp1)
 {    
 ((unsigned long *)Data)[2]  = ulRate * ucTemp0 / ucTemp1;
 
 
 ((unsigned int *)Data)[1]   = (unsigned long)334223600 / ((unsigned long *)Data)[2];
 
 if (1550 <= ((unsigned int *)Data)[1])
 {
 if (1570 >= ((unsigned int *)Data)[1])
 {
 ucN_Code    = ucTemp0;
 ucM_Code    = ucTemp1;
 break;
 }
 
 ((unsigned int *)Data)[1]   = ((unsigned int *)Data)[1] - 1550;
 }
 else  
 {
 if (1537 <= ((unsigned int *)Data)[1])
 {
 ucN_Code    = ucTemp0;
 ucM_Code    = ucTemp1;
 break;
 }
 
 ((unsigned int *)Data)[1]   = 1550 - ((unsigned int *)Data)[1];
 }
 
 if (((unsigned int *)Data)[0] > ((unsigned int *)Data)[1])
 {
 ((unsigned int *)Data)[0]   = ((unsigned int *)Data)[1];
 
 ucN_Code    = ucTemp0;
 ucM_Code    = ucTemp1;
 }
 }
 
 ucTemp1 = ucTemp1 + 1;
 
 if (2 <= ucTemp1)
 {
 ((unsigned long *)Data)[2]  = ulRate * ucTemp0 / ucTemp1;
 
 
 ((unsigned int *)Data)[1]   = (unsigned long)334223600 / ((unsigned long *)Data)[2];
 
 if (1550 <= ((unsigned int *)Data)[1])
 {
 if (1570 >= ((unsigned int *)Data)[1])
 {
 ucN_Code    = ucTemp0;
 ucM_Code    = ucTemp1;
 break;
 }
 
 ((unsigned int *)Data)[1]   = ((unsigned int *)Data)[1] - 1550;
 }
 else
 {
 if (1537 <= ((unsigned int *)Data)[1])
 {
 ucN_Code    = ucTemp0;
 ucM_Code    = ucTemp1;
 break;
 }
 
 ((unsigned int *)Data)[1]   = 1550 - ((unsigned int *)Data)[1];
 }
 
 if (((unsigned int *)Data)[0] > ((unsigned int *)Data)[1])
 {
 ((unsigned int *)Data)[0]   = ((unsigned int *)Data)[1];
 
 ucN_Code    = ucTemp0;
 ucM_Code    = ucTemp1;
 }
 }
 }
 while (53 >= ++ucTemp0);
 
 
 











 
 usClock     = usClock - 1;
 
 Wait_For_Event(0x04);




 
 
 RTDSetByte(0xC9, 0x8c);
 RTDSetByte(0xCA, 0x20);
 RTDSetByte(0xCB, 0x18);
 
 Data[0]     = 5;
 Data[1]     = 0;
 Data[2]     = 0xD7;
 Data[3]     = 0x0f; 
 Data[4]     = 0x00;
 Data[5]     = 0;
 RTDWrite(Data);
 
 Data[0]     = 5;
 Data[1]     = 0;
 Data[2]     = 0xCC;
 Data[3]     = (unsigned char)(usClock >> 8);
 Data[4]     = (unsigned char)usClock;
 Data[5]     = 5;
 Data[6]     = 0;
 Data[7]     = 0xDB;
 Data[8]     = ucM_Code - 2;
 Data[9]     = ucN_Code - 2;
 Data[10]    = 0;
 RTDWrite(Data);
 
 PowerUp_ADC();
 


 
 Delay_Xms(10);
 
 
 
 
 
 RTDSetByte(0xC9, 0xfc);
 RTDSetByte(0xCA, 0x21);
 RTDSetByte(0xCB, 0x17);
 
 
 
 
 
 
 
 Wait_For_Event(0x01);
 
 ulRate  = (unsigned long)24576 * usADC_Clock / usStdHS;          
 
 




 
 
 if(ucI_Code)
 {
 if((ucI_Code & 0x80) == 0x80)
 RTDSetBit(0xCA,0xdf,0x20);   
 else
 RTDSetBit(0xCA,0xdf,0x00);   
 
 ucI_Code = ucI_Code & 0x7f;
 
 RTDSetByte(0xC9,0x18 | ((ucI_Code & 0x07) << 5));
 RTDSetBit(0xCA,0xfc,0x04 | ((ucI_Code & 0x18) >> 3));
 RTDSetByte(0xCB,21);
 }
 else
 {
 RTDSetByte(0xC9,0x1C);
 RTDSetByte(0xCA,0x11);  
 RTDSetByte(0xCB, 0x16);    
 }
 
 
 
 
 
 
 
#line 914 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 946 "Code\Lcd_func.c" /0
 
 if(!bAutoInProgress)
 Wait_For_Event(0x01);
 
 
 
 if (ucPE_Level)
 {
 
 
 
 Delay_Xms(2);
 }
 
 
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 
 
 
 if(bFrameSync && bStable)
 RTDSetBit(0x8E,0xdf,0x20);
 
 
 
#line 972 "Code\Lcd_func.c" /1
 
 
 
#line 975 "Code\Lcd_func.c" /0
 } 
 
 void Set_Phase(unsigned char phase)
 {
 unsigned char   ucX_Ctrl, ucY_Ctrl, ucSelect;
 
 
 unsigned long   ulRate  = (unsigned long)24576 * usADC_Clock / usStdHS;      
 
 
#line 985 "Code\Lcd_func.c" /1
 
 
#line 987 "Code\Lcd_func.c" /0
 phase   &= 0x7c;
 
 
 ucSelect    = phase & 0x3c;
 
 phase       = phase >> 2;
 ucX_Ctrl    = (4 >= phase || 29 <= phase) ? 0x80 : (13 <= phase && 21 >= phase) ? 0x80 : 0x00;
 ucY_Ctrl    = (12 >= phase || 29 <= phase) ? 0x01 : 0x00;
 
 
#line 997 "Code\Lcd_func.c" /1
 
 
#line 999 "Code\Lcd_func.c" /0
 ucY_Ctrl    = ucX_Ctrl | (ucSelect << 1) | ucY_Ctrl;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 ucSelect    = ulRate * 391 / 1000000;
 
 
 
 ucSelect    = 32 >= ucSelect ? 32 - ucSelect : 64 - ucSelect;
 
 
 
 
 ucX_Ctrl    = (phase >= ucSelect) ? phase - ucSelect : ucSelect - phase;
 
 Data[0]     = 6 + (stMUD.H_POSITION - ucH_Min_Margin);
 
 ucSelect    = (phase + 6) < ucSelect ? Data[0] - 1 : Data[0];
 
 
 
 
 Wait_For_Event(0x04);
 
 
 RTDSetByte(0x4E, (6 < ucX_Ctrl && 26 > ucX_Ctrl) ? 0x00 : 0x10);
 
 RTDSetByte(0x8D, ucSelect);
 
 
 RTDSetByte(0x9f, ucY_Ctrl);
 
 Delay_Xms(2);
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 
 }
 
 
 
 
 
 void Set_Bright_Contrast(void)
 {
 
 if (100 < stGUD0.CONTRAST)          stGUD0.CONTRAST         = 50;
 if (100 < stGUD0.RTD_R_CONTRAST)    stGUD0.RTD_R_CONTRAST   = 50;
 if (100 < stGUD0.RTD_G_CONTRAST)    stGUD0.RTD_G_CONTRAST   = 50;
 if (100 < stGUD0.RTD_B_CONTRAST)    stGUD0.RTD_B_CONTRAST   = 50;
 
 Data[0] = 9;
 Data[1] = 0;
 Data[2] = 0x5E;
 
 
#line 1066 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
#line 1074 "Code\Lcd_func.c" /0
 {
 Data[3] = 0x7d;
 Data[4] = 0x7d;
 Data[5] = 0x7d;
 }
 
 switch((stGUD1.INPUT_SOURCE & 0x18) >> 3)
 {
 case 0:
 Data[13] = stGUD4.C1_G;
 Data[14] = stGUD4.C1_B;
 Data[15] = stGUD4.C1_R;		
 break;
 case 1:
 Data[13] = stGUD4.C2_G;
 Data[14] = stGUD4.C2_B;
 Data[15] = stGUD4.C2_R;		
 break;
 case 2:
 Data[13] = stGUD4.C3_G;
 Data[14] = stGUD4.C3_B;
 Data[15] = stGUD4.C3_R;		
 break;
 default:
 Data[13] = stGUD0.RTD_G_CONTRAST;
 Data[14] = stGUD0.RTD_B_CONTRAST;
 Data[15] = stGUD0.RTD_R_CONTRAST;
 break;
 }
 
 if((stGUD1.INPUT_SOURCE & 0x07) == 0)
 Data[6] = 0x80;  
 else
 Data[6] = (50 >= stGUD0.CONTRAST) ? 78 + stGUD0.CONTRAST : 104 + (stGUD0.CONTRAST >> 1);
 
#line 1109 "Code\Lcd_func.c" /1
 
 
#line 1111 "Code\Lcd_func.c" /0
 
 
 Data[7] = (50 >= Data[13]) ? (unsigned int)Data[6] * (75 + (Data[13] >> 1)) / 100
 : (unsigned int)Data[6] * (88 + (Data[13] >> 2)) / 100;
 
 Data[8] = (50 >= Data[14]) ? (unsigned int)Data[6] * (75 + (Data[14] >> 1)) / 100
 : (unsigned int)Data[6] * (88 + (Data[14] >> 2)) / 100;
 
 Data[6] = (50 >= Data[15]) ? (unsigned int)Data[6] * (75 + (Data[15] >> 1)) / 100
 : (unsigned int)Data[6] * (88 + (Data[15] >> 2)) / 100;
 
 Data[9] = 0;
 RTDWrite(Data);
 
 if (100 < stGUD0.BRIGHT)    stGUD0.BRIGHT   = 50;
 
 Data[0] = 6;
 Data[1] = 0;
 Data[2] = 0x90;
 
#line 1131 "Code\Lcd_func.c" /1
 
 
 
 
 
 
#line 1137 "Code\Lcd_func.c" /0
 Data[3] = 0x80;
 Data[4] = 0x01;
 
 
 
 
 
 
 












 
 
 
 
 
#line 1163 "Code\Lcd_func.c" /1
 
 
#line 1165 "Code\Lcd_func.c" /0
 Data[5] = 38 + (unsigned int)(217 - 0) * stGUD0.BRIGHT /100;						 
 
#line 1167 "Code\Lcd_func.c" /1
 
 
 
 
 
 
#line 1173 "Code\Lcd_func.c" /0
 
 
#line 1175 "Code\Lcd_func.c" /1
 
 
#line 1177 "Code\Lcd_func.c" /0
 Data[6] = 0;
 
 
 RTDWrite(Data);
 }
 
 void Set_Gamma(void)
 {
 switch (stGUD1.FUNCTION & 0x60)
 {
 case 0x20 :
 WriteGamma(GAMMA_1, GAMMA_1, GAMMA_1);
 break;
 case 0x40 :
 WriteGamma(GAMMA_2, GAMMA_2, GAMMA_2);
 break;
 case 0x60 :
 WriteGamma(GAMMA_3, GAMMA_3, GAMMA_3);
 break;
 default :
 RTDSetBit(0x5D, 0xeb, 0x00);    
 break;
 }
 }
 
 void Set_Dithering(void)
 {
 
#line 1205 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
#line 1213 "Code\Lcd_func.c" /0
 
 
 WriteDither(DITHER_1,0);
 
 
#line 1218 "Code\Lcd_func.c" /1
 
 
#line 1220 "Code\Lcd_func.c" /0
 
 RTDSetBit(0x5D, 0x97, 0x00);        
 
 
 }
 
 void Sharpness(void)
 {
 if (0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 
 
 RTDSetByte(0x1B, 0xc4);
 
 switch (stGUD1.FILTER)
 {
 case 0 :
 WriteSU_COEF(SU_COEF_1, SU_COEF_1);
 break;
 case 1 :
 WriteSU_COEF(SU_COEF_2, SU_COEF_2);
 break;
 case 2 :
 if((usIPH_ACT_WID == 1280) && (2 == 2))
 {
 WriteSU_COEF(SU_COEF_7, SU_COEF_7);
 }
 else
 {
 WriteSU_COEF(SU_COEF_3, SU_COEF_3);
 }
 
 break;
 case 3 :
 WriteSU_COEF(SU_COEF_4, SU_COEF_4);
 break;
 default :
 WriteSU_COEF(SU_COEF_5, SU_COEF_5);
 break;
 }
 
 RTDSetByte(0x1B, 0xc7);
 }
 }
 
 
 
 
 unsigned char Set_Contrast_Gain(unsigned char ContrastValue, unsigned char ColorValue)
 {
 if(ContrastValue >= 45)  
 {
 if(ColorValue & 0x80)
 {
 ColorValue &= 0x7f;
 ColorValue = ColorValue + ContrastValue - 45;
 if(ColorValue > 0x7f)
 ColorValue  = 0xff; 	 
 else
 ColorValue |= 0x80;	 
 }
 else
 {
 if(ColorValue > (ContrastValue - 45))
 ColorValue = ColorValue - (ContrastValue - 45);
 else
 ColorValue = 0x80 | (ContrastValue - 45 - ColorValue);
 }
 }
 else   
 {
 if(ColorValue & 0x80)
 {
 ColorValue &= 0x7f;
 if((45 - ContrastValue) > ColorValue)
 ColorValue = 45 - ContrastValue - ColorValue;
 else
 ColorValue = 0x80 | (ColorValue - (45 - ContrastValue));
 
 }
 else
 ColorValue = ColorValue + (45 - ContrastValue);
 }
 
 return ColorValue;
 }
 
 
 
 void SetColorGainOffset(unsigned char addr,unsigned char parameter,unsigned char bios)
 {
 if(bios & 0x80)
 {	 
 bios &= 0x7f;
 RTDSetByte(addr, (parameter >= bios) ? parameter - bios : 0);
 }
 else
 {	 
 RTDSetByte(addr, (parameter >= (0xff - bios)) ? 0xff : parameter + bios);
 }   
 }
 
 void SetADC_Gain(void)
 {










 
 
 unsigned char   ucTempContrast = 50;
 unsigned char   ucRate1  = (unsigned long)98 * usADC_Clock / usStdHS/4;
 unsigned char   ucRed = 0,ucGreen = 0,ucBlue = 0;
 
 
 if(110 < ucRate1)
 {
 ucRed   =  0x80 | 29;
 ucGreen =  0x80 | 28;
 ucBlue  =  0x80 | 27;
 }
 else if(100 < ucRate1)
 {
 ucRed   =  0x80 | 10;
 ucGreen =  0x80 | 12;
 ucBlue  =  0x80 | 10;
 
 }
 else if(90 < ucRate1)
 {
 ucRed   =  1;
 ucGreen =  1;
 ucBlue  =  2;
 
 }
 else if(70 < ucRate1)
 {
 ucRed   =  6;
 ucGreen =  5;
 ucBlue  =  5;
 
 }
 else if(48 < ucRate1)
 {
 ucRed   =  0;
 ucGreen =  0;
 ucBlue  =  0;
 }
 else if(38 < ucRate1)
 {
 ucRed   =  8;
 ucGreen =  9;
 ucBlue  =  8;
 
 }
 else
 {
 ucRed   =  2;
 ucGreen =  5;
 ucBlue  =  4;
 }
 
 
 
 
 if (100 < stGUD0.CONTRAST)	stGUD0.CONTRAST = 50;
 ucTempContrast = (unsigned int)stGUD0.CONTRAST * 9 / 10;
 
 ucRed   = Set_Contrast_Gain(ucTempContrast,ucRed);
 ucGreen = Set_Contrast_Gain(ucTempContrast,ucGreen);
 ucBlue  = Set_Contrast_Gain(ucTempContrast,ucBlue); 
 
 
 
 
 
 
#line 1403 "Code\Lcd_func.c" /1
 
 
#line 1405 "Code\Lcd_func.c" /0
 SetColorGainOffset(0xE0,stGUD2.AD_R_GAIN,ucRed);
 
 
 SetColorGainOffset(0xE1,stGUD2.AD_G_GAIN,ucGreen);
 
 
#line 1411 "Code\Lcd_func.c" /1
 
 
#line 1413 "Code\Lcd_func.c" /0
 SetColorGainOffset(0xE2,stGUD2.AD_B_GAIN,ucBlue);
 
 
 
 }
 
 void SetADC_Offset(void)
 {










 
 unsigned char   ucRed = 0, ucBlue = 0, ucGreen = 0;
 unsigned char   ucRate  = (unsigned long)98 * usADC_Clock / usStdHS/4;
 
 
 if(110 < ucRate)
 {
 ucRed = 10;
 ucGreen = 11;
 ucBlue = 11;
 }
 else if(90 < ucRate)
 {
 ucRed = 5;
 ucGreen = 7;
 ucBlue = 5;
 }
 else if(60 < ucRate)
 {
 ucRed = 0;
 ucGreen = 0;
 ucBlue = 0;
 }
 else if(48 < ucRate)
 {
 ucRed = 0x80 | 1;
 ucGreen = 0;
 ucBlue = 0x80 | 1;
 }
 else
 {
 ucRed = 0;
 ucGreen = 0x80 | 1;
 ucBlue = 0x80 | 1;
 }













 
 
 
 
#line 1483 "Code\Lcd_func.c" /1
 
 
#line 1485 "Code\Lcd_func.c" /0
 SetColorGainOffset(0xE3,stGUD2.AD_R_OFFSET,ucRed);
 
 
 SetColorGainOffset(0xE4,stGUD2.AD_G_OFFSET,ucGreen);
 
 
#line 1491 "Code\Lcd_func.c" /1
 
 
#line 1493 "Code\Lcd_func.c" /0
 SetColorGainOffset(0xE5,stGUD2.AD_B_OFFSET,ucBlue);
 
 
 
 }
 
 void SetADC_GainOffset(void)
 {
 SetADC_Gain();
 SetADC_Offset();
 }
 
#line 1505 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1530 "Code\Lcd_func.c" /0
 



















 
 
 void Wait_For_Event(unsigned char event)
 {
 unsigned char   ucDelayCnt  = 80;    
 unsigned char   ucProtect   = 24;    
 
 RTDSetByte(0x1F,0x00);           
 
 bNotify_Timer1_Int  = 0;
 
 Data[0] = 0;
 Data[1] = 0;
 TR1     = 1;
 do
 {
 if (bNotify_Timer1_Int)
 {
 bNotify_Timer1_Int  = 0;
 
 if (Data[1] & (0x01 | 0x02))
 {
 Data[1]     = 0;
 ucProtect   = 24;
 }
 else if (ucProtect)
 {
 ucProtect   = ucProtect - 1;
 }
 
 if (--ucDelayCnt)   TR1 = 1;
 }
 
 
 RTDRead(0x1F, 1, 1);   
 
 
 if(Data[0])
 RTDSetByte(0x1F,0x00);
 
 
 Data[1] |= (Data[0] & (0x01 | 0x02));
 Data[0] &= event;
 
 }
 while (0 == Data[0] && 0 != ucDelayCnt);
 }
 
 
#line 1599 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 













 
 
 
 
 
 
#line 1661 "Code\Lcd_func.c" /0
 
 
 void Save_GUD0(void)
 {
 Data[0]     = 11;
 Data[1]     = 0xAE;
 Data[2]     = 0xE0;
 Data[3]     = stGUD0.CONTRAST;
 Data[4]     = stGUD0.BRIGHT;
 Data[5]     = stGUD0.RTD_R_CONTRAST;
 Data[6]     = stGUD0.RTD_G_CONTRAST;
 Data[7]     = stGUD0.RTD_B_CONTRAST;
 Data[8]     = stGUD0.RTD_R_BRIGHT;
 Data[9]     = stGUD0.RTD_G_BRIGHT;
 Data[10]    = stGUD0.RTD_B_BRIGHT;
 I2CWrite(Data);
 
 Delay_Xms(0x10);
 }
 
 void Load_GUD0(void)
 {
 I2CRead(0xAE, 0xE0 , 8);
 
 stGUD0.CONTRAST         = Data[0];
 stGUD0.BRIGHT           = Data[1];
 stGUD0.RTD_R_CONTRAST   = Data[2];
 stGUD0.RTD_G_CONTRAST   = Data[3];
 stGUD0.RTD_B_CONTRAST   = Data[4];
 stGUD0.RTD_R_BRIGHT     = Data[5];
 stGUD0.RTD_G_BRIGHT     = Data[6];
 stGUD0.RTD_B_BRIGHT     = Data[7];
 }
 
 void Save_GUD1(void)
 {
 Data[0]     = 10;
 Data[1]     = 0xAE;
 Data[2]     = 0xE8;
 Data[3]     = stGUD1.FUNCTION;
 Data[4]     = stGUD1.INPUT_SOURCE;
 Data[5]     = stGUD1.FILTER;
 Data[6]     = stGUD1.OSD_POSH;
 Data[7]     = stGUD1.OSD_POSV;
 Data[8]     = stGUD1.OSD_TIMEOUT;
 Data[9]     = stGUD1.OSD_INPUT;			 
 Data[10]     = 0;						 
 I2CWrite(Data);
 
 Delay_Xms(0x10);
 }
 
 void Load_GUD1(void)
 {
 I2CRead(0xAE, 0xE8 , 7);
 
 stGUD1.FUNCTION			= Data[0];
 stGUD1.INPUT_SOURCE	= Data[1];
 stGUD1.FILTER			= Data[2];
 stGUD1.OSD_POSH		= Data[3];
 stGUD1.OSD_POSV		= Data[4];
 stGUD1.OSD_TIMEOUT		= Data[5];
 stGUD1.OSD_INPUT 		= Data[6];		 
 
 }
 
 void Save_GUD2(void)
 {
 Data[0]     = 9;
 Data[1]     = 0xAE;
 Data[2]     = 0xF0;
 Data[3]     = stGUD2.AD_R_GAIN;
 Data[4]     = stGUD2.AD_G_GAIN;
 Data[5]     = stGUD2.AD_B_GAIN;
 Data[6]     = stGUD2.AD_R_OFFSET;
 Data[7]     = stGUD2.AD_G_OFFSET;
 Data[8]     = stGUD2.AD_B_OFFSET;
 
 I2CWrite(Data);
 Delay_Xms(0x10);
 }
 
 void Load_GUD2(void)
 {
 I2CRead(0xAE, 0xF0 , 6);
 
 stGUD2.AD_R_GAIN    = Data[0];
 stGUD2.AD_G_GAIN    = Data[1];
 stGUD2.AD_B_GAIN    = Data[2];
 stGUD2.AD_R_OFFSET  = Data[3];
 stGUD2.AD_G_OFFSET  = Data[4];
 stGUD2.AD_B_OFFSET  = Data[5];
 }
 
 void Save_GUD3(void)
 {
 Data[0]     = 7;
 Data[1]     = 0xAE;
 Data[2]     = 0xF8;
 Data[3]     = stGUD3.VOLUME;
 Data[4]     = stGUD3.CURR_CHANNEL;
 Data[5]     = stGUD3.PREV_CHANNEL;
 Data[6]     = stGUD3.TV_SETTING;
 
 I2CWrite(Data);
 Delay_Xms(0x10);
 }
 
 void Load_GUD3(void)
 {
 I2CRead(0xAE, 0xF8 , 4);
 
 stGUD3.VOLUME       = Data[0];
 stGUD3.CURR_CHANNEL = Data[1];
 stGUD3.PREV_CHANNEL = Data[2];
 stGUD3.TV_SETTING   = Data[3];
 }
 
 void Save_GUD4(void)
 {
 Data[0]     = 12;
 Data[1]     = 0xAE;
 Data[2]     = 0xD0;
 Data[3]     = stGUD4.C1_R;
 Data[4]     = stGUD4.C1_G;
 Data[5]     = stGUD4.C1_B;
 Data[6]     = stGUD4.C2_R;
 Data[7]     = stGUD4.C2_G;
 Data[8]     = stGUD4.C2_B;
 Data[9]     = stGUD4.C3_R;
 Data[10]    = stGUD4.C3_G;
 Data[11]    = stGUD4.C3_B;
 I2CWrite(Data);
 
 Delay_Xms(0x10);
 }
 
 void Load_GUD4(void)
 {
 I2CRead(0xAE, 0xD0 , 9);
 
 stGUD4.C1_R   = Data[0];
 stGUD4.C1_G   = Data[1];
 stGUD4.C1_B   = Data[2];
 stGUD4.C2_R   = Data[3];
 stGUD4.C2_G   = Data[4];
 stGUD4.C2_B   = Data[5];
 stGUD4.C3_R   = Data[6];
 stGUD4.C3_G   = Data[7];
 stGUD4.C3_B   = Data[8];
 }
 
 
 void Save_MUD(unsigned char mode_num)
 {
 if (0 == mode_num || 64 < mode_num)  return;
 
 Data[0] = 7;
 Data[1] = 0xAC;
 Data[2] = (mode_num - 1) << 2;	        
 Data[3] = stMUD.H_POSITION;
 Data[4] = stMUD.V_POSITION;
 Data[5] = stMUD.CLOCK;
 Data[6] = (stMUD.PHASE & 0x7c); 
 I2CWrite(Data);
 
 Delay_Xms(0x10);
 }
 
 void Load_MUD(unsigned char mode_num)
 {
 if (0 == mode_num || 64 < mode_num)  return;
 
 I2CRead(0xAC, (mode_num - 1) << 2, 4);
 
 stMUD.H_POSITION    = Data[0];
 stMUD.V_POSITION    = Data[1];
 stMUD.CLOCK         = Data[2];
 stMUD.PHASE         = Data[3] & 0x7c;
 
 
 
 }
 
 void Init_GUD(void)      
 {
 stGUD0.CONTRAST         = INIT_EEPROM0[3];
 stGUD0.BRIGHT           = INIT_EEPROM0[4];
 stGUD0.RTD_R_CONTRAST   = INIT_EEPROM0[5];
 stGUD0.RTD_G_CONTRAST   = INIT_EEPROM0[6];
 stGUD0.RTD_B_CONTRAST   = INIT_EEPROM0[7];
 stGUD0.RTD_R_BRIGHT     = INIT_EEPROM0[8];
 stGUD0.RTD_G_BRIGHT     = INIT_EEPROM0[9];
 stGUD0.RTD_B_BRIGHT     = INIT_EEPROM0[10];
 
 stGUD1.FUNCTION         = INIT_EEPROM0[11];
 stGUD1.INPUT_SOURCE     = INIT_EEPROM0[12];
 stGUD1.FILTER           = INIT_EEPROM0[13];
 stGUD1.OSD_POSH         = INIT_EEPROM0[14];
 stGUD1.OSD_POSV         = INIT_EEPROM0[15];
 stGUD1.OSD_TIMEOUT      = INIT_EEPROM0[16];
 stGUD1.OSD_INPUT      = INIT_EEPROM0[17];		 
 
 stGUD2.AD_R_GAIN        = INIT_EEPROM1[3];
 stGUD2.AD_G_GAIN        = INIT_EEPROM1[4];
 stGUD2.AD_B_GAIN        = INIT_EEPROM1[5];
 stGUD2.AD_R_OFFSET      = INIT_EEPROM1[6];
 stGUD2.AD_G_OFFSET      = INIT_EEPROM1[7];
 stGUD2.AD_B_OFFSET      = INIT_EEPROM1[8];
 
 stGUD3.VOLUME           = INIT_EEPROM1[11];
 stGUD3.CURR_CHANNEL     = INIT_EEPROM1[12];
 stGUD3.PREV_CHANNEL     = INIT_EEPROM1[13];
 stGUD3.TV_SETTING       = INIT_EEPROM1[14];
 
 stGUD4.C1_R             = INIT_EEPROM2[3];
 stGUD4.C1_G             = INIT_EEPROM2[4];
 stGUD4.C1_B             = INIT_EEPROM2[5];
 stGUD4.C2_R             = INIT_EEPROM2[6];
 stGUD4.C2_G             = INIT_EEPROM2[7];
 stGUD4.C2_B             = INIT_EEPROM2[8];
 stGUD4.C3_R             = INIT_EEPROM2[9];
 stGUD4.C3_G             = INIT_EEPROM2[10];
 stGUD4.C3_B             = INIT_EEPROM2[11];
 
 
 I2CWrite(INIT_EEPROM0);
 Delay_Xms(0x10);
 
 I2CWrite(INIT_EEPROM1);
 Delay_Xms(0x10);
 
 I2CWrite(INIT_EEPROM2);
 Delay_Xms(0x10);
 
 
 
 }
 
 void Init_MUD(void)
 {
 unsigned char   ucModeIdx;
 
 
 Data[0]     = 11;
 Data[1]     = 0xAE;
 Data[2]     = 0;
 Data[3]     = 0xff;
 Data[4]     = 0xff;
 Data[5]     = 0xff;
 Data[6]     = 0xff;
 Data[7]     = 0xff;
 Data[8]     = 0xff;
 Data[9]     = 0xff;
 Data[10]    = 0xff;
 I2CWrite(Data);
 Delay_Xms(0x10);
























 
 
 Data[0]     = 7;
 Data[1]     = 0xAC;
 Data[2]     = 0;
 Data[3]     = 0x80;  
 Data[4]     = 0x80;  
 Data[5]     = 0x80;  
 Data[6]     = 0x01;  
 
 ucModeIdx   = 0;
 do
 {
 Data[2]     = ucModeIdx << 2;
 ucModeIdx   = ucModeIdx + 1;
 
 switch (ucModeIdx)
 {
 case 64 :
 Data[3] = 0xbc;          
 Data[4] = 0x65 ^ 0x80;   
 Data[5] = 0x64 ^ 0x80;   
 Data[6] = 0x00 ^ 0x80;   
 break;
 case 65 :
 Data[3] = 0xb1;          
 Data[4] = 0x5f ^ 0x80;   
 Data[5] = 0x65 ^ 0x80;   
 Data[6] = 0x00 ^ 0x80;   
 break;
 
#line 1973 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1986 "Code\Lcd_func.c" /0
 case 62 :
 Data[3] = 0x95;          
 Data[4] = 0x47 ^ 0x80;   
 Data[5] = 0x48 ^ 0x80;   
 Data[6] = 0xff ^ 0x80;   
 break;
 case 63 :
 Data[3] = 0x82;          
 Data[4] = 0x47 ^ 0x80;   
 Data[5] = 0x42 ^ 0x80;   
 Data[6] = 0x00 ^ 0x80;   
 break;
 
 }
 
 I2CWrite(Data);
 Delay_Xms(0x10);
 }
 while (64 > ucModeIdx);
 }
 
 void Check_EEPROM(void)
 {
 I2CRead(0xAE, 0xFE , 2);
 
 if ((INIT_EEPROM1[17] != Data[0]) || (INIT_EEPROM1[18] != Data[1]))
 {
 Delay_Xms(0x10);
 
 Init_GUD();
 Init_MUD();
 }
 else
 {
 Load_GUD0();             
 Load_GUD1();             
 Load_GUD2();             
 Load_GUD3();             
 Load_GUD4();             
 }
 }
 
 void Free_Background(void)   
 {
 RTDCodeW(FreeV);                             
 
 
 if ( 0 == bPanel_Status)
 {
 
 RTDSetByte(0x21, 0x00 | 0x00 | 0x00 | 0x00);        
 RTDSetBit(0x20, 0xfd, 0x01);     
 }
 
 RTDSetBit(0x04, 0xfe, 0x00);         
 
 
 RTDSetBit(0x21, 0x0f, 5 == (stGUD1.INPUT_SOURCE & 0x07) ? 0x10 | 0x00 | 0x00 | 0x00  : 
 0x00 | 0x00 | 0x00 | 0x00);
 
 }
 
 
 void Reset_Mode(void)
 {  
 unsigned char ucTimeout = 120;
 
 
  M512_Port51  = 1;         
 
#line 2056 "Code\Lcd_func.c" /1
 
 
#line 2058 "Code\Lcd_func.c" /0
 
 
 RTDSetByte(0x02, 0x40);   
 
 
#line 2063 "Code\Lcd_func.c" /1
 
 
#line 2065 "Code\Lcd_func.c" /0
 
 
 
 RTDSetBit(0x99,0x0f,0x00);  
 
 
#line 2071 "Code\Lcd_func.c" /1
 
 
#line 2073 "Code\Lcd_func.c" /0
 
 
 RTDSetBit(0x8E,0xdf,0x00);
 
 
 RTDSetBit(0x31,0x7f,0x00);
 
 
 
 RTDSetBit(0xFF,0xfc,0x00);
 
 
 RTDSetByte(0x01, 0x00);   
 RTDSetByte(0x1F, 0x00);   
 RTDSetByte(0x3D,0x00);
 
 
 
 Free_Background();
 
 RTDOSDW(OSD_Reset);             
 RTDSetBit(0x6D, 0xfe, 0x00);	 
 
 
 RTDSetBit(0x3D, 0xdf, 0x00); 
 
 RTDSetByte(0x3D,0x40);  
 do
 {
 RTDRead(0x3D, 1, 1);
 Delay_Xms(1); 
 
 }while( --ucTimeout && ((Data[0] & 0x40 ) == 0x40));
 ucPE_Max = 0;
 ucPE_Level = 0;
 
 
 
 ucMode_Curr     = 0;
 ucMode_Found    = 255;
 
 ucMode_Times    = 0;
 ucAV_Mode       = 0;
 bStable         = 0;
 bReload         = 1;
 bFrameSync      = 0;
 ucPE_Max        = 0;
 ucI_Code        = 0;
 bOverSpec       = 0;
 
 if (2 == ucInputSrc || 3 == ucInputSrc || 5 == ucInputSrc)
 {
 RTDCodeW(VIDEO_INI);
 I2CWrite((3 == ucInputSrc) ? SV_DETECT : AV_DETECT);
 
 if (5 == ucInputSrc)
 {
 
 I2CWrite(TV_SOURCE_SEL);
 I2CWrite(TV_SCAN_GAIN);
 }
 }
 
#line 2136 "Code\Lcd_func.c" /1
 
 
 
 
 
 
#line 2142 "Code\Lcd_func.c" /0
 
 }
 
 
 
#line 2147 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 2261 "Code\Lcd_func.c" /0
 
 
 
 
 
 
 
 
#line 2269 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 2335 "Code\Lcd_func.c" /0
 
 
#line 2337 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 2411 "Code\Lcd_func.c" /0
 
 void RTD_Test(void)
 {
 
 
#line 2416 "Code\Lcd_func.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 2572 "Code\Lcd_func.c" /0
 
 }
 
 
 
 
 
 
 void Set_Spread(void)
 {
 RTDSetBit(0x99, 0x00, (stGUD3.SPREAD << 4));
 RTDSetBit(0x9b, 0xff, 0x20);
 }
 
 void Init_FRecall(void)				 
 {
 stGUD0.CONTRAST         = INIT_EEPROM0[3];
 stGUD0.BRIGHT           = INIT_EEPROM0[4];
 
 
 
 stGUD0.RTD_R_BRIGHT     = INIT_EEPROM0[8];
 stGUD0.RTD_G_BRIGHT     = INIT_EEPROM0[9];
 stGUD0.RTD_B_BRIGHT     = INIT_EEPROM0[10];
 
 stGUD1.FUNCTION         = INIT_EEPROM0[11];
 stGUD1.INPUT_SOURCE     = INIT_EEPROM0[12];
 stGUD1.FILTER           = INIT_EEPROM0[13];
 stGUD1.OSD_POSH         = INIT_EEPROM0[14];
 stGUD1.OSD_POSV         = INIT_EEPROM0[15];
 stGUD1.OSD_TIMEOUT      = INIT_EEPROM0[16];
 stGUD1.OSD_INPUT      = INIT_EEPROM0[17];
 
 stGUD3.VOLUME           = INIT_EEPROM1[11];
 stGUD3.CURR_CHANNEL     = INIT_EEPROM1[12];
 stGUD3.PREV_CHANNEL     = INIT_EEPROM1[13];
 
 I2CWrite(INIT_EEPROM0);
 Delay_Xms(0x10);
 
 
 
 
 Save_GUD0();
 Save_GUD3();					 
 }
 
 void Init_FACTORY(void)		 
 {
 unsigned char   ucTemp1, ucTemp2;
 
 
 ucTemp1 = stGUD1.FUNCTION & 0x07;        
 ucTemp2 = stGUD1.INPUT_SOURCE & 0x07;    
 
 if (7 < ucTemp1)
 ucTemp1 = 0;
 
 
 usOSD_Timer = (unsigned int)2 << 9;      
 
 
 Init_FRecall();
 
 
 usOSD_Timer = (unsigned int)stGUD1.OSD_TIMEOUT << 9;
 
 
 stGUD1.FUNCTION     = (stGUD1.FUNCTION & 0xf8) | ucTemp1;
 stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | ucTemp2;
 Save_GUD1();
 
 
 Set_Bright_Contrast();
 SetADC_Gain();				 
 
 
 SetVolume();
 
 
 if (0 == (stGUD1.INPUT_SOURCE & 0x07))
 {
 if (0xfc == Auto_Config())   ucMode_Curr = 254;
 }
 
 
 OSD_Position(0x01);
 
 
 Init_MUD();
 
 
 Load_MUD(ucMode_Curr);
 
 
 
 }
 
