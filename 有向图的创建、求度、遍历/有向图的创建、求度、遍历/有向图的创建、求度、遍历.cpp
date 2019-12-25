//��Ŀ����
//�Ӽ��̽�������ͼ�Ķ��㼯����������������ͼ���������������
//
//��1��������ĳ��ȡ�����Լ���;
//
//(2) �ӵ�һ�������������һ��������ȱ�������;
//
//(3) �ӵ�һ�����㶥���������һ��������ȱ������С�
//
//ע�⣺���û�������������˳��Ϊ�������š�
//
//����Ⱥ͹�����ȱ����У�����ѡ�����С�Ķ��㡣
//
//����
//��һ�����������������Կո�������ֱ����ͼ�Ķ�����n�ͻ���e��(������� <= 20)
//�ڶ����������붥��ֵ������Ϊ�ַ����м䲻�ü������
//����ȥ��e�У�ÿ��Ϊ�����ַ� uv���м�û�м����������ʾһ����<u, v>��
//
//���
//�������n�У�����Ϊ�������ĳ��Ⱥ���ȣ���ʽΪ������w ����ֵ ���ֵ ��ֵ�������߼��ÿո������
//����ȥ��һ�У����������ȱ����������У�������޼��������
//
//���һ�У����������ȱ����������У�������޼��������
//
//
//�������� Copy
//5 7
//ABCDE
//AB
//AE
//BC
//CD
//DA
//DB
//EC
//������� Copy
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
