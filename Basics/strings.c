#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "Zen";
  char str2[] = "Code";

  // strlwr(str1); // upper case
  // printf("%s\n", str1);

  // strupr(str1); // lower case
  // printf("%s\n", str1);

  // strcat(str1, str2); // concatenate
  // printf("%s\n", str1);

  // strncat(str1, str2, 1); // concatenate upto n-characters
  // printf("%s\n", str1);

  // strcpy(str1, str2); // copy
  // printf("%s\n", str1);

  // strncpy(str1, str2, 3); // copy upto n-characters
  // printf("%s\n", str1);

  // strset(str1, '#'); // set all characters to '#'
  // printf("%s\n", str1);

  // strnset(str1, '#', 2); // set first n-characters to '#'
  // printf("%s\n", str1);

  strrev(str1); // reverses the string (in place)
  printf("%s\n", str1);

  // printf("Length of string : %llu\n", strlen(str1));
  // printf("Are they equal ? : %d\n", strcmp(str1, str2)); // 1 -> Not Equal |
  // 0 -> Equal printf("Are they equal (upto n-characters)? : %d\n",
  // strncmp(str1, str2, 2)); // 1 -> Not Equal | 0 -> Equal printf("Are they
  // equal (ignoring case) : %d\n", strcmpi(str1, str2)); printf("Are they equal
  // (ignoring case) (upto n-characters): %d\n", strnicmp(str1, str2, 2));

  return 0;
}
