#ifndef TETRIS_H
#define TETRIS_H

#ifdef __cplusplus
#include "figures_types.hpp"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "color_defines.h"

#define TETRIS_MAP_DIV_HIGH   12
#define TETRIS_MAP_DIV_WIDTH  20

// Estructura del mapa
typedef struct Tetris {
  unsigned int initiated;
  unsigned int tetris_map_div_high;
  unsigned int tetris_map_div_width;
  unsigned int tetris_square_high;
  unsigned int tetris_square_width;
  char mapa[TETRIS_MAP_DIV_WIDTH][TETRIS_MAP_DIV_HIGH];
} Tetris;

// Estructura de la configuración del mapa
Tetris tetris;

// Prototipo de la función para registrar las dimensiones del mapa de tetris
void tetris_init(unsigned int, unsigned int);

// Permite registrar la función de dibujado en pantalla del usuario
void setDrawTetrisMapCallback(void (*)(Tetris *));

// Ejecuta la función de dibujado en pantalla del usuario
void drawTetrisMapCallback(void);

// Puntero a función de dibujado en pantalla del usuario
void (*drawMap)(Tetris *);

#ifdef __cplusplus
}
#endif

#endif
