#include "display_config.h"
#include "esp_system.h"
#include "tetris.hpp"

#define DISPLAY_HIGH          480
#define DISPLAY_WIDTH         800

void draw_callback(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int color) {
  gfx->fillRect(x, y, w, h, color);  // x, y, longX, longY, Color
}

void setup() {
  
  Serial.begin(115200);
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx->begin();
  
  tetrisInit(DISPLAY_HIGH, DISPLAY_WIDTH);   // High, Width
  
  setDrawTetrisMapCallback(draw_callback);
  drawTetrisMapCallback();
  
  //Figure *unafigura = new Figure(FIGURE_T, 5, 6);
  //Serial.println(unafigura -> getFigureType());
  //delete unafigura;
  //uint32_t hw_random = esp_random() % FIGURE_COUNT;  // número aleatorio de 32 bits
  //Serial.println(hw_random);
  
}

void loop() {
  
}
