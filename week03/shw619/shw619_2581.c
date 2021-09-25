#include<stdio.h>

int main(void)
{
    int m, n = 0;
    int sum = 0;
    int min, k, i;
    int count = 0;

    scanf_s("%d %d", &m, &n);

    for (i = m; i <= n; i++)
    {
        for (k = 2; k < i; k++)
        {
            if (i % k == 0)
                break;
        }
        if (i == k)
        {
            sum += i;
            count++;

            if (count == 1)
                min = i;
        }
    }

    if (count == 0)
        printf("-1\n");

    else
    {
        printf("%d\n%d\n", sum, min);
    }


}