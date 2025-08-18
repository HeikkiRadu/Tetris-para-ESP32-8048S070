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

class Figure {
  private:
    FigureType type;
    unsigned int pos_x = 4;
    unsigned int pos_y = 1;
    static const char map_length = 4;
  protected:
    char figure_map[map_length][map_length] = {0, 0, 0, 0,
                                               0, 0, 0, 0,
                                               0, 0, 0, 0,
                                               0, 0, 0, 0};
  public:
    Figure(FigureType);
    void setPosX(unsigned int);
    void setPosY(unsigned int);
    unsigned int getPosX(void);
    unsigned int getPosY(void);
    FigureType getFigureType(void);
    char getMapLength(void);
    char *getMap(void);
};

#endif
