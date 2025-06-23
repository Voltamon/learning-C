#include <stdio.h>

int main() {
  static int (*print)(const char*, ...);
  print = &printf;
  print("Hello, World!");
  return 0;
}

