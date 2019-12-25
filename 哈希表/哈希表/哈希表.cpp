#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#define HASHSIZE 31

int HashFunc(int key, int *count) // ����������
{
	*count += 1;
	return key % HASHSIZE;
}

int Collision(int di, int *count) // ���̽����ɢ��
{
	*count += 1;
	srand(100);
	return ((di + rand()) % HASHSIZE);
}

void Createht(char name[], char Hashtable[][20], int *count) // ������ϣ��
{
	int data = 0; 
	int i;
	for (i = 0; name[i]; i++)
	{
		data += toascii(name[i]);
	}
	data = HashFunc(data, count);
	if (Hashtable[data][0] == '\0')      // ��Ϊ�����������Ѿ��ѹ�ϣ���keyȫ����ʼ��Ϊ"\0"��
	{	                                 // ���Խ���������if ���жϹ�ϣ���Ӧλ���Ƿ�Ϊ�ա�
		strcpy(Hashtable[data], name);   // �����ϣ���Ӧλ�������ݣ������
	}
	else // �����ϣ���Ӧλ�������ݣ�����д����ͻ���������̽����ɢ��
	{
		while (1)
		{
			data = Collision(data, count);
			if (Hashtable[data][0] == '\0') // �����ϣ���Ӧλ�������ݣ������
			{
				strcpy(Hashtable[data], name);
				break;
			}
		}
	}

}

int HashSearch(char data[], char Hashtable[][20], int *count)
{
	int address = 0; // �˴���address �ʹ�����ϣ��ʱ��data��һ����˼
	int i;
	for (i = 0; data[i]; i++)
	{
		address += toascii(data[i]);
	}
	address = HashFunc(address, count);
	if (Hashtable[address][0] == '\0') // ��Ϊ�����������Ѿ��ѹ�ϣ���keyȫ����ʼ��Ϊ"\0"��
	{                                  // ���Խ���������if ���жϹ�ϣ���Ӧλ���Ƿ�Ϊ�ա�
		printf("����ʧ�ܣ�����");      // �����ϣ���Ӧλ��Ϊ�գ������ʧ�ܣ������޴����ݣ�����-1��
		return -1;
	}
	if (!strcmp(Hashtable[address], data)) //������ҳɹ��򷵻ع�ϣ��Ķ�Ӧ�±�
	{
		return address;
	}
	else // �����ϣ���Ӧλ�������ݣ�����д����ͻ���������̽����ɢ��
	{
		while (1)
		{
			address = Collision(address, count);
			if (Hashtable[address][0] == '\0')
			{
				printf("����ʧ�ܣ�����");
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
	char data[20]; // ���ڴ洢����ʱ������
	char name[30][20] = { "tianpeisen", "heshuai", "zhaoshihao", "yuanjiawei", "aiyifu", "liqinqing",
						 "zhoupeng", "zhuangxuan", "zhaomei", "fuzhenshuai", "gaofeng", "lijie",
						 "liuxiaoying", "songdan", "denglei", "tianliuqian", "sunzhe", "huangyuxin",
						 "kongweishaung", "liqingyang", "jimanman", "liuxinyi", "liuxuechun", "liuyunlong",
						 "liuzijun", "maxingcai", "mayu", "menglu", "niuxueshuang", "wangchang" };
	char Hashtable[HASHSIZE][20]; // ��ϣ��
	for (i = 0; i < HASHSIZE; i++) // ��ϣ���keyȫ����ʼ��Ϊ"\0"
	{
		Hashtable[i][0] = '\0';
	}
	for (i = 0; i < 30; i++) //������ϣ��
	{
		Createht(name[i], Hashtable, &count);
	}
	printf("ƽ�����ҳ���Ϊ: %f\n", count / 30.0);
	printf("��������Ҫ���ҵ�����(ƴ��): ");
	scanf("%s", data);
	int pos = HashSearch(data, Hashtable, &count); // ��ϣ�����
	if (pos != -1)
	{
		printf("���ҳɹ���%s �ڹ�ϣ���е�λ��Ϊ%d��\n", data, pos);
	}
	system("pause");
	return 0;
}