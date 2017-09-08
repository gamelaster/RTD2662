//----------------------------------------------------------------------------------------------------
// ID Code      : HdmiModeTable.h No.0000
// Update Note  : 
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Mode Define
// We have two kind of mode set. One is Preset mode 
// and another is User mode. If you have to add a new
// mode, please add it into "Preset Mode" and modify
// the defination of _MAX_PRESET_MODE.
//--------------------------------------------------
#define _MAX_HDMI_PRESET_MODE            56
/*

#define _MODE_FIRST                 252
#define _MODE_EXIST                 253
#define _MODE_NOSUPPORT             254
#define _MODE_NOSIGNAL              255
*/

//--------------------------------------------------
// Hdmi Preset Mode
//--------------------------------------------------
/*
enum HdmiPresetModeDef
{
    _MODE_640x480P_60HZ = 0,        // Mode 00:
    _MODE_720x240P_60HZ,            // Mode 01:
    _MODE_720x288P_50HZ,            // Mode 02:
    _MODE_720x480P_60HZ,            // Mode 03:
    _MODE_720x480I_60HZ,            // Mode 04:
    _MODE_720x576P_50HZ,            // Mode 05:
    _MODE_720x576I_50HZ,            // Mode 06:
    _MODE_1280x720P_50HZ,           // Mode 07:
    _MODE_1280x720P_60HZ,           // Mode 08:
    _MODE_1440x480P_60HZ,           // Mode 09:
    _MODE_1440x576P_50HZ,           // Mode 10:
    _MODE_1920x1080P_50HZ,          // Mode 11:
    _MODE_1920x1080P_60HZ,          // Mode 12:
    _MODE_1920x1080I_50HZ,          // Mode 13:
    _MODE_1920x1080I_60HZ,          // Mode 14:
    _MODE_2880x240P_60HZ,           // Mode 15:
    _MODE_2880x288P_50HZ,           // Mode 16:
    _MODE_2880x480I_60HZ,           // Mode 17:
    _MODE_2880x576I_50HZ,           // Mode 18:
};
*/
/*
//--------------------------------------------------
// Defination of Mode Detection Tolerance
//--------------------------------------------------
#define _HFREQ_TOLERANCE            10      // kHz. Ex: 1.5kHz ==> 15
#define _VFREQ_TOLERANCE            10      // Hz.  Ex: 1.5Hz ==> 15


//--------------------------------------------------
// Defination of Mode Polarity
//--------------------------------------------------
#define _SYNC_HN_VN                 0x01
#define _SYNC_HP_VN                 0x02
#define _SYNC_HN_VP                 0x04
#define _SYNC_HP_VP                 0x08
*/

#ifdef __MAIN__
#if(_HDMI_EDID == _ON)
BYTE code tHDMI_EDID_DATA[] =
{

    /*4, _NON_AUTOINC,   _DDC_DVI_ENABLE_FD,              0x04,
    4, _NON_AUTOINC,   _DDC_DVI_INDEX_FE,               0x00,
    131, _NON_AUTOINC, _DDC_DVI_ACCESS_PORT_FF,         
    0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,
    0x5A,0x63,0x1C,0xB0,0x01,0x01,0x01,0x01,
    0x01,0x0F,0x01,0x03,0x80,0x26,0x1E,0x78,
    0x2E,0xFD,0x56,0xA5,0x53,0x4A,0x9D,0x24,
    0x14,0x4F,0x54,0xAF,0xEF,0x80,0x81,0x80,
    0x81,0x40,0x71,0x4F,0x31,0x0A,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x30,0x2A,
    0x00,0x98,0x51,0x00,0x2A,0x40,0x30,0x70,
    0x13,0x00,0x78,0x2D,0x11,0x00,0x00,0x1E,
    0x00,0x00,0x00,0xFF,0x00,0x50,0x58,0x58,
    0x30,0x35,0x30,0x31,0x30,0x30,0x30,0x30,
    0x31,0x0A,0x00,0x00,0x00,0xFD,0x00,0x32,
    0x4B,0x1E,0x52,0x0E,0x00,0x0A,0x20,0x20,
    0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,
    0x00,0x56,0x50,0x39,0x32,0x30,0x20,0x53,
    0x65,0x72,0x69,0x65,0x73,0x0A,0x00,0x83,

    4, _NON_AUTOINC,   _DDC_DVI_ENABLE_FD,              0x05,*/


    //4, _NON_AUTOINC,   _DDC_DVI_ENABLE_FD,              0x06,
    //4, _NON_AUTOINC,   _DDC_DVI_INDEX_FE,               0x00,
    //131, _NON_AUTOINC, _DDC_DVI_ACCESS_PORT_FF,         
    /*0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,
    0x2a,0xc3,0x20,0x61,0x01,0x01,0x01,0x01,
    0x00,0x0e,0x01,0x03,0x80,0x45,0x27,0x78,
    0x2a,0x7c,0x11,0x9e,0x59,0x47,0x9b,0x27,
    0x10,0x50,0x54,0x00,0x00,0x00,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x1d,
    0x80,0x18,0x71,0x1c,0x16,0x20,0x58,0x2c,
    0x25,0x00,0xb4,0x86,0x21,0x00,0x00,0x9e,
    0x8c,0x0a,0xd0,0x8a,0x20,0xe0,0x2d,0x10,
    0x10,0x3e,0x96,0x00,0x08,0x86,0x21,0x00,
    0x00,0x18,0x00,0x00,0x00,0xfc,0x00,0x4c,
    0x54,0x2d,0x33,0x32,0x58,0x35,0x37,0x35,
    0x0a,0x20,0x20,0x20,0x00,0x00,0x00,0xfd,
    0x00,0x3b,0x3d,0x0f,0x2e,0x08,0x00,0x0a,
    0x20,0x20,0x20,0x20,0x20,0x20,0x01,0x9a,*/
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
    0x4a, 0x8b, 0x20, 0x61, 0x01, 0x01, 0x01, 0x01, 
    0x00, 0x0e, 0x01, 0x03, 0x80, 0x45, 0x27, 0x78, 
    0x2a, 0x7c, 0x11, 0x9e, 0x59, 0x47, 0x9b, 0x27, 
    0x10, 0x50, 0x54, 0x00, 0x00, 0x00, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1d, 
    0x80, 0x18, 0x71, 0x1c, 0x16, 0x20, 0x58, 0x2c, 
    0x25, 0x00, 0xb4, 0x86, 0x21, 0x00, 0x00, 0x9e, 
    0x8c, 0x0a, 0xd0, 0x8a, 0x20, 0xe0, 0x2d, 0x10, 
    0x10, 0x3e, 0x96, 0x00, 0x08, 0x86, 0x21, 0x00, 
    0x00, 0x18, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x4c, 
    0x54, 0x2d, 0x33, 0x32, 0x58, 0x35, 0x37, 0x35, 
    0x0a, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xfd, 
    0x00, 0x3b, 0x3d, 0x0f, 0x2e, 0x08, 0x00, 0x0a, 
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0xb2, 

   //131, _NON_AUTOINC, _DDC_DVI_ACCESS_PORT_FF,         
    /*0x02,0x03,0x1a,0x72,0x47,0x85,0x02,0x03,
    0x04,0x01,0x06,0x07,0x23,0x09,0x07,0x07,
    0x83,0x01,0x00,0x00,0x65,0x03,0x0c,0x00,
    0x10,0x00,0x01,0x1d,0x00,0x72,0x51,0xd0,
    0x1e,0x20,0x6e,0x28,0x55,0x00,0xb4,0x86,
    0x21,0x00,0x00,0x1e,0xd6,0x09,0x80,0xa0,
    0x20,0xe0,0x2d,0x10,0x10,0x60,0xa2,0x00,
    0x08,0x86,0x21,0x00,0x00,0x18,0x8c,0x0a,
    0xd0,0x8a,0x20,0xe0,0x2d,0x10,0x10,0x3e,
    0x96,0x00,0xb4,0x86,0x21,0x00,0x00,0x18,
    0x8c,0x0a,0xa0,0x14,0x51,0xf0,0x16,0x00,
    0x26,0x7c,0x43,0x00,0x08,0x86,0x21,0x00,
    0x00,0x98,0x8c,0x0a,0xa0,0x14,0x51,0xf0,
    0x16,0x00,0x26,0x7c,0x43,0x00,0xb4,0x86,
    0x21,0x00,0x00,0x98,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,*/
    0x02, 0x03, 0x1a, 0x72, 0x47, 0x85, 0x02, 0x03, 
    0x04, 0x01, 0x06, 0x07, 0x23, 0x09, 0x07, 0x07, 
    0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0c, 0x00, 
    0x10, 0x00, 0x01, 0x1d, 0x00, 0x72, 0x51, 0xd0, 
    0x1e, 0x20, 0x6e, 0x28, 0x55, 0x00, 0xb4, 0x86, 
    0x21, 0x00, 0x00, 0x1e, 0xd6, 0x09, 0x80, 0xa0, 
    0x20, 0xe0, 0x2d, 0x10, 0x10, 0x60, 0xa2, 0x00, 
    0x08, 0x86, 0x21, 0x00, 0x00, 0x18, 0x8c, 0x0a, 
    0xd0, 0x8a, 0x20, 0xe0, 0x2d, 0x10, 0x10, 0x3e, 
    0x96, 0x00, 0xb4, 0x86, 0x21, 0x00, 0x00, 0x18, 
    0x8c, 0x0a, 0xa0, 0x14, 0x51, 0xf0, 0x16, 0x00, 
    0x26, 0x7c, 0x43, 0x00, 0x08, 0x86, 0x21, 0x00, 
    0x00, 0x98, 0x8c, 0x0a, 0xa0, 0x14, 0x51, 0xf0, 
    0x16, 0x00, 0x26, 0x7c, 0x43, 0x00, 0xb4, 0x86, 
    0x21, 0x00, 0x00, 0x98, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 

    //4, _NON_AUTOINC,   _DDC_DVI_ENABLE_FD,              0x07,

    //_END
};
#endif//End of #if(_HDMI_EDID == _ON)
/*
ModeTableType code tINPUTMODE_PRESET_TABLE[_MAX_PRESET_MODE] =
{
    //--------------------------------------------------
    // Preset Modes
    //--------------------------------------------------
    {   // Mode 0 : 640 x 350 x 70 Hz
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        640, 350,                                                           // InputWidth, InputHeight,
        315, 700,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        800, 449,                                                           // IHTotal, IVTotal,
        144, 62,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 1 : 640 x 350 x 85 Hz
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        640, 350,                                                           // InputWidth, InputHeight,
        378, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE + 5, _VFREQ_TOLERANCE + 5,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        832, 445,                                                           // IHTotal, IVTotal,
        160, 63,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 2 : 720 x 400 x 70 Hz
        //0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        0 | _SYNC_HN_VP | _SYNC_HP_VP | _SYNC_HN_VN,                        // Polarity Flags,
        720, 400,                                                           // InputWidth, InputHeight,
        315, 700,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        900, 449,                                                           // IHTotal, IVTotal,
        162, 37,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 3 : 720 x 400 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        720, 400,                                                           // InputWidth, InputHeight,
        380, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE + 5, _VFREQ_TOLERANCE + 5,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        936, 446,                                                           // IHTotal, IVTotal,
        180, 45,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 4 : 640 x 480 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        315, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        800, 525,                                                           // IHTotal, IVTotal,
        144, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 5 : 640 x 480 x 66 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        350, 666,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        864, 525,                                                           // HTotal, VTotal,
        160, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 6 : 640 x 480 x 72 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        378, 728,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        832, 520,                                                           // HTotal, VTotal,
        168, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 7 : 640 x 480 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        375, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        840, 500,                                                           // IHTotal, IVTotal,
        184, 19,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 8 : 640 x 480 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        640, 480,                                                           // InputWidth, InputHeight,
        433, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        832, 510,                                                           // IHTotal, IVTotal,
        136, 28,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 9 : 800 x 600 x 56 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        351, 562,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1024, 625,                                                          // HTotal, VTotal,
        200, 24,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 10 : 800 x 600 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        378, 603,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1056, 628,                                                          // IHTotal, IVTotal,
        216, 27,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 11 : 800 x 600 x 72 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        480, 720,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1040, 666,                                                          // HTotal, VTotal,
        184, 29,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 12 : 800 x 600 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        468, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1056, 625,                                                          // IHTotal, IVTotal,
        240, 24,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 13 : 800 x 600 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        800, 600,                                                           // InputWidth, InputHeight,
        536, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1048, 631,                                                          // IHTotal, IVTotal,
        216, 30,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 14 : 832 x 624 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        832, 624,                                                           // InputWidth, InputHeight,
        497, 745,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1152, 667,                                                          // IHTotal, IVTotal,
        288, 42,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 15 : 1024 x 768 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        483, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1344, 806,                                                          // IHTotal, IVTotal,
        296, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 16 : 1024 x 768 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        564, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1328, 806,                                                          // HTotal, VTotal,
        280, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 17 : 1024 x 768 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        600, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1312, 800,                                                          // IHTotal, IVTotal,
        272, 31,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 18 : 1024 x 768 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1024, 768,                                                          // InputWidth, InputHeight,
        682, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1376, 808,                                                          // IHTotal, IVTotal,
        304, 39,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 19 : 1024 x 800 x 73 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1024, 800,                                                          // InputWidth, InputHeight,
        620, 740,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1328, 837,                                                          // IHTotal, IVTotal,
        264, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 20 : 1024 x 800 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1024, 800,                                                          // InputWidth, InputHeight,
        715, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1320, 837,                                                          // IHTotal, IVTotal,
        280, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 21 : 1152 x 864 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        537, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1512, 894,                                                          // HTotal, VTotal,
        300, 30,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 22 : 1152 x 864 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        642, 702,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1472, 914,                                                          // HTotal, VTotal,
        288, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 23 : 1152 x 864 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        675, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1600, 900,                                                          // IHTotal, IVTotal,
        384, 35,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 24 : 1152 x 864 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 864,                                                          // InputWidth, InputHeight,
        770, 850,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1576, 907,                                                          // HTotal, VTotal,
        360, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 25 : 1152 x 870 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 870,                                                          // InputWidth, InputHeight,
        686, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1456, 915,                                                          // HTotal, VTotal,
        272, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 26 : 1152 x 900 x 66 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 900,                                                          // InputWidth, InputHeight,
        618, 660,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1528, 937,                                                          // HTotal, VTotal,
        336, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 27 : 1152 x 900 x 76 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1152, 900,                                                          // InputWidth, InputHeight,
        718, 766,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1504, 937,                                                          // HTotal, VTotal,
        320, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 28 : 1280 x 720 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 720,                                                          // InputWidth, InputHeight,
        447, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1656, 746,                                                          // HTotal, VTotal,
        339, 25,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 29 : 1280 x 720 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 720,                                                          // InputWidth, InputHeight,
        564, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1688, 751,                                                          // HTotal, VTotal,
        340, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 30 : 1280 x 768 x 60 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1280, 768,                                                          // InputWidth, InputHeight,
        477, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1668, 794,                                                          // HTotal, VTotal,
        332, 26,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 31 : 1280 x 768 x 70 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1280, 768,                                                          // InputWidth, InputHeight,
        560, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1692, 799,                                                          // HTotal, VTotal,
        336, 31,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 32 : 1280 x 768 x 75 Hz
        0 | _SYNC_HN_VP,                                                    // Polarity Flags,
        1280, 768,                                                          // InputWidth, InputHeight,
        601, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1706, 801,                                                          // HTotal, VTotal,
        346, 33,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 33 : 1280 x 960 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 960,                                                          // InputWidth, InputHeight,
        600, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1800, 1000,                                                         // IHTotal, IVTotal,
        424, 39,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 34 : 1280 x 960 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 960,                                                          // InputWidth, InputHeight,
        750, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1680, 1000,                                                         // HTotal, VTotal,
        368, 39,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 35 : 1280 x 960 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 960,                                                          // InputWidth, InputHeight,
        860, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1728, 1011,                                                         // IHTotal, IVTotal,
        384, 50,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 36 : 1280 x 1024 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        640, 600,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1688, 1066,                                                         // IHTotal, IVTotal,
        360, 41,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 37 : 1280 x 1024 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        746, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1722, 1065,                                                         // HTotal, VTotal,
        359, 40,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 38 : 1280 x 1024 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        800, 750,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1688, 1066,                                                         // IHTotal, IVTotal,
        392, 41,                                                            // IHStartPos, IVStartPos,
    },

    {   // Mode 39 : 1280 x 1024 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1280, 1024,                                                         // InputWidth, InputHeight,
        911, 850,                                                           // IHFreq in kHz, IVFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // IHFreqTolerance in kHz, IVFreqTolerance in Hz,
        1728, 1072,                                                         // IHTotal, IVTotal,
        384, 47,                                                            // IHStartPos, IVStartPos,
    },

   {   // Mode 40 : 1440 x 900 x 60 Hz
        0 | _SYNC_HN_VP | _SYNC_HN_VN | _SYNC_HP_VP,                        // Polarity Flags,
        1440, 900,                                                          // InputWidth, InputHeight,
        559, 598,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1904, 934,                                                          // HTotal, VTotal,
        384, 31,                                                            // HStartPos, VStartPos,
    },

 
    {   // Mode 41 : 1440 x 900 x 60 Hz  (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1440, 900,                                                          // InputWidth, InputHeight,
        557, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1600, 926,                                                          // HTotal, VTotal,
        112, 23,                                                            // HStartPos, VStartPos,
    },
 
    {   // Mode 42 : 1440 x 900 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1440, 900,                                                          // InputWidth, InputHeight,
        706, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1936, 942,                                                          // HTotal, VTotal,
        400, 39,                                                            // HStartPos, VStartPos,
    },
 
    {   // Mode 43 : 1600 x 1200 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        750, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 44 : 1600 x 1200 x 65 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        812, 650,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 45 : 1600 x 1200 x 70 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        875, 700,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 46 : 1600 x 1200 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        937, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 47 : 1600 x 1200 x 85 Hz
        0 | _SYNC_HN_VN | _SYNC_HP_VN | _SYNC_HN_VP | _SYNC_HP_VP,          // Polarity Flags,
        1600, 1200,                                                         // InputWidth, InputHeight,
        1062, 850,                                                          // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1250,                                                         // HTotal, VTotal,
        496, 49,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 48 : 1680 x 1050 x 60 Hz
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        653, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2240, 1089,                                                         // HTotal, VTotal,
        456, 36,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 49 : 1680 x 1050 x 60 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        647, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2160, 1080,                                                         // HTotal, VTotal,
        112, 27,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 50 : 1680 x 1050 x 75 Hz
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        823, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2272, 1099,                                                         // HTotal, VTotal,
        472, 46,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 51 : 1680 x 1050 x 75 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1680, 1050,                                                         // InputWidth, InputHeight,
        815, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        1840, 1088,                                                         // HTotal, VTotal,
        112, 35,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 52 : 1920 x 1200 x 60 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1920, 1200,                                                         // InputWidth, InputHeight,
        746, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2592, 1245,                                                         // HTotal, VTotal,
        536, 42,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 53 : 1920 x 1200 x 60 Hz (Reduced Blanking)
        0 | _SYNC_HP_VN,                                                    // Polarity Flags,
        1920, 1200,                                                         // InputWidth, InputHeight,
        740, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2080, 1235,                                                         // HTotal, VTotal,
        112, 32,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 54 : 1920 x 1200 x 75 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1920, 1200,                                                         // InputWidth, InputHeight,
        940, 750,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2608, 1255,                                                         // HTotal, VTotal,
        552, 52,                                                            // HStartPos, VStartPos,
    },

    {   // Mode 55 : 1920 x 1440 x 60 Hz 
        0 | _SYNC_HN_VN | _SYNC_HN_VP | _SYNC_HP_VP,                        // Polarity Flags,
        1920, 1440,                                                         // InputWidth, InputHeight,
        900, 600,                                                           // HFreq in kHz, VFreq in Hz,
        _HFREQ_TOLERANCE, _VFREQ_TOLERANCE,                                 // HFreqTolerance in kHz, VFreqTolerance in Hz,
        2600, 1500,                                                         // HTotal, VTotal,
        552, 59,                                                            // HStartPos, VStartPos,
    },
};
*/
#if(_DISP_INFO_BY_MODE == _ON)

DisplayTableType code tDISPLAY_PRESET_TABLE[_MAX_PRESET_MODE] =
{
    //--------------------------------------------------
    // Preset Modes
    //--------------------------------------------------
    {   // Mode 0 : 640 x 350 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 1 : 640 x 350 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 2 : 720 x 400 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 3 : 720 x 400 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 4 : 640 x 480 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 5 : 640 x 480 x 66 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 6 : 640 x 480 x 72 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 7 : 640 x 480 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 8 : 640 x 480 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 9 : 800 x 600 x 56 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 10 : 800 x 600 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 11 : 800 x 600 x 72 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 12 : 800 x 600 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 13 : 800 x 600 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 14 : 832 x 624 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 15 : 1024 x 768 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 16 : 1024 x 768 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 17 : 1024 x 768 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 18 : 1024 x 768 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 19 : 1024 x 800 x 73 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 20 : 1024 x 800 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 21 : 1152 x 864 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 22 : 1152 x 864 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 23 : 1152 x 864 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 24 : 1152 x 864 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 25 : 1152 x 870 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 26 : 1152 x 900 x 66 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 27 : 1152 x 900 x 76 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 28 : 1280 x 720 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 29 : 1280 x 720 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 30 : 1280 x 768 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 31 : 1280 x 768 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 32 : 1280 x 768 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 33 : 1280 x 960 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 34 : 1280 x 960 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 35 : 1280 x 960 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 36 : 1280 x 1024 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 37 : 1280 x 1024 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 38 : 1280 x 1024 x 75 Hz
        1512,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 39 : 1280 x 1024 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 40 : 1440 x 900 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 41 : 1440 x 900 x 60 Hz (Reduced Blanking)
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 42 : 1440 x 900 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 43 : 1600 x 1200 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 44 : 1600 x 1200 x 65 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 45 : 1600 x 1200 x 70 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 46 : 1600 x 1200 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 47 : 1600 x 1200 x 85 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 48 : 1680 x 1050 x 60 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 49 : 1680 x 1050 x 60 Hz (Reduced Blanking)
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 50 : 1680 x 1050 x 75 Hz
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },

    {   // Mode 51 : 1680 x 1050 x 75 Hz (Reduced Blanking)
        1408,                                                               // DHTotal,
        1280, 1024,                                                         // DHWidth, DVHeight,
    },
};

#endif  // End of #if(_DHTOTAL_BY_MODE == _ON)

#else
#if(_HDMI_EDID == _ON)
extern BYTE code tHDMI_EDID_DATA[];
#endif //End of #if(_HDMI_EDID == _ON)
extern ModeTableType code tINPUTMODE_PRESET_TABLE[_MAX_PRESET_MODE];

#if(_DISP_INFO_BY_MODE == _ON)

extern DisplayTableType code tDISPLAY_PRESET_TABLE[_MAX_PRESET_MODE];

#endif

#endif
