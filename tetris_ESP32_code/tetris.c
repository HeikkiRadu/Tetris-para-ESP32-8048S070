#include "tetris.h"

// Función para registrar las dimensiones del mapa de tetris
void tetris_config(unsigned int _length_high, unsigned int _length_width, unsigned int _div_high, unsigned int _div_width) {
  mapa_conf.initiated = 1;
  mapa_conf.length_high = _length_high;
  mapa_conf.length_width = _length_width;
  mapa_conf.div_high = _div_high;
  mapa_conf.div_width = _div_width;
}
