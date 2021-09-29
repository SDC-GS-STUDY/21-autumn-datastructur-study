//���� �� 2~10, �ջ��,�� ������ ���� �� 1~N
//0.001�� �ɸ�

#include <stdio.h>
#include <time.h>

int teamCount, destroyTeam, plusTeam, temp = 0;
int destTeamNum, plusTeamNum = 0;
int Number[12] = { 0, }; // 1������ 11������ �� �־����


int goKayac() {

	int kayacNum = 0;

	if(destroyTeam == 0) return kayacNum; //�ջ�� �� ������ == 0
	else {
		if (plusTeam == 0) return destroyTeam; //�� ������ �� ������ �ջ�� �״�� ��� �Ұ���
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

	scanf_s("%d %d %d", &teamCount, &destroyTeam, &plusTeam); //���� �� , �ջ�� ���� ��, �ϳ� �� ������ ���� ��

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