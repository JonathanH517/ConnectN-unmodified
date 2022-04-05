#include <stdio.h>
#include <stdlib.h>
#include "board.h"
char** create_empty_board(int num_rows, int num_cols) {
  int i;
  int j;

  char** board;
  board = (char**)malloc(num_rows * sizeof(char*));
  for(int i = 0; i < num_rows; i++) {
    board[i] = (char*)malloc(num_cols * sizeof(char));
  }

  for(i = 0; i < num_rows; i++) {
    for(j = 0; j < num_cols; j++) {
      board[i][j] = ' ';
    }
  }
  return board;
}

void print_board(int num_rows, int num_cols, char** board) {
  int i;
  int j;
  for(i = num_rows - 1; i >= 0; i--) {
    printf("%d ", i);
    for(j = 0; j < num_cols; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("%s", "  ");  //  for the last row
  for(i = 0; i < num_cols; i++) {
    printf("%d ", i);
  }
  printf("\n");
}
