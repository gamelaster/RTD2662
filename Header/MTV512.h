#include "HEADER\Main_def.h"

//#if(MCU_TYPE == MCU_MTV512)
//extern   unsigned char xdata PRAM[128];     //	    _at_ 0x0800;

//#if(USE_MCU_DDC)
//**************************************************************
//                            Myson Addtion
//Create DDC RAM Address
extern unsigned char xdata byMTV512_DDCRAMA[128];  // _at_ 0x0e00  //DDCRAM1 
extern unsigned char xdata byMTV512_DDCRAMB[128];  //  _at_ 0x0e80  //DDCRAM2
//**************************************************************
//#endif

//Xdata use DPTR instruction
//Pdata use MOVX instruction set at BL51 Code/banking linker>size/location
extern   unsigned char xdata M512_PadMode0;     //  _at_ 0xF2B;
extern   unsigned char xdata M512_PadMode1;     //  _at_ 0xF2C;
extern   unsigned char xdata M512_PadMode2;     //  _at_ 0xF2D;
extern   unsigned char xdata M512_PadMode3;     //  _at_ 0xF2E;
extern   unsigned char xdata M512_PadMode4;     //  _at_ 0xF2E;
extern   unsigned char xdata M512_PadMode5;     //  _at_ 0xF2E;
extern   unsigned char xdata M512_Option1;
extern   unsigned char xdata M512_PadMode6; 
extern   unsigned char xdata M512_PadMode7; 

extern   unsigned char xdata M512_Port40;     //    _at_ 0xF30;
extern   unsigned char xdata M512_Port41;     //    _at_ 0xF31;
extern   unsigned char xdata M512_Port42;     //    _at_ 0xF32;
//extern   unsigned char xdata byM212_Port43;     //    _at_ 0xF33;
//extern   unsigned char xdata byM212_Port44;     //    _at_ 0xF34;
//extern   unsigned char xdata byM212_Port45;     //    _at_ 0xF35;
//extern   unsigned char xdata byM212_Port46;     //    _at_ 0xF36;
//extern   unsigned char xdata byM212_Port47;     //    _at_ 0xF37;


extern   unsigned char xdata M512_Port50;     //    _at_ 0xF38;
extern   unsigned char xdata M512_Port51;     //    _at_ 0xF39;
extern   unsigned char xdata M512_Port52;     //    _at_ 0xF3A;
extern   unsigned char xdata M512_Port53;     //    _at_ 0xF3B;
extern   unsigned char xdata M512_Port54;     //    _at_ 0xF3C;
extern   unsigned char xdata M512_Port55;     //    _at_ 0xF3D;
extern   unsigned char xdata M512_Port56;     //    _at_ 0xF3E;

extern   unsigned char xdata M512_Port60;     //    _at_ 0xF28;
extern   unsigned char xdata M512_Port61;     //    _at_ 0xF29;
extern   unsigned char xdata M512_Port62;     //    _at_ 0xF2A;
extern   unsigned char xdata M512_Port63;     //    _at_ 0xF28;
extern   unsigned char xdata M512_Port64;     //    _at_ 0xF29;/
extern   unsigned char xdata M512_Port65;     //    _at_ 0xF2A;
extern   unsigned char xdata M512_Port66;     //    _at_ 0xF28;
extern   unsigned char xdata M512_Port67;     //    _at_ 0xF29;

extern   unsigned char xdata M512_Port76;	  
extern   unsigned char xdata M512_Port77;	  
// define MTV212M's PWM DAC register
extern   unsigned char xdata M512_DA0;     //	    _at_ 0xF20;
extern   unsigned char xdata M512_DA1;     //	    _at_ 0xF21;
extern   unsigned char xdata M512_DA2;     //	    _at_ 0xF22;
extern   unsigned char xdata M512_DA3;     //	    _at_ 0xF23;
extern   unsigned char xdata M512_DA4;     //	    _at_ 0xF20;
extern   unsigned char xdata M512_DA5;     //	    _at_ 0xF21;
extern   unsigned char xdata M512_DA6;     //	    _at_ 0xF22;
extern   unsigned char xdata M512_DA7;     //	    _at_ 0xF23;
extern   unsigned char xdata M512_DA8;     //	    _at_ 0xF20;
extern   unsigned char xdata M512_DA9;     //	    _at_ 0xF21;
extern   unsigned char xdata M512_DA10;     //	    _at_ 0xF22;
extern   unsigned char xdata M512_DA11;     //	    _at_ 0xF23;
extern   unsigned char xdata M512_DA12;     //	    _at_ 0xF23;
extern   unsigned char xdata M512_DA13;     //	    _at_ 0xF23;

//define MTV212M's H/VSync processor register
extern   unsigned char xdata M512_HVSTUS;     //    _at_ 0xF40;
extern   unsigned char xdata M512_HCNTH;     //     _at_ 0xF41;
extern   unsigned char xdata M512_HCNTL;     //     _at_ 0xF42;
extern   unsigned char xdata M512_VCNTH;     //     _at_ 0xF43;
extern   unsigned char xdata M512_VCNTL;     //     _at_ 0xF44;
extern   unsigned char xdata M512_INTFLG;     //    _at_ 0xF48;
extern   unsigned char xdata M512_INTEN;     //     _at_ 0xF49;


//define MTV212's IIC's control
extern   unsigned char xdata M512_IIC_CTR;     //        _at_ 0xF00;
extern   unsigned char xdata M512_IIC_STUS1;     //      _at_ 0xF01;
extern   unsigned char xdata M512_IIC_STUS2;     //      _at_ 0xF02;
extern   unsigned char xdata M512_IIC_INTFLG;     //	   _at_ 0xF03;
extern   unsigned char xdata M512_IIC_INTEN;     //	   _at_ 0xF04;
extern   unsigned char xdata M512_IIC_MBUF;     //	      _at_ 0xF05;
extern   unsigned char xdata M512_IIC_TXRCABUF;     //   _at_ 0xF06;
extern   unsigned char xdata M512_IIC_SLVAADR;     //    _at_ 0xF07;
extern   unsigned char xdata M512_IIC_TXRCBBUF;     //   _at_ 0xF08;
extern   unsigned char xdata M512_IIC_SLVBADR;     //    _at_ 0xF09;
//extern   unsigned char xdata byM212_IIC_DBUF;     //     _at_ 0xF0A;
extern   unsigned char xdata M512_ISPSLV;     //         _at_ 0xF0B;
extern   unsigned char xdata M512_ISPEN;     //          _at_ 0xF0C;


//define MTV212's A/D converter
//extern   unsigned char xdata byM212_ADC;     //	    _at_ 0xF10;
extern   unsigned char xdata M512_ADC;     //	    _at_ 0xF10;
extern   unsigned char xdata M512_WDT;     //	    _at_ 0xF18;
extern   unsigned char xdata EINT1PEN ;   //    _at_ 0xF8E; DWL 0101

#if(USE_MCU_DDC)
//******************************************************
//                         Myson Revise
//extern   Byte xdata byM212_IIC_TXRCABUF;     //   _at_ 0xF06;
extern   unsigned char xdata byM512_DDCCTRA1;              //_at_ 0xF06;
//******************************************************
//******************************************************
//                         Myson Revise
//extern   Byte xdata byM212_IIC_SLVAADR;     //    _at_ 0xF07;
extern   unsigned char xdata byM512_SLVA1ADR;             //_at_ 0xF07;
//******************************************************

//******************************************************
//                         Myson Addtion
extern   unsigned char xdata byM512_CTRSLVB;   // _at_ 0xF0A;
//******************************************************

//******************************************************
//                         Myson Addtion
extern   unsigned char xdata  byM512_DDCCTRA2;    //_at_  0x0F86;
extern   unsigned char xdata  byM512_SLVA2ADR;     // _at_  0x0F87;
//******************************************************
//#endif


#endif

//PIN DEFINE






