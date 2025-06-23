#include <stdio.h>
#include <string.h>

int main() {
	int num;
	char num_s[11];
	char rev_num[11];

	printf("Enter a number : ");
	scanf("%d", &num);

	sprintf(num_s, "%d", num);
	strncpy(rev_num, num_s, 11);
	strrev(rev_num);
	
	if (strcmp(rev_num, num_s) == 0) 
	printf("%d is a palindrome number", num);
	else printf("%d is not a palindrome number", num);
}
