#ifdef __FRAMESYNC__

//#include "Main_def.h"

bit bFrameSync          = 0;    // 1 - OK , 0 - Fail
unsigned char   idata   ucSyncErrorCnt  = 0;

unsigned char   idata   ucStatus        = 0;
unsigned char   idata   ucPE_Max        = 0;
unsigned char   idata   ucI_Code        = 0;
unsigned char   idata   ucP_Corr        = 0;


void AbortSync(void);

unsigned char TestSync(unsigned int offset);
unsigned char Frame_Sync(void);
void Adjust_I_Code(void);

#else

extern bit bFrameSync;    // 1 - OK , 0 - Fail
extern unsigned char   idata   ucSyncErrorCnt;
extern unsigned char   idata   ucPE_Max;
extern unsigned char   idata   ucStatus;
extern unsigned char   idata   ucI_Code;
extern unsigned char   idata   ucP_Corr;

extern unsigned char Frame_Sync(void);
extern bit Frame_Sync_Detector(void);
extern void Adjust_I_Code(void);

#endif
