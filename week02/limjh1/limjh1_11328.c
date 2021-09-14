/*
�� ���� ���ڿ��� ����, 2��° ���ڿ��� 1��° ���ڿ��� strfry �Լ��� �����Ͽ� ����� �� �ִ��� �Ǵ��϶�.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
		
	int caseNum; //ȸ��
	int Index[1000] = { 0, };

	bool isPossible = true;

	scanf_s("%d", &caseNum);

	for (int i = 0; i < caseNum; i++)
	{
		//���� ������ �ʱ�ȭ
		isPossible = true;
		for (int i = 0; i < 1000; i++)
		{
			Index[i] = 0;
		}
		char firstString[1000] = "";
		char secondString[1000] = "";

		scanf_s("%s", &firstString, 1000);
		scanf_s("%s", &secondString, 1000);
		
		//���ڿ� ���� �ٸ��� ���⼭ �Ÿ���
		if (strlen(firstString) != strlen(secondString)) 
		{
			isPossible = false;					
		}
		else 
		{
			// 'a' = 97 �ƽ�Ű �ڵ� int������ ���� �ҹ��ڷ� ���� ���� �� �����ϰ� ��
			// ó�� �迭�ϰ� �ι�° �迭�� ������ ���ĺ� ���ٸ� 0�ϰ���
			for (int i = 0; i < strlen(firstString); i++)
			{
				Index[firstString[i] - 'a']++;
				Index[secondString[i] - 'a']--;
			}				

			for (int i = 0; i < 26; i++)
			{
				if (Index[i] != 0)
				{
					isPossible = false;					
					break;
				}
			}
		}


		if (isPossible == true)
		{
			printf("Possible\n");
		}
		else if (isPossible == false)
		{
			printf("Impossible\n");
		}
	
	}

	return 0;
}