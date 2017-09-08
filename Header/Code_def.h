///////////////////////////////////////////////////////////////////
// Definitions for RTD read/write mode
#define READ        1
#define WRITE       0
 
#define Y_INC       0
#define N_INC       1
#define BURST       2   // Only valid for writing data to RTD by RTDWrite() or RTDCodeW()

///////////////////////////////////////////////////////////////////
// Definitions for input source select
#define SOURCE_VGA      0
#define SOURCE_DVI      1
#define SOURCE_AV       2
#define SOURCE_SV       3
#define SOURCE_YUV      4
#define SOURCE_TV       5
#define SOURCE_MAX      SOURCE_DVI

///////////////////////////////////////////////////////////////////
// Definitions for Sync type select
#define SYNC_SS         0x00
#define SYNC_CS         0x10
#define SYNC_SOG        0x20

///////////////////////////////////////////////////////////////////
// Definitions for OSD language select
#define ENGLISH     0
#define GERMAN      1
#define FRENCH      2
#define ITALIAN     3
#define SPANISH     4
#define CHINESE_T   5
#define CHINESE_S   6
#define JAPANESS    7
