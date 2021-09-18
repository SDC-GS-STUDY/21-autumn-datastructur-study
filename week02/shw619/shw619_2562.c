#include<stdio.h>

int main(void)
{
    int n, max = 0, a = 0;
    for (int i = 0; i < 9; i++) {
        scanf_s("%d", &n);

        if (n > max)
        {
            max = n;
            a = i + 1;
        }

    }
    printf("%d \n%d", max, a);
}

