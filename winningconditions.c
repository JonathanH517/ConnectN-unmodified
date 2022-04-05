#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "winningconditions.h"
// [0, 1, 2, 3]--> 4 chars, need 2 == 4-2
bool all_same_char(char* vector, int same_char_needed, int num_char_in_vector, char player_char) {
  int same_char_total = 0;
  int i;
  int j;
  for(i = 0; i <= num_char_in_vector - same_char_needed; i++) {
    for(j = 0; j < same_char_needed; j++) {  // 2 times
      if(player_char != vector[i+j]) {
        same_char_total = 0;
        break;
      } else {
        same_char_total += 1;
      }
      if(same_char_total >= same_char_needed) {
        return true;
        break;

    }
  }

}
  return false;
}

bool Win_horizontally(char** board, int same_char_needed, int num_rows, int num_cols, char player_char) {
  int i;
  bool finalreturn = false;
  for(i = 0; i < num_rows; i++) {
    if(all_same_char(board[i], same_char_needed, num_cols, player_char) == true) {  // The components of row vectors are columns
      finalreturn = true;
      break;
    } else {
      finalreturn = false;
    }
  }
  return finalreturn;
}

bool Win_vertically(char** board, int same_char_needed, int num_rows, int num_cols, char player_char) {
  int i;
  int j;
  bool finalreturn = false;
  char* cols = NULL;
  for(i = 0; i < num_cols; i++) {
    cols = (char*)malloc(num_rows * sizeof(char));
    for(j = 0; j < num_rows; j++) {
      cols[j] = board[j][i];  // initialize chars to the column(1 by 1)
    }
    if(all_same_char(cols, same_char_needed, num_rows, player_char) == true) {  // if true
      finalreturn = true;
      free(cols);  // reset the cols
      break;
    } else {
      finalreturn = false;
    }
  }
  return finalreturn;
}

bool Win_right_diagonal(char** board, int same_char_needed, int num_rows, int num_cols, char player_char) {
    int same_char_total = 0;
    int i;
    int j;
    int k;

    for(i = 0; i <= num_rows - same_char_needed; i++) {
        for(j = 0; j <= (num_cols - same_char_needed); j++) {
            for(k = 0; k < same_char_needed; k++) {
                if(player_char != board[i+k][j+k]) {
                    same_char_total = 0;
                    break;
                }
                ++same_char_total;
                if(same_char_total >= same_char_needed) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Win_left_diagonal(char** board, int same_char_needed, int num_rows, int num_cols, char player_char) {
    int same_char_total = 0;
    int i;
    int j;
    int k;

    for(i = 0; i <= num_rows - same_char_needed; i++) {
        for(j = num_cols - 1; j >= (num_cols - 1 - same_char_needed); j--) {
            for(k = 0; k < same_char_needed; k++) {
                if(player_char != board[i+k][j-k]) {
                    same_char_total = 0;
                    break;
                }
                ++same_char_total;

                if(same_char_total >= same_char_needed) {
                    return true;

                }
            }
        }
    }
    return false;
}

bool if_tie(char** board, int num_rows, int num_cols) {
  int i;
  int j;

  for(i = 0; i < num_rows; i++) {
    for(j = 0; j < num_cols; j++) {
      if(board[i][j] == ' ') {
        return false;

      }
    }
  }

  return true;
}

bool someone_win(char** board, int num_rows, int num_cols, int same_char_needed, char player_char) {
  bool final_return = false;

  if(Win_horizontally(board, same_char_needed, num_rows, num_cols, player_char) == true
   || Win_vertically(board, same_char_needed, num_rows, num_cols, player_char) == true
   || Win_left_diagonal(board, same_char_needed, num_rows, num_cols, player_char) == true
   || Win_right_diagonal(board, same_char_needed, num_rows, num_cols, player_char) == true) {
     final_return = true;
   }
   return final_return;
}
