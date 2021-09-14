#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc,free가 선언된 헤더파일

typedef struct _student 
{
	int sex;//여자=0, 남자=1
	int grade; //1<= Y <=6
} Student, *PStudent;

void Ascending_sort(Student* _list, int _total);
void Ascending_sort_grade(Student* _list, int _start, int _length);
int Check_split(Student* _list, int _total);
int Room_counter();

int main()
{
	//Student students[1000];//1<=학생수N<=1000
	int total, max;//total:최대 학생 수. max: 한 방에 배정할 수 있는 최대 학생 수

	scanf("%d %d", &total, &max);//N,K 값 입력 받기.

	PStudent p = (PStudent)malloc(sizeof(Student) * total);

	//students 구조체 배열 동적할당.
	for (int i = 0; i < total; i++)
	{
		scanf("%d %d", &p[i].sex, &p[i].grade);
	}

	//오름차순 정렬 알고리즘 함수.{우선순위: 성별>학년}
	Ascending_sort(p, total);
	printf("%d",Room_counter(p,total));

	free(p); //동적으로 선언한 포인터 해제!
}

//result print
	/*printf("----------------Ascending_sort----------------\n");
	for (int i = 0; i < total; i++)
	{
		printf("%d %d\n", p[i].sex, p[i].grade);
	}*/


//int RoomCounter() : 배열을 돌면서, 학년 또는 성별이 바뀔때마다 return하는 room개수의 값을 증가시킨다.
//최대인원수 K도 고려. 만일 K가 넘어갈 시에 추가적으로 count+1해야됨.
int Room_counter(Student* _list, int _total)
{
	int R_count = 0;//RoomCount
	int K_count = 0; //K_Count(한 방의 최대 수용 인원)
	for (int i = 0; i < _total - 1; i++)
	{
		if (K_count >= 2)
		{
			R_count += 1;
			K_count = 0;
		}

		if (_list[i].sex != _list[i + 1].sex || _list[i].grade != _list[i + 1].grade)
		{
			R_count += 1;
			K_count = 0;//방이 바뀌어서 인원수 0으로 초기화.
		}
		else  K_count++; //인원수 증가.

	}
	R_count += 1; //마지막 + 1

	return R_count;
}

int Check_split(Student* _list, int _total)
{
	for (int i = 0; i < _total-1; i++)
	{
		if (_list[i].sex != _list[i + 1].sex) return i+1;
	}
}

void Ascending_sort(Student* _list, int _total) //오름차순 정렬 알고리즘
{
	for (int i = _total; 0 < i; i--)
	{
		int _sex, _grade;
		for (int j = 0; j < i - 1; j++)
		{
			if (_list[j].sex > _list[j + 1].sex)
			{
				_sex = _list[j].sex;
				_grade = _list[j].grade;

				_list[j].sex = _list[j + 1].sex; //값 복사
				_list[j].grade = _list[j + 1].grade; //값 복사
				_list[j + 1].sex = _sex;
				_list[j + 1].grade = _grade;
				/*printf("*********************************\n");
				printf("[!]swap!!-------: %d %d\n", _list[j].sex, _list[j].grade);
				printf("[!]swap!!-------: %d %d\n", _list[j + 1].sex, _list[j + 1].grade);
				printf("*********************************\n");*/
			}

		}
		//printf("--changed sorting size--\n");
	}
	int _split = Check_split(_list, _total);
	//printf("girl count! : %d \n", _split);
	Ascending_sort_grade(_list,0, _split);
	Ascending_sort_grade(_list, _split, _total);
}

void Ascending_sort_grade(Student* _list, int _start , int _length) //오름차순 정렬 알고리즘
{
	//위의 함수는 성별 정렬 이후에 진행된다고 가정하고 작성한 로직이다.
	for (int i = _length; _start < i; i--)
	{
		int _sex, _grade;
		for (int j = _start; j < i - 1; j++)
		{
			/*printf("****value check\n");
			printf("[V]swap!!-------: %d %d\n", _list[j].sex, _list[j].grade);
			printf("[V]swap!!-------: %d %d\n", _list[j + 1].sex, _list[j + 1].grade);*/
			if (_list[j].grade > _list[j + 1].grade)
			{
				_sex = _list[j].sex;
				_grade = _list[j].grade;

				_list[j].sex = _list[j + 1].sex; //값 복사
				_list[j].grade = _list[j + 1].grade; //값 복사
				_list[j + 1].sex = _sex;
				_list[j + 1].grade = _grade;
				/*printf("*********************************\n");
				printf("[!]swap!!-------: %d %d\n", _list[j].sex, _list[j].grade);
				printf("[!]swap!!-------: %d %d\n", _list[j + 1].sex, _list[j + 1].grade);
				printf("*********************************\n");*/
			}		
		}
	}
}