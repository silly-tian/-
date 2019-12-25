#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#define HASHSIZE 31

int HashFunc(int key, int *count)
{
	*count += 1;
	return key % HASHSIZE;
}

int Collision(int di, int *count)
{
	*count += 1;
	srand(100);
	return ((di + rand()) % HASHSIZE);
}

void Createht(char name[], char Hashtable[][20], int *count)
{
	int data = 0;
	int i;
	for (i = 0; name[i]; i++)
	{
		data += toascii(name[i]);
	}
	data = HashFunc(data, count);
	if (Hashtable[data][0] == '\0')
	{
		strcpy(Hashtable[data], name);
	}
	else
	{
		while (1)
		{
			data = Collision(data, count);
			if (Hashtable[data][0] == '\0')
			{
				strcpy(Hashtable[data], name);
				break;
			}
		}
	}

}

int HashSearch(char data[], char Hashtable[][20], int *count)
{
	int address = 0;
	int i;
	for (i = 0; data[i]; i++)
	{
		address += toascii(data[i]);
	}
	address = HashFunc(address, count);
	if (Hashtable[address][0] == '\0')
	{
		printf("查找失败！！！");
		return -1;
	}
	if (!strcmp(Hashtable[address], data))
	{
		return address;
	}
	else
	{
		while (1)
		{
			address = Collision(address, count);
			if (Hashtable[address][0] == '\0')
			{
				printf("查找失败！！！");
				return -1;
			}
			if (!strcmp(Hashtable[address], data))
			{
				return address;
			}
		}
	}
	return 0;
}

int main()
{
	int count = 0;
	int i;
	char data[20];
	char name[30][20] = { "tianpeisen", "heshuai", "zhaoshihao", "yuanjiawei", "aiyifu", "liqinqing",
						 "zhoupeng", "zhuangxuan", "zhaomei", "fuzhenshuai", "gaofeng", "lijie",
						 "liuxiaoying", "songdan", "denglei", "tianliuqian", "sunzhe", "huangyuxin",
						 "kongweishaung", "liqingyang", "jimanman", "liuxinyi", "liuxuechun", "liuyunlong",
						 "liuzijun", "maxingcai", "mayu", "menglu", "niuxueshuang", "wangchang" };
	char Hashtable[HASHSIZE][20];
	for (i = 0; i < HASHSIZE; i++)
	{
		Hashtable[i][0] = '\0';
	}
	for (i = 0; i < 30; i++)
	{
		Createht(name[i], Hashtable, &count);
		int c;
		c = 1;
	}
	printf("平均查找长度为: %f\n", count / 30.0);
	printf("请输入需要查找的名字(拼音): ");
	scanf("%s", data);
	int pos = HashSearch(data, Hashtable, &count);
	if (pos != -1)
	{
		printf("查找成功，%s 在哈希表中的位置为%d。\n", data, pos);
	}
	system("pause");
	return 0;
}