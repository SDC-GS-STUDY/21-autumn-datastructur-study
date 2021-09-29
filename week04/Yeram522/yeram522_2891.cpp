#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

int main()
{
	int N, S, R;
	int* damaged;
	int* spare;

	scanf("%d %d %d", &N, &S, &R);//N: 팀의 수, S: 카약이 손상된 팀의 수, R: 카약을 하나 더 가져온 팀의 수

	damaged = new int[S];
	spare = new int[R];
	
	for (int i = 0; i < S; i++)	scanf("%d", &damaged[i]);//카약시 손상된 팀의 리스트
	for (int i = 0; i < R; i++)	scanf("%d", &spare[i]);//카약을 하나 더 가져온 팀의 리스트

	//카약을 적절히 빌렸을 때 출발하지 못하는 팀의 최솟값은?
	int count = 0;
	int min = 0 ;
	int result = 0;
	while (count < S)
	{
		int temp = 0;
		if (min == R ) result++;//여분의 카약이 다 쓰였을 경우 뒷 번호의 손상된 팀들은 참가 할 수 없다.
		for (int i = min; i < R+1; i++)//손상된 팀을 기준으로 앞 뒤(-1,+1)에 하나 더 가져온 팀이 있는지 검사한다.여분의 카약도 손상되었을 경우 이는 빌려 줄 수 없다.
		{
			if (spare[i] == damaged[count])
			{
				min++;
				break; //자신의 것이 고장나서 여분의 카약을 써야할 때는 그냥 pass한다.
			}
			if (count >= min && spare[i] == damaged[count] - 1)//자기 앞 번호가 여분의 카약이 있는지.
			{
				min++;
				//printf("[+]손상된 팀 %d가 %d의 카약을 빌림\n", damaged[count], spare[i]);
				break;
			}
			if (count <= S  && spare[i] == damaged[count] + 1)//자기 뒷 번호가 여분의 카약이 있는지.
			{
				min++;
				//printf("[+]손상된 팀 %d가 %d의 카약을 빌림\n", damaged[count], spare[i]);
				break;
			}

			temp++;
			
			if (temp == R)
			{
				result++;
				//printf("[!]손상된 팀 %d 빌리기 실패 %d\n", damaged[count],temp);
			}
			
		}
		count++;
	}
	printf("%d", result);
	

}