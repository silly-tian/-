//��Ŀ����
//������An*m��ĳ��Ԫ��A[i][j]�Ǿ����i����ֵ��С��Ԫ�أ�ͬʱ���ǵ�j����ֵ��
//
//���Ԫ�أ����Ԫ��A[i][j]�Ǿ����е�һ�����㡣���Զ�ά����洢���󣬱�д
//
//�㷨�����A�е��������㣬�㷨��ʱ�临�Ӷ�Ҫ�����ĵ͡�
//ע�⵱���ֵ����Сֵ���������ʱ������ֶర��������
//
//����
//��һ����������������M��������N���Կո�����
//֮���M�У������������ĸ������ݣ��Կո�����
//���
//�������㣬��������Ϊ������������������㡣ÿ�������ԣ�row, col, val
//
//������ʽ���������row ����������кţ�col����������кţ�val��������
//
//��ֵ��
//�������㣬�������NONE����
//
//�������� Copy
//4 6
//45 67 87 34 56 26
//93 75 85 75 92 75
//94 85 96 75 78 75
//23 17 75 28 98 61
//������� Copy
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