#ifdef __INITIAL__

void Reset_RTD(void);
void Init_Input_Source(void);

#else

extern void MCU_Init(void);
extern void Firmware_Init(void);
extern void Power_Up_Init(void);
extern void Reset_RTD(void);
extern void Init_Input_Source(void);
extern void Power_Status_Init(void);

#endif
