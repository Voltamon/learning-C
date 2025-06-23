#include <stdio.h>
#include <stddef.h>

struct User {
	char name[48];
	long long unsigned int phone_number;
};

int main() {
	struct User user = {"Voltamon@48", 8777250831};
	size_t size = sizeof(user);
	
	printf("Size : %llu bytes\n", size);
	printf("%s : %llu", user.name, user.phone_number);
	
	return 0;
}
