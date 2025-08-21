#include "figures_bag.hpp"

FiguresBag::FiguresBag() {}

Figure *FiguresBag::getNextFigure(void) {
  if (index >= FIGURE_COUNT) {
    mixBag();
    index = 0;
  }
  return &figures[index++];
}

void FiguresBag::mixBag(void) {
  for (int i = FIGURE_COUNT - 1; i > 0; i--) {
    int j = getRandomNumber() % (i + 1);
    Figure temp = figures[i];
    figures[i] = figures[j];
    figures[j] = temp;
  }
}
