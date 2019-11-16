//题目描述
//从键盘接收扩展先序序列，以二叉链表作为存储结构，建立二叉树。输出这棵二叉树的先序、中序和后序遍历序列。
//
//输入
//输入扩展先序序列。二叉树结点的data是字符类型数据, 其中#表示空格字符。
//
//输出
//三行依次输出先序、中序、后序遍历序列。
//
//样例输入 Copy
//ABC##DE#G##F###
//
//样例输出 Copy
//ABCDEGF
//CBEGDFA
//CGEFDBA

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>