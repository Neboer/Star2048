#ifndef DIRECT_TABLE_H
#define DIRECT_TABLE_H

typedef struct
{
    int** table;
    int size;
} DirectTable;


void direct_table_init(DirectTable* dt, int size);

void direct_table_free(DirectTable* dt);

// rotate the table's pintle to the target direction.
void direct_table_rotate_90_cw_times(DirectTable* dt, int times);

#endif // DIRECT_TABLE_H