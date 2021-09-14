/*
�� �濡 ������ �� �ִ� �ִ� �ο� �� K�� �־����� ��, ���ǿ� �°� ��� �л��� �����ϱ� ���� �ʿ��� ���� �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <stdio.h>

int student; // ���п��࿡ �����ϴ� �л� ��
int maxStudentRoom; //�� �濡 ���� ������ �ִ� �ο���
int grade; //�г� 1~6
int gender; //0 �� 1 ��
int minimumRoom; //�ּ����� �� ��

int room[100];
	/* �� ��ȣ
		��	��
	1	1	0
	2	3	2
	3	5	4
	4	7	6
	5	9	8
	6	11	10
	*/

void RoomCount(int num) {
	if (gender == 0)//���ڶ��
		room[num]++;
	else if (gender == 1)//���ڶ��
		room[num+1]++;		
}

void RoomSet() {
	for (int num = 0; num < 12; num++)
	{
		if (room[num] >= maxStudentRoom)
			minimumRoom += (room[num] / maxStudentRoom + room[num] % maxStudentRoom);
		else if (room[num] < maxStudentRoom && room[num] != 0)
			minimumRoom += 1;
	}	
}

int main(void) {

	scanf_s("%d %d", &student, &maxStudentRoom);

	for (int i = 0; i < student; i++)
	{
		scanf_s("%d %d", &gender, &grade);

		switch (grade)
		{
		case 1:
			RoomCount(0);
			break;
		case 2:
			RoomCount(2);
			break;
		case 3:
			RoomCount(4);
			break;
		case 4:
			RoomCount(6);
			break;
		case 5:
			RoomCount(8);
			break;
		case 6:
			RoomCount(10);
			break;
		default:
			break;
		}
	}

	RoomSet();

	printf("%d", minimumRoom);

	return 0;
}