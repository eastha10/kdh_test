#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int end = 0;
char board[5][5];

void play(void)
{
	int x, y;
	printf("원하는 칸의 좌표를 입력하시오: ");
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
		printf("당신이 이미 선택한 구역입니다.\n");
		play();
	}
	else
	{
		printf("상대가 이미 선택한 구역입니다.\n");
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
	printf("5*5 틱택토 게임 인간 vs 컴퓨터\n");
	printf("틱택토 게임을 시작합니다.\n");
	printf("선공은 1번, 후공은 2번, 프로그램을 종료하려면 다른 숫자를 눌러주세요: ");
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
		printf("프로그램을 종료합니다.");
		break;
	}

}