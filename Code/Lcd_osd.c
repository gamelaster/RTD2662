#define __OSD__

#include "reg52.h" 

#include "Header\MAIN_DEF.H"
#include "Header\CONFIG.H"
#include "Header\ACCESS.H"
#include "Header\LCD_FUNC.H"
#include "Header\LCD_AUTO.H"
#include "Header\LCD_MSG.H"
#include "Header\LCD_MAIN.H"
#include "Header\LCD_OSD.H"
#include "Header\FONT.H"
#include "Header\OSD.H"
#include "Header\SRC_CTRL.H"
#include "Header\OSD_TREE.H"

#include "Header\rgb_echo.H"

#if (TV_CHIP != TV_NONE)
#include "TUNER.H"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OSD Process Dispatch Table
// In this code, when input source is not VGA, AUTO CONFIG page will not be shown.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char GetNextPageIdx(unsigned char ucPageCurr)
{
    switch (stGUD1.INPUT_SOURCE & 0x07)
    {
    case SOURCE_VGA :
        return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
    case SOURCE_DVI :
        return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
    case SOURCE_AV  :
        return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
    case SOURCE_SV  :
        return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
    case SOURCE_YUV :
        return (5 <= ucPageCurr) ? 1 : ucPageCurr + 1;
    default :
        return 1;
    }
    
}

unsigned char GetPrevPageIdx(unsigned char ucPageCurr)
{
   switch (stGUD1.INPUT_SOURCE & 0x07)
    {
    case SOURCE_VGA :
        return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
    case SOURCE_DVI :
        return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
    case SOURCE_AV  :
        return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
    case SOURCE_SV  :
        return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
    case SOURCE_YUV :
        return (1 >= ucPageCurr) ? 5 : ucPageCurr - 1;
    default :
        return 1;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OSD Process Public Function
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  OSD Window : Control OSD Windows
//  win_no     : bit 2 ~ 0   Window Number 0 ~ 7
//  row_start  : bit 10 ~ 0  Window Row Start Address
//  row_end    : bit 10 ~ 0  Window Row End Address
//  col_start  : bit 10 ~ 0  Window Column Start Address
//  col_end    : bit 10 ~ 0  Window Column End Address
//  width      : bit 2 ~ 0   shadow/border width or 3D button thickness in pixel unit 1~8 pixel
//  height     : bit 2 ~ 0   shadow/border height in line unit , it must the same with width for 3D button thickness
//  color      : bit 3 ~ 0   window color index in 16-color LUT
//  color_sb   : bit 7 ~ 4   shadow color or left-top/bottom border color for 3D window
//             : bit 3 ~ 0   border color or right-bottom/top border color
//  gradient   : bit 7       R Gradient Polarity 0 : Decrease  1 : Increase
//             : bit 6       G Gradient Polarity 0 : Decrease  1 : Increase
//             : bit 5       B Gradient Polarity 0 : Decrease  1 : Increase
//             : bit 4 ~ 3   Gradient level      00~11 : 1 step ~ 4 setp per level
//             : bit 2       Enable Red Color Gradient
//             : bit 1       Enable Green Color Gradient
//             : bit 0       Enable Blue Color Gradient
//  gra_level  : bit 2~0     111 ~ 001 : 7 level ~ 1 level per gradient, 000 : 8 level per gradient
//  attr       : bit 6       1 - Enable Gradient function      0 - Disable Gradient function
//             : bit 5       1 - Vertical Gradient             0 - Horizontal Gradient
//             : bit 4       1 - Enable Shadow/Border/3D button   0 - Disable
//             : bit 3 ~ 1   000 : Shadow Type 1
//                           001 : Shadow Type 2
//                           010 : Shadow Type 3
//                           011 : Shadow Type 4
//                           100 : 3D Button Type 1
//                           101 : 3D Button Type 2
//                           110 : Reserved
//                           111 : Border
//             : bit 0       1 - Enable Window            0 - Disable Window
void OSD_Window(unsigned char win_no, unsigned int row_start, unsigned int row_end, unsigned int col_start, unsigned int col_end,
					unsigned char width, unsigned char height, unsigned char color, unsigned char color_sb, unsigned char gradient,
					unsigned char gray_level,unsigned char attr)
{
	if(win_no > 7)  
		return;

	Data[0]     = 5;
	Data[1]     = Y_INC;
	Data[2]     = OSD_ADDR_MSB_90;
	Data[3]     = 0xc1;
	Data[4]     = (win_no << 2);
	Data[5]     = 0;
	RTDWrite(Data);
	Data[0]     = 6;
	Data[1]     = N_INC;
	Data[2]     = OSD_DATA_92;
	Data[3]     = ((width & 0x07) << 3) | (height & 0x07);
	Data[4]     = color_sb;
	Data[5]     = gradient;
	Data[6]     = 0;
	RTDWrite(Data);

	Data[0]     = 5;
	Data[1]     = Y_INC;
	Data[2]     = OSD_ADDR_MSB_90;
	Data[3]     = 0xe1;
	Data[4]     = (win_no << 2) + 1;
	Data[5]     = 0;
	RTDWrite(Data);
	Data[0]     = 9;
	Data[1]     = N_INC;
	Data[2]     = OSD_DATA_92;
	Data[3]     = (unsigned char)((unsigned int)(row_start & 0x003f) << 2);
	Data[4]     = (unsigned char)((unsigned int)(col_start & 0x0007) << 5) | 
			      (unsigned char)((unsigned int)(row_start & 0x07c0) >> 6);
	Data[5]     = (unsigned char)((unsigned int)(col_start & 0x07f8) >> 3);

	Data[6]     = (unsigned char)((unsigned int)(row_end & 0x003f) << 2);
	Data[7]    = (unsigned char)((unsigned int)(col_end & 0x0007) << 5) | 
				  (unsigned char)((unsigned int)(row_end & 0x07c0) >> 6);
	Data[8]    = (unsigned char)((unsigned int)(col_end & 0x07f8) >> 3);
	Data[9]     = 0;
	RTDWrite(Data);

	Delay_Xms(25);
	
	/*
	do
	{
		RTDRead(0x94, 0x01, Y_INC);
	}
	while( ((Data[0] >> 5) & 0x01) );
	*/
	
	Data[0]     = 5;
	Data[1]     = Y_INC;
	Data[2]     = OSD_ADDR_MSB_90;
	Data[3]     = 0xc1;
	Data[4]     = (win_no << 2) + 3;
	Data[5]     = 0;
	RTDWrite(Data);
	Data[0]     = 6;
	Data[1]     = N_INC;
	Data[2]     = OSD_DATA_92;
	Data[3]    = 0x00;
	Data[4]    = (unsigned char)((gray_level & 0x07) << 4) |( color & 0x0f);
	Data[5]    = attr;
	Data[6]    = 0;
	RTDWrite(Data);

}

/////////////////////////////////////////////////////////////////////////////////////
//anson
/////////////////////////////////////////////////////////////////////////////////////
void OSD_Fact_Line(unsigned char row, unsigned char col, unsigned char length,
              unsigned char value, unsigned char indicate)
{
	unsigned int idata usStart_Addr;
	unsigned char idata ucTemp;

	usStart_Addr = FONT_SELECT_ADDRESS;

	//The address of the first character Cn1 in Row n = FONT_SELECT_ADDRESS + Row0_length + Row1_length +...+Row(n-1)_length
	for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
		usStart_Addr += FactRow_Info[0][ucTemp];

	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;

	if( (col+1) > FactRow_Info[0][row + 1])	// if column_start > row_length, then return
		return;
	else if((col + 1 + length) > FactRow_Info[0][row + 1])	// if column_start + length > row_length, then re-calculate the length
		length = FactRow_Info[0][row + 1] - col;

	// indicate : 0, 1, 2, 3 set byte 0, 1, 2 and all byte
	Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | (((indicate << 2) + 1) << 4);
	Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
	Data[5] = 0;
	RTDWrite(Data);

	Data[0]     = (indicate == 3) ? length * 3 + 3 : length + 3;
	Data[1]     = BURST;
	Data[2]     = OSD_DATA_92;
	Data[3]     = value;
	Data[4]     = 0;
	RTDWrite(Data);

}

void OSD_Fact_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width)
{
	width = width;
	if (height)
	{
		do
		{
			OSD_Fact_Line(row_start, col_start, FactRow_Info[0][row_start+1], 0x00, 3);
			//OSD_Line(row_start, col_start, width, 0x00, 3);
			row_start++;
		}
		while (--height);
	}
}

void ShowValue(unsigned char row, unsigned char col,unsigned char value, unsigned char color)
{
	unsigned int idata usStart_Addr;
	unsigned char idata ucTemp;

	usStart_Addr = FONT_SELECT_ADDRESS;

	//The address of the first character Cn1 in Row n = FONT_SELECT_ADDRESS + Row0_length + Row1_length +...+Row(n-1)_length
	for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
		usStart_Addr += FactRow_Info[0][ucTemp];

	Data[10] = value/100;
	Data[11] = (value - (Data[10]*100))/10;
	Data[12] = value - (Data[10]*100) - (Data[11]*10);
	if(0 != Data[10])
	{
		Data[10] += _0_;
		Data[11] += _0_;
	}
	else
	{
		if(0 != Data[11])	Data[11] += _0_;
	}
	Data[12] += _0_;
	//Byte1
	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;
	Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | 0x50;
	Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
	Data[5] = 0;
	RTDWrite(Data);
	Data[0]     = 6;
	Data[1]     = N_INC;
	Data[2]     = OSD_DATA_92;
	Data[3]     = Data[10];
	Data[4]     = Data[11];
	Data[5]     = Data[12];
	Data[6]     = 0;
	RTDWrite(Data);
	//Byte2
	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;
	Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | 0x90;
	Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
	Data[5] = 0;
	RTDWrite(Data);
	Data[0]     = 6;
	Data[1]     = N_INC;
	Data[2]     = OSD_DATA_92;
	Data[3]     = color;
	Data[4]     = color;
	Data[5]     = color;
	Data[6]     = 0;
	RTDWrite(Data);
}

void Value_Adjust(unsigned char *Var, unsigned char Key, unsigned char VMax, unsigned char VMin)
{
	if(NOTIFY_LEFT_KEY == Key)
	{
		if(bKeyTurbo)
			*Var   = (*Var < (VMax - 1)) ? (*Var + 2) : VMax;
		else
			*Var   = (*Var < VMax) ? (*Var + 1) : VMax;
	}
	else
	{
		if(bKeyTurbo)
			*Var   = (*Var > (VMin + 1)) ? *Var - 2 : VMin;
		else
			*Var   = (*Var > VMin) ? (*Var - 1) : VMin;
	}
}

void SPREAD_Adjust(unsigned char* variable,unsigned char Key)
{
	if (NOTIFY_LEFT_KEY == Key)
	{
		if (15 <= *variable)
			return;
 
		if (!bKeyTurbo)
			*variable   = 15 > *variable ? *variable + 1 : 15;
		else
			*variable   = 14 > *variable ? *variable + 2 : 15;
	}
	else
	{
		if (0 == *variable)
			return;

		if (!bKeyTurbo)
			*variable   = 0 < *variable ? *variable - 1 : 0;
		else
			*variable   = 1 < *variable ? *variable - 2 : 0;
	}
}


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void Get_OSD_Margin(void)
{
	unsigned char ucH_Min, ucH_Max, ucV_Max;

#if (DISP_ALIGN)
	RTDRead(DH_ACT_STA_27, 0x02, Y_INC);
	Data[2] = Data[1] & 0x07;
	Data[3] = Data[0];

	ucH_Min = (((unsigned int *)Data)[1] / 4) + 1;
	ucH_Max = OSD_HMAX;
#else
	RTDRead(DH_ACT_END_29, 0x02, Y_INC);
	Data[2] = Data[1] & 0x07;
	Data[3] = Data[0];

	//ucH_Max = ((((unsigned int *)Data)[1] - 312 - 8 - 16) / 4) + 1;
	ucH_Max = ((((unsigned int *)Data)[1] - 512) / 4) + 1; 
	ucH_Min = OSD_HMIN;
#endif

	RTDRead(DV_ACT_END_34, 0x02, Y_INC);
	Data[2] = Data[1] & 0x07;
	Data[3] = Data[0];

	ucV_Max = (((unsigned int *)Data)[1] - DV_ACT_STA_POS - 250 - 14) / 4;

	Data[0] = ucH_Min;
	Data[1] = ucH_Max;
	Data[2] = OSD_VMIN;
	Data[3] = ucV_Max;
	
}

// OSD_Position : Restore OSD position according to global settings
// para : OSD font parameter
// OSD_GLOBAL_BLINK    : 0x10
// OSD_DISP_ZONE_LEFT  : 0x04
// OSD_DISP_ZONE_RIGHT : 0x08
// OSD_ROTATE          : 0x02
// OSD_ENABLE          : 0x01

void OSD_Position(unsigned char para)
{
	Get_OSD_Margin();

	if (Data[0] > stGUD1.OSD_POSH || Data[1] < stGUD1.OSD_POSH ||
		Data[2] > stGUD1.OSD_POSV || Data[3] < stGUD1.OSD_POSV)
	{
		stGUD1.OSD_POSV = OSD_VMID;
		stGUD1.OSD_POSH = OSD_HMID;
		Save_GUD1();
	}

		if(ucOSD_Page_Index == PAGE_Factory)		//anson
		{
			stGUD1.OSD_POSH = 230;
			stGUD1.OSD_POSV = 100;
		}

	Wait_For_Event(EVENT_DEN_STOP);

	Data[0]     = 5;
	Data[1]     = Y_INC;
	Data[2]     = OSD_ADDR_MSB_90;
	Data[3]     = 0xc0;
	Data[4]     = 0x00;
	Data[5]     = 6;
	Data[6]     = N_INC;
	Data[7]     = OSD_DATA_92;
	Data[8]     = stGUD1.OSD_POSV >> 1;
	Data[9]     = (unsigned char)(stGUD1.OSD_POSH >> 2);
	Data[10]    = ((unsigned char)(stGUD1.OSD_POSH & 0x0003) << 6) | ((stGUD1.OSD_POSV & 0x01) << 5) | para;
				//+ (unsigned char)(OSD_Enable[10] & 0x1e) + osd_en;
	Data[11]    = 0;
	RTDWrite(Data);

}

void OSD_Line(unsigned char row, unsigned char col, unsigned char length,
              unsigned char value, unsigned char indicate)
{
	unsigned int idata usStart_Addr;
	unsigned char idata ucTemp;

	usStart_Addr = FONT_SELECT_ADDRESS;

	//The address of the first character Cn1 in Row n = FONT_SELECT_ADDRESS + Row0_length + Row1_length +...+Row(n-1)_length
	for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
		usStart_Addr += Row_Info[0][ucTemp];

	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;

	if( (col+1) > Row_Info[0][row + 1])	// if column_start > row_length, then return
		return;
	else if((col + 1 + length) > Row_Info[0][row + 1])	// if column_start + length > row_length, then re-calculate the length
		length = Row_Info[0][row + 1] - col;
    	
	// indicate : 0, 1, 2, 3 set byte 0, 1, 2 and all byte
	Data[3] = (unsigned char)( ((usStart_Addr + col)  & 0x0fff) >> 8 ) | (((indicate << 2) + 1) << 4);
	Data[4] = (unsigned char)((usStart_Addr + col) & 0x00ff);
	Data[5] = 0;  
	RTDWrite(Data);

	Data[0]     = (indicate == 3) ? length * 3 + 3 : length + 3;
	Data[1]     = BURST; 
	Data[2]     = OSD_DATA_92;
	Data[3]     = value;
	Data[4]     = 0;
	RTDWrite(Data);
	
}     


void OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color, unsigned char color_slider)
{
	unsigned int idata usStart_Addr;
	unsigned char idata ucTemp;
	unsigned int bound;

	usStart_Addr = FONT_SELECT_ADDRESS;

	for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
		usStart_Addr += Row_Info[0][ucTemp];

	length = length -5;
	bound   = ((length-2)*6 + 2*3) * value;

	// Set color
	Data[0] = 6;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;
	Data[3] = (unsigned char)((((usStart_Addr + col) >>8 ) & 0x0f ) | 0x90);
	Data[4] = (unsigned char)( (usStart_Addr + col) & 0x00ff);
	Data[5] = (color << 4) & 0xf0;		
	Data[6] = 0;
	RTDWrite(Data);

	Data[0] = 5;
	Data[1] = N_INC;
	Data[2] = OSD_DATA_92;
	Data[3] = (color << 4) & 0xf0;		
	Data[4] = (color << 4) & 0xf0;		
	Data[5] = 0;
	RTDWrite(Data);

	OSD_Line(row,col+5,12,((color_slider<<4) & 0xf0),2);
	Data[0] = 6;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;

	Data[6] = 0;

 	for (row = 0; row < length; row++)
    	{
		Data[3] = (unsigned char)((((usStart_Addr + col + row + 5) >> 8 ) & 0x0f ) | 0x50);
    		Data[4] = (unsigned char)( (usStart_Addr + col + row + 5) & 0x00ff);

		if( row == 0 || row == (length-1) )
		{
			if( bound )
			{
				if( bound >= (range*3) )
				{
					Data[5] = (row==0) ? 0x13 : 0x1e;
					bound = bound - range*3;
				}
				else
				{
			       	color   = (bound << 4) / (range*3);
					bound = 0;
	
					if (4 > color)
						Data[5] = (row==0) ? 0x10 : 0x1b;	
					else if (8 > color)
						Data[5] = (row==0) ? 0x11 : 0x1c;
					else if (12 > color)
						Data[5] = (row==0) ? 0x12 : 0x1d;
					else
						Data[5] = (row==0) ? 0x13 : 0x1e;
				}
			}
			else
			{
				Data[5] = (row==0) ? 0x10 : 0x1b;	
			}
		}
		else
		{
			if( bound )
			{
				if( bound >= (range*6) )
				{
					Data[5] = 0x1a;
					bound = bound - range*6;
				}
				else
				{
					color   = (bound << 4) / (range*6);
					bound = 0;
	
					if (1 > color)
						Data[5] = 0x14;
					else if (4 > color)
						Data[5] = 0x15;
					else if (6 > color)
						Data[5] = 0x16;
					else if (9 > color)
						Data[5] = 0x17;
					else if (11 > color)
						Data[5] = 0x18;
					else if (14 > color)
						Data[5] = 0x19;
					else
						Data[5] = 0x1a;
				}
			}
			else
			{
				Data[5] = 0x14;
			}
		
		}

		RTDWrite(Data);
		
	}

	range	= value / 10;
	row		= value - (range * 10);	// x1
	color	= range / 10;			// x100
	range	= range - (color * 10);	// x10

	row		= row + 0x01;
	range	= (range || color) ? range + 0x01 : 0x00;
	color	= color ? color + 0x01 : 0x00;

	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;
	Data[3] = (unsigned char)((((usStart_Addr + col) >>8 ) & 0x0f ) | 0x50);
	Data[4] = (unsigned char)( (usStart_Addr + col ) & 0x00ff);
	Data[5] = 0;
	RTDWrite(Data);

	Data[0] = 6;
	Data[1] = N_INC;
	Data[2] = OSD_DATA_92;
	Data[3] = color;		// Number x100
	Data[4] = range;		// Number x10
	Data[5] = row;		// Number x1
	Data[6] = 0;
	RTDWrite(Data);

}


void Init_Page(unsigned char index)
{
	index = index;
	OSD_Position(OSD_ENABLE);
	OSD_Clear(5, 11, 15, 1);	//Need to be modified case by case.
	if( ucOSD_Page_Index == 1)
		RTDOSDW(OSD_Window_Setting);
}

void Show_Osd_Page(unsigned char Page_Num,unsigned char* Page_Attr,unsigned char OSD_Table_Num)
{
	Init_Page(Page_Num);
	RTDOSDW(Page_All_Atb);
	RTDOSDW(OSD_PAGE_All_TABLE[0][stGUD1.FUNCTION & 0x07]);
	RTDOSDW(Page_Attr);
	RTDOSDW(OSD_PAGE_TABLE[OSD_Table_Num][stGUD1.FUNCTION & 0x07]);
	Show_Mode();
}

void OSD_Clear(unsigned char row_start, unsigned char height, unsigned char col_start, unsigned char width)
{
	width = width;
	if (height)
	{
		do
		{
			OSD_Line(row_start, col_start, Row_Info[0][row_start+1], 0x00, 3);
			//OSD_Line(row_start, col_start, width, 0x00, 3);
			row_start++;
		}
		while (--height);
	}
}

void Bright_Contrast_Adjust(unsigned char* variable,unsigned char Key)
{
//	if (NOTIFY_RIGHT_KEY == Key)
    if (NOTIFY_LEFT_KEY == Key)
	{
		if (100 <= *variable)
			return;
 
		if (KEY_TURBO_ENABLE > ucKey_Issued)
			*variable   = 100 > *variable ? *variable + 1 : 100;
		else
			*variable   = 99 > *variable ? *variable + 2 : 100;
	}
	else
	{
		if (0 == *variable)
			return;

		if (KEY_TURBO_ENABLE > ucKey_Issued)
			*variable   = 0 < *variable ? *variable - 1 : 0;
		else
			*variable   = 1 < *variable ? *variable - 2 : 0;
	}
}

void Osd_Change_Item(unsigned char Pess_Key,unsigned char Item_Num)
{
	if (ucOSD_Item_Index0)
	{
		// Select and highlight the next/previous item
		//OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
		//	, 0, 0, 14, 251, 0, 1, 0);
		if (NOTIFY_RIGHT_KEY == Pess_Key)
			ucOSD_Item_Index0   = (Item_Num == ucOSD_Item_Index0) ? 1 : (ucOSD_Item_Index0 + 1);
		else
			ucOSD_Item_Index0   = (1 == ucOSD_Item_Index0) ? Item_Num : (ucOSD_Item_Index0 - 1);

		// Move window 6
		OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
			, 1, 1, 14, 251, 0, 1, 25);
	}
	else
	{
		// Change to next/previous main page
		//OSD_Window( 5, 150, 282, (54 + (ucOSD_Page_Index-1)*(29+4)), (84 + (ucOSD_Page_Index-1)*(29+4))
		//	, 0, 0, 14, 251, 0, 1, 0);
		if (NOTIFY_RIGHT_KEY == Pess_Key)
			ucOSD_Page_Index    = GetNextPageIdx(ucOSD_Page_Index);
		else
			ucOSD_Page_Index    = GetPrevPageIdx(ucOSD_Page_Index);
	} 
}

void Show_Mode(void)
{
	unsigned int idata usStart_Addr;
	unsigned char idata ucTemp;

	OSD_Line(3, 12, 15, 0, 1);                       // Attribute
	usStart_Addr = FONT_SELECT_ADDRESS;

	//The address of the first character Cn1 in Row n = FONT_SELECT_ADDRESS + Row0_length + Row1_length +...+Row(n-1)_length
	for(ucTemp = 1; ucTemp < 3+1; ucTemp ++)
		usStart_Addr += Row_Info[0][ucTemp];

	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;
	Data[3] = (unsigned char)( (((usStart_Addr + 12)  & 0x0fff) >> 8 ) | 0x50);
	Data[4] = (unsigned char)( (usStart_Addr + 12) & 0x00ff);
	Data[5] = 0;
	RTDWrite(Data);
	
	

	switch (ucMode_Curr)
	{   
	/*
		case MODE_NOSIGNAL:     // NO SIGNAL
			OSD_Line(11, 2, 24, CHINESE_T <= (stGUD1.FUNCTION & 0x07) ? 0x80 | COLOR_BLUE : COLOR_BLUE, 0);

			if ((SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07)) && (VGA_ONLINE != bVGA_CONNECT))
				RTDOSDW(OSD_REMK_TABLE[0][stGUD1.FUNCTION & 0x07]);
			else
				RTDOSDW(OSD_REMK_TABLE[1][stGUD1.FUNCTION & 0x07]);
			break;

		case MODE_UNDEFINED0:
		case MODE_UNDEFINED1:
		case MODE_NOSUPPORT:
			OSD_Line(11, 2, 24, CHINESE_T <= (stGUD1.FUNCTION & 0x07) ? 0x80 | COLOR_BLUE : COLOR_BLUE, 0);
			RTDOSDW(OSD_REMK_TABLE[2][stGUD1.FUNCTION & 0x07]);
			break;

		case MODE_VIDEO60HZ:    // NTSC 60HZ
			OSD_Line(11, 2, 24, COLOR_BLUE, 0);     // Set characters to blue
			RTDCodeW(Remark_Mode);

			switch(ucAV_Mode)
			{
				case 0x01:  RTDCodeW(Remark_V60_0); break;
				case 0x11:  RTDCodeW(Remark_V60_1); break;
				case 0x21:  RTDCodeW(Remark_V60_2); break;
				case 0x31:  RTDCodeW(Remark_V60_3); break;
				case 0x41:  RTDCodeW(Remark_V60_4); break;
				case 0x03:  RTDCodeW(Remark_V60_5); break;
			}
			break;
			
		case MODE_VIDEO50HZ:    // PAL 50HZ
			OSD_Line(11, 2, 24, COLOR_BLUE, 0);     // Set characters to blue
			RTDCodeW(Remark_Mode);

			switch(ucAV_Mode)
			{   
				case 0x02:  RTDCodeW(Remark_V50_0); break;
				case 0x12:  RTDCodeW(Remark_V50_1); break;
				case 0x22:  RTDCodeW(Remark_V50_2); break;
				case 0x32:  RTDCodeW(Remark_V50_3); break;
				case 0x03:  RTDCodeW(Remark_V50_5); break;
			}
			break;

		case MODE_YUV60HZ:
		case MODE_YUV50HZ:
		break;
*/
		default :
			//OSD_Line(11, 2, 24, COLOR_BLUE, 0);     // Set characters to blue

			{
			unsigned int    usHwid;
			unsigned char   ucTemp;

			usHwid  = usIPH_ACT_WID;

			if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07))
			{
				if (MODE_1600x1200x60HZ == ucMode_Curr)
				{
					usHwid  = 1600;
				}
				else 
				{
					if (MODE_1600x1200x60HZ > ucMode_Curr)
					{
						if (MODE_1280x0960x60HZ <= ucMode_Curr)
							usHwid  = 1280;
						else if (MODE_1152x0864x75HZ <= ucMode_Curr)
						usHwid  = 1152;
					}
					else
					{
						if (MODE_USER1600x1200 == ucMode_Curr)
							usHwid  = 1600;
						else if (MODE_USER1280x960 <= ucMode_Curr)
							usHwid  = 1280;
						else if (MODE_USER1152x864 <= ucMode_Curr)
							usHwid  = 1152;
					}
				}
					//anson 050512
				if	((MODE_0640x0400x70HZ == ucMode_Curr)||(MODE_0720x0400x70HZ == ucMode_Curr))
				{
					if(stGUD1.FUNCTION & 0x10)
						usHwid  = 640;
					else
						usHwid  = 720;
				}
			}

			//RTDCodeW(Remark_Mode);

			Data[0] = 12;
			Data[1] = N_INC;
			Data[2] = OSD_DATA_92;

			ucTemp  = usHwid / 100;

			if (10 <= ucTemp)
			{
				Data[3] = _1_;
				Data[4] = ucTemp - 10 + _0_;
			}
			else
			{
				Data[3] = 0;
				Data[4] = ucTemp + _0_;
			}

			ucTemp  = usHwid - ((unsigned int)100 * ucTemp);
        
			Data[5] = ucTemp / 10;
			
			Data[6] = ucTemp - (10 * Data[5]) + _0_;
			Data[5] = Data[5] + _0_;
			Data[7] = 0x0e;

			ucTemp      = usIPV_ACT_LEN / 100;
			Data[12]    = usIPV_ACT_LEN - ((unsigned int)100 * ucTemp);

			if (10 <= ucTemp)
			{
				Data[0]     = 13;
				Data[8]     = _1_;
				Data[9]     = ucTemp - 10 + _0_;
				Data[10]    = Data[12] / 10;
				Data[11]    = Data[12] - (10 * Data[10]) + _0_;
				Data[10]    = Data[10] + _0_;
				Data[12]    = 0x00;
				Data[13]    = 0;
			}
			else
			{
				Data[8]     = ucTemp + _0_;
				Data[9]     = Data[12] / 10;
				Data[10]    = Data[12] - (10 * Data[9]) + _0_;
				Data[9]     = Data[9] + _0_;
				Data[11]    = 0x00;
				Data[12]    = 0;
			}

			Data[12]    = 0;
			RTDWrite(Data);

			// Show Refresh Rate
			//RTDCodeW(Remark_Rate);

			Data[0] = 7;
			Data[1] = N_INC;
			Data[2] = OSD_DATA_92;
			Data[3] = ucRefresh / 10;
			Data[4] = ucRefresh - (Data[3] * 10) + _0_;
			Data[3] = Data[3] + _0_;
			Data[5] = 0x27;
			Data[6] = 0x59;
			Data[7] = 0;
			RTDWrite(Data);
			if (10 <= ucTemp)
				OSD_Line( 3, 21, 1, 0x8c, 0);
			else
				OSD_Line( 3, 20, 1, 0x8c, 0);
			}

			break;
			
	}
}   

///////////////////////////////////////////////////////////////////////////////////////////
//anson
///////////////////////////////////////////////////////////////////////////////////////////
void FACTORY_Key_Key(void)
{
	ucOSD_Page_Index = PAGE_Factory;
	ucOSD_Item_Index0 = PAGEFact_ITEM_Recall;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

void Page0_Left_Right_Key(unsigned char Key)
{
//    RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
// Although you can add ending animation here, I don't think it is necessary.
//    RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
//    RTDOSDW(OSD_Reset);            // Clear OSD
	//usOSD_Timer         = 5;     // 20 sec
    if (!b_rgb_VOLUME_STATUS)
    {
      OSD_Position(OSD_ENABLE);
      RTDOSDW(rgb_OSD_VOLUME);
	RTDOSDW(strTabVOLUME_Atb[stGUD1.FUNCTION & 0x07]);		//anson
      RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
      b_rgb_VOLUME_STATUS = 1;
    }
	//OSD_Window( 5, 10, 136, 54, 84, 1, 1, 14, 251, 0, 1, 25);
	if(NOTIFY_LEFT_KEY == Key)
	{
        if (stGUD3.VOLUME > 0x00) stGUD3.VOLUME--;
        SetVolume();
        Save_GUD3();
		rgb_OSD_Slider(0, 7, 24, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
	}

	else if(NOTIFY_RIGHT_KEY == Key)
	{
        if (stGUD3.VOLUME < 0x1f) stGUD3.VOLUME++;
        SetVolume();
        Save_GUD3();
		rgb_OSD_Slider(0, 7, 24, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
    }


}

void Page0_Enter_Key(void)
{
	if((stGUD3.TV_SETTING & 0x08) == 0x08 )//Factory Mode		//anson
	{
		//Into Factory mode
		ucOSD_Page_Index    = PAGE_Factory;
		ucOSD_Item_Index0   = PAGEFact_ITEM_Recall;
		ucOSD_Item_Index1   = 0;
		ucOSD_Item_Index2   = 0;
	}
	else
	{
		// Change to OSD Main Page 1 and Main Program will show it
		ucOSD_Page_Index    = 1;
		ucOSD_Item_Index0   = 0;
		ucOSD_Item_Index1   = 0;
		ucOSD_Item_Index2   = 0;
		b_rgb_VOLUME_STATUS = 0;
	}
}

void Page0_LR_Key(void)
{
	// Go to Hidden Function Page
	if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07))
	{
		ucOSD_Page_Index    = 8;
		ucOSD_Item_Index0   = 1;
		ucOSD_Item_Index1   = 0;
		ucOSD_Item_Index2   = 0;
	}
}

void Page1_Enter_Key(void)
{
	if (0 == ucOSD_Item_Index0)
	{
		if (MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
		{
			// Select and highlight the first item
			ucOSD_Item_Index0   = PAGE1_ITEM_CONTRAST;
			ucOSD_Item_Index1   = 0;

			//Enable window 6 and draw it
			//OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
// win_no, row_start, row_end,col_start,col_end, width, height, color, color_sb, gradient, gray_level, attr
            OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
		}
	}
	else
	{
		if (ucOSD_Item_Index1)
		{
			// Leave the item and reset text color
			switch (ucOSD_Item_Index0)
			{
				case PAGE1_ITEM_AUTOBAL :
                    if (ucOSD_Item_Index1 == 1 ) //1 : Yes  ,   2 : No
                    {
						if (ERROR_INPUT == Auto_Balance())
						{
							ucMode_Curr = MODE_OSDFORCE;
							return ;
						}
                    }
					OSD_Line( 13, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x40, 2);
					break;

				case PAGE1_ITEM_CONTRAST :
					// Redraw slider and make the number become black.
					OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 4, 14);
					break;

				case PAGE1_ITEM_BRIGHT :
					// Redraw slider and make the number become black.
					OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 4, 14);
					break;

				case PAGE1_ITEM_COLORTEMP :
					//Set words color to black
					OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x40, 2);
					break;

				case PAGE1_ITEM_GAMMA :
					//Set words color to black
					OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x40, 2);
					break;
			}

			ucOSD_Item_Index1   = 0;

		}
		else
		{
			if (PAGE1_ITEM_EXIT == ucOSD_Item_Index0)
			{
				// Disable highlight window 6
				OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
					, 0, 0, 14, 251, 0, 1, 0);
				// De-select the page item and disable the hightlight window
				ucOSD_Item_Index0   = 0;
				ucOSD_Item_Index1   = 0;
			}
			else if (MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
			{
				switch (ucOSD_Item_Index0)
				{
					case PAGE1_ITEM_AUTOBAL :
                        ucOSD_Item_Index1  = 2;
						OSD_Line( 13, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
						break;

					case PAGE1_ITEM_CONTRAST :
						ucOSD_Item_Index1   = 1;

						// Redraw slider and make the number become Red.
						OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 2, 14);
						break;

					case PAGE1_ITEM_BRIGHT :
						ucOSD_Item_Index1   = 1;

						// Redraw slider and make the number become Red.
						OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 2, 14);
						break;

					case PAGE1_ITEM_COLORTEMP :
						ucOSD_Item_Index1 = ((stGUD1.INPUT_SOURCE & 0x18) >> 3) + 1;

						//Here we can only change the color in Byte 2 for necessary words
						OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x20, 2);
						break;

					case PAGE1_ITEM_GAMMA :
						ucOSD_Item_Index1   = ((stGUD1.FUNCTION >> 5) & 0x03) + 1;

						//Here we can only change the color in Byte 2 for necessary words
						OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
						break;

					case PAGE1_ITEM_RGBADJ :
						OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
							, 0, 0, 14, 251, 0, 1, 0);
						ucOSD_Item_Index1   = PAGE1B_ITEM_RED;
						ucOSD_Item_Index2   = 0;
						OSD_Proc_B(NOTIFY_SHOW);       // Show the sub-page
						break;
				}
			}
		}
	}
}

void Page1_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		switch (ucOSD_Item_Index0)
		{
    		case PAGE1_ITEM_AUTOBAL :
//           		ucOSD_Item_Index1   = (NOTIFY_LEFT_KEY == Key) ? 1 : 2;
           		ucOSD_Item_Index1   = (NOTIFY_RIGHT_KEY == Key) ? 1 : 2;
				OSD_Line( 13, 36, 14, 0x40, 2);	//Set color to black
				OSD_Line( 13, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
				break;

			case PAGE1_ITEM_CONTRAST :
				Bright_Contrast_Adjust(&stGUD0.CONTRAST,Key);

				OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 2, 14);

#if(ANALOG_CONTRAST)
				if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
					SetADC_Gain();
				else
					Set_Bright_Contrast();
#else
				Set_Bright_Contrast();
#endif

				Save_GUD0();
				break;

			case PAGE1_ITEM_BRIGHT :
				Bright_Contrast_Adjust(&stGUD0.BRIGHT,Key);
		
				OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 2, 14);
				Set_Bright_Contrast();
				Save_GUD0();
				break;

			case PAGE1_ITEM_COLORTEMP:
//				if(NOTIFY_RIGHT_KEY == Key)
				if(NOTIFY_LEFT_KEY == Key)
					ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 4) ? 4 : ucOSD_Item_Index1 + 1;
				else
					ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 1) ? 1 : ucOSD_Item_Index1 - 1;

				stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xe7 ) | ((ucOSD_Item_Index1 - 1) << 3);

				//Here we can only change the color in Byte 2 for necessary words
				OSD_Line( 11, 36, 20, 0x40, 2);	//Set color to black
				OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x20, 2);

				Set_Bright_Contrast();
				Save_GUD1();
				break;
				
			case PAGE1_ITEM_GAMMA :
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (4 <= ucOSD_Item_Index1)
						break;

					ucOSD_Item_Index1   = ucOSD_Item_Index1 + 1;
				}
				else
				{
					if (1 >= ucOSD_Item_Index1)
						break;

					ucOSD_Item_Index1   = ucOSD_Item_Index1 - 1;
				}

				stGUD1.FUNCTION = (stGUD1.FUNCTION & 0x9f) | ((ucOSD_Item_Index1 - 1) << 5);
				//Here we can only change the color in Byte 2 for necessary words
				OSD_Line( 9, 36, 14, 0x40, 2);	//Set color to black
				OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);

				Set_Gamma();
				Save_GUD1();
				break;
            
		}
	}
	else
	{
		Osd_Change_Item(Key,PAGE1_ITEM_NUM);
		
	}
}

void Page1_Show(void)
{
	Show_Osd_Page(0,Page1_Atb,0);

	//Set Window 5 to select "Colour"
	OSD_Window( 5, 10, 136, 54, 84, 1, 1, 14, 251, 0, 1, 25);

	if (MODE_NOSIGNAL == ucMode_Curr || MODE_NOSUPPORT == ucMode_Curr)
	{
		//ucOSD_Item_Index0   = 0;
		//ucOSD_Item_Index1   = 0;
	}

	OSD_Slider(5, 31, 17, stGUD0.CONTRAST, 100, 4, 14);
	OSD_Slider(7, 31, 17, stGUD0.BRIGHT, 100, 4, 14);
	
	switch (ucOSD_Item_Index0)
	{
		case PAGE1_ITEM_CONTRAST :
			break;
			
		case PAGE1_ITEM_BRIGHT :
			break;
			
		case PAGE1_ITEM_GAMMA :
			break;
			
		case PAGE1_ITEM_RGBADJ :
			OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
				, 1, 1, 14, 251, 0, 1, 25);
			break;
	}
}

void Page1B_Enter_Key(void)
{
	ucOSD_Page_Index = 7;
	if (PAGE1B_ITEM_EXIT == ucOSD_Item_Index1)
	{
		// De-select the page item and disable the hightlight window
		OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
			, 0, 0, 14, 251, 0, 1, 0);
		ucOSD_Item_Index1   = 0;
		ucOSD_Item_Index2   = 0;
	}
	else
	{
		if (ucOSD_Item_Index2)
		{
			ucOSD_Item_Index2   = 0;	// Leave the item
			switch (ucOSD_Item_Index1)
			{
				case PAGE1B_ITEM_RED :
					OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 4, 2);
					break;
				
				case PAGE1B_ITEM_GREEN :
					OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 4, 12);
					break;
				
				case PAGE1B_ITEM_BLUE :
					OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 4, 3);
					break;
			}
		}
		else if (MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
		{
			ucOSD_Item_Index2   = 1;	// Enter the item

			//Draw the selected slider
			switch (ucOSD_Item_Index1)
			{
				case PAGE1B_ITEM_RED :
					OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 2, 2);
					break;
				
				case PAGE1B_ITEM_GREEN :
					OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 12, 12);
					break;
				
				case PAGE1B_ITEM_BLUE :
					OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 3, 3);
					break;
			}
		}
	}
	ucOSD_Page_Index = 1;
}

void Page1B_Left_Right_Key(unsigned char Key)
{
	ucOSD_Page_Index = 7;
	if (ucOSD_Item_Index2)
	{
		switch (ucOSD_Item_Index1)
		{
			case PAGE1B_ITEM_RED :
				Bright_Contrast_Adjust(&stGUD0.RTD_R_CONTRAST,Key);
		
				OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 2, 2);
				break;
				
			case PAGE1B_ITEM_GREEN :
				Bright_Contrast_Adjust(&stGUD0.RTD_G_CONTRAST,Key);
			
				OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 12, 12);
				break;
				
			case PAGE1B_ITEM_BLUE :
				Bright_Contrast_Adjust(&stGUD0.RTD_B_CONTRAST,Key);
			
				OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 3, 3);
				break;
		}

		Set_Bright_Contrast();
		Save_GUD0();
		
	}
	else
	{
		// Select and highlight the next/previous item
		if (NOTIFY_RIGHT_KEY == Key)
			ucOSD_Item_Index1   = (PAGE1B_ITEM_NUM == ucOSD_Item_Index1) ? 1 : (ucOSD_Item_Index1 + 1);
		else
			ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? PAGE1B_ITEM_NUM : (ucOSD_Item_Index1 - 1);
            
		OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index1-1)*(29+4)), (84 + (ucOSD_Item_Index1-1)*(29+4))
			, 1, 1, 14, 251, 0, 1, 25);
	}
	ucOSD_Page_Index = 1;
}

void Page1B_Show(void)
{
	Show_Osd_Page(0,Page7_Atb,6);

	// Set window 6 to Highlight the select item
	OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
	
	if (MODE_NOSIGNAL == ucMode_Curr || MODE_NOSUPPORT == ucMode_Curr)      
		ucOSD_Item_Index2   = 0;

	if (0 == ucOSD_Item_Index2)
	{
		ucOSD_Page_Index = 7;
		OSD_Slider(5, 31, 17, stGUD0.RTD_R_CONTRAST, 100, 4, 2);
		OSD_Slider(7, 31, 17, stGUD0.RTD_G_CONTRAST, 100, 4, 12);
		OSD_Slider(9, 31, 17, stGUD0.RTD_B_CONTRAST, 100, 4, 3);
		ucOSD_Page_Index = 1;
	}
	else
	{
		//Set the active slider (Red, Greed, Blue)
		/*
		OSD_Slider(11, 2, 20,
			(PAGE1B_ITEM_RED == ucOSD_Item_Index1) ? stGUD0.RTD_R_CONTRAST 
			: (PAGE1B_ITEM_GREEN == ucOSD_Item_Index1) ? stGUD0.RTD_G_CONTRAST
			: stGUD0.RTD_B_CONTRAST, 100, 0x61);

		*/
	}
}

void Page2_Enter_Key()
{
	if (0 == ucOSD_Item_Index0)
	{
		if (MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
		{
			// Select and highlight the first item
			ucOSD_Item_Index0   = PAGE2_ITEM_POSH;
			ucOSD_Item_Index1   = 0;

			//Enable Window 6 and Draw it
			OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
		}
	}
	else
	{
		if (ucOSD_Item_Index1)
		{
			switch (ucOSD_Item_Index0)
			{
				case PAGE2_ITEM_POSH :
					OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 4, 14);
					break;

				case PAGE2_ITEM_POSV :
					OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 4, 14);
					break;
					
				case PAGE2_ITEM_PHASE :
#if(MORE_PHASE)
					OSD_Slider(11, 31, 17, stMUD.PHASE, 127, 4, 14);
#else
					OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 4, 14);
#endif
					break;
					
				case PAGE2_ITEM_CLOCK :

#if(ALIGN_LEFT == CLOCK_ALIGN)
                    OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 4, 14);
#else
					OSD_Slider(13, 31, 17, stMUD.CLOCK - 28, 200, 4, 14);
#endif
					break;

				case PAGE2_ITEM_SHARP :
					OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x40, 2);
					break;
												
			}

			ucOSD_Item_Index1   = 0;    // Leave the item
			
		}
		else
		{
			if (PAGE2_ITEM_EXIT == ucOSD_Item_Index0)
			{
				// Disable Window 6 and Draw it
				OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
					, 0, 0, 14, 251, 0, 1, 0);
				// De-select the page item and disable the hightlight window
				ucOSD_Item_Index0   = 0;
				ucOSD_Item_Index1   = 0;
			}
			else if (MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
			{
				if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07) || PAGE2_ITEM_SHARP == ucOSD_Item_Index0)
				{
					switch (ucOSD_Item_Index0)
					{
						case PAGE2_ITEM_POSH :
							ucOSD_Item_Index1   = 1;    // Enter the item
							OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 2, 14);
							break;
							
						case PAGE2_ITEM_POSV :
							ucOSD_Item_Index1   = 1;    // Enter the item
							OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 2, 14);
							break;
							
						case PAGE2_ITEM_PHASE :
							ucOSD_Item_Index1   = 1;    // Enter the item
#if(MORE_PHASE)
							OSD_Slider(11, 31, 17, stMUD.PHASE, 127, 2, 14);
#else
							OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 2, 14);
#endif
							break;
							
						case PAGE2_ITEM_CLOCK :
							ucOSD_Item_Index1   = 1;    // Enter the item
#if(ALIGN_LEFT == CLOCK_ALIGN)
                            OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 2, 14);
#else
							OSD_Slider(13, 31, 17, stMUD.CLOCK - 28, 200, 2, 14);
#endif
							break;

						case PAGE2_ITEM_SHARP :
							ucOSD_Item_Index1   = stGUD1.FILTER + 1;
							OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
							break;
												
					}
				}
			}
		}
	}
}

void Page2_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE2_ITEM_POSH :
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (ucH_Min_Margin >= stMUD.H_POSITION)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stMUD.H_POSITION    = stMUD.H_POSITION > ucH_Min_Margin ? stMUD.H_POSITION - 1 : ucH_Min_Margin;
					else
						stMUD.H_POSITION    = stMUD.H_POSITION > (ucH_Min_Margin + 2) ? stMUD.H_POSITION - 3 : ucH_Min_Margin;
				}
				else
				{
					if (ucH_Max_Margin <= stMUD.H_POSITION)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stMUD.H_POSITION    = stMUD.H_POSITION < ucH_Max_Margin ? stMUD.H_POSITION + 1 : ucH_Max_Margin;
					else
						stMUD.H_POSITION    = stMUD.H_POSITION < (ucH_Max_Margin - 2) ? stMUD.H_POSITION + 3 : ucH_Max_Margin;
				}

				OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 2, 14);
				Set_H_Position();
				Set_Phase(stMUD.PHASE);
				Save_MUD(ucMode_Curr);
				break;
				
			case PAGE2_ITEM_POSV :
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if ((unsigned int)256 - ucV_Min_Margin <= stMUD.V_POSITION)
						break;

					stMUD.V_POSITION    += 1;
				}
				else
				{
					if (ucV_Min_Margin >= stMUD.V_POSITION)
						break;

					stMUD.V_POSITION    -= 1;
				}

				OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 2, 14);
				Set_V_Position();
				Save_MUD(ucMode_Curr);
				break;
								
			case PAGE2_ITEM_PHASE :
#if(MORE_PHASE)
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (0x7f <= stMUD.PHASE)
						break;

					stMUD.PHASE += 1;
				}
				else
				{
					if (0x00 == stMUD.PHASE)
						break;

					stMUD.PHASE -= 1;
				}

				OSD_Slider(11, 31, 17, stMUD.PHASE, 127, 2, 14);
#else
				stMUD.PHASE     &= 0x7c;
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (0x7c <= stMUD.PHASE)
						break;

					stMUD.PHASE += 4;
				}
				else
				{
					if (0x00 == stMUD.PHASE)
						break;

					stMUD.PHASE -= 4;
				}
					
				OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 2, 14);
#endif
				Set_Phase(stMUD.PHASE);
				Save_MUD(ucMode_Curr);
				break;
					
			case PAGE2_ITEM_CLOCK :
#if(ALIGN_LEFT == CLOCK_ALIGN)
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (178 <= stMUD.CLOCK)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stMUD.CLOCK = (177 >= stMUD.CLOCK) ? stMUD.CLOCK + 1 : 178;
					else
						stMUD.CLOCK = (176 >= stMUD.CLOCK) ? stMUD.CLOCK + 2 : 178;
                    
					Set_Clock();
					Set_H_Position();
				}
				else
				{
					if (78 >= stMUD.CLOCK)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stMUD.CLOCK = (79 <= stMUD.CLOCK) ? stMUD.CLOCK - 1 : 78;
					else
						stMUD.CLOCK = (80 <= stMUD.CLOCK) ? stMUD.CLOCK - 2 : 78;

					Set_H_Position();
					Set_Clock();
				}

				OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 2, 14);

#else
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (228 <= stMUD.CLOCK)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stMUD.CLOCK = (227 >= stMUD.CLOCK) ? stMUD.CLOCK + 1 : 228;
					else
						stMUD.CLOCK = (226 >= stMUD.CLOCK) ? stMUD.CLOCK + 2 : 228;
                    
					Set_Clock();
					Set_H_Position();
				}
				else
				{
					if (28 >= stMUD.CLOCK)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stMUD.CLOCK = (29 <= stMUD.CLOCK) ? stMUD.CLOCK - 1 : 28;
					else
						stMUD.CLOCK = (30 <= stMUD.CLOCK) ? stMUD.CLOCK - 2 : 28;

					Set_H_Position();
					Set_Clock();
				}

				OSD_Slider(13, 31, 17, stMUD.CLOCK - 28, 200, 2, 14);
#endif
				Save_MUD(ucMode_Curr);
				break;

			case PAGE2_ITEM_SHARP :
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (5 <= ucOSD_Item_Index1)
						break;

					ucOSD_Item_Index1   = ucOSD_Item_Index1 + 1;
				}
				else
				{
					if (1 >= ucOSD_Item_Index1)
						break;

					ucOSD_Item_Index1   = ucOSD_Item_Index1 - 1;
				}

				OSD_Line( 9, 36, 14, 0x40, 2);	//Set color to black
				OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(2+1), 1, 0x20, 2);
				
				stGUD1.FILTER    = ucOSD_Item_Index1 - 1;
				Sharpness();
                
				if((usIPH_ACT_WID == 1280) && (DISP_SIZE == DISP_1280x1024) && (stGUD1.FILTER == 0x02))
					RTDSetBit(SCALE_CTRL_15, 0xff, 0x01);   // Turn on H scale-up
				else if((usIPH_ACT_WID == 1280) && (DISP_SIZE == DISP_1280x1024) && (stGUD1.FILTER != 0x02))
					RTDSetBit(SCALE_CTRL_15, 0xfe, 0x00);   // Turn off H scale-up

                		Save_GUD1();
				break;
			
					
		}
	}
	else
	{
		Osd_Change_Item(Key,PAGE2_ITEM_NUM);
	}
}


void Page2_Show()
{
	Show_Osd_Page(1,Page2_Atb,1);

	//Set Window 5 to select "Picture"
	OSD_Window( 5, 10, 136, 87, 117, 1, 1, 14, 251, 0, 1, 25);

	if (MODE_NOSIGNAL == ucMode_Curr || MODE_NOSUPPORT == ucMode_Curr)
	{
		ucOSD_Item_Index0   = 0;
		ucOSD_Item_Index1   = 0;
	}

	if (SOURCE_VGA != (stGUD1.INPUT_SOURCE & 0x07) && PAGE2_ITEM_SHARP != ucOSD_Item_Index0)
	{
		ucOSD_Item_Index1   = 0;
	}

	if (0 == ucOSD_Item_Index1)
	{
		OSD_Slider(5, 31, 17, ucH_Max_Margin - stMUD.H_POSITION, ucH_Max_Margin - ucH_Min_Margin, 4, 14);
		OSD_Slider(7, 31, 17, (unsigned int)(stMUD.V_POSITION - ucV_Min_Margin) * 50 / (128 - ucV_Min_Margin), 100, 4, 14);
#if(MORE_PHASE)
		OSD_Slider(11, 31, 17, stMUD.PHASE, 127, 4, 14);
#else
		OSD_Slider(11, 31, 17, (stMUD.PHASE & 0x7c) >> 2, 31, 4, 14);
#endif

#if(ALIGN_LEFT == CLOCK_ALIGN)
        OSD_Slider(13, 31, 17, stMUD.CLOCK - 78, 100, 4, 14);
#else
		OSD_Slider(13, 31, 17, stMUD.CLOCK - 28, 200, 4, 14);
#endif
	}
	else
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE2_ITEM_POSH :
				break;
				
			case PAGE2_ITEM_POSV :
				break;
				
			case PAGE2_ITEM_PHASE :
				break;
				
			case PAGE2_ITEM_CLOCK :
				break;

			case PAGE2_ITEM_SHARP :
				break;
		}
	}
}

/*
bit Page3_Enter_Key(void)
{
	if (0 == ucOSD_Item_Index0)
	{
		if ((MODE_NOSIGNAL != ucMode_Curr) && (MODE_NOSUPPORT != ucMode_Curr) && (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07)))
		{
			// Select and highlight the first item
			ucOSD_Item_Index0   = PAGE3_ITEM_AUTOCFG;
			ucOSD_Item_Index1   = 0;
			
			OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
		}
	}
	else
	{
		if (PAGE3_ITEM_EXIT == ucOSD_Item_Index0)
		{
			// Disable highlight window
			OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
				, 0, 0, 14, 251, 0, 1, 0);
			// De-select the page item and disable the hightlight window
			ucOSD_Item_Index0   = 0;
			ucOSD_Item_Index1   = 0;
		}
		else if (ucOSD_Item_Index1)
		{
			if (1 == ucOSD_Item_Index1)
			{
				switch (ucOSD_Item_Index0)
				{
					case PAGE3_ITEM_AUTOCFG :
						if (MODE_0640x0350x70HZ <= ucMode_Curr && MODE_0720x0400x70HZ >= ucMode_Curr)
						{
							unsigned char ucResult;

							stMUD.CLOCK = 128;

							Set_H_Position();
							Set_Clock();
							Save_MUD(ucMode_Curr);

							ucResult    = Auto_Phase();

							if (ERROR_SUCCEED == ucResult)
							{
								ucResult    = Auto_Position();
							}
							
							if (ERROR_INPUT == ucResult)
							{
								ucMode_Curr = MODE_OSDFORCE;
								return 0;
							}
						}
						else
						{
							if (ERROR_INPUT == Auto_Config())
                            {
								ucMode_Curr = MODE_OSDFORCE;
								return 0;
							}
						}

						OSD_Line( 5, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x40, 2);
						break;

					case PAGE3_ITEM_AUTOBAL :
						if (ERROR_INPUT == Auto_Balance())
						{
							ucMode_Curr = MODE_OSDFORCE;
							return 0;
						}

						OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x40, 2);
						break;
						
				}
			}
			
			switch (ucOSD_Item_Index0)
			{
					case PAGE3_ITEM_AUTOCFG :
						OSD_Line( 5, 36, 14, 0x40, 2);	//Set color to black
						break;
					case PAGE3_ITEM_AUTOBAL :
						OSD_Line( 7, 36, 14, 0x40, 2);	//Set color to black
						break;
			}
			ucOSD_Item_Index1   = 0;    // Leave the item
			//Show_Mode();
		}
		else
		{
			if (MODE_NOSIGNAL == ucMode_Curr || MODE_NOSUPPORT == ucMode_Curr)  
				return 1;//break;

			ucOSD_Item_Index1   = 2;    // Enter the item, default NO

			switch (ucOSD_Item_Index0)
			{
					case PAGE3_ITEM_AUTOCFG :
						OSD_Line( 5, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
						break;
					case PAGE3_ITEM_AUTOBAL :
						OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
						break;
			}
		}
	}
}
*/

/*
void Page3_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		ucOSD_Item_Index1   = (NOTIFY_LEFT_KEY == Key) ? 1 : 2;

		switch (ucOSD_Item_Index0)
		{
				case PAGE3_ITEM_AUTOCFG :
					OSD_Line( 5, 36, 14, 0x40, 2);	//Set color to black
					OSD_Line( 5, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
					break;
				case PAGE3_ITEM_AUTOBAL :
					OSD_Line( 7, 36, 14, 0x40, 2);	//Set color to black
					OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
					break;
		}
	}
	else
	{
		Osd_Change_Item(Key,PAGE3_ITEM_NUM);
	}
}

void Page3_Show(void)
{
	Show_Osd_Page(2,Page3_Atb,2);

	//Set Window 5 to select "Functuin"
	OSD_Window( 5, 10, 136, 120, 150, 1, 1, 14, 251, 0, 1, 25);

	if (MODE_NOSIGNAL == ucMode_Curr || MODE_NOSUPPORT == ucMode_Curr)
	{
		ucOSD_Item_Index0   = 0;
		ucOSD_Item_Index1   = 0;
	}
}
*/

void Page4_Enter_Key(void)
{
	if (0 == ucOSD_Item_Index0)
	{
		// Select and highlight the first item
		ucOSD_Item_Index0   = PAGE4_ITEM_LANGUAGE;
		ucOSD_Item_Index1   = 0;

		OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
	}
	else
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE4_ITEM_LANGUAGE :
				ucOSD_Item_Index1 = (stGUD1.FUNCTION & 0x07) + 1;
				OSD_Proc_B(NOTIFY_SHOW);		// Show the sub-page
				break;
				
			case PAGE4_ITEM_OSDH :
				if (ucOSD_Item_Index1)
				{
					ucOSD_Item_Index1 = 0;		// Leave the item
					Get_OSD_Margin();
					OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 4, 14);
				}
				else
				{
					ucOSD_Item_Index1 = 1;    // Enter the item, show slider
					Get_OSD_Margin();
					OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 2, 14);
				}
				break;
				
			case PAGE4_ITEM_OSDV :
				if (ucOSD_Item_Index1)
				{
					ucOSD_Item_Index1   = 0;    // Leave the item
					Get_OSD_Margin();
					OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 4, 14);
				}
				else
				{
					ucOSD_Item_Index1   = 1;    // Enter the item, slider
					Get_OSD_Margin();
					OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 2, 14);
				}
				break;
				
			case PAGE4_ITEM_TIMEOUT :
				if(ucOSD_Item_Index2)
				{
					ucOSD_Item_Index2   = 0;
					ucOSD_Item_Index1   = 0;    // Leave the item

					//Redraw the ON/OFF words
					OSD_Line( 11, 31, 3, 0x40, 2);
					OSD_Line( 11, 31, 3, 0x00, 1);

					OSD_Line( 11, 36, 12, 0x8a, 0);
					OSD_Line( 11, 36, 12, 0x00, 1);
					switch( stGUD1.FUNCTION & 0x07 )
					{
						case 5:
							OSD_Line( 11, 37, 1, 0x8c, 0);
							OSD_Line( 11, 37, 1, 0xb3, 1);
							OSD_Line( 11, 43, 1, 0x8c, 0);
							OSD_Line( 11, 43, 1, 0xc9, 1);
							break;

						case 6:
							OSD_Line( 11, 37, 1, 0x8c, 0);
							OSD_Line( 11, 37, 1, 0xdb, 1);
							OSD_Line( 11, 43, 1, 0x8c, 0);
							OSD_Line( 11, 43, 1, 0xe5, 1);
							break;

						case 7:
							OSD_Line( 11, 37, 1, 0x8c, 0);
							OSD_Line( 11, 37, 1, 0x9b, 1);
							OSD_Line( 11, 43, 1, 0x8c, 0);
							OSD_Line( 11, 43, 1, 0x9c, 1);
							break;

						default:
							OSD_Line( 11, 37, 1, 0x2e, 1);
							OSD_Line( 11, 38, 1, 0x2d, 1);
							OSD_Line( 11, 43, 1, 0x2e, 1);
							OSD_Line( 11, 44, 2, 0x25, 1);
							break;

					}
					OSD_Line( 11, 36, 12, 0x40, 2);

					OSD_Line( 11, 35, 1, 0x00, 1);
					OSD_Line( 11, 48, 1, 0x00, 1);
										
					OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
						, 1, 1, 14, 251, 0, 1, 25);

				}
				else if (ucOSD_Item_Index1)
				{
					if(ucOSD_Item_Index1 == 2)
					{
						OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x40, 2);
						ucOSD_Item_Index1 = 0;
					}
					else
					{
						ucOSD_Item_Index2    = 1;
						if(stGUD1.OSD_TIMEOUT < 5)
						{
							stGUD1.OSD_TIMEOUT = 20; //reset to 20 seconds
							usOSD_Timer         = 1020; //20*51     
							Save_GUD1();
						}
                        
						OSD_Line( 11, 36, 12, 0xe0, 2);
						OSD_Line( 11, 36, 12, 0x8c, 0);
						OSD_Line( 11, 35, 1, 0x40, 2);
						OSD_Line( 11, 35, 1, 0x0d, 1);
						OSD_Line( 11, 48, 1, 0x40, 2);
						OSD_Line( 11, 48, 1, 0x0c, 1);
						OSD_Slider(11, 31, 17, stGUD1.OSD_TIMEOUT, 60, 2, 14);
					}
				}
				else
				{
					ucOSD_Item_Index1   = stGUD1.OSD_TIMEOUT ? 1 : 2;
					OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x20, 2);
				}
				break;
				
			case PAGE4_ITEM_TRANSLU :
				if (ucOSD_Item_Index1)
				{
					ucOSD_Item_Index1   = 0;    // Leave the item
					OSD_Slider(13, 31, 17, (stGUD1.INPUT_SOURCE & 0xe0) >> 5, 7, 4, 14);
				}
				else
				{
					ucOSD_Item_Index1   = 1;
					OSD_Slider(13, 31, 17, (stGUD1.INPUT_SOURCE & 0xe0) >> 5, 7, 2, 14);
				}
				break;
				
			case PAGE4_ITEM_EXIT :
				// Disable highlight window 6
				OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
					, 0, 0, 14, 251, 0, 1, 0);
				// De-select the page item and disable the hightlight window
				ucOSD_Item_Index0   = 0;
				ucOSD_Item_Index1   = 0;
				
				break;
				
		}
	}
}

void Page4_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE4_ITEM_OSDH :
				Get_OSD_Margin();
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (Data[1] <= stGUD1.OSD_POSH)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stGUD1.OSD_POSH   = Data[1] > stGUD1.OSD_POSH ? stGUD1.OSD_POSH + 1 : Data[1];
					else
						stGUD1.OSD_POSH   = (Data[1] - 1) > stGUD1.OSD_POSH ? stGUD1.OSD_POSH + 2 : Data[1];
				}
				else
				{
					if (Data[0] >= stGUD1.OSD_POSH)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stGUD1.OSD_POSH   = Data[0] < stGUD1.OSD_POSH ? stGUD1.OSD_POSH - 1 : Data[0];
					else
						stGUD1.OSD_POSH   = (Data[0] + 1) < stGUD1.OSD_POSH ? stGUD1.OSD_POSH - 2 : Data[0];
				}

				OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 2, 14);
				OSD_Position(OSD_ENABLE);
				Save_GUD1();
				break;
				
			case PAGE4_ITEM_OSDV :
				Get_OSD_Margin();
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					
					if (Data[3] <= stGUD1.OSD_POSV)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stGUD1.OSD_POSV   = Data[3] > stGUD1.OSD_POSV ? stGUD1.OSD_POSV + 1 : Data[3];
					else
						stGUD1.OSD_POSV   = (Data[3] - 1) > stGUD1.OSD_POSV ? stGUD1.OSD_POSV + 2 : Data[3];
				
				}
				else
				{
				
					if (Data[2] >= stGUD1.OSD_POSV)
						break;

					if (KEY_TURBO_ENABLE > ucKey_Issued)
						stGUD1.OSD_POSV   = Data[2] < stGUD1.OSD_POSV ? stGUD1.OSD_POSV - 1 : Data[2];
					else
						stGUD1.OSD_POSV   = (Data[2] + 1) < stGUD1.OSD_POSV ? stGUD1.OSD_POSV - 2 : Data[2];
						
				}
				
				OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 2, 14);
				OSD_Position(OSD_ENABLE);
				Save_GUD1();
				break;
				
			case PAGE4_ITEM_TIMEOUT :
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if(ucOSD_Item_Index2)
					{
						stGUD1.OSD_TIMEOUT = (stGUD1.OSD_TIMEOUT == 60) ? 60 : stGUD1.OSD_TIMEOUT + 1;
						OSD_Slider(11, 31, 17, stGUD1.OSD_TIMEOUT, 60, 2, 14);
					}
					else if(ucOSD_Item_Index1)
					{
						//if (2 == ucOSD_Item_Index1)     break;
						ucOSD_Item_Index1  = 2;
						stGUD1.OSD_TIMEOUT  = 0;
						OSD_Line( 11, 36, 14, 0x40, 2);
						OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x20, 2);
					}
				}
				else
				{
					if(ucOSD_Item_Index2)
					{
						stGUD1.OSD_TIMEOUT = (stGUD1.OSD_TIMEOUT == 5) ? 5 : stGUD1.OSD_TIMEOUT - 1;
						OSD_Slider(11, 31, 17, stGUD1.OSD_TIMEOUT, 60, 2, 14);
					}
					else if(ucOSD_Item_Index1)
					{
						//if (1 == ucOSD_Item_Index1)     break;
						ucOSD_Item_Index1   = 1;
						OSD_Line( 11, 36, 14, 0x40, 2);
						OSD_Line( 11, 36 + (ucOSD_Item_Index1-1)*(6+1), 3, 0x20, 2);
					}
				}

				usOSD_Timer         = (unsigned int)stGUD1.OSD_TIMEOUT * 51;     // 20 sec
				//stGUD1.OSD_TIMEOUT  = (1 == ucOSD_Item_Index1) ? 2 : 0;
				Save_GUD1();
				break;
				
			case PAGE4_ITEM_TRANSLU :
				Data[0] = (stGUD1.INPUT_SOURCE & 0xe0) >> 5;
//				if(NOTIFY_RIGHT_KEY  == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if(ucOSD_Item_Index1)
					{
						Data[0] = (Data[0] == 0x07) ? 0x07 : Data[0] + 1;
						stGUD1.INPUT_SOURCE = stGUD1.INPUT_SOURCE & 0x1f | (Data[0] << 5);
					}
				}
				else
				{
					if(ucOSD_Item_Index1)
					{
						Data[0] = (Data[0] == 0x00) ? 0x00 : Data[0] - 1;
						stGUD1.INPUT_SOURCE = stGUD1.INPUT_SOURCE & 0x1f | (Data[0] << 5);
					}
				}

				RTDSetBit(OVL_CTRL_6D, 0xc7, Data[0] << 3);
				OSD_Slider(13, 31, 17, Data[0] , 7, 2, 14);
				Save_GUD1();
				break;
				
		}
	}
	else
	{
		Osd_Change_Item(Key,PAGE4_ITEM_NUM);
	}
}


void Page4_Show(void)
{
	Show_Osd_Page(2,Page4_Atb,3);


	//Set Window 5 to select "OSD Menu"
//	OSD_Window( 5, 10, 136, 153, 183, 1, 1, 14, 251, 0, 1, 25);
	OSD_Window( 5, 10, 136, 120, 150, 1, 1, 14, 251, 0, 1, 25);

	if (0 == ucOSD_Item_Index1)
	{
		Get_OSD_Margin();
		OSD_Slider(7, 31, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 4, 14);
		Get_OSD_Margin();
		OSD_Slider(9, 31, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 4, 14);

		OSD_Slider(13, 31, 17, (stGUD1.INPUT_SOURCE & 0xe0) >> 5, 7, 4, 14);
		if( ucOSD_Item_Index0 == PAGE4_ITEM_LANGUAGE)
			OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
	}
	else
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE4_ITEM_OSDH :
				//Get_OSD_Margin();
				//OSD_Slider(11, 2, 17, stGUD1.OSD_POSH - Data[0], Data[1] - Data[0], 0x02);
				break;
				
			case PAGE4_ITEM_OSDV :
				//Get_OSD_Margin();
				//OSD_Slider(11, 2, 17, stGUD1.OSD_POSV - Data[2], Data[3] - Data[2], 0x02);
				break;
				
			case PAGE4_ITEM_TIMEOUT :
				//ucOSD_Item_Index1   = stGUD1.OSD_TIMEOUT ? 1 : 2;
				//OSD_Line( 10, 15 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x00, 2);
				break;
				
			case PAGE4_ITEM_TRANSLU :
				//ucOSD_Item_Index1   = (stGUD1.INPUT_SOURCE & 0x80) ? 1 : 2;     // 1-On, 2-Off
				//OSD_Line( 10, 15 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x00, 2);
				break;
				
		}
	}
}

void Page4B_Enter_Key(void)
{
	if ((stGUD1.FUNCTION & 0x07) != (ucOSD_Item_Index1 - 1))
	{
		stGUD1.FUNCTION = (stGUD1.FUNCTION & 0xf8) | ((ucOSD_Item_Index1 - 1) & 0x07);
		Save_GUD1();

		switch (stGUD1.FUNCTION & 0x07)
		{
			case CHINESE_T :
			case CHINESE_S :
				//RTDCodeW(OSD_Reset);
				RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
				Load_VLC_Font(Font_East_C, 0x5a9, 0x45);
				Page4_Show();
				//RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
				//RTDCodeW(OSD_Enable);
				break;
				
			case JAPANESS :
				//RTDCodeW(OSD_Reset);
				RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
				Load_VLC_Font(Font_East_J, 0x573, 0x4B);
				Page4_Show();
				//RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
				//RTDCodeW(OSD_Enable);
				break;
				
			default :
				break;
				
		}
	}

	ucOSD_Item_Index1   = 0;    // Quit Sub-Page
}

void Page4B_Left_Right_Key(unsigned char Key)
{
	// Select and highlight the next/previous item
	OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
		54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 0, 0, 14, 251, 0, 1, 0);
	if (NOTIFY_RIGHT_KEY == Key)
		ucOSD_Item_Index1   = (PAGE4B_ITEM_NUM == ucOSD_Item_Index1) ? 1 : (ucOSD_Item_Index1 + 1);
	else
		ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? PAGE4B_ITEM_NUM : (ucOSD_Item_Index1 - 1);

	OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
		54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
}

void Page4B_Show(void)
{
	Show_Osd_Page(3,Page8_Atb,7);
	RTDOSDW(Page8_Content);
	// Set Window 6
	OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
		54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
}

void Page5_Enter_Key(void)
{
	if (0 == ucOSD_Item_Index0)
	{
		// Select and highlight the first item
		ucOSD_Item_Index0   = PAGE5_ITEM_SOURCE;
		ucOSD_Item_Index1   = 0;
		OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 0);
		OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
	}
	else
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE5_ITEM_SOURCE :
				Data[0]             = stGUD1.INPUT_SOURCE & 0x07;
				ucOSD_Item_Index1   = (SOURCE_DVI == Data[0])   ? PAGE5B_ITEM_DVI 
					: (SOURCE_AV == Data[0])    ? PAGE5B_ITEM_CVBS 
					: (SOURCE_SV == Data[0])    ? PAGE5B_ITEM_SV 
					: (SOURCE_YUV == Data[0])   ? PAGE5B_ITEM_YUV 
					: (SOURCE_TV == Data[0])    ? PAGE5B_ITEM_TV : PAGE5B_ITEM_DSUB;

				OSD_Proc_B(NOTIFY_SHOW);   // Show the sub-page
				break;
				
			case PAGE5_ITEM_OPTION :
				if (ucOSD_Item_Index1)
				{
					OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(7+1), 7, 0x40, 2);
										
					//ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? 0x00 : 0x80;
                    Data[0]   = (1 == ucOSD_Item_Index1) ? 0x00 : 0x10;
					//stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0x7f) | ucOSD_Item_Index1;
                    stGUD1.FUNCTION = stGUD1.FUNCTION & 0xef | Data[0];
					ucOSD_Item_Index1   = 0;
					Save_GUD1();

					if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07) && 400 == usIPV_ACT_LEN &&
						MODE_0640x0400x56HZ != ucMode_Curr && MODE_USER720x400 != ucMode_Curr)
					{
						//if (stGUD1.INPUT_SOURCE & 0x80)
/*						if (stGUD1.FUNCTION & 0x10)
						{
							if (720 == usIPH_ACT_WID)
								ucMode_Curr = MODE_OSDFORCE;    // Force to VGA search mode again
						}
						else
						{
							if (640 == usIPH_ACT_WID)
								ucMode_Curr = MODE_OSDFORCE;    // Force to VGA search mode again
						}
*/
						if (stGUD1.FUNCTION & 0x10)		//anson
						{
							stGUD1.FUNCTION = (stGUD1.FUNCTION & 0xef);
							ucMode_Curr = MODE_OSDFORCE;
						}
						else	
						{
							stGUD1.FUNCTION = (stGUD1.FUNCTION | 0x10);
							ucMode_Curr = MODE_OSDFORCE;
						}
					}
				}
				else
				{
					ucOSD_Item_Index1   = (stGUD1.FUNCTION & 0x10) ? 2 : 1;     // 1-720, 2-640//(stGUD1.INPUT_SOURCE & 0x80) ? 2 : 1;     // 1-720, 2-640
					OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(7+1), 7, 0x20, 2);
				}
				break;
				
			case PAGE5_ITEM_RECALL :
				if (ucOSD_Item_Index1)
				{
					if (1 == ucOSD_Item_Index1)
					{
                        		{
						unsigned char   ucTemp1, ucTemp2;

						// Save the global settings we don't want to reset
						ucTemp1 = stGUD1.FUNCTION & 0x07;       // Language select
						ucTemp2 = stGUD1.INPUT_SOURCE & 0x07;   // Source select

						if (JAPANESS < ucTemp1)
							ucTemp1 = ENGLISH;

						// Reset OSD time-out timer
						usOSD_Timer = (unsigned int)2 << 9;     // 20 sec

						// Reset global settings to default
						Init_GUD();
						// Reset OSD time-out timer
						usOSD_Timer = (unsigned int)stGUD1.OSD_TIMEOUT << 9;

						// Restore the global settings we don't want to reset
						stGUD1.FUNCTION     = (stGUD1.FUNCTION & 0xf8) | ucTemp1;
						stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | ucTemp2;
						Save_GUD1();

						// Reset brightness and contrast to default
						Set_Bright_Contrast();

#if (AUDIO_TYPE != AUDIO_NONE)
						SetVolume();
#endif
						// Reset OSD position
						OSD_Position(OSD_ENABLE);
					}

						// Reset all mode settings to default
						Init_MUD();

						// Read default settings for current mode
						Load_MUD(ucMode_Curr);

						// Leave current mode and search mode again
						ucMode_Curr = MODE_OSDFORCE;
					}

					OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x40, 2);
					ucOSD_Item_Index1   = 0;    // Leave the item
				}
				else
				{
					ucOSD_Item_Index1   = 2;    // Enter the item, Default NO
					OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
				}
				break;
				
			case PAGE5_ITEM_VOLUME :
				if (ucOSD_Item_Index1)
				{
					ucOSD_Item_Index1   = 0;    // Leave the item
					OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);
				}
				else
				{
					ucOSD_Item_Index1   = 1;    // Enter the item, show slider

					stGUD3.VOLUME   &= 0x1f;
					OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 2, 14);
				}
				break;
				
			case PAGE5_ITEM_EXIT :
				// Disable highlight window
				OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
					, 0, 0, 14, 251, 0, 1, 0);
				// De-select the page item and disable the hightlight window
				ucOSD_Item_Index0   = 0;
				ucOSD_Item_Index1   = 0;

				break;
				
		}
	}
}

void Page5_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE5_ITEM_OPTION :
				ucOSD_Item_Index1   = (NOTIFY_LEFT_KEY == Key) ? 2 : 1;      // 1-720, 2-640
				OSD_Line( 7, 36 , 16, 0x40, 2);
				OSD_Line( 7, 36 + (ucOSD_Item_Index1-1)*(7+1), 7, 0x20, 2);
				//RTDOSDW((1 == ucOSD_Item_Index1) ? OSD_MODE_V720 : OSD_MODE_V640);
				break;
				
			case PAGE5_ITEM_RECALL :
//				ucOSD_Item_Index1   = (NOTIFY_LEFT_KEY == Key) ? 1 : 2;
				ucOSD_Item_Index1   = (NOTIFY_RIGHT_KEY == Key) ? 1 : 2;
				OSD_Line( 9, 36 , 14, 0x40, 2);
				OSD_Line( 9, 36 + (ucOSD_Item_Index1-1)*(6+1), 4, 0x20, 2);
				//RTDOSDW(OSD_YESNO_TABLE[ucOSD_Item_Index1 - 1][stGUD1.FUNCTION & 0x07]);
				break;
				
			case PAGE5_ITEM_VOLUME :
//				if (NOTIFY_RIGHT_KEY == Key)
				if (NOTIFY_LEFT_KEY == Key)
				{
					if (0x00 == stGUD3.VOLUME)
						break;

					stGUD3.VOLUME   = stGUD3.VOLUME - 1;
				}
				else
				{
					if (0x1f <= stGUD3.VOLUME)
						break;

					stGUD3.VOLUME   = stGUD3.VOLUME + 1;
				}

				OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 2, 14);
				SetVolume();
				Save_GUD3();
				break;
				
			default :
				break;
				
		}
	}
	else
	{
		Osd_Change_Item(Key,PAGE5_ITEM_NUM);
	}
}

void Page5_Show(void)
{
	Show_Osd_Page(3,Page5_Atb,4);

	//Set Window 5 to select "Misc."
//	OSD_Window( 5, 10, 136, 186, 216, 1, 1, 14, 251, 0, 1, 25);
	OSD_Window( 5, 10, 136, 153, 183, 1, 1, 14, 251, 0, 1, 25);

#if (AUDIO_TYPE != AUDIO_NONE)

	OSD_Slider(11, 31, 17, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);

#endif
	if (0 == ucOSD_Item_Index1)
	{
		if( ucOSD_Item_Index0 == PAGE5_ITEM_SOURCE)
			OSD_Window( 6, 150, 282, 54, 84, 1, 1, 14, 251, 0, 1, 25);
	}
	else
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGE5_ITEM_OPTION :
				//OSD_Line( 10, 15 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x00, 2);
				//RTDOSDW((1 == ucOSD_Item_Index1) ? OSD_MODE_V720 : OSD_MODE_V640);
				break;
				
			case PAGE5_ITEM_RECALL :
				//OSD_Line( 10, 15 + (ucOSD_Item_Index1-1)*(4+1), 4, 0x00, 2);
				//RTDOSDW(OSD_YESNO_TABLE[ucOSD_Item_Index1 - 1][stGUD1.FUNCTION & 0x07]);
				break;
				
			case PAGE5_ITEM_VOLUME :
				//stGUD3.VOLUME   &= 0x1f;
				//OSD_Slider(11, 2, 20, 0x1f - stGUD3.VOLUME, 0x1f, 0x61);
				break;
				
			default :
				break;
				
		}
	}
}

void Page5B_Enter_Key()
{
	Data[0] = (PAGE5B_ITEM_DVI == ucOSD_Item_Index1) ?  SOURCE_DVI 
		: (PAGE5B_ITEM_CVBS == ucOSD_Item_Index1) ? SOURCE_AV
		: (PAGE5B_ITEM_SV == ucOSD_Item_Index1) ?   SOURCE_SV 
		: (PAGE5B_ITEM_YUV == ucOSD_Item_Index1) ?  SOURCE_YUV 
		: (PAGE5B_ITEM_TV == ucOSD_Item_Index1) ?   SOURCE_TV : SOURCE_VGA;

	if(Data[0] != ucInputSrc)
	{
		Change_Source(Data[0]);
		ucOSD_Page_Index = 0;
	}
	else
	{
		ucOSD_Item_Index1 = 0;            // Quit Sub-Page
	}

}

void Page5B_Left_Right_Key(unsigned char Key)
{
	// Select and highlight the next/previous item
	OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
		54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 0, 0, 14, 251, 0, 1, 0);
	if (NOTIFY_RIGHT_KEY == Key)
		ucOSD_Item_Index1   = (PAGE5B_ITEM_NUM == ucOSD_Item_Index1) ? 1 : (ucOSD_Item_Index1 + 1);
	else
		ucOSD_Item_Index1   = (1 == ucOSD_Item_Index1) ? PAGE5B_ITEM_NUM : (ucOSD_Item_Index1 - 1);

	OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
		54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
}

void Page5B_Show()
{
	Show_Osd_Page(4,Page9_Atb,8);
	RTDOSDW(Page9_Content);

	OSD_Window( 6, 150 + ((ucOSD_Item_Index1-1)/4)*170, 282 + ((ucOSD_Item_Index1-1)/4)*170, 
		54 + ((ucOSD_Item_Index1-1)%4)*33, 84 + ((ucOSD_Item_Index1-1)%4)*33, 1, 1, 14, 251, 0, 1, 25);
	// Highlight the select item
	// Set Window 6
	//OSD_Window( 6, 152, 282, 56, 86, 2, 2, 14, 251, 0, 1, 25);


}

void Page6_Left_Right_Key(unsigned char Key)
{
	if(Key == NOTIFY_RIGHT_KEY)
		ucOSD_Page_Index    = GetNextPageIdx(ucOSD_Page_Index);
	else
		ucOSD_Page_Index    = GetPrevPageIdx(ucOSD_Page_Index);
}

void Page6_Show(void)
{
	//Init_Page(5);
	//RTDOSDW(OSD_PAGE_TABLE[5][stGUD1.FUNCTION & 0x07]);

	Show_Osd_Page(4,Page6_Atb,5);

	//Set Window 5 to select "Exit"
//	OSD_Window( 5, 10, 136, 219, 249, 1, 1, 14, 251, 0, 1, 25);
	OSD_Window( 5, 10, 136, 186, 216, 1, 1, 14, 251, 0, 1, 25);
}

//////////////////////////////////////////////////////////////////////////////////
//anson
//////////////////////////////////////////////////////////////////////////////////
void PageFactory_Show(void)
{
	OSD_Fact_Clear( 0,20, 0,30);
	OSD_Position(OSD_ENABLE);
	OSD_Position(OSD_ENABLE);

	RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
	RTDOSDW(OSD_Reset);
	RTDOSDW(OSD_Clean_All);
	RTDOSDW(FactoryPageAtbFont);
	OSD_Fact_Line( 3, 0, 15, 0x20, 2);
	RTDOSDW(Version_Panel);
	ShowValue( 5,12, stGUD0.CONTRAST, 0x13 );		//Contrast
	ShowValue( 6,12, stGUD0.BRIGHT, 0x13 );		//Brightness
	ShowValue( 7,12, stGUD3.SPREAD, 0x13 );		//Spread
	ShowValue( 8,  9, stGUD4.C2_R, 0x13 );			//R-6500K
	ShowValue( 8,15, stGUD4.C2_G, 0x13 );			//G-6500K
	ShowValue( 8,21, stGUD4.C2_B, 0x13 );			//B-6500K
}

void PageFactory_Enter_Key(void)
{
	if (ucOSD_Item_Index1)
	{
		if (ucOSD_Item_Index2)
		{
			switch(ucOSD_Item_Index1)
			{
				case 1:
					OSD_Fact_Line( 8,  9, 3, 0x13, 2);
					ucOSD_Item_Index2   = 0;
					break;
				case 2:
					OSD_Fact_Line( 8,15, 3, 0x13, 2);
					ucOSD_Item_Index2   = 0;
					break;
				case 3:
					OSD_Fact_Line( 8,21, 3, 0x13, 2);
					ucOSD_Item_Index2   = 0;
					break;
			}
		}
		else		//ucOSD_Item_Index2 = 0 
		{
			switch (ucOSD_Item_Index0)
			{
				case PAGEFact_ITEM_Contrast:
					ShowValue(5,12, stGUD0.CONTRAST, 0x13 );
					ucOSD_Item_Index1   = 0;
					break;

				case PAGEFact_ITEM_Brightness:
					ShowValue(6,12, stGUD0.BRIGHT, 0x13 );
					ucOSD_Item_Index1   = 0;
					break;

				case PAGEFact_ITEM_Spread:
					ShowValue(7,12, stGUD3.SPREAD, 0x13 );
					ucOSD_Item_Index1   = 0;
					break;

				case PAGEFact_ITEM_6500K:

					switch(ucOSD_Item_Index1)
					{
						case 1:
							OSD_Fact_Line( 8,  9, 3, 0x23, 2);
							ucOSD_Item_Index2   = 1;
							break;
						case 2:
							OSD_Fact_Line( 8,15, 3, 0x23, 2);
							ucOSD_Item_Index2   = 1;
							break;
						case 3:
							OSD_Fact_Line( 8,21, 3, 0x23, 2);
							ucOSD_Item_Index2   = 1;
							break;
						case 4:
							OSD_Fact_Line( 8,25, 4, 0x13, 2);
							ucOSD_Item_Index1   = 0;
							break;
					}
					break;
			}
		}
	}
	else		//into ucOSD_Item_Index1 = 1 ;
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGEFact_ITEM_Recall:
				Init_FACTORY();
				ShowValue( 5,12, stGUD0.CONTRAST, 0x13 );		//Contrast
				ShowValue( 6,12, stGUD0.BRIGHT, 0x13 );		//Brightness
				ShowValue( 8,  9, stGUD4.C2_R, 0x13 );			//R-6500K
				ShowValue( 8,15, stGUD4.C2_G, 0x13 );			//G-6500K
				ShowValue( 8,21, stGUD4.C2_B, 0x13 );			//B-6500K

				stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xE7 ) | 0x08;  //6500 mode
				Set_Bright_Contrast();
				RTDOSDW(RecallOK);
				break;

			case PAGEFact_ITEM_Auto_Color:
				Auto_Balance();
				RTDOSDW(AutoOK);
				break;

			case PAGEFact_ITEM_Contrast:
				ShowValue(5,12, stGUD0.CONTRAST, 0x23 );
				ucOSD_Item_Index1   = 1;
				break;

			case PAGEFact_ITEM_Brightness:
				ShowValue(6,12, stGUD0.BRIGHT, 0x23 );
				ucOSD_Item_Index1   = 1;
				break;

			case PAGEFact_ITEM_Spread:
				ShowValue(7,12, stGUD3.SPREAD, 0x23 );
				ucOSD_Item_Index1   = 1;
				break;

			case PAGEFact_ITEM_6500K:
				OSD_Fact_Line( 8, 7, 1, 0x23, 2);
				ucOSD_Item_Index1   = 1;
				break;

			case PAGEFact_ITEM_EXIT:
				ucOSD_Page_Index	 = 0;
				ucOSD_Item_Index0   = 0;
				ucOSD_Item_Index1   = 0;
				ucOSD_Item_Index2   = 0;

				RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
				RTDOSDW(OSD_Reset);
				break;
		}
	}
}

void PageFactory_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		if (ucOSD_Item_Index2)
		{
			switch (ucOSD_Item_Index0)
			{
			//select 6500K value;
				case PAGEFact_ITEM_6500K:

					switch(ucOSD_Item_Index1)
					{
						case 1:
							Value_Adjust(&stGUD4.C2_R,Key,255,0);
							ShowValue( 8,  9, stGUD4.C2_R, 0x23 );
							break;
						case 2:
							Value_Adjust(&stGUD4.C2_G,Key,255,0);
							ShowValue( 8,15, stGUD4.C2_G, 0x23 );
							break;
						case 3:
							Value_Adjust(&stGUD4.C2_B,Key,255,0);
							ShowValue( 8,21, stGUD4.C2_B, 0x23 );
							break;
					}
					Set_Bright_Contrast();
					Save_GUD4();
					break;

			}
		}
		else		//ucOSD_Item_Index1 = 1 , ucOSD_Item_Index2 = 0
		{
			switch (ucOSD_Item_Index0)
			{
				if(NOTIFY_RIGHT_KEY == Key)
					ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 1) ? 7 : ucOSD_Item_Index0 - 1;
				else
					ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 7) ? 1 : ucOSD_Item_Index0 + 1;

			//select Contrast value;
				case PAGEFact_ITEM_Contrast:
					Bright_Contrast_Adjust(&stGUD0.CONTRAST,Key);
					ShowValue(5,12, stGUD0.CONTRAST, 0x23 );

				#if(ANALOG_CONTRAST)
					if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
						SetADC_Gain();
					else
						Set_Bright_Contrast();
				#else
						Set_Bright_Contrast();
				#endif

					Save_GUD0();
					break;

			//select Brightness value;
				case PAGEFact_ITEM_Brightness:
					Bright_Contrast_Adjust(&stGUD0.BRIGHT,Key);
					ShowValue(6,12, stGUD0.BRIGHT, 0x23 );
					Set_Bright_Contrast();
					Save_GUD0();
					break;

				case PAGEFact_ITEM_Spread:
					SPREAD_Adjust(&stGUD3.SPREAD,Key);
					ShowValue(7,12, stGUD3.SPREAD, 0x23 );
					Set_Spread();
					Save_GUD3();
					break;

			//select 6500K R,G,B,Exit ;
				case PAGEFact_ITEM_6500K:

					if(NOTIFY_RIGHT_KEY == Key)
						ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 4) ? 1 : ucOSD_Item_Index1 + 1;
					else
						ucOSD_Item_Index1 = (ucOSD_Item_Index1 == 1) ? 4 : ucOSD_Item_Index1 - 1;

						switch(ucOSD_Item_Index1)
						{
							case 1:
								OSD_Fact_Line( 8,  7, 1, 0x23, 2);
								OSD_Fact_Line( 8,13, 1, 0x13, 2);
								OSD_Fact_Line( 8,25, 4, 0x13, 2);
								break;
							case 2:
								OSD_Fact_Line( 8,  7, 1, 0x13, 2);
								OSD_Fact_Line( 8,13, 1, 0x23, 2);
								OSD_Fact_Line( 8,19, 1, 0x13, 2);
								break;
							case 3:
								OSD_Fact_Line( 8,13, 1, 0x13, 2);
								OSD_Fact_Line( 8,19, 1, 0x23, 2);
								OSD_Fact_Line( 8,25, 4, 0x13, 2);
								break;
							case 4:
								OSD_Fact_Line( 8,  7, 1, 0x13, 2);
								OSD_Fact_Line( 8,19, 1, 0x13, 2);
								OSD_Fact_Line( 8,25, 4, 0x23, 2);
								break;
						}
					break;
			}
		}
	}
	else	//ucOSD_Item_Index1 = 0
	{
	//select Factory Main menu ;
		if(NOTIFY_RIGHT_KEY == Key)
			ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 7) ? 1 : ucOSD_Item_Index0 + 1;
		else
			ucOSD_Item_Index0 = (ucOSD_Item_Index0 == 1) ? 7 : ucOSD_Item_Index0 - 1;

		switch (ucOSD_Item_Index0)
		{
			case PAGEFact_ITEM_Recall:
				OSD_Fact_Line( 9, 1,  7, 0x10, 2);
				OSD_Fact_Line( 3, 1, 14, 0x20, 2);
				OSD_Fact_Line( 4, 1, 10, 0x10, 2);
				break;

			case PAGEFact_ITEM_Auto_Color:
				OSD_Fact_Line( 3, 1, 14, 0x10, 2);
				OSD_Fact_Line( 4, 1, 10, 0x20, 2);
				OSD_Fact_Line( 5, 1, 10, 0x10, 2);
				break;

			case PAGEFact_ITEM_Contrast:
				OSD_Fact_Line( 4, 1, 10, 0x10, 2);
				OSD_Fact_Line( 5, 1, 10, 0x20, 2);
				OSD_Fact_Line( 6, 1, 10, 0x10, 2);
				break;

			case PAGEFact_ITEM_Brightness:
				OSD_Fact_Line( 5, 1, 10, 0x10, 2);
				OSD_Fact_Line( 6, 1, 10, 0x20, 2);
				OSD_Fact_Line( 7, 1, 10, 0x10, 2);
				break;

			case PAGEFact_ITEM_Spread:
				OSD_Fact_Line( 6, 1, 10, 0x10, 2);
				OSD_Fact_Line( 7, 1, 10, 0x20, 2);
				OSD_Fact_Line( 8, 1,   5, 0x10, 2);
				break;

			case PAGEFact_ITEM_6500K:
				OSD_Fact_Line( 7, 1,10, 0x10, 2);
				OSD_Fact_Line( 8, 1,  5, 0x20, 2);
				OSD_Fact_Line( 9, 1,  7, 0x10, 2);
				Set_Bright_Contrast();
				break;

			case PAGEFact_ITEM_EXIT:
				OSD_Fact_Line( 8, 1,  5, 0x10, 2);
				OSD_Fact_Line( 9, 1,  7, 0x20, 2);
				OSD_Fact_Line( 3, 1,14, 0x10, 2);
				break;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

void PageADC_Left_Right_Key(unsigned char Key)
{
	if (ucOSD_Item_Index1)
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGEH_ITEM_REDGAIN :
				if (NOTIFY_RIGHT_KEY == Key)
				{
					if (0xff == stGUD2.AD_R_GAIN)
						return;

					stGUD2.AD_R_GAIN    += 1;
				}
				else
				{
					if (0x00 == stGUD2.AD_R_GAIN)
						return;

					stGUD2.AD_R_GAIN    -= 1;
				}

				OSD_Slider(5, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
				SetADC_Gain();
				break;
				
			case PAGEH_ITEM_GREENGAIN :
				if (NOTIFY_RIGHT_KEY == Key)
				{
					if (0xff == stGUD2.AD_G_GAIN)
						return;

					stGUD2.AD_G_GAIN    += 1;
				}
				else
				{
					if (0x00 == stGUD2.AD_G_GAIN)
						return;

					stGUD2.AD_G_GAIN    -= 1;
				}

				OSD_Slider(7, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
				SetADC_Gain();
				break;
					
			case PAGEH_ITEM_BLUEGAIN :
				if (NOTIFY_RIGHT_KEY == Key)
				{
					if (0xff == stGUD2.AD_B_GAIN)
						return;

					stGUD2.AD_B_GAIN    += 1;
				}
				else
				{
					if (0x00 == stGUD2.AD_B_GAIN)
						return;

					stGUD2.AD_B_GAIN    -= 1;
				}

				OSD_Slider(9, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
				SetADC_Gain();
				break;
				
			case PAGEH_ITEM_REDOFFSET :
				if (NOTIFY_RIGHT_KEY == Key)
				{
					if (0xff == stGUD2.AD_R_OFFSET)
						return;

					stGUD2.AD_R_OFFSET  += 1;
				}
				else
				{
					if (0x00 == stGUD2.AD_R_OFFSET)
						return;

					stGUD2.AD_R_OFFSET  -= 1;
				}
				
				OSD_Slider(11, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
				SetADC_Offset();
				break;
				
			case PAGEH_ITEM_GREENOFFSET :
				if (NOTIFY_RIGHT_KEY == Key)
				{
					if (0xff == stGUD2.AD_G_OFFSET)
						return;

					stGUD2.AD_G_OFFSET  += 1;
				}
				else
				{
					if (0x00 == stGUD2.AD_G_OFFSET)
						return;

					stGUD2.AD_G_OFFSET  -= 1;
				}

				OSD_Slider(13, 36, 17, stGUD2.AD_R_GAIN, 0xff, 2, 14);
				SetADC_Offset();
				break;
				
			case PAGEH_ITEM_BLUEOFFSET :
				if (NOTIFY_RIGHT_KEY == Key)
				{
					if (0xff == stGUD2.AD_B_OFFSET)
						return;

					stGUD2.AD_B_OFFSET  += 1;
				}
				else
				{
					if (0x00 == stGUD2.AD_B_OFFSET)
						return;

					stGUD2.AD_B_OFFSET  -= 1;
				}
				
				OSD_Slider(15, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
				SetADC_Offset();
				break;
				
		}

		Save_GUD2();
	}
	else
	{
		if (ucOSD_Item_Index0)
		{
			// Select and highlight the next/previous item
			if (NOTIFY_RIGHT_KEY == Key)
				ucOSD_Item_Index0   = (PAGEH_ITEM_NUM == ucOSD_Item_Index0) ? 1 : (ucOSD_Item_Index0 + 1);
			else
				ucOSD_Item_Index0   = (1 == ucOSD_Item_Index0) ? PAGEH_ITEM_NUM : (ucOSD_Item_Index0 - 1);

			OSD_Window( 6, 0, 476, 0, 252, 4, 4, 0, 1, 231, 1, 113);
		}
	}
}

void PageADC_Enter_Key(void)
{
	if (0 == ucOSD_Item_Index0)
	{
		// Select and highlight the first item
		ucOSD_Item_Index0   = PAGEH_ITEM_REDGAIN;
		ucOSD_Item_Index1   = 0;
		OSD_Window( 6, 152, 282, 56, 86, 2, 2, 14, 251, 0, 1, 25);
	}
	else
	{
		if (PAGEH_ITEM_EXIT == ucOSD_Item_Index0)
		{                
			ucOSD_Page_Index    = 0;        // Close OSD
		}
		else
		{
			if (ucOSD_Item_Index1)
			{
				ucOSD_Item_Index1   = 0;    // Leave the item, Show Mode
				RTDOSDW(OSD_Version);
			}
			else
			{
				ucOSD_Item_Index1   = 1;    // Enter the item, Show slider

				switch (ucOSD_Item_Index0)
				{
					case PAGEH_ITEM_REDGAIN :
						OSD_Slider(5, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
						break;
						
					case PAGEH_ITEM_GREENGAIN :
						OSD_Slider(7, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
						break;
						
					case PAGEH_ITEM_BLUEGAIN :
						OSD_Slider(9, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
						break;
						
					case PAGEH_ITEM_REDOFFSET :
						OSD_Slider(11, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
						break;
						
					case PAGEH_ITEM_GREENOFFSET :
						OSD_Slider(13, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
						break;
						
					case PAGEH_ITEM_BLUEOFFSET :
						OSD_Slider(15, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 2, 14);
						break;
						
				}
			}
		}
	}
}

void PageADC_Show(void)
{
	Init_Page(0);

	RTDOSDW(PageADC_Atb);
	RTDOSDW(PageADC_ENG);

	// Highlight the select item
	//OSD_Window( 5, 0, 476, 0, 252, 4, 4, 0, 1, 231, 1, 113);		//Set Window 5

	if (0 == ucOSD_Item_Index1)
	{
		RTDOSDW(OSD_Version);
	}
	else
	{
		switch (ucOSD_Item_Index0)
		{
			case PAGEH_ITEM_REDGAIN :
				OSD_Slider(5, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
				break;
				
			case PAGEH_ITEM_GREENGAIN :
				OSD_Slider(7, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
				break;
				
			case PAGEH_ITEM_BLUEGAIN :
				OSD_Slider(9, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
				break;
				
			case PAGEH_ITEM_REDOFFSET :
				OSD_Slider(11, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
				break;
				
			case PAGEH_ITEM_GREENOFFSET :
				OSD_Slider(13, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
				break;
				
			case PAGEH_ITEM_BLUEOFFSET :
				OSD_Slider(15, 36, 17, stGUD2.AD_B_OFFSET, 0xff, 4, 14);
				break;
				
		}
	}
}





unsigned char Page1_Goto_Subpage(unsigned char Key)
{
	if (PAGE1_ITEM_RGBADJ == ucOSD_Item_Index0 && ucOSD_Item_Index1)
	{
		if (MODE_NOSIGNAL == ucMode_Curr || MODE_NOSUPPORT == ucMode_Curr)
		{
			ucOSD_Item_Index1   = 0;
			ucOSD_Item_Index2   = 0;
		}
		else
		{
			// When RGB adjust sub-page is open, just re-direct the message to the sub-page process
			OSD_Proc_B(Key);
		}

		if (ucOSD_Item_Index1)  
			return  0;	// RGB adjust sub-Page still in work

		ucOSD_Item_Index2   = 0;

		//Key  = NOTIFY_SHOW;  // Redraw itself when returned from sub-page
		return 1;
		
	}

	return 2;
	
}


unsigned char Page4_Goto_Subpage(unsigned char Key)
{
	if (PAGE4_ITEM_LANGUAGE == ucOSD_Item_Index0 && 0 != ucOSD_Item_Index1)
	{
		if (NOTIFY_SHOW != Key)
		{
			// When language setting sub-page is open, just re-direct the message to the sub-page process
			OSD_Proc_B(Key);

			if (ucOSD_Item_Index1)  
				return 0;     // Language Setting Sub-Page still in work

			//action  = NOTIFY_SHOW;              // Redraw itself when returned from sub-page
			return 1;
		}
		else
		{
			// Quit language sub-page if signal changed.
			ucOSD_Item_Index1   = 0;
		}
	}

	return 2;
	
}

unsigned char Page5_Goto_Subpage(unsigned char Key)
{
	if (PAGE5_ITEM_SOURCE == ucOSD_Item_Index0 && 0 != ucOSD_Item_Index1)
	{
		if (NOTIFY_SHOW != Key)
		{
			// When source select sub-page is open, just re-direct the message to the sub-page process
			OSD_Proc_B(Key);

			if (ucOSD_Item_Index1)  return 0;     // Source select sub-Page still in work

			//action  = NOTIFY_SHOW;              // Redraw itself when returned from sub-page
			return 1;
		}
		else
		{
			// Quit source select sub-page if signal changed.
			ucOSD_Item_Index1   = 0;
		}
	}

	return 2;

}

#if(VIDEO_CHIP != VDC_NONE)

void PageVDC_Enter_Key(void)
{
           if (0 == ucOSD_Item_Index0)
        {
            // Select and highlight the first item
            ucOSD_Item_Index0   = PAGEV_ITEM_CONTRAST;
            ucOSD_Item_Index1   = 0;
            //OSD_Window(1, (2 + ucOSD_Item_Index0), (2 + ucOSD_Item_Index0), 7, 23, 7, COLOR_CYAN);
            OSD_Window( 5, 10, 136, 54, 84, 1, 1, 14, 251, 0, 1, 25);
        }
        else
        {
            if (PAGEV_ITEM_EXIT == ucOSD_Item_Index0)
            {                
                ucOSD_Page_Index    = 0;        // Close OSD
            }
            else
            {
                if (ucOSD_Item_Index1)
                {
                    ucOSD_Item_Index1   = 0;    // Leave the item, Show Mode
                    
                    RTDOSDW(OSD_Version);

                }
                else    // if (MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
                {
                    ucOSD_Item_Index1   = 1;    // Enter the item, Show slider

                    switch (ucOSD_Item_Index0)
                    {
                    case PAGEV_ITEM_CONTRAST :
                        //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST, 0xff, 0x61);
                        OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST, 0xff, 2, 14);
                        break;
                    case PAGEV_ITEM_BRIGHT :
                        //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT, 0xff, 0x61);
                        OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT, 0xff, 2, 14);
                        break;
                    case PAGEV_ITEM_HUE :
                        //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE, 0xff, 0x61);
                        OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE, 0xff, 2, 14);
                        break;
                    case PAGEV_ITEM_SATURATION :
                        //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION, 0xff, 0x61);
                        OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION, 0xff, 2, 14);
                        break;
                    }
                }
            }
        }
}

void PageVDC_Left_Right_Key(unsigned char Key)
{
   if (ucOSD_Item_Index1)
        {
            switch (ucOSD_Item_Index0)
            {            
            case PAGEV_ITEM_CONTRAST :
                if (NOTIFY_RIGHT_KEY == Key)
                {
                    if (0xff == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST)   return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST    += 1;
                }
                else
                {
                    if (0x00 == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST)   return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST    -= 1;
                }
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST, 0xff, 2, 14);
                break;
            case PAGEV_ITEM_BRIGHT :
                if (NOTIFY_RIGHT_KEY == Key)
                {
                    if (0xff == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT)     return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT  += 1;
                }
                else
                {
                    if (0x00 == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT)     return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT  -= 1;
                }
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT, 0xff, 2, 14);
                break;
            case PAGEV_ITEM_HUE :
                if (NOTIFY_RIGHT_KEY == Key)
                {
                    if (0xff == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE)        return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE += 1;
                }
                else
                {
                    if (0x00 == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE)        return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE -= 1;
                }
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE, 0xff, 2, 14);
                break;
            case PAGEV_ITEM_SATURATION :
                if (NOTIFY_RIGHT_KEY == Key)
                {
                    if (0xff == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION)     return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION  += 1;
                }
                else
                {
                    if (0x00 == ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION)     return;

                    ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION  -= 1;
                }
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION, 0xff, 2, 14);
                break;
            }
            SetVDC_Color();
            Save_MUD(ucMode_Curr);
        }
        else
        {
            if (ucOSD_Item_Index0)
            {
                // Select and highlight the next/previous item
                if (NOTIFY_RIGHT_KEY == Key)
                    ucOSD_Item_Index0   = (PAGEV_ITEM_NUM == ucOSD_Item_Index0) ? 1 : (ucOSD_Item_Index0 + 1);
                else
                    ucOSD_Item_Index0   = (1 == ucOSD_Item_Index0) ? PAGEV_ITEM_NUM : (ucOSD_Item_Index0 - 1);

                //OSD_Window(1, (2 + ucOSD_Item_Index0), (2 + ucOSD_Item_Index0), 7, 23, 7, COLOR_CYAN);
                  Osd_Change_Item(Key,PAGEV_ITEM_NUM);
            }
        }
}

void PageVDC_Show(void)
{
          Init_Page(0);

        RTDOSDW(PageVDC_Atb);
        RTDOSDW(PageVDC_ENG);

        // Highlight the select item
        //OSD_Window(1, (2 + ucOSD_Item_Index0), (2 + ucOSD_Item_Index0), 7, 23, (ucOSD_Item_Index0 ? 7 : 3), COLOR_CYAN);
        OSD_Window( 5, 10, 136, 54, 84, 1, 1, 14, 251, 0, 1, 25);

        if (0 == ucOSD_Item_Index1)
        {
            RTDOSDW(OSD_Version);

        }
        else
        {
            switch (ucOSD_Item_Index0)
            {
            case PAGEV_ITEM_CONTRAST :
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VCONTRAST, 0xff, 2, 14);
                break;
            case PAGEV_ITEM_BRIGHT :
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VBRIGHT, 0xff, 2, 14);
                break;
            case PAGEV_ITEM_HUE :
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VHUE, 0xff, 2, 14);
                break;
            case PAGEV_ITEM_SATURATION :
                //OSD_Slider(11, 2, 20, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION, 0xff, 0x61);
                OSD_Slider(11, 36, 17, ((LP_VIDEO_MODE_USER_DATA)&stMUD)->VSATURATION, 0xff, 2, 14);
                break;
            }
        }
}
#endif

unsigned char Sub_Page_Process(unsigned char Key)
{
	unsigned char ucTemp = 2;
	
	switch(ucOSD_Page_Index)
	{
		case 1:
			ucTemp = Page1_Goto_Subpage(Key); 
			break;
			
//		case 4:
		case 3:	    
			ucTemp = Page4_Goto_Subpage(Key);
			break;

//		case 5:	    			
		case 4:
			ucTemp = Page5_Goto_Subpage(Key);
			break;
			
		default:
			break;
	}

	return ucTemp;
	
}

///////////////////////////////////////////////////////////////////////////////////////////
//anson
///////////////////////////////////////////////////////////////////////////////////////////
void FACTORY_Key_Process(void)    //anson
{
	switch(ucOSD_Page_Index)
	{
		case 0:
			FACTORY_Key_Key();
			break;
        }
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
void Enter_Key_Process(void)
{
	switch(ucOSD_Page_Index)
	{
		case 0:
			Page0_Enter_Key();
			break;
			
		case 1:
			Page1_Enter_Key();
			break;
			
		case 2:
			Page2_Enter_Key();
			break;
/*			
		case 3:
			if(Page3_Enter_Key())  
				break;
			else
				return;
			break;
*/			
		case 3:
			Page4_Enter_Key();
			break;
			
		case 4:
			Page5_Enter_Key();
			break;
			
		case 5:
			// Just set ucOSD_Page_Index to 0 and wait for main program to clear screen
			ucOSD_Page_Index    = 0;
			break;
			
		case 8:
			if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
				PageADC_Enter_Key();

#if(VIDEO_CHIP != VDC_NONE)
			else
				PageVDC_Enter_Key();
#endif
			break;
			
		case PAGE_Factory:
			PageFactory_Enter_Key();
			break;
			
	}
}

void Enter_Key_B_Process(void)
{
	switch(ucOSD_Page_Index)
	{
		case 1:
			Page1B_Enter_Key();
			break;
			
//		case 4:
		case 3:	    
			Page4B_Enter_Key();
			break;

			
//		case 5:    
        case 4:
			Page5B_Enter_Key();
			break;
			
	}
}
void Left_Right_Key_Process(unsigned char Key)
{
	switch(ucOSD_Page_Index)
	{
		case 0:
			Page0_Left_Right_Key(Key);
			break;
			
		case 1:        
			Page1_Left_Right_Key(Key);
			break;
			
		case 2:        
			Page2_Left_Right_Key(Key);
			break;
/*			
		case 3:        
			Page3_Left_Right_Key(Key);
			break;
*/			
		case 3:        
			Page4_Left_Right_Key(Key);
			break;
			
		case 4:        
			Page5_Left_Right_Key(Key);
			break;
			
		case 5:        
			Page6_Left_Right_Key(Key);
			break;
			
		case 8:
			if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
				PageADC_Left_Right_Key(Key);

#if(VIDEO_CHIP != VDC_NONE)
			else
				PageVDC_Left_Right_Key(Key);
#endif
			break;

		case PAGE_Factory:
			PageFactory_Left_Right_Key(Key);
			break;

	}
}

void Left_Right_Key_B_Process(unsigned char Key)
{
	switch(ucOSD_Page_Index)
	{
		case 1:	     
			Page1B_Left_Right_Key(Key);
			break;
			
//		case 4:	     
		case 3:	    
			Page4B_Left_Right_Key(Key);
			break;


//		case 5:	     
		case 4:	    
			Page5B_Left_Right_Key(Key);
			break;
			
	}
}

void Show_Process(void)
{
	switch(ucOSD_Page_Index)
	{
		case 1:	     
			Page1_Show();
			break;
			
		case 2:	     
			Page2_Show();
			break;
/*			
		case 3:	     
			Page3_Show();
			break;
*/			
		case 3:	     
			Page4_Show();
			break;
			
		case 4:	     
			Page5_Show();
			break;
			
		case 5:	     
			Page6_Show();
			break;
			
		case 8:
			if((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA)
				PageADC_Show();

#if(VIDEO_CHIP != VDC_NONE)
			else
				PageVDC_Show();
#endif
			break;

		case PAGE_Factory:
			PageFactory_Show();
			break;

	}
}

void Show_B_Process(void)
{
	switch(ucOSD_Page_Index)
	{
		case 1:
			Page1B_Show();
			break;
			
//		case 4:	    
		case 3:	    
			Page4B_Show();
			break;
			

//		case 5:	    
		case 4:	    
			Page5B_Show();
			break;
			
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OSD Process Routine
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// In all OSD main page process, you CANNOT call other main page process directly.
// You CAN only change ucOSD_Page_Index to indicate other main page.
// Main program will detect the change of ucOSD_Page_Index and send NOTIFY_SHOW to the new page.
// The only constraint is YOU CANNOT change ucOSD_Page_Index when receive NOTIFY_SHOW.
// p.s. You can call sub-page process directly.

// OSD_Proc0 handles messages when there is no OSD window on screen (ucOSD_Page_Index = 0)
void OSD_Proc(unsigned char action)
{

#if (TV_CHIP != TV_NONE)
       if(ucOSD_Page_Index == 0)
	   {
		  //if (SOURCE_TV == (stGUD1.INPUT_SOURCE & 0x07) && OSD_Proc[1][stGUD1.INPUT_SOURCE & 0x07])
		  if (SOURCE_TV == (stGUD1.INPUT_SOURCE & 0x07))
		  {
			  // Change to OSD Main Page 1 and Main Program will show it
			  ucOSD_Page_Index    = 1;
			  ucOSD_Item_Index0   = 0;
			  ucOSD_Item_Index1   = 0;
			  ucOSD_Item_Index2   = 0;

              	b_rgb_VOLUME_STATUS = 0;

			  return;
		  }
	  }
#endif

	Data[0] = Sub_Page_Process(action);

	if(Data[0] == 1)
		action = NOTIFY_SHOW;	// Redraw itself when returned from sub-page
	else if(Data[0] == 0)
		return;	// Source select sub-Page still in work
       
	if((MODE_NOSIGNAL != ucMode_Curr)&&(MODE_NOSUPPORT != ucMode_Curr))	//anson
	{
		switch(action)
		{
			case NOTIFY_AUTO_KEY :
				
//				if ((b_rgb_VOLUME_STATUS)|(ucOSD_Page_Index)) //eric test
//				{
//					ucOSD_Page_Index    = 0;
//					ucOSD_Item_Index0   = 0;
//					ucOSD_Item_Index1   = 0;
//					ucOSD_Item_Index2   = 0;
					
//					b_rgb_VOLUME_STATUS = 0;
//					RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
//		              	
//				}
//				else
//				{
				if (SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07) && MODE_NOSIGNAL != ucMode_Curr && MODE_NOSUPPORT != ucMode_Curr)
				{
					RTDOSDW(OSD_Reset);
					OSD_Position(OSD_ENABLE);
					RTDOSDW(OSD_AUTO);
					RTDOSDW(strTabAuto_Atb[stGUD1.FUNCTION & 0x07]);		//anson
					RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
					if (MODE_0640x0350x70HZ <= ucMode_Curr && MODE_0720x0400x70HZ >= ucMode_Curr)
					{
						stMUD.CLOCK = 128;
						Set_H_Position();
						Set_Clock();
						Save_MUD(ucMode_Curr);
						if (ERROR_INPUT == Auto_Phase())
							ucMode_Curr = MODE_OSDFORCE;
						if (ERROR_INPUT == Auto_Position())
							ucMode_Curr = MODE_OSDFORCE;
					}
					else
					{
						if (ERROR_INPUT == Auto_Config())   ucMode_Curr = MODE_OSDFORCE;
						//if (ERROR_INPUT == Auto_Phase())   ucMode_Curr = MODE_OSDFORCE;
					}
					b_rgb_VOLUME_STATUS = 0;
					ucOSD_Page_Index    = 0;
					RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
					// Although you can add ending animation here, I don't think it is necessary.
					RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
					RTDOSDW(OSD_Reset);            // Clear OSD
//				}
				
				}
				break;

			case NOTIFY_ENTER_KEY:
					b_rgb_VOLUME_STATUS = 0;
					Enter_Key_Process();
				break;
			
			case NOTIFY_RIGHT_KEY:
			case NOTIFY_LEFT_KEY:
					Left_Right_Key_Process(action);
				break;
			
			case NOTIFY_EXIT_KEY :
					rgb_EXIT_KEY();
				break;

			case NOTIFY_SHOW:
					Show_Process();
				break;
			
			case NOTIFY_LR_KEY:
					if(ucOSD_Page_Index == 0)
						Page0_LR_Key();
				break;
			
			case NOTIFY_FACTORY_KEY:             //anson 
				if((stGUD3.TV_SETTING & 0x08) == 0x08 )//Factory Mode		
				{
					FACTORY_Key_Process();
				}
				break;

			default:
				break;
			
		}
	}
}

void OSD_Proc_B(unsigned char action)
{
	switch(action)
	{
		case NOTIFY_ENTER_KEY:
			Enter_Key_B_Process();
			break;
			
		case NOTIFY_RIGHT_KEY:
		case NOTIFY_LEFT_KEY:
			Left_Right_Key_B_Process(action);
			break;
			
        case NOTIFY_EXIT_KEY :
           rgb_EXIT_KEY();
		case NOTIFY_SHOW:
			Show_B_Process();
			break;
			
		default:
			break;
			
	}
}


#if (TV_NONE != TV_CHIP)


void TV_AutoScan(void)
{
    unsigned char   ucTemp0, ucTemp1, ucTemp2;

    RTDOSDW(OSD_Reset); 
    RTDCodeW(FreeV);                        // FreeRun V registers & Background & disable
    RTDSetBit(VGIP_CTRL_04, 0xfe, 0x00);    // Input Run Disable

    RTDSetBit(VDIS_SIGINV_21, 0x0f, 0x10| DISP_EO_SWAP | DISP_RB_SWAP | DISP_ML_SWAP);

    I2CWrite(AV_DETECT);
    I2CWrite(TV_SOURCE_SEL);
    I2CWrite(TV_SCAN_GAIN);

    RTDCodeW(OSD_Enable);

    ucTemp0 = 0;
    ucTemp1 = 0;
    ucTemp2 = stGUD3.CURR_CHANNEL;

    stGUD3.CURR_CHANNEL = 1;

    while (1)
    {
        Set_TV_Channel();
        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);

        if (0 == (ucTemp0 & 0x07))
        {
            I2CRead(ADDR_EROM1, 0xd0 + (ucTemp0 >> 3), 0x01);
            ucTemp1 = Data[0];
        }
        
        Data[1] = 12;
        do
        {
            Delay_Xms(50);
            I2CRead(ADDR_VIDEO, 0x1f, 0x01);
            if (Data[0] & 0x40)     break;
        }
        while (--Data[1]);
        
        if (Data[1])
        {
            ucTemp1 &= 0xff - (1 << (7 - (ucTemp0 & 0x07)));
        }
        else
        {
            ucTemp1 |= 1 << (7 - (ucTemp0 & 0x07));
        }      
        
        Data[0] = 4;
        Data[1] = ADDR_EROM1;
        Data[2] = 0xd0 + (ucTemp0 >> 3);
        Data[3] = ucTemp1;
        I2CWrite(Data);

        if (stGUD3.TV_SETTING & 0x01)
        {
            if (MAX_CATV_NUM == stGUD3.CURR_CHANNEL)    break;
        }
        else
        {
            if (MAX_AIR_NUM == stGUD3.CURR_CHANNEL)     break;
        }

        stGUD3.CURR_CHANNEL += 1;
        ucTemp0             += 1;
    }        
    stGUD3.CURR_CHANNEL = ucTemp2;
    Set_TV_Channel();
    Show_TV_Info(stGUD3.CURR_CHANNEL, 2);

    Delay_Xms(SET_2404_DELAY);
}

void Show_TV_Info(unsigned channel, unsigned char option)
{
    RTDSetBit(OVL_CTRL_6D, 0xfd, 0x00);     // Set the OSD become two times of original width (dual pixel)

    if (2 < option)     option  = 2;

    RTDOSDW(OSD_CHANNEL);
    Show_TV_Number(channel, 1, 5 - option, option);
	
    if (stGUD3.TV_SETTING & 0x02)
    {
        RTDOSDW(OSD_MUTE);
    }
    else
    {
        RTDOSDW((stGUD3.TV_SETTING & 0x04) ? OSD_SAP : OSD_STEREO);
    }
}

void Show_TV_Number(unsigned char num, unsigned char row, unsigned char col, unsigned char option)
{
    RTDSetBit(OVL_CTRL_6D, 0xfd, 0x00);     // Set the OSD become two times of original width (dual pixel)

    Data[0]     = 5;
    Data[1]     = Y_INC;
    Data[2]     = OSD_ROW_90;
    Data[3]     = 0x80 | row;
    Data[4]     = col;

    Data[6]     = N_INC;
    Data[7]     = OSD_DATA_92;

    if (1 < option)
    {
        Data[5]     = 6;
        Data[11]    = 0;

        Data[8]     = num / 100;

        num         = num - (Data[8] * 100);

        Data[9]     = num / 10;
        Data[10]    = num - (Data[9] * 10) + _0_;        
        Data[8]     = Data[8] + _0_;
        Data[9]     = Data[9] + _0_;
    }
    else if (1 == option)
    {
        Data[5]     = 5;
        Data[10]    = 0;

        Data[8]     = num / 10;
        Data[9]     = num - (Data[8] * 10) + _0_;
        Data[8]     = Data[8] + _0_;
    }
    else
    {
        Data[5]     = 4;
        Data[9]     = 0;

        Data[8]     = num + _0_;
    }
    RTDWrite(Data);
}

void OSD_TV_Proc(unsigned char action)
{
    switch (ucOSD_Item_Index0)
    {
    case 1 :
        // ucOSD_Item_Index0 will be 1 when we are in TV control menu
        OSD_TV_Menu(action);

        if (ucOSD_Item_Index0)  return;

        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;

        if (NOTIFY_ENTER_KEY == action || NOTIFY_IR_MENU == action || NOTIFY_NONE == action)    action  = NOTIFY_SHOW;

        OSD_Clear(0, 15, 0, 30);
        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        break;
    case 2 :
        // ucOSD_Item_Index0 will be 2 when volume level is shown on screen.
        if (ucOSD_Item_Index2)      ucOSD_Item_Index2   -= 1;

        if (0 == ucOSD_Item_Index2 || (NOTIFY_NONE != action && NOTIFY_IR_VOLINC != action && NOTIFY_IR_VOLDEC != action))
        {
            ucOSD_Item_Index0   = 0;
            ucOSD_Item_Index1   = 0;
            ucOSD_Item_Index2   = 0;

            OSD_Clear(0, 15, 0, 30);
            Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        }
        break;
    case 3 :
        // ucOSD_Item_Index0 will be 3 when channel number is not shown on screen.
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        break;

    default :
        // ucOSD_Item_Index0 is 0xff~0xfd and ucOSD_Item_Index1 is non-zero when user inputs channel number.
        // We will issue NOTIFY_IR_ENTER automatically to end input when channel no. is identified or key is timeout.
        // We will abort if any other key is pressed.
        if (0xfd < ucOSD_Item_Index0)
        {
            if (0 == ucOSD_Item_Index2)
                ucOSD_Item_Index0   = 0xfd;
            else
                ucOSD_Item_Index2   = ucOSD_Item_Index2 - 1;

            if (NOTIFY_NONE != action && NOTIFY_SHOW != action && 
                NOTIFY_IR_ENTER != action && (NOTIFY_IR_NUM0 > action || NOTIFY_IR_NUM9 < action))
            {
                ucOSD_Item_Index0   = 0;
                ucOSD_Item_Index1   = 0;
                ucOSD_Item_Index2   = 0;
                Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
            }
        }

        if (0xfd == ucOSD_Item_Index0)
        {
            ucOSD_Item_Index2   = 0;
            action              = NOTIFY_IR_ENTER;
        }
        break;
    }

    switch (action)
    {
    case NOTIFY_SHOW :
        OSD_Clear(0, 15, 0, 30);

        if (0xfd > ucOSD_Item_Index0)
        {
            if (3 != ucOSD_Item_Index0)
            {
                ucOSD_Item_Index0   = 0;
                ucOSD_Item_Index1   = 0;
                ucOSD_Item_Index2   = 0;
                Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
            }
        }
        else
        {
            Show_TV_Info(ucOSD_Item_Index1, 0xff - ucOSD_Item_Index0);
        }
        break;

    case NOTIFY_ENTER_KEY :
    case NOTIFY_IR_MENU :
        ucOSD_Item_Index0   = 1;
        ucOSD_Item_Index1   = 1;
        ucOSD_Item_Index2   = 0;
        OSD_TV_Menu(NOTIFY_SHOW);
        break;

    case NOTIFY_RIGHT_KEY :
    case NOTIFY_IR_CHINC :
        // Increase the channel
        Next_Channel();
        Save_GUD3();

        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        ucOSD_Item_Index0   = 0;
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        break;

    case NOTIFY_LEFT_KEY :
    case NOTIFY_IR_CHDEC :
        // Decrease the channel
        Prev_Channel();
        Save_GUD3();

        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        ucOSD_Item_Index0   = 0;
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        break;

    case NOTIFY_IR_JUMP :
        Data[0]             = stGUD3.CURR_CHANNEL;
        stGUD3.CURR_CHANNEL = stGUD3.PREV_CHANNEL;
        stGUD3.PREV_CHANNEL = Data[0];
        Set_TV_Channel();
        Save_GUD3();

        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        ucOSD_Item_Index0   = 0;
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        break;

    case NOTIFY_IR_VOLINC :
    case NOTIFY_IR_VOLDEC :
        // Disable mute when changing volume
        stGUD3.TV_SETTING   = stGUD3.TV_SETTING & 0xfd;

        if (NOTIFY_IR_VOLINC == action)
            stGUD3.VOLUME   = 31 > stGUD3.VOLUME ? stGUD3.VOLUME + 1 : 31;
        else
            stGUD3.VOLUME   = 0 < stGUD3.VOLUME ? stGUD3.VOLUME - 1 : 0;

        SetVolume();
        Save_GUD3();

        RTDOSDW(OSD_VOLUME);	
        Show_TV_Number(stGUD3.VOLUME, 2, 4, 1);

        ucOSD_Item_Index0   = 2;
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 50;   // For time-out counter
        break;

    case NOTIFY_IR_MUTE :
        stGUD3.TV_SETTING   = stGUD3.TV_SETTING ^ 0x02;
        SetVolume();
        Save_GUD3();

        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        ucOSD_Item_Index0   = 0;
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        break;

    case NOTIFY_IR_ENTER :
        if (ucOSD_Item_Index1)
        {
            ucOSD_Item_Index0   = 0;

            if (stGUD3.TV_SETTING & 0x01)
            {
                if (MAX_CATV_NUM >= ucOSD_Item_Index1)
                {
                    stGUD3.PREV_CHANNEL = stGUD3.CURR_CHANNEL;
                    stGUD3.CURR_CHANNEL = ucOSD_Item_Index1;

                    ucOSD_Item_Index0   = 1;    // Valid channel
                }
            }
            else
            {
                if (MAX_AIR_NUM >= ucOSD_Item_Index1)
                {
                    stGUD3.PREV_CHANNEL = stGUD3.CURR_CHANNEL;
                    stGUD3.CURR_CHANNEL = ucOSD_Item_Index1;

                    ucOSD_Item_Index0   = 1;    // Valid channel
                }
            }

            if (ucOSD_Item_Index0)
            {
                Set_TV_Channel();

                if (stGUD3.PREV_CHANNEL != stGUD3.CURR_CHANNEL)
                {
                    // Disable mute when changing channel
                    stGUD3.TV_SETTING   = stGUD3.TV_SETTING & 0xfd;
                    SetVolume();
                }

                Save_GUD3();
            }
        }
        ucOSD_Item_Index0   = 0;
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        break;

    case NOTIFY_IR_DISP :
        ucOSD_Item_Index1   = 0;
        ucOSD_Item_Index2   = 0;
        OSD_Clear(0, 15, 0, 30);

        if (ucOSD_Item_Index0)
        {
            ucOSD_Item_Index0   = 0;
            Show_TV_Info(stGUD3.CURR_CHANNEL, 2);
        }
        else
        {
            ucOSD_Item_Index0   = 3;
        }
        break;

    default :
        // We handle IR messages
        if (NOTIFY_IR_NUM0 <= action && NOTIFY_IR_NUM9 >= action)
        {
            if (0xfd > ucOSD_Item_Index0)
            {
                ucOSD_Item_Index0   = 0xff;
                ucOSD_Item_Index1   = action - NOTIFY_IR_NUM0;
            }
            else
            {
                ucOSD_Item_Index0   = ucOSD_Item_Index0 - 1;
                ucOSD_Item_Index1   = (ucOSD_Item_Index1 * 10) + (action - NOTIFY_IR_NUM0);
            }

            ucOSD_Item_Index2   = 80;   // For time-out counter

            if (6 < ucOSD_Item_Index1)
            {
#if (TV_SYSTEM == TV_NTSC)
                if (0 == (stGUD3.TV_SETTING & 0x01) || 12 < ucOSD_Item_Index1)
#endif
                {
                    ucOSD_Item_Index0   = 0xfd;
                }
            }

            Show_TV_Info(ucOSD_Item_Index1, 0xff - ucOSD_Item_Index0);
        }
        break;
    }
}



void Highlight_Item(unsigned char index1, unsigned char index2)
{
    switch (index1)
    {
    case PAGE_TV_ITEM_SYSTEM :
        if (index2)
            OSD_Window(1, 0, 0, 0x13, 0x18, 7, COLOR_CYAN);
        else
            OSD_Window(1, 0, 0, 0x0a, 0x0e, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_CONTRAST :
        OSD_Window(1, 2, 2, 0x0a, 0x0e, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_BRIGHT :
        OSD_Window(1, 4, 4, 0x0a, 0x0e, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_SOUND :
        if (index2)
            OSD_Window(1, 6, 6, 0x13, 0x17, 7, COLOR_CYAN);
        else
            OSD_Window(1, 6, 6, 0x0a, 0x11, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_CHANNEL :
        OSD_Window(1, 8, 8, 0x0a, 0x0e, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_VOLUME :
        OSD_Window(1, 10, 10, 0x0a, 0x0d, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_AUTOSCAN :
        if (index2)
            OSD_Window(1, 12, 12, 0x13, 0x17, 7, COLOR_CYAN);
        else
            OSD_Window(1, 12, 12, 0x0a, 0x0d, 7, COLOR_CYAN);
        break;
    case PAGE_TV_ITEM_EXIT :
        OSD_Window(1, 14, 14, 0x00, 0x03, 7, COLOR_CYAN);
        break;
    }        
}

void OSD_TV_Menu(unsigned char action)
{
    switch (action)
    {
    case NOTIFY_ENTER_KEY :
        switch (ucOSD_Item_Index1)
        {
        case PAGE_TV_ITEM_SYSTEM :
            ucOSD_Item_Index1   = PAGE_TV_ITEM_CONTRAST;
            break;
        case PAGE_TV_ITEM_CONTRAST :
            ucOSD_Item_Index1   = PAGE_TV_ITEM_BRIGHT;
            break;
        case PAGE_TV_ITEM_BRIGHT :
            ucOSD_Item_Index1   = PAGE_TV_ITEM_SOUND;
            ucOSD_Item_Index2   = (stGUD3.TV_SETTING & 0x04) ? 1 : 0;
            break;
        case PAGE_TV_ITEM_SOUND :
            ucOSD_Item_Index1   = PAGE_TV_ITEM_CHANNEL;
            break;
        case PAGE_TV_ITEM_CHANNEL :
            ucOSD_Item_Index1   = PAGE_TV_ITEM_VOLUME;	 
            break;
        case PAGE_TV_ITEM_VOLUME :
            ucOSD_Item_Index1   = PAGE_TV_ITEM_AUTOSCAN;
            ucOSD_Item_Index2   = 0;
            break;
        case PAGE_TV_ITEM_AUTOSCAN :
            if (ucOSD_Item_Index2)
            {
                TV_AutoScan();
                
                ucMode_Curr = MODE_OSDFORCE;

                return;                 // Return, not break
            }
            else
            {
                ucOSD_Item_Index1   = PAGE_TV_ITEM_EXIT;
            }
            break;
        case PAGE_TV_ITEM_EXIT:
            ucOSD_Item_Index0   = 0;
            ucOSD_Item_Index1   = 0;
            ucOSD_Item_Index2   = 0;
            RTDOSDW(OSD_Reset);
            RTDCodeW(OSD_Enable);
            return;                     // Return, not break
        }
        // Hightlight next item if not returned
        Highlight_Item(ucOSD_Item_Index1, ucOSD_Item_Index2);
        break;

    case NOTIFY_RIGHT_KEY :     // Right-key to Increase; Left-key to Decrease
    case NOTIFY_LEFT_KEY :
        switch (ucOSD_Item_Index1)
        {
        case PAGE_TV_ITEM_SYSTEM :
            ucOSD_Item_Index2   = ucOSD_Item_Index2 ? 0 : 1;
            stGUD3.TV_SETTING   = ucOSD_Item_Index2 ? (stGUD3.TV_SETTING | 0x01) : (stGUD3.TV_SETTING & 0xfe);
            Set_TV_Channel();
            Save_GUD3();
            break;
        case PAGE_TV_ITEM_CONTRAST :
            if (NOTIFY_RIGHT_KEY == action)
            {
                if (KEY_TURBO_ENABLE > ucKey_Issued)
                    stGUD0.CONTRAST   = 100 > stGUD0.CONTRAST ? stGUD0.CONTRAST + 1 : 100;
                else
                    stGUD0.CONTRAST   = 99 > stGUD0.CONTRAST ? stGUD0.CONTRAST + 2 : 100;
            }
            else
            {
                if (KEY_TURBO_ENABLE > ucKey_Issued)
                    stGUD0.CONTRAST   = 0 < stGUD0.CONTRAST ? stGUD0.CONTRAST - 1 : 0;
                else
                    stGUD0.CONTRAST   = 1 < stGUD0.CONTRAST ? stGUD0.CONTRAST - 2 : 0;
            }
            Show_TV_Number(stGUD0.CONTRAST, 0x02, 0x0b, 0x02);
            Set_Bright_Contrast();
            Save_GUD0();
            break;
        case PAGE_TV_ITEM_BRIGHT :
            if (NOTIFY_RIGHT_KEY == action)
            {
                if (KEY_TURBO_ENABLE > ucKey_Issued)
                    stGUD0.BRIGHT   = 100 > stGUD0.BRIGHT ? stGUD0.BRIGHT + 1 : 100;
                else
                    stGUD0.BRIGHT   = 99 > stGUD0.BRIGHT ? stGUD0.BRIGHT + 2 : 100;
            }
            else
            {
                if (KEY_TURBO_ENABLE > ucKey_Issued)
                    stGUD0.BRIGHT   = 0 < stGUD0.BRIGHT ? stGUD0.BRIGHT - 1 : 0;
                else
                    stGUD0.BRIGHT   = 1 < stGUD0.BRIGHT ? stGUD0.BRIGHT - 2 : 0;
            }
            Show_TV_Number(stGUD0.BRIGHT, 0x04, 0x0b, 0x02);
            Set_Bright_Contrast();
            Save_GUD0();
            break;
        case PAGE_TV_ITEM_SOUND :
            ucOSD_Item_Index2   = ucOSD_Item_Index2 ? 0 : 1;
            stGUD3.TV_SETTING   = ucOSD_Item_Index2 ? (stGUD3.TV_SETTING | 0x04) : (stGUD3.TV_SETTING & 0xfb);
            // Disable mute when changing TV sound mode
            stGUD3.TV_SETTING   = stGUD3.TV_SETTING & 0xfd;
            SetVolume();
            Save_GUD3();
            break;
        case PAGE_TV_ITEM_CHANNEL :
            if (NOTIFY_RIGHT_KEY == action)
                Next_Channel();
            else
                Prev_Channel();
            Show_TV_Number(stGUD3.CURR_CHANNEL, 0x08, 0x0b, 0x02);
            Save_GUD3();
            break;

        case PAGE_TV_ITEM_VOLUME :
            if (NOTIFY_RIGHT_KEY == action)
                stGUD3.VOLUME   = (31 == stGUD3.VOLUME) ? 31 : stGUD3.VOLUME + 1;
            else
                stGUD3.VOLUME   = (0 == stGUD3.VOLUME) ? 0 : stGUD3.VOLUME - 1;
            Show_TV_Number(stGUD3.VOLUME, 0x0a, 0x0b, 0x01);
            SetVolume();
            Save_GUD3();
            break;
        case PAGE_TV_ITEM_AUTOSCAN :
            ucOSD_Item_Index2   = ucOSD_Item_Index2 ? 0 : 1;
            break;
        } 	
        Highlight_Item(ucOSD_Item_Index1, ucOSD_Item_Index2);
        break;

    case NOTIFY_SHOW :
        OSD_Clear(0, 15, 0, 30);
        RTDSetBit(OVL_CTRL_6D, 0xfd, 0x00);     // Set the OSD become two times of original width (dual pixel)

        RTDOSDW(OSD_PageTV);    
        
        switch (ucOSD_Item_Index1)
        {
        case PAGE_TV_ITEM_SYSTEM :
            ucOSD_Item_Index2   = (stGUD3.TV_SETTING & 0x01) ? 1 : 0;
            break;
        case PAGE_TV_ITEM_SOUND :
            ucOSD_Item_Index2   = (stGUD3.TV_SETTING & 0x04) ? 1 : 0;
            break;
        }        
        Highlight_Item(ucOSD_Item_Index1, ucOSD_Item_Index2);

        Show_TV_Number(stGUD0.CONTRAST, 0x02, 0x0b, 0x02);
        Show_TV_Number(stGUD0.BRIGHT, 0x04, 0x0b, 0x02);
        Show_TV_Number(stGUD3.CURR_CHANNEL, 0x08, 0x0b, 0x02);
        Show_TV_Number(stGUD3.VOLUME, 0x0a, 0x0b, 0x01);
        break;

    default :
        // We don't handle other messages
        if (NOTIFY_NONE != action || (0 == usOSD_Timer && 0 != stGUD1.OSD_TIMEOUT))
        {
            ucOSD_Item_Index0   = 0;
            ucOSD_Item_Index1   = 0;
            ucOSD_Item_Index2   = 0;
            RTDOSDW(OSD_Reset);
            RTDCodeW(OSD_Enable);
        }
        break;
    }
}

#endif


void OSD_Opening(void)
{
	int idata num;

	//OSD_Position(OSD_ENABLE);

	OSD_Window( 7, 0 , 488, 0, 264,
		 0, 0, 14, 251, 0, 1, 1);

	Delay_Xms(128);

	RTDCodeW(OSD_Enable);
	RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
						
	for(num = 0;num < 112; num+=6)
	{
		OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
			 0, 0, 14, 251, 0, 1, 1);
	}

	OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
		 0, 0, 14, 251, 0, 1, 0);

	

/*
#if (1)

    RTDCodeW(OSD_Enable);

#else

    // For OSD animetion

    RTDCodeW(Palette_Open);
    RTDCodeW(Palette_1);

    RTDCodeW(OSD_Enable);
    
    Delay_Xms(16);
    Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End                                    
    RTDCodeW(Palette_2);

    Delay_Xms(16);
    Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    RTDCodeW(Palette_3);
    
    Delay_Xms(28);
    Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    RTDCodeW(Palette_4);
    
    Delay_Xms(28);
    Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    RTDCodeW(Palette_5);

    Delay_Xms(28);
    Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    RTDCodeW(Palette_6);

    Delay_Xms(28);
    Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    RTDCodeW(Palette_7);

    RTDCodeW(Palette_Close);

#endif

*/
}

void OSD_Ending(void)
{
	int idata num;

	for(num = 112;num > 0; num-=6)
	{
		OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
			 0, 0, 14, 251, 0, 1, 1);
	}

	RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);     
	RTDOSDW(OSD_Reset);            // Clear OSD
	//Delay_Xms(128);
	OSD_Window( 7, 0 + num*2, 488 - num*2 , 0 + num, 264 - num,
		 0, 0, 14, 251, 0, 1, 0);


#if (0)

    // For OSD animetion

    unsigned char ucTemp;

    // First, clear debug information drawn by OSD_Show_Check()
    OSD_Line(13, 2, 24, 0x00, 0);
    OSD_Line(13, 2, 24, 0x00, 1);

    // Close unused window
    OSD_Window(0, 0, 0, 0, 0, 0, 0);
    OSD_Window(1, 0, 0, 0, 0, 0, 0);
    OSD_Window(2, 0, 0, 0, 0, 0, 0);

    OSD_Line(11, 2, 24, 0x00, 0);
    OSD_Line(11, 2, 24, 0x00, 1);

    for (ucTemp = 0; ucTemp < 5; ucTemp ++)
    {
        OSD_Line(ucTemp, 2, 24, 0x00, 0);          // Attribute
        OSD_Line(ucTemp, 2, 24, 0x00, 1);          // Display
        OSD_Line(10 - ucTemp, 2, 24, 0x00, 0);     // Attribute
        OSD_Line(10 - ucTemp, 2, 24, 0x00, 1);     // Display
        OSD_Window(3, ucTemp + 1, 9 - ucTemp, 2, 25,
            OSD_WINDOW_ENABLE | OSD_WINDOW_SHADOWING, COLOR_CYAN);  // Main OSD window

        Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    }

    OSD_Line(5, 2, 24, 0x00, 0);    // Attribute
    OSD_Line(5, 2, 24, 0x00, 1);    // Display

    for (ucTemp = 0; ucTemp < 12; ucTemp += 2)
    {
        OSD_Window(3, 5, 5, ucTemp + 3, 23 - ucTemp,
            OSD_WINDOW_ENABLE | OSD_WINDOW_SHADOWING, COLOR_CYAN);

        Wait_For_Event(EVENT_DEN_STOP);     // Wait for Frame End
    }

#endif
}


//Not modified yet
void Show_Note(void)
{
	RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
	RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
	//RTDCodeW(OSD_Reset);
	OSD_Position(OSD_ENABLE);


	// When input format changed, OSD will be cleared by Detect_VGA_Mode() and Detect_AV_Mode()
	switch (stGUD1.INPUT_SOURCE & 0x07)
	{
		case SOURCE_VGA:
//#if (VIDEO_CHIP != VDC_NONE)
			RTDOSDW(OSD_RGB);  // OSD RGB note
//#endif
			break;
			
		case SOURCE_DVI:
			RTDOSDW(OSD_DVI);  // OSD DVI note
			break;
			
		case SOURCE_AV:
			RTDOSDW(OSD_AV);   // OSD AV note
			break;
			
		case SOURCE_SV:
			RTDOSDW(OSD_SV);   // OSD S-Video note
			break;
			
		case SOURCE_YUV:
			RTDOSDW(OSD_YUV);  // OSD YUV note
			break;
			
		case SOURCE_TV:
			RTDOSDW(OSD_TV);
			break;
			
	}

	
	RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
	//RTDCodeW(OSD_Enable);
	
}


//Not modified yet
void Show_Hint(void)
{
	if (MODE_NOSIGNAL == ucMode_Curr)
	{
		RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
		//RTDCodeW(OSD_Reset);

#if(MCU_TYPE == MCU_WINBOND)
		if ((SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07)) && (VGA_ONLINE != bVGA_CONNECT))
#else
		if ((SOURCE_VGA == (stGUD1.INPUT_SOURCE & 0x07)) && (VGA_ONLINE != MCU_ReadVgaConnect()))
#endif
		{
			RTDOSDW(OSD_HINT_TABLE[0][stGUD1.FUNCTION & 0x07]);
		}
		else
		{
			RTDOSDW(OSD_Clean_All);
			RTDOSDW(OSD_HINT_TABLE[1][stGUD1.FUNCTION & 0x07]);
		}

		//RTDCodeW(OSD_Enable);
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
	}
	else if ((MODE_NOSUPPORT == ucMode_Curr) || bOverSpec)
	{
		RTDSetByte(HOSTCTRL_02, 0x40);  // Wake RTD up
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x00);
		//RTDCodeW(OSD_Reset);

		RTDOSDW(OSD_HINT_TABLE[2][stGUD1.FUNCTION & 0x07]);

		//RTDCodeW(OSD_Enable);
		RTDSetBit(OVL_CTRL_6D, 0xfe, 0x01);
	}
}


#if (SHOW_CHECK)
void OSD_Show_Check(void)
{
	OSD_Line(17, 2, 38, 0, 1);                       // Attribute

	//OSD_Show_Num(0x02, ucOSD_Page_Index);                       // Status
	//OSD_Show_Num(0x02, ucDebug_Value0);                       // Status
	OSD_Show_Num(0x02, ucDebug_Value0);                       // Status
	
	OSD_Show_Num(0x05, ucDebug_Value1);                    // ucMode_Curr
	//OSD_Show_Num(0x05, stMUD.V_POSITION);                    // ucMode_Curr

	OSD_Show_Num(0x08, ucDebug_Value2);
    //OSD_Show_Num(0x08, ucMode_Curr);

	RTDRead(LAST_LINE_H_2C, 1, N_INC);                  // Last Line Length
	Data[15]    = Data[0] & 0xf8;
	OSD_Show_Num(0x0b, Data[15] >> 6);
	RTDRead(LAST_LINE_L_26, 1, N_INC);
	OSD_Show_Num(0x0d, (Data[15] << 2) | (Data[0] >> 3));

#if (RTDDEBUG)
	OSD_Show_Num(0x10, (unsigned char)(usPE_Sum >> 8));
	OSD_Show_Num(0x12, (unsigned char)usPE_Sum);
	OSD_Show_Num(0x17, (unsigned char)ucPE_Level);
#else
	OSD_Show_Num(0x10, (unsigned char)(usHsync >> 8));  // usHsync
	OSD_Show_Num(0x12, (unsigned char)usHsync);
	OSD_Show_Num(0x15, (unsigned char)(usVsync >> 8));  // usVsync
	OSD_Show_Num(0x17, (unsigned char)usVsync);   

#endif

}

void OSD_Show_Num(unsigned char column, unsigned char no)
{
	unsigned int idata usStart_Addr;
	unsigned char idata ucTemp;

	usStart_Addr = FONT_SELECT_ADDRESS;

	//The address of the first character Cn1 in Row n = FONT_SELECT_ADDRESS + Row0_length + Row1_length +...+Row(n-1)_length
	for(ucTemp = 1; ucTemp < 17+1; ucTemp ++)
		usStart_Addr += Row_Info[0][ucTemp];

	Data[0]     = 5;
	Data[1]     = Y_INC;
	Data[2]     = OSD_ROW_90;
	Data[3] = (unsigned char)( (((usStart_Addr + column)  & 0x0fff) >> 8 ) | 0x50);
	Data[4] = (unsigned char)( (usStart_Addr + column) & 0x00ff);
	Data[5]     = 0;                 	
	RTDWrite(Data);

	column  = no / 16;              // Bit 7~4
	no      = no - (column * 16);   // Bit 3~0

	column  = (9 < column) ? (column + (0x20 - 10)) : (column + _0_);
	no      = (9 < no) ? (no + (0x20 - 10)) : (no + _0_);
    
	Data[0] = 5;
	Data[1] = N_INC;
	Data[2] = OSD_DATA_92;
	Data[3] = column;
	Data[4] = no;
	Data[5] = 0;
	RTDWrite(Data);
}
#endif
