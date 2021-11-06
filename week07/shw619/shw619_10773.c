#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int cnt = 0;
int s[1000000];


void push(int a)
{
	s[cnt] = a;
	cnt++;
}

int pop()
{
	cnt--;
	s[cnt] = 0;
}



int main()
{


    int cnt = 0;
    int sum = 0;
	int input = 0;

	scanf("%d", &cnt);


	for (int i = 0; i < cnt; i++) {

		scanf("%d", &input);

		if (input == 0)
			pop();
		else
			push(input);
	}

    for (int i = 0; i <= cnt; i++)
        sum +=s[i];
    printf("%d\n", sum);
    return 0;

}