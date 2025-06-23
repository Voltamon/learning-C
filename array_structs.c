#include <stdio.h>

typedef struct {
	 char name[48];
	 float cgpa;
} Student;

int main() {
	Student Steve = {"Steve Smith", 8.61};
	Student Owen = {"Owen Grady", 9.24};
	Student Simon = {"Simon Riley", 8.85};

	Student students[3] = {Steve, Owen, Simon};
	int size = sizeof(students) / sizeof(students[0]);

	for (int i = 0; i < size; i++) 
	printf("%s : %.2f\n", 
	students[i].name, students[i].cgpa);
		
	return 0;
}
