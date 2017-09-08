//#include "MAIN_DEF.H"

//////////////////////////////////////////////////////////////////
//anson
//////////////////////////////////////////////////////////////////
#define PAGE_NUM		15
#define PAGE_0			0
#define PAGE_1			1
#define PAGE_2			2
#define PAGE_3			3
#define PAGE_4			4
#define PAGE_5			5
#define PAGE_Factory	15		//factory page
//////////////////////////////////////////////////////////////////

#define PAGE1_ITEM_NUM       6
#define PAGE1_ITEM_NONE      0
#define PAGE1_ITEM_CONTRAST  1
#define PAGE1_ITEM_BRIGHT    2
#define PAGE1_ITEM_GAMMA     3
#define PAGE1_ITEM_RGBADJ    4
#define PAGE1_ITEM_AUTOBAL   5
#define PAGE1_ITEM_EXIT      6
#define PAGE1_ITEM_COLORTEMP 7



#define PAGE1B_ITEM_NUM     4
#define PAGE1B_ITEM_NONE    0
#define PAGE1B_ITEM_RED     1
#define PAGE1B_ITEM_GREEN   2
#define PAGE1B_ITEM_BLUE    3
#define PAGE1B_ITEM_EXIT    4

#define PAGE2_ITEM_NUM      6
#define PAGE2_ITEM_NONE     0
#define PAGE2_ITEM_POSH     1
#define PAGE2_ITEM_POSV     2
#define PAGE2_ITEM_SHARP    3
#define PAGE2_ITEM_PHASE    4
#define PAGE2_ITEM_CLOCK    5
#define PAGE2_ITEM_EXIT     6

#define PAGE3_ITEM_NUM      3
#define PAGE3_ITEM_NONE     0
#define PAGE3_ITEM_AUTOCFG  1
#define PAGE3_ITEM_AUTOPOS  4
#define PAGE3_ITEM_AUTOPHA  5
#define PAGE3_ITEM_AUTOCLK  6
#define PAGE3_ITEM_AUTOBAL  2
#define PAGE3_ITEM_EXIT     3

#define PAGE4_ITEM_NUM      6
#define PAGE4_ITEM_NONE     0
#define PAGE4_ITEM_LANGUAGE 1
#define PAGE4_ITEM_OSDH     2
#define PAGE4_ITEM_OSDV     3
#define PAGE4_ITEM_TIMEOUT  4
#define PAGE4_ITEM_TRANSLU  5
#define PAGE4_ITEM_EXIT     6

#define PAGE4B_ITEM_NUM         8
#define PAGE4B_ITEM_NONE        0
#define PAGE4B_ITEM_ENGLISH     1
#define PAGE4B_ITEM_GERMAN      2
#define PAGE4B_ITEM_FRENCH      3
#define PAGE4B_ITEM_ITALIAN     4
#define PAGE4B_ITEM_SPANISH     5
#define PAGE4B_ITEM_CHINESE_T   6
#define PAGE4B_ITEM_CHINESE_S   7
#define PAGE4B_ITEM_JAPANESS    8

///////////////////////////////////////////////////////////////////////////////////////////
//anson
///////////////////////////////////////////////////////////////////////////////////////////
#define PAGEFact_ITEM_NUM			7
#define PAGEFact_ITEM_NONE			0
#define PAGEFact_ITEM_Recall		1
#define PAGEFact_ITEM_Auto_Color	2
#define PAGEFact_ITEM_Contrast		3
#define PAGEFact_ITEM_Brightness	4
#define PAGEFact_ITEM_Spread		5
#define PAGEFact_ITEM_6500K		6
#define PAGEFact_ITEM_EXIT			7

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
#if (AUDIO_TYPE == AUDIO_NONE)

#define PAGE5_ITEM_NUM      4
#define PAGE5_ITEM_NONE     0
#define PAGE5_ITEM_SOURCE   1
#define PAGE5_ITEM_OPTION   2
#define PAGE5_ITEM_RECALL   3
#define PAGE5_ITEM_EXIT     4
#define PAGE5_ITEM_VOLUME   5

#else

#define PAGE5_ITEM_NUM      5
#define PAGE5_ITEM_NONE     0
#define PAGE5_ITEM_SOURCE   1
#define PAGE5_ITEM_OPTION   2
#define PAGE5_ITEM_RECALL   3
#define PAGE5_ITEM_VOLUME   4
#define PAGE5_ITEM_EXIT     5

#endif

#if (TMDS_ENABLE == _FALSE)

#if (VIDEO_CHIP == VDC_NONE)

#define PAGE5B_ITEM_NUM     1
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1

#define PAGE5B_ITEM_DVI     2
#define PAGE5B_ITEM_CVBS    3
#define PAGE5B_ITEM_SV      4
#define PAGE5B_ITEM_YUV     5
#define PAGE5B_ITEM_TV      6

#else   // VIDEO_CHIP != VDC_NONE

#if (VIDEO_CHIP != VDC_SAA7118)

#if (TV_CHIP == TV_NONE)

#define PAGE5B_ITEM_NUM     3
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_CVBS    2
#define PAGE5B_ITEM_SV      3

#define PAGE5B_ITEM_TV      4
#define PAGE5B_ITEM_YUV     5
#define PAGE5B_ITEM_DVI     6

#else

#define PAGE5B_ITEM_NUM     4
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_CVBS    2
#define PAGE5B_ITEM_SV      3
#define PAGE5B_ITEM_TV      4

#define PAGE5B_ITEM_YUV     5
#define PAGE5B_ITEM_DVI     6

#endif

#else   // VIDEO_CHIP == VDC_SAA7118

#if (TV_CHIP == TV_NONE)

#define PAGE5B_ITEM_NUM     4
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_CVBS    2
#define PAGE5B_ITEM_SV      3
#define PAGE5B_ITEM_YUV     4

#define PAGE5B_ITEM_TV      5
#define PAGE5B_ITEM_DVI     6


#else // TV_CHIP != TV_NONE

#define PAGE5B_ITEM_NUM     5
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_CVBS    2
#define PAGE5B_ITEM_SV      3
#define PAGE5B_ITEM_YUV     4
#define PAGE5B_ITEM_TV      5

#define PAGE5B_ITEM_DVI     6

#endif

#endif

#endif

#else   // TMDS_CHIP != TMDS_NONE

#if (VIDEO_CHIP == VDC_NONE)

#define PAGE5B_ITEM_NUM     2
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_DVI     2

#define PAGE5B_ITEM_CVBS    3
#define PAGE5B_ITEM_SV      4
#define PAGE5B_ITEM_YUV     5
#define PAGE5B_ITEM_TV      6

#else   // VIDEO_CHIP != VDC_NONE

#if (VIDEO_CHIP != VDC_SAA7118)

#if (TV_CHIP == TV_NONE)

#define PAGE5B_ITEM_NUM     4
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_DVI     2
#define PAGE5B_ITEM_CVBS    3
#define PAGE5B_ITEM_SV      4

#define PAGE5B_ITEM_TV      5
#define PAGE5B_ITEM_YUV     6


#else

#define PAGE5B_ITEM_NUM     5
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_DVI     2
#define PAGE5B_ITEM_CVBS    3
#define PAGE5B_ITEM_SV      4
#define PAGE5B_ITEM_TV      5

#define PAGE5B_ITEM_YUV     6

#endif

#else   // VIDEO_CHIP == VDC_SAA7118

#if (TV_CHIP == TV_NONE)
#define PAGE5B_ITEM_NUM     5
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_DVI     2
#define PAGE5B_ITEM_CVBS    3
#define PAGE5B_ITEM_SV      4
#define PAGE5B_ITEM_YUV     5

#define PAGE5B_ITEM_TV      6

#else

#define PAGE5B_ITEM_NUM     6
#define PAGE5B_ITEM_NONE    0
#define PAGE5B_ITEM_DSUB    1
#define PAGE5B_ITEM_DVI     2
#define PAGE5B_ITEM_CVBS    3
#define PAGE5B_ITEM_SV      4
#define PAGE5B_ITEM_YUV     5
#define PAGE5B_ITEM_TV      6

#endif

#endif

#endif

#endif

#define PAGEH_ITEM_NUM          7
#define PAGEH_ITEM_NONE         0
#define PAGEH_ITEM_REDGAIN      1
#define PAGEH_ITEM_GREENGAIN    2
#define PAGEH_ITEM_BLUEGAIN     3
#define PAGEH_ITEM_REDOFFSET    4
#define PAGEH_ITEM_GREENOFFSET  5
#define PAGEH_ITEM_BLUEOFFSET   6
#define PAGEH_ITEM_EXIT         7

#define PAGEV_ITEM_NUM          5
#define PAGEV_ITEM_NONE         0
#define PAGEV_ITEM_CONTRAST     1
#define PAGEV_ITEM_BRIGHT       2
#define PAGEV_ITEM_HUE          3
#define PAGEV_ITEM_SATURATION   4
#define PAGEV_ITEM_EXIT         5

#define PAGE_TV_ITEM_SYSTEM   1
#define PAGE_TV_ITEM_CONTRAST 2
#define PAGE_TV_ITEM_BRIGHT   3
#define PAGE_TV_ITEM_SOUND    4
#define PAGE_TV_ITEM_CHANNEL  5
#define PAGE_TV_ITEM_VOLUME   6
#define PAGE_TV_ITEM_AUTOSCAN 7
#define PAGE_TV_ITEM_EXIT     8

