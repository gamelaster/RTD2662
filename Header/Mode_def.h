///////////////////////////////////////////////////////////////////
// Definitions for input resolution
#define MODE_VGA350x50Hz        1   // VGA350-50Hz (640x350/720x350-50Hz)
#define MODE_VGA400x50Hz        2   // VGA400-50Hz (640x400/720x400-50Hz)
#define MODE_VGA350x60Hz        3   // VGA350-60Hz (640x350/720x350-60Hz)
#define MODE_VGA400x60Hz        4   // VGA400-60Hz (640x400/720x400-60Hz)

#define MODE_0640x0400x56HZ     5   // NEC
#define MODE_0640x0350x70HZ     6   // VGA 350-70
#define MODE_0720x0350x70HZ     7   // VGA-TEXT 350-70
#define MODE_0640x0400x70HZ     8   // VGA 400-70
#define MODE_0720x0400x70HZ     9   // VGA-TEXT 400-70
#define MODE_0640x0350x85HZ     10  // VESA
#define MODE_0640x0400x85HZ     11  // VESA
#define MODE_0720x0400x85HZ     12  // VESA
#define MODE_0640x0480x50HZ     13  // VGA
#define MODE_0640x0480x60HZ     14  // VESA
#define MODE_0640x0480x66HZ     15  // MAC 480-66A
#define MODE_0640x0480x72HZ     16  // VESA
#define MODE_0640x0480x75HZ     17  // VESA
#define MODE_0640x0480x85HZ     18  // VESA
#define MODE_0800x0600x56HZ     19  // VESA
#define MODE_0800x0600x60HZ     20  // VESA
#define MODE_0800x0600x66HZ     21  // MAC 600-66
#define MODE_0800x0600x72HZ     22  // VESA
#define MODE_0800x0600x75HZ     23  // VESA
#define MODE_0800x0600x85HZ     24  // VESA
#define MODE_0832x0624x75HZ     25  // MAC 624-57
#define MODE_1024x0768x60HZ     26  // VESA
#define MODE_1024x0768x59HZ     27  // MAC768-60
#define MODE_1024x0768x66HZ     28  // COMPAQ 1024
#define MODE_1024x0768x70HZ     29  // VESA
#define MODE_1024x0768x72HZ     30  // VESA		//anson 05_0321 add
#define MODE_1024x0768x74HZ     31  // MAC 768-75
#define MODE_1024x0768x75HZ     32  // VESA
#define MODE_1024x0768x85HZ     33  // VESA
#define MODE_1024x0800x84HZ     34  // SUN 800-84
#define MODE_1152x0864x75HZ     35  // VESA
#define MODE_1152x0870x75HZ     36  // MAC 870-75
#define MODE_1152x0900x66HZ     37  // SUN 900-66
#define MODE_1152x0900x76HZ     38  // SUN 900-76
#define MODE_1280x0960x60HZ     39  // VESA
#define MODE_1280x0960x85HZ     40  // VESA
#define MODE_1280x1024x60HZ     41  // VESA
#define MODE_1280x1024x72HZ     42  // WS-SGI
#define MODE_1280x1024x76HZ     43  // SUN 1024-76
#define MODE_1280x1024x75HZ     44  // VESA
#define MODE_1280x1024x85HZ     45  // VESA
#define MODE_1600x1200x60HZ     46  // VESA

#define MODE_RESERVED_00        47  // Reserved VGA mode for future use
#define MODE_RESERVED_01        48  // Reserved VGA mode for future use
#define MODE_RESERVED_02        49  // Reserved VGA mode for future use
#define MODE_RESERVED_03        50  // Reserved VGA mode for future use

#define MODE_USER720x400        51  // User Mode 720x400
#define MODE_USER640x480        52  // User Mode 640x480
#define MODE_USER800x600        53  // User Mode 800x600
#define MODE_USER1024x768       54  // User Mode 1024x768
#define MODE_USER1152x864       55  // User Mode 1152x864
#define MODE_USER1152x900       56  // User Mode 1152x900
#define MODE_USER1280x960       57  // User Mode 1280x960
#define MODE_USER1280x1024      58  // User Mode 1280x1024
#define MODE_USER1600x1200      59  // User Mode 1600x1200

#define MODE_UNDEFINED0         60  // Used for save-mode
#define MODE_UNDEFINED1         61  // Used for save-mode

#define MODE_VIDEO60HZ          62  // Video Mode 60Hz for AV/S-Video
#define MODE_VIDEO50HZ          63  // Video Mode 50Hz for AV/S-Video
#define MODE_YUV60HZ            64  // Video Mode 60Hz for YUV
#define MODE_YUV50HZ            65  // Video Mode 50Hz for YUV

#define MODE_NOSIGNAL           0   // No signal
#define MODE_OSDFORCE           254 // Force to reset display by OSD
#define MODE_NOSUPPORT          255 // Signal out of range

/*
#define VGA_MODE_NUM            56
#define VIDEO_MODE_NUM          4
*/
