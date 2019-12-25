#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#define HASHSIZE 31

int HashFunc(int key, int *count) // 除留余数法
{
	*count += 1;
	return key % HASHSIZE;
}

int Collision(int di, int *count) // 随机探测再散列
{
	*count += 1;
	srand(100);
	return ((di + rand()) % HASHSIZE);
}

void Createht(char name[], char Hashtable[][20], int *count) // 创建哈希表
{
	int data = 0; 
	int i;
	for (i = 0; name[i]; i++)
	{
		data += toascii(name[i]);
	}
	data = HashFunc(data, count);
	if (Hashtable[data][0] == '\0')      // 因为在主函数中已经把哈希表的key全部初始化为"\0"，
	{	                                 // 所以进行这样的if 来判断哈希表对应位置是否为空。
		strcpy(Hashtable[data], name);   // 如果哈希表对应位置无数据，则存入
	}
	else // 如果哈希表对应位置有数据，则进行处理冲突，利用随机探测再散列
	{
		while (1)
		{
			data = Collision(data, count);
			if (Hashtable[data][0] == '\0') // 如果哈希表对应位置无数据，则存入
			{
				strcpy(Hashtable[data], name);
				break;
			}
		}
	}

}

int HashSearch(char data[], char Hashtable[][20], int *count)
{
	int address = 0; // 此处的address 和创建哈希表时的data是一个意思
	int i;
	for (i = 0; data[i]; i++)
	{
		address += toascii(data[i]);
	}
	address = HashFunc(address, count);
	if (Hashtable[address][0] == '\0') // 因为在主函数中已经把哈希表的key全部初始化为"\0"，
	{                                  // 所以进行这样的if 来判断哈希表对应位置是否为空。
		printf("查找失败！！！");      // 如果哈希表对应位置为空，则查找失败，表中无此数据，返回-1。
		return -1;
	}
	if (!strcmp(Hashtable[address], data)) //如果查找成功则返回哈希表的对应下标
	{
		return address;
	}
	else // 如果哈希表对应位置有数据，则进行处理冲突，利用随机探测再散列
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
	char data[20]; // 用于存储查找时的数据
	char name[30][20] = { "tianpeisen", "heshuai", "zhaoshihao", "yuanjiawei", "aiyifu", "liqinqing",
						 "zhoupeng", "zhuangxuan", "zhaomei", "fuzhenshuai", "gaofeng", "lijie",
						 "liuxiaoying", "songdan", "denglei", "tianliuqian", "sunzhe", "huangyuxin",
						 "kongweishaung", "liqingyang", "jimanman", "liuxinyi", "liuxuechun", "liuyunlong",
						 "liuzijun", "maxingcai", "mayu", "menglu", "niuxueshuang", "wangchang" };
	char Hashtable[HASHSIZE][20]; // 哈希表
	for (i = 0; i < HASHSIZE; i++) // 哈希表的key全部初始化为"\0"
	{
		Hashtable[i][0] = '\0';
	}
	for (i = 0; i < 30; i++) //创建哈希表
	{
		Createht(name[i], Hashtable, &count);
	}
	printf("平均查找长度为: %f\n", count / 30.0);
	printf("请输入需要查找的名字(拼音): ");
	scanf("%s", data);
	int pos = HashSearch(data, Hashtable, &count); // 哈希表查找
	if (pos != -1)
	{
		printf("查找成功，%s 在哈希表中的位置为%d。\n", data, pos);
	}
	system("pause");
	return 0;
}