#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "color_defines.h"
#include "figures_bag.hpp"

#define TETRIS_MAP_DIV_HEIGHT   12
#define TETRIS_MAP_DIV_WIDTH    20

typedef enum {
    NO_COLLISION,
    COLLISION_X,
    COLLISION_Y,
    END_GAME
} CollisionState;

// Clase Tetris
class Tetris {
  private:
    unsigned int initiated;
    unsigned int map_div_height;
    unsigned int map_div_width;
    unsigned int square_height;
    unsigned int square_width;
    char mapa[TETRIS_MAP_DIV_WIDTH][TETRIS_MAP_DIV_HEIGHT];
    void (*drawMapCallback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned long (*timeCallback)(void);
    Move (*inputMoveCallback)(void);
    FiguresBag bag;
    Figure *figure_active = nullptr;
    unsigned long time_ant_fall = 0;
    unsigned long time_ant_input = 0;
    unsigned long time_act = 0;
    void drawMap(void);
    void setFigureOnMap(void);
    CollisionState collisionDetector(void);
    void resetMap(void); 
    void clearFigureActive(void);
  public:
    Tetris(unsigned int, unsigned int);
    void setDrawTetrisMapCallback(void (*)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int));
    void setRandomNumberCallback(unsigned int (*)(void));
    void setTimeCallback(unsigned long (*)(void));
    void setInputMoveCallback(Move (*)(void));
    void timer_handler(void);
};

#endif
