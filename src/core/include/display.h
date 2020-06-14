#ifndef DISPLAY_H
#define DISPLAY_H

#include "state.h"
#include "grid.h"

#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 30

/* Return pointer to game window */
int startScreen();
WINDOW *init_display();
void printState(state_t *curr, WINDOW *game_window);

#endif
