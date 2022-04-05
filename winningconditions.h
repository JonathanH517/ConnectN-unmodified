#include <stdio.h>
#include <stdbool.h>
#ifndef WINNINGCONDITIONS_H
  #define WINNINGCONDITIONS_H
  bool all_same_char(char* vector, int same_char_needed, int num_char_in_vector, char player_char);
  bool Win_horizontally(char** board, int same_char_needed, int num_rows, int num_cols, char player_char);
  bool Win_vertically(char** board, int same_char_needed, int num_cols, int num_rows, char player_char);
  bool Win_left_diagonal(char** board, int num_rows, int num_cols, int same_char_needed, char player_char);
  bool Win_right_diagonal(char** board, int num_rows, int num_cols, int same_char_needed, char player_char);
  bool if_tie(char** board, int num_rows, int num_cols);
  bool someone_win(char** board, int num_rows, int num_cols, int same_char_needed, char player_char);

#endif
