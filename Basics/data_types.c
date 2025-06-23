#include <stdbool.h>
#include <stdio.h>

int main() {
  char a = 'C'; // 8-bits
  char b[] = "Bro Code";

  printf("%c %s\n", a, b);
  printf("%zu %zu bytes\n", sizeof(a), sizeof(b));

  float c = 95.8151971;              // 32-bits
  double d = 3.14159265358979323846; // 64-bits

  printf("%f %.15lf\n", c, d);
  printf("%zu %zu bytes\n", sizeof(c), sizeof(d));

  bool e = true; // 8-bits

  printf("%d\n", e);
  printf("%zu bytes\n", sizeof(e));

  char f = 120;          // 8-bits
  unsigned char g = 255; // 8-bits

  printf("%c %u\n", f, g);
  printf("%zu %zu bytes\n", sizeof(f), sizeof(g));

  int h = 23563622;           // 32-bits
  unsigned int i = 426233693; // 32-bits

  printf("%d %u\n", h, i);
  printf("%zu %zu bytes\n", sizeof(h), sizeof(i));

  short int j = 32450;          // 16-bits
  unsigned short int k = 65023; // 16-bits

  printf("%i %hu\n", j, k);
  printf("%zu %zu bytes\n", sizeof(j), sizeof(k));

  long long int l = 1545224352553432422;           // 64-bits
  unsigned long long int m = 1845246523562626551U; // 64-bits

  printf("%lld %llu\n", l, m);
  printf("%zu %zu bytes\n", sizeof(l), sizeof(m));

  return 0;
}
