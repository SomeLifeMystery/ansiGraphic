/**
  *  Game Of Life
  *
  *
  */

#include "ansiGraphic2.1.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct s_map {
  int32_t sizeX, sizeY;
  char** board;
  int** neighbours;
  unsigned long death_and_desolation;
} map_t;

int usage() {
  printf("./gol sizeX sizeY sizePopulation fps\n\n");
  return -1;
}

ansigraphic_color_RGB_t color_black = {
  {'0', '0', '0'},
  {'0', '0', '0'},
  {'0', '0', '0'}
};
ansigraphic_color_RGB_t color_randomGreen;
ansigraphic_color_RGB_t color_randomBlue;

void display(map_t* map, ansigraphic_image_RGB_t* image) {
  ansigraphic_ivector2_t xy;
  int r, g, b;
  xy.y = -1;
  while (++xy.y < map->sizeY) {
    xy.x = -1;
    while (++xy.x < map->sizeX) {
      g = 55 + (rand() % 200);	
      b = 205 + (rand() % 50);
      ansigraphic_color_RGB_set(&color_randomGreen, 0, g, 0);
      ansigraphic_color_RGB_set(&color_randomBlue, 0, 0, b);
      switch (map->board[xy.y][xy.x]) {
      case 0:
	ansigraphic_pixelSetColor_RGB(image, &xy, &color_black, &color_randomBlue);
	//ansigraphic_pixelSetValue_RGB(image, &xy, ' ');
	break;
      case 1:
	ansigraphic_pixelSetColor_RGB(image, &xy, &color_randomGreen, &color_randomGreen);
	//ansigraphic_pixelSetValue_RGB(image, &xy, CELL_DOT);
	break;
      default:
	break;
      }
    }
  }
  ansigraphic_imagePrint_RGB(image);
}

#define CORRECT_MAX(var, max) (var < 0 ? max-1 : var >= max ? 0 : var)

int32_t countNeighbours(map_t* map, int32_t x, int32_t y) {
  int32_t count = 0;

  count+=map->board[CORRECT_MAX(y-1, map->sizeY)][CORRECT_MAX(x-1, map->sizeX)];
  count+=map->board[CORRECT_MAX(y, map->sizeY)][CORRECT_MAX(x-1, map->sizeX)];
  count+=map->board[CORRECT_MAX(y+1, map->sizeY)][CORRECT_MAX(x-1, map->sizeX)];
  count+=map->board[CORRECT_MAX(y-1, map->sizeY)][CORRECT_MAX(x, map->sizeX)];
  count+=map->board[CORRECT_MAX(y+1, map->sizeY)][CORRECT_MAX(x, map->sizeX)];
  count+=map->board[CORRECT_MAX(y-1, map->sizeY)][CORRECT_MAX(x+1, map->sizeX)];
  count+=map->board[CORRECT_MAX(y, map->sizeY)][CORRECT_MAX(x+1, map->sizeX)];
  count+=map->board[CORRECT_MAX(y+1, map->sizeY)][CORRECT_MAX(x+1, map->sizeX)];
  return count;
}

void process(map_t* map) {
  int32_t x, y;

  map->death_and_desolation = 0;
  y = -1;
  while (++y < map->sizeY) {
    x = -1;
    while (++x < map->sizeX) {
      map->neighbours[y][x] = countNeighbours(map, x, y);
      map->death_and_desolation += map->neighbours[y][x];
    }
  }
  y = -1;
  while (++y < map->sizeY) {
    x = -1;
    while (++x < map->sizeX) {
      if (map->board[y][x] == 1) {
	if (map->neighbours[y][x] <= 1)
	  map->board[y][x] = 0;
	else if (map->neighbours[y][x] >= 4)
	  map->board[y][x] = 0;
      }
      else {
	if (map->neighbours[y][x] == 3)
	  map->board[y][x] = 1;
      }
    }
  }
}

int main(int ac, char**av) {
  int x, y;

  if (ac != 5)
    return usage();

  // Map initialization
  map_t map;
  map.sizeX = atoi(av[1]);
  map.sizeY = atoi(av[2]);
  map.board = calloc(sizeof(char*), map.sizeY);
  map.neighbours = calloc(sizeof(int*), map.sizeY);
  y = -1;
  while (++y < map.sizeY) {
    map.board[y] = calloc(sizeof(char), map.sizeX);
    map.neighbours[y] = calloc(sizeof(int), map.sizeX);
  }
  // Image init
  ansigraphic_image_RGB_t* image = ansigraphic_newImage_RGB(map.sizeX, map.sizeY);
  
  // Population initialization
  int32_t sizePopulation = atoi(av[3]);
  srand(time(0));
  while (--sizePopulation > 0) {
    x = rand() % map.sizeX;
    y = rand() % map.sizeY;
    map.board[y][x] = 1;
  }

  // Execution
  int32_t delay = 1000 / atoi(av[4]);
  clock_t timer, clocked = 0;
  unsigned long cycles = 0;
  map.death_and_desolation = 1;
  while (map.death_and_desolation > 0) {
    timer = clocked;
    display(&map, image);
    process(&map);
    clocked = clock() / CLOCKS_PER_SEC;
    timer = delay - (clocked - timer);
    if (timer > 0)
      usleep(timer * 1000);
    ++cycles;
  }
  
  // Map freeing
  y = -1;
  while (++y < map.sizeY) {
    free(map.board[y]);
    free(map.neighbours[y]);
  }
  free(map.board);
  free(map.neighbours);

  // Image deletion
  ansigraphic_deleteImage_RGB(image);

  printf("Life cycles to desolation ans despair: %lu\n", cycles);
  return 0;
} 
