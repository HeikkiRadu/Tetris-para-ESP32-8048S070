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
//#define TETRIS_SQUARE_HIGH    DISPLAY_HIGH / TETRIS_MAP_DIV_HIGH
//#define TETRIS_SQUARE_WIDTH   DISPLAY_WIDTH / TETRIS_MAP_DIV_WIDTH

// Estructura del mapa
typedef struct MapaConfig {
  unsigned int initiated;
  unsigned int tetris_map_div_high;
  unsigned int tetris_map_div_width;
  unsigned int tetris_square_high;
  unsigned int tetris_square_width;
} MapaConfig;

MapaConfig mapa_conf;

// Prototipo de la función para registrar las dimensiones del mapa de tetris
void tetris_config(unsigned int, unsigned int);

void setDrawTetrisMapCallback(void (*)(MapaConfig *));
void drawTetrisMapCallback(void);
void (*drawMap)(MapaConfig *);

// Declaración del mapa
char mapa[TETRIS_MAP_DIV_WIDTH][TETRIS_MAP_DIV_HIGH];

#ifdef __cplusplus
}
#endif

#endif
