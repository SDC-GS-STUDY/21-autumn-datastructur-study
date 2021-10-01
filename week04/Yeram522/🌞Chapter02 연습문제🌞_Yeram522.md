## 🌞Chapter02 연습문제🌞_Yeram522

📘 C언어로 쉽게 풀어쓴 자료구조(p.63 - 66)

⭐ => 아리까리, 모르겠는 문제!

.

`[01]` 5개

`[02]` (1) 순환호출 함수내부

`[03]` (3) 지역변수

`[04]` (4) 스택이 허용하는 한도

`[05]` return 0;으로 인해 최종 리턴값이 0*recursive(n)이 되어 0으로 반환된다.

`[06]` 탈출 조건이 없기 때문에, 무한 재귀 함수가 된다.

`[07]` 5 4 3 2 1 0 / 반환 값 = 15

`[08]` 5 4 3 2 1 0/ 반환 값= 2

`[09]` 10 7 4 1/ 반환 값=0

`[10]` 1

`[11]` 8개

`[12]`  evisrucer  (recursive가 역순으로 출력된다.)

`[13]`

```c
int recursive(int _n)
{
	if (_n == 0) return 1;
	return _n + recursive(_n-1);
}
```

`[14]`⭐ 출력이 잘 안나옴..ㅠ왜징.

```c
double recursive(int _n)
{
	if (_n == 1) return (double)1;
	return ((double)1 / (double)_n) + recursive(_n-1);
}
```

`[15]` 

//사진

`[16]`

```c
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		sum += i;

	printf("%d", sum);
}
```



`[17]`

```c
int factorial(int _n)
{
	if (_n == 1) return 1;
	return _n * factorial(_n-1);
}

int binomial_coefficient(int _n,int _k)
{
	if (_k == 0 || _k == _n) return 1;

	return binomial_coefficient(_n - 1, _k - 1) + binomial_coefficient(_n - 1, _k);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	//순환함수 이용
	printf("%d", binomial_coefficient(n, k));

	//반복함수이용.
	//에반데..ㅋ
}
```



`[18]`

(a) A(3,2) = 29, A(2,3) = 9

(b)

```c
int Ackermann(int _m, int _n)
{
	if (_m == 0) return _n + 1;
	if (_n == 0) return Ackermann(_m - 1, 1);

	return Ackermann(_m - 1, Ackermann(_m, _n - 1));
}
```

(c) ㅗ



`[19]`

`[20]`

`[21]`

```C
void fillspace(int _x, int _y, int (*_Arr)[10],int _col)//초기 매개변수는 시작지점
{
	if (_Arr[_x][_y] != 0) return;
	_Arr[_x][_y] = 1;
	fillspace(_x-1, _y, _Arr, _col);
	fillspace(_x+1, _y, _Arr, _col);
	fillspace(_x, _y-1, _Arr, _col);
	fillspace(_x, _y+1, _Arr, _col);
}
int main()
{
	int numArr[10][10] = {
		{2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2},
		{2,2,2,0,0,0,0,2,2,2},
		{2,2,2,2,0,0,0,2,2,2},
		{2,2,2,2,0,0,0,2,2,2},
		{2,2,2,2,0,0,0,0,2,2},//시작지점: 세로5 가로6
		{2,2,2,2,0,2,2,2,2,2},
		{2,2,2,2,0,2,2,2,2,2},
		{2,2,2,2,0,2,2,2,2,2},
		{2,2,2,2,2,2,2,2,2,2}
	};
	int col = sizeof(numArr[0]) / sizeof(int);
	int row = sizeof(numArr) / sizeof(numArr[0]);

	fillspace(5, 6, &numArr, col);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", numArr[i][j]);
		}
		printf("\n");
	}
}
```

