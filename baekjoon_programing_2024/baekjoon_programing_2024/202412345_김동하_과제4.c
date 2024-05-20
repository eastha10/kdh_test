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
	printf("���ϴ� ĭ�� ��ǥ�� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);
	if (x > 4 || x < 0 || y > 4 || y < 0)
	{
		printf("�߸��� ��ǥ�� �����Ͽ����ϴ�.\n");
		play();
	}
	else if (board[x][y] == 'X' || board[x][y] == 'O')
	{
		printf("�̹� ���õ� �����Դϴ�.\n");
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
	for (x = 0; x < 5; x++) 
	{
		for (y = 0; y < 5; y++) 
		{
			if (board[x][y] == ' ') 
			{
				board[x][y] = 'X';
				if (cwf('X')) 
				{
					return;
				}
				else 
				{
					board[x][y] = ' ';
				}
			}
		}
	}
	for (x = 0; x < 5; x++) 
	{
		for (y = 0; y < 5; y++) 
		{
			if (board[x][y] == ' ') 
			{
				board[x][y] = 'O';
				if (cwf('O')) 
				{
					board[x][y] = 'X';
					return;
				}
				else 
				{
					board[x][y] = ' ';
				}
			}
		}
	}
	while (1) {
		x = rand() % 5;
		y = rand() % 5;
		if (board[x][y] == ' ') 
		{
			board[x][y] = 'X';
			break;
		}
	}
}

int cwf(char player) 
{
	int i, j;
	for (i = 0; i < 5; i++) 
	{
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player && board[i][4] == player)
			return 1;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player && board[4][i] == player)
			return 1;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player)
		return 1;
	if (board[0][4] == player && board[1][3] == player && board[2][2] == player && board[3][1] == player && board[4][0] == player)
		return 1;
	return 0;
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
	for (int wc = 0; wc < 5; wc++) 
	{
		int sumX = 0;
		int sumO = 0;
		for (int score = 0; score < 5; score++) 
		{
			if (board[score][wc] == 'X') sumX++;
			if (board[score][wc] == 'O') sumO++;
		}
		if (sumX == 5) 
		{
			printf("��ǻ���� �¸��Դϴ�.\n");
			end = 1;
			return;
		}
		if (sumO == 5) 
		{
			printf("����� �¸��Դϴ�.\n");
			end = 1;
			return;
		}
	}
}

void win_2() {
	for (int wc = 0; wc < 5; wc++) 
	{
		int sumX = 0;
		int sumO = 0;
		for (int score = 0; score < 5; score++) 
		{
			if (board[wc][score] == 'X') sumX++;
			if (board[wc][score] == 'O') sumO++;
		}
		if (sumX == 5) 
		{
			printf("��ǻ���� �¸��Դϴ�.\n");
			end = 1;
			return;
		}
		if (sumO == 5) 
		{
			printf("����� �¸��Դϴ�.\n");
			end = 1;
			return;
		}
	}
}

void win_3() 
{
	int sumX = 0;
	int sumO = 0;
	for (int i = 0; i < 5; i++) 
	{
		if (board[i][i] == 'X') sumX++;
		if (board[i][i] == 'O') sumO++;
	}
	if (sumX == 5) 
	{
		printf("��ǻ���� �¸��Դϴ�.\n");
		end = 1;
		return;
	}
	if (sumO == 5) 
	{
		printf("����� �¸��Դϴ�.\n");
		end = 1;
		return;
	}
}

void win_4() 
{
	int sumX = 0;
	int sumO = 0;
	for (int i = 0; i < 5; i++) 
	{
		if (board[i][4 - i] == 'X') sumX++;
		if (board[i][4 - i] == 'O') sumO++;
	}
	if (sumX == 5) 
	{
		printf("��ǻ���� �¸��Դϴ�.\n");
		end = 1;
		return;
	}
	if (sumO == 5) 
	{
		printf("����� �¸��Դϴ�.\n");
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
		printf("���º� �Դϴ�.\n");
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
	printf("5*5 ƽ���� ���� �ΰ� vs ��ǻ��\n");
	printf("ƽ���� ������ �����մϴ�.\n");
	printf("������ 1��, �İ��� 2��, ���α׷��� �����Ϸ��� �ٸ� ���ڸ� �����ּ���: ");
	scanf("%d", &start);
	switch (start)
	{
	case 1:
	{
		while (end != 1)
		{
			play();
			printBoard(board);
			win();
			draw();
			if (end == 1)
				break;
			printf("*******************\n");
			com();
			printBoard(board);
			win();
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
			win();
			draw();
			if (end == 1)
				break;
			play();
			printBoard(board);
			win();
			draw();
			if (end == 1)
				break;
			printf("*******************\n");
		}
		break;
	}
	default:
		printf("���α׷��� �����մϴ�.");
		break;
	}
	return 0;
}