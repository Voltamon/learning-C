#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_SIZE(x) (sizeof(x) * 8)
#define BIT_VALUE(x, n) (((x) >> (n)) & 0x1)

int main(void) {
  uint64_t num = 0x74b5e23cf14c643d; // Random number

  uint64_t size;
  char *binary;

  size = BIT_SIZE(num);
  binary = malloc(size + 1);

  if (!binary) {
    fprintf(stderr, "Memory allocation failed\n");
    fflush(stderr);

    return 1;
  }
  binary[0] = '\0';

  for (int8_t i = size - 1; i >= 0; i--) {
    char bit[2];
    snprintf(bit, sizeof(bit), "%d", BIT_VALUE(num, i));

    strncat(binary, bit, 1);
  }

  int8_t index;
  index = strcspn(binary, "1");

  for (int8_t i = index; i <= size; i++)
    fprintf(stdout, "%c", binary[i]);

  fprintf(stdout, "\n");
  fflush(stdout);

  free(binary);
  return 0;
}
