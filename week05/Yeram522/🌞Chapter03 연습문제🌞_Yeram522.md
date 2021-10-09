## 🌞Chapter02 연습문제🌞_Yeram522

📘 C언어로 쉽게 풀어쓴 자료구조(p.98 - 99)

⭐ => 아리까리, 모르겠는 문제! 혹은 참고한 문제

.

`[01]`  (4) 800 바이트

`[02]`  (4) 1040번지 -> 1039번지 아닌가욤??

`[03] `  (2) double array2[10] //80

`[04]` 

``` c
int main()
{
	int two[10];

	for (int i = 0; i < 10; i++)
	{
		two[i] = 1;
		for (int j = 0; j < i; j++)
			two[i] *= 2;

		printf("%d\n", two[i]);
	}

	return 0;
}
```

`[05]` 

```c
struct person
{
  char name[10];
  int age;
  float salary;
};
```

`[06]` 

```c
typedef struct Complex
{
  float real;
  float imaginary;
}complex;

complex c1 = {1.0, 5.0};
complex c2 = {2.0, 6.0};
```



`[07]` 

복소수의 합을 계산하는 함수.

```c
Complex complex_add(Complex a, Complex b)
{
    Complex add = {a.real+b.real, a.imaginary+b.imaginary};
    return add;
}
```



`[08]` 

크기가 n인 배열 array에서 임의의 위치 ,loc에 정수 value를 삽입하는 함수 insert를 작성.

정수가 삽입되면 그 뒤에 있는 정수들은 한칸씩 밀림.

현재 배열에 들어있는 원소의 개수는 items개.

```c
void insert(int array[]. int loc, int value)
{
    //loc을 기준으로 for문을 뒤에서 부터 돌린다.
    for(int i = items - 1; loc < i; i--)
        array[i+1] = array[i];//한칸씩 오른쪽으로 옮긴다.
    array[loc] = value; //위치에 삽입한다.
}
```



`[09]`  O(n)

`[10]`  

//loc에 있는 정수를 삭제

```c
void insert(int array[]. int loc)
{
    //loc다음꺼부터 왼쪽으로 한칸씩 이동시킨다.
    for(int i = loc; i < items-1; i++)
        array[i] = array[i+1];//한칸씩 오른쪽으로 옮긴다.
    array[items] = 0; //마지막 원소 초기화.
}
```



`[11]` O(n)

`[12]`  

```c
typedef struct example
{
  int n;
  char s[20];
}example;

int main()
{
    exampe* ex;
    ex = (example*)malloc(SIZE * sizeof(example));
    ex.n = 100;
    strcpy(ex.s,"just testing");
    
    free(ex);
    return 0;
}
```







