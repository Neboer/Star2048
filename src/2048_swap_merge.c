#include "2048_swap_merge.h"

// push items to buttom, remove the air inside them.
void push_to_buttom(int **table, int size)
{
    for (int x = 0; x < size; ++x)
    {
        int write_pos = size - 1;
        for (int y = size - 1; y >= 0; --y)
        {
            if (table[y][x] != 0)
            {
                table[write_pos][x] = table[y][x];
                if (write_pos != y)
                {
                    table[y][x] = 0;
                }
                --write_pos;
            }
        }
    }
}

void merge_two_neightbor(int **table, int size)
{
    for (int x = 0; x < size; ++x)
    {
        for (int y = size - 1; y > 0; --y)
        {
            if (table[y][x] == table[y - 1][x] && table[y][x] != 0)
            {
                table[y][x] *= 2;
                table[y - 1][x] = 0;
            }
        }
    }
}

void push_to_buttom_and_merge(int **table, int size)
{
    // first, we need to push all the items to the buttom.
    push_to_buttom(table, size);
    // then, we merge the neightbor items.
    merge_two_neightbor(table, size);
    // finally, we push all the items to the buttom again.
    push_to_buttom(table, size);
}
