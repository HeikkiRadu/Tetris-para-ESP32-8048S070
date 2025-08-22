#include "tetris.hpp"

// Ejecuta la función de dibujado en pantalla del usuario enviando los argumentos x, y, w, h y color
void Tetris::drawMap(void) {
  for(int i = 0; i < map_div_width; i++) {
    for(int j = 0; j < map_div_high; j++) {
      drawMapCallback(square_width * i, square_high * (map_div_high - 1 - j),
                      square_width, square_high,
                      Colores[mapa[i][j]]);
    }
  }
}

void Tetris::setFigureOnMap(void) {
  if(figure_active == nullptr) {
    figure_active = bag.getNextFigure();
  }

  char *figure_map_ptr = figure_active -> getMap();
  
  unsigned int offset_x = figure_active -> getPosX();
  unsigned int offset_y = figure_active -> getPosY();
  char map_length = figure_active -> getMapLength();
  for(int i = 0; i < map_length; i++) {
    for(int j = 0; j < map_length; j++) {
      mapa[offset_y + i][offset_x + j] = *(figure_map_ptr + i * map_length + j);
    }
  }
}
