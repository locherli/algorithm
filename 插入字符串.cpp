#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char s1[100], s2[100];
	int f;
	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);
	scanf("%d", &f);

	// ȥ�� s1 �� s2 �Ļ��з�
	s1[strlen(s1) - 1] = '\0';
	s2[strlen(s2) - 1] = '\0';

	// �� s1 ��ָ��λ�� f ������ s2
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	char result[200];

	int length_s1 = strlen(s1);
	int length_s2 = strlen(s2);
	strncpy(result, s1, f);
	strncpy(result + f, s2, length_s2);
	strcpy(result + f + length_s2, s1 + f);
	printf("%s\n", result);

	return 0;
}
