#include "Header\main_def.h"

//#if(MCU_TYPE == MCU_MTV512)		//anson 050519
#include "Header\MTV512.h"
//#endif

///////////////////////////////////////////////////////////////////
// Definitions for GPIO control

#define PANEL_ON        0   // Power on  state for LCD panel 
#define PANEL_OFF       1   // Power off state for LCD panel
#if 1
#define LIGHT_ON	0   // Power on  state for backlight inverter
#define LIGHT_OFF	1   // Power off state for backlight inverter
#else
#define LIGHT_ON	1   // Power on  state for backlight inverter
#define LIGHT_OFF	0   // Power off state for backlight inverter
#endif
#define VDC_ON          1   // Power on  state for video decoder
#define VDC_OFF         0   // Power off state for video decoder

#define LVDS_ON         0   // Power on  state for LVDS Tx
#define LVDS_OFF        1   // Power off state for LVDS Tx

#define VGA_ONLINE      0   // VGA cable connected state
#define DVI_ONLINE      1   // DVI cable connected state

#define ADC_RED_PHASE_FT    (0x01 << 2)//(0x07 << 2)  //ADC RED phase fine tune   (0x00 ~ 0x07)
#define ADC_GREEN_PHASE_FT  (0x01 << 4)//(0x00 << 4)  //ADC GREEN phase fine tune (0x00 ~ 0x07)
#define ADC_BLUE_PHASE_FT    0x01        //ADC BLUE phase fine tune  (0x00 ~ 0x07)

#if(KINGMICE)
/*
    sbit bRTD_IRQ       = 0x86;
    sbit bDVI_CONNECT   = 0x87;
    
    sbit bPANEL_PWR     = 0x90;
    sbit bLIGHT_PWR     = 0x91;
    sbit bIIC_SCL       = 0x92;
    sbit bIIC_SDA       = 0x93;
    sbit bRTD_PWR       = 0x94;
    
    #if(PARALLEL_PORT)
    sbit bRTD_SDIO_0    = 0x95;
    sbit bRTD_SDIO_3    = 0x94;//joe1205
    sbit bRTD_SDIO_2    = 0xb2;
    sbit bRTD_SDIO_1    = 0xb0;//joe1205
    #else
    sbit bRTD_SDIO_0    = 0x95;
    #endif
    
    sbit bRTD_SCLK      = 0x96;
    sbit bRTD_SCSB      = 0x97;
    sbit bRTD_RST       = 0xb1;
    
    sbit bLVDS_PWR      = 0xb7;
    sbit bPOWER_KEY     = 0xb7;
    sbit bTMDS_PWR      = 0xa2;
    sbit bVDC_PWR       = 0xb1;
    sbit bVGA_CONNECT   = 0xa5;
    
    sbit bDDC_SDA       = 0xb0;
    sbit bDDC_SCL       = 0xb1;
    sbit bIR_GPIO       = 0xb2;
    sbit bMENU_KEY      = 0xb3;
    sbit bENTER_KEY     = 0xb4;
    sbit bRIGHT_KEY     = 0xb5;
    sbit bLEFT_KEY      = 0xb6;
    //sbit bPOWER_KEY     = 0xb7;
    
    
    // For button control
    #define POWER_KEY_PORT  0x03    // Port 3
    #define POWER_KEY_MASK  0x80    // Bit  7
    
    #define MENU_KEY_PORT   0x03    // Port 3
    #define MENU_KEY_MASK   0x08    // Bit  3
    
    #define ENTER_KEY_PORT  0x03    // Port 3
    #define ENTER_KEY_MASK  0x10    // Bit  4
    
    #define RIGHT_KEY_PORT  0x03    // Port 3
    #define RIGHT_KEY_MASK  0x20    // Bit  5
    
    #define LEFT_KEY_PORT   0x03    // Port 3
    #define LEFT_KEY_MASK   0x40    // Bit  6
    
*/
#else//(!KINGMICE)

#if(MCU_TYPE == MCU_WINBOND)
/*
///////////////////////////////MCU_WINBOND Start /////////////////////////////////
sbit bRTD_SDIO_0	= 0x80;
#if(PARALLEL_PORT)
sbit bRTD_SDIO_1	= 0x81;
sbit bRTD_SDIO_2	= 0x82;
sbit bRTD_SDIO_3	= 0x83;
#endif

sbit bRTD_SCLK		= 0x84;
sbit bRTD_SCSB		= 0x85;
sbit bIIC_SCL			= 0x86;
sbit bIIC_SDA		= 0x87;

sbit bPANEL_PWR		= 0x90;
sbit bLIGHT_PWR		= 0x91;
sbit bGREEN_LED		= 0x92;     //LED 2     
sbit bRED_LED		= 0x93;     //LED 1     
sbit bPOWER_KEY		= 0x94;     //p1.4     
sbit bMENU_KEY		= 0x95;     //p1.0     
sbit bENTER_KEY		= 0xa7;     //p1.7                 

sbit bAUTO_KEY		= 0xa0;     //p1.1     
sbit bMUTE			= 0xa1;     //Audio mute
sbit bVGA_CONNECT	= 0xa3;
sbit bSTANDBY		= 0xa4;

sbit bDDC_SCL		= 0xb0;
sbit bDDC_SDA		= 0xb1;
sbit bRTD_RST		= 0xb2;
sbit bIR_GPIO		= 0xb3;
sbit bRIGHT_KEY		= 0xb4;     //p1.2     
sbit bLEFT_KEY		= 0xb5;     //p1.3     
sbit bUP_KEY			= 0xb6;     //P1.5     
sbit bDOWN_KEY		= 0xb7;     //P1.6     

// For button control
#define MENU_KEY_PORT		0x01    // Port 1   
#define MENU_KEY_MASK		0x20    // Bit  5   
                                            
#define AUTO_KEY_PORT		0x02    //port 2    
#define AUTO_KEY_MASK		0x01    //Bit  1    //for rm
                                            
#define RIGHT_KEY_PORT		0x03    // Port 3   
#define RIGHT_KEY_MASK		0x10    // Bit  4   
                                            
#define LEFT_KEY_PORT		0x03    // Port 3   
#define LEFT_KEY_MASK		0x20    // Bit  5   
                                            
#define POWER_KEY_PORT		0x01    // Port 1   
#define POWER_KEY_MASK	0x10    // Bit  4   

#define DOWN_KEY_PORT		0x03    // PORT 3   
#define DOWN_KEY_MASK		0x80    // Bit 7    
                                                
#define ENTER_KEY_PORT		0x02    // Port 1       
#define ENTER_KEY_MASK		0x80    // Bit  7   //for rm    
   
#define FACTORY_KEY_PORT	0x01  // Port 1				//anson
#define FACTORY_KEY_MASK	0x14  // Bit  4 and 2
///////////////////////////////MCU_WINBOND  END/////////////////////////////////
*/
///////////////////////////////MCU_MTV512 Start/////////////////////////////////
sbit bRTD_SDIO_0	= 0x90;

#if(PARALLEL_PORT)
sbit bRTD_SDIO_1	= 0x91;
sbit bRTD_SDIO_2	= 0x92;
sbit bRTD_SDIO_3	= 0x93;
#endif

sbit bRTD_SCLK		= 0x94;
sbit bRTD_SCSB		= 0x95;
sbit bIIC_SCL			= 0x96;
sbit bIIC_SDA		= 0x97;

sbit bDDC_SCL		= 0xb0;
sbit bDDC_SDA		= 0xb1;
//sbit bIR_GPIO		= 0xb3;
sbit bRTD_RST		= 0xb2;
sbit bRIGHT_KEY		= 0xb4;
sbit bLEFT_KEY		= 0xb5;

#define bPANEL_PWR		M512_Port50//(M512_Port50&0x01)
#define bLIGHT_PWR		M512_Port51//(M512_Port51&0x01)
#define bGREEN_LED		M512_Port52
#define bRED_LED		M512_Port53
#define bPOWER_KEY	 	(M512_Port54&0x01)
//#define bMENU_KEY	 	(M512_Port55&0x01)
#if 0
#define bENTER_KEY	 	(M512_Port55&0x01)
#define bAUTO_KEY	 	(M512_Port60&0x01)
#else //eric modify Handstar 19"
#define bAUTO_KEY	 	(M512_Port55&0x01)
#define bENTER_KEY	 	(M512_Port60&0x01)
#endif
//////////////////
#define bMUTE	 		M512_Port61//(M512_Port60&0x01)
#define bHot_Plug		(M512_Port62&0x01)	//P6.2
#define bVGA_CONNECT	 (M512_Port63&0x01)
#define bSTANDBY	 	M512_Port64//(M512_Port64&0x01)

// For button control
                                            
//#define AUTO_KEY_PORT		0x02    //port 2    
#define AUTO_KEY_MASK		0x01    //Bit  1    //for rm
                                            
//#define RIGHT_KEY_PORT		0x03    // Port 3   
#define RIGHT_KEY_MASK		0x08    // Bit  4   
                                            
//#define LEFT_KEY_PORT		0x03    // Port 3   
#define LEFT_KEY_MASK		0x60    // Bit  5   
                                            
//#define POWER_KEY_PORT		0x01    // Port 1   
#define POWER_KEY_MASK	0x10    // Bit  4   

//#define ENTER_KEY_PORT		0x01    // Port 1       
#define ENTER_KEY_MASK		0x20    // Bit  5   //for rm    
   
//#define FACTORY_KEY_PORT	0x01  // Port 1				//anson
#define FACTORY_KEY_MASK	0x14  // Bit  4 and 2
///////////////////////////////MCU_MTV512 END/////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
#else				// MCU_TYPE == MCU_MTV512				//anson add

sbit bRTD_SDIO_0	= 0x90;

#if(PARALLEL_PORT)
sbit bRTD_SDIO_1	= 0x91;
sbit bRTD_SDIO_2	= 0x92;
sbit bRTD_SDIO_3	= 0x93;
#endif

sbit bRTD_SCLK		= 0x94;
sbit bRTD_SCSB		= 0x95;
sbit bIIC_SCL			= 0x96;
sbit bIIC_SDA		= 0x97;

sbit bDDC_SCL		= 0xb0;
sbit bDDC_SDA		= 0xb1;
//sbit bIR_GPIO		= 0xb3;
sbit bRTD_RST		= 0xb2;
sbit bRIGHT_KEY		= 0xb4;
sbit bLEFT_KEY		= 0xb5;

#define bPANEL_PWR		M512_Port50//(M512_Port50&0x01)
#define bLIGHT_PWR		M512_Port51//(M512_Port51&0x01)
#define bGREEN_LED		M512_Port52
#define bRED_LED		M512_Port53
#define bPOWER_KEY	 	(M512_Port54&0x01)
//#define bMENU_KEY	 	(M512_Port55&0x01)
#define bENTER_KEY	 	(M512_Port55&0x01)

#define bAUTO_KEY	 	(M512_Port60&0x01)
#define bMUTE	 		M512_Port61//(M512_Port60&0x01)
#define bVGA_CONNECT	 (M512_Port63&0x01)
#define bSTANDBY	 	M512_Port64//(M512_Port64&0x01)

#define bUP_KEY		 	(M512_Port76&0x01)
#define bDOWN_KEY	 	(M512_Port77&0x01)

               
// For button control
//#define MENU_KEY_PORT		0x01    // Port 1   
//#define MENU_KEY_MASK		0x20    // Bit  5   
                                            
//#define AUTO_KEY_PORT		0x02    //port 2    
#define AUTO_KEY_MASK		0x01    //Bit  1    //for rm
                                            
//#define RIGHT_KEY_PORT		0x03    // Port 3   
#define RIGHT_KEY_MASK		0x10    // Bit  4   
                                            
//#define LEFT_KEY_PORT		0x03    // Port 3   
#define LEFT_KEY_MASK		0x20    // Bit  5   
                                            
//#define POWER_KEY_PORT		0x01    // Port 1   
#define POWER_KEY_MASK	0x10    // Bit  4   

//#define DOWN_KEY_PORT		0x03    // PORT 3   
#define DOWN_KEY_MASK		0x80    // Bit 7    
                                                
//#define ENTER_KEY_PORT		0x02    // Port 1       
#define ENTER_KEY_MASK		0x80    // Bit  7   //for rm    
   
//#define FACTORY_KEY_PORT	0x01  // Port 1				//anson
#define FACTORY_KEY_MASK	0x14  // Bit  4 and 2

///////////////////////////////////////////////////////////////////////////////////////////////////
#endif

#endif
