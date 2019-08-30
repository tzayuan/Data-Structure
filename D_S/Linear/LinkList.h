#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include "SqList.h"
typedef struct LNode {
	int data;
	struct LNode* next;
}LinkList;//2019��7��24�� 21:27:26

void CreateListF(LinkList *& L, SqList L1, int n);//2019��7��24�� 21:43:09
void CreateListR(LinkList *& L, SqList L1, int n);//2019��7��25�� 21:27:13
int LocateElem(LinkList *L, int e);//2019��7��25�� 21:30:44
void InsertElem(LinkList *& L, int x, int i);//��Ϊ��������һ������������һ�����,���ͷ���ָ������ܻᱻ�޸�;//�ѿ��ǲ���λ�ò��Ե����(2019��7��25�� 22:40:45);//2019��7��25�� 21:36:09
void DispLinkList(LinkList *L);//2019��7��25�� 22:50:32
void DeleteNode(LinkList *& L, int i);//2019��7��25�� 22:50:27
void MergeLinkList(LinkList *L1, LinkList *L2, LinkList *&L3);//2019��7��26�� 22:08:02