#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stop = 0;
char board[5][5];
int end = 0;
int cc;
int start;

void play()
{
	int x, y;
	printf("원하는 칸의 좌표를 입력하시오: ");
	scanf("%d %d", &x, &y);
	if (x > 4 || x < 0 || y > 4 || y < 0)
	{
		printf("잘못된 좌표를 설정하였습니다.\n");
		play();
	}
	else if (board[x][y] == 'X' || board[x][y] == 'O')
	{
		printf("이미 선택된 구역입니다.\n");
		play();
	}
	else
	{
		board[x][y] = 'O';
	}
}

void com()
{
	int x, y;
	int nopl = 0;
	if (start == 2)
	{
		cc++;
	}
	if (0 <= cc && cc < 3)
	{
		x = rand() % 3 + 1;
		srand((unsigned)time(NULL));
		y = rand() % 3 + 1;
		srand((unsigned)time(NULL));
		if (board[x][y] == 'X' || board[x][y] == 'O')
		{
			com();
			nopl++;
		}
		else
		{
			board[x][y] = 'X';
			nopl = 0;
		}
		cc++;
	}
	else
	{
		x = rand() % 5;
		srand((unsigned)time(NULL));
		y = rand() % 5;
		srand((unsigned)time(NULL));
		nopl = 0;
		if (board[x][y] == 'X' || board[x][y] == 'O')
		{
			com();
		}
		else
		{
			board[x][y] = 'X';
		}
		cc++;
	}
}

void printBoard(char board[5][5])
{
	for (int i = 0; i < 5; i++) {
		printf("---|---|---|---|---\n");
		printf(" %c | %c | %c | %c | %c  \n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
	}
	printf("---|---|---|---|---\n");
}

void win_1()
{
	int sum = 0;
	int score;
	int wc;
	for (wc = 0; wc < 5; wc++)
	{
		for (score = 0; score < 5; score++)
		{
			sum = sum + board[score][wc];
		}
		if (sum == 79 * 5)
		{
			printf("당신의 승리 입니다.");
			end = 1;
			return;
		}
		else if (sum == 88 * 5)
		{
			printf("컴퓨터의 승리입니다.");
			end = 1;
			return;
		}
	}
}

void win_2()
{
	int sum = 0;
	int score;
	int wc = 0;
	for (wc = 0; wc < 5; wc++)
	{
		for (score = 0; score < 5; score++)
		{
			sum = sum + board[wc][score];
		}
		if (sum == 79 * 5)
		{
			printf("당신의 승리 입니다.");
			end = 1;
			return;
		}
		else if (sum == 88 * 5)
		{
			printf("컴퓨터의 승리입니다.");
			end = 1;
			return;
		}
	}
}

void win_3()
{
	int sum;
	sum = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
	if (sum == 79 * 5)
	{
		printf("당신의 승리 입니다.");
	end = 1;
		return;
	}
	else if (sum == 88 * 5)
	{
		printf("컴퓨터의 승리입니다.");
		end = 1;
		return;
	}
}

void win_4()
{
	int sum;
	sum = board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0];
	if (sum == 79 * 5)
	{
		printf("당신의 승리 입니다.");
		end = 1;
		return;
	}
	else if (sum == 88 * 5)
	{
		printf("컴퓨터의 승리입니다.");
		end = 1;
		return;
	}
}

void win()
{
	win_1();
	win_2();
	win_3();
	win_4();
}

void draw()
{
	stop++;
	if (stop > 24)
	{
		printf("무승부 입니다.\n");
		end = 1;
	}
}

int main(void)
{
	int i, j;
	stop = 0;
	end = 0;
	cc = 0;
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
		while (end != 1)
		{
			play();
			printBoard(board);
			win_1();
			win_2();
			win_3();
			win_4();
			draw();
			com();
			if (end == 1)
				break;
			printBoard(board);
			win_1();
			win_2();
			win_3();
			win_4();
			draw();
			if (end == 1)
				break;
		}
		break;
	}
	case 2:
	{
		while (end != 1)
		{
			com();
			printBoard(board);
			win_1();
			win_2();
			win_3();
			win_4();
			draw();
			if (end == 1)
				break;
			play();
			printBoard(board);
			win_1();
			win_2();
			win_3();
			win_4();
			draw();
			if (end == 1)
				break;
		}
		break;
	}
	default:
		printf("프로그램을 종료합니다.");
		break;
	}
	return 0;
} 