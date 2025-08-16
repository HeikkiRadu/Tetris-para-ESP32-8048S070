#include "tetris.h"

#include "display_config.h"

#define DISPLAY_HIGH          480
#define DISPLAY_WIDTH         800

void draw_callback(MapaConfig *_mapa) {
  for(int i = 0; i < _mapa -> tetris_map_div_width; i++) {
    for(int j = 0; j < _mapa -> tetris_map_div_high; j++) {
      gfx->fillRect(_mapa -> tetris_square_width * i, _mapa -> tetris_square_high * j,  // x, y
                    _mapa -> tetris_square_width, _mapa -> tetris_square_high,          // longX, longY
                    Colores[mapa[i][j]]);                                               // Color
    }
  }
}

void setup() {
  
  Serial.begin(115200);
  
  pinMode(DISPLAY_BL, OUTPUT);
  digitalWrite(DISPLAY_BL, HIGH);
  
  gfx->begin();
  //gfx->fillScreen(Colores[TETRIS_ROJO]);
  tetris_config(DISPLAY_HIGH, DISPLAY_WIDTH);
  
  setDrawTetrisMapCallback(draw_callback);
  drawTetrisMapCallback();

  FigureO unafigura;
  
}

void loop() {

  //Serial.println(mapa.length_high);
  
}
