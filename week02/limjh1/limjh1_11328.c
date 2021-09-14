/*
두 개의 문자열에 대해, 2번째 문자열이 1번째 문자열에 strfry 함수를 적용하여 얻어질 수 있는지 판단하라.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
		
	int caseNum; //회차
	int Index[1000] = { 0, };

	bool isPossible = true;

	scanf_s("%d", &caseNum);

	for (int i = 0; i < caseNum; i++)
	{
		//원래 값으로 초기화
		isPossible = true;
		for (int i = 0; i < 1000; i++)
		{
			Index[i] = 0;
		}
		char firstString[1000] = "";
		char secondString[1000] = "";

		scanf_s("%s", &firstString, 1000);
		scanf_s("%s", &secondString, 1000);
		
		//문자열 길이 다르면 여기서 거르기
		if (strlen(firstString) != strlen(secondString)) 
		{
			isPossible = false;					
		}
		else 
		{
			// 'a' = 97 아스키 코드 int값으로 영어 소문자로 들어온 값들 비교 가능하게 함
			// 처음 배열하고 두번째 배열에 구성된 알파벳 같다면 0일거임
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