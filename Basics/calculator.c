#include <stdio.h>

int main() {
  char operator;
  double num1, num2;

  printf("Enter a number : ");
  scanf("%lf", &num1);

  printf("Enter another number : ");
  scanf("%lf", &num2);

  while (getchar() != '\n');

  printf("Enter an operator (+, - , *, /) : ");
  scanf("%c", &operator);

  switch (operator) {
    case '+':
      printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Dividing by zero is not possible!");
        break;
      }

      printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
      break;
    default:
      printf("Invalid Operator");

  }

  return 0;
}
