#define __SOURCECTRL__

#include "Header\Lcd_main.h"
#include "Header\Lcd_func.h"
#include "Header\Mode_Detect.h"
#include "Header\Initial.h"
#include "Header\Src_Ctrl.h"
#include "Header\Access.h"

bit Source_Control(void)
{
            if ((stGUD1.INPUT_SOURCE & 0x07) != ucInputSrc)
            {
                stGUD1.INPUT_SOURCE = (stGUD1.INPUT_SOURCE & 0xf8) | (ucInputSrc & 0x07);
                Save_GUD1();
                
                ucModeCnt   = MODE_DETECT_FREQ;     // Reset Input Mode Detector

                Reset_Mode();


                Init_Input_Source();
                Measure_Mode();
                
                Set_Task(STATE_SOURCECHANGE);       // Notify Task State Machine

                bNotify_Timer0_Int  = 0;

                //continue;   // leave current iteration.
				return _TRUE;
            }
			return _FALSE;
}

void Change_Source(unsigned char source)
{
    if (SOURCE_MAX < source)    return;

    if (SOURCE_VGA == source)
    {
        ucInputSrc  = SOURCE_VGA;
    }
 else if (SOURCE_DVI == source)
    {
#if (TMDS_ENABLE) 
        ucInputSrc  = SOURCE_DVI;
#else
        ucInputSrc  = SOURCE_VGA;
#endif
    }
    else if (SOURCE_AV == source || SOURCE_SV == source)
    {
#if (VIDEO_CHIP != VDC_NONE)
        ucInputSrc  = source;   // SOURCE_AV or SOURCE_SV      
#else
        ucInputSrc  = SOURCE_VGA;
#endif
    }
    else if (SOURCE_YUV == source)
    {
#if (VIDEO_CHIP == VDC_SAA7118)
        ucInputSrc  = source;   // SOURCE_YUV
#else
        ucInputSrc  = SOURCE_VGA;
#endif
    }
    else
    {
#if (TV_CHIP != TV_NONE)
        ucInputSrc = source;    // SOURCE_TV
#else
        ucInputSrc = SOURCE_VGA;
#endif
    }
}

#if(SOURCE_AUTO_SCAN)
void Source_Auto_Scan(void)
{

             Data[0] = stGUD1.INPUT_SOURCE & 0x07; 
             if((Data[0] == MASTER_SOURCE) || (Data[0] == SLAVE_SOURCE) || (Data[0] == THIRD_SOURCE)) 
			     bSourceScanEnable = !bSourceScanEnable;

				if(!bSourceScanEnable)
                     Mode_Detector();

				if(bStable && bSourceScanEnable)
                {
				    
					Measure_Source(ucNext_Source);

					if((ucNext_Source == SOURCE_VGA) || (ucNext_Source == SOURCE_DVI))
					{
						RTDRead(SYNC_POR_4C, 0x09, Y_INC);
                        
						if(Data[0] & 0x02)
                        {
                           RTDSetByte(SYNC_POR_4C,0x20);
                           Data[2] = 0x80;
                           Data[4] = 0x80;
                        }

						if(((Data[4] & 0x80) != 0x80) && ((Data[2] & 0x80) != 0x80))
						{
							Data[5] = Data[3];
							Data[4] = Data[4] & 0x87;
							Data[3] = Data[1];
							Data[2] = Data[2] & 0x8f;							
							
							if( (((unsigned int*)Data)[1] < 1024)  && (((unsigned int*)Data)[1] > 260) &&
								(((unsigned int*)Data)[2] < 1260)  && (((unsigned int*)Data)[2] > 430))
							{
								if(ucSource_Times < VGA_SEARCH_TIMES)
									ucSource_Times += 1;
								else
								{
									ucInputSrc = ucNext_Source;
									ucNext_Source = MASTER_SOURCE; 
									ucSource_Times = 0;
								}									
							}
							else
							{
								ucSource_Times = 0;
							
                                 ucNext_Source = (ucNext_Source == MASTER_SOURCE) ? SLAVE_SOURCE : 
								(ucNext_Source == SLAVE_SOURCE ) ? THIRD_SOURCE : MASTER_SOURCE;
 														                                                                       		
							}
							
						}
						else
						{
							ucSource_Times = 0;
				            ucNext_Source = (ucNext_Source == MASTER_SOURCE) ? SLAVE_SOURCE : 
								(ucNext_Source == SLAVE_SOURCE ) ? THIRD_SOURCE : MASTER_SOURCE;
							
						}
					}//end of if((ucNext_Source == SOURCE_VGA) || (ucNext_Source == SOURCE_DVI))
					else
					{
						I2CRead(ADDR_VIDEO, 0x1f, 0x01);
					
						if (0 == (Data[0] & 0x40))
						{
							if(ucSource_Times < VGA_SEARCH_TIMES)
									ucSource_Times += 1;
							else
							{
								ucInputSrc = ucNext_Source;
								ucNext_Source = MASTER_SOURCE; 
								ucSource_Times = 0;
							}		
						}
						else
						{
							ucSource_Times = 0;
                          
                             ucNext_Source = (ucNext_Source == MASTER_SOURCE) ? SLAVE_SOURCE : 
								(ucNext_Source == SLAVE_SOURCE ) ? THIRD_SOURCE : MASTER_SOURCE;
						}
					}
					
					RTDSetByte(SYNC_CTRL_4A,0x00);
					//RTDSetByte(SYNC_POR_4C, (stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA ? 0x32 : 0x02);
					
					if(((stGUD1.INPUT_SOURCE & 0x07) == SOURCE_VGA) && (SYNC_SS != ucSync_Type))
                       RTDSetByte(SYNC_POR_4C,0x32);
                    else
                       RTDSetByte(SYNC_POR_4C,0x02);
                    
				}//end of if(bStable)
}
#endif
