#pragma once
#include "pch.h"

//
//������������:�ǿն�������Ҷ�ӽ��������˫��֧�������1;

//��������˳��洢�ṹ
typedef int SBTree[MaxSize];

//����������ʽ�洢�ṹ
typedef struct node {
	char data;
	struct node *lchild;
	struct node *rchild;
}LBTNode;

//��������������ʽ�洢�ṹ
typedef struct node {
	char data;//���������
	int ltag, rtag;//���ӵ��������
	struct node *lchild;//���ӻ�����ָ��(ָ��ǰ�����)
	struct node *rchild;//�Һ��ӻ�����ָ��(ָ�����̽��)
}TBTNode;//������������Ͷ���

//��������haffman tree
typedef struct {
	int data;//���ֵ
	float weight;//Ȩ��
	int parent;//˫�׽��
	int lchild;//���ӽ��
	int rchild;//�Һ��ӽ��
}HTNode;
//�������Ļ����㷨,�ǵݹ��㷨��δ����,�漰"����ջ�����ݹ�"һ��
//ǰ�����,�������,��������ĵݹ��㷨���ǵݹ��㷨
void PreOrder(LBTNode *b);//2019��9��11�� 20:20:16
void PreOrder1(LBTNode *b);//2019��9��11�� 20:26:17
void InOrder(LBTNode *b);//2019��9��11�� 20:51:59
void InOrder1(LBTNode *b);//2019��9��11�� 21:23:27
void PostOrder(LBTNode *b);//2019��9��11�� 21:25:20
void PostOrder1(LBTNode *b);//2019��9��11�� 21:48:01
void CreateLBTNode(LBTNode *&b, char *str);//2019��9��11�� 22:17:05

LBTNode *FindNode(LBTNode *b, int x);//2019��9��12�� 21:29:44
LBTNode *LchildNode(LBTNode *b);//2019��9��12�� 21:31:41
LBTNode *RchildNode(LBTNode *b);//2019��9��12�� 21:33:19
int LBTNodeDepth(LBTNode *b);//2019��9��12�� 21:43:56
void DispLBTNode(LBTNode *b);

LBTNode *CreateLBT1(char *pre, char *in, int n);
LBTNode *CreateLBT2(char *post, char *in, int n, int m);
