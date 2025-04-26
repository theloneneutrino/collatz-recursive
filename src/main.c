#include <stdio.h>

int charToInt (char* thisguy) {
  fprintf(stdout,"Your input was %s.\n",thisguy);
  return -1;
}

int main(int argc, char** argv)
{
  switch (argc)
    {
    case 2:
      charToInt(argv[0]);
      break;
    default:
      fprintf(stderr,"Error: Invalid usage of %s.\n", argv[0]);
      return 1;
    }
}
