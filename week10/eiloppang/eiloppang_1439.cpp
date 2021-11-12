#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char string[1000];
	scanf("%s", string);

	int countZero = 0;
	int countOne = 0;
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		if (string[i] != string[i + 1]) {
			if (string[i] == '0')
				countZero++;
			else
				countOne++;
		}
	}
	
	if (countZero > countOne)
		printf("%d", countOne);
	else if (countOne > countZero)
		printf("%d", countZero);
	else
		printf("0");
}