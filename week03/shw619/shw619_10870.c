#include <stdio.h>

int f(int n) {
    int a, b;

    a = 0;
    b = 1;

    if (n == 0)
        return a;

    else if (n == 1)
        return b;

    else
        return f(n - 1) + f(n - 2);
}

int main() {
    int n;

    scanf_s("%d", &n);
    printf("%d\n", f(n));

    return 0;
}
