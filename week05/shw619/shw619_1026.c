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

    //��������
    //���������̶�� �θ��±�
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
     //��������
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) { 
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    //B�� ������ ���� �����µ� �׷� B�� �迭���� ���� ū�� ã�Ƽ� A�迭���� �����Ŷ� ���ϸ� �ǳ�?
    //�ٵ� ū ���� �׷� ������� ã��..?
    //�� ū���� ã�� ���ϰ� ã�� ���ϰ� 
    //��.......

    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    printf("%d", sum);

}