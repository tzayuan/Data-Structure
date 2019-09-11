#pragma once
#include "pch.h"

//
//二叉树的性质:非空二叉树上叶子结点数等于双分支结点数加1;

//二叉树的顺序存储结构
typedef int SBTree[MaxSize];

//二叉树的链式存储结构
typedef struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
}LBTNode;

//二叉树的基本算法
void PreOrder(LBTNode *b);//2019年9月11日 20:20:16
void PreOrder1(LBTNode *b);//2019年9月11日 20:26:17
void InOrder(LBTNode *b);//2019年9月11日 20:51:59
void InOrder1(LBTNode *b);//2019年9月11日 21:23:27
void PostOrder(LBTNode *b);//2019年9月11日 21:25:20
void PostOrder1(LBTNode *b);//2019年9月11日 21:48:01
void CreateLBTNode(LBTNode *&b, char *str);//2019年9月11日 22:17:05