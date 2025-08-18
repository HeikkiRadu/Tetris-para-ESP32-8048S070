#include "figures_bag.hpp"

FiguresBag::FiguresBag() {}

Figure *FiguresBag::getNextFigure(void) {
  Figure *figure = &figures[index];
  if(index == 6) {
    /* MIXEAR BAG */
    index = 0;
  } else {
    index++;
  }
  return figure;
}
