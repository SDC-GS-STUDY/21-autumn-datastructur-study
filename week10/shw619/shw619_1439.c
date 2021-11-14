#include <stdio.h>

int main(void)
{
	int i, one, zero,num = 0;
	char array[1000000];

	while (1)
	{
		scanf_s("%c", &array[i]);

		if (array[i++] == '\n')
			break;
	}

	while (1)
	{
		if (array[num] == '0') {
			while (array[num + 1] == '0')
				num++;
			zero += 1;
			num++;
		}
		else {
			while (array[num + 1] == '1')
				num++;
			one += 1;
			num++;
		}
		if (array[num] == '\n')
			break;
	}
	
	if (zero < one)
		printf("%d\n", zero);
	else
		printf("%d\n", one);

	return 0;
}