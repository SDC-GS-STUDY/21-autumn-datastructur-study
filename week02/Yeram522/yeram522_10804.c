#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//역순
void reverse(int _a, int _b, int _arr[])
{
	int length = _b - _a - 1; //탐색할 배열의 길이를 정한다.
	for (int i = 0; i < length+2; i++) //길이+2 만큼 순회
	{
		int last = _arr[_b - 1]; //[a,b]범위에서 가장 우측의 값을 지역변수에 저장해둔다.
		for (int j = _b - 1; _a - 1+i < j; j--) _arr[j] = _arr[j - 1];
		_arr[_a - 1+i] = last;
	}
}

int main()
{
	int arr[20] = { 0, };
	int a, b;//배열의 범위

	for (int i = 0; i < 20; i++) arr[i] += (i+1); //arr[20] 배열 초기화.

	for (int i = 0; i <10; i++)
	{
		scanf("%d %d", &a, &b);
		reverse(a, b, arr);
	}

	for (int i = 0; i < 20; i++) printf("%d ", arr[i]);
	
}