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
	printf("���ϴ� ĭ�� ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);
	if (board[x][y] < 70)
	{
		board[x][y] = 'O';
	}
	else if (board[x][y] = 79)
	{
		printf("����� �̹� ������ �����Դϴ�.\n");
		play(board[5][5]);
	}
	else
	{
		printf("��밡 �̹� ������ �����Դϴ�.\n");
		play(board[5][5]);
	}
}

int main(void)
{
	char board[5][5];
	int x, y, k;
	srand((unsigned)time(NULL));
	// ���� �ʱ�ȭ 
	for (x = 0; x < 5; x++)
		for (y = 0; y < 5; y++)
			board[x][y] = ' ';
	// ����ڷκ��� ��ġ�� �޾Ƽ� ���忡 ǥ���Ѵ�. 
	for (k = 0; k < 25; k++) {
		play(board);		// ������ �Է�
		printBoard(board);
		printf("*******************\n");
		com(board, 'X');	// ��ǻ���� �Է�
		printBoard(board);
	}
	return 0;
}
