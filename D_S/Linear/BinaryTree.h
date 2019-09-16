#pragma once
#include "pch.h"

//
//二叉树的性质:非空二叉树上叶子结点数等于双分支结点数加1;

//二叉树的顺序存储结构
typedef int SBTree[MaxSize];

//二叉树的链式存储结构
typedef struct node {
	char data;
	struct node *lchild;
	struct node *rchild;
}LBTNode;

//线索二叉树的链式存储结构
typedef struct node {
	char data;//结点数据域
	int ltag, rtag;//增加的线索标记
	struct node *lchild;//左孩子或线索指针(指向前驱结点)
	struct node *rchild;//右孩子或线索指针(指向其后继结点)
}TBTNode;//线索树结点类型定义

//哈夫曼树haffman tree
typedef struct {
	int data;//结点值
	float weight;//权重
	int parent;//双亲结点
	int lchild;//左孩子结点
	int rchild;//右孩子结点
}HTNode;
//二叉树的基本算法,非递归算法暂未掌握,涉及"利用栈消除递归"一节
//前序遍历,中序遍历,后序遍历的递归算法及非递归算法
void PreOrder(LBTNode *b);//2019年9月11日 20:20:16
void PreOrder1(LBTNode *b);//2019年9月11日 20:26:17
void InOrder(LBTNode *b);//2019年9月11日 20:51:59
void InOrder1(LBTNode *b);//2019年9月11日 21:23:27
void PostOrder(LBTNode *b);//2019年9月11日 21:25:20
void PostOrder1(LBTNode *b);//2019年9月11日 21:48:01
void CreateLBTNode(LBTNode *&b, char *str);//2019年9月11日 22:17:05

LBTNode *FindNode(LBTNode *b, int x);//2019年9月12日 21:29:44
LBTNode *LchildNode(LBTNode *b);//2019年9月12日 21:31:41
LBTNode *RchildNode(LBTNode *b);//2019年9月12日 21:33:19
int LBTNodeDepth(LBTNode *b);//2019年9月12日 21:43:56
void DispLBTNode(LBTNode *b);

LBTNode *CreateLBT1(char *pre, char *in, int n);
LBTNode *CreateLBT2(char *post, char *in, int n, int m);
