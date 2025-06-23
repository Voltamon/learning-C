#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int progress = 0;

void *update_progress(void *vargp) {
  srand(time(NULL));

  while (progress < 100) {
    sleep(1);
    progress += rand() % 5;
    if (progress > 100)
      progress = 100;
  }

  sleep(5);
}

int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, update_progress, NULL);

  while (progress <= 100) {
    sleep(1);
    printf("\e[1;1H\e[2J");
    printf("%d% [", progress);

    for (int i = 1; i <= progress / 2; i++)
      printf("#");

    for (int i = progress / 2; i < 50; i++)
      printf(" ");

    printf("]\n");
    fflush(stdout);

    if (progress == 100)
      break;
  }

  pthread_join(thread, NULL);
  return 0;
}
