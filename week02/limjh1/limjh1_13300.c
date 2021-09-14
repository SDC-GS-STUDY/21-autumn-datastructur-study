/*
한 방에 배정할 수 있는 최대 인원 수 K가 주어졌을 때, 조건에 맞게 모든 학생을 배정하기 위해 필요한 방의 최소 개수를 구하는 프로그램을 작성하시오.
*/

#include <stdio.h>

int student; // 수학여행에 참가하는 학생 수
int maxStudentRoom; //한 방에 배정 가능한 최대 인원수
int grade; //학년 1~6
int gender; //0 여 1 남
int minimumRoom; //최소한의 방 수

int room[100];
	/* 방 번호
		남	여
	1	1	0
	2	3	2
	3	5	4
	4	7	6
	5	9	8
	6	11	10
	*/

void RoomCount(int num) {
	if (gender == 0)//여자라면
		room[num]++;
	else if (gender == 1)//남자라면
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