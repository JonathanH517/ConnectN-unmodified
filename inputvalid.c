#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "inputvalid.h"



bool isValidMove(int numInput, char** board, int val, int row, int col) {
    return isValidFormat(numInput, 1) && isInRange(val, 0, col-1);
}

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = (numArgsRead == numArgsNeed);
    char character;
    do{
        scanf("%c", &character); //45  bob  \n
        if(!isspace(character)) {
            formatIsGood = false;
        }
    }while(character != '\n');
    return formatIsGood;
}


bool isInRange(int val, int lowerBound, int upperBound) {
    return val >= lowerBound && val <= upperBound;
}
