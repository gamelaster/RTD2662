#ifdef __OSD__



//  unsigned int idata us_rgb_Temp01 = 0;
//  unsigned int idata us_rgb_Temp02 = 0;

  
  bit b_rgb_VOLUME_STATUS = 0;

  void rgb_OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
                unsigned char color, unsigned char color_slider);
  void rgb_LED_LIGHT_CONTROL(void);

  void rgb_EXIT_KEY(void);


#else

   //extern void rgb_OSD_Slider(unsigned char row, unsigned char col, unsigned char length, unsigned char value, unsigned char range,
  //              unsigned char color, unsigned char color_slider);

//  extern unsigned int idata us_rgb_Temp01;
//  extern unsigned int idata us_rgb_Temp02;

   extern bit b_rgb_VOLUME_STATUS;
   extern void rgb_LED_LIGHT_CONTROL(void);

   extern void rgb_EXIT_KEY(void);


#endif 
