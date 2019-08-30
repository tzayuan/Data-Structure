#pragma once
#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>

typedef struct LStackNode {
	int data;
	struct LStackNode * next;
}LStackNode;

//带有头结点的基于单链表存储结构的栈.此处规定栈的所有操作都是在单链表的表头进行的,第一个数据结点是栈顶结点, 最后一个结点是栈底结点
void InitLStack(LStackNode *&lst);
int isEmptyLStack(LStackNode *lst);
void pushLStack(LStackNode *&lst, int x);
int popLStack(LStackNode *&lst, int &x);

//不带头结点的基于单链表存储结构的栈.
void InitLStackWithoutHead(LStackNode *&lst);
int isEmptyLStackWithoutHead(LStackNode *lst);
void pushLStackWithoutHead(LStackNode *&lst, int x);
int popLStackWithoutHead(LStackNode *&lst, int &x);