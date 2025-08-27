#ifndef FIGURES_TYPES_HPP
#define FIGURES_TYPES_HPP

typedef enum {
    FIGURE_O,
    FIGURE_I,
    FIGURE_L,
    FIGURE_J,
    FIGURE_S,
    FIGURE_Z,
    FIGURE_T,
    FIGURE_COUNT
} FigureType;

typedef enum {
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_DOWN,
  MOVE_ROTATION,
  MOVE_X,
  MOVE_Y,
  MOVE_IDE
} Move;

class Figure {
  private:
    FigureType type;
    unsigned int pos_x;
    unsigned int pos_y;
    unsigned int pos_x_ant;
    unsigned int pos_y_ant;
    Move mov_prev;
    static const char map_length = 4;
  protected:
    char figure_map[map_length][map_length] = {0, 0, 0, 0,
                                               0, 0, 0, 0,
                                               0, 0, 0, 0,
                                               0, 0, 0, 0};
  public:
    Figure(FigureType);
    void resetFigure(void);
    void setPosX(unsigned int);
    void setPosY(unsigned int);
    unsigned int getPosX(void);
    unsigned int getPosY(void);
    FigureType getFigureType(void);
    char getMapLength(void);
    char *getMap(void);
    Move getMovePrevious(void);
    void restorePreviousStateX(void);
    void restorePreviousStateY(void);
    void rotFigure(void);
};

#endif
