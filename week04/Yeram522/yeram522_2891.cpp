#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

int main()
{
	int N, S, R;
	int* damaged;
	int* spare;

	scanf("%d %d %d", &N, &S, &R);//N: ���� ��, S: ī���� �ջ�� ���� ��, R: ī���� �ϳ� �� ������ ���� ��

	damaged = new int[S];
	spare = new int[R];
	
	for (int i = 0; i < S; i++)	scanf("%d", &damaged[i]);//ī��� �ջ�� ���� ����Ʈ
	for (int i = 0; i < R; i++)	scanf("%d", &spare[i]);//ī���� �ϳ� �� ������ ���� ����Ʈ

	//ī���� ������ ������ �� ������� ���ϴ� ���� �ּڰ���?
	int count = 0;
	int min = 0 ;
	int result = 0;
	while (count < S)
	{
		int temp = 0;
		if (min == R ) result++;//������ ī���� �� ������ ��� �� ��ȣ�� �ջ�� ������ ���� �� �� ����.
		for (int i = min; i < R+1; i++)//�ջ�� ���� �������� �� ��(-1,+1)�� �ϳ� �� ������ ���� �ִ��� �˻��Ѵ�.������ ī�൵ �ջ�Ǿ��� ��� �̴� ���� �� �� ����.
		{
			if (spare[i] == damaged[count])
			{
				min++;
				break; //�ڽ��� ���� ���峪�� ������ ī���� ����� ���� �׳� pass�Ѵ�.
			}
			if (count >= min && spare[i] == damaged[count] - 1)//�ڱ� �� ��ȣ�� ������ ī���� �ִ���.
			{
				min++;
				//printf("[+]�ջ�� �� %d�� %d�� ī���� ����\n", damaged[count], spare[i]);
				break;
			}
			if (count <= S  && spare[i] == damaged[count] + 1)//�ڱ� �� ��ȣ�� ������ ī���� �ִ���.
			{
				min++;
				//printf("[+]�ջ�� �� %d�� %d�� ī���� ����\n", damaged[count], spare[i]);
				break;
			}

			temp++;
			
			if (temp == R)
			{
				result++;
				//printf("[!]�ջ�� �� %d ������ ���� %d\n", damaged[count],temp);
			}
			
		}
		count++;
	}
	printf("%d", result);
	

}