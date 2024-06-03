#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define ROW 3
#define COL 3
//检查是否决出胜者，决出：返回1，未决出：返回0
//int judge(char board[ROW][COL])
//{
//	for (int i = 0; i < ROW; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == '#')
//			return 1;
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == '#')
//			return 1;
//		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == '#')
//			return 1;
//		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == '#')
//			return 1;
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == '@')
//			return -1;
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == '@')
//			return -1;
//		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == '@')
//			return -1;
//		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == '@')
//			return -1;
//	}
//	return 0;
//
//}
int judge(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0] == '#' && board[i][1] == '#' && board[i][2] == '#')
			return 1;
		if (board[0][i] == '#' && board[1][i] == '#' && board[2][i] == '#')
			return 1;
		if (board[i][0] == '@' && board[i][1] == '@' && board[i][2] == '@')
			return -1;
		if (board[0][i] == '@' && board[1][i] == '@' && board[2][i] == '@')
			return -1;
	}
	if (board[0][0] == '#' && board[1][1] == '#' && board[2][2] == '#')
		return 1;
	if (board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#')
		return 1;
	if (board[0][0] == '@' && board[1][1] == '@' && board[2][2] == '@')
		return -1;
	if (board[0][2] == '@' && board[1][1] == '@' && board[2][0] == '@')
		return -1;

	return 0;
}
void setPlayer(char board[ROW][COL], int x, int y)
{
	board[x][y] = '#';
}
int setRobot(char board[ROW][COL], int x, int y)
{
	if (board[x][y] == ' ')
	{
		board[x][y] = '@';
		return 0;
	}
	else
	{
		return -1;
	}

}
void printBoard(char board[ROW][COL], int x, int y)
{

	int i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++) {
			printf("%c", board[i][j]);
			if (j < COL - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < ROW - 1) {
			printf("-|-|-\n");
		}
	}
}
void initializeBoard(char board[ROW][COL], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void content()
{
	char board[ROW][COL];
	initializeBoard(board, ROW, COL);
	for (int numOfStep = 0; numOfStep < ROW * COL; numOfStep++)
	{
		system("cls");
		printf("输入要下的坐标：");//玩家的回合
		int x, y;
		scanf("%d %d", &x, &y);
		setPlayer(board, x - 1, y - 1);
		printBoard(board, ROW, COL);
		int isValid;//机器人的回合
		do {
			int setOfRobot_x = rand() % 3;
			int setOfRobot_y = rand() % 3;
			isValid = setRobot(board, setOfRobot_x, setOfRobot_y);
		} while (isValid);

		printf("\n");
		printf("Robot:\n");
		Sleep(1000);
		printBoard(board, ROW, COL);
		

		int isOver = judge(board);//判断是否决出胜负
		if (isOver == 1)
		{
			printf("YOU WIN\n");
		}
		else if(isOver == -1)
		{
			printf("YOU LOSE\n");
		}
		system("pause");
		if (isOver == 1)
		{
			break;
		}
		else if (isOver == -1)
		{
			break;
		}

	}
}
void game()
{
	int select = 0;
	do
	{
		printf("******三子棋游戏*******\n");
		printf("**    1：进入游戏    **\n");
		printf("**    0：退出游戏    **\n");
		printf("***********************\n");
		printf("请输入数字进行选择\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:printf("开始游戏\n");
			content(); break;
		case 0:printf("exit"); break;
		default:printf("error");
			break;
		}

	} while (select);
}
int main()
{
	game();
	return 0;
}