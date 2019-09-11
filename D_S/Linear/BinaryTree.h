#pragma once
#include "pch.h"

//
//������������:�ǿն�������Ҷ�ӽ��������˫��֧�������1;

//��������˳��洢�ṹ
typedef int SBTree[MaxSize];

//����������ʽ�洢�ṹ
typedef struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
}LBTNode;

//�������Ļ����㷨
void PreOrder(LBTNode *b);//2019��9��11�� 20:20:16
void PreOrder1(LBTNode *b);//2019��9��11�� 20:26:17
void InOrder(LBTNode *b);//2019��9��11�� 20:51:59
void InOrder1(LBTNode *b);//2019��9��11�� 21:23:27
void PostOrder(LBTNode *b);//2019��9��11�� 21:25:20
void PostOrder1(LBTNode *b);//2019��9��11�� 21:48:01
void CreateLBTNode(LBTNode *&b, char *str);//2019��9��11�� 22:17:05