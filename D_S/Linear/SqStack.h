#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
typedef struct SqStack{
	int data[MaxSize];
	int top;//��һ��дʱ����дָ�����š�����
}SqStack;

typedef struct op{
	char data[MaxSize];
	int top;
}op;

typedef struct st{
	float data[MaxSize];
	int top;
}st;

typedef struct sharedSt {
	int data[MaxSize];
	int top1;
	int top2;
}sharedSt;

static int maze[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void InitStack(SqStack &st);//2019��8��10�� 22:09:59
int StackEmpty(SqStack st);//2019��8��10�� 22:11:59
int PushStack(SqStack &st, int x);//2019��8��10�� 22:14:33
int PopStack(SqStack &st, int &x);//2019��8��10�� 22:16:03
//�������ʽ��ֵ:1)��׺���ʽת��׺���ʽ(�沨�����ʽ); 2)�沨�����ʽ��ֵ
void trans(char exp[], char postexp[]);//2019��8��12�� 00:59:23
float computeValue(char postexp[]);//2019��8��12�� 02:56:13
void mazePath(int x1, int y1, int x2, int y2);//maze����Ϊ��̬ȫ�ֱ�������,������ʽ������δ���