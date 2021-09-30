#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//0ms
int result(int _count)
{
	printf("%d", _count);
	return 0;
}

int main()
{
	int N,num=0;
	int count = 0;

	scanf("%d", &N);//입력

    //for문: 선언 먼저하고 나중에 초기화 할 수 있다.
	for (int i = 1; i < 100; i++)//1~99까지는 무조건, 한수이다.
	{
		num = i;			
		if (num > N) return result(count);
		count++;//한수개수 카운트
	}
			  

	//num이 110이상일 때 카운트.
	for (int a1 = 1; a1 < 10; a1++)//3자리수만 다룬다. a1은 수열의 첫항을 의미한다.
	{
        // i/100을 하면 100의자리 숫자가 나옴.백의자리 숫자에 따라 공차의 범위가 정해진다. 공차 먹고싶다.
		for (int tolerance = -a1 / 2; tolerance <= (9 - a1) / 2; tolerance++)//공차를 하나씩 증가하면서 한수의 조건에 해당하는 수를 만든다.
		{
			num = 100 * a1 + 10 *(a1+tolerance) + a1+tolerance*2;//an = a1 + tolerence(n-1)
			if (num > N) return result(count);
			count++;				
		}		
	}

	if(num>=999) printf("%d", count);
}