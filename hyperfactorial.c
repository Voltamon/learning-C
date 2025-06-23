#include <stdio.h>
#include <math.h>

#define NUMBER 10;

unsigned long long int hyperfactorial(int num) {
    if (num == 1) return 1;
    return hyperfactorial(num - 1) * (unsigned long long int)pow(num, num);
}

int main() {
    int num;
    num = NUMBER;

    fprintf(stdout, "%llu\n", hyperfactorial(num));
    fflush(stdout);

    return 0;
}
