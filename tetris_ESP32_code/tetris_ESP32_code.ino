#include "display_config.h"
#include "esp_system.h"
#include "tetris.hpp"
#include "touch.hpp"

#define DISPLAY_HEIGHT  480
#define DISPLAY_WIDTH   800

Tetris *tetris = new Tetris(DISPLAY_HEIGHT, DISPLAY_WIDTH);   // High, Width

unsigned int random_generator_callback(void) {
  return esp_random();
}

void draw_callback(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int color) {
  gfx->fillRect(x, y, w, h, color);  // x, y, longX, longY, Color
}

unsigned long time_miliS_callback(void) {
  return millis();
}

bool isTouched_prev = false;
uint16_t x_start = 0;
uint16_t y_start = 0;

Move input_move_callback(void) {

  Move move_input = MOVE_IDE;
  
  tp.read();
  bool isTouched_act = tp.isTouched;
  if(isTouched_act && !isTouched_prev) {
    x_start = tp.points[0].x;
    y_start = tp.points[0].y;
  } else if(isTouched_act && isTouched_prev) {
    int16_t displacement_y = tp.points[0].y - y_start;
    int16_t displacement_x = tp.points[0].x - x_start;
    if(displacement_y <= -30) {
      //Serial.println("Movimiento a la izquierda");
      move_input = MOVE_LEFT;
    } else if(displacement_y >= 30){
      //Serial.println("Movimiento a la derecha");
      move_input = MOVE_RIGHT;
    } else if(displacement_x <= -40) {
      //Serial.println("Movimiento hacia abajo");
      move_input = MOVE_DOWN;
    }/* else if(displacement_x >= 80){
      Serial.println("Movimiento hacia arriba");
    }*/
  } else if((!isTouched_act && isTouched_prev) || (!isTouched_act && !isTouched_prev)) {
    if(!isTouched_act && isTouched_prev)
      move_input = MOVE_ROTATION;
    x_start = 0;
    y_start = 0;
  }
  
  isTouched_prev = isTouched_act;

  return move_input;
  
}

void setup() {
  
  Serial.begin(115200);
  
  initTouch();
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx -> begin();
  
  tetris -> setDrawTetrisMapCallback(draw_callback);
  tetris -> setRandomNumberCallback(random_generator_callback);
  tetris -> setTimeCallback(time_miliS_callback);
  tetris -> setInputMoveCallback(input_move_callback);
  
}

void loop() {
  
  tetris -> timer_handler();
  
}
