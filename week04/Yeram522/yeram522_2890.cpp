#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>


int main()
{
	//���������� ī���� �׻� 9��
	
	char *map;//���� �迭
	int* ranking;
	int* distance;
	int R, C; //R:�� C:��(10<=R, C<=50)
	scanf("%d %d", &R, &C);

	map = new char[(C+1) * R];
	ranking = new int[C+1];
	distance = new int[C+1];
	memset(ranking, 0,sizeof(ranking)* (C + 1));

	//-----------�����Է�
	int R_count = 0;//��(R)���� �������� R��ŭ while�� ������.
	int C_count = 0;//C���� �Ǹ� �ٽ� 0���� �ʱ�ȭ.
	while (R_count < R)
	{
		C_count++;
		scanf("%c", &map[C_count + R_count *(C +1)-1]);
				
		if (C_count == C + 1)
		{
			map[R_count * (C + 1) + (C + 1)] = '\n';
			R_count++;
			C_count = 0;
			
		}	
	}
	map[(C + 1) * R] = '\0';

	//printf("%s\n", map);

	//-------------����Ž��
	R_count = 0;//����:��(R)���� �������� R��ŭ while�� ������.
	C_count = C+1;//\n�� F����|S.......222F\n| �ε����� �ǹ�.
	while (R_count < R)
	{
		C_count--;//F�ٷ� �պ��� ī��Ʈ ����.

		//1���� index��: C_count + R_count *(C +1)
		int index = C_count + R_count * (C + 1);
		if (map[index - 1] == 'S')
		{
			R_count++;
			C_count = C;
			continue;
		}
		if (!(1 <= map[index - 1] - '0' && map[index - 1] - '0' <= 9)) continue;
		distance[map[index - 1] - '0' - 1] = (C-1) - C_count+1;//ranking[ī���ȣ-1]=��¼����� �Ÿ�
 		//printf("no:%d, distance:%d, index: %d\n", map[index - 1] - '0', distance[map[index - 1] - '0' - 1], map[index - 1] - '0' - 1);
		R_count++;
		C_count = C;
		
	}

	

	//--------------�������
	int min=0;//���� ���� �Ÿ� �ּڰ�
	while (min < C-5)//�ּڰ��� ���� �����Ͽ� distance= ��-2(S,F)�������� �ͺ��� ������ �����Ѵ�.
	{
		for (int i = 0; i < 9; i++)//ī���� ������ 9�� �̹Ƿ� 9������ Ž���Ѵ�.
		{
			if (min != distance[i]) continue;
			for (int i = 0; i < 9; i++)
			{
				if (min <= distance[i]) ranking[i]++;
			}
			break;
		}
		
		min++;
	}

	for (int i = 0; i < 9; i++)
	{
		printf("%d\n", ranking[i]);
	}

	
	
	

	return 0;
}