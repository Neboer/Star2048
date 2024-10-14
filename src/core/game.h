#ifndef GAME_H
#define GAME_H

#include "direct_table.h"

typedef int GameMove;

#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_UP 3
#define MOVE_RIGHT 4

#define GAME_OVER 1
#define GAME_WIN 2
#define GAME_CONTINUE 3

typedef struct
{
    DirectTable board;
    int score;
} Game;

void game_init(Game* game, int size);

void game_free(Game* game);

void game_move(Game* game, GameMove move);

// return whether the board has empty position.
int game_add_one_random(Game* game);

int game_check(Game* game);

void print_game(Game* game);

#endif // GAME_H