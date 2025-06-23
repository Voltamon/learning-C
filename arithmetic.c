#include <stdio.h>

int main() {
  int x = 5;
  int y = 2;

  printf("%d + %d = %d\n", x, y, x + y);          // Addition
  printf("%d - %d = %d\n", x, y, x - y);          // Subtraction
  printf("%d * %d = %d\n", x, y, x * y);          // Multiplication
  printf("%d / %d = %.1f\n", x, y, x / (float)y); // Division
  printf("%d %% %d = %d\n", x, y, x % y);         // Remainder

  printf("%d++ ", x);
  x++; // Increment
  printf("%d\n", x);

  printf("%d-- ", y);
  y--; // Decrement
  printf("%d\n", y);

  return 0;
}
