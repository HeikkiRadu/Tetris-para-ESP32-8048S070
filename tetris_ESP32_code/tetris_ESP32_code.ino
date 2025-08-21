#include "display_config.h"
#include "esp_system.h"
#include "tetris.hpp"

#define DISPLAY_HIGH          480
#define DISPLAY_WIDTH         800

Tetris *tetris = new Tetris(DISPLAY_HIGH, DISPLAY_WIDTH);   // High, Width

unsigned int random_generator_callback(void) {
  return esp_random();
}

void draw_callback(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int color) {
  gfx->fillRect(x, y, w, h, color);  // x, y, longX, longY, Color
}

void setup() {
  
  Serial.begin(115200);
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx -> begin();
  
  tetris -> setDrawTetrisMapCallback(draw_callback);
  tetris -> drawTetrisMapCallback();

  tetris -> setRandomNumberCallback(random_generator_callback);
  
  
  
}

void loop() {
  
}
