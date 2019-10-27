//题目描述
//用一个m×n的矩阵表示迷宫，0和1分别表示迷宫中的通路和障碍。设计一个程序，对给定的迷宫，求出找到的第一条从入口到出口的通路，或得到没有通路的结论。
//
//我们指定 :
//(1) 迷宫的入口为矩阵的左上角（1, 1），迷宫的出口为右下角（m, n）;
//(2) 路径的探索顺序依次为"东南西北"（即：右下左上）。
//
//输入
//第一行输入两个整数，空格间隔，分别表示矩阵的行数m和列数n；
//接下来的连续m行，输入迷宫矩阵的信息。

//输出
//求得的通路以三元组(i, j, d)的形式输出。
//
//其中：
//i, j指示迷宫的一个坐标;
//d表示走到下一坐标的方向(数字1表示东，数字2表示南，数字3表示西，数字4表示北);
//终点d值为0。
//
//样例输入
//   9 8
//   0  0  1  0  0  0  1  0   (空格我自己加的，原输入没有空格，嘻嘻嘻)
//   0  0  1  0  0  0  1  0
//   0  0  0  0  1  1  0  1
//   0  1  1  1  0  0  1  0
//   0  0  0  1  0  0  0  0 
//   0  1  0  0  0  1  0  1
//   0  1  1  1  1  0  0  1
//   1  1  0  0  0  1  0  1 
//   1  1  0  0  0  0  0  0
//样例输出
//(1, 1, 1)(1, 2, 2)(2, 2, 2)(3, 2, 3)(3, 1, 2)(4, 1, 2)(5, 1, 1)(5, 2, 1)(5, 3, 2)(6, 3, 1)(6, 4, 1)(6, 5, 4)(5, 5, 1)(5, 6, 1)(5, 7, 2)(6, 7, 2)(7, 7, 2)(8, 7, 2)(9, 7, 1)(9, 8, 0)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct round
{
	int x;
	int y;
	int way;
};

struct maze
{
	int road;
	int flag;
};

int main()
{
	int count = 0;
	int m, n;
	int i;
	int j;
	int flag;
	scanf("%d %d", &m, &n);
	char *row_maze = (char *)malloc((n + 1) * sizeof(char));
	struct maze *maze_data = (struct maze*)malloc((m * n) * sizeof(struct maze));
	struct round *round_data = (struct round*)malloc((m * n) * sizeof(struct round));
	for (i = 0; i < m; i++)
	{
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF)
		{
			;
		}
		scanf("%s", row_maze);
		for (j = 0; j < n; j++)
		{
			maze_data[j + i * n].road = row_maze[j] - 48;
		}
	}
	i = 0;
	while (i < m * n)
	{
		if (round_data[i].x == n && round_data[i].y == m)
		{
			break;
		}
		flag = 0;
		if (i == 0)
		{
			round_data[i].x = 1;
			round_data[i].y = 1;
			round_data[i].way = 1;
			maze_data[0].flag = 1;
			count++;
		}
		while (round_data[i].way < 6)
		{
			if (flag == 0)
			{
				switch (round_data[i].way)
				{
				case 1:
					if ((round_data[i].x + 1) < n + 1 && maze_data[(round_data[i].x + 1 - 1) + (round_data[i].y - 1) * n].flag != 1 && maze_data[(round_data[i].x + 1 - 1) + (round_data[i].y - 1) * n].road == 0)
					{
						i++;
						round_data[i].x = round_data[i - 1].x + 1;
						round_data[i].y = round_data[i - 1].y;
						round_data[i].way = 1;
						maze_data[(round_data[i].x - 1) + (round_data[i].y - 1) * n].flag = 1;
						flag = 1;
						count++;
					}
					else
					{
						round_data[i].way++;
					}
					break;
				case 2:
					if ((round_data[i].y + 1) < m + 1 && maze_data[(round_data[i].x - 1) + (round_data[i].y + 1 - 1) * n].flag != 1 && maze_data[(round_data[i].x - 1) + (round_data[i].y + 1 - 1) * n].road == 0)
					{
						i++;
						round_data[i].x = round_data[i - 1].x;
						round_data[i].y = round_data[i - 1].y + 1;
						round_data[i].way = 1;
						maze_data[(round_data[i].x - 1) + (round_data[i].y - 1) * n].flag = 1;
						flag = 1;
						count++;
					}
					else
					{
						round_data[i].way++;
					}
					break;
				case 3:
					if ((round_data[i].x - 1) > 0 && maze_data[(round_data[i].x - 1 - 1) + (round_data[i].y - 1) * n].flag != 1 && maze_data[(round_data[i].x - 1 - 1) + (round_data[i].y - 1) * n].road == 0)
					{
						i++;
						round_data[i].x = round_data[i - 1].x - 1;
						round_data[i].y = round_data[i - 1].y;
						round_data[i].way = 1;
						maze_data[(round_data[i].x - 1) + (round_data[i].y - 1) * n].flag = 1;
						flag = 1;
						count++;
					}
					else
					{
						round_data[i].way++;
					}
					break;
				case 4:
					if ((round_data[i].y - 1) > 0 && maze_data[(round_data[i].x - 1) + (round_data[i].y - 1 - 1) * n].flag != 1 && maze_data[(round_data[i].x - 1) + (round_data[i].y - 1 - 1) * n].road == 0)
					{
						i++;
						round_data[i].x = round_data[i - 1].x;
						round_data[i].y = round_data[i - 1].y - 1;
						round_data[i].way = 1;
						maze_data[(round_data[i].x - 1) + (round_data[i].y - 1) * n].flag = 1;
						flag = 1;
						count++;
					}
					else
					{
						round_data[i].way++;
					}
					break;
				case 5:
					maze_data[(round_data[i].x - 1) + (round_data[i].y - 1) * n].flag = 0;
					round_data[i].x = 0;
					round_data[i].y = 0;
					round_data[i].way = 1;
					i--;
					round_data[i].way++;
					count--;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	round_data[count - 1].way = 0;
	for (i = 0; i < count; i++)
	{
		printf("(%d,%d,%d)", round_data[i].y, round_data[i].x, round_data[i].way);
	}

	system("pause");
	return 0;
}