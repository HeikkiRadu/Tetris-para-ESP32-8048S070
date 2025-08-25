#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "color_defines.h"
#include "figures_bag.hpp"

#define TETRIS_MAP_DIV_HIGH   12
#define TETRIS_MAP_DIV_WIDTH  20

typedef enum {
    NO_COLLISION,
    COLLISION
} CollisionState;

// Clase Tetris
class Tetris {
  private:
    unsigned int initiated;
    unsigned int map_div_high;
    unsigned int map_div_width;
    unsigned int square_high;
    unsigned int square_width;
    char mapa[TETRIS_MAP_DIV_WIDTH][TETRIS_MAP_DIV_HIGH];
    void (*drawMapCallback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned long (*timeCallback)(void);
    FiguresBag bag;
    Figure *figure_active = nullptr;
    unsigned long time_ant = 0;
    unsigned long time_act = 0;
  public:
    Tetris(unsigned int, unsigned int);
    void setDrawTetrisMapCallback(void (*)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int));
    void setRandomNumberCallback(unsigned int (*)(void));
    void setTimeCallback(unsigned long (*)(void));
    void drawMap(void);
    void setFigureOnMap(void);
    void timer_handler(void);
    CollisionState collisionDetector(void);
};

#endif
