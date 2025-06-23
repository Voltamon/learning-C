#include <stdio.h>
#include <string.h>

typedef struct {
  char name[48];
  int age;
  double percentile;
} aspirant;

int hash(char name[], int age) {
  int hash_code = 0;
  for (int i = 0; i < strlen(name); i++)
    hash_code += name[i];

  return hash_code * age;
}

int main() {
  aspirant Voltamon;

  strcpy(Voltamon.name, "Voltamon");
  Voltamon.age = 17;
  Voltamon.percentile = 97.2;

  return 0;
}
