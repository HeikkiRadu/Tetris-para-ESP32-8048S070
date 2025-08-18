#include "tetris.h"

// Función para registrar las dimensiones del mapa de tetris e inicializar el mapa
void tetrisInit(unsigned int display_high, unsigned int display_width) {
  tetris.initiated = 1;
  tetris.tetris_square_high = display_high / TETRIS_MAP_DIV_HIGH;
  tetris.tetris_square_width = display_width / TETRIS_MAP_DIV_WIDTH;
  tetris.tetris_map_div_high = TETRIS_MAP_DIV_HIGH;
  tetris.tetris_map_div_width = TETRIS_MAP_DIV_WIDTH;
  for(int i = 0; i < TETRIS_MAP_DIV_WIDTH; i++) {
    for(int j = 0; j < TETRIS_MAP_DIV_HIGH; j++) {
      if(i == 0 || i == TETRIS_MAP_DIV_WIDTH - 1 || j == 0 || j == TETRIS_MAP_DIV_HIGH - 1)
        tetris.mapa[i][j] = 1;
    }
  }
}

// Registra la función de dibujado en pantalla del usuario
void setDrawTetrisMapCallback(void (*_drawMap)(Tetris *)) {
  drawMap = _drawMap;
}

// Ejecuta la función de dibujado en pantalla del usuario enviando 
void drawTetrisMapCallback(void) {
  drawMap(&tetris);
}
