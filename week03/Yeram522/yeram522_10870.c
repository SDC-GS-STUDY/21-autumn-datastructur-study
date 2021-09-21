#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int fibo(int _n1, int _n2, int _count)
{
	if (_count == 0 && _n1 + _n2 > 1) return _n1;
	if ((_count == 0 || _count == 1)&& _n1+_n2<=1 ) return _count;
	//printf("fibo(%d,%d,%d)\n", _n2, _n1 + _n2, _count);
	_count -= 1;
	return fibo(_n2 ,_n1 + _n2, _count);
}

int main()
{
	int count;

	scanf("%d", &count);

	printf("%d",fibo(0, 1, count));
}