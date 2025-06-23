#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int random_number;
	srand(time(0));
	
	random_number = (rand() % 6) + 1;
	printf("%d", random_number);

	return 0;
}
