#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void com(char board[5][5], char myChar)
{
	int x, y;
	x = rand() % 5;
	y = rand() % 5;
	board[x][y] = myChar;
}
void printBoard(char board[5][5])
{
	for (int i = 0; i < 5; i++) {
		printf("---|---|---|---|---\n");
		printf(" %c | %c | %c | %c | %c  \n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
	}
	printf("---|---|---|---|---\n");
}

void play(char board[5][5])
{
	int x, y;
	printf("원하는 칸의 좌표를 입력하시오: ");
	scanf("%d %d", &x, &y);
	if (board[x][y] < 70)
	{
		board[x][y] = 'O';
	}
	else if (board[x][y] = 79)
	{
		printf("당신이 이미 선택한 구역입니다.\n");
		play(board[5][5]);
	}
	else
	{
		printf("상대가 이미 선택한 구역입니다.\n");
		play(board[5][5]);
	}
}

int main(void)
{
	char board[5][5];
	int x, y, k;
	srand((unsigned)time(NULL));
	// 보드 초기화 
	for (x = 0; x < 5; x++)
		for (y = 0; y < 5; y++)
			board[x][y] = ' ';
	// 사용자로부터 위치를 받아서 보드에 표시한다. 
	for (k = 0; k < 25; k++) {
		play(board);		// 유저의 입력
		printBoard(board);
		printf("*******************\n");
		com(board, 'X');	// 컴퓨터의 입력
		printBoard(board);
	}
	return 0;
}
