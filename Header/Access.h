//#include "main_def.h"

#ifdef __ACCESS__

// Data
unsigned char data  Data[16];	// data array for RTD/I2C R/W

unsigned char data ucCnt;
bit bBit;
unsigned int data uiCount;
unsigned char data ucByte_Temp;

unsigned char bdata Reg;

sbit    r0 = Reg ^ 0;
sbit    r1 = Reg ^ 1;
sbit    r2 = Reg ^ 2;
sbit    r3 = Reg ^ 3;
sbit    r4 = Reg ^ 4;
sbit    r5 = Reg ^ 5;
sbit    r6 = Reg ^ 6;
sbit    r7 = Reg ^ 7;



// Function
void BitDly(void);
void SetPortBit(unsigned char port, unsigned char and, unsigned char or);
void SetSFRPort(unsigned char port, unsigned char Data);
unsigned char GetSFRPort(unsigned char port);

unsigned char I2CGetByte(unsigned char ack);
void I2CSendByte(unsigned char send);
void I2CSendAddr(unsigned char addr, unsigned char index ,unsigned char rd);
void I2CSendStop(void);
void I2CRead(unsigned char addr, unsigned char index, unsigned char count);	// main I2C control Read
void I2CWrite(unsigned char *array);						// main I2C control write

unsigned char RTDGetByte(void);
void RTDSendByte(unsigned char send);                                     
void RTDSendAddr(unsigned char addr, unsigned char rd, unsigned char inc); 
void RTDRead(unsigned char index, unsigned char count, unsigned char inc);  // main RTD control Read
void RTDWrite(unsigned char data *array);                                   // main RTD control write
void RTDCodeW(unsigned char code *array);                                   // main RTD control write
void RTDOSDW(unsigned char code *array);


void RTDSetBit(unsigned char addr,unsigned char and, unsigned char or);     // RTD reg. bit setting 
void RTDSetByte(unsigned char addr, unsigned char val);                     // RTD reg. byte setting

#if(VLC_COMPRESS)
void Load_VLC_Font(unsigned char code *array, unsigned int start, unsigned int length);
unsigned char Get_VLD(unsigned char code *array);
void Getbit(unsigned char code *array);
#else
void Load_Font(unsigned char code *array, unsigned int start, unsigned int length);
#endif

#if(MCU_TYPE == MCU_MTV512)
void MCU_Initial(void);
void MCU_WriteI2cScl(bit Status);
void MCU_WriteI2cSda(bit Status);
bit MCU_ReadI2cSda(void);

#if(RESET_TYPE == RESET_IN)
void MCU_WriteRtdReset(bit Status);
bit MCU_ReadRtdReset(void);
#endif

//void MCU_WriteRtdSdio(bit Status);
//bit MCU_ReadRtdSdio(void);
void MCU_WriteRtdSclk(bit Status);
void MCU_WriteRtdScsb(bit Status);
#if (VIDEO_CHIP != VDC_NONE)
void MCU_WriteVideoPower(bit Status);
#endif

void MCU_WritePanelPower(bit Status);
//bit MCU_ReadPanelPower(void);
void MCU_WriteBacklightPower(bit Status);
bit MCU_ReadBacklightPower(void);
bit MCU_ReadVgaConnect(void);
#endif

#if(HDCP_ENABLE)
void KEYCodeW(unsigned char code *array);
#endif

#else

// Data
extern unsigned char data Data[16];

// Function
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

#if(HDCP_ENABLE)
extern void KEYCodeW(unsigned char code *array);
#endif

#if(MCU_TYPE == MCU_MTV512)
extern void MCU_Initial(void);
extern void MCU_WriteI2cScl(bit Status);
extern void MCU_WriteI2cSda(bit Status);
extern bit MCU_ReadI2cSda(void);

#if(RESET_TYPE == RESET_IN)
extern void MCU_WriteRtdReset(bit Status);
extern bit MCU_ReadRtdReset(void);
#endif


//extern void MCU_WriteRtdSdio(bit Status);
//extern bit MCU_ReadRtdSdio(void);
extern void MCU_WriteRtdSclk(bit Status);
extern void MCU_WriteRtdScsb(bit Status);
#if (VIDEO_CHIP != VDC_NONE)
extern void MCU_WriteVideoPower(bit Status);
#endif
/*
extern bit MCU_ReadMenuKey(void);
extern bit MCU_ReadEnterKey(void);
extern bit MCU_ReadRightKey(void);
extern bit MCU_ReadLeftKey(void);
extern bit MCU_ReadPowerKey(void);
*/
extern void MCU_WritePanelPower(bit Status);
//extern bit MCU_ReadPanelPower(void);
extern void MCU_WriteBacklightPower(bit Status);
extern bit MCU_ReadBacklightPower(void);
extern bit MCU_ReadVgaConnect(void);
#endif

#endif
