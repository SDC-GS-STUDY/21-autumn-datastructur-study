/*
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.

아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.

아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.
*/
#include <stdio.h>

int main(void) {

	int arr[9];
	int sum = 0;
	int swap = 0;
	int n = 9;

	int anwarr[7];
	int a = 0, b = 0, c = 0;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
		sum += arr[i];
	}

	//100이 만들어 질때의 순번 저장
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - arr[i] - arr[j] == 100) 
			{
				a = i;
				b = j;			
			}
		}
	}

	//새로운 배열에 필요없는 값 제외하고 할당
	for (int i = 0; i < 9; i++)
	{
		if (i != a && i != b && c < 7) {
			anwarr[c] = arr[i];
			c++;
		}
	}

	//정렬
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (anwarr[i] > anwarr[i + 1]) {
				swap = anwarr[i + 1];
				anwarr[i + 1] = anwarr[i];
				anwarr[i] = swap;
			}
		}
	}

	//출력
	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", anwarr[i]);
	}
	return 0;
}