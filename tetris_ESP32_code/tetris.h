#ifndef TETRIS_H
#define TETRIS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "color_defines.h"

// Estructura del mapa
struct MapaConfig {
  unsigned int initiated;
  unsigned int length_high;
  unsigned int length_width;
  unsigned int div_high;
  unsigned int div_width;
} mapa_conf;

// Prototipo de la función para registrar las dimensiones del mapa de tetris
void tetris_config(unsigned int, unsigned int, unsigned int, unsigned int);

#ifdef __cplusplus
}
#endif

#endif
