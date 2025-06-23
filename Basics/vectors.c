#include <stdio.h>

typedef struct {
  int x;
  int y;
} vector;

vector addVectors(vector a, vector b) {
  vector sum = {a.x + b.x, a.y + b.y};
  return sum;
}

void displayVector(vector v) {
  fprintf(stdout, "%di + %dj", v.x, v.y);
  fflush(stdout);
}

int main(void) {
  vector a = {12, 4};
  vector b = {1, 9};

  displayVector(addVectors(a, b));
  return 0;
}
