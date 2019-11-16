//题目描述
//若矩阵An*m中某个元素A[i][j]是矩阵第i行中值最小的元素，同时又是第j列中值最
//
//大的元素，则称元素A[i][j]是矩阵中的一个马鞍点。设以二维数组存储矩阵，编写
//
//算法求矩阵A中的所有马鞍点，算法的时间复杂度要尽量的低。
//注意当最大值（最小值）并列相等时，会出现多鞍点的情况。
//
//输入
//第一行输入矩阵的总行数M和总列数N，以空格间隔。
//之后的M行，依次输入矩阵的各行数据，以空格间隔。
//输出
//若有马鞍点，则以行序为主序，依次输出各个马鞍点。每个马鞍点以（row, col, val
//
//）的形式输出，其中row 代表马鞍点的行号，col代表马鞍点的列号，val代表马鞍点
//
//的值。
//若无马鞍点，则输出“NONE”。
//
//样例输入 Copy
//4 6
//45 67 87 34 56 26
//93 75 85 75 92 75
//94 85 96 75 78 75
//23 17 75 28 98 61
//样例输出 Copy
//(2, 4, 75)(2, 6, 75)(3, 4, 75)(3, 6, 75)

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#define MaxSize 1000
typedef struct
{
	int row, col, value;
}Triple;

typedef struct
{
	Triple data[MaxSize + 1];
	int rows, cols, nums;
}Ts;

int main()
{
	Ts *A = (Ts*)malloc(sizeof(Ts));
	int row, col, i, j, flag = 0;
	scanf("%d %d", &row, &col);
	A->rows = row;
	A->cols = col;
	A->nums = row * col;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			scanf("%d", &A->data[(i - 1)*A->cols + j].value);
			A->data[(i - 1)*A->cols + j].row = i;
			A->data[(i - 1)*A->cols + j].col = j;
		}
	}
	int numb[MaxSize];
	for (i = 1; i <= row + col; i++)
	{
		int max = 0;
		if (i <= row)
		{
			int min = A->data[(i - 1)*col + 1].value;
			for (j = 1; j <= col; j++)
			{
				int now = A->data[(i - 1)*col + j].value;
				if (min > now)
					min = now;
			}
			numb[i] = min;
		}
		else {
			for (j = 1; j <= row; j++)
			{
				int now = A->data[(j - 1)*col + (i - row)].value;
				if (max < now)
					max = now;
			}
			numb[i] = max;
		}
	}
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			int now = A->data[(i - 1)*A->cols + j].value;
			int row1 = A->data[(i - 1)*A->cols + j].row;
			int col1 = A->data[(i - 1)*A->cols + j].col;
			if (now == numb[row1] && now == numb[col1 + row])
			{
				printf("(%d,%d,%d)", row1, col1, now);
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf("NONE");
	system("pause");
	return 0;
}