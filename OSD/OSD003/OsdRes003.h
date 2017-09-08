#if(_OSD_TYPE == _OSD003)



#ifdef __OSDRES003__

#else
extern BYTE code tOSD_WINDOW7_STYLE[];
extern BYTE code tOSD_WINDOW0_STYLE[];
extern BYTE code tPALETTE_0[];
extern BYTE code FntIcnBright[];
extern BYTE code FntIcnContrast[];
extern BYTE code FntIconSaturation[];
extern BYTE code FntIcnExit[];
extern BYTE code FntIcnReset[];
extern BYTE code FntIcnLang[];
extern BYTE code FntIconHue[];
extern BYTE code FntIcnSpker[];
extern BYTE code tUserMenuOsdMap[];
extern BYTE code tFactoryMenuOsdMap[];
extern BYTE code t001MenuOsdMap[];           //Added at 11.26 for OSD001
extern BYTE code tArrowHead[];

extern BYTE code tMsgOsdMap[];
extern BYTE code tPALETTE_0[];
extern BYTE code tMainWindowStyle[];
extern BYTE code tPopupMenuWindowStyle[];

extern BYTE code tColorIco_Normal[];
extern BYTE code tColorIco_Select[];
extern BYTE code tColorIco_Disable[];
      
extern BYTE code tAdjustIco_Normal[];
extern BYTE code tAdjustIco_Select[];
extern BYTE code tAdjustIco_Disable[];
       
extern BYTE code tOsdIco_Normal[];
extern BYTE code tOsdIco_Select[];
extern BYTE code tOsdIco_Disable[];
     
extern BYTE code tTVIco_Normal[];
extern BYTE code tTVIco_Select[];
extern BYTE code tTVIco_Disable[];
      
extern BYTE code tFuncIco_Normal[];
extern BYTE code tFuncIco_Select[];
extern BYTE code tFuncIco_Disable[];
    
extern BYTE code tSoundIco_Normal[];
extern BYTE code tSoundIco_Select[];
extern BYTE code tSoundIco_Disable[];

extern code STitle tMainTitle[][_LANGUAGE_CNT];

extern code BYTE *tIcon_Normal[];
extern code BYTE *tIcon_Select[];
extern code BYTE *tIcon_Disable[];

extern code BYTE sVGA[];
extern code BYTE sDVI[];
extern code BYTE sHDMI[];
extern code BYTE sYPBPR[];
extern code BYTE sSVideo[];
extern code BYTE sAV[];
extern code BYTE sSource[]; 
extern code BYTE sTV[];
extern code BYTE sSpace[];
extern code BYTE s16_9[];
extern code BYTE s4_3[];
extern code BYTE sAuto[];
extern code BYTE s2328[];
extern code BYTE s3238[];
extern code BYTE sLeftRight[];
extern code BYTE sUpDown[];
extern code BYTE sLeft[];
extern code BYTE sRight[];
extern code BYTE sUp[];
extern code BYTE sDown[];

extern code BYTE sNo[];
extern code BYTE sYes[];

extern code BYTE sStandard_Eng[];
extern code BYTE sSoft_Eng[];
extern code BYTE sVivid_Eng[];
extern code BYTE sPersonal_Eng[];

extern code BYTE sNTSC_M[];
extern code BYTE sNTSC_4_BG[];
extern code BYTE sNTSC_4_DK[];
extern code BYTE sNTSC_4_I[];
extern code BYTE sPAL_M[];

extern code BYTE sPAL_BG[];
extern code BYTE sPAL_I[];
extern code BYTE sPAL_DK[];
extern code BYTE sPAL_N[];

extern code BYTE sSECAM_BG[];
extern code BYTE sSECAM_DK[];
extern code BYTE sSECAM_L[];
extern code BYTE sSECAM_LL[];



extern code BYTE *sAutoConfig[];
extern code BYTE *sAutoPowerDown[];
extern code BYTE *sAutoSearch[];
extern code BYTE *sBalance[];
extern code BYTE *sBass[];
extern code BYTE *sBBE[];
extern code BYTE *sBlueScreen[];
extern code BYTE *sFm[];
extern code BYTE *sSharpness[];
extern code BYTE *sBrightness[];
extern code BYTE *sChannel[];
extern code BYTE *sClock[];
extern code BYTE *sColorTemp[];
extern code BYTE *sContrast[];
extern code BYTE *sDisplayRatio[];
extern code BYTE *sDouble[];
extern code BYTE *sHPosition[];
extern code BYTE *sHue[];
extern code BYTE *sLanguage[];
extern code BYTE *sIR[];
extern code BYTE *sManualSearch[];
extern code BYTE *sMute[];
extern code BYTE *sPhase[];
extern code BYTE *sReset[];
extern code BYTE *sSaturation[];
extern code BYTE *sSkip[];
extern code BYTE *sSRS[];
extern code BYTE *sSystem[];
extern code BYTE *sTimer[];
extern code BYTE *sTransparent[];
extern code BYTE *sTreble[];
extern code BYTE *sTuning[];
extern code BYTE *sVolume[];
extern code BYTE *sVPosition[];

extern code BYTE *sNoSignal[];
extern code BYTE *sNotSupport[];

extern code BYTE *sUser[];
extern code BYTE *s9300[];
extern code BYTE *s6500[];

extern code BYTE *sOK[];
extern code BYTE *sCancel[];
extern code BYTE *sLanguageName[];

extern code BYTE *sOn[];
extern code BYTE *sOff[];
extern code BYTE *SOnOff[2][10];

extern code BYTE *s15Min[];
extern code BYTE *s30Min[];
extern code BYTE *s45Min[];
extern code BYTE *s60Min[];
extern code BYTE *s75Min[];
extern code BYTE *s90Min[];
extern code BYTE *s105Min[];
extern code BYTE *s120Min[];
//---------------------------------------------------------------------------
extern code BYTE *sFM_877[];
extern code BYTE *sFM_879[];
extern code BYTE *sFM_881[];
extern code BYTE *sFM_883[];
extern code BYTE *sFM_885[];
extern code BYTE *sFM_887[];
extern code BYTE *sFM_889[];
extern code BYTE *sFM_891[];
extern code BYTE *sFM_880[];
extern code BYTE *sFM_882[];
extern code BYTE *sFM_884[];
extern code BYTE *sFM_886[];
extern code BYTE *sFM_888[];
extern code BYTE *sFM_890[];
extern code BYTE *sFM_892[];
extern code BYTE *sFM_894[];

//---------------------------------------------------------------------------
extern code BYTE sMhz[];
extern code BYTE *sSearchUP[];
extern code BYTE *sSearchDown[];
extern code BYTE *sExit[];


//---------------------------------------------------------------------------
extern code BYTE * sYPbPrMode[];
extern code BYTE sPAL[];
extern code BYTE sNTSC[];
extern code BYTE * sTVType[14];

extern BYTE code sFacAdjustColor[];
extern BYTE code sFacGain[];
extern BYTE code sFacOffset[];
extern BYTE code sFac9300[];
extern BYTE code sFac6500[];
extern BYTE code sFacRGB[];
extern BYTE code sBurnIn[];
extern BYTE code sFacExit[];
extern BYTE code sFacOn[];
extern BYTE code sFacOff[];
//---------------------------------------------------------------------------
extern BYTE code tGlobalCharWidth[];
extern BYTE code tFntVolumeCharWidth[];
extern BYTE code FntGlobal[];
extern BYTE code FntKor[];
extern BYTE code FntJap[];
extern BYTE code FntRus[];
extern BYTE code FntChi_S[];
extern BYTE code FntChi_T[];
extern BYTE code FntMainIcon[];

extern BYTE code FntCH_S[];
extern BYTE code FntCH_T[];

extern BYTE code tFntLangaugeNameCharWidth[];
extern BYTE code tFntRusCharWidth[];
extern BYTE code tFntJapCharWidth[];
extern BYTE code tFntKorCharWidth[];
extern BYTE code FntLangaugeName[];

extern BYTE code FntAdjustPage_S[];
extern BYTE code FntColorPage_S[];
extern BYTE code FntFuncPage_S[];
extern BYTE code FntOSDPage_S[];
extern BYTE code FntPublic_CHI_S[];
extern BYTE code FntSoundPage_S[];
extern BYTE code FntTVPage_S[];
extern BYTE code FntOther_CHI_S[];


extern BYTE code FntAdjustPage_T[];
extern BYTE code FntColorPage_T[];
extern BYTE code FntFuncPage_T[];
extern BYTE code FntOSDPage_T[];
extern BYTE code FntPublic_CHI_T[];
extern BYTE code FntSoundPage_T[];
extern BYTE code FntTVPage_T[];
extern BYTE code FntOther_CHI_T[];


#endif				//#ifdef __OSDRES001__


// extand function & Var
// Title
extern BYTE code FntColorEng_Title[];
extern BYTE code FntAdjustEng_Title[];
extern BYTE code FntTVEng_Title[];
extern BYTE code FntOSDEng_Title[];
extern BYTE code FntFunctionEng_Title[];
extern BYTE code FntSoundEng_Title[];
extern BYTE code FntVolume[];
extern BYTE code FntMute[];
extern BYTE code FntInputState[];

extern BYTE code FntTitleAdjust_CHIS[];
extern BYTE code FntTitleFunc_CHIS[];
extern BYTE code FntTitleOSD_CHIS[];
extern BYTE code FntTitleSound_CHIS[];
extern BYTE code FntTitleTV_CHIS[];
extern BYTE code FntTitleColor_CHIS[];

extern BYTE code FntTitleAdjust_CHIT[];
extern BYTE code FntTitleFunc_CHIT[];
extern BYTE code FntTitleOSD_CHIT[];
extern BYTE code FntTitleSound_CHIT[];
extern BYTE code FntTitleTV_CHIT[];
extern BYTE code FntTitleColor_CHIT[];


#endif		//#if(_OSD_TYPE == _OSD003)
