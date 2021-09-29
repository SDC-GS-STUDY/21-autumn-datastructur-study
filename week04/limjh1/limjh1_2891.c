//팀의 수 2~10, 손상된,더 가져온 팀의 수 1~N
//0.001초 걸림

#include <stdio.h>
#include <time.h>

int teamCount, destroyTeam, plusTeam, temp = 0;
int destTeamNum, plusTeamNum = 0;
int Number[12] = { 0, }; // 1번부터 11번까지 방 있어야함


int goKayac() {

	int kayacNum = 0;

	if(destroyTeam == 0) return kayacNum; //손상된 팀 없으면 == 0
	else {
		if (plusTeam == 0) return destroyTeam; //더 가져온 팀 없으면 손상된 그대로 출발 불가능
		else {			
			for (int i = 1; i <= teamCount; i++) {
				if (Number[i] == 1) {
					if (Number[i - 1] == -1) {
						Number[i - 1]++;
						Number[i]--;
					}
					else if (Number[i + 1] == -1) {
						Number[i + 1]++;
						Number[i]--;
					}
				}
			}

			for (int i = 1; i <= teamCount; i++) {
			
				if (Number[i] == -1)
					kayacNum++;
			}
			return kayacNum;
		}
	}
}

int main(void) {

	scanf_s("%d %d %d", &teamCount, &destroyTeam, &plusTeam); //팀의 수 , 손상된 팀의 수, 하나 더 가져온 팀의 수

	for (int i = 0; i < destroyTeam; i++)
	{
		scanf_s("%d", &destTeamNum); 
		Number[destTeamNum]--;
	}

	for (int i = 0; i < plusTeam; i++)
	{
		scanf_s("%d", &plusTeamNum); 
		Number[plusTeamNum]++;
	}

	clock_t start = clock();
	printf("%d\n", goKayac());
	clock_t end = clock();

	printf("%.3f\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}