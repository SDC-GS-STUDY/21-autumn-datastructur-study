#include<stdio.h>

int main(void) {

    int n, temp, sum = 0;
    int a[50];
    int b[50];


    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) 
        scanf_s("%d", &a[i]);

    for (int i = 0; i < n; i++)
        scanf_s("%d", &b[i]);

    //오름차순
    //버블정렬이라고 부르는군
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
     //내림차순
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) { 
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    //B는 재정렬 하지 말랬는데 그럼 B의 배열에서 가장 큰값 찾아서 A배열에서 작은거랑 곱하면 되나?
    //근데 큰 값을 그럼 어떤식으로 찾나..?
    //음 큰값을 찾고 곱하고 찾고 곱하고 
    //음.......

    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    printf("%d", sum);

}