#include <stdio.h>
#include <stdlib.h>
#include "commandlines.h"
#include "winningconditions.h"
#include "board.h"
#include "inputvalid.h"
#include "gameplay.h"

void player_put_in(char*** board, int* num_rows, int* num_cols, int* same_char_needed, char** argv, int argc) {
  int user_col;
  int i;
  char player_char = 'O';  // initialize to O
  int numInput;

  examine_commandlines(argc, argv, num_rows, num_cols, same_char_needed);
  *board = create_empty_board(*num_rows, *num_cols);
  print_board(*num_rows, *num_cols, *board);

  while(1) {
    if(someone_win(*board, *num_rows, *num_cols, *same_char_needed, player_char) == true) {
      if (player_char == 'X') {
        printf("Player 1 Won!");
        exit(0);
      } else {
        printf("Player 2 Won!");
        exit(0);
      }
    }
    else if(if_tie(*board, *num_rows, *num_cols) == true) {
      printf("Tie game!");
      exit(0);
    } else {  // check validation before entering the game
      do {
        printf("Enter a column between 0 and %d to play in: ", *num_cols - 1);
        numInput = scanf("%d", &user_col);
      } while (isValidMove(numInput, *board, user_col, *num_rows, *num_cols) == false);
        if(player_char == 'X') {
          player_char = 'O';
        } else {
          player_char = 'X';
        }
      for(i=0; i<*num_rows; i++) {  // switch between X and O
        if((*board)[i][user_col] == ' ') {
          (*board)[i][user_col] = player_char;
          print_board(*num_rows, *num_cols, *board);
          break;
          }
    }
   }
  }
}
