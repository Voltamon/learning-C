#include <stddef.h>
#include <stdio.h>

typedef struct {
  char name[48];
  unsigned long long int phone_number;
} User;

int main() {
  User user = {"Voltamon@48", 8777250831};
  size_t size = sizeof(user);

  printf("Size : %llu bytes\n", size);
  printf("%s : %llu", user.name, user.phone_number);

  return 0;
}
