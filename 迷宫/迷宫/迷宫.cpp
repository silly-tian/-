//��Ŀ����
//��һ��m��n�ľ����ʾ�Թ���0��1�ֱ��ʾ�Թ��е�ͨ·���ϰ������һ�����򣬶Ը������Թ�������ҵ��ĵ�һ������ڵ����ڵ�ͨ·����õ�û��ͨ·�Ľ��ۡ�
//
//����ָ�� :
//(1) �Թ������Ϊ��������Ͻǣ�1, 1�����Թ��ĳ���Ϊ���½ǣ�m, n��;
//(2) ·����̽��˳������Ϊ"��������"�������������ϣ���
//
//����
//��һ�����������������ո������ֱ��ʾ���������m������n��
//������������m�У������Թ��������Ϣ��

//���
//��õ�ͨ·����Ԫ��(i, j, d)����ʽ�����
//
//���У�
//i, jָʾ�Թ���һ������;
//d��ʾ�ߵ���һ����ķ���(����1��ʾ��������2��ʾ�ϣ�����3��ʾ��������4��ʾ��);
//�յ�dֵΪ0��
//
//��������
//   9 8
//   0  0  1  0  0  0  1  0   (�ո����Լ��ӵģ�ԭ����û�пո�������)
//   0  0  1  0  0  0  1  0
//   0  0  0  0  1  1  0  1
//   0  1  1  1  0  0  1  0
//   0  0  0  1  0  0  0  0 
//   0  1  0  0  0  1  0  1
//   0  1  1  1  1  0  0  1
//   1  1  0  0  0  1  0  1 
//   1  1  0  0  0  0  0  0
//�������
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