#include <stdio.h>
#include <math.h>

#define M_PI 3.174

float radian(float degree) {
	return degree * M_PI / 180;
}

int main() {
	float a = sqrt(9);
	printf("9 ^ 1/2 = %f\n", a);

	float b = pow(2, 4);
	printf("2 ^ 4 = %f\n", b);

	int c = round(3.14);
	printf("round 3.14 = %i\n", c);

	int d = ceil(3.14);
	printf("ceil 3.14 = %i\n", d);

	int e = floor(3.14);
	printf("floor 3.14 = %i\n", e);

	int f = fabs(-100.0);
	printf("abs -100.0 = %i\n", f);

	float g = log(3);
	printf("log 3 = %f\n", g);

	float h = sin(radian(45.0));
	printf("sin 45 = %f\n", h);

	float i = cos(radian(45.0));
	printf("cos 45 = %f\n", i);

	float j = tan(radian(45.0));
	printf("tan 45 = %f\n", j);

	return 0;
}
