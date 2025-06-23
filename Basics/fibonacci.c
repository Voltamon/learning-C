#include <stdio.h>

unsigned int fibo(int n) {
  unsigned int fibo[n];
  fibo[0] = 0;
  fibo[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  return fibo[n];
}

int main() {
  unsigned short int n;

  printf("Enter n (to display nth fibonacci term) : ");
  scanf("%hu", &n);

  printf("%dth term : %u\n", n, fibo(n));

  return 0;
}
