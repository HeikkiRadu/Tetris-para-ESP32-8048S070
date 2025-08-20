#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "color_defines.h"
#include "figures_bag.hpp"

#define TETRIS_MAP_DIV_HIGH   12
#define TETRIS_MAP_DIV_WIDTH  20

// Clase Tetris
class Tetris {
  private:
    unsigned int initiated;
    unsigned int map_div_high;
    unsigned int map_div_width;
    unsigned int square_high;
    unsigned int square_width;
    char mapa[TETRIS_MAP_DIV_WIDTH][TETRIS_MAP_DIV_HIGH];
    void (*drawMap)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
  public:
    FiguresBag bag;
    Tetris(unsigned int, unsigned int);
    void setDrawTetrisMapCallback(void (*)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int));
    void drawTetrisMapCallback(void);
};

#endif
