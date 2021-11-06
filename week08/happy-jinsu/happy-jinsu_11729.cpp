#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void hanoi(int, int, int, int);

int main() {
    int num;
    int k;

    scanf("%d", &num);
    k = pow(2, num) - 1;
    printf("%d\n", k);
    hanoi(num, 1, 3, 2);

    return 0;
}

void hanoi(int n, int start, int finish, int bar)
{
    if (n == 1)
        printf("%d %d\n", start, finish);

    else
    {
        hanoi(n - 1, start, bar, finish);
        printf("%d %d\n", start, finish);
        hanoi(n - 1, bar, finish, start);
    }
}