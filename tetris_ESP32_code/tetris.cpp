#include "tetris.hpp"

Tetris::Tetris(unsigned int display_high, unsigned int display_width) {
  initiated = 1;
  square_high = display_high / TETRIS_MAP_DIV_HIGH;
  square_width = display_width / TETRIS_MAP_DIV_WIDTH;
  map_div_high = TETRIS_MAP_DIV_HIGH;
  map_div_width = TETRIS_MAP_DIV_WIDTH;
  for(int i = 0; i < TETRIS_MAP_DIV_WIDTH; i++) {
    for(int j = 0; j < TETRIS_MAP_DIV_HIGH; j++) {
      i == 0 || i == TETRIS_MAP_DIV_WIDTH - 1 || j == 0 || j == TETRIS_MAP_DIV_HIGH - 1 ? mapa[i][j] = 1 :
                                                                                          mapa[i][j] = 0;
    }
  }
}

// Registra la función de dibujado en pantalla del usuario
void Tetris::setDrawTetrisMapCallback(void (*_drawMap)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)) {
  drawMap = _drawMap;
}

// Ejecuta la función de dibujado en pantalla del usuario enviando 
void Tetris::drawTetrisMapCallback(void) {
  for(int i = 0; i < map_div_width; i++) {
    for(int j = 0; j < map_div_high; j++) {
      drawMap(square_width * i, square_high * j,
              square_width, square_high,
              Colores[mapa[i][j]]);
    }
  }
}

void Tetris::setRandomNumberCallback(unsigned int (*_getRandomNumber)(void)) {
  bag.getRandomNumber = _getRandomNumber;
  bag.mixBag();
}
