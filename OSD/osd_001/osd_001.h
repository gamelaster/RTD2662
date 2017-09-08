#if(_001_OSD)
//#define _OSD_001_

//void COsdFacHandler();
void Draw001Menu(void);
void M001MenuAdj(BYTE ucMode);
void M001Proc(void);
void Exit001Menu(void);
//--------------------------
void DrawBrightnessMenu(void);
void DrawContrastMenu(void);
void DrawSaturationMenu(void);
void DrawHueMenu(void);
void DrawSourceA1A2Menu(void);
void DrawLeftRightChangeMenu();
void DrawUpDownChangeMenu();		
void DrawDisplayRadioMenu();

void DrawVolumeMenu(void);
void DrawResetMenu(void);
void DrawExitMenu(void);
//--------------------------
void Draw001MenuItem(BYTE ucItem,BYTE ucState);
void Adjust001Contrast(BYTE ucMode);
void Adjust001Brightness(BYTE ucMode);
void Adjust001Hue(BYTE ucMode);
void Adjust001Saturation(BYTE ucMode);
void Adjust001Source(BYTE ucMode);

void Adjust001LeftRight(ucMode);
void Adjust001UpDown(ucMode);
void Adjust001DisplayRatio(ucMode);
//void Adjust001Volume(BYTE ucMode);
void M001ValueAdj(BYTE ucMode);
void OSDSlider1(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color);
void CShowNumber2(const WORD ucNumber, BYTE ucUserDefLong);

extern void Draw001Menu(void);
extern void Draw001MainMenu(void);
extern void Exit001Menu(void);
extern void M001Proc(void);


void MainMenuItemPro(void);
void ResetItemProc();
void ResetAdjustLeftRight(BYTE LR);
void ResetMenuProc(void);


//#endif

#endif  //#if(FACTORY_MENU_EN)
