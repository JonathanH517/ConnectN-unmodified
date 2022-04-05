#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gameplay.h"

int main(int argc, char** argv) {  // Give a command line arguement, in this case argc = 4
  char** board;
  int num_rows = 0;
  int num_cols = 0;
  int same_char_needed = 0;
  player_put_in(&board, &num_rows, &num_cols, &same_char_needed, argv, argc);  // Each moves
  return 0;
}