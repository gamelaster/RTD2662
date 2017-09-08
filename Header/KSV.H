//#include "main_def.h"

#ifdef __HDCPKSV__

#if(HDCP_ENABLE)
unsigned char code BKSV[];
unsigned char code HDCP_KEY_A_Port[];
#endif

#else

#if(HDCP_ENABLE)
extern unsigned char code BKSV[];
extern unsigned char code HDCP_KEY_A_Port[];
#endif

#endif
