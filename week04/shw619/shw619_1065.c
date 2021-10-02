#include <stdio.h> 

int main(void) 
{ 
	int n, i;

	int num = 99, a, b; 
	scanf_s("%d", &n);
	
	if (n < 100) // 100이하 까지는 다 한수임 
	{ 
		printf("%d", n); 
		return 0;
	} 
	
	//100이상일 경우를 생각해보자 
	for (i = 100; i <= n; i++)
	{ 
		//백의 자리를 뜻하는 i/100 
		//백의 자리 & 십의 자리 차이를 a에 저장
		a = i / 100 - i / 10 % 10; 
		//십의 자리 &일의 자리 차이를 b에 저장
		b = i / 10 % 10 - i % 10; 

		// a랑 b랑 같으면 즉, 차이가 같으면 한수니깐 num count 올라감 
		if (a == b)
			num++;
	} 
	
	printf("%d\n", num); 
	
	return 0; 

}

