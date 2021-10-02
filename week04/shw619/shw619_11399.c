#include <stdio.h> 

int main(void)
{ 
	int N, i, pi, sum; 
	//줄에 서는 사람의 수는 1000이하이다. 
	int p[1001] = {0}; 
	//인출 시간도 1000이하임 문제에서 주어짐
	int time[1000] = {0}; 

	// 사람의 수 입력 받고 
	scanf_s("%d", &N);
	// 처리하는데 걸리는 시간을 pi라고 했을 땡 pi처리하는 시간을 갖는 사람이 있으면 p[pi]도 존재하는거고 그래서 ++
	for(i = 0; i < N; i++)
	{ 
		scanf_s("%d", &pi); 
		p[pi]++;
	} 

	//더할 합과 시간을 일단 0으로 초기화 해주셈 어차피 다시 time에 넣어줄거기 때문임 
	sum = 0; 
	pi = 0; 
	
	//대기 + 처리 시간 구하기 

	for(i = 1; i < 1001; i++)
	{ 
		while(p[i] > 0)
		{ 
			sum += i;
			time[pi] = sum;
			pi++; 
			//시간은 증가고 
			//배열 값은 줄어들고 계속 반복 
			p[i]--; 
		} 
	}

	sum = 0; 

	for(i = 0; i < N; i++)
		sum += time[i]; 

	printf("%d\n", sum);
	return 0; 
}
