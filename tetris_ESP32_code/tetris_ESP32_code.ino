#include "tetris.h"

#include "display_config.h"

#define display_high          480
#define display_width         800
#define tetris_map_div_high   12
#define tetris_map_div_width  20

uint16_t color[20*20];

void setup() {

  for(int i = 0; i < 20*20; i++) {
    color[i] = Colores[2]; // BRG -> 5bits 5bits 6bits
  }
  
  Serial.begin(115200);
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx->begin();
  gfx->fillScreen(BLUE);
  
  //tetris_config(display_high, display_width, tetris_map_div_high, tetris_map_div_width);
  gfx->draw16bitRGBBitmap(50, 50, color, 20, 20);
  
}

void loop() {

  //Serial.println(mapa.length_high);
  
}
