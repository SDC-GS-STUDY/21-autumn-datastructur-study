// �ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷�

#include <stdio.h>

int PrimeNum(int num, int count) {

	if (num < 2) // 0, 1�� �Ҽ��� �ƴ�
		return 0;
	else if (num == 2) // �� �ڽ� ������ 4�� Ʋ��,,tlqk,, 2�� ��� ����Լ����� 2 % 2 = 0�̶� �Ҽ� �ƴѰŷ� ���, ���� ó�� �ؾ���
		return 1;
	else {
		if (num % count == 0) //������ 0�̸� �Ҽ� �ƴ�
			return 0;
		else if (num % count != 0 && count < num-1)
			return PrimeNum(num, count + 1); // count�� num�̶� ������ ������ 0�̴� �� ������ ���Ͽ� +1
		else if (num % count != 0 && count == num-1)
			return 1; //  count == num-1 ���� ������ �� ������ 0�ƴϸ� �� ���� �Ҽ�!
	}
}

int main(void) {

	int m,n = 0; //����
	
	int sum = 0;
	int min = 0;

	scanf_s("%d %d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		if (PrimeNum(i,2)) { //�Ҽ��� true = 1

			sum += i;

			if (min > i || min == 0) // 0�̸� �����̱� ������ �Ҵ�
				min = i;
		}
	}

	if (sum != 0) // ���� 0�̸� �ƹ��͵� �Ҽ��� �ƴ�
		printf("%d\n%d", sum, min);
	else
		printf("-1");

	return 0;
}