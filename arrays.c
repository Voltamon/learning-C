#include <stdio.h>

int main() {
	double prices[6] = {1.0, 2.0, 5.0, 10.0, 20.0};
	for (int i = 0; i < (int) (sizeof(prices) / sizeof(prices[i])); i++) 
	printf("$%6.2lf\n", prices[i]);
}
