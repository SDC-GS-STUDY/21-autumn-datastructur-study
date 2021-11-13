#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	char chars[1000000];

	scanf("%s", &chars);

	int count = 0; int i = 0;
	bool enter = false;
	while (chars[i+1]!='\0')
	{
		if (chars[i] != chars[i + 1])
		{
			if(enter==false) count++;
			enter = (enter) ? false : true;
		}
		i++;
	}

	printf("%d", count);
}