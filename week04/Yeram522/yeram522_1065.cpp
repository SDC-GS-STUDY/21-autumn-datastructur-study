#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//0ms
int result(int _count)
{
	printf("%d", _count);
	return 0;
}

int main()
{
	int N,num=0;
	int count = 0;

	scanf("%d", &N);//�Է�

    //for��: ���� �����ϰ� ���߿� �ʱ�ȭ �� �� �ִ�.
	for (int i = 1; i < 100; i++)//1~99������ ������, �Ѽ��̴�.
	{
		num = i;			
		if (num > N) return result(count);
		count++;//�Ѽ����� ī��Ʈ
	}
			  

	//num�� 110�̻��� �� ī��Ʈ.
	for (int a1 = 1; a1 < 10; a1++)//3�ڸ����� �ٷ��. a1�� ������ ù���� �ǹ��Ѵ�.
	{
        // i/100�� �ϸ� 100���ڸ� ���ڰ� ����.�����ڸ� ���ڿ� ���� ������ ������ ��������. ���� �԰�ʹ�.
		for (int tolerance = -a1 / 2; tolerance <= (9 - a1) / 2; tolerance++)//������ �ϳ��� �����ϸ鼭 �Ѽ��� ���ǿ� �ش��ϴ� ���� �����.
		{
			num = 100 * a1 + 10 *(a1+tolerance) + a1+tolerance*2;//an = a1 + tolerence(n-1)
			if (num > N) return result(count);
			count++;				
		}		
	}

	if(num>=999) printf("%d", count);
}