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
void win_1()
{
	int sum = 0;
	int score;
	int wc = 0;
	for (score = 0; score < 5; score++)
	{
		sum = sum + board[score][wc];
	}
	if (sum / 5 == 79)
	{
		printf("����� �¸� �Դϴ�.");
		end = 1;
	}

	else if (sum / 5 == 88)
	{
		printf("��ǻ���� �¸��Դϴ�.");
		end = 1;
	}
	else
	{
		wc++;
		win_1();
	}
}

void win_2()
{
	int sum = 0;
	int score;
	int wc = 0;
	for (score = 0; score < 5; score++)
	{
		sum = sum + board[wc][score];
	}
	if (sum / 5 == 79)
	{
		printf("����� �¸� �Դϴ�.");
		end = 1;
	}

	else if (sum / 5 == 88)
	{
		printf("��ǻ���� �¸��Դϴ�.");
		end = 1;
	}
	else
	{
		wc++;
		win_2();
	}
}

void win_3()
{
	int sum = 0;
	int wc = 0;
	sum = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
	if (sum / 5 == 79)
	{
		printf("����� �¸� �Դϴ�.");
		end = 1;
	}

	else if (sum / 5 == 88)
	{
		printf("��ǻ���� �¸��Դϴ�.");
		end = 1;
	}
	else
	{
		wc++;
		win_3();
	}
}

void win_4()
{
	int sum = 0;
	int wc = 0;
	sum = board[0][4] + board[1][3] + board[2][2] + board[1][3] + board[4][0];
	if (sum / 5 == 79)
	{
		printf("����� �¸� �Դϴ�.");
		end = 1;
	}

	else if (sum / 5 == 88)
	{
		printf("��ǻ���� �¸��Դϴ�.");
		end = 1;
	}
	else
	{
		wc++;
		win_4();
	}
}

com()
{

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
			win_1();
			win_2();
			win_3();
			win_4();
		}
		break;
	}
	case 2:
	{
		while (end = 1)
		{
			com();
			play();
			win_1();
			win_2();
			win_3();
			win_4();
		}
		break;
	}
	default:
		printf("���α׷��� �����մϴ�.");
		break;
	}
	return 0;
}