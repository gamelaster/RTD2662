// These are common messages.
// You can define other messages for your need, but you should confirm 
// your OSD process can respond with your messages.
#define NOTIFY_NONE         0x00
#define NOTIFY_MENU_KEY     0x01
#define NOTIFY_ENTER_KEY    0x02
#define NOTIFY_RIGHT_KEY    0x03
#define NOTIFY_LEFT_KEY     0x04
//echo modify begin ... 2004.03.17
  #define NOTIFY_AUTO_KEY     0x05
//echo modify end;
#define NOTIFY_EXIT_KEY     0x06
#define NOTIFY_LR_KEY       0x08    // Issued when no OSD on display and an user presses left and right key

#define NOTIFY_FACTORY_KEY 	0x09 			//anson


#define NOTIFY_IR_NUM0      0x10
#define NOTIFY_IR_NUM1      0x11
#define NOTIFY_IR_NUM2      0x12
#define NOTIFY_IR_NUM3      0x13
#define NOTIFY_IR_NUM4      0x14
#define NOTIFY_IR_NUM5      0x15
#define NOTIFY_IR_NUM6      0x16
#define NOTIFY_IR_NUM7      0x17
#define NOTIFY_IR_NUM8      0x18
#define NOTIFY_IR_NUM9      0x19
#define NOTIFY_IR_SOURCE    0x1a
#define NOTIFY_IR_DISP      0x1b
#define NOTIFY_IR_JUMP      0x1c
#define NOTIFY_IR_CHDEC     0x1d
#define NOTIFY_IR_CHINC     0x1e
#define NOTIFY_IR_VOLINC    0x1f
#define NOTIFY_IR_VOLDEC    0x20
#define NOTIFY_IR_MENU      0x21
#define NOTIFY_IR_ENTER     0x22
#define NOTIFY_IR_MUTE      0x23


#define NOTIFY_POWERUP      0x80
#define NOTIFY_POWERDOWN    0x81

#define NOTIFY_CLEAR_OSD    0x82
#define NOTIFY_SHOW         0x83    // Issued by main program, not by Key_Trans()

// Key_Trans() issues the first message for a button right after you press it.
// If you keep pressing a button down for (KEY_REPEAT_COUNT * 20ms), Key_Trans() will
// issues the same messages in the period of (KEY_REPEAT_PERIOD * 20ms).
// Not all keys need this feature. You should decide by yourself.
#define KEY_REPEAT_COUNT    15
#define KEY_REPEAT_PERIOD   1
#define KEY_TURBO_ENABLE    15


#ifdef __MESSAGE__

unsigned char idata ucKey_Issued    = 0;
bit bKeyTurbo   = 0;						//anson

unsigned char Key_Trans();
void OSD_Dispatcher(unsigned char message);

#else

extern unsigned char idata  ucKey_Issued;
extern bit bKeyTurbo;						//anson

extern unsigned char Key_Trans();
extern void OSD_Dispatcher(unsigned char message);

#endif

