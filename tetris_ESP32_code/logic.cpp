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
      if(*(figure_map_ptr + i * map_length + j) != 0 && mapa[offset_y + i][offset_x + j] != 0)
        return COLLISION;
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
    for(int j = 0; j < map_div_high; j++) {
      
      color_index = j >= offset_x && j < offset_x + map_length &&
                    i >= offset_y && i < offset_y + map_length &&
                    *(figure_map_ptr + (i - offset_y) * map_length + (j - offset_x)) != 0 ?
                    *(figure_map_ptr + (i - offset_y) * map_length + (j - offset_x)) :
                    mapa[i][j];
      
      drawMapCallback(square_width * i, square_high * (map_div_high - 1 - j),
                      square_width, square_high,
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

void Tetris::timer_handler(void) {
  
  if(collisionDetector()) {
    figure_active -> setPosY(figure_active -> getPosY() - 1);
    setFigureOnMap();
    figure_active -> resetFigure();
    figure_active = nullptr;
  } else {
    drawMap();
  }
  
  time_act = timeCallback();
  if(time_act - time_ant >= 1000) {
    figure_active -> setPosY(figure_active -> getPosY() + 1);
    time_ant = time_act;
  }
  
}
