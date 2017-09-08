



#define ADC_POWER         0
#define TMDS_POWER        1
#define VDC_POWER         2
#define LVDS_POWER        3


#ifdef __POWERCTRL__

bit bPower_Status       = 0;    // 1 - ON, 0 - OFF
bit bPanel_Status       = 0;
void Set_Panel(unsigned char status);



#else

extern bit bPower_Status;    // 1 - ON, 0 - OFF
extern bit bPanel_Status;

extern void PowerDown_ADC(void);
extern void PowerUp_ADC(void);
extern void PowerDown_VDC(void);
extern void PowerUp_VDC(void);
extern void PowerDown_LVDS(void);
extern void PowerUp_LVDS(void);
extern void PowerDown_TMDS(void);
extern void PowerUp_TMDS(void);

extern void Set_Panel(unsigned char status);
extern bit Power_Control(unsigned char Notify);


#endif

