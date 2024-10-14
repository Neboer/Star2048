#ifndef _2048_MOVE_H_
#define _2048_MOVE_H_

/* How does we complete a game move? 
First, we spin the game board to make sure the user is swap down.
Then, we do the merge logic. Finally, we spin back! */

// this function will only work for down move.
void push_to_buttom_and_merge(int **table, int size);

#endif // _2048_MOVE_H_