#include <stdio.h>

int count; //���� ��
int a, b;
int max = 0;
int min = 100000;
int result;

int recursionFunc(int num) {

	if (num > 0) {
		scanf_s("%d %d", &a, &b);

		if (a > max) //���� �� �� �ִ�
			max = a;
		if (b < min) //������ �� �� �ּ�
			min = b;
		return recursionFunc(num - 1);
	}
	else
		return 0;

}

int main(void) {	

	scanf_s("%d", &count);
	recursionFunc(count);

	result = max - min; //���� ���� �ƴѰ��� �׳� �°� ������ ������ 0���� ó��

	if (result < 0)
		result = 0;

	printf("%d", result);

	return 0;
}