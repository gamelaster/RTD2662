
#line 1 "Code\Lcd_osd.c" /0
 
 
  
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
 
 
#line 3 "Code\Lcd_osd.c" /0
 
 
  
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 5 "Code\Lcd_osd.c" /0
 
  
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
 
 
#line 6 "Code\Lcd_osd.c" /0
 
  
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
 
 
#line 7 "Code\Lcd_osd.c" /0
 
  
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
 
 
#line 8 "Code\Lcd_osd.c" /0
 
  
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
 
 
#line 9 "Code\Lcd_osd.c" /0
 
  
#line 1 "Header\LCD_MSG.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 56 "Header\LCD_MSG.H" /1
 
 
 
 
 
 
 
 
#line 64 "Header\LCD_MSG.H" /0
 
 extern unsigned char idata  ucKey_Issued;
 extern bit bKeyTurbo;						 
 
 extern unsigned char Key_Trans();
 extern void OSD_Dispatcher(unsigned char message);
 
 
 
#line 10 "Code\Lcd_osd.c" /0
 
  
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
 
 
 
#line 11 "Code\Lcd_osd.c" /0
 
  
#line 1 "Header\LCD_OSD.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char   idata   ucOSD_Page_Index    = 0;
 unsigned char   idata   ucOSD_Item_Index0   = 0;
 unsigned char   idata   ucOSD_Item_Index1   = 0;
 unsigned char   idata   ucOSD_Item_Index2   = 0;
 
 unsigned char   idata   ucOSD_Pre_Page_Index    = 0;
 
#line 32 "Header\LCD_OSD.H" /1
 
 
 
 
#line 36 "Header\LCD_OSD.H" /0
 
 unsigned char GetNextPageIdx(unsigned char ucPageCurr);
 unsigned char GetPrevPageIdx(unsigned char ucPageCurr);
 
 
 void OSD_Window(unsigned char win_no, unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end,
 unsigned char width, unsigned char height, unsigned char color, unsigned char color_sb, unsigned char gradient,
 unsigned char gra_level,unsigned char attr);
 void OSD_Position(unsigned char para);
 void OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
 unsigned char color, unsigned char color_slider);
 
 void Get_OSD_Margin(void);
 
 void OSD_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate);
 void OSD_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);
 
 
 
 
 void OSD_Fact_Line(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char indicate); 
 void OSD_Fact_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width);	 
 void Value_Adjust(unsigned char *Var, unsigned char Key, unsigned char VMax, unsigned char VMin); 
 
 
 
 void Show_Mode(void);
 void Init_Page(unsigned char index);
 void OSD_Proc(unsigned char action);
 void OSD_Proc_B(unsigned char action);
 
 
 void OSD_TV_Proc(unsigned char action);
 void OSD_TV_Menu(unsigned char action);
 void Show_TV_Info(unsigned channel, unsigned char option);
 void Show_TV_Number(unsigned char num, unsigned char row, unsigned char col, unsigned char option);
 
 void TV_AutoScan(void);
 
 void OSD_Opening(void);
 void OSD_Ending(void);
 
 
 void Show_Note(void);
 void Show_Hint(void);
 
 
#line 83 "Header\LCD_OSD.H" /1
 
 
 
#line 86 "Header\LCD_OSD.H" /0
 
 
 
 
#line 90 "Header\LCD_OSD.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 137 "Header\LCD_OSD.H" /0
 
#line 12 "Code\Lcd_osd.c" /0
 
  
#line 1 "Header\FONT.H" /0
 
#line 2 "Header\FONT.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4329 "Header\FONT.H" /0
 
 extern unsigned char code Font_East_J[];  
 extern unsigned char code Font_East_C[];  
 extern unsigned char code Font_Global[];  
 extern unsigned char code Font_Icons[];  
 extern unsigned char code Font_add[];					 
 
 
#line 13 "Code\Lcd_osd.c" /0
 
  
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
 
 
 
#line 14 "Code\Lcd_osd.c" /0
 
  
#line 1 "Header\SRC_CTRL.H" /0
 
#line 2 "Header\SRC_CTRL.H" /1
 
 
 
 
 
 
 
 
 
 
 
#line 13 "Header\SRC_CTRL.H" /0
 
 
 
 extern bit bSourceScanEnable;     
 
 
 
 
 extern bit Source_Control(void);
 extern void Change_Source(unsigned char source);
 
 
 extern void Source_Auto_Scan();
 
 
 
#line 15 "Code\Lcd_osd.c" /0
 
  
#line 1 "Header\OSD_TREE.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 89 "Header\OSD_TREE.H" /1
 
  
  
  
  
  
  
  
 
 
#line 99 "Header\OSD_TREE.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
#line 111 "Header\OSD_TREE.H" /1
 
 
 
  
  
  
 
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
 
  
  
  
 
 
 
  
  
  
  
  
  
 
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
  
  
  
 
  
 
 
 
 
 
 
 
 
#line 188 "Header\OSD_TREE.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 202 "Header\OSD_TREE.H" /1
 
 
 
 
 
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
  
  
  
 
  
 
 
 
 
 
 
  
  
  
  
  
  
  
 
  
 
 
 
  
  
  
  
  
  
  
  
 
 
 
 
 
 
#line 261 "Header\OSD_TREE.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 16 "Code\Lcd_osd.c" /0
 
 
  
#line 1 "Header\rgb_echo.H" /0
 
 
 
 
 
 
 
 
 bit b_rgb_VOLUME_STATUS = 0;
 
 void rgb_OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
 unsigned char color, unsigned char color_slider);
 void rgb_LED_LIGHT_CONTROL(void);
 
 void rgb_EXIT_KEY(void);
 
 
 
#line 19 "Header\rgb_echo.H" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 18 "Code\Lcd_osd.c" /0
#line 18 "Code\Lcd_osd.c" /0
 
 
 
#line 21 "Code\Lcd_osd.c" /1
  
 
#line 23 "Code\Lcd_osd.c" /0
 
 
 
 
 
 
 unsigned char GetNextPageIdx(unsigned char ucPageCurr)
 {
 switch (stGUD1.INPUT_SOURCE & 0x07)
 {
 case 0 :
 return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
 case 1 :
 return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
 case 2  :
 return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
 case 3  :
 return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
 case 4 :
 return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
 default :
 return 1;
 }
 
 }
 
 unsigned char GetPrevPageIdx(unsigned char ucPageCurr)
 {
 switch (stGUD1.INPUT_SOURCE & 0x07)
 {
 case 0 :
 return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
 case 1 :
 return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
 case 2  :
 return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
 case 3  :
 return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
 case 4 :
 return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
 default :
 return 1;
 }
 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void OSD_Window(unsigned char win_no, unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end,
 unsigned char width, unsigned char height, unsigned char color, unsigned char color_sb, unsigned char gradient,
 unsigned char gray_level,unsigned char attr)
 {
 if(win_no > 7)  
 return;
 
 Data[0]     = 5;
 Data[1]     = 0;
 Data[2]     = 0x90;
 Data[3]     = 0xc1;
 Data[4]     = (win_no << 2);
 Data[5]     = 0;
 RTDWrite(Data);
 Data[0]     = 6;
 Data[1]     = 1;
 Data[2]     = 0x92;
 Data[3]     = ((width & 0x07) << 3) | (height & 0x07);
 Data[4]     = color_sb;
 Data[5]     = gradient;
 Data[6]     = 0;
 RTDWrite(Data);
 
 Data[0]     = 5;
 Data[1]     = 0;
 Data[2]     = 0x90;
 Data[3]     = 0xe1;
 Data[4]     = (win_no << 2) + 1;
 Data[5]     = 0;
 RTDWrite(Data);
 Data[0]     = 9;
 Data[1]     = 1;
 Data[2]     = 0x92;
 Data[3]     = (unsigned char)((unsigned int)(row_start & 0x003f) << 2);
 Data[4]     = (unsigned char)((unsigned int)(col_start & 0x0007) << 5) | 
 (unsigned char)((unsigned int)(row_start & 0x07c0) >> 6);
 Data[5]     = (unsigned char)((unsigned int)(col_start & 0x07f8) >> 3);
 
 Data[6]     = (unsigned char)((unsigned int)(row_end & 0x003f) << 2);
 Data[7]    = (unsigned char)((unsigned int)(col_end & 0x0007) << 5) | 
 (unsigned char)((unsigned int)(row_end & 0x07c0) >> 6);
 Data[8]    = (unsigned char)((unsigned int)(col_end & 0x07f8) >> 3);
 Data[9]     = 0;
 RTDWrite(Data);
 
 Delay_Xms(25);
 






 
 
 Data[0]     = 5;
 Data[1]     = 0;
 Data[2]     = 0x90;
 Data[3]     = 0xc1;
 Data[4]     = (win_no << 2) + 3;
 Data[5]     = 0;
 RTDWrite(Data);
 Data[0]     = 6;
 Data[1]     = 1;
 Data[2]     = 0x92;
 Data[3]    = 0x00;
 Data[4]    = (unsigned char)((gray_level & 0x07) << 4) |( color & 0x0f);
 Data[5]    = attr;
 Data[6]    = 0;
 RTDWrite(Data);
 
 }
 
 
 
 
 void OSD_Fact_Line(unsigned char row, unsigned char col, unsigned char length,
 unsigned char value, unsigned char indicate)
 {
 unsigned int idata usStart_Addr;
 unsigned char idata ucTemp;
 
 usStart_Addr = 19;
 
 
 for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
 usStart_Addr += FactRow_Info[0][ucTemp];
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x90;
 
 if( (col+1) > FactRow_Info[0][row + 1])	 
 return;
 else if((col + 1 + length) > FactRow_Info[0][row + 1])	 
 length = FactRow_Info[0][row + 1] - col;
 
 
 Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | (((indicate << 2) + 1) << 4);
 Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
 Data[5] = 0;
 RTDWrite(Data);
 
 Data[0]     = (indicate == 3) ? length * 3 + 3 : length + 3;
 Data[1]     = 2;
 Data[2]     = 0x92;
 Data[3]     = value;
 Data[4]     = 0;
 RTDWrite(Data);
 
 }
 
 void OSD_Fact_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width)
 {
 width = width;
 if (height)
 {
 do
 {
 OSD_Fact_Line(row_start, col_start, FactRow_Info[0][row_start+1], 0x00, 3);
 
 row_start++;
 }
 while (--height);
 }
 }
 
 void ShowValue(unsigned char row, unsigned char col,unsigned char value, unsigned char color)
 {
 unsigned int idata usStart_Addr;
 unsigned char idata ucTemp;
 
 usStart_Addr = 19;
 
 
 for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
 usStart_Addr += FactRow_Info[0][ucTemp];
 
 Data[10] = value/100;
 Data[11] = (value - (Data[10]*100))/10;
 Data[12] = value - (Data[10]*100) - (Data[11]*10);
 if(0 != Data[10])
 {
 Data[10] += 0x01;
 Data[11] += 0x01;
 }
 else
 {
 if(0 != Data[11])	Data[11] += 0x01;
 }
 Data[12] += 0x01;
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x90;
 Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | 0x50;
 Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
 Data[5] = 0;
 RTDWrite(Data);
 Data[0]     = 6;
 Data[1]     = 1;
 Data[2]     = 0x92;
 Data[3]     = Data[10];
 Data[4]     = Data[11];
 Data[5]     = Data[12];
 Data[6]     = 0;
 RTDWrite(Data);
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x90;
 Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | 0x90;
 Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
 Data[5] = 0;
 RTDWrite(Data);
 Data[0]     = 6;
 Data[1]     = 1;
 Data[2]     = 0x92;
 Data[3]     = color;
 Data[4]     = color;
 Data[5]     = color;
 Data[6]     = 0;
 RTDWrite(Data);
 }
 
 void Value_Adjust(unsigned char *Var, unsigned char Key, unsigned char VMax, unsigned char VMin)
 {
 if(0x04 == Key)
 {
 if(bKeyTurbo)
 *Var   = (*Var < (VMax - 1)) ? (*Var + 2) : VMax;
 else
 *Var   = (*Var < VMax) ? (*Var + 1) : VMax;
 }
 else
 {
 if(bKeyTurbo)
 *Var   = (*Var > (VMin + 1)) ? *Var - 2 : VMin;
 else
 *Var   = (*Var > VMin) ? (*Var - 1) : VMin;
 }
 }
 
 void SPREAD_Adjust(unsigned char* variable,unsigned char Key)
 {
 if (0x04 == Key)
 {
 if (15 <= *variable)
 return;
 
 if (!bKeyTurbo)
 *variable   = 15 > *variable ? *variable + 1 : 15;
 else
 *variable   = 14 > *variable ? *variable + 2 : 15;
 }
 else
 {
 if (0 == *variable)
 return;
 
 if (!bKeyTurbo)
 *variable   = 0 < *variable ? *variable - 1 : 0;
 else
 *variable   = 1 < *variable ? *variable - 2 : 0;
 }
 }
 
 
 
 
 
 void Get_OSD_Margin(void)
 {
 unsigned char ucH_Min, ucH_Max, ucV_Max;
 
 
#line 340 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
#line 347 "Code\Lcd_osd.c" /0
 RTDRead(0x29, 0x02, 0);
 Data[2] = Data[1] & 0x07;
 Data[3] = Data[0];
 
 
 ucH_Max = ((((unsigned int *)Data)[1] - 512) / 4) + 1; 
 ucH_Min = (((0x0520 - (0x0520 - 0x0020)) / 4) + 1);
 
 
 RTDRead(0x34, 0x02, 0);
 Data[2] = Data[1] & 0x07;
 Data[3] = Data[0];
 
 ucV_Max = (((unsigned int *)Data)[1] - 0x000c - 250 - 14) / 4;
 
 Data[0] = ucH_Min;
 Data[1] = ucH_Max;
 Data[2] = 3;
 Data[3] = ucV_Max;
 
 }
 
 
 
 
 
 
 
 
 
 void OSD_Position(unsigned char para)
 {
 Get_OSD_Margin();
 
 if (Data[0] > stGUD1.OSD_POSH || Data[1] < stGUD1.OSD_POSH ||
 Data[2] > stGUD1.OSD_POSV || Data[3] < stGUD1.OSD_POSV)
 {
 stGUD1.OSD_POSV = ((3 + (((0x040c - 0x000c) - 250 - 14) / 4)) / 2);
 stGUD1.OSD_POSH = (((((0x0520 - 544) / 4) + 1) + (((0x0520 - (0x0520 - 0x0020)) / 4) + 1)) / 2);
 Save_GUD1();
 }
 
 if(ucOSD_Page_Index == 15)		 
 {
 stGUD1.OSD_POSH = 230;
 stGUD1.OSD_POSV = 100;
 }
 
 Wait_For_Event(0x20);
 
 Data[0]     = 5;
 Data[1]     = 0;
 Data[2]     = 0x90;
 Data[3]     = 0xc0;
 Data[4]     = 0x00;
 Data[5]     = 6;
 Data[6]     = 1;
 Data[7]     = 0x92;
 Data[8]     = stGUD1.OSD_POSV >> 1;
 Data[9]     = (unsigned char)(stGUD1.OSD_POSH >> 2);
 Data[10]    = ((unsigned char)(stGUD1.OSD_POSH & 0x0003) << 6) | ((stGUD1.OSD_POSV & 0x01) << 5) | para;
 
 Data[11]    = 0;
 RTDWrite(Data);
 
 }
 
 void OSD_Line(unsigned char row, unsigned char col, unsigned char length,
 unsigned char value, unsigned char indicate)
 {
 unsigned int idata usStart_Addr;
 unsigned char idata ucTemp;
 
 usStart_Addr = 19;
 
 
 for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
 usStart_Addr += Row_Info[0][ucTemp];
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x90;
 
 if( (col+1) > Row_Info[0][row + 1])	 
 return;
 else if((col + 1 + length) > Row_Info[0][row + 1])	 
 length = Row_Info[0][row + 1] - col;
 
 
 Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | (((indicate << 2) + 1) << 4);
 Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
 Data[5] = 0;  
 RTDWrite(Data);
 
 Data[0]     = (indicate == 3) ? length * 3 + 3 : length + 3;
 Data[1]     = 2; 
 Data[2]     = 0x92;
 Data[3]     = value;
 Data[4]     = 0;
 RTDWrite(Data);
 
 }     
 
 
 void OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
 unsigned char color, unsigned char color_slider)
 {
 unsigned int idata usStart_Addr;
 unsigned char idata ucTemp;
 unsigned int bound;
 
 usStart_Addr = 19;
 
 for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
 usStart_Addr += Row_Info[0][ucTemp];
 
 length = length -5;
 bound   = ((length-2)*6 + 2*3) * value;
 
 
 Data[0] = 6;
 Data[1] = 0;
 Data[2] = 0x90;
 Data[3] = (unsigned char)((((usStart_Addr + col) >>8 ) & 0x0f ) | 0x90);
 Data[4] = (unsigned char)( (usStart_Addr + col) & 0x00ff);
 Data[5] = (color << 4) & 0xf0;		
 Data[6] = 0;
 RTDWrite(Data);
 
 Data[0] = 5;
 Data[1] = 1;
 Data[2] = 0x92;
 Data[3] = (color << 4) & 0xf0;		
 Data[4] = (color << 4) & 0xf0;		
 Data[5] = 0;
 RTDWrite(Data);
 
 OSD_Line(row,col+5,12,((color_slider<<4) & 0xf0),2);
 Data[0] = 6;
 Data[1] = 0;
 Data[2] = 0x90;
 
 Data[6] = 0;
 
 for (row = 0; row < length; row++)
 {
 Data[3] = (unsigned char)((((usStart_Addr + col + row + 5) >> 8 ) & 0x0f ) | 0x50);
 Data[4] = (unsigned char)( (usStart_Addr + col + row + 5) & 0x00ff);
 
 if( row == 0 || row == (length-1) )
 {
 if( bound )
 {
 if( bound >= (range*3) )
 {
 Data[5] = (row==0) ? 0x13 : 0x1e;
 bound = bound - range*3;
 }
 else
 {
 color   = (bound << 4) / (range*3);
 bound = 0;
 
 if (4 > color)
 Data[5] = (row==0) ? 0x10 : 0x1b;	
 else if (8 > color)
 Data[5] = (row==0) ? 0x11 : 0x1c;
 else if (12 > color)
 Data[5] = (row==0) ? 0x12 : 0x1d;
 else
 Data[5] = (row==0) ? 0x13 : 0x1e;
 }
 }
 else
 {
 Data[5] = (row==0) ? 0x10 : 0x1b;	
 }
 }
 else
 {
 if( bound )
 {
 if( bound >= (range*6) )
 {
 Data[5] = 0x1a;
 bound = bound - range*6;
 }
 else
 {
 color   = (bound << 4) / (range*6);
 bound = 0;
 
 if (1 > color)
 Data[5] = 0x14;
 else if (4 > color)
 Data[5] = 0x15;
 else if (6 > color)
 Data[5] = 0x16;
 else if (9 > color)
 Data[5] = 0x17;
 else if (11 > color)
 Data[5] = 0x18;
 else if (14 > color)
 Data[5] = 0x19;
 else
 Data[5] = 0x1a;
 }
 }
 else
 {
 Data[5] = 0x14;
 }
 
 }
 
 RTDWrite(Data);
 
 }
 
 range	= value / 10;
 row		= value - (range * 10);	 
 color	= range / 10;			 
 range	= range - (color * 10);	 
 
 row		= row + 0x01;
 range	= (range || color) ? range + 0x01 : 0x00;
 color	= color ? color + 0x01 : 0x00;
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x90;
 Data[3] = (unsigned char)((((usStart_Addr + col) >>8 ) & 0x0f ) | 0x50);
 Data[4] = (unsigned char)( (usStart_Addr + col ) & 0x00ff);
 Data[5] = 0;
 RTDWrite(Data);
 
 Data[0] = 6;
 Data[1] = 1;
 Data[2] = 0x92;
 Data[3] = color;		 
 Data[4] = range;		 
 Data[5] = row;		 
 Data[6] = 0;
 RTDWrite(Data);
 
 }
 
 
 void Init_Page(unsigned char index)
 {
 index = index;
 OSD_Position(0x01);
 OSD_Clear(5, 11, 15, 1);	 
 if( ucOSD_Page_Index == 1)
 RTDOSDW(OSD_Window_Setting);
 }
 
 void Show_Osd_Page(unsigned char Page_Num,unsigned char* Page_Attr,unsigned char OSD_Table_Num)
 {
 Init_Page(Page_Num);
 RTDOSDW(Page_All_Atb);
 RTDOSDW(OSD_PAGE_All_TABLE[0][stGUD1.FUNCTION & 0x07]);
 RTDOSDW(Page_Attr);
 RTDOSDW(OSD_PAGE_TABLE[OSD_Table_Num][stGUD1.FUNCTION & 0x07]);
 Show_Mode();
 }
 
 void OSD_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width)
 {
 width = width;
 if (height)
 {
 do
 {
 OSD_Line(row_start, col_start, Row_Info[0][row_start+1], 0x00, 3);
 
 row_start++;
 }
 while (--height);
 }
 }
 
 void Bright_Contrast_Adjust(unsigned char* variable,unsigned char Key)
 {
 
 if (0x04 == Key)
 {
 if (100 <= *variable)
 return;
 
 if (15 > ucKey_Issued)
 *variable   = 100 > *variable ? *variable + 1 : 100;
 else
 *variable   = 99 > *variable ? *variable + 2 : 100;
 }
 else
 {
 if (0 == *variable)
 return;
 
 if (15 > ucKey_Issued)
 *variable   = 0 < *variable ? *variable - 1 : 0;
 else
 *variable   = 1 < *variable ? *variable - 2 : 0;
 }
 }
 
 void Osd_Change_Item(unsigned char Pess_Key,unsigned char Item_Num)
 {
 if (ucOSD_Item_Index0)
 {
 
 
 
 if (0x03 == Pess_Key)
 ucOSD_Item_Index0   = (Item_Num == ucOSD_Item_Index0) ? 1 : (ucOSD_Item_Index0 + 1);
 else
 ucOSD_Item_Index0   = (1 == ucOSD_Item_Index0) ? Item_Num : (ucOSD_Item_Index0 - 1);
 
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 1, 1, 14, 251, 0, 1, 25);
 }
 else
 {
 
 
 
 if (0x03 == Pess_Key)
 ucOSD_Page_Index    = GetNextPageIdx(ucOSD_Page_Index);
 else
 ucOSD_Page_Index    = GetPrevPageIdx(ucOSD_Page_Index);
 } 
 }
 
 void Show_Mode(void)
 {
 unsigned int idata usStart_Addr;
 unsigned char idata ucTemp;
 
 OSD_Line(3, 12, 15, 0, 1);                        
 usStart_Addr = 19;
 
 
 for(ucTemp = 1; ucTemp < 3+1; ucTemp ++)
 usStart_Addr += Row_Info[0][ucTemp];
 
 Data[0] = 5;
 Data[1] = 0;
 Data[2] = 0x90;
 Data[3] = (unsigned char)( (((usStart_Addr + 12)  & 0x0fff) >> 8 ) | 0x50);
 Data[4] = (unsigned char)( (usStart_Addr + 12) & 0x00ff);
 Data[5] = 0;
 RTDWrite(Data);
 
 
 
 switch (ucMode_Curr)
 {   

















































 
 default :
 
 
 {
 unsigned int    usHwid;
 unsigned char   ucTemp;
 
 usHwid  = usIPH_ACT_WID;
 
 if (0 == (stGUD1.INPUT_SOURCE & 0x07))
 {
 if (46 == ucMode_Curr)
 {
 usHwid  = 1600;
 }
 else 
 {
 if (46 > ucMode_Curr)
 {
 if (39 <= ucMode_Curr)
 usHwid  = 1280;
 else if (35 <= ucMode_Curr)
 usHwid  = 1152;
 }
 else
 {
 if (59 == ucMode_Curr)
 usHwid  = 1600;
 else if (57 <= ucMode_Curr)
 usHwid  = 1280;
 else if (55 <= ucMode_Curr)
 usHwid  = 1152;
 }
 }
 
 if	((8 == ucMode_Curr)||(9 == ucMode_Curr))
 {
 if(stGUD1.FUNCTION & 0x10)
 usHwid  = 640;
 else
 usHwid  = 720;
 }
 }
 
 
 
 Data[0] = 12;
 Data[1] = 1;
 Data[2] = 0x92;
 
 ucTemp  = usHwid / 100;
 
 if (10 <= ucTemp)
 {
 Data[3] = 0x02;
 Data[4] = ucTemp - 10 + 0x01;
 }
 else
 {
 Data[3] = 0;
 Data[4] = ucTemp + 0x01;
 }
 
 ucTemp  = usHwid - ((unsigned int)100 * ucTemp);
 
 Data[5] = ucTemp / 10;
 
 Data[6] = ucTemp - (10 * Data[5]) + 0x01;
 Data[5] = Data[5] + 0x01;
 Data[7] = 0x0e;
 
 ucTemp      = usIPV_ACT_LEN / 100;
 Data[12]    = usIPV_ACT_LEN - ((unsigned int)100 * ucTemp);
 
 if (10 <= ucTemp)
 {
 Data[0]     = 13;
 Data[8]     = 0x02;
 Data[9]     = ucTemp - 10 + 0x01;
 Data[10]    = Data[12] / 10;
 Data[11]    = Data[12] - (10 * Data[10]) + 0x01;
 Data[10]    = Data[10] + 0x01;
 Data[12]    = 0x00;
 Data[13]    = 0;
 }
 else
 {
 Data[8]     = ucTemp + 0x01;
 Data[9]     = Data[12] / 10;
 Data[10]    = Data[12] - (10 * Data[9]) + 0x01;
 Data[9]     = Data[9] + 0x01;
 Data[11]    = 0x00;
 Data[12]    = 0;
 }
 
 Data[12]    = 0;
 RTDWrite(Data);
 
 
 
 
 Data[0] = 7;
 Data[1] = 1;
 Data[2] = 0x92;
 Data[3] = ucRefresh / 10;
 Data[4] = ucRefresh - (Data[3] * 10) + 0x01;
 Data[3] = Data[3] + 0x01;
 Data[5] = 0x27;
 Data[6] = 0x59;
 Data[7] = 0;
 RTDWrite(Data);
 if (10 <= ucTemp)
 OSD_Line( 3, 21, 1, 0x8c, 0);
 else
 OSD_Line( 3, 20, 1, 0x8c, 0);
 }
 
 break;
 
 }
 }   
 
 
 
 
 void FACTORY_Key_Key(void)
 {
 ucOSD_Page_Index = 15;
 ucOSD_Item_Index0 = 1;
 }
 
 
 
 void Page0_Left_Right_Key(unsigned char Key)
 {
 
 
 
 
 
 if (!b_rgb_VOLUME_STATUS)
 {
 OSD_Position(0x01);
 RTDOSDW(rgb_OSD_VOLUME);
 RTDOSDW(strTabVOLUME_Atb[stGUD1.FUNCTION & 0x07]);		 
 RTDSetBit(0x6D, 0xfe, 0x01);
 b_rgb_VOLUME_STATUS = 1;
 }
 
 if(0x04 == Key)
 {
 if (stGUD3.VOLUME > 0x00) stGUD3.VOLUME--;
 SetVolume();
 Save_GUD3();
 rgb_OSD_Slider(0, 7, 24, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
 }
 
 else if(0x03 == Key)
 {
 if (stGUD3.VOLUME < 0x1f) stGUD3.VOLUME++;
 SetVolume();
 Save_GUD3();
 rgb_OSD_Slider(0, 7, 24, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
 }
 
 
 }
 
 void Page0_Enter_Key(void)
 {
 if((stGUD3.TV_SETTING & 0x08) == 0x08 ) 
 {
 
 ucOSD_Page_Index    = 15;
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 ucOSD_Item_Index2   = 0;
 }
 else
 {
 
 ucOSD_Page_Index    = 1;
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 ucOSD_Item_Index2   = 0;
 b_rgb_VOLUME_STATUS = 0;
 }
 }
 
 void Page0_LR_Key(void)
 {
 
 if (0 == (stGUD1.INPUT_SOURCE & 0x07))
 {
 ucOSD_Page_Index    = 8;
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 ucOSD_Item_Index2   = 0;
 }
 }
 
 void Page1_Enter_Key(void)
 {
 if (0 == ucOSD_Item_Index0)
 {
 if (0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 
 
 
 
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 }
 }
 else
 {
 if (ucOSD_Item_Index1)
 {
 
 switch (ucOSD_Item_Index0)
 {
 case 5 :
 if (ucOSD_Item_Index1 == 1 )  
 {
 if (0xfc == Auto_Balance())
 {
 ucMode_Curr = 254;
 return ;
 }
 }
 OSD_Line( 13, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x40, 2);
 break;
 
 case 1 :
 
 OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 4, 14);
 break;
 
 case 2 :
 
 OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 4, 14);
 break;
 
 case 7 :
 
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x40, 2);
 break;
 
 case 3 :
 
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x40, 2);
 break;
 }
 
 ucOSD_Item_Index1   = 0;
 
 }
 else
 {
 if (6 == ucOSD_Item_Index0)
 {
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 0, 0, 14, 251, 0, 1, 0);
 
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 }
 else if (0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 switch (ucOSD_Item_Index0)
 {
 case 5 :
 ucOSD_Item_Index1  = 2;
 OSD_Line( 13, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
 break;
 
 case 1 :
 ucOSD_Item_Index1   = 1;
 
 
 OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 2, 14);
 break;
 
 case 2 :
 ucOSD_Item_Index1   = 1;
 
 
 OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 2, 14);
 break;
 
 case 7 :
 ucOSD_Item_Index1 = ((stGUD1.INPUT_SOURCE & 0x18) >> 3) + 1;
 
 
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x20, 2);
 break;
 
 case 3 :
 ucOSD_Item_Index1   = ((stGUD1.FUNCTION >> 5) & 0x03) + 1;
 
 
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
 break;
 
 case 4 :
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 0, 0, 14, 251, 0, 1, 0);
 ucOSD_Item_Index1   = 1;
 ucOSD_Item_Index2   = 0;
 OSD_Proc_B(0x83);        
 break;
 }
 }
 }
 }
 }
 
 void Page1_Left_Right_Key(unsigned char Key)
 {
 if (ucOSD_Item_Index1)
 {
 switch (ucOSD_Item_Index0)
 {
 case 5 :
 
 ucOSD_Item_Index1   = (0x03 == Key) ? 1 : 2;
 OSD_Line( 13, 36, 14, 0x40, 2);	 
 OSD_Line( 13, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
 break;
 
 case 1 :
 Bright_Contrast_Adjust(&stGUD0.CONTRAST,Key);
 
 OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 2, 14);
 
 
 if((stGUD1.INPUT_SOURCE & 0x07) == 0)
 SetADC_Gain();
 else
 Set_Bright_Contrast();
 
#line 1101 "Code\Lcd_osd.c" /1
 
 
#line 1103 "Code\Lcd_osd.c" /0
 
 Save_GUD0();
 break;
 
 case 2 :
 Bright_Contrast_Adjust(&stGUD0.BRIGHT,Key);
 
 OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 2, 14);
 Set_Bright_Contrast();
 Save_GUD0();
 break;
 
 case 7:
 
 if(0x04 == Key)
 ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 4) ? 4 : ucOSD_Item_Index1 + 1;
 else
 ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 1) ? 1 : ucOSD_Item_Index1 - 1;
 
 stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xe7 ) | ((ucOSD_Item_Index1 - 1) << 3);
 
 
 OSD_Line( 11, 36, 20, 0x40, 2);	 
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x20, 2);
 
 Set_Bright_Contrast();
 Save_GUD1();
 break;
 
 case 3 :
 
 if (0x04 == Key)
 {
 if (4 <= ucOSD_Item_Index1)
 break;
 
 ucOSD_Item_Index1   = ucOSD_Item_Index1 + 1;
 }
 else
 {
 if (1 >= ucOSD_Item_Index1)
 break;
 
 ucOSD_Item_Index1   = ucOSD_Item_Index1 - 1;
 }
 
 stGUD1.FUNCTION = (stGUD1.FUNCTION & 0x9f) | ((ucOSD_Item_Index1 - 1) << 5);
 
 OSD_Line( 9, 36, 14, 0x40, 2);	 
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
 
 Set_Gamma();
 Save_GUD1();
 break;
 
 }
 }
 else
 {
 Osd_Change_Item(Key,6);
 
 }
 }
 
 void Page1_Show(void)
 {
 Show_Osd_Page(0,Page1_Atb,0);
 
 
 OSD_Window( 5, 10, 136, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 
 if (0 == ucMode_Curr || 255 == ucMode_Curr)
 {
 
 
 }
 
 OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 4, 14);
 OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 4, 14);
 
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 break;
 
 case 2 :
 break;
 
 case 3 :
 break;
 
 case 4 :
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 1, 1, 14, 251, 0, 1, 25);
 break;
 }
 }
 
 void Page1B_Enter_Key(void)
 {
 ucOSD_Page_Index = 7;
 if (4 == ucOSD_Item_Index1)
 {
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 0, 0, 14, 251, 0, 1, 0);
 ucOSD_Item_Index1   = 0;
 ucOSD_Item_Index2   = 0;
 }
 else
 {
 if (ucOSD_Item_Index2)
 {
 ucOSD_Item_Index2   = 0;	 
 switch (ucOSD_Item_Index1)
 {
 case 1 :
 OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 4, 2);
 break;
 
 case 2 :
 OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 4, 12);
 break;
 
 case 3 :
 OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 4, 3);
 break;
 }
 }
 else if (0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 ucOSD_Item_Index2   = 1;	 
 
 
 switch (ucOSD_Item_Index1)
 {
 case 1 :
 OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 2, 2);
 break;
 
 case 2 :
 OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 12, 12);
 break;
 
 case 3 :
 OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 3, 3);
 break;
 }
 }
 }
 ucOSD_Page_Index = 1;
 }
 
 void Page1B_Left_Right_Key(unsigned char Key)
 {
 ucOSD_Page_Index = 7;
 if (ucOSD_Item_Index2)
 {
 switch (ucOSD_Item_Index1)
 {
 case 1 :
 Bright_Contrast_Adjust(&stGUD0.RTD_R_CONTRAST,Key);
 
 OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 2, 2);
 break;
 
 case 2 :
 Bright_Contrast_Adjust(&stGUD0.RTD_G_CONTRAST,Key);
 
 OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 12, 12);
 break;
 
 case 3 :
 Bright_Contrast_Adjust(&stGUD0.RTD_B_CONTRAST,Key);
 
 OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 3, 3);
 break;
 }
 
 Set_Bright_Contrast();
 Save_GUD0();
 
 }
 else
 {
 
 if (0x03 == Key)
 ucOSD_Item_Index1   = (4 == ucOSD_Item_Index1) ? 1 : (ucOSD_Item_Index1 + 1);
 else
 ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? 4 : (ucOSD_Item_Index1 - 1);
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index1-1)*(29+4)), (84 + (ucOSD_Item_Index1-1)*(29+4))
 , 1, 1, 14, 251, 0, 1, 25);
 }
 ucOSD_Page_Index = 1;
 }
 
 void Page1B_Show(void)
 {
 Show_Osd_Page(0,Page7_Atb,6);
 
 
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 
 if (0 == ucMode_Curr || 255 == ucMode_Curr)      
 ucOSD_Item_Index2   = 0;
 
 if (0 == ucOSD_Item_Index2)
 {
 ucOSD_Page_Index = 7;
 OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 4, 2);
 OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 4, 12);
 OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 4, 3);
 ucOSD_Page_Index = 1;
 }
 else
 {
 






 
 }
 }
 
 void Page2_Enter_Key()
 {
 if (0 == ucOSD_Item_Index0)
 {
 if (0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 
 
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 }
 }
 else
 {
 if (ucOSD_Item_Index1)
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 4, 14);
 break;
 
 case 2 :
 OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 4, 14);
 break;
 
 case 4 :
 
#line 1361 "Code\Lcd_osd.c" /1
 
 
#line 1363 "Code\Lcd_osd.c" /0
 OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 4, 14);
 
 break;
 
 case 5 :
 
 
 OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 4, 14);
 
#line 1372 "Code\Lcd_osd.c" /1
 
 
#line 1374 "Code\Lcd_osd.c" /0
 break;
 
 case 3 :
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x40, 2);
 break;
 
 }
 
 ucOSD_Item_Index1   = 0;     
 
 }
 else
 {
 if (6 == ucOSD_Item_Index0)
 {
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 0, 0, 14, 251, 0, 1, 0);
 
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 }
 else if (0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 if (0 == (stGUD1.INPUT_SOURCE & 0x07) || 3 == ucOSD_Item_Index0)
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 ucOSD_Item_Index1   = 1;     
 OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 2, 14);
 break;
 
 case 2 :
 ucOSD_Item_Index1   = 1;     
 OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 2, 14);
 break;
 
 case 4 :
 ucOSD_Item_Index1   = 1;     
 
#line 1415 "Code\Lcd_osd.c" /1
 
 
#line 1417 "Code\Lcd_osd.c" /0
 OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 2, 14);
 
 break;
 
 case 5 :
 ucOSD_Item_Index1   = 1;     
 
 OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 2, 14);
 
#line 1426 "Code\Lcd_osd.c" /1
 
 
#line 1428 "Code\Lcd_osd.c" /0
 break;
 
 case 3 :
 ucOSD_Item_Index1   = stGUD1.FILTER + 1;
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
 break;
 
 }
 }
 }
 }
 }
 }
 
 void Page2_Left_Right_Key(unsigned char Key)
 {
 if (ucOSD_Item_Index1)
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 
 if (0x04 == Key)
 {
 if (ucH_Min_Margin >= stMUD.H_POSITION)
 break;
 
 if (15 > ucKey_Issued)
 stMUD.H_POSITION    = stMUD.H_POSITION > ucH_Min_Margin ? stMUD.H_POSITION - 1 : ucH_Min_Margin;
 else
 stMUD.H_POSITION    = stMUD.H_POSITION > (ucH_Min_Margin + 2) ? stMUD.H_POSITION - 3 : ucH_Min_Margin;
 }
 else
 {
 if (ucH_Max_Margin <= stMUD.H_POSITION)
 break;
 
 if (15 > ucKey_Issued)
 stMUD.H_POSITION    = stMUD.H_POSITION < ucH_Max_Margin ? stMUD.H_POSITION + 1 : ucH_Max_Margin;
 else
 stMUD.H_POSITION    = stMUD.H_POSITION < (ucH_Max_Margin - 2) ? stMUD.H_POSITION + 3 : ucH_Max_Margin;
 }
 
 OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 2, 14);
 Set_H_Position();
 Set_Phase(stMUD.PHASE);
 Save_MUD(ucMode_Curr);
 break;
 
 case 2 :
 
 if (0x04 == Key)
 {
 if ((unsigned int)256 - ucV_Min_Margin <= stMUD.V_POSITION)
 break;
 
 stMUD.V_POSITION    += 1;
 }
 else
 {
 if (ucV_Min_Margin >= stMUD.V_POSITION)
 break;
 
 stMUD.V_POSITION    -= 1;
 }
 
 OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 2, 14);
 Set_V_Position();
 Save_MUD(ucMode_Curr);
 break;
 
 case 4 :
 
#line 1501 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1519 "Code\Lcd_osd.c" /0
 stMUD.PHASE     &= 0x7c;
 
 if (0x04 == Key)
 {
 if (0x7c <= stMUD.PHASE)
 break;
 
 stMUD.PHASE += 4;
 }
 else
 {
 if (0x00 == stMUD.PHASE)
 break;
 
 stMUD.PHASE -= 4;
 }
 
 OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 2, 14);
 
 Set_Phase(stMUD.PHASE);
 Save_MUD(ucMode_Curr);
 break;
 
 case 5 :
 
 
 if (0x04 == Key)
 {
 if (178 <= stMUD.CLOCK)
 break;
 
 if (15 > ucKey_Issued)
 stMUD.CLOCK = (177 >= stMUD.CLOCK) ? stMUD.CLOCK + 1 : 178;
 else
 stMUD.CLOCK = (176 >= stMUD.CLOCK) ? stMUD.CLOCK + 2 : 178;
 
 Set_Clock();
 Set_H_Position();
 }
 else
 {
 if (78 >= stMUD.CLOCK)
 break;
 
 if (15 > ucKey_Issued)
 stMUD.CLOCK = (79 <= stMUD.CLOCK) ? stMUD.CLOCK - 1 : 78;
 else
 stMUD.CLOCK = (80 <= stMUD.CLOCK) ? stMUD.CLOCK - 2 : 78;
 
 Set_H_Position();
 Set_Clock();
 }
 
 OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 2, 14);
 
 
#line 1575 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 1605 "Code\Lcd_osd.c" /0
 Save_MUD(ucMode_Curr);
 break;
 
 case 3 :
 
 if (0x04 == Key)
 {
 if (5 <= ucOSD_Item_Index1)
 break;
 
 ucOSD_Item_Index1   = ucOSD_Item_Index1 + 1;
 }
 else
 {
 if (1 >= ucOSD_Item_Index1)
 break;
 
 ucOSD_Item_Index1   = ucOSD_Item_Index1 - 1;
 }
 
 OSD_Line( 9, 36, 14, 0x40, 2);	 
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
 
 stGUD1.FILTER    = ucOSD_Item_Index1 - 1;
 Sharpness();
 
 if((usIPH_ACT_WID == 1280) && (2 == 2) && (stGUD1.FILTER == 0x02))
 RTDSetBit(0x15, 0xff, 0x01);    
 else if((usIPH_ACT_WID == 1280) && (2 == 2) && (stGUD1.FILTER != 0x02))
 RTDSetBit(0x15, 0xfe, 0x00);    
 
 Save_GUD1();
 break;
 
 
 }
 }
 else
 {
 Osd_Change_Item(Key,6);
 }
 }
 
 
 void Page2_Show()
 {
 Show_Osd_Page(1,Page2_Atb,1);
 
 
 OSD_Window( 5, 10, 136, 87, 117, 1, 1, 14, 251, 0, 1, 25);
 
 if (0 == ucMode_Curr || 255 == ucMode_Curr)
 {
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 }
 
 if (0 != (stGUD1.INPUT_SOURCE & 0x07) && 3 != ucOSD_Item_Index0)
 {
 ucOSD_Item_Index1   = 0;
 }
 
 if (0 == ucOSD_Item_Index1)
 {
 OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 4, 14);
 OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 4, 14);
 
#line 1672 "Code\Lcd_osd.c" /1
 
 
#line 1674 "Code\Lcd_osd.c" /0
 OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 4, 14);
 
 
 
 OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 4, 14);
 
#line 1680 "Code\Lcd_osd.c" /1
 
 
#line 1682 "Code\Lcd_osd.c" /0
 }
 else
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 break;
 
 case 2 :
 break;
 
 case 4 :
 break;
 
 case 5 :
 break;
 
 case 3 :
 break;
 }
 }
 }
 















































































































 
 






































 
 
 void Page4_Enter_Key(void)
 {
 if (0 == ucOSD_Item_Index0)
 {
 
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 }
 else
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 ucOSD_Item_Index1 = (stGUD1.FUNCTION & 0x07) + 1;
 OSD_Proc_B(0x83);		 
 break;
 
 case 2 :
 if (ucOSD_Item_Index1)
 {
 ucOSD_Item_Index1 = 0;		 
 Get_OSD_Margin();
 OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 4, 14);
 }
 else
 {
 ucOSD_Item_Index1 = 1;     
 Get_OSD_Margin();
 OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 2, 14);
 }
 break;
 
 case 3 :
 if (ucOSD_Item_Index1)
 {
 ucOSD_Item_Index1   = 0;     
 Get_OSD_Margin();
 OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 4, 14);
 }
 else
 {
 ucOSD_Item_Index1   = 1;     
 Get_OSD_Margin();
 OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 2, 14);
 }
 break;
 
 case 4 :
 if(ucOSD_Item_Index2)
 {
 ucOSD_Item_Index2   = 0;
 ucOSD_Item_Index1   = 0;     
 
 
 OSD_Line( 11, 31, 3, 0x40, 2);
 OSD_Line( 11, 31, 3, 0x00, 1);
 
 OSD_Line( 11, 36, 12, 0x8a, 0);
 OSD_Line( 11, 36, 12, 0x00, 1);
 switch( stGUD1.FUNCTION & 0x07 )
 {
 case 5:
 OSD_Line( 11, 37, 1, 0x8c, 0);
 OSD_Line( 11, 37, 1, 0xb3, 1);
 OSD_Line( 11, 43, 1, 0x8c, 0);
 OSD_Line( 11, 43, 1, 0xc9, 1);
 break;
 
 case 6:
 OSD_Line( 11, 37, 1, 0x8c, 0);
 OSD_Line( 11, 37, 1, 0xdb, 1);
 OSD_Line( 11, 43, 1, 0x8c, 0);
 OSD_Line( 11, 43, 1, 0xe5, 1);
 break;
 
 case 7:
 OSD_Line( 11, 37, 1, 0x8c, 0);
 OSD_Line( 11, 37, 1, 0x9b, 1);
 OSD_Line( 11, 43, 1, 0x8c, 0);
 OSD_Line( 11, 43, 1, 0x9c, 1);
 break;
 
 default:
 OSD_Line( 11, 37, 1, 0x2e, 1);
 OSD_Line( 11, 38, 1, 0x2d, 1);
 OSD_Line( 11, 43, 1, 0x2e, 1);
 OSD_Line( 11, 44, 2, 0x25, 1);
 break;
 
 }
 OSD_Line( 11, 36, 12, 0x40, 2);
 
 OSD_Line( 11, 35, 1, 0x00, 1);
 OSD_Line( 11, 48, 1, 0x00, 1);
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 1, 1, 14, 251, 0, 1, 25);
 
 }
 else if (ucOSD_Item_Index1)
 {
 if(ucOSD_Item_Index1 == 2)
 {
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x40, 2);
 ucOSD_Item_Index1 = 0;
 }
 else
 {
 ucOSD_Item_Index2    = 1;
 if(stGUD1.OSD_TIMEOUT < 5)
 {
 stGUD1.OSD_TIMEOUT = 20;  
 usOSD_Timer         = 1020;  
 Save_GUD1();
 }
 
 OSD_Line( 11, 36, 12, 0xe0, 2);
 OSD_Line( 11, 36, 12, 0x8c, 0);
 OSD_Line( 11, 35, 1, 0x40, 2);
 OSD_Line( 11, 35, 1, 0x0d, 1);
 OSD_Line( 11, 48, 1, 0x40, 2);
 OSD_Line( 11, 48, 1, 0x0c, 1);
 OSD_Slider(11, 31, 17, stGUD1.OSD_TIMEOUT, 60, 2, 14);
 }
 }
 else
 {
 ucOSD_Item_Index1   = stGUD1.OSD_TIMEOUT ? 1 : 2;
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x20, 2);
 }
 break;
 
 case 5 :
 if (ucOSD_Item_Index1)
 {
 ucOSD_Item_Index1   = 0;     
 OSD_Slider(13, 31, 17, (stGUD1.INPUT_SOURCE & 0xe0) >> 5, 7, 4, 14);
 }
 else
 {
 ucOSD_Item_Index1   = 1;
 OSD_Slider(13, 31, 17, (stGUD1.INPUT_SOURCE & 0xe0) >> 5, 7, 2, 14);
 }
 break;
 
 case 6 :
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 0, 0, 14, 251, 0, 1, 0);
 
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 
 break;
 
 }
 }
 }
 
 void Page4_Left_Right_Key(unsigned char Key)
 {
 if (ucOSD_Item_Index1)
 {
 switch (ucOSD_Item_Index0)
 {
 case 2 :
 Get_OSD_Margin();
 
 if (0x04 == Key)
 {
 if (Data[1] <= stGUD1.OSD_POSH)
 break;
 
 if (15 > ucKey_Issued)
 stGUD1.OSD_POSH   = Data[1] > stGUD1.OSD_POSH ? stGUD1.OSD_POSH + 1 : Data[1];
 else
 stGUD1.OSD_POSH   = (Data[1] - 1) > stGUD1.OSD_POSH ? stGUD1.OSD_POSH + 2 : Data[1];
 }
 else
 {
 if (Data[0] >= stGUD1.OSD_POSH)
 break;
 
 if (15 > ucKey_Issued)
 stGUD1.OSD_POSH   = Data[0] < stGUD1.OSD_POSH ? stGUD1.OSD_POSH - 1 : Data[0];
 else
 stGUD1.OSD_POSH   = (Data[0] + 1) < stGUD1.OSD_POSH ? stGUD1.OSD_POSH - 2 : Data[0];
 }
 
 OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 2, 14);
 OSD_Position(0x01);
 Save_GUD1();
 break;
 
 case 3 :
 Get_OSD_Margin();
 
 if (0x04 == Key)
 {
 
 if (Data[3] <= stGUD1.OSD_POSV)
 break;
 
 if (15 > ucKey_Issued)
 stGUD1.OSD_POSV   = Data[3] > stGUD1.OSD_POSV ? stGUD1.OSD_POSV + 1 : Data[3];
 else
 stGUD1.OSD_POSV   = (Data[3] - 1) > stGUD1.OSD_POSV ? stGUD1.OSD_POSV + 2 : Data[3];
 
 }
 else
 {
 
 if (Data[2] >= stGUD1.OSD_POSV)
 break;
 
 if (15 > ucKey_Issued)
 stGUD1.OSD_POSV   = Data[2] < stGUD1.OSD_POSV ? stGUD1.OSD_POSV - 1 : Data[2];
 else
 stGUD1.OSD_POSV   = (Data[2] + 1) < stGUD1.OSD_POSV ? stGUD1.OSD_POSV - 2 : Data[2];
 
 }
 
 OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 2, 14);
 OSD_Position(0x01);
 Save_GUD1();
 break;
 
 case 4 :
 
 if (0x04 == Key)
 {
 if(ucOSD_Item_Index2)
 {
 stGUD1.OSD_TIMEOUT = (stGUD1.OSD_TIMEOUT == 60) ? 60 : stGUD1.OSD_TIMEOUT + 1;
 OSD_Slider(11, 31, 17, stGUD1.OSD_TIMEOUT, 60, 2, 14);
 }
 else if(ucOSD_Item_Index1)
 {
 
 ucOSD_Item_Index1  = 2;
 stGUD1.OSD_TIMEOUT  = 0;
 OSD_Line( 11, 36, 14, 0x40, 2);
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x20, 2);
 }
 }
 else
 {
 if(ucOSD_Item_Index2)
 {
 stGUD1.OSD_TIMEOUT = (stGUD1.OSD_TIMEOUT == 5) ? 5 : stGUD1.OSD_TIMEOUT - 1;
 OSD_Slider(11, 31, 17, stGUD1.OSD_TIMEOUT, 60, 2, 14);
 }
 else if(ucOSD_Item_Index1)
 {
 
 ucOSD_Item_Index1   = 1;
 OSD_Line( 11, 36, 14, 0x40, 2);
 OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x20, 2);
 }
 }
 
 usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 51;      
 
 Save_GUD1();
 break;
 
 case 5 :
 Data[0] = (stGUD1.INPUT_SOURCE & 0xe0) >> 5;
 
 if (0x04 == Key)
 {
 if(ucOSD_Item_Index1)
 {
 Data[0] = (Data[0] == 0x07) ? 0x07 : Data[0] + 1;
 stGUD1.INPUT_SOURCE = stGUD1.INPUT_SOURCE & 0x1f | (Data[0] << 5);
 }
 }
 else
 {
 if(ucOSD_Item_Index1)
 {
 Data[0] = (Data[0] == 0x00) ? 0x00 : Data[0] - 1;
 stGUD1.INPUT_SOURCE = stGUD1.INPUT_SOURCE & 0x1f | (Data[0] << 5);
 }
 }
 
 RTDSetBit(0x6D, 0xc7, Data[0] << 3);
 OSD_Slider(13, 31, 17, Data[0] , 7, 2, 14);
 Save_GUD1();
 break;
 
 }
 }
 else
 {
 Osd_Change_Item(Key,6);
 }
 }
 
 
 void Page4_Show(void)
 {
 Show_Osd_Page(2,Page4_Atb,3);
 
 
 
 
 OSD_Window( 5, 10, 136, 120, 150, 1, 1, 14, 251, 0, 1, 25);
 
 if (0 == ucOSD_Item_Index1)
 {
 Get_OSD_Margin();
 OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 4, 14);
 Get_OSD_Margin();
 OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 4, 14);
 
 OSD_Slider(13, 31, 17, (stGUD1.INPUT_SOURCE & 0xe0) >> 5, 7, 4, 14);
 if( ucOSD_Item_Index0 == 1)
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 RTDSetBit(0x6D, 0xfe, 0x01);
 }
 else
 {
 switch (ucOSD_Item_Index0)
 {
 case 2 :
 
 
 break;
 
 case 3 :
 
 
 break;
 
 case 4 :
 
 
 break;
 
 case 5 :
 
 
 break;
 
 }
 }
 }
 
 void Page4B_Enter_Key(void)
 {
 if ((stGUD1.FUNCTION & 0x07) != (ucOSD_Item_Index1 - 1))
 {
 stGUD1.FUNCTION = (stGUD1.FUNCTION & 0xf8) | ((ucOSD_Item_Index1 - 1) & 0x07);
 Save_GUD1();
 
 switch (stGUD1.FUNCTION & 0x07)
 {
 case 5 :
 case 6 :
 
 RTDSetBit(0x6D, 0xfe, 0x00);
 Load_VLC_Font(Font_East_C, 0x5a9, 0x45);
 Page4_Show();
 
 
 break;
 
 case 7 :
 
 RTDSetBit(0x6D, 0xfe, 0x00);
 Load_VLC_Font(Font_East_J, 0x573, 0x4B);
 Page4_Show();
 
 
 break;
 
 default :
 break;
 
 }
 }
 
 ucOSD_Item_Index1   = 0;     
 }
 
 void Page4B_Left_Right_Key(unsigned char Key)
 {
 
 OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
 54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 0, 0, 14, 251, 0, 1, 0);
 if (0x03 == Key)
 ucOSD_Item_Index1   = (8 == ucOSD_Item_Index1) ? 1 : (ucOSD_Item_Index1 + 1);
 else
 ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? 8 : (ucOSD_Item_Index1 - 1);
 
 OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
 54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
 }
 
 void Page4B_Show(void)
 {
 Show_Osd_Page(3,Page8_Atb,7);
 RTDOSDW(Page8_Content);
 
 OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
 54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
 }
 
 void Page5_Enter_Key(void)
 {
 if (0 == ucOSD_Item_Index0)
 {
 
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 0);
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 }
 else
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 Data[0]             = stGUD1.INPUT_SOURCE & 0x07;
 ucOSD_Item_Index1   = (1 == Data[0])   ? 2 
 : (2 == Data[0])    ? 3 
 : (3 == Data[0])    ? 4 
 : (4 == Data[0])   ? 5 
 : (5 == Data[0])    ? 6 : 1;
 
 OSD_Proc_B(0x83);    
 break;
 
 case 2 :
 if (ucOSD_Item_Index1)
 {
 OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(7+1), 7, 0x40, 2);
 
 
 Data[0]   = (1 == ucOSD_Item_Index1) ? 0x00 : 0x10;
 
 stGUD1.FUNCTION = stGUD1.FUNCTION & 0xef | Data[0];
 ucOSD_Item_Index1   = 0;
 Save_GUD1();
 
 if (0 == (stGUD1.INPUT_SOURCE & 0x07) && 400 == usIPV_ACT_LEN &&
  5 != ucMode_Curr && 51 != ucMode_Curr)
 {
 










 
 if (stGUD1.FUNCTION & 0x10)		 
 {
 stGUD1.FUNCTION = (stGUD1.FUNCTION & 0xef);
 ucMode_Curr = 254;
 }
 else	
 {
 stGUD1.FUNCTION = (stGUD1.FUNCTION | 0x10);
 ucMode_Curr = 254;
 }
 }
 }
 else
 {
 ucOSD_Item_Index1   = (stGUD1.FUNCTION & 0x10) ? 2 : 1;      
 OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(7+1), 7, 0x20, 2);
 }
 break;
 
 case 3 :
 if (ucOSD_Item_Index1)
 {
 if (1 == ucOSD_Item_Index1)
 {
 {
 unsigned char   ucTemp1, ucTemp2;
 
 
 ucTemp1 = stGUD1.FUNCTION & 0x07;        
 ucTemp2 = stGUD1.INPUT_SOURCE & 0x07;    
 
 if (7 < ucTemp1)
 ucTemp1 = 0;
 
 
 usOSD_Timer = (unsigned int)2 << 9;      
 
 
 Init_GUD();
 
 usOSD_Timer = (unsigned int)stGUD1.OSD_TIMEOUT << 9;
 
 
 stGUD1.FUNCTION     = (stGUD1.FUNCTION & 0xf8) | ucTemp1;
 stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | ucTemp2;
 Save_GUD1();
 
 
 Set_Bright_Contrast();
 
 
 SetVolume();
 
 
 OSD_Position(0x01);
 }
 
 
 Init_MUD();
 
 
 Load_MUD(ucMode_Curr);
 
 
 ucMode_Curr = 254;
 }
 
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x40, 2);
 ucOSD_Item_Index1   = 0;     
 }
 else
 {
 ucOSD_Item_Index1   = 2;     
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
 }
 break;
 
 case 4 :
 if (ucOSD_Item_Index1)
 {
 ucOSD_Item_Index1   = 0;     
 OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
 }
 else
 {
 ucOSD_Item_Index1   = 1;     
 
 stGUD3.VOLUME   &= 0x1f;
 OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 2, 14);
 }
 break;
 
 case 5 :
 
 OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
 , 0, 0, 14, 251, 0, 1, 0);
 
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 
 break;
 
 }
 }
 }
 
 void Page5_Left_Right_Key(unsigned char Key)
 {
 if (ucOSD_Item_Index1)
 {
 switch (ucOSD_Item_Index0)
 {
 case 2 :
 ucOSD_Item_Index1   = (0x04 == Key) ? 2 : 1;       
 OSD_Line( 7, 36 , 16, 0x40, 2);
 OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(7+1), 7, 0x20, 2);
 
 break;
 
 case 3 :
 
 ucOSD_Item_Index1   = (0x03 == Key) ? 1 : 2;
 OSD_Line( 9, 36 , 14, 0x40, 2);
 OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
 
 break;
 
 case 4 :
 
 if (0x04 == Key)
 {
 if (0x00 == stGUD3.VOLUME)
 break;
 
 stGUD3.VOLUME   = stGUD3.VOLUME - 1;
 }
 else
 {
 if (0x1f <= stGUD3.VOLUME)
 break;
 
 stGUD3.VOLUME   = stGUD3.VOLUME + 1;
 }
 
 OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 2, 14);
 SetVolume();
 Save_GUD3();
 break;
 
 default :
 break;
 
 }
 }
 else
 {
 Osd_Change_Item(Key,5);
 }
 }
 
 void Page5_Show(void)
 {
 Show_Osd_Page(3,Page5_Atb,4);
 
 
 
 OSD_Window( 5, 10, 136, 153, 183, 1, 1, 14, 251, 0, 1, 25);
 
 
 
 OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
 
 
 if (0 == ucOSD_Item_Index1)
 {
 if( ucOSD_Item_Index0 == 1)
 OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
 }
 else
 {
 switch (ucOSD_Item_Index0)
 {
 case 2 :
 
 
 break;
 
 case 3 :
 
 
 break;
 
 case 4 :
 
 
 break;
 
 default :
 break;
 
 }
 }
 }
 
 void Page5B_Enter_Key()
 {
 Data[0] = (2 == ucOSD_Item_Index1) ?  1 
 : (3 == ucOSD_Item_Index1) ? 2
 : (4 == ucOSD_Item_Index1) ?   3 
 : (5 == ucOSD_Item_Index1) ?  4 
 : (6 == ucOSD_Item_Index1) ?   5 : 0;
 
 if(Data[0] != ucInputSrc)
 {
 Change_Source(Data[0]);
 ucOSD_Page_Index = 0;
 }
 else
 {
 ucOSD_Item_Index1 = 0;             
 }
 
 }
 
 void Page5B_Left_Right_Key(unsigned char Key)
 {
 
 OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
 54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 0, 0, 14, 251, 0, 1, 0);
 if (0x03 == Key)
 ucOSD_Item_Index1   = (2 == ucOSD_Item_Index1) ? 1 : (ucOSD_Item_Index1 + 1);
 else
 ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? 2 : (ucOSD_Item_Index1 - 1);
 
 OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
 54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
 }
 
 void Page5B_Show()
 {
 Show_Osd_Page(4,Page9_Atb,8);
 RTDOSDW(Page9_Content);
 
 OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
 54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
 
 
 
 
 
 }
 
 void Page6_Left_Right_Key(unsigned char Key)
 {
 if(Key == 0x03)
 ucOSD_Page_Index    = GetNextPageIdx(ucOSD_Page_Index);
 else
 ucOSD_Page_Index    = GetPrevPageIdx(ucOSD_Page_Index);
 }
 
 void Page6_Show(void)
 {
 
 
 
 Show_Osd_Page(4,Page6_Atb,5);
 
 
 
 OSD_Window( 5, 10, 136, 186, 216, 1, 1, 14, 251, 0, 1, 25);
 }
 
 
 
 
 void PageFactory_Show(void)
 {
 OSD_Fact_Clear( 0,20, 0,30);
 OSD_Position(0x01);
 OSD_Position(0x01);
 
 RTDSetBit(0x6D, 0xfe, 0x00);
 RTDOSDW(OSD_Reset);
 RTDOSDW(OSD_Clean_All);
 RTDOSDW(FactoryPageAtbFont);
 OSD_Fact_Line( 3, 0, 15, 0x20, 2);
 RTDOSDW(Version_Panel);
 ShowValue( 5,12, stGUD0.CONTRAST, 0x13 );		 
 ShowValue( 6,12, stGUD0.BRIGHT, 0x13 );		 
 ShowValue( 7,12, stGUD3.SPREAD, 0x13 );		 
 ShowValue( 8,  9, stGUD4.C2_R, 0x13 );			 
 ShowValue( 8,15, stGUD4.C2_G, 0x13 );			 
 ShowValue( 8,21, stGUD4.C2_B, 0x13 );			 
 }
 
 void PageFactory_Enter_Key(void)
 {
 if (ucOSD_Item_Index1)
 {
 if (ucOSD_Item_Index2)
 {
 switch(ucOSD_Item_Index1)
 {
 case 1:
 OSD_Fact_Line( 8,  9, 3, 0x13, 2);
 ucOSD_Item_Index2   = 0;
 break;
 case 2:
 OSD_Fact_Line( 8,15, 3, 0x13, 2);
 ucOSD_Item_Index2   = 0;
 break;
 case 3:
 OSD_Fact_Line( 8,21, 3, 0x13, 2);
 ucOSD_Item_Index2   = 0;
 break;
 }
 }
 else		 
 {
 switch (ucOSD_Item_Index0)
 {
 case 3:
 ShowValue(5,12, stGUD0.CONTRAST, 0x13 );
 ucOSD_Item_Index1   = 0;
 break;
 
 case 4:
 ShowValue(6,12, stGUD0.BRIGHT, 0x13 );
 ucOSD_Item_Index1   = 0;
 break;
 
 case 5:
 ShowValue(7,12, stGUD3.SPREAD, 0x13 );
 ucOSD_Item_Index1   = 0;
 break;
 
 case 6:
 
 switch(ucOSD_Item_Index1)
 {
 case 1:
 OSD_Fact_Line( 8,  9, 3, 0x23, 2);
 ucOSD_Item_Index2   = 1;
 break;
 case 2:
 OSD_Fact_Line( 8,15, 3, 0x23, 2);
 ucOSD_Item_Index2   = 1;
 break;
 case 3:
 OSD_Fact_Line( 8,21, 3, 0x23, 2);
 ucOSD_Item_Index2   = 1;
 break;
 case 4:
 OSD_Fact_Line( 8,25, 4, 0x13, 2);
 ucOSD_Item_Index1   = 0;
 break;
 }
 break;
 }
 }
 }
 else		 
 {
 switch (ucOSD_Item_Index0)
 {
 case 1:
 Init_FACTORY();
 ShowValue( 5,12, stGUD0.CONTRAST, 0x13 );		 
 ShowValue( 6,12, stGUD0.BRIGHT, 0x13 );		 
 ShowValue( 8,  9, stGUD4.C2_R, 0x13 );			 
 ShowValue( 8,15, stGUD4.C2_G, 0x13 );			 
 ShowValue( 8,21, stGUD4.C2_B, 0x13 );			 
 
 stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xE7 ) | 0x08;   
 Set_Bright_Contrast();
 RTDOSDW(RecallOK);
 break;
 
 case 2:
 Auto_Balance();
 RTDOSDW(AutoOK);
 break;
 
 case 3:
 ShowValue(5,12, stGUD0.CONTRAST, 0x23 );
 ucOSD_Item_Index1   = 1;
 break;
 
 case 4:
 ShowValue(6,12, stGUD0.BRIGHT, 0x23 );
 ucOSD_Item_Index1   = 1;
 break;
 
 case 5:
 ShowValue(7,12, stGUD3.SPREAD, 0x23 );
 ucOSD_Item_Index1   = 1;
 break;
 
 case 6:
 OSD_Fact_Line( 8, 7, 1, 0x23, 2);
 ucOSD_Item_Index1   = 1;
 break;
 
 case 7:
 ucOSD_Page_Index	 = 0;
 ucOSD_Item_Index0   = 0;
 ucOSD_Item_Index1   = 0;
 ucOSD_Item_Index2   = 0;
 
 RTDSetBit(0x6D, 0xfe, 0x00);
 RTDOSDW(OSD_Reset);
 break;
 }
 }
 }
 
 void PageFactory_Left_Right_Key(unsigned char Key)
 {
 if (ucOSD_Item_Index1)
 {
 if (ucOSD_Item_Index2)
 {
 switch (ucOSD_Item_Index0)
 {
 
 case 6:
 
 switch(ucOSD_Item_Index1)
 {
 case 1:
 Value_Adjust(&stGUD4.C2_R,Key,255,0);
 ShowValue( 8,  9, stGUD4.C2_R, 0x23 );
 break;
 case 2:
 Value_Adjust(&stGUD4.C2_G,Key,255,0);
 ShowValue( 8,15, stGUD4.C2_G, 0x23 );
 break;
 case 3:
 Value_Adjust(&stGUD4.C2_B,Key,255,0);
 ShowValue( 8,21, stGUD4.C2_B, 0x23 );
 break;
 }
 Set_Bright_Contrast();
 Save_GUD4();
 break;
 
 }
 }
 else		 
 {
 switch (ucOSD_Item_Index0)
 {
 if(0x03 == Key)
 ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 1) ? 7 : ucOSD_Item_Index0 - 1;
 else
 ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 7) ? 1 : ucOSD_Item_Index0 + 1;
 
 
 case 3:
 Bright_Contrast_Adjust(&stGUD0.CONTRAST,Key);
 ShowValue(5,12, stGUD0.CONTRAST, 0x23 );
 
 
 if((stGUD1.INPUT_SOURCE & 0x07) == 0)
 SetADC_Gain();
 else
 Set_Bright_Contrast();
 
#line 2789 "Code\Lcd_osd.c" /1
 
 
#line 2791 "Code\Lcd_osd.c" /0
 
 Save_GUD0();
 break;
 
 
 case 4:
 Bright_Contrast_Adjust(&stGUD0.BRIGHT,Key);
 ShowValue(6,12, stGUD0.BRIGHT, 0x23 );
 Set_Bright_Contrast();
 Save_GUD0();
 break;
 
 case 5:
 SPREAD_Adjust(&stGUD3.SPREAD,Key);
 ShowValue(7,12, stGUD3.SPREAD, 0x23 );
 Set_Spread();
 Save_GUD3();
 break;
 
 
 case 6:
 
 if(0x03 == Key)
 ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 4) ? 1 : ucOSD_Item_Index1 + 1;
 else
 ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 1) ? 4 : ucOSD_Item_Index1 - 1;
 
 switch(ucOSD_Item_Index1)
 {
 case 1:
 OSD_Fact_Line( 8,  7, 1, 0x23, 2);
 OSD_Fact_Line( 8,13, 1, 0x13, 2);
 OSD_Fact_Line( 8,25, 4, 0x13, 2);
 break;
 case 2:
 OSD_Fact_Line( 8,  7, 1, 0x13, 2);
 OSD_Fact_Line( 8,13, 1, 0x23, 2);
 OSD_Fact_Line( 8,19, 1, 0x13, 2);
 break;
 case 3:
 OSD_Fact_Line( 8,13, 1, 0x13, 2);
 OSD_Fact_Line( 8,19, 1, 0x23, 2);
 OSD_Fact_Line( 8,25, 4, 0x13, 2);
 break;
 case 4:
 OSD_Fact_Line( 8,  7, 1, 0x13, 2);
 OSD_Fact_Line( 8,19, 1, 0x13, 2);
 OSD_Fact_Line( 8,25, 4, 0x23, 2);
 break;
 }
 break;
 }
 }
 }
 else	 
 {
 
 if(0x03 == Key)
 ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 7) ? 1 : ucOSD_Item_Index0 + 1;
 else
 ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 1) ? 7 : ucOSD_Item_Index0 - 1;
 
 switch (ucOSD_Item_Index0)
 {
 case 1:
 OSD_Fact_Line( 9, 1,  7, 0x10, 2);
 OSD_Fact_Line( 3, 1, 14, 0x20, 2);
 OSD_Fact_Line( 4, 1, 10, 0x10, 2);
 break;
 
 case 2:
 OSD_Fact_Line( 3, 1, 14, 0x10, 2);
 OSD_Fact_Line( 4, 1, 10, 0x20, 2);
 OSD_Fact_Line( 5, 1, 10, 0x10, 2);
 break;
 
 case 3:
 OSD_Fact_Line( 4, 1, 10, 0x10, 2);
 OSD_Fact_Line( 5, 1, 10, 0x20, 2);
 OSD_Fact_Line( 6, 1, 10, 0x10, 2);
 break;
 
 case 4:
 OSD_Fact_Line( 5, 1, 10, 0x10, 2);
 OSD_Fact_Line( 6, 1, 10, 0x20, 2);
 OSD_Fact_Line( 7, 1, 10, 0x10, 2);
 break;
 
 case 5:
 OSD_Fact_Line( 6, 1, 10, 0x10, 2);
 OSD_Fact_Line( 7, 1, 10, 0x20, 2);
 OSD_Fact_Line( 8, 1,   5, 0x10, 2);
 break;
 
 case 6:
 OSD_Fact_Line( 7, 1,10, 0x10, 2);
 OSD_Fact_Line( 8, 1,  5, 0x20, 2);
 OSD_Fact_Line( 9, 1,  7, 0x10, 2);
 Set_Bright_Contrast();
 break;
 
 case 7:
 OSD_Fact_Line( 8, 1,  5, 0x10, 2);
 OSD_Fact_Line( 9, 1,  7, 0x20, 2);
 OSD_Fact_Line( 3, 1,14, 0x10, 2);
 break;
 }
 }
 }
 
 
 
 
 
 void PageADC_Left_Right_Key(unsigned char Key)
 {
 if (ucOSD_Item_Index1)
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 if (0x03 == Key)
 {
 if (0xff == stGUD2.AD_R_GAIN)
 return;
 
 stGUD2.AD_R_GAIN    += 1;
 }
 else
 {
 if (0x00 == stGUD2.AD_R_GAIN)
 return;
 
 stGUD2.AD_R_GAIN    -= 1;
 }
 
 OSD_Slider(5, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
 SetADC_Gain();
 break;
 
 case 2 :
 if (0x03 == Key)
 {
 if (0xff == stGUD2.AD_G_GAIN)
 return;
 
 stGUD2.AD_G_GAIN    += 1;
 }
 else
 {
 if (0x00 == stGUD2.AD_G_GAIN)
 return;
 
 stGUD2.AD_G_GAIN    -= 1;
 }
 
 OSD_Slider(7, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
 SetADC_Gain();
 break;
 
 case 3 :
 if (0x03 == Key)
 {
 if (0xff == stGUD2.AD_B_GAIN)
 return;
 
 stGUD2.AD_B_GAIN    += 1;
 }
 else
 {
 if (0x00 == stGUD2.AD_B_GAIN)
 return;
 
 stGUD2.AD_B_GAIN    -= 1;
 }
 
 OSD_Slider(9, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
 SetADC_Gain();
 break;
 
 case 4 :
 if (0x03 == Key)
 {
 if (0xff == stGUD2.AD_R_OFFSET)
 return;
 
 stGUD2.AD_R_OFFSET  += 1;
 }
 else
 {
 if (0x00 == stGUD2.AD_R_OFFSET)
 return;
 
 stGUD2.AD_R_OFFSET  -= 1;
 }
 
 OSD_Slider(11, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
 SetADC_Offset();
 break;
 
 case 5 :
 if (0x03 == Key)
 {
 if (0xff == stGUD2.AD_G_OFFSET)
 return;
 
 stGUD2.AD_G_OFFSET  += 1;
 }
 else
 {
 if (0x00 == stGUD2.AD_G_OFFSET)
 return;
 
 stGUD2.AD_G_OFFSET  -= 1;
 }
 
 OSD_Slider(13, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
 SetADC_Offset();
 break;
 
 case 6 :
 if (0x03 == Key)
 {
 if (0xff == stGUD2.AD_B_OFFSET)
 return;
 
 stGUD2.AD_B_OFFSET  += 1;
 }
 else
 {
 if (0x00 == stGUD2.AD_B_OFFSET)
 return;
 
 stGUD2.AD_B_OFFSET  -= 1;
 }
 
 OSD_Slider(15, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 SetADC_Offset();
 break;
 
 }
 
 Save_GUD2();
 }
 else
 {
 if (ucOSD_Item_Index0)
 {
 
 if (0x03 == Key)
 ucOSD_Item_Index0   = (7 == ucOSD_Item_Index0) ? 1 : (ucOSD_Item_Index0 + 1);
 else
 ucOSD_Item_Index0   = (1 == ucOSD_Item_Index0) ? 7 : (ucOSD_Item_Index0 - 1);
 
 OSD_Window( 6, 0, 476, 0, 252, 4, 4, 0, 1, 231, 1, 113);
 }
 }
 }
 
 void PageADC_Enter_Key(void)
 {
 if (0 == ucOSD_Item_Index0)
 {
 
 ucOSD_Item_Index0   = 1;
 ucOSD_Item_Index1   = 0;
 OSD_Window( 6, 152, 282, 56, 86, 2, 2, 14, 251, 0, 1, 25);
 }
 else
 {
 if (7 == ucOSD_Item_Index0)
 {                
 ucOSD_Page_Index    = 0;         
 }
 else
 {
 if (ucOSD_Item_Index1)
 {
 ucOSD_Item_Index1   = 0;     
 RTDOSDW(OSD_Version);
 }
 else
 {
 ucOSD_Item_Index1   = 1;     
 
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 OSD_Slider(5, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 break;
 
 case 2 :
 OSD_Slider(7, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 break;
 
 case 3 :
 OSD_Slider(9, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 break;
 
 case 4 :
 OSD_Slider(11, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 break;
 
 case 5 :
 OSD_Slider(13, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 break;
 
 case 6 :
 OSD_Slider(15, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
 break;
 
 }
 }
 }
 }
 }
 
 void PageADC_Show(void)
 {
 Init_Page(0);
 
 RTDOSDW(PageADC_Atb);
 RTDOSDW(PageADC_ENG);
 
 
 
 
 if (0 == ucOSD_Item_Index1)
 {
 RTDOSDW(OSD_Version);
 }
 else
 {
 switch (ucOSD_Item_Index0)
 {
 case 1 :
 OSD_Slider(5, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
 break;
 
 case 2 :
 OSD_Slider(7, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
 break;
 
 case 3 :
 OSD_Slider(9, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
 break;
 
 case 4 :
 OSD_Slider(11, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
 break;
 
 case 5 :
 OSD_Slider(13, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
 break;
 
 case 6 :
 OSD_Slider(15, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
 break;
 
 }
 }
 }
 
 
 
 
 
 unsigned char Page1_Goto_Subpage(unsigned char Key)
 {
 if (4 == ucOSD_Item_Index0 && ucOSD_Item_Index1)
 {
 if (0 == ucMode_Curr || 255 == ucMode_Curr)
 {
 ucOSD_Item_Index1   = 0;
 ucOSD_Item_Index2   = 0;
 }
 else
 {
 
 OSD_Proc_B(Key);
 }
 
 if (ucOSD_Item_Index1)  
 return  0;	 
 
 ucOSD_Item_Index2   = 0;
 
 
 return 1;
 
 }
 
 return 2;
 
 }
 
 
 unsigned char Page4_Goto_Subpage(unsigned char Key)
 {
 if (1 == ucOSD_Item_Index0 && 0 != ucOSD_Item_Index1)
 {
 if (0x83 != Key)
 {
 
 OSD_Proc_B(Key);
 
 if (ucOSD_Item_Index1)  
 return 0;      
 
 
 return 1;
 }
 else
 {
 
 ucOSD_Item_Index1   = 0;
 }
 }
 
 return 2;
 
 }
 
 unsigned char Page5_Goto_Subpage(unsigned char Key)
 {
 if (1 == ucOSD_Item_Index0 && 0 != ucOSD_Item_Index1)
 {
 if (0x83 != Key)
 {
 
 OSD_Proc_B(Key);
 
 if (ucOSD_Item_Index1)  return 0;      
 
 
 return 1;
 }
 else
 {
 
 ucOSD_Item_Index1   = 0;
 }
 }
 
 return 2;
 
 }
 
 
#line 3240 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 3424 "Code\Lcd_osd.c" /0
 
 unsigned char Sub_Page_Process(unsigned char Key)
 {
 unsigned char ucTemp = 2;
 
 switch(ucOSD_Page_Index)
 {
 case 1:
 ucTemp = Page1_Goto_Subpage(Key); 
 break;
 
 
 case 3:	    
 ucTemp = Page4_Goto_Subpage(Key);
 break;
 
 
 case 4:
 ucTemp = Page5_Goto_Subpage(Key);
 break;
 
 default:
 break;
 }
 
 return ucTemp;
 
 }
 
 
 
 
 void FACTORY_Key_Process(void)     
 {
 switch(ucOSD_Page_Index)
 {
 case 0:
 FACTORY_Key_Key();
 break;
 }
 }
 
 
 
 void Enter_Key_Process(void)
 {
 switch(ucOSD_Page_Index)
 {
 case 0:
 Page0_Enter_Key();
 break;
 
 case 1:
 Page1_Enter_Key();
 break;
 
 case 2:
 Page2_Enter_Key();
 break;







 
 case 3:
 Page4_Enter_Key();
 break;
 
 case 4:
 Page5_Enter_Key();
 break;
 
 case 5:
 
 ucOSD_Page_Index    = 0;
 break;
 
 case 8:
 if((stGUD1.INPUT_SOURCE & 0x07) == 0)
 PageADC_Enter_Key();
 
 
#line 3509 "Code\Lcd_osd.c" /1
 
 
 
#line 3512 "Code\Lcd_osd.c" /0
 break;
 
 case 15:
 PageFactory_Enter_Key();
 break;
 
 }
 }
 
 void Enter_Key_B_Process(void)
 {
 switch(ucOSD_Page_Index)
 {
 case 1:
 Page1B_Enter_Key();
 break;
 
 
 case 3:	    
 Page4B_Enter_Key();
 break;
 
 
 
 case 4:
 Page5B_Enter_Key();
 break;
 
 }
 }
 void Left_Right_Key_Process(unsigned char Key)
 {
 switch(ucOSD_Page_Index)
 {
 case 0:
 Page0_Left_Right_Key(Key);
 break;
 
 case 1:        
 Page1_Left_Right_Key(Key);
 break;
 
 case 2:        
 Page2_Left_Right_Key(Key);
 break;




 
 case 3:        
 Page4_Left_Right_Key(Key);
 break;
 
 case 4:        
 Page5_Left_Right_Key(Key);
 break;
 
 case 5:        
 Page6_Left_Right_Key(Key);
 break;
 
 case 8:
 if((stGUD1.INPUT_SOURCE & 0x07) == 0)
 PageADC_Left_Right_Key(Key);
 
 
#line 3579 "Code\Lcd_osd.c" /1
 
 
 
#line 3582 "Code\Lcd_osd.c" /0
 break;
 
 case 15:
 PageFactory_Left_Right_Key(Key);
 break;
 
 }
 }
 
 void Left_Right_Key_B_Process(unsigned char Key)
 {
 switch(ucOSD_Page_Index)
 {
 case 1:	     
 Page1B_Left_Right_Key(Key);
 break;
 
 
 case 3:	    
 Page4B_Left_Right_Key(Key);
 break;
 
 
 
 case 4:	    
 Page5B_Left_Right_Key(Key);
 break;
 
 }
 }
 
 void Show_Process(void)
 {
 switch(ucOSD_Page_Index)
 {
 case 1:	     
 Page1_Show();
 break;
 
 case 2:	     
 Page2_Show();
 break;




 
 case 3:	     
 Page4_Show();
 break;
 
 case 4:	     
 Page5_Show();
 break;
 
 case 5:	     
 Page6_Show();
 break;
 
 case 8:
 if((stGUD1.INPUT_SOURCE & 0x07) == 0)
 PageADC_Show();
 
 
#line 3646 "Code\Lcd_osd.c" /1
 
 
 
#line 3649 "Code\Lcd_osd.c" /0
 break;
 
 case 15:
 PageFactory_Show();
 break;
 
 }
 }
 
 void Show_B_Process(void)
 {
 switch(ucOSD_Page_Index)
 {
 case 1:
 Page1B_Show();
 break;
 
 
 case 3:	    
 Page4B_Show();
 break;
 
 
 
 case 4:	    
 Page5B_Show();
 break;
 
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 void OSD_Proc(unsigned char action)
 {
 
 
#line 3695 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 3712 "Code\Lcd_osd.c" /0
 
 Data[0] = Sub_Page_Process(action);
 
 if(Data[0] == 1)
 action = 0x83;	 
 else if(Data[0] == 0)
 return;	 
 
 if((0 != ucMode_Curr)&&(255 != ucMode_Curr))	 
 {
 switch(action)
 {
 case 0x05 :
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 if (0 == (stGUD1.INPUT_SOURCE & 0x07) && 0 != ucMode_Curr && 255 != ucMode_Curr)
 {
 RTDOSDW(OSD_Reset);
 OSD_Position(0x01);
 RTDOSDW(OSD_AUTO);
 RTDOSDW(strTabAuto_Atb[stGUD1.FUNCTION & 0x07]);		 
 RTDSetBit(0x6D, 0xfe, 0x01);
 if (6 <= ucMode_Curr && 9 >= ucMode_Curr)
 {
 stMUD.CLOCK = 128;
 Set_H_Position();
 Set_Clock();
 Save_MUD(ucMode_Curr);
 if (0xfc == Auto_Phase())
 ucMode_Curr = 254;
 if (0xfc == Auto_Position())
 ucMode_Curr = 254;
 }
 else
 {
 if (0xfc == Auto_Config())   ucMode_Curr = 254;
 
 }
 b_rgb_VOLUME_STATUS = 0;
 ucOSD_Page_Index    = 0;
 RTDSetByte(0x02, 0x40);   
 
 RTDSetBit(0x6D, 0xfe, 0x00);
 RTDOSDW(OSD_Reset);             
 
 
 }
 break;
 
 case 0x02:
 b_rgb_VOLUME_STATUS = 0;
 Enter_Key_Process();
 break;
 
 case 0x03:
 case 0x04:
 Left_Right_Key_Process(action);
 break;
 
 case 0x06 :
 rgb_EXIT_KEY();
 break;
 
 case 0x83:
 Show_Process();
 break;
 
 case 0x08:
 if(ucOSD_Page_Index == 0)
 Page0_LR_Key();
 break;
 
 case 0x09:              
 if((stGUD3.TV_SETTING & 0x08) == 0x08 ) 
 {
 FACTORY_Key_Process();
 }
 break;
 
 default:
 break;
 
 }
 }
 }
 
 void OSD_Proc_B(unsigned char action)
 {
 switch(action)
 {
 case 0x02:
 Enter_Key_B_Process();
 break;
 
 case 0x03:
 case 0x04:
 Left_Right_Key_B_Process(action);
 break;
 
 case 0x06 :
 rgb_EXIT_KEY();
 case 0x83:
 Show_B_Process();
 break;
 
 default:
 break;
 
 }
 }
 
 
 
#line 3837 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4454 "Code\Lcd_osd.c" /0
 
 
 void OSD_Opening(void)
 {
 int idata num;
 
 
 
 OSD_Window( 7, 0 , 488, 0, 264,
 0, 0, 14, 251, 0, 1, 1);
 
 Delay_Xms(128);
 
 RTDCodeW(OSD_Enable);
 RTDSetBit(0x6D, 0xfe, 0x01);
 
 for(num = 0;num < 112; num+=6)
 {
 OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
 0, 0, 14, 251, 0, 1, 1);
 }
 
 OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
 0, 0, 14, 251, 0, 1, 0);
 
 
 










































 
 }
 
 void OSD_Ending(void)
 {
 int idata num;
 
 for(num = 112;num > 0; num-=6)
 {
 OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
 0, 0, 14, 251, 0, 1, 1);
 }
 
 RTDSetBit(0x6D, 0xfe, 0x00);     
 RTDOSDW(OSD_Reset);             
 
 OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
 0, 0, 14, 251, 0, 1, 0);
 
 
 
#line 4544 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4585 "Code\Lcd_osd.c" /0
 }
 
 
 
 void Show_Note(void)
 {
 RTDSetByte(0x02, 0x40);   
 RTDSetBit(0x6D, 0xfe, 0x00);
 
 OSD_Position(0x01);
 
 
 
 switch (stGUD1.INPUT_SOURCE & 0x07)
 {
 case 0:
 
 RTDOSDW(OSD_RGB);   
 
 break;
 
 case 1:
 RTDOSDW(OSD_DVI);   
 break;
 
 case 2:
 RTDOSDW(OSD_AV);    
 break;
 
 case 3:
 RTDOSDW(OSD_SV);    
 break;
 
 case 4:
 RTDOSDW(OSD_YUV);   
 break;
 
 case 5:
 RTDOSDW(OSD_TV);
 break;
 
 }
 
 
 RTDSetBit(0x6D, 0xfe, 0x01);
 
 
 }
 
 
 
 void Show_Hint(void)
 {
 if (0 == ucMode_Curr)
 {
 RTDSetByte(0x02, 0x40);   
 RTDSetBit(0x6D, 0xfe, 0x00);
 
 
 
 if ((0 == (stGUD1.INPUT_SOURCE & 0x07)) && (0 != (M512_Port63&0x01)))
 
#line 4647 "Code\Lcd_osd.c" /1
 
 
#line 4649 "Code\Lcd_osd.c" /0
 {
 RTDOSDW(OSD_HINT_TABLE[0][stGUD1.FUNCTION & 0x07]);
 }
 else
 {
 RTDOSDW(OSD_Clean_All);
 RTDOSDW(OSD_HINT_TABLE[1][stGUD1.FUNCTION & 0x07]);
 }
 
 
 RTDSetBit(0x6D, 0xfe, 0x01);
 }
 else if ((255 == ucMode_Curr) || bOverSpec)
 {
 RTDSetByte(0x02, 0x40);   
 RTDSetBit(0x6D, 0xfe, 0x00);
 
 
 RTDOSDW(OSD_HINT_TABLE[2][stGUD1.FUNCTION & 0x07]);
 
 
 RTDSetBit(0x6D, 0xfe, 0x01);
 }
 }
 
 
 
#line 4676 "Code\Lcd_osd.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 4743 "Code\Lcd_osd.c" /0
