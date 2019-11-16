//题目描述
//假设某通信报文的字符集由A, B, C, D, E, F这6个字符组成，它们在报文中出现的频度（频度均为整数值）。
//(1)构造一棵哈弗曼树，依次给出各字符编码结果。
//(2)给字符串进行编码。
//(3)给编码串进行译码。
//
//规定：
//构建哈弗曼树时：左子树根结点权值小于等于右子树根结点权值。
//生成编码时：左分支标0，右分支标1。
//
//输入
//第一行：依次输入6个整数，依次代表A, B, C, D, E, F的频度，用空格隔开。
//第二行：待编码的字符串
//第三行：待译码的编码串
//
//输出
//前6行依次输出各个字符及其对应编码，格式为【字符 : 编码】（冒号均为英文符号）
//第7行：编码串
//第8行：译码串
//
//样例输入 Copy
//3 4 10 8 6 5
//BEE
//0010000100111101
//
//样例输出 Copy
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

//哈弗曼树的结构体数组
typedef struct
{
	int Weight;
	int Parent, Lchild, Rchild;
}HTNode, HuffmanTree[M + 1];


// 存储哈夫曼编码
typedef char * Huffmancode[N + 1];

void IniHuffmanTree(HuffmanTree ht);
void CrtHuffmanTree(HuffmanTree ht);
void CrtHuffmanCode(HuffmanTree ht, Huffmancode hc);

//初始化哈弗曼树
void IniHuffmanTree(HuffmanTree ht) //初始化哈弗曼树
{
	int i;
	for (i = 1; i < N + 1; i++) //遍历初始的结点(有权值)
	{
		scanf("%d", &ht[i].Weight);
		ht[i].Parent = 0;
		ht[i].Lchild = 0;
		ht[i].Rchild = 0;
	}
	for (i = N + 1; i < M + 1; i++) // 遍历剩下的结点(没有权值)
	{
		ht[i].Weight = 0;
		ht[i].Parent = 0;
		ht[i].Lchild = 0;
		ht[i].Rchild = 0;
	}
}

// 创建哈夫曼树
void CrtHuffmanTree(HuffmanTree ht)
{
	int i;
	int j;
	int min1 = 2147483647; // 定义成int的最大值
	int min2 = 2147483647;
	int min1_i = 1;
	int min2_i = 1;
	for (i = N + 1; i < M + 1; i++) // 循环后面的结点
	{
		min1 = 2147483647;
		min2 = 2147483647;

		//寻找最小值和次小值
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

		//设置父母结点和孩子结点和权值
		ht[i].Lchild = min1_i; 
		ht[i].Rchild = min2_i;
		ht[i].Weight = min1 + min2;
		ht[min1_i].Parent = i;
		ht[min2_i].Parent = i;
	}
}

// 哈弗曼树编码
void CrtHuffmanCode(HuffmanTree ht, Huffmancode hc)
{
	int i;
	char *cd; // 临时存储编码
	int start;
	int c; //自身结点
	int p;  // 父母结点
	cd = (char *)malloc(N * sizeof(char));
	cd[N - 1] = '\0';
	for (i = 1; i <= N; i++)
	{
		start = N - 1;
		c = i;
		p = ht[i].Parent;
		// 倒着存储编码在临时的cd里
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
		// 将临时的cd放在hc里
		strcpy(hc[i], &cd[start]);
	}
	free(cd); // 释放临时
}


int main()
{
	HuffmanTree ht; 
	Huffmancode hc;
	char s[100];
	char ss[100];
	IniHuffmanTree(ht); // 初始化哈弗曼树
	CrtHuffmanTree(ht); // 创造哈夫曼树
	CrtHuffmanCode(ht, hc); // 哈弗曼树编码

	scanf("%s", s); // 输入的字母 ,在第二行输入

	char sss[100];
	int j1 = 0;
	int j2;
	int j3 = 0;
	scanf("%s", ss); // 输入的码 , 在第三行输入

	// 输出编码格式
	int i;
	for (i = 1; i < N + 1; i++)
	{
		printf("%c:%s\n", 64 + i, hc[i]);
	}

	//输入BEE后，输出的对应编码
	i = 0;
	while (s[i])
	{
		printf("%s", hc[s[i] - 64]);
		i++;
	}
	printf("\n");

	// 将输入的码翻译出来
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