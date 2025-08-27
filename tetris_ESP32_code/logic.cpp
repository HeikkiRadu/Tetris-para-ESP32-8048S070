#include "tetris.hpp"

CollisionState Tetris::collisionDetector(void) {
  
  if(figure_active == nullptr) {
    figure_active = bag.getNextFigure();
  }

  char *figure_map_ptr = figure_active -> getMap();
  
  unsigned int offset_x = figure_active -> getPosX();
  unsigned int offset_y = figure_active -> getPosY();
  char map_length = figure_active -> getMapLength();
  
  CollisionState state = NO_COLLISION;
  
  for(int i = 0; i < map_length; i++) {
    for(int j = 0; j < map_length; j++) {
      if(*(figure_map_ptr + i * map_length + j) != 0 && mapa[offset_y + i][offset_x + j] != 0) {
        if(offset_x == 4 && offset_y == 1) {
          return END_GAME;
        } else {
          switch(figure_active -> getMovePrevious()) {
            case MOVE_X:
              return COLLISION_X;
            break;
            case MOVE_Y:
              return COLLISION_Y;
            break;
          }
        }
      }
    }
  }
  
  return state;
  
}

void Tetris::drawMap(void) {
  
  if(figure_active == nullptr) {
    figure_active = bag.getNextFigure();
  }

  char *figure_map_ptr = figure_active -> getMap();
  
  unsigned int offset_x = figure_active -> getPosX();
  unsigned int offset_y = figure_active -> getPosY();
  char map_length = figure_active -> getMapLength();
  
  char color_index;
  for(int i = 0; i < map_div_width; i++) {
    for(int j = 0; j < map_div_height; j++) {
      
      color_index = j >= offset_x && j < offset_x + map_length &&
                    i >= offset_y && i < offset_y + map_length &&
                    *(figure_map_ptr + (i - offset_y) * map_length + (j - offset_x)) != 0 ?
                    *(figure_map_ptr + (i - offset_y) * map_length + (j - offset_x)) :
                    mapa[i][j];
      
      drawMapCallback(square_width * i, square_height * (map_div_height - 1 - j),
                      square_width, square_height,
                      Colores[color_index]);
      
    }
  }
  
}

void Tetris::setFigureOnMap(void) {
  
  if(figure_active == nullptr) {
    figure_active = bag.getNextFigure();
  }
  
  char *figure_map_ptr = figure_active -> getMap();
  
  unsigned int offset_x = figure_active -> getPosX();
  unsigned int offset_y = figure_active -> getPosY();
  
  char map_length = figure_active -> getMapLength();
  
  for(int i = 0; i < map_length; i++) {
    for(int j = 0; j < map_length; j++) {
      if(*(figure_map_ptr + i * map_length + j) != 0) {
        mapa[offset_y + i][offset_x + j] = *(figure_map_ptr + i * map_length + j);
      }
    }
  }
  
}

void Tetris::clearFigureActive(void) {
  figure_active -> restorePreviousStateY();
  setFigureOnMap();
  figure_active -> resetFigure();
  figure_active = nullptr;
}

void Tetris::timer_handler(void) {
  
  Move input = inputMoveCallback();
  
  time_act = timeCallback();
  
  if(time_act - time_ant_fall >= 1000) {
    figure_active -> setPosY(figure_active -> getPosY() + 1);
    input = MOVE_IDE;
    time_ant_fall = time_act;
  }
  
  //if(time_act - time_ant_input >= 50) {
    switch(input) {
      case MOVE_LEFT:
        figure_active -> setPosX(figure_active -> getPosX() - 1);
      break;
      case MOVE_RIGHT:
        figure_active -> setPosX(figure_active -> getPosX() + 1);
      break;
      case MOVE_DOWN:
        figure_active -> setPosY(figure_active -> getPosY() + 1);
      break;
      case MOVE_ROTATION:
        figure_active -> rotFigure();
      break;
    }
    //time_ant_input = time_act;
  //}
  
  switch(collisionDetector()) {
    case NO_COLLISION:
      drawMap();
    break;
    case COLLISION_X:
      figure_active -> restorePreviousStateX();
    break;
    case COLLISION_Y:
      clearFigureActive();
    break;
    case END_GAME:
      clearFigureActive();
      resetMap();
    break;
  }
  
}
