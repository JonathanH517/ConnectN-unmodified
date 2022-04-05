#include <stdio.h>
#include <stdlib.h>
#include "commandlines.h"
void Valid_AgrC(int input_num, int num_needed) {
  if (input_num != num_needed) {
    if (input_num < num_needed) {
        printf("Not enough arguments entered\n");
        printf("Usage: connectn.out num_rows num_columns ");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    if (input_num > num_needed) {
        printf("Too many arguments entered\n");
        printf("Usage: connectn.out num_rows num_columns ");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
}
}

void Valid_ArgV(int user_int, int input_num) {
    //  check if there's characters after the digits
    if(input_num != 1) {
        printf("Value must be integer\n");
        printf("Ending Program\n");
        exit(0);
    }
    if (user_int < 0) {
        printf("Value can't be less than zero\n");
        printf("Ending Program\n");
        exit(0);
    }
}

void examine_commandlines(int argc, char** argv, int* num_rows, int* num_cols, int* same_char_needed) {
  int input;
  char blank;

  Valid_AgrC(argc, 4);   // valid argc from command

  input = sscanf(argv[1], "%d %c", num_rows, &blank);  //  get and check argv

  Valid_ArgV(*num_rows, input);
  input = sscanf(argv[2], "%d%c", num_cols, &blank);
  Valid_ArgV(*num_cols, input);
  input = sscanf(argv[3], "%d%c", same_char_needed, &blank);
  Valid_ArgV(*same_char_needed, input);
}
