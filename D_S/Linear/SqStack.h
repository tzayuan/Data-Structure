#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
typedef struct SqStack{
	int data[MaxSize];
	int top;//第一次写时打算写指针来着。。。
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

void InitStack(SqStack &st);//2019年8月10日 22:09:59
int StackEmpty(SqStack st);//2019年8月10日 22:11:59
int PushStack(SqStack &st, int x);//2019年8月10日 22:14:33
int PopStack(SqStack &st, int &x);//2019年8月10日 22:16:03
//算术表达式求值:1)中缀表达式转后缀表达式(逆波兰表达式); 2)逆波兰表达式求值
void trans(char exp[], char postexp[]);//2019年8月12日 00:59:23
float computeValue(char postexp[]);//2019年8月12日 02:56:13
void mazePath(int x1, int y1, int x2, int y2);//maze设置为静态全局变量即可,若传形式参数如何传？