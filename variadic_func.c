#include <stdarg.h>
#include <stdio.h>

int add(int argc, ...) {
  int sum;
  va_list num;

  sum = 0;
  va_start(num, argc);

  for (int i = 0; i < argc; i++)
    sum += va_arg(num, int);

  va_end(num);
  return sum;
}

int main(void) {
  printf("%d\n", add(2, 1, 6));
  printf("%d\n", add(4, 1, 9, 4, 9));

  return 0;
}
