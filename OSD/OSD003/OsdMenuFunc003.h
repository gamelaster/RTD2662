#if(_OSD_TYPE == _OSD003)


#ifdef __OSDDRAW003__

#else

#endif


// extand function & Var
bit CEnable(void);
bit CDisable(void);	

bit CVideoEnable(void);
bit CVideoNTSCEnable(void);
bit CVgaEnable(void);
bit CHDMIEnable(void);
bit CDviEnable(void);
bit CTVEnable(void);

bit CMIVgaEnable(void);
bit CMIDVIEnable(void);
bit CMIHDMIEnable(void);
bit CMIYPBPREnable(void);
bit CMISVEnable(void);
bit CMIAVEnable(void);
bit CMITVEnable(void);

bit CEngEnable(void);
bit CCHI_S_Enable(void);
bit CFRA_Enable(void);
bit CITA_Enable(void);
bit CDEU_Enable(void);
bit CESP_Enable(void);
bit CCHI_T_Enable(void);
bit CJAP_Enable(void);
bit CKOR_Enable(void);
bit CRUS_Enable(void);

bit CEnNtsc_M(void);
bit CEnNtsc_BG(void);
bit CEnNtsc_DK(void);
bit CEnNtsc_I(void);
bit CEnPal_M(void);
bit CEnPal_BG(void);
bit CEnPal_DK(void);
bit CEnPal_I(void);
bit CEnPal_N(void);
bit CEnSecam_BG(void);
bit CEnSecam_DK(void);
bit CEnSecam_L(void);
bit CEnSecam_LL(void);
bit COSDDoubleEN(void);

//void CShowReset(void);
extern void CShowVGAMode(BYTE x,BYTE y);
extern void CShowMode(BYTE x,BYTE y);

extern void InitMainOsd(void);
extern void DrawMainMenuItem(BYTE ucItem,BYTE ucState);
extern void DrawMainItemTitle(BYTE ucItem);
extern void DrawMainMenu(void);
extern void DrawColorPage(void);
extern void DrawAdjustPage(void);
extern void DrawOSDPage(void);
extern void DrawTVPage(void);
extern void DrawFuncPage(void);
extern void DrawSoundPage(void);
extern void DrawSubMenu(BYTE ucPageIndex);


// Extent function define
extern bit MDisplayRatioEnable(void);
extern bit MSoundEnable(void);
extern bit MNJW1144Enable(void);

extern void MMenuNoneProc(void);
extern void MMenuNoneEnterSubMenu(void);
//---------------------------------------------------------------------------
// MainMenu
extern void MMainMenuProc(void);
extern void MMainMenuValueAdj(BYTE ucMode);
extern void MMainMenuMenuAdj(BYTE ucMode);
extern void MMainMenuEnterSubMenu(void);
extern void MMainMenuReturnUpMenu(void);
//---------------------------------------------------------------------------
// Color
extern void MColorProc(void);
extern void MColorValueAdj(BYTE ucMode);
extern void MColorMenuAdj(BYTE ucMode);
extern void MColorEnterSubMenu(void);
extern void MColorReturnUpMenu(void);
//---------------------------------------------------------------------------
// Brightness Adjust
extern void MBrightnessProc(void);
extern void MBrightnessValueAdj(BYTE ucMode);
extern void MBrightnessReturnUpMenu(void);
//---------------------------------------------------------------------------
// Contrast Adjust
extern void MContrastProc(void);
extern void MContrastValueAdj(BYTE ucMode);
extern void MContrastReturnUpMenu(void);
//---------------------------------------------------------------------------
// Hue Adjust
extern void MHueProc(void);
extern void MHueValueAdj(BYTE ucMode);
extern void MHueReturnUpMenu(void);
//---------------------------------------------------------------------------
// Saturation Adjust
extern void MSaturationProc(void);
extern void MSaturationValueAdj(BYTE ucMode);
extern void MSaturationReturnUpMenu(void);
//---------------------------------------------------------------------------
// ColorTemp
extern void EnterColorTempMenu(void);
extern void MColorTempProc(void);
extern void MColorTempValueAdj(BYTE ucMode);
extern void MColorTempMenuAdj(BYTE ucMode);
extern void MColorTempEnterSubMenu(void);
extern void MColorTempReturnUpMenu(void);
//---------------------------------------------------------------------------
// ColorTemp User
void DrawColorUSERMenuItem(BYTE ucItem,BYTE ucState);
void EnterColorTempUserMenu(void);
void ClearColorUSERMenu(void);
void MColorUserProc(void);
void MColorUserValueAdj(BYTE ucMode);
void MColorUserMenuAdj(BYTE ucMode);
void MColorUserReturnUpMenu(void);
void MColorUserEnterSubMenu(void);
void ColorRAdjust(BYTE ucMode);
void ColorGAdjust(BYTE ucMode);
void ColorBAdjust(BYTE ucMode);

extern void MRProc(void);
extern void MRValueAdj(BYTE ucMode);
extern void MRReturnUpMenu(void);
extern void MGProc(void);
extern void MGValueAdj(BYTE ucMode);
extern void MGReturnUpMenu(void);
extern void MBProc(void);
extern void MBValueAdj(BYTE ucMode);
extern void MBReturnUpMenu(void);

//---------------------------------------------------------------------------
// Adjust
extern void MAdjustProc(void);
extern void MAdjustValueAdj(BYTE ucMode);
extern void MAdjustMenuAdj(BYTE ucMode);
extern void MAdjustEnterSubMenu(void);
extern void MAdjustReturnUpMenu(void);
//---------------------------------------------------------------------------
// AutoAdjust
extern void EnterAutoConfigMenu(void);
extern void MAutoAdjustProc(void);
extern void MAutoAdjustValueAdj(BYTE ucMode);
extern void MAutoAdjustMenuAdj(BYTE ucMode);
extern void MAutoAdjustEnterSubMenu(void);
extern void MAutoAdjustReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\H Position Adjust
extern void MAdjustHPositionProc(void);
extern void MAdjustHPositionValueAdj(BYTE ucMode);
extern void MAdjustHPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\V Position Adjust
extern void MAdjustVPositionProc(void);
extern void MAdjustVPositionValueAdj(BYTE ucMode);
extern void MAdjustVPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\Phase Adjust
extern void MAdjustPhaseProc(void);
extern void MAdjustPhaseValueAdj(BYTE ucMode);
extern void MAdjustPhaseReturnUpMenu(void);
//---------------------------------------------------------------------------
// Adjust\\Clock Adjust
extern void MAdjustClockProc(void);
extern void MAdjustClockValueAdj(BYTE ucMode);
extern void MAdjustClockReturnUpMenu(void);
//---------------------------------------------------------------------------
// OSD
extern void MOSDProc(void);
extern void MOSDValueAdj(BYTE ucMode);
extern void MOSDMenuAdj(BYTE ucMode);
extern void MOSDEnterSubMenu(void);
extern void MOSDReturnUpMenu(void);
//---------------------------------------------------------------------------
// Language
extern void EnterLanguageMenu(void);
extern void MLanguageProc(void);
extern void MLanguageValueAdj(BYTE ucMode);
extern void MLanguageMenuAdj(BYTE ucMode);
extern void MLanguageEnterSubMenu(void);
extern void MLanguageReturnUpMenu(void);
//---------------------------------------------------------------------------
// HPosition Adjust
extern void MHPositionProc(void);
extern void MHPositionValueAdj(BYTE ucMode);
extern void MHPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// VPosition Adjust
extern void MVPositionProc(void);
extern void MVPositionValueAdj(BYTE ucMode);
extern void MVPositionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Timer
extern void MTimerProc(void);
extern void MTimerAdjValue(BYTE ucMode);
extern void MTimerReturnUpMenu(void);
//---------------------------------------------------------------------------
// Transparent
extern void MTransparentProc(void);
extern void MTransparentReturnUpMenu(void);
//---------------------------------------------------------------------------
// Double
extern void EnterDoubleMenu(void);
extern void MDoubleProc(void);
extern void MDoubleValueAdj(BYTE ucMode);
extern void MDoubleMenuAdj(BYTE ucMode);
extern void MDoubleEnterSubMenu(void);
extern void MDoubleReturnUpMenu(void);
//---------------------------------------------------------------------------
// OSD H/V position
extern void COSDHPositionAdj(BYTE ucMode);
extern void COSDVPositionAdj(BYTE ucMode);
//---------------------------------------------------------------------------
// Transparent
extern void CTransparentAdj(BYTE ucMode);
//---------------------------------------------------------------------------
// TV
extern void MTVProc(void);
extern void MTVValueAdj(BYTE ucMode);
extern void MTVMenuAdj(BYTE ucMode);
extern void MTVEnterSubMenu(void);
extern void MTVReturnUpMenu(void);

extern void MChannelProc(void);
extern void MChannelReturnUpMenu(void);
//---------------------------------------------------------------------------
// System
extern void EnterSystemMenu(void);
extern void MSystemProc(void);
extern void MSystemValueAdj(BYTE ucMode);
extern void MSystemMenuAdj(BYTE ucMode);
extern void MSystemEnterSubMenu(void);
extern void MSystemReturnUpMenu(void);
//---------------------------------------------------------------------------
// AutoSearch
extern void EnterAutoSearchMenu(void);
extern void MAutoSearchProc(void);
extern void MAutoSearchValueAdj(BYTE ucMode);
extern void MAutoSearchMenuAdj(BYTE ucMode);
extern void MAutoSearchEnterSubMenu(void);
extern void MAutoSearchReturnUpMenu(void);
bit CKeyStopAutoSearch(void);
void CShowAutoSerachTotal(BYTE ucSearchTotal);
void CShowFreq(WORD iFreqN, BYTE x, BYTE y);
void CShowAutoSearchSliderInOSD(WORD ucCurrentValue);
//---------------------------------------------------------------------------
// ManualSearch
extern void EnterMSearchMenu(void);
extern void MManualSearchProc(void);
extern void MManualSearchValueAdj(BYTE ucMode);
extern void MManualSearchMenuAdj(BYTE ucMode);
extern void MManualSearchEnterSubMenu(void);
extern void MManualSearchReturnUpMenu(void);
//---------------------------------------------------------------------------
// Tuning
extern void CTuningAdj(BYTE ucMode);
extern void MTuningProc(void);
extern void MTuningReturnUpMenu(void);
//---------------------------------------------------------------------------
// Skip
extern void EnterSkipMenu(void);
extern void MSkipProc(void);
extern void MSkipValueAdj(BYTE ucMode);
extern void MSkipMenuAdj(BYTE ucMode);
extern void MSkipEnterSubMenu(void);
extern void MSkipReturnUpMenu(void);
//---------------------------------------------------------------------------
// Function
extern void MFunctionProc(void);
extern void MFunctionValueAdj(BYTE ucMode);
extern void MFunctionMenuAdj(BYTE ucMode);
extern void MFunctionEnterSubMenu(void);
extern void MFunctionReturnUpMenu(void);
//---------------------------------------------------------------------------
// Reset
extern void EnterResetMenu(void);
extern void MResetProc(void);
extern void MResetValueAdj(BYTE ucMode);
extern void MResetMenuAdj(BYTE ucMode);
extern void MResetEnterSubMenu(void);
extern void MResetReturnUpMenu(void);
//---------------------------------------------------------------------------
// DisplayRatio
extern void EnterDisplayRatioMenu(void);
extern void MDisplayRatioProc(void);
extern void MDisplayRatioValueAdj(BYTE ucMode);
extern void MDisplayRatioMenuAdj(BYTE ucMode);
extern void MDisplayRatioEnterSubMenu(void);
extern void MDisplayRatioReturnUpMenu(void);
//---------------------------------------------------------------------------
// AutoPowerDown
extern void EnterADPMenu(void);
extern void MAutoPowerDownProc(void);
extern void MAutoPowerDownValueAdj(BYTE ucMode);
extern void MAutoPowerDownMenuAdj(BYTE ucMode);
extern void MAutoPowerDownEnterSubMenu(void);
extern void MAutoPowerDownReturnUpMenu(void);
//---------------------------------------------------------------------------
// BlueScreen
extern void EnterBlueScreenMenu(void);
extern void MBlueScreenProc(void);
extern void MBlueScreenValueAdj(BYTE ucMode);
extern void MBlueScreenMenuAdj(BYTE ucMode);
extern void MBlueScreenEnterSubMenu(void);
extern void MBlueScreenReturnUpMenu(void);
//---------------------------------------------------------------------------
// Sharpness
extern void MSharpnessAdjValue(BYTE ucMode);
void MSharpnessProc(void);
void MSharpnessReturnUpMenu(void);

// Sound
extern void MSoundProc(void);
extern void MSoundValueAdj(BYTE ucMode);
extern void MSoundMenuAdj(BYTE ucMode);
extern void MSoundEnterSubMenu(void);
extern void MSoundReturnUpMenu(void);
//---------------------------------------------------------------------------
// Volume Adjust
extern void MVolumeProc(void);
extern void MVolumeValueAdj(BYTE ucMode);
extern void MVolumeReturnUpMenu(void);
//---------------------------------------------------------------------------
// Balance Adjust
extern void MBalanceProc(void);
extern void MBalanceValueAdj(BYTE ucMode);
extern void MBalanceReturnUpMenu(void);
//---------------------------------------------------------------------------
// Bass Adjust
extern void MBassProc(void);
extern void MBassValueAdj(BYTE ucMode);
extern void MBassReturnUpMenu(void);
//---------------------------------------------------------------------------
// Treble Adjust
extern void MTrebleProc(void);
extern void MTrebleValueAdj(BYTE ucMode);
extern void MTrebleReturnUpMenu(void);




//---------------------------------------------------------------------------
// Source
extern void DrawSourceMenu(void);
extern void MSourceProc(void);
extern void MSourceValueAdj(BYTE ucMode);
extern void MSourceMenuAdj(BYTE ucMode);
extern void MSourceEnterSubMenu(void);
extern void MSourceReturnUpMenu(void);


// Short menu \ Volume
extern void MScVolumeProc(void);
extern void MScVolumeValueAdj(BYTE ucMode);
extern void MScVolumeReturnUpMenu(void);

//---------------------------------------------------------------------------
// Short menu \ Input ch num
extern void MScInputChNumProc(void); 
extern void SInceptNumber(const WORD ucNumber);
extern void SShowCurrentInputState(BYTE ucInputState);
void DrawShortCuteMenu(void);

extern void EnterSCVolume(void);
//extern void EnterSCBright(void);
extern void EnterSCInputNum(void);

extern void CShortCutBright(void);

//---------------------------------------------------------------------------
void CShowMode(BYTE x, BYTE y);
void CDisplayCurrentSourceMessage(void);
void ChangeSourceAv1(void);
void ChangeSourceAv2(void);
void ChangePicUD(void);
void ChangePicLR(void);
void CAdjPicMode(void);
void CChangeSourceAvSv(void);
void InitFrame(void);


#endif		//#if(_OSD_TYPE == _OSD003)
