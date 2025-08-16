#include "tetris.h"

// Función para registrar las dimensiones del mapa de tetris
void tetris_config(unsigned int display_high, unsigned int display_width) {
  mapa_conf.initiated = 1;
  mapa_conf.tetris_square_high = display_high / TETRIS_MAP_DIV_HIGH;
  mapa_conf.tetris_square_width = display_width / TETRIS_MAP_DIV_WIDTH;
  mapa_conf.tetris_map_div_high = TETRIS_MAP_DIV_HIGH;
  mapa_conf.tetris_map_div_width = TETRIS_MAP_DIV_WIDTH;
  for(int i = 0; i < TETRIS_MAP_DIV_WIDTH; i++) {
    for(int j = 0; j < TETRIS_MAP_DIV_HIGH; j++) {
      if(i == 0 || i == TETRIS_MAP_DIV_WIDTH - 1 || j == 0 || j == TETRIS_MAP_DIV_HIGH - 1)
        mapa[i][j] = 1;
    }
  }
}

void setDrawTetrisMapCallback(void (*_drawMap)(MapaConfig *)) {
  drawMap = _drawMap;
}

void drawTetrisMapCallback(void) {
  drawMap(&mapa_conf);
}
