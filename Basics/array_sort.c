#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) 
        swap(&array[j], &array[j + 1]);
    }
  }
}

int main() {
  int arr[10] = {1, 4, 6, 2, 9, 7, 3, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  sort(arr, size);

  for (int i = 0; i < size; i++) 
    printf("%d ", arr[i]);

  return 0;
}
