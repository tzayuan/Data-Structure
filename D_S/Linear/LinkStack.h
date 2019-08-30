#pragma once
#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>

typedef struct LStackNode {
	int data;
	struct LStackNode * next;
}LStackNode;

//����ͷ���Ļ��ڵ�����洢�ṹ��ջ.�˴��涨ջ�����в��������ڵ�����ı�ͷ���е�,��һ�����ݽ����ջ�����, ���һ�������ջ�׽��
void InitLStack(LStackNode *&lst);
int isEmptyLStack(LStackNode *lst);
void pushLStack(LStackNode *&lst, int x);
int popLStack(LStackNode *&lst, int &x);

//����ͷ���Ļ��ڵ�����洢�ṹ��ջ.
void InitLStackWithoutHead(LStackNode *&lst);
int isEmptyLStackWithoutHead(LStackNode *lst);
void pushLStackWithoutHead(LStackNode *&lst, int x);
int popLStackWithoutHead(LStackNode *&lst, int &x);