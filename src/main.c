#include "recursive.h"

int charToInt (char* thisguy) {
  unsigned int result = 0;
  unsigned int it = 0;

  while (thisguy[it] != 0) {
    if (('0' <= thisguy[it]) && (thisguy[it] <= '9')) {
      result += thisguy[it] - 0x30;
    }
    else {
      fprintf(stderr,"Error: your input was not a positive integer.");
      return -1;
    }


    if (thisguy[it + 1] != 0)
      result *= 10;

    it++;
  }

  return result;
}

int main(int argc, char** argv)
{
  int inputNum = 0;

  switch (argc)
    {
    case 2:
      inputNum = charToInt(argv[1]);
      if (inputNum == -1) {
        return 1;
      }
      recursive(inputNum);
      return 0;
    default:
      fprintf(stderr,"Error: Invalid usage of %s.\n", argv[0]);
      fprintf(stdout,"Usage: %s <number>\nWhere number is a positive integer.\n", argv[0]);
      return 1;
    }
}
