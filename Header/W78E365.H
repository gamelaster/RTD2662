/*--------------------------------------------------------------------------

--------------------------------------------------------------------------*/

/*  BYTE Registers  */
sfr P0    = 0x80;
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
sfr P1    = 0x90;
sfr SCON  = 0x98;
sfr SBUF  = 0x99;
sfr P2    = 0xA0;
sfr IE    = 0xA8;
sfr P3    = 0xB0;
sfr IP    = 0xB8;
sfr PSW   = 0xD0;
sfr ACC   = 0xE0;
sfr B     = 0xF0;

/*  P1  */
sbit P17  = P1^7;
sbit P16  = P1^6;
sbit P15  = P1^5;
sbit P14  = P1^4;
sbit P13  = P1^3;
sbit P12  = P1^2;
sbit P11  = P1^1;
sbit P10  = P1^0;

/*  8052 Extensions  */
sfr T2CON  = 0xC8;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;

/* WinBond extension */
sfr PWM3   = 0xDE;
sfr PWM2   = 0xDD;
sfr PWMCON1= 0xDC;
sfr PWM1   = 0xDB;
sfr PWM0   = 0xDA;
sfr PWMP   = 0xD9;
sfr P4     = 0xD8;
sfr PWM4   = 0xCF;
sfr PWMCON2= 0xCE;
sfr T2MOD  = 0xC9;
sfr SFRCN  = 0xC7;
sfr SFRFD  = 0xC6;
sfr SFRAH  = 0xC5;
sfr SFRAL  = 0xC4;
sfr P4CONB = 0xC3;
sfr P4CONA = 0xC2;
sfr XICON  = 0xC0;
sfr CHPCON = 0xBF;
sfr P43AH  = 0xB5;
sfr P43AL  = 0xB4;
sfr P4CSIN = 0xAE;
sfr P42AH  = 0xAD;
sfr P42AL  = 0xAC;
sfr XRAMAH = 0xA1;
sfr P41AH  = 0x95;
sfr P41AL  = 0x94;
sfr WDTC   = 0x8F;
sfr AUXR   = 0x8E;
sfr POR    = 0x86;
sfr P40AH  = 0x85;
sfr P40AL  = 0x84;
sfr CHPENR = 0xF6;

/*  BIT Registers  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit P     = PSW^0; //8052 only

/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  IE  */
sbit EA    = IE^7;
sbit ET2   = IE^5; //8052 only
sbit ES    = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;

/*  IP  */
sbit PT2   = IP^5;
sbit PS    = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;

/*  P3  */
sbit RD    = P3^7;
sbit WR    = P3^6;
sbit T1    = P3^5;
sbit T0    = P3^4;
sbit INT1  = P3^3;
sbit INT0  = P3^2;
sbit TXD   = P3^1;
sbit RXD   = P3^0;

/*  SCON  */
sbit SM0   = SCON^7;
sbit SM1   = SCON^6;
sbit SM2   = SCON^5;
sbit REN   = SCON^4;
sbit TB8   = SCON^3;
sbit RB8   = SCON^2;
sbit TI    = SCON^1;
sbit RI    = SCON^0;

/*  P1  */
sbit T2EX  = P1^1; // 8052 only
sbit T2    = P1^0; // 8052 only
             
/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;


/* XICON */
sbit PX3    = XICON^7;
sbit EX3    = XICON^6;
sbit IE3    = XICON^5;
sbit IT3    = XICON^4;
sbit PX2    = XICON^3;
sbit EX2    = XICON^2;
sbit IE2    = XICON^1;
sbit IT2    = XICON^0;

/* P4 */
sbit INT2   = P4^3;
sbit INT3   = P4^2;

/* SMC5152 chip */

#define	SMC_DATA	P10
#define	SMC_CLOCK	P11
#define	SMC_LATCH	P12

#define	AD9822_DATA	P15
#define	AD9822_CLK	P16
#define	AD9822_LOAD	P17

#define	SPI_DATA	P15
#define	SPI_CLK		P16
#define	SPI_LOAD	P17

#if 0
#define	I2CSCL	TXD
#define	I2DAT	RXD
#else
#define	I2CSCL	SPI_CLK
#define	I2CDAT	SPI_DATA
#endif
