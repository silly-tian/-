//��Ŀ����
//����ĳͨ�ű��ĵ��ַ�����A, B, C, D, E, F��6���ַ���ɣ������ڱ����г��ֵ�Ƶ�ȣ�Ƶ�Ⱦ�Ϊ����ֵ����
//(1)����һ�ù������������θ������ַ���������
//(2)���ַ������б��롣
//(3)�����봮�������롣
//
//�涨��
//������������ʱ�������������ȨֵС�ڵ��������������Ȩֵ��
//���ɱ���ʱ�����֧��0���ҷ�֧��1��
//
//����
//��һ�У���������6�����������δ���A, B, C, D, E, F��Ƶ�ȣ��ÿո������
//�ڶ��У���������ַ���
//�����У�������ı��봮
//
//���
//ǰ6��������������ַ������Ӧ���룬��ʽΪ���ַ� : ���롿��ð�ž�ΪӢ�ķ��ţ�
//��7�У����봮
//��8�У����봮
//
//�������� Copy
//3 4 10 8 6 5
//BEE
//0010000100111101
//
//������� Copy
//A : 000
//B : 001
//C : 10
//D : 01
//E : 111
//F : 110
//001111111
//BADBED

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6
#define M 2 * N - 1

//���������Ľṹ������
typedef struct
{
	int Weight;
	int Parent, Lchild, Rchild;
}HTNode, HuffmanTree[M + 1];


// �洢����������
typedef char * Huffmancode[N + 1];

void IniHuffmanTree(HuffmanTree ht);
void CrtHuffmanTree(HuffmanTree ht);
void CrtHuffmanCode(HuffmanTree ht, Huffmancode hc);

//��ʼ����������
void IniHuffmanTree(HuffmanTree ht) //��ʼ����������
{
	int i;
	for (i = 1; i < N + 1; i++) //������ʼ�Ľ��(��Ȩֵ)
	{
		scanf("%d", &ht[i].Weight);
		ht[i].Parent = 0;
		ht[i].Lchild = 0;
		ht[i].Rchild = 0;
	}
	for (i = N + 1; i < M + 1; i++) // ����ʣ�µĽ��(û��Ȩֵ)
	{
		ht[i].Weight = 0;
		ht[i].Parent = 0;
		ht[i].Lchild = 0;
		ht[i].Rchild = 0;
	}
}

// ������������
void CrtHuffmanTree(HuffmanTree ht)
{
	int i;
	int j;
	int min1 = 2147483647; // �����int�����ֵ
	int min2 = 2147483647;
	int min1_i = 1;
	int min2_i = 1;
	for (i = N + 1; i < M + 1; i++) // ѭ������Ľ��
	{
		min1 = 2147483647;
		min2 = 2147483647;

		//Ѱ����Сֵ�ʹ�Сֵ
		for (j = 1; j < i; j++) 
		{
			if (min1 > ht[j].Weight && ht[j].Parent == 0)
			{
				min2 = min1;
				min2_i = min1_i;
				min1 = ht[j].Weight;
				min1_i = j;
			}
			else if (min2 > ht[j].Weight && ht[j].Parent == 0)
			{
				min2 = ht[j].Weight;
				min2_i = j;
			}
		}

		//���ø�ĸ���ͺ��ӽ���Ȩֵ
		ht[i].Lchild = min1_i; 
		ht[i].Rchild = min2_i;
		ht[i].Weight = min1 + min2;
		ht[min1_i].Parent = i;
		ht[min2_i].Parent = i;
	}
}

// ������������
void CrtHuffmanCode(HuffmanTree ht, Huffmancode hc)
{
	int i;
	char *cd; // ��ʱ�洢����
	int start;
	int c; //������
	int p;  // ��ĸ���
	cd = (char *)malloc(N * sizeof(char));
	cd[N - 1] = '\0';
	for (i = 1; i <= N; i++)
	{
		start = N - 1;
		c = i;
		p = ht[i].Parent;
		// ���Ŵ洢��������ʱ��cd��
		while (p != 0)
		{
			start--;
			if (ht[p].Lchild == c)
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}
			c = p;
			p = ht[p].Parent;
		}
		hc[i] = (char *)malloc((N - start) * sizeof(char));
		// ����ʱ��cd����hc��
		strcpy(hc[i], &cd[start]);
	}
	free(cd); // �ͷ���ʱ
}


int main()
{
	HuffmanTree ht; 
	Huffmancode hc;
	char s[100];
	char ss[100];
	IniHuffmanTree(ht); // ��ʼ����������
	CrtHuffmanTree(ht); // �����������
	CrtHuffmanCode(ht, hc); // ������������

	scanf("%s", s); // �������ĸ ,�ڵڶ�������

	char sss[100];
	int j1 = 0;
	int j2;
	int j3 = 0;
	scanf("%s", ss); // ������� , �ڵ���������

	// ��������ʽ
	int i;
	for (i = 1; i < N + 1; i++)
	{
		printf("%c:%s\n", 64 + i, hc[i]);
	}

	//����BEE������Ķ�Ӧ����
	i = 0;
	while (s[i])
	{
		printf("%s", hc[s[i] - 64]);
		i++;
	}
	printf("\n");

	// ��������뷭�����
	while (ss[j1])
	{
		sss[j3] = ss[j1];
		sss[j3 + 1] = '\0';
		for (j2 = 1; j2 < N + 1; j2++)
		{
			if (strcmp(sss, hc[j2]) == 0)
			{
				printf("%c", j2 + 64);
				char sss[100];
				j3 = -1;
				break;
			}
		}
		j3++;
		j1++;
	}


	system("pause");
	return 0;
}