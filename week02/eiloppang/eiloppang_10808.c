#include <stdio.h>
#include <string.h>

int main() {
	int alphabet[26] = { 0, };
	char s[100] = { 0, };
	scanf("%s", s);
	int len;
	len = strlen(s);
	
	for (int i = 0; i < len; i++) {
		alphabet[s[i] - 'a']++; //���ڿ� �ϳ��ϳ� �˻��ؼ� a �ƽ�Ű �ڵ�� ���ؼ� 0, 1, 2.. alphabet �迭�� ����. ������ 1 ������ �׳� ������.. 
								  
	} // ������: ���ڿ� �˻��� �� ���� ���ĺ� ������ ������ �� ����� �� �ƴѰ�??.. �迭 �ʱ�ȭ�ؼ� ������ �ǰ�?

	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	printf("\n");

}

