//题目描述
//从键盘接收有向图的顶点集，弧集，创建有向图，并完成下列任务：
//
//（1）计算结点的出度、入度以及度;
//
//(2) 从第一个顶点出发，求一个深度优先遍历序列;
//
//(3) 从第一个顶点顶点出发，求一个广度优先遍历序列。
//
//注意：以用户输入各个顶点的顺序为顶点的序号。
//
//在深度和广度优先遍历中，优先选择序号小的顶点。
//
//输入
//第一行输入两个整数，以空格隔开，分别代表图的顶点数n和弧数e。(顶点个数 <= 20)
//第二行依次输入顶点值，类型为字符，中间不用间隔符。
//接下去有e行，每行为两个字符 uv（中间没有间隔符），表示一条弧<u, v>。
//
//输出
//连续输出n行，依次为各个结点的出度和入度，格式为【顶点w 出度值 入度值 度值】，四者间用空格隔开。
//接下去的一行，输出深度优先遍历顶点序列（顶点间无间隔符）。
//
//最后一行，输出广度优先遍历顶点序列（顶点间无间隔符）。
//
//
//样例输入 Copy
//5 7
//ABCDE
//AB
//AE
//BC
//CD
//DA
//DB
//EC
//样例输出 Copy
//A 2 1 3
//B 1 2 3
//C 1 2 3
//D 2 1 3
//E 1 1 2
//ABCDE
//ABECD

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#define MAXVEX 20

int visited1[MAXVEX] = { 0 };
int visited2[MAXVEX] = { 0 };

typedef struct 
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;

void Create(AdjMatrix *G);
int LocateVex(AdjMatrix *G, char v);
void inout(AdjMatrix *G, int in[], int out[]);
void DFS(AdjMatrix *G, int v0);

void DFS(AdjMatrix *G, int v0)
{
	int w;
	int flag = 0;
	int flag1 = -1;
	printf("%c", G->vex[v0]);
	visited1[v0] = 1;
	int i;
	for (i = 1; i <= G->arcnum; i++)
	{
		if (G->arcs[v0][i] == 1)
		{
			w = i;
			flag++;
			flag1 = 1;
			break;
		}
	}
	while (flag1 != -1)
	{
		if (!visited1[w])
		{
			DFS(G, w);
		}
		int count = 0;
		for (i = 1; i <= G->arcnum; i++)
		{
			if (G->arcs[v0][i] == 1)
			{
				count++;
			}
			if (count > flag)
			{
				w = i;
				break;
			}
			flag1 = -1;
		}
	}
}

void inout(AdjMatrix *G, int in[], int out[])
{
	int i;
	int j;
	for (i = 1; i <= G->vexnum; i++)
	{
		for (j = 1; j <= G->vexnum; j++)
		{
			if (G->arcs[i][j] == 1)
			{
				out[i]++;
				in[j]++;
			}
		}
	}
}

int LocateVex(AdjMatrix *G, char v)
{
	int i;
	for (i = 1; G->vexnum; i++)
	{
		if (G->vex[i] == v)
		{
			return i;
		}
	}
	return 0;
}

void Create(AdjMatrix *G)
{
	int i, j, k, ch;
	char vex1, vex2;
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (i = 1; i <= G->vexnum; i++)
	{
		for (j = 1; j <= G->vexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		;
	}
	for (i = 1; i <= G->vexnum; i++)
	{
		scanf("%c", &G->vex[i]);
	}
	for (k = 0; k < G->arcnum; k++)
	{
		while ((ch = getchar()) != '\n' && ch != EOF)
		{
			;
		}
		scanf("%c%c", &vex1, &vex2);
		i = LocateVex(G, vex1);
		j = LocateVex(G, vex2);
		G->arcs[i][j] = 1;
	}
}

int main()
{
	int in[MAXVEX] = { 0 };
	int out[MAXVEX] = { 0 };
	int i;
	char shendu[MAXVEX];
	char guangdu[MAXVEX];
	AdjMatrix G;
	Create(&G);
	inout(&G, in, out);
	for (i = 1; i <= G.vexnum; i++)
	{
		printf("%c %d %d %d\n", G.vex[i], out[i], in[i], in[i] + out[i]);
	}
	DFS(&G, 1);
	system("pause");
	return 0;
}
