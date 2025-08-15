#include "tetris.h"

#include "display_config.h"

#define display_high          480
#define display_width         800
#define tetris_map_div_high   12
#define tetris_map_div_width  20

void setup() {
  
  Serial.begin(115200);
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx->begin();
  gfx->fillScreen(BLUE);
  
  //tetris_config(display_high, display_width, tetris_map_div_high, tetris_map_div_width);
  //gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
  
}

void loop() {

  //Serial.println(mapa.length_high);
  
}
