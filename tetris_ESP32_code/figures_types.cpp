#include "figures_types.hpp"

Figure::Figure(FigureType _type) {
  type = _type;
  resetFigure();
}

void Figure::resetFigure(void) {
  pos_x = 4;
  pos_y = 1;
  pos_x_ant = 4;
  pos_y_ant = 1;
  switch(type) {
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
  mov_prev = MOVE_X;
  pos_x_ant = pos_x;
  pos_x = _pos_x;
}

void Figure::setPosY(unsigned int _pos_y) {
  mov_prev = MOVE_Y;
  pos_y_ant = pos_y;
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

void Figure::restorePreviousStateX(void) {
  pos_x = pos_x_ant;
}

void Figure::restorePreviousStateY(void) {
  pos_y = pos_y_ant;
}

Move Figure::getMovePrevious(void) {
  return mov_prev;
}

void Figure::rotFigure(void) {
  char temp_map[map_length][map_length];
  for(int i = 0; i < map_length; i++) {
    for(int j = 0; j < map_length; j++) {
      temp_map[j][map_length - 1 - i] = figure_map[i][j];
    }
  }
  for(int i = 0; i < map_length; i++) {
    for(int j = 0; j < map_length; j++) {
      figure_map[i][j] = temp_map[i][j];
    }
  }
}
