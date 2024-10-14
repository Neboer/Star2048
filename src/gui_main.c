
#include "raylib.h"
#include "core/game.h"
#include <math.h>
#include <stdio.h>
#include "gui/draw_text.h"

void gui_draw_game(Game *game, int start_x, int start_y, int screen_size)
{
    // calculate the size of each cell
    int cell_full_size = (int)roundf((float)screen_size / (float)game->board.size);
    int cell_margin = (int)round((float)cell_full_size / 4.0);
    int cell_size = cell_full_size - cell_margin;

    // draw the board
    for (int y = 0; y < game->board.size; ++y)
    {
        for (int x = 0; x < game->board.size; ++x)
        {
            int cell_x = start_x + x * cell_full_size + cell_margin;
            int cell_y = start_y + y * cell_full_size + cell_margin;
            int cell_value = game->board.table[y][x];
            Color cell_color = RAYWHITE;
            switch (cell_value)
            {
            case 0:
                cell_color = RAYWHITE;
                break;
            case 2:
                cell_color = (Color){238, 228, 218, 255};
                break;
            case 4:
                cell_color = (Color){237, 224, 200, 255};
                break;
            case 8:
                cell_color = (Color){242, 177, 121, 255};
                break;
            case 16:
                cell_color = (Color){245, 149, 99, 255};
                break;
            case 32:
                cell_color = (Color){246, 124, 95, 255};
                break;
            case 64:
                cell_color = (Color){246, 94, 59, 255};
                break;
            case 128:
                cell_color = (Color){237, 207, 114, 255};
                break;
            case 256:
                cell_color = (Color){237, 204, 97, 255};
                break;
            case 512:
                cell_color = (Color){237, 200, 80, 255};
                break;
            case 1024:
                cell_color = (Color){237, 197, 63, 255};
                break;
            case 2048:
                cell_color = (Color){237, 194, 46, 255};
                break;
            default:
                cell_color = (Color){0, 0, 0, 255};
                break;
            }
            DrawRectangle(cell_x, cell_y, cell_size, cell_size, cell_color);
            if (cell_value != 0)
            {
                char *text = TextFormat("%d", cell_value);
                // TextBox text_box = draw_text_on_box(cell_size/2, text);
                // printf("text: %s, font_size: %d, start_x: %d, start_y: %d\n", text, text_box.font_size, text_box.start_x, text_box.start_y);
                DrawText(text, cell_x + 23, cell_y + 23, 47, BLACK);
            }
        }
    }
}

int game_add_random(Game *game)
{
    game_add_one_random(game);
    int has_empty = game_add_one_random(game);
    if (!has_empty)
    {
        print_game(game);
        printf("Game over!\n");
        return GAME_OVER;
    }
    return GAME_CONTINUE;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 530;
    int current_game_result = GAME_CONTINUE;

    InitWindow(screenWidth, screenHeight, "Star2048 Game");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    Game game;
    game_init(&game, 4);
    game_add_random(&game);

    double last_key_pressed_time = 0;
    double key_press_cooldown = 0.4;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        int arrow_key_code[4] = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};
        int move_code[4] = {MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT};
        // Update
        if (current_game_result == GAME_CONTINUE)
        {
            for (int i = 0; i < 4; i++)
            {
                if (IsKeyPressed(arrow_key_code[i]) && GetTime() - last_key_pressed_time > key_press_cooldown)
                {
                    game_move(&game, move_code[i]);
                    current_game_result = game_add_random(&game);
                    last_key_pressed_time = GetTime();
                }
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        gui_draw_game(&game, 160, 20, 505);

        if (current_game_result == GAME_OVER)
        {
            DrawRectangle(160, 480, 505, 40, (Color){255, 255, 255, 200});
            DrawText("Game Over!", 320, 480, 40, RED);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
