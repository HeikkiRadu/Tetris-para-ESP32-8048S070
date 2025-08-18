#include "tetris.h"

#include "display_config.h"

#define DISPLAY_HIGH          480
#define DISPLAY_WIDTH         800

void draw_callback(Tetris *_tetris) {
  for(int i = 0; i < _tetris -> tetris_map_div_width; i++) {
    for(int j = 0; j < _tetris -> tetris_map_div_high; j++) {
      gfx->fillRect(_tetris -> tetris_square_width * i, _tetris -> tetris_square_high * j,    // x, y
                    _tetris -> tetris_square_width, _tetris -> tetris_square_high,            // longX, longY
                    Colores[_tetris -> mapa[i][j]]);                                               // Color
    }
  }
}

void setup() {
  
  Serial.begin(115200);
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx->begin();
  //gfx->fillScreen(Colores[TETRIS_ROJO]);
  tetris_init(DISPLAY_HIGH, DISPLAY_WIDTH);
  
  setDrawTetrisMapCallback(draw_callback);
  drawTetrisMapCallback();
  
  //Figure *unafigura = new Figure(FIGURE_T, 5, 6);
  //Serial.println(unafigura -> getFigureType());
  //delete unafigura;
  Serial.println(6 == FIGURE_T);
  
}

void loop() {

  //Serial.println(mapa.length_high);
  
}
