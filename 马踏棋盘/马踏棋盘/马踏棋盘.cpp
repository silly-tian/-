//��Ŀ����
//�������8��8������ָ����ĳ��������ͼ��ʾ��������ƶ���Ҫ��ÿ������ֻ����һ�Σ��߱�������ȫ��64����������������·�ߣ��������������·�߽�����1��2������64��������һ��8��8�ķ��������
//
//�ر�涨������밴��ͼ��ʾ1��8��˳�����8����ͬ�����̽����
//
//      8          1
//
//
//7                       2
//
//           ��
//
//6                       3
//
//
//      5          4
//
//
//����
//������������ m ��n���ո���������ʾ��ʼ�����кţ���ΧΪ1~8����
//���
//�Ծ�����ʽ��8��8�����е�·�������
//
//ÿ������ռ�����ַ��Ŀ�ȣ�������λʱ���Ҷ��룩��ÿ���������һ��
//
//��������
//1 1
//�������
// 1 38 55 34  3 36 19 22
//54 47  2 37 20 23  4 17
//39 56 33 46 35 18 21 10
//48 53 40 57 24 11 16  5
//59 32 45 52 41 26  9 12
//44 49 58 25 62 15  6 27
//31 60 51 42 29  8 13 64
//50 43 30 61 14 63 28  7

//37 to 40
//37 to 56

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct cell
{
	int flag;
	int num;
};

struct horse
{
	int x;
	int y;
	int d;
};

//int main()
//{
//	int m, n;
//	int i = 0;
//	int flag = 0;
//	int count = 0;
//	scanf("%d %d", &m, &n);
//	struct cell cell_data[64] = { 0 };
//	struct horse horse_data[64] = { 0 };
//	while (i < 63)
//	{
//		flag = 0;
//		if (i == 0)
//		{
//			cell_data[(m - 1) * 8 + (n - 1)].flag = 1;
//			cell_data[(m - 1) * 8 + (n - 1)].num = i + 1;
//			horse_data[i].x = m;
//			horse_data[i].y = n;
//			horse_data[i].d = 0;
//			while (horse_data[i].d < 9)
//			{
//				if (flag == 0)
//				{
//					switch (horse_data[i].d)
//					{
//					case 0:
//						if (((horse_data[i].x + 1) < 9) && ((horse_data[i].y - 2) > 0) && cell_data[(horse_data[i].x + 1 - 1) + (horse_data[i].y - 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 1;
//							horse_data[i].y = horse_data[i - 1].y - 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 1:
//						if (((horse_data[i].x + 2) < 9) && ((horse_data[i].y - 1) > 0) && cell_data[(horse_data[i].x + 2 - 1) + (horse_data[i].y - 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 2;
//							horse_data[i].y = horse_data[i - 1].y - 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 2:
//						if (((horse_data[i].x + 2) < 9) && ((horse_data[i].y + 1) < 9) && cell_data[(horse_data[i].x + 2 - 1) + (horse_data[i].y + 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 2;
//							horse_data[i].y = horse_data[i - 1].y + 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 3:
//						if (((horse_data[i].x + 1) < 9) && ((horse_data[i].y + 2) < 9) && cell_data[(horse_data[i].x + 1 - 1) + (horse_data[i].y + 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 1;
//							horse_data[i].y = horse_data[i - 1].y + 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 4:
//						if (((horse_data[i].x - 1) > 0) && ((horse_data[i].y + 2) < 9) && cell_data[(horse_data[i].x - 1 - 1) + (horse_data[i].y + 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 1;
//							horse_data[i].y = horse_data[i - 1].y + 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 5:
//						if (((horse_data[i].x - 2) > 0) && ((horse_data[i].y + 1) < 9) && cell_data[(horse_data[i].x - 2 - 1) + (horse_data[i].y + 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 2;
//							horse_data[i].y = horse_data[i - 1].y + 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 6:
//						if (((horse_data[i].x - 2) > 0) && ((horse_data[i].y - 1) > 0) && cell_data[(horse_data[i].x - 2 - 1) + (horse_data[i].y - 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 2;
//							horse_data[i].y = horse_data[i - 1].y - 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 7:
//						if (((horse_data[i].x - 1) > 0) && ((horse_data[i].y - 2) > 0) && cell_data[(horse_data[i].x - 1 - 1) + (horse_data[i].y - 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 1;
//							horse_data[i].y = horse_data[i - 1].y - 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 8:
//						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 0;
//						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = 0;
//						horse_data[i].d = 0;
//						horse_data[i].x = 0;
//						horse_data[i].y = 0;
//						i--;
//						horse_data[i].d++;
//						break;
//					}
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//		else
//		{
//			while (horse_data[i].d < 9)
//			{
//				if (flag == 0)
//				{
//					switch (horse_data[i].d)
//					{
//					case 0:
//						if (((horse_data[i].x + 1) < 9) && ((horse_data[i].y - 2) > 0) && cell_data[(horse_data[i].x + 1 - 1) + (horse_data[i].y - 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 1;
//							horse_data[i].y = horse_data[i - 1].y - 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 1:
//						if (((horse_data[i].x + 2) < 9) && ((horse_data[i].y - 1) > 0) && cell_data[(horse_data[i].x + 2 - 1) + (horse_data[i].y - 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 2;
//							horse_data[i].y = horse_data[i - 1].y - 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 2:
//						if (((horse_data[i].x + 2) < 9) && ((horse_data[i].y + 1) < 9) && cell_data[(horse_data[i].x + 2 - 1) + (horse_data[i].y + 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 2;
//							horse_data[i].y = horse_data[i - 1].y + 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 3:
//						if (((horse_data[i].x + 1) < 9) && ((horse_data[i].y + 2) < 9) && cell_data[(horse_data[i].x + 1 - 1) + (horse_data[i].y + 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x + 1;
//							horse_data[i].y = horse_data[i - 1].y + 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 4:
//						if (((horse_data[i].x - 1) > 0) && ((horse_data[i].y + 2) < 9) && cell_data[(horse_data[i].x - 1 - 1) + (horse_data[i].y + 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 1;
//							horse_data[i].y = horse_data[i - 1].y + 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 5:
//						if (((horse_data[i].x - 2) > 0) && ((horse_data[i].y + 1) < 9) && cell_data[(horse_data[i].x - 2 - 1) + (horse_data[i].y + 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 2;
//							horse_data[i].y = horse_data[i - 1].y + 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 6:
//						if (((horse_data[i].x - 2) > 0) && ((horse_data[i].y - 1) > 0) && cell_data[(horse_data[i].x - 2 - 1) + (horse_data[i].y - 1 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 2;
//							horse_data[i].y = horse_data[i - 1].y - 1;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 7:
//						if (((horse_data[i].x - 1) > 0) && ((horse_data[i].y - 2) > 0) && cell_data[(horse_data[i].x - 1 - 1) + (horse_data[i].y - 2 - 1) * 8].flag == 0)
//						{
//							i++;
//							horse_data[i].x = horse_data[i - 1].x - 1;
//							horse_data[i].y = horse_data[i - 1].y - 2;
//							horse_data[i].d = 0;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
//							cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
//							flag = 1;
//						}
//						else
//						{
//							horse_data[i].d++;
//						}
//						break;
//					case 8:
//						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 0;
//						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = 0;
//						horse_data[i].d = 0;
//						horse_data[i].x = 0;
//						horse_data[i].y = 0;
//						flag = 1;
//						i--;
//						horse_data[i].d++;
//						break;
//					}
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//	}
//	for (i = 0; i < 64; i++)
//	{
//		printf("%2d ", cell_data[i].num);
//		count++;
//		if (count == 8)
//		{
//			count = 0;
//			printf("\n");
//		}
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int m, n;
	int i = 0;
	int flag = 0;
	int count = 0;
	scanf("%d %d", &m, &n);
	struct cell cell_data[64] = { 0 };
	struct horse horse_data[64] = { 0 };
	while (i < 63)
	{
		flag = 0;
		if (i == 0)
		{
			cell_data[(m - 1) * 8 + (n - 1)].flag = 1;
			cell_data[(m - 1) * 8 + (n - 1)].num = i + 1;
			horse_data[i].x = m;
			horse_data[i].y = n;
			horse_data[i].d = 0;
		}
		while (horse_data[i].d < 9)
		{
			if (flag == 0)
			{
				switch (horse_data[i].d)
				{
				case 0:
					if (((horse_data[i].x + 1) < 9) && ((horse_data[i].y - 2) > 0) && cell_data[(horse_data[i].x + 1 - 1) + (horse_data[i].y - 2 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x + 1;
						horse_data[i].y = horse_data[i - 1].y - 2;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 1:
					if (((horse_data[i].x + 2) < 9) && ((horse_data[i].y - 1) > 0) && cell_data[(horse_data[i].x + 2 - 1) + (horse_data[i].y - 1 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x + 2;
						horse_data[i].y = horse_data[i - 1].y - 1;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 2:
					if (((horse_data[i].x + 2) < 9) && ((horse_data[i].y + 1) < 9) && cell_data[(horse_data[i].x + 2 - 1) + (horse_data[i].y + 1 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x + 2;
						horse_data[i].y = horse_data[i - 1].y + 1;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 3:
					if (((horse_data[i].x + 1) < 9) && ((horse_data[i].y + 2) < 9) && cell_data[(horse_data[i].x + 1 - 1) + (horse_data[i].y + 2 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x + 1;
						horse_data[i].y = horse_data[i - 1].y + 2;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 4:
					if (((horse_data[i].x - 1) > 0) && ((horse_data[i].y + 2) < 9) && cell_data[(horse_data[i].x - 1 - 1) + (horse_data[i].y + 2 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x - 1;
						horse_data[i].y = horse_data[i - 1].y + 2;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 5:
					if (((horse_data[i].x - 2) > 0) && ((horse_data[i].y + 1) < 9) && cell_data[(horse_data[i].x - 2 - 1) + (horse_data[i].y + 1 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x - 2;
						horse_data[i].y = horse_data[i - 1].y + 1;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 6:
					if (((horse_data[i].x - 2) > 0) && ((horse_data[i].y - 1) > 0) && cell_data[(horse_data[i].x - 2 - 1) + (horse_data[i].y - 1 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x - 2;
						horse_data[i].y = horse_data[i - 1].y - 1;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 7:
					if (((horse_data[i].x - 1) > 0) && ((horse_data[i].y - 2) > 0) && cell_data[(horse_data[i].x - 1 - 1) + (horse_data[i].y - 2 - 1) * 8].flag == 0)
					{
						i++;
						horse_data[i].x = horse_data[i - 1].x - 1;
						horse_data[i].y = horse_data[i - 1].y - 2;
						horse_data[i].d = 0;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 1;
						cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = i + 1;
						flag = 1;
					}
					else
					{
						horse_data[i].d++;
					}
					break;
				case 8:
					cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].flag = 0;
					cell_data[(horse_data[i].x - 1) + (horse_data[i].y - 1) * 8].num = 0;
					horse_data[i].d = 0;
					horse_data[i].x = 0;
					horse_data[i].y = 0;
					i--;
					horse_data[i].d++;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	for (i = 0; i < 64; i++)
	{
		printf("%2d ", cell_data[i].num);
		count++;
		if (count == 8)
		{
			count = 0;
			printf("\n");
		}
	}
	system("pause");
	return 0;
}