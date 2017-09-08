#if(_KEY_TYPE == _KT_PCB2660_003)

#define _FUNC_EN_CHK_KEY_DOWN       0
#define _FUNC_EN_CHK_KEY_UP         0

#define _MENU_KEY_MASK              _BIT1
#define _LEFT_KEY_MASK              _BIT2
#define _RIGHT_KEY_MASK             _BIT3
#define _AV1_KEY_MASK               _BIT4
#if(_KEY6_TYPE == KEY6_AV2)
	#define _AV2_KEY_MASK               _BIT5
#else
	#define _169_KEY_MASK				_BIT5
#endif
#define _SOURCE_KEY_MASK            _BIT6

#if(_KEY1_TYPE == KEY1_RESET)
    #define _RESET_KEY_MASK		    _BIT7/*Modified for sleep key,AndyLiu 20080313*/
#else
    #define _SLEEP_KEY_MASK			_BIT7/*Modified for sleep key,AndyLiu 20080313*/
#endif




#ifdef __KEY__

// Key map
SKeyToOsdEvent code tKONoSignal[] =
{
    {_SOURCE_KEY_MESSAGE,		_OE_CHANGE_SOURCE},
    {_IR_SOURCE_KEY_MESSAGE,	_OE_CHANGE_SOURCE},
    {_AV1_KEY_MESSAGE,			_OE_CHANGE_SOURCE_AV1  },
	{_AV2_KEY_MESSAGE,			_OE_CHANGE_SOURCE_AV2  },
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOPublic[] =
{         /*
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU },
    {_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT     },
    {_LEFT_KEY_MESSAGE,         _OE_MENU_PREV     },
                    */
	{_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU },
	//{_RIGHT_KEY_MESSAGE,		_OE_SC_VOLUME     },
    //{_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME     },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC     },
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC     }, 
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY       },
    {_ESC_KEY_MESSAGE,			_OE_RETURN_UPMENU },
    {_RESET_KEY_MESSAGE,		_OE_RESET		  },
    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },//Modified for DISPRATIO key,AndyLiu 20080328
    // Shortcut key message
    {_SOURCE_KEY_MESSAGE,       _OE_CHANGE_SOURCE },
    {_IR_SOURCE_KEY_MESSAGE,	_OE_CHANGE_SOURCE },
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE       },
   // {_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME     },
   // {_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME     },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC     },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC     },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0 },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1 },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2 },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3 },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4 },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5 },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6 },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7 },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8 },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9 },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH   },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN     },
    {_AV1_KEY_MESSAGE,			_OE_CHANGE_SOURCE_AV1  },
    {_AV2_KEY_MESSAGE,			_OE_CHANGE_SOURCE_AV2  },
    {_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE},

    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOMenuNone[] =
{
	{_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU      },
	{_SOURCE_KEY_MESSAGE,		_OE_CHANGE_SOURCE      },
	{_IR_SOURCE_KEY_MESSAGE,	_OE_CHANGE_SOURCE      },
    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
	//{_RIGHT_KEY_MESSAGE,		_OE_SC_VOLUME          },
    //{_LEFT_KEY_MESSAGE,         _OE_SC_VOLUME          },
    {_UP_KEY_MESSAGE,           _OE_SC_CH_INC          },
    {_DOWN_KEY_MESSAGE,         _OE_SC_CH_DEC          },

	//{_IR_LEFT_KEY_MESSAGE,      _OE_SC_VOLUME          },
    //{_IR_RIGHT_KEY_MESSAGE,     _OE_SC_VOLUME          },

   {_AV1_KEY_MESSAGE,			_OE_CHANGE_SOURCE_AV1  },
   {_AV2_KEY_MESSAGE,			_OE_CHANGE_SOURCE_AV2  },
    
    {_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 
    
    {_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE    },
//    {_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE  },
//	{_IR_SCREEN_KEY_MESSAGE,    _OE_CHANGE_SCREEN},    
    {_RESET_KEY_MESSAGE,        _OE_RESET              },

    {_IR_MENU_KEY_MESSAGE,		_OE_ENTER_SUBMENU      },
    {_IR_UP_KEY_MESSAGE,        _OE_SC_CH_INC          },
    {_IR_DOWN_KEY_MESSAGE,      _OE_SC_CH_DEC          },
    //{_IR_LEFT_KEY_MESSAGE,      _OE_SC_VOLUME          },
   // {_IR_RIGHT_KEY_MESSAGE,     _OE_SC_VOLUME          }, 
    
    {_MUTE_KEY_MESSAGE,         _OE_SC_MUTE            },
    //{_VOL_DEC_KEY_MESSAGE,      _OE_SC_VOLUME          },
    //{_VOL_INC_KEY_MESSAGE,      _OE_SC_VOLUME          },
    {_CH_DEC_KEY_MESSAGE,       _OE_SC_CH_DEC          },
    {_CH_INC_KEY_MESSAGE,       _OE_SC_CH_INC          },
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0      },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1      },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2      },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3      },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4      },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5      },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6      },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7      },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8      },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9      },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CH        },
    {_RETURN_KEY_MESSAGE,       _OE_SC_RETURN          },
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY            },
    {_FAC_KEY_MESSAGE,			_OE_FAC_OPEN		   },
    {_AUTO_KEY_MESSAGE, 		_DO_AUTO_CONFIG   },  // ESC    
    
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},



 	// End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG              },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOMainMenu[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU },
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_RIGHT_KEY_MESSAGE,        _OE_ENTER_SUBMENU },

    {_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE},    
    {_IR_LEFT_KEY_MESSAGE,      _OE_MENU_NEXT    },

    {_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},

    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},

    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
   
    {_LEFT_KEY_MESSAGE,        	 _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},

    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
    
    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC},

    {_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 

    //{_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE},


    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu0[] =
{
    {_MENU_KEY_MESSAGE,         _OE_ENTER_SUBMENU},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},

    
    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
    {_IR_MENU_KEY_MESSAGE,      _OE_ENTER_SUBMENU},
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC},

    //{_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE},


    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu2[] =
{
    {_MENU_KEY_MESSAGE,         _OE_ENTER_RESET},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    
    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
    {_IR_MENU_KEY_MESSAGE,      _OE_ENTER_RESET},
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC},

    //{_IR_MODE_KEY_MESSAGE,      _OE_CHANGE_PIC_MODE},


    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Key map
SKeyToOsdEvent code tKOSubMenu1[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},

    {_IR_DISPRATIO_KEY_MESSAGE,  _OE_DISPRATIO    },
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOSource[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_UP_KEY_MESSAGE,           _OE_MENU_PREV},
    {_DOWN_KEY_MESSAGE,         _OE_MENU_NEXT},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_IR_LEFT_KEY_MESSAGE,         _OE_MENU_PREV    },
    {_IR_RIGHT_KEY_MESSAGE,        _OE_MENU_NEXT    },
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCut[] =
{
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,         _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,        _OE_ADJ_INC},
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},

    {_IR_MENU_KEY_MESSAGE,      _OE_RETURN_UPMENU},
    {_IR_LEFT_KEY_MESSAGE,      _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,     _OE_ADJ_INC},

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
// Shortcut key inputch
SKeyToOsdEvent code tKOShortInputCHMenu[] = 
{
    {_NUM_0_KEY_MESSAGE,        _OE_SC_INPUT_NUM0            },
    {_NUM_1_KEY_MESSAGE,        _OE_SC_INPUT_NUM1            },
    {_NUM_2_KEY_MESSAGE,        _OE_SC_INPUT_NUM2            },
    {_NUM_3_KEY_MESSAGE,        _OE_SC_INPUT_NUM3            },
    {_NUM_4_KEY_MESSAGE,        _OE_SC_INPUT_NUM4            },
    {_NUM_5_KEY_MESSAGE,        _OE_SC_INPUT_NUM5            },
    {_NUM_6_KEY_MESSAGE,        _OE_SC_INPUT_NUM6            },
    {_NUM_7_KEY_MESSAGE,        _OE_SC_INPUT_NUM7            },
    {_NUM_8_KEY_MESSAGE,        _OE_SC_INPUT_NUM8            },
    {_NUM_9_KEY_MESSAGE,        _OE_SC_INPUT_NUM9            },
    {_INPUT_CH_KEY_MESSAGE,     _OE_SC_INPUT_CHANGE_CH       },
    {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU            },
    {_DISPLAY_KEY_MESSAGE,      _OE_DISPLAY                  },
    {_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG                    },

};
//------------------------------------------------------------

SKeyToOsdEvent code tKOFactory[] =
{
 //   {_MENU_KEY_MESSAGE,         _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,           _OE_MENU_PREV       },
    {_RIGHT_KEY_MESSAGE,          _OE_MENU_NEXT       },
    {_MENU_KEY_MESSAGE,           _OE_ENTER_SUBMENU   },
	{_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG             },
};

//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCut001[] =
{
    {_MENU_KEY_MESSAGE,              _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,                    _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,                   _OE_ADJ_INC},
	{_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    {_IR_MENU_KEY_MESSAGE,           _OE_RETURN_UPMENU},
    {_IR_LEFT_KEY_MESSAGE,                 _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,                _OE_ADJ_INC},
    {_IR_FUNC_BRI_DEC,                     _OE_ADJ_DEC},
    {_IR_FUNC_BRI_INC,                     _OE_ADJ_INC},

    {_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCutContrast001[] =
{
    {_MENU_KEY_MESSAGE,              _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,                    _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,                   _OE_ADJ_INC},

    {_IR_MENU_KEY_MESSAGE,           _OE_RETURN_UPMENU},
    {_IR_LEFT_KEY_MESSAGE,                 _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,                _OE_ADJ_INC},
    {_IR_FUNC_CON_DEC,                     _OE_ADJ_DEC},
    {_IR_FUNC_CON_INC,                     _OE_ADJ_INC},
	{_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    {_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCutSaturation001[] =
{
    {_MENU_KEY_MESSAGE,              _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,                    _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,                   _OE_ADJ_INC},
	{_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    {_IR_MENU_KEY_MESSAGE,           _OE_RETURN_UPMENU},
    {_IR_LEFT_KEY_MESSAGE,                 _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,                _OE_ADJ_INC},
    {_IR_FUNC_COLOR_DEC,                     _OE_ADJ_DEC},
    {_IR_FUNC_COLOR_INC,                     _OE_ADJ_INC},

    {_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 

    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------
SKeyToOsdEvent code tKOShortCutVolume001[] =
{
    {_MENU_KEY_MESSAGE,              _OE_RETURN_UPMENU},
    {_LEFT_KEY_MESSAGE,                    _OE_ADJ_DEC},
    {_RIGHT_KEY_MESSAGE,                   _OE_ADJ_INC},
	{_SLEEP_KEY_MESSAGE,        _OE_SC_TIMER_CHANGE},
    {_IR_MENU_KEY_MESSAGE,           _OE_RETURN_UPMENU},
    {_IR_LEFT_KEY_MESSAGE,                 _OE_ADJ_DEC},
    {_IR_RIGHT_KEY_MESSAGE,                _OE_ADJ_INC},
    {_IR_FUNC_VOL_DEC,                     _OE_ADJ_DEC},
    {_IR_FUNC_VOL_INC,                     _OE_ADJ_INC},

	{_IR_SCREEN_UD_KEY_MESSAGE,			_OE_PIC_CHANGE_U_D  },//jokerxie modify for
    {_IR_SCREEN_LR_KEY_MESSAGE,			_OE_PIC_CHANGE_L_R  },//screen up down left right 
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG         },
};
//------------------------------------------------------------

SKeyToOsdEvent code tKOFactorySub[] =
{
 //   {_MENU_KEY_MESSAGE,          _OE_RETURN_UPMENU},
 //   {_LEFT_KEY_MESSAGE,          _OE_MENU_PREV    },
    {_MENU_KEY_MESSAGE,          _OE_MENU_NEXT      },
    {_LEFT_KEY_MESSAGE,          _OE_ADJ_INC        },
	{_RIGHT_KEY_MESSAGE,         _OE_ADJ_DEC        },
	
    // End flag,not modify there
    {_NONE_KEY_MESSAGE,         _NONE_MSG           },
};


#else               //#ifdef __PCB2660_003_KEY__

// Key map
extern SKeyToOsdEvent code tKONoSignal[];
extern SKeyToOsdEvent code tKOPublic[];
extern SKeyToOsdEvent code tKOMenuNone[];
extern SKeyToOsdEvent code tKOMainMenu[];
extern SKeyToOsdEvent code tKOSubMenu[];
extern SKeyToOsdEvent code tKOSubMenu0[];
extern SKeyToOsdEvent code tKOSubMenu1[];
extern SKeyToOsdEvent code tKOSubMenu2[];
extern SKeyToOsdEvent code tKOSource[];
extern SKeyToOsdEvent code tKOFactory[];
extern SKeyToOsdEvent code tKOFactorySub[];
extern SKeyToOsdEvent code tKOShortCut[];
extern SKeyToOsdEvent code tKOShortInputCHMenu[];
extern SKeyToOsdEvent code tKOShortCut001[];
extern SKeyToOsdEvent code tKOShortCutContrast001[];
extern SKeyToOsdEvent code tKOShortCutSaturation001[];
extern SKeyToOsdEvent code tKOShortCutVolume001[];

#endif              //#ifdef __PCB2660_003_KEY__

BYTE CKeyScan(void);
void CKeyMessageProc(void);

#endif              //#if(_KEY_TYPE == _KT_PCB2660_003)
