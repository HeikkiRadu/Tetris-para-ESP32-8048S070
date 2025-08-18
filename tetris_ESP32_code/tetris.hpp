#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "color_defines.h"
#include "figures_bag.hpp"

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
  FiguresBag bag;
} Tetris;

// Estructura de la configuración del mapa
extern Tetris tetris;

// Prototipo de la función para registrar las dimensiones del mapa de tetris
void tetrisInit(unsigned int, unsigned int);

// Permite registrar la función de dibujado en pantalla del usuario
void setDrawTetrisMapCallback(void (*)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int));

// Ejecuta la función de dibujado en pantalla del usuario
void drawTetrisMapCallback(void);

// Puntero a función de dibujado en pantalla del usuario
extern void (*drawMap)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

// Permite registrar la función del usuario para la generación de números random
//void setRandomGenCallback(long (*)(void));

#endif
