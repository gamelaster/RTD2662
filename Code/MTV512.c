#include "Header\Main_def.h"

//#if(MCU_TYPE == MCU_MTV512)		//anson

#if(USE_MCU_DDC)
/* define these variable for MTV230M chip configuration */
//Byte xdata PRAM[128]	    _at_ 0x0800;

//**************************************************************
//                            Myson Addtion
//Create DDC RAM Address
unsigned char xdata byMTV512_DDCRAMA[128]   _at_ 0x0e00;  //DDCRAM1 
unsigned char xdata byMTV512_DDCRAMB[128]   _at_ 0x0e80;  //DDCRAM2
//**************************************************************

//******************************************************
//                         Myson Addtion
unsigned char xdata byM512_CTRSLVB    _at_ 0xF0A;
//******************************************************

//******************************************************
//                         Myson Revise
//Byte xdata byM212_IIC_TXRCABUF   _at_ 0xF06;
unsigned char xdata byM512_DDCCTRA1   _at_ 0xF06;
//******************************************************
//******************************************************
//                         Myson Addtion
unsigned char xdata  byM512_DDCCTRA2    _at_  0x0F86;
unsigned char xdata  byM512_SLVA2ADR     _at_  0x0F87;
//******************************************************
//                         Myson Revise
//Byte xdata byM212_IIC_SLVAADR    _at_ 0xF07;
unsigned char xdata byM512_SLVA1ADR    _at_ 0xF07;
//******************************************************

//******************************************************
//                         Myson Addtion
unsigned char xdata byM512_CTRSLVB    _at_ 0xF0A;
//******************************************************
#endif


//Xdata use DPTR instruction
//Pdata use MOVX instruction set at BL51 Code/banking linker>size/location
unsigned char xdata M512_PadMode0  _at_  0xF50;
unsigned char xdata M512_PadMode1  _at_  0xF51;
unsigned char xdata M512_PadMode2  _at_  0xF52;
unsigned char xdata M512_PadMode3  _at_  0xF53;
unsigned char xdata M512_PadMode4  _at_  0xF54;
unsigned char xdata M512_PadMode5  _at_  0xF55;
unsigned char xdata M512_Option1   _at_ 0xF56;
unsigned char xdata M512_PadMode6  _at_ 0xF5E; //DWL 1219
unsigned char xdata M512_PadMode7  _at_ 0xF5F; //DWL 1219

unsigned char xdata M512_Port40    _at_ 0xF58;
unsigned char xdata M512_Port41    _at_ 0xF59;
unsigned char xdata M512_Port42    _at_ 0xF5A;



unsigned char xdata M512_Port50    _at_ 0xF30;
//#define  bPANEL_PWR  byM212_Port50
unsigned char xdata M512_Port51    _at_ 0xF31;
unsigned char xdata M512_Port52    _at_ 0xF32;
unsigned char xdata M512_Port53    _at_ 0xF33;
unsigned char xdata M512_Port54    _at_ 0xF34;
unsigned char xdata M512_Port55    _at_ 0xF35;
unsigned char xdata M512_Port56    _at_ 0xF36;

unsigned char xdata M512_Port60    _at_ 0xF38;
unsigned char xdata M512_Port61    _at_ 0xF39;
unsigned char xdata M512_Port62    _at_ 0xF3A;
unsigned char xdata M512_Port63    _at_ 0xF3B;
unsigned char xdata M512_Port64    _at_ 0xF3C;
unsigned char xdata M512_Port65    _at_ 0xF3D;
unsigned char xdata M512_Port66    _at_ 0xF3E;
unsigned char xdata M512_Port67    _at_ 0xF3F;

unsigned char xdata M512_Port76    _at_ 0xF76;//dwl 1219
unsigned char xdata M512_Port77    _at_ 0xF77;//dwl 1219

// define MTV212M's PWM DAC register
unsigned char xdata M512_DA0	    _at_ 0xF20;
unsigned char xdata M512_DA1	    _at_ 0xF21;
unsigned char xdata M512_DA2	    _at_ 0xF22;
unsigned char xdata M512_DA3	    _at_ 0xF23;
unsigned char xdata M512_DA4	    _at_ 0xF24;
unsigned char xdata M512_DA5	    _at_ 0xF25;
unsigned char xdata M512_DA6	    _at_ 0xF26;
unsigned char xdata M512_DA7	    _at_ 0xF27;
unsigned char xdata M512_DA8	    _at_ 0xF28;
unsigned char xdata M512_DA9	    _at_ 0xF29;
unsigned char xdata M512_DA10	    _at_ 0xF2A;
unsigned char xdata M512_DA11	    _at_ 0xF2B;
unsigned char xdata M512_DA12	    _at_ 0xF2C;
unsigned char xdata M512_DA13	    _at_ 0xF2D;

//define MTV212M's H/VSync processor register
unsigned char xdata M512_HVSTUS    _at_ 0xF40;
unsigned char xdata M512_HCNTH     _at_ 0xF41;
unsigned char xdata M512_HCNTL     _at_ 0xF42;
unsigned char xdata M512_VCNTH     _at_ 0xF43;
unsigned char xdata M512_VCNTL     _at_ 0xF44;

unsigned char xdata M512_INTFLG    _at_ 0xF48;
unsigned char xdata M512_INTEN     _at_ 0xF49;

//define MTV212's IIC's control
unsigned char xdata M512_IIC_CTR        _at_ 0xF00;
unsigned char xdata M512_IIC_STUS1      _at_ 0xF01;
unsigned char xdata M512_IIC_STUS2      _at_ 0xF02;
unsigned char xdata M512_IIC_INTFLG	   _at_ 0xF03;
unsigned char xdata M512_IIC_INTEN	   _at_ 0xF04;
unsigned char xdata M512_IIC_MBUF	      _at_ 0xF05;
//unsigned char xdata M512_IIC_TXRCABUF   _at_ 0xF06;
//unsigned char xdata M512_IIC_SLVAADR    _at_ 0xF07;
unsigned char xdata M512_IIC_TXRCBBUF   _at_ 0xF08;
unsigned char xdata M512_IIC_SLVBADR    _at_ 0xF09;
//unsigned char xdata byM212_IIC_DBUF     _at_ 0xF0A;
unsigned char xdata M512_ISPSLV         _at_ 0xF0B;
unsigned char xdata M512_ISPEN          _at_ 0xF0C;

//define MTV212's A/D converter
//unsigned char xdata byM212_ADC	    _at_ 0xF10;
unsigned char xdata M512_ADC	    _at_ 0xF10;
unsigned char xdata M512_WDT	    _at_ 0xF18;
unsigned char xdata EINT1PEN        _at_ 0xF8E; 
//#endif					//anson
