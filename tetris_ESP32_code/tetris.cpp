#include "tetris.hpp"

Tetris::Tetris(unsigned int display_high, unsigned int display_width) {
  initiated = 1;
  square_high = display_high / TETRIS_MAP_DIV_HIGH;
  square_width = display_width / TETRIS_MAP_DIV_WIDTH;
  map_div_high = TETRIS_MAP_DIV_HIGH;
  map_div_width = TETRIS_MAP_DIV_WIDTH;
  for(int i = 0; i < TETRIS_MAP_DIV_WIDTH; i++) {
    for(int j = 0; j < TETRIS_MAP_DIV_HIGH; j++) {
      mapa[i][j] = i == 0 || i == TETRIS_MAP_DIV_WIDTH - 1 ||
                   j == 0 || j == TETRIS_MAP_DIV_HIGH - 1 ?
                   1 : 0;
    }
  }
}

// Registra la función de dibujado en pantalla del usuario
void Tetris::setDrawTetrisMapCallback(void (*_drawMapCallback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)) {
  drawMapCallback = _drawMapCallback;
}

void Tetris::setRandomNumberCallback(unsigned int (*_getRandomNumber)(void)) {
  bag.getRandomNumber = _getRandomNumber;
  bag.mixBag();
}

void Tetris::setTimeCallback(unsigned long (*_timeCallback)(void)) {
  timeCallback = _timeCallback;
}
