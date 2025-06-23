#include <stdio.h>

enum Day {
  Mon,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat,
  Sun
}; // each value is assigned an unsigned int

int main() {
  enum Day day = Thu;

  switch (day) {
  case 0 ... 4:
    printf("Its a weekday!");
    break;
  case 5 ... 6:
    printf("Its a weekend!");
    break;
  default:
    printf("Its not even a day!");
  }

  return 0;
}
