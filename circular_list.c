#include <stdio.h>
#include <stdbool.h>

bool is_equal(int* arr1, int* arr2, int size) {
  for (int i = 0; i < size; i++)
  if (arr1[i] != arr2[i]) return false;

  return true;
}

void rotate_list(int* arr, int size) {
  int temp = arr[size - 1];

  for (int i = size - 1; i > 0; i--)
  arr[i] = arr[i - 1];

  arr[0] = temp;
}

int main() {
  int size = 5;

  int arr1[] = {1, 4, 7, 6, 2};
  int arr2[] = {4, 7, 6, 2, 1};

  for (int i = 0; i < size; i++) {
    if (is_equal(arr1, arr2, size)) {
      printf("Arrays are equal\n");
      return 0;
    }

    rotate_list(arr1, size);
  }

  printf("Arrays are not equal\n");
  return 0;
}
