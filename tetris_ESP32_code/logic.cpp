#include "tetris.hpp"

// Ejecuta la función de dibujado en pantalla del usuario enviando los argumentos x, y, w, h y color
void Tetris::drawMap(void) {
  for(int i = 0; i < map_div_width; i++) {
    for(int j = 0; j < map_div_high; j++) {
      drawMapCallback(square_width * i, square_high * j,
                      square_width, square_high,
                      Colores[mapa[i][j]]);
    }
  }
}
