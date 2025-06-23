#include <pthread.h>
#include <stdio.h>

int i = 0;

void *thread_function(void *arg) {
  for (; i < 20; i++)
    printf("%d\n", 10 + i);
  return NULL;
}

int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, thread_function, NULL);

  for (; i < 10; i++)
    printf("%d\n", i);

  pthread_join(thread, NULL);
  return 0;
}
