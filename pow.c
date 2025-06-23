#include <stdio.h>
#include <math.h>

int main() {
  for (int i = 0; i < 100; i++) {
    double result = pow(9, i);
    printf("9^%d = %.0f\n", i, result);
  }
}
