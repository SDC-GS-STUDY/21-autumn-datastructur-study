#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void Print_result(bool _result);
bool Check_Pos(char _put[], char _get[]);

int main()
{
	int test_count; //테스트 할 케이스의 수.
	//입력
	scanf("%d", &test_count);

	char put[1000], get[1000];

	bool* results = (bool*)malloc(sizeof(results) * test_count); //동적할당형식!! 잘 기억하기!!
	
	for (int i = 0; i < test_count; i++)
	{
		scanf("%s %s", &put, &get); //입력을 받는다.

		results[i] = Check_Pos(put, get);
	}

	for (int i = 0; i < test_count; i++) Print_result(results[i]);

	free(results);
}

void Print_result(bool _result)
{
	if (_result) printf("Possible\n");
	else printf("Impossible\n");
}

bool Check_Pos(char _put[], char _get[]) //_put: 입력 넣는 문자/ _get: 얻어질 수 있는지>비교 하는 문자
{
	//알파벳 개수를 저장하는 배열
	int alpha_put[26] = { 0, };
	int alpha_get[26] = { 0, };
	int i = 0;
	
	while (_put[i] != '\0') //둘다 길이 같아서 인덱스 같이 써도 ㄱㅊ
	{
		alpha_put[(int)_put[i] - 97] += 1;
		alpha_get[(int)_get[i] - 97] += 1;
		i++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha_put[i] != alpha_get[i]) return false;
	}

	return true;

}