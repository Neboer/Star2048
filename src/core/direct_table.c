#include "direct_table.h"
#include <stdlib.h>

// rotate 90 cw
void rotate_90_cw(int** table, int size) {
    for (int layer = 0; layer < size / 2; ++layer) {
        int first = layer;
        int last = size - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = table[first][i];
            // left to up
            table[first][i] = table[last - offset][first];
            // down to left
            table[last - offset][first] = table[last][last - offset];
            // right to down
            table[last][last - offset] = table[i][last];
            // up to right
            table[i][last] = top;
        }
    }
}

void direct_table_rotate_90_cw_times(DirectTable* dt, int times) {
    for (int i = 0; i < times; ++i) {
        rotate_90_cw(dt->table, dt->size);
    }
}

void direct_table_init(DirectTable* dt, int size) {
    dt->size = size;
    dt->table = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        dt->table[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; ++j) {
            dt->table[i][j] = 0;
        }
    }
}

void direct_table_free(DirectTable* dt) {
    for (int i = 0; i < dt->size; ++i) {
        free(dt->table[i]);
    }
    free(dt->table);
}