#include "game.h"
#include "2048_swap_merge.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初始化游戏
void game_init(Game *game, int size)
{
    srand(time(NULL));
    direct_table_init(&game->board, size);
    game->score = 0;
}

// 释放游戏
void game_free(Game *game)
{
    direct_table_free(&game->board);
}

// how much times does a game move need to cw-rotate to be the same as another game move.
int move_cw_to_another_move(GameMove from, GameMove to)
{
    return (to - from + 4) % 4;
}

// do a move
void game_move(Game *game, GameMove move)
{
    // rotate the board to make the user is swap down.
    direct_table_rotate_90_cw_times(&game->board, move_cw_to_another_move(move, MOVE_DOWN));

    // do the merge logic.
    push_to_buttom_and_merge(game->board.table, game->board.size);

    // rotate back!
    direct_table_rotate_90_cw_times(&game->board, move_cw_to_another_move(MOVE_DOWN, move));
}

// 打印游戏
void print_game(Game *game)
{
    printf("Score: %d\n", game->score);
    for (int y = 0; y < game->board.size; ++y)
    {
        for (int x = 0; x < game->board.size; ++x)
        {
            if (game->board.table[y][x] == 0)
            {
                printf("%5c ", '-');
            }
            else
            {
                printf("%5d ", game->board.table[y][x]);
            }
        }
        printf("\n");
    }
}

typedef struct
{
    int x;
    int y;
} Vet2;

// add game_random_count of random number to the game board, and find the game result.
// return whether the board has empty position.
int game_add_one_random(Game *game)
{
    // find all the empty position.
    int empty_count = 0;
    Vet2 empty_positions[game->board.size * game->board.size];
    for (int y = 0; y < game->board.size; ++y)
    {
        for (int x = 0; x < game->board.size; ++x)
        {
            if (game->board.table[y][x] == 0)
            {
                empty_positions[empty_count].x = x;
                empty_positions[empty_count].y = y;
                ++empty_count;
            }
        }
    }
    // if there is no empty position, return.
    if (empty_count == 0)
    {
        return 0;
    }
    // add a random number to a random empty position.
    int random_index = rand() % empty_count;
    int random_number = rand() % 10 == 0 ? 4 : 2;
    game->board.table[empty_positions[random_index].y][empty_positions[random_index].x] = random_number;
    return 1;
}