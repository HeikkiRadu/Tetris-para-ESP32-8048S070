#ifndef FIGURES_BAG_HPP
#define FIGURES_BAG_HPP

#include "figures_types.hpp"

class FiguresBag {
  private:
    char index = 0;
    Figure figures[FIGURE_COUNT] = {Figure(FIGURE_O),
                                    Figure(FIGURE_I),
                                    Figure(FIGURE_L),
                                    Figure(FIGURE_J),
                                    Figure(FIGURE_S),
                                    Figure(FIGURE_Z),
                                    Figure(FIGURE_T)};
  public:
    unsigned int (*getRandomNumber)(void);
    FiguresBag(void);
    Figure *getNextFigure(void);
    void mixBag(void);
};

#endif
