#include <stdio.h>
#include <time.h>

void timer(int hours, int minutes, int seconds) {
  int total_seconds = hours * 3600 + minutes * 60 + seconds;
  while (total_seconds > 0) {
    printf("\e[1;1H\e[2J");

    printf("Time remaining: %02d:%02d:%02d\n", (total_seconds / 3600),
           (total_seconds % 3600) / 60, (total_seconds % 60));

    clock_t inter = clock() + CLOCKS_PER_SEC;
    while (clock() < inter)
      ;

    total_seconds--;
  }

  printf("\e[1;1H\e[2J");
  printf("Time's up!\n");
}

int main() {
  int hours, minutes, seconds;

  printf("Enter the time in HH::MM::SS format: ");
  scanf("%d::%d::%d", &hours, &minutes, &seconds);

  timer(hours, minutes, seconds);
  return 0;
}
