#include "recursive.h"

void recursive (unsigned int number)
{
  fprintf(stdout,"Number was %i.\n", number);
  if (number == 1) { // if the number is one, exit.  It has hit an infinite loop
    return;
  }
  else if ((number & 1) == 0) { // if the number is even divide by two
    recursive(number / 2);
  }
  else {
    recursive(3 * number + 1); // if it is odd (and not 1) multiply by 3 and add 1
  }
}
