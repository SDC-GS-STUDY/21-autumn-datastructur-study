#include <stdio.h> 

int main(void) 
{ 
	int n, i;

	int num = 99, a, b; 
	scanf_s("%d", &n);
	
	if (n < 100) // 100���� ������ �� �Ѽ��� 
	{ 
		printf("%d", n); 
		return 0;
	} 
	
	//100�̻��� ��츦 �����غ��� 
	for (i = 100; i <= n; i++)
	{ 
		//���� �ڸ��� ���ϴ� i/100 
		//���� �ڸ� & ���� �ڸ� ���̸� a�� ����
		a = i / 100 - i / 10 % 10; 
		//���� �ڸ� &���� �ڸ� ���̸� b�� ����
		b = i / 10 % 10 - i % 10; 

		// a�� b�� ������ ��, ���̰� ������ �Ѽ��ϱ� num count �ö� 
		if (a == b)
			num++;
	} 
	
	printf("%d\n", num); 
	
	return 0; 

}

