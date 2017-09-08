#include "HEADER\main_def.h"

#if(RS232_DEBUG)
extern const unsigned char PutStringToScr(const unsigned char code* pstr);
extern void PutCharToScr(const unsigned char ch);

void DebugModeLoop(void);
void DispOSD_TestMessage(void);
void HexToBin(unsigned int HexData);

//unsigned char   idata   UartNum        = 0;
//unsigned char idata  UartData[4];	// data array for RTD/I2C R/W


//extern unsigned char   idata   UartNum;
//extern unsigned char   idata   UartData[4];


extern unsigned char bdata byflag20;
extern bit  fTest;//    =  byflag20^0;

extern unsigned char bdata byflag21;
extern bit  fUart_Start;//    =  byflag20^0;
extern bit  fUartStart;
extern bit    fDebugModeEnable;
#endif



