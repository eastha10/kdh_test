#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int end = 0;
char board[5][5];

void play(void)
{
	int x, y;
	printf("���ϴ� ĭ�� ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);
	if (board[x][y] < 70)
	{
		board[x][y] = 'O';
		for (y = 0; y < 5; y++)
		{
			for (x = 0; x < 5; x++)
			{
				printf("%c", board[x][y]);
			}
			printf("\n");
		}
	}
	else if (board[x][y] = 79)
	{
		printf("����� �̹� ������ �����Դϴ�.\n");
		play();
	}
	else
	{
		printf("��밡 �̹� ������ �����Դϴ�.\n");
		play();
	}
}

void com(void)
{

}

void winplay()
{
	int sum = 0;
	int score;
	for (score = 0; score < 5; score++)
	{
		sum = sum + board[score][0];
	}
}

void wincom()
{
	int sum = 0;
	int score;
	for (score = 0; score < 5; score++)
	{
		sum = sum + board[score][0];
	}
}

int main(void)
{
	int start, i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			board[i][j] = ' ';
	}
	printf("5*5 ƽ���� ���� �ΰ� vs ��ǻ��\n");
	printf("ƽ���� ������ �����մϴ�.\n");
	printf("������ 1��, �İ��� 2��, ���α׷��� �����Ϸ��� �ٸ� ���ڸ� �����ּ���: ");
	scanf("%d", &start);
	switch (start)
	{
	case 1:
	{
		while (end = 1)
		{
			play();
			com();
		}
		break;
	}
	case 2:
	{
		while (end = 1)
		{
			play();
			com();
		}
		break;
	}
	default:
		printf("���α׷��� �����մϴ�.");
		break;
	}

}