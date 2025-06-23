#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc < 2) return 0;

  int num[argc - 2];
  int result;

  for (int i = 2; i < argc; i++)
  num[i - 2] = atoi(argv[i]);

  if (strcmpi(argv[1], "add") == 0) for (int i = 0; i < argc - 2; i++) result += num[i];
  else if (strcmpi(argv[1], "subtract") == 0) result = num[0] - num[1];

  else if (strcmpi(argv[1], "multiply") == 0) {
    result = 1;
    for (int i = 0; i < argc - 2; i++)
    result *= num[i];
  }
  else if (strcmpi(argv[1], "divide") == 0) {
    if (num[1] == 0) {
      fprintf(stderr, "Division by zero not possible\n");
      goto exit;
    }
    result = num[0] / num[1];
  }
  else fprintf(stderr, "Invalid operation\n");

  exit:
  printf("%d\n", result);
  return 0;
}
