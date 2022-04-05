#ifndef COMMANDLINES_H
  #define COMMANDLINES_H
  void Valid_AgrC(int input_num, int num_needed);
  void Valid_ArgV(int user_int, int input_num);
  void examine_commandlines(int argc, char** argv, int* num_rows, int* num_cols, int* same_char_needed);
#endif
