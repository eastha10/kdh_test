#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stop = 0;
char board[5][5];
int end = 0;

void play()
{
    int x, y;
    printf("���ϴ� ĭ�� ��ǥ�� �Է��Ͻÿ�: ");
    scanf("%d %d", &x, &y);
    if (board[x][y] == 'X' || board[x][y] == 'O')
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
    do {
        x = rand() % 5;
        y = rand() % 5;
    } while (board[x][y] == 'X' || board[x][y] == 'O');
    board[x][y] = 'X';
}

void printBoard(char board[5][5])
{
    for (int i = 0; i < 5; i++) {
        printf("---|---|---|---|---\n");
        printf(" %c | %c | %c | %c | %c  \n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
    }
    printf("---|---|---|---|---\n");
}

void win()
{
    int score, wc;
    char sum;

    // ��� �� Ȯ��
    for (wc = 0; wc < 5; wc++)
    {
        sum = 0;
        for (score = 0; score < 5; score++)
            sum += board[wc][score];
        if (sum == 'O' * 5)
        {
            printf("����� �¸� �Դϴ�.\n");
            end = 1;
            return;
        }
        else if (sum == 'X' * 5)
        {
            printf("��ǻ���� �¸��Դϴ�.\n");
            end = 1;
            return;
        }

        sum = 0;
        for (score = 0; score < 5; score++)
            sum += board[score][wc];
        if (sum == 'O' * 5)
        {
            printf("����� �¸� �Դϴ�.\n");
            end = 1;
            return;
        }
        else if (sum == 'X' * 5)
        {
            printf("��ǻ���� �¸��Դϴ�.\n");
            end = 1;
            return;
        }
    }

    // �밢�� Ȯ��
    sum = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
    if (sum == 'O' * 5)
    {
        printf("����� �¸� �Դϴ�.\n");
        end = 1;
        return;
    }
    else if (sum == 'X' * 5)
    {
        printf("��ǻ���� �¸��Դϴ�.\n");
        end = 1;
        return;
    }

    sum = board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0];
    if (sum == 'O' * 5)
    {
        printf("����� �¸� �Դϴ�.\n");
        end = 1;
        return;
    }
    else if (sum == 'X' * 5)
    {
        printf("��ǻ���� �¸��Դϴ�.\n");
        end = 1;
        return;
    }
}

void draw()
{
    stop++;
    if (stop == 25)
    {
        printf("���º� �Դϴ�.\n");
        end = 1;
    }
}

int main(void)
{
    int start, i, j;
    srand((unsigned)time(NULL));
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
        while (end == 0)
        {
            play();
            printBoard(board);
            win();
            if (end == 1) break;
            draw();
            if (end == 1) break;
            com();
            printBoard(board);
            win();
            if (end == 1) break;
            draw();
        }
        break;
    }
    case 2:
    {
        while (end == 0)
        {
            com();
            printBoard(board);
            win();
            if (end == 1) break;
            draw();
            if (end == 1) break;
            play();
            printBoard(board);
            win();
            if (end == 1) break;
            draw();
        }
        break;
    }
    default:
        printf("���α׷��� �����մϴ�.");
        break;
    }
    return 0;
}
