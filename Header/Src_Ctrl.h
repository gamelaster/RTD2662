#ifdef __SOURCECTRL__

#if(SOURCE_AUTO_SCAN)
bit bSourceScanEnable   = 0;    // 1 : Start the source auto scan function
                                // 0 : Disable the source auto scan function

unsigned char   idata   ucNext_Source = MASTER_SOURCE;
unsigned char   idata   ucSource_Times  = 0;

#endif

#else


#if(SOURCE_AUTO_SCAN)
extern bit bSourceScanEnable;    // 1 : Start the source auto scan function
                                // 0 : Disable the source auto scan function
#endif


extern bit Source_Control(void);
extern void Change_Source(unsigned char source);

#if(SOURCE_AUTO_SCAN)
extern void Source_Auto_Scan();
#endif

#endif
