#include <stdio.h>

int charToInt (char* thisguy) {
  unsigned int result = 0;
  unsigned int it = 0;

  while (thisguy[it] != 0) {
    if (('0' <= thisguy[it]) && (thisguy[it] <= '9')) {
      result += thisguy[it] - 0x30;
    }
    else {
      fprintf(stderr,"Error: your input was not a positive integer.");
    }


    if (thisguy[it + 1] != 0)
      result *= 10;

    it++;
  }

  fprintf(stdout,"Your input was %i.\n",result);
  return result;
}

int main(int argc, char** argv)
{
  switch (argc)
    {
    case 2:
      charToInt(argv[1]);
      break;
    default:
      fprintf(stderr,"Error: Invalid usage of %s.\n", argv[0]);
      fprintf(stdout,"Usage: %s <number>\nWhere number is a positive integer.", argv[0]);
      return 1;
    }
}
