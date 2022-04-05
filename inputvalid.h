#ifndef INPUTVALID_H
  #define INPUTVALID_H
  #include <stdbool.h>

  bool isValidFormat(const int numArgsRead, const int numArgsNeed);
  bool isInRange(int val, int lowerBound, int upperBound);
  bool isValidMove(int numInput, char** board, int val, int row, int col);

#endif
