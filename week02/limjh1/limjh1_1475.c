/*
�ټ��̴� �������� ������ ���� �̻�Դ�. �ټ��̴� �ڱ� �� ��ȣ�� ���� �ö�ƽ ���ڷ� ���� ���̷��� �Ѵ�.
�ټ����� ���������� �ö�ƽ ���ڸ� �� ��Ʈ�� �Ǵ�. �� ��Ʈ���� 0������ 9������ ���ڰ� �ϳ��� ����ִ�. 
�ټ����� �� ��ȣ�� �־����� ��, �ʿ��� ��Ʈ�� ������ �ּڰ��� ����Ͻÿ�. (6�� 9�� ����� �̿��� �� �ְ�, 9�� 6�� ����� �̿��� �� �ִ�.)
*/
#include  <stdio.h>

int main() {

    int n;
    int num;
    int arr[10] = { 0, };

    scanf_s("%d", &n);

    while (n != 0) {

        arr[n % 10]++; //���¼��� �� ���� ����� ī��Ʈ

        n /= 10;

    }

    num = (arr[6] + arr[9] + 1) / 2;  //6, 9 +1 ������ ���� ex) 3+1/2 = 2, 4+1/2 = 2

    for (int i = 0; i < 10; i++) {

        if (i == 6 || i == 9) //6,9�� ��찡 �ִ��� ���� ������ �Ҵ��ؼ� �糦
            continue;

        if (arr[i] >= num) //arr���� ���� �ִ� ����ŭ ��Ʈ ������ ��
            num = arr[i];
    }

    if (num == 0) //while���� 0 �����߾ 0 ����ó���ؾ��� ���� n = 0�� �� while���� ���� num���� ó��
        num = 1;

    printf("%d", num);

    return 0;

}