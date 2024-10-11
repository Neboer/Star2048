#include "game.h"
#include <stdio.h>

int get_a_vaild_move()
{
    int move;
    while (1)
    {
        printf("Please input your move: Down(1), Left(2), Up(3), Right(4)\n");
        scanf("%d", &move);
        if (move < 1 || move > 4)
        {
            printf("Invalid move! Please input again.\n");
        }
        else
        {
            return move;
        }
    }
}

int main()
{
    Game game;
    game_init(&game, 4);

    while (1)
    {
        game_add_one_random(&game);
        int has_empty = game_add_one_random(&game);
        if (!has_empty)
        {
            print_game(&game);
            printf("Game over!\n");
            break;
        }

        print_game(&game);
        game_move(&game, get_a_vaild_move());
    }
    game_free(&game);
    return 0;
}