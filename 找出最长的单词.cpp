#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX_SENTENCE 10
int count_non_space_characters(const char* str) {
	int count = 0;
	const char* space_chars = " "; // 指定的字符集合为单个空格字符
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			count++;
		}
		str++;
	}

	return count;
}
void print_longest_word(const char* str)
{
	char word[100];
	char longest_word[100];
	int length = 0, length_max = 0;
	int j;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			j = 0;
			while (str[i] != ' ' && str[i]!='\n')
			{
				word[j] = str[i];
				i++;
				j++;
			}
			word[j] = '\0';
			length = strlen(word);
			if (length > length_max)
			{
				length_max = length;
				strcpy(longest_word, word);
			}
		}
	}
	printf("%s\n", longest_word);
}
//输出最长的单词
int main() {
	char string[MAX_SENTENCE][SIZE];
	int lenSentence[MAX_SENTENCE];
	int num_sentence = 0;
	const char* space_chars = " ";
	while (1) {
		fgets(&string[num_sentence][SIZE], SIZE, stdin);
		if (strcmp(&string[num_sentence][SIZE], "stop\n") == 0) {
			break;
		}
		lenSentence[num_sentence] = count_non_space_characters(&string[num_sentence][SIZE]) - 1;
		num_sentence++;
	}
	for (int i = 0; i < num_sentence; i++)
	{
		printf("%d ", lenSentence[i]);
		print_longest_word(&string[i][SIZE]);
	}

	return 0;
}