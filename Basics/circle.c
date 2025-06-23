#include <stdio.h>
#include <math.h>

#define M_PI 3.141592653589793

double area(float radius) {
	return M_PI * pow(radius, 2);
}

double circumference(float radius) {
	return 2 * M_PI * radius;
}

int main() {
	float radius;
	double c_area, c_circumference;

	printf("Enter radius : ");
	scanf("%f", &radius);

	c_area = area(radius);
	c_circumference = circumference(radius);

	printf("Area : %.2f\n", c_area);
	printf("Circumference : %.2f\n", c_circumference);

	return 0;
}
