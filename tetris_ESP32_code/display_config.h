#include <Arduino_GFX_Library.h>

#define DISPLAY_BL 2

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(GFX_NOT_DEFINED /* CS */, GFX_NOT_DEFINED /* SCK */, GFX_NOT_DEFINED /* SDA */,
                                                       41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
                                                       14 /* R0 */, 21 /* R1 */,    47 /* R2 */,    48 /* R3 */,  45 /* R4 */,
                                                        9 /* G0 */, 46 /* G1 */,     3 /* G2 */,     8 /* G3 */,  16 /* G4 */, 1 /* G5 */,
                                                       15 /* B0 */, 7  /* B1 */,     6 /* B2 */,     5 /* B3 */,   4 /* B4 */);

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
Arduino_RPi_DPI_RGBPanel *gfx = new Arduino_RPi_DPI_RGBPanel(bus,
                                                             800 /*width*/,  0 /*hsync_polarity*/, 16 /*hsync_front_porch*/, 4 /*hsync_pulse_width*/, 32 /*hsync_back_porch*/,
                                                             480 /*height*/, 0 /*vsync_polarity*/, 16 /*vsync_front_porch*/, 4 /*vsync_pulse_width*/, 32 /*vsync_back_porch*/,
                                                             1 /*pclk_active_neg*/, 16000000 /*prefer_speed*/, true /*auto_flush*/);

/*(bus, 800, 0, 210, 30, 16,
480, 0, 22, 13, 10, 1, 16000000, true);*/
