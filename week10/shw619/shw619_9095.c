#include <stdio.h>


int main(void)
{

	int T = 0;
	int num;
	int array[12] = { 0, };
	
	scanf_s("%d", &T);
	array[0] = 1;
	array[1] = 2;
	array[2] = 4;

	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &num);

		for (int j = 3; j < num; j++) {
			array[j] = array[j - 1] + array[j - 2] + array[j - 3];
		}

		printf("%d\n", array[num - 1]);

	}

}