#include<stdio.h>

//�迭 �ں��� �����ؼ� Ǯ��ߵ�

int main(void) {

    int n;
    int a[101];
    int cnt = 0;

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
        scanf_s("%d", &a[i]);

    //�ں��� �����ؼ� �տ� �ִ� ���� ������ Ŭ ���� 1�� ���ҽ��Ѽ� ��� ����Ű ��
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] >= a[i]) {
            cnt += a[i - 1] - (a[i] - 1);
            a[i - 1] = a[i] - 1;
        }
    }

   

    printf("%d", cnt);

}