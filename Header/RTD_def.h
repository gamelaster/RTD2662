

#define CAPTURE_HDELAY      3//5
#define MEASURE_HDEALY      10//12
#define MEAS_H_STA_OFFSET   (MEASURE_HDEALY - CAPTURE_HDELAY)
#define MEAS_H_END_OFFSET   (MEASURE_HDEALY - CAPTURE_HDELAY + 1)

#define MINIMUM_HDELAY      6//24    
#define PROGRAM_HDELAY      6//24

#define MINIMUM_VDELAY      1
#define PROGRAM_VDELAY      3   // Must be smaller than 8

///////////////////////////////////////////////////////////////////
// Definitions for OSD user font table
#define SWAP_FONT_RAM       0

///////////////////////////////////////////////////////////////////
//Definitions for APLL P_Code
#define P_Code              21//22
#define I_Correction        4//24   //If set to 0, I_Correction will be the (P_Correction / 4 + 10)
#define Correct_Amount      185  //When Phase Error exceed the threshold "16",the correction amount
                                 //will update to this value
///////////////////////////////////////////////////////////////////
// Definitions for RTD control register address

#define ID_REG_00           0x00
#define STATUS0_01          0x01
#define HOSTCTRL_02         0x02
#define IRQCTRL0_03         0x03
#define VGIP_CTRL_04        0x04
#define VGIP_SIGINV_05      0x05
#define IPH_ACT_STA_06      0x06
#define IPH_ACT_WID_08      0x08
#define IPV_ACT_STA_0A      0x0A
#define IPV_ACT_LEN_0C      0x0C
#define IRQ_CTRL1_0E        0x0E
#define PTNPOS_LO_0F        0x0F
#define ADC_TEST_10         0x10
#define PTNRD_11            0x11
#define PTNGD_12            0x12
#define PTNBD_13            0x13
#define INT_FLD_DETECT_14   0x14    //INTERNAL_FIELD_DETECTION
#define SCALE_CTRL_15       0x15
#define HOR_SCA_16          0x16
#define VER_SCA_18          0x18
#define HV_SCA_L_1A         0x1A
#define FILTER_CTRL0_1B     0x1B
#define FILTER_CTRL1_1C     0x1C
#define FILTER_PORT_1D      0x1D
#define FS_FT_DELAY_1E      0x1E    //FRAME SYNC FINETUNE DELAY
#define STATUS1_1F          0x1F
#define VDIS_CTRL_20        0x20
#define VDIS_SIGINV_21      0x21
#define DH_TOTAL_22         0x22
#define DH_HS_END_24        0x24
#define DH_BKGD_STA_25      0x25
#define LAST_LINE_L_26      0x26
#define DH_ACT_STA_27       0x27
#define DH_ACT_END_29       0x29
#define DH_BKGD_END_2B      0x2B
#define LAST_LINE_H_2C      0x2C
#define DV_TOTAL_2D         0x2D
#define DV_TOTAL_H_2E       0x2E
#define DV_VS_END_2F        0x2F
#define DV_BKGD_STA_30      0x30
#define DV_BKGD_STA_31      0x31
#define DV_ACT_STA_32       0x32
#define DV_ACT_END_34       0x34
#define DV_BKGD_END_36      0x36
#define IV_DV_LINES_38      0x38
#define YUV2RGB_39          0x39
#define DIS_TIMING0_3A      0X3A
#define DIS_TIMING1_3B      0x3B
#define PE_CONTROL_3C       0x3C    // From RTD2020 rev.C
#define DV_TOTAL_STATUS_3D  0x3D
#define DUTY_FINE_TUNE_3E   0x3E
#define DUTY_FINE_TUNE_3F   0x3F
#define DRW_BSU_40          0x40
#define DRL_BSU_42          0x42
#define SYNC_CTRL_4A        0x4A
#define SYNC_CTRL_4B        0x4B
#define SYNC_POR_4C         0x4C
#define MEAS_HS_PER_4D      0x4D
#define MEAS_HS_LATCH_4E    0x4E
#define MEAS_VS_PER_4F      0x4F
#define MEAS_HI_51          0x51
#define MEAS_HI_52          0x52
#define MEAS_VS_53          0x53
#define MEAS_VS_HI_54       0x54
#define CLAMP_55            0x55
#define FX_LST_LEN_L_59     0x59
#define FX_LST_LEN_H_5A     0x5A
#define ANTI_FLICKER_TH1_5B 0x5B
#define COLOR_CTRL_5D       0x5D
#define BRIGHT_R_5E         0x5E
#define BRIGHT_G_5F         0x5F
#define BRIGHT_B_60         0x60
#define CONTRAST_R_61       0x61
#define CONTRAST_G_62       0x62
#define CONTRAST_B_63       0x63
#define RED_GAMMA_64        0x64
#define GRN_GAMMA_65        0x65
#define BLU_GAMMA_66        0x66
#define DITHER_PORT_67      0x67
#define OP_CRC_CTRL_68      0x68
#define OP_CRC_BYTE_69      0x69
#define PATTERN_GEN_6C      0x6C
#define BGCOLOR_CONTROL_6C  0x6C
#define OVL_CTRL_6D         0x6D
#define OVL_LUT_ADDR_6E     0x6E
#define OVL_PORT_6F         0x6F
#define SD_CTRL_70          0x70
#define H_SCALE_DL_71       0x71
#define V_SCALE_DL_73       0x73
#define H_BND_STA_L_75      0x75    //H_BOUNDARY_STA_L
#define H_BND_END_L_76      0x76
#define H_BND_HIGH_77       0x77
#define V_BND_STA_L_78      0x78    //V_BOUNDARY_STA_L
#define V_BND_END_L_79      0x79
#define V_BND_HIGH_7A       0x7A
#define MARGIN_R_7B         0x7B
#define MARGIN_G_7C         0x7C
#define MARGIN_B_7D         0x7D
#define DIFF_THRED_7E       0x7E    //DIFF_THRESHOLD
#define AUTO_ADJ_CTRL_7F    0x7F
#define VER_START_80        0x80
#define HOR_START_84        0x84
#define AUTO_PHASE0_88      0x88
#define AUTO_BAL_RESULT_88  0x88
#define IVS_DELAY_8C        0x8C
#define IHS_DELAY_8D        0x8D
#define ODD_CTRL_8E         0x8E
#define OSD_ADDR_MSB_90     0x90
#define OSD_ADDR_LSB_91     0x91
#define OSD_ROW_90          0x90
#define OSD_COL_91          0x91
#define OSD_DATA_92         0x92
#define OSD_TEST_93         0x93
#define OSD_SCRAMBLE_94     0x94
#define TC_ADDR_PORT_95     0x95    //TCON_ADDRESS_PORT
#define TC_DATA_PORT_96     0x96    //TCON_DATA_PORT
#define FIX_DVTOTAL_LSB_97  0x97
#define FIX_DVTOTAL_MSB_98  0x98
#define SPREAD_SPECTRUM_99  0x99
#define PLL_PHASE_9F        0x9f
#define DCLK_OFFSET_LSB_9A  0x9a
#define DCLK_OFFSET_MSB_9B  0x9b
#define HW_AUTO_PHASE_9E    0x9e
#define TMDS_OUTPUT_ENA_A0  0xa0
#define TMDS_INPUT_ENA_A1   0xa1
#define ANG_PERFORMANCE1_A2 0xa2
#define ANG_PERFORMANCE2_A3 0xa3
#define ANG_PERFORMANCE3_A4 0xa4
#define ANG_TEST_SEL_A5     0xa5
#define HDCP_CONTROL_REG_A6 0xa6
#define CRC_OUTPUT_BYTE_A7  0xa7
#define DB_TEST_MODE_AA     0xaa
#define DVI_REG_TEST_AB     0xab
#define PATTERN_COM_AC      0xac
#define PIXEL_ERROR_RATE_AD 0xad
#define DVI_CTRL1_AF        0xaf
#define TMDS_CTL_STATUS_B0  0xb0
#define DEVICE_KEY_ACCESS_B1 0xb1
#define TMDS_TEST_MODE1_B3  0xb3
#define HDCP_ADDR_PORT_B6   0xb6
#define HDCP_DATA_PORT_B7   0xb7
#define DDC_ENABLE_BC       0xbc
#define DDC_INDEX_BD        0xbd
#define DDC_ACCESS_PORT_BE  0xbe
#define LVDS_CTRL0_C0       0xc0
#define LVDS_CTRL_C1        0xc1
#define LVDS_CTRL_C2        0xc2
#define LVDS_CTRL_C3        0xc3
#define LVDS_CTRL_C4        0xc4
#define PLL_DIV_CTRL0_C8    0xC8
#define I_CODE_LB_C9        0xC9
#define I_CODE_MB_CA        0xCA
#define P_CODE_CB           0xCB
#define PLLDIV_CC           0xCC
#define PLL_CALIBRATION_CE  0xCE
#define DPLL_CTRL_D0        0xD0
#define DPLL_M_D1           0xD1
#define DPLL_N_D2           0xD2
#define DPLL_FILTER_D3      0xD3
#define DPLL_SSP_D4         0xD4    //Spread Spectrum
#define PLL1_CTRL_D6        0xD6
#define PLL1_M_D7           0xD7
#define PLL1_FILTER_D9      0xD9
#define PLL2_CTRL_DA        0xDA
#define PLL2_M_DB           0xDB
#define PLL2_FILTER_DD      0xDD
#define PLL_PHASE_DF        0xDF
#define REDGAIN_E0          0xE0
#define GRNGAIN_E1          0xE1
#define BLUGAIN_E2          0xE2
#define REDOFST_E3          0xE3
#define GRNOFST_E4          0xE4
#define BLUOFST_E5          0xE5
#define ADC_CTRL_E6         0xE6
#define ADC_REG_CUR_L_E7    0xE7
#define ADC_REG_CUR_H_E8    0xE8
#define ADC_REG_TEST_E9     0xE9
#define ADC_REG_CLK_EA      0xEA
#define ADC_FRAME_MODULE_EB 0xEB
#define ADC_DIFF_MODE_EC    0xEC
#define HS_SCHMITT_TRIG_ED  0xED
#define DDC_SET_SLAVE_F0    0xF0
#define DDC_SUB_IN_F1       0xF1
#define DDC_DATA_IN_F2      0xF2
#define DDC_DATA_OUT_F3     0xF3
#define DDC_STATUS_F4       0xF4
#define DDC_IRQ_CTRL_F5     0xF5
#define GP1_ODOCTRL_F6      0xF6    //GPIO_P1 OPEN_DRAIN OUTPUT CONTROL
#define GP1_IO_CTRL_F7      0xF7
#define GP1_FUNC_SEL_F8     0xF8
#define GP2_ODOCTRL_F9      0xF9
#define GP2_IO_CTRL_FA      0xFA
#define GP2_FUNC_SEL_FB     0xFB
#define DDC_ENABLE_FC       0xFC
#define DDC_INDEX_FD        0xFD
#define DDC_ACCESS_P_FE     0xFE    //DDC_ACCESS_PORT
#define TMDS_CORRECTION_FF  0xFF

/* Old definition for RTD3001
#define STATUS0_01          0x01
#define HOSTCTRL_02         0x02
#define IRQCTRL_03          0x03
#define VGIP_CTRL_04        0x04
#define VGIP_SIGINV_05      0x05
#define IPH_ACT_STA_06      0x06
#define IPH_ACT_WID_08      0x08
#define IPV_ACT_STA_0A      0x0A
#define IPV_ACT_LEN_0C      0x0C
#define SCALE_CTRL_15       0x15
#define HSCALE_FACTOR_16    0x16
#define VSCALE_FACTOR_18    0x18
#define FILTER_CTRL_1A      0x1A
#define HFILTER_PORT_1B     0x1B
#define VFILTER_PORT_1C     0x1C
#define FS_FT_DELAY_1E      0x1E
#define STATUS1_1F          0x1F
#define VDIS_CTRL_20        0x20
#define VDIS_SIGINV_21      0x21
#define DH_TOTAL_22         0x22
#define DH_BKGD_STA_25      0x25
#define LAST_LINE_L_26      0x26
#define DH_ACT_STA_27       0x27
#define DH_ACT_END_29       0x29
#define DH_BKGD_END_2B      0x2B
#define LAST_LINE_H_2C      0x2C
#define DV_TOTAL_2D         0x2D
#define DV_TOTAL_H_2E       0x2E
#define DV_BKGD_STA_30      0x30
#define DV_ACT_STA_32       0x32
#define DV_ACT_END_34       0x34
#define DV_BKGD_END_36      0x36
#define MEMCTRL_38          0x38
#define MEM_TIMING_3A       0X3A
#define DIS_TIMING_3B       0x3B
#define PLLCTRL_3C          0x3C
#define DCLK_3D             0x3D
#define MCLK_3F             0x3F
#define COMP_WID_43         0x43
#define DWPIX_BSU_45        0x45
#define DRPIX_BSU_47        0x47
#define DRLEN_BSU_49        0x49
#define SYNC_CTRL_4B        0x4B
#define SYNC_POR_4C         0x4C
#define HSYNC_HI_51         0x51
#define CLAMP_55            0x55
#define MEM_TEST_5B         0x5B
#define COLOR_CTRL_5D       0x5D
#define BRIGHT_R_5E         0x5E
#define BRIGHT_G_5F         0x5F
#define BRIGHT_B_60         0x60
#define CONTRAST_R_61       0x61
#define CONTRAST_G_62       0x62
#define CONTRAST_B_63       0x63
#define RED_GAMMA_64        0x64
#define GRN_GAMMA_65        0x65
#define BLU_GAMMA_66        0x66
#define DITHER_PORT_67      0x67
#define FULL_LINE_68        0x68
#define OVL_CTRL_6D         0x6D
#define OVL_LUT_ADDR_6E     0x6E
#define OVL_PORT_6F         0x6F
#define SD_CTRL_70          0x70
#define WRT_MEM_PIX_71      0x71
#define H_SCALE_DL_75       0x75
#define V_SCALE_DL_77       0x77
#define AUTO_BAL_CTRL_79    0x79
#define AUTO_PHA_CTRL_7A    0x7A
#define MARGIN_R_7B         0x7B
#define MARGIN_G_7C         0x7C
#define MARGIN_B_7D         0x7D
#define LINE_SEL_7E         0x7E
#define AUTO_POS_CTRL_7F    0x7F
#define VER_START_80        0x80
#define HOR_START_84        0x84
#define AUTO_PHASE0_88      0x88
#define AUTO_BAL_RESULT_88  0x88
#define IVS_DELAY_8C        0x8C
#define IHS_DELAY_8D        0x8D
#define ODD_CTRL_8E         0x8E
#define OSD_ROW_90          0x90
#define OSD_COL_91          0x91
#define OSD_DATA_92         0x92
#define TC_CTRL1_B0         0xB0
#define TC_CTRL2_B1         0xB1
#define TC_CTRL3_B3         0xB2
#define TC_GPO7_B3          0xB3
#define TC_GPO6_BC          0xBC
#define TC_GPO5_C5          0xC5
#define TC_GPO4_CE          0xCE
#define TC_GPO3_D7          0xD7
#define TC_GPO2_E0          0xE0
#define TC_GPO1_E9          0xE9
#define TC_GPO0_F2          0xF2
*/