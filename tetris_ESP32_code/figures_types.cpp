#include "figures_types.hpp"

Figure::Figure(FigureType _type) {
  type = _type;
  switch(_type) {
    case FIGURE_O:
      figure_map[0][1] = 2;
      figure_map[0][2] = 2;
      figure_map[1][1] = 2;
      figure_map[1][2] = 2;
    break;
    case FIGURE_I:
      figure_map[0][0] = 3;
      figure_map[0][1] = 3;
      figure_map[0][2] = 3;
      figure_map[0][3] = 3;
    break;
    case FIGURE_L:
      figure_map[1][0] = 4;
      figure_map[1][1] = 4;
      figure_map[1][2] = 4;
      figure_map[0][2] = 4;
    break;
    case FIGURE_J:
      figure_map[0][0] = 5;
      figure_map[1][0] = 5;
      figure_map[1][1] = 5;
      figure_map[1][2] = 5;
    break;
    case FIGURE_S:
      figure_map[0][1] = 6;
      figure_map[0][2] = 6;
      figure_map[1][0] = 6;
      figure_map[1][1] = 6;
    break;
    case FIGURE_Z:
      figure_map[0][0] = 7;
      figure_map[0][1] = 7;
      figure_map[1][1] = 7;
      figure_map[1][2] = 7;
    break;
    case FIGURE_T:
      figure_map[0][1] = 8;
      figure_map[1][0] = 8;
      figure_map[1][1] = 8;
      figure_map[1][2] = 8;
    break;
  }
}

void Figure::setPosX(unsigned int _pos_x) {
  pos_x = _pos_x;
}

void Figure::setPosY(unsigned int _pos_y) {
  pos_y = _pos_y;
}

unsigned int Figure::getPosX(void) {
  return pos_x;
}

unsigned int Figure::getPosY(void) {
  return pos_y;
}

FigureType Figure::getFigureType(void) {
  return type;
}

char Figure::getMapLength(void) {
  return map_length;
}

char *Figure::getMap(void) {
  return &figure_map[0][0];
}
