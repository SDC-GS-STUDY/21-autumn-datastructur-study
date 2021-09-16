#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//재귀함수
void split_num(int num, int _result, int _results[]); //자리수 분리 알고리즘
void Count_num(int _results[], int _nums[]);
void counting(int _index, int _results[], int _nums[]); //숫자가 몇개 있는지 카운트.

int main()
{
	int A, B, C;
	int result;
	//int results = (int)malloc(sizeof(Student) * total);
	int results[10] = {0, };
	int nums[10] = { 0, };
	int num = 0;

	//한 줄에 한개씩 숫자가 주어진다.
	scanf("%d", &A); //입력
	scanf("%d", &B);
	scanf("%d", &C);

	//A*B*C의 값.
	result = A * B * C;

	split_num(num,result, results);

	Count_num(results, nums);

	for (int i = 0; i < 10; i++) printf("%d\n", nums[i]); //결과
}

void split_num(int num, int _result, int _results[]) //자리수 분리 알고리즘
{
	if (_result < 10 && _result % 10 == 0) //탈출조건
		return;

	_results[num] = _result % 10;
	//printf("_results[%d] : %d", num, _results[num]);
	num++;
	return split_num(num, _result / 10, _results);
}

void Count_num(int _results[], int _nums[])
{
	for (int i = 9; 0 < i; i--)
		if (_results[i] != 0) return counting(i, _results, _nums);
}

void counting(int _index, int _results[], int _nums[])
{
	for (int i = _index; 0 <= i; i--)
		_nums[_results[i]]+= 1;
	
}