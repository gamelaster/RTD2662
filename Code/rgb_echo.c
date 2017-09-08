
#include "reg52.h" 
#include "Header\MTV512.H"

#include "Header\MAIN_DEF.H"
#include "Header\CONFIG.H"
#include "Header\ACCESS.H"
#include "Header\LCD_FUNC.H"
//#include "Header\LCD_AUTO.H"
//#include "Header\LCD_MSG.H"
#include "Header\LCD_MAIN.H"
#include "Header\LCD_OSD.H"
//#include "Header\FONT.H"
#include "Header\OSD.H"
//#include "Header\SRC_CTRL.H"
//#include "Header\OSD_TREE.H"
#include "Header\rgb_echo.H"

/*
void rgb_OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color, unsigned char color_slider)
{

//--------------設定 1 bit font 起始位置
	Data[0] = 5;
	Data[1] = Y_INC;
	Data[2] = OSD_ADDR_MSB_90;
	Data[3] = 0x50; // | (usStart_Addr >> 8);
	Data[4] = col;  //0x00 | (usStart_Addr & 0x00ff);
	Data[5] = 0;
	RTDWrite(Data);


//---------------畫左圓弧
    Data[0] = 4;
	Data[1] = N_INC;
	Data[2] = OSD_DATA_92;
	Data[3] = 0x1a;	
    Data[4] = 4;
    Data[5] = BURST;
    Data[6] = OSD_DATA_92;
    Data[7] =
    
	RTDWrite(Data);


}

*/

//		rgb_OSD_Slider(0, 16, 12, 0x1f - stGUD3.VOLUME, 0x1f, 4, 14);

void rgb_OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color, unsigned char color_slider)
{
	unsigned int idata usStart_Addr;
//	unsigned char idata ucTemp;
	unsigned int bound;

	usStart_Addr = 0;

//	for(ucTemp = 1; ucTemp < row+1; ucTemp ++)
//		usStart_Addr += Row_Info[0][ucTemp];

    usStart_Addr = col;

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

void rgb_LED_LIGHT_CONTROL(void)
{
        if ((bStable)&& (bPower_Status) && (MODE_NOSIGNAL != ucMode_Curr)&& (MODE_NOSUPPORT != ucMode_Curr)) //anson
        {
          SetMute(1);
          bGREEN_LED = 0;
          bRED_LED   = 1;
        }
        else 
        {
            if (!bPower_Status)
            {
               bRED_LED   = 1;			//anson	MTV512	1 = off	0 = on
               bGREEN_LED = 1;			//		Tp2804	1 = on	0 = off
            }
            else
            {
               bRED_LED   = 0;
               bGREEN_LED = 1;
            }
        }
}


void rgb_EXIT_KEY(void)
{
           if(ucOSD_Page_Index)
           {
             if (ucOSD_Item_Index0)
             {
               if (ucOSD_Item_Index1)
               {
                 if (ucOSD_Item_Index2)
                 {
                   ucOSD_Item_Index2 = 0;
                 }
                 else
                 {
                   ucOSD_Item_Index1 = 0;
                 }
               }
               else
               {
                 ucOSD_Item_Index0 = 0;
                   OSD_Window( 6, 150, 282, (54 + (ucOSD_Item_Index0-1)*(29+4)), (84 + (ucOSD_Item_Index0-1)*(29+4))
                                , 0, 0, 14, 251, 0, 1, 0);

               }
             }
             else
             {
               ucOSD_Page_Index = 0;
             }
           }

}
