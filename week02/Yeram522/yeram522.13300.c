#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc,free�� ����� �������

typedef struct _student 
{
	int sex;//����=0, ����=1
	int grade; //1<= Y <=6
} Student, *PStudent;

void Ascending_sort(Student* _list, int _total);
void Ascending_sort_grade(Student* _list, int _start, int _length);
int Check_split(Student* _list, int _total);
int Room_counter();

int main()
{
	//Student students[1000];//1<=�л���N<=1000
	int total, max;//total:�ִ� �л� ��. max: �� �濡 ������ �� �ִ� �ִ� �л� ��

	scanf("%d %d", &total, &max);//N,K �� �Է� �ޱ�.

	PStudent p = (PStudent)malloc(sizeof(Student) * total);

	//students ����ü �迭 �����Ҵ�.
	for (int i = 0; i < total; i++)
	{
		scanf("%d %d", &p[i].sex, &p[i].grade);
	}

	//�������� ���� �˰��� �Լ�.{�켱����: ����>�г�}
	Ascending_sort(p, total);
	printf("%d",Room_counter(p,total));

	free(p); //�������� ������ ������ ����!
}

//result print
	/*printf("----------------Ascending_sort----------------\n");
	for (int i = 0; i < total; i++)
	{
		printf("%d %d\n", p[i].sex, p[i].grade);
	}*/


//int RoomCounter() : �迭�� ���鼭, �г� �Ǵ� ������ �ٲ𶧸��� return�ϴ� room������ ���� ������Ų��.
//�ִ��ο��� K�� ���. ���� K�� �Ѿ �ÿ� �߰������� count+1�ؾߵ�.
int Room_counter(Student* _list, int _total)
{
	int R_count = 0;//RoomCount
	int K_count = 0; //K_Count(�� ���� �ִ� ���� �ο�)
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
			K_count = 0;//���� �ٲ� �ο��� 0���� �ʱ�ȭ.
		}
		else  K_count++; //�ο��� ����.

	}
	R_count += 1; //������ + 1

	return R_count;
}

int Check_split(Student* _list, int _total)
{
	for (int i = 0; i < _total-1; i++)
	{
		if (_list[i].sex != _list[i + 1].sex) return i+1;
	}
}

void Ascending_sort(Student* _list, int _total) //�������� ���� �˰���
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

				_list[j].sex = _list[j + 1].sex; //�� ����
				_list[j].grade = _list[j + 1].grade; //�� ����
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

void Ascending_sort_grade(Student* _list, int _start , int _length) //�������� ���� �˰���
{
	//���� �Լ��� ���� ���� ���Ŀ� ����ȴٰ� �����ϰ� �ۼ��� �����̴�.
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

				_list[j].sex = _list[j + 1].sex; //�� ����
				_list[j].grade = _list[j + 1].grade; //�� ����
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