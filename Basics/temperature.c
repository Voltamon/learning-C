#include <stdio.h>
#include <ctype.h>

int main() {
	char unit;
	float temp;

	printf("Enter the temperature : ");
	scanf("%f", &temp);
	
	printf("Enter unit of temperature (C or F): ");
	scanf("%c", &unit);
	
	unit = toupper(unit);

	switch (unit) {
		case 'C':
			printf("Temperature in Fahrenheit : ");
			printf("%.2f F\n", temp * 1.8 + 32);
			break;
			
		case 'F':
			printf("Temperature in Celsius : ");
			printf("%.2f C\n", (temp - 32) * 5 / (float) 9);
			break;

		default:
			printf("Invalid unit of temperature\n");
	}

	return 0;
}
