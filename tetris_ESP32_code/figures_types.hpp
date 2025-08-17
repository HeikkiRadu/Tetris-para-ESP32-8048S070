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
    unsigned int pos_x;
    unsigned int pos_y;
  public:
    Figure(FigureType, unsigned int, unsigned int);
    virtual ~Figure();
    virtual unsigned int getMapLength(void) = 0;
    virtual char *getMap(void) = 0;
    void setPosX(unsigned int);
    void setPosY(unsigned int);
    unsigned int getPosX(void);
    unsigned int getPosY(void);
    FigureType getFigureType(void);
};

class FigureO : public Figure {
  private:
    static const char map_length = 2;
    char figure_map[map_length][map_length] = {2, 2,
                                               2, 2};
  public:
    FigureO(unsigned int, unsigned int);
    ~FigureO();
    unsigned int getMapLength(void) override;
    char *getMap(void) override;
};

#endif
