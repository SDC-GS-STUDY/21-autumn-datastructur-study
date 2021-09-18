#include <stdio.h>
#include <string.h>

int main() {
	int alphabet[26] = { 0, };
	char s[100] = { 0, };
	scanf("%s", s);
	int len;
	len = strlen(s);
	
	for (int i = 0; i < len; i++) {
		alphabet[s[i] - 'a']++; //문자열 하나하나 검사해서 a 아스키 코드랑 비교해서 0, 1, 2.. alphabet 배열에 저장. 있으면 1 없으면 그냥 지나감.. 
								  
	} // 문제점: 문자열 검사할 때 없는 알파벳 때문에 쓰레기 값 생기는 거 아닌가??.. 배열 초기화해서 괜찮은 건가?

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	printf("\n");

}

