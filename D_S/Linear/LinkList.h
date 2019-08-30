#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include "SqList.h"
typedef struct LNode {
	int data;
	struct LNode* next;
}LinkList;//2019年7月24日 21:27:26

void CreateListF(LinkList *& L, SqList L1, int n);//2019年7月24日 21:43:09
void CreateListR(LinkList *& L, SqList L1, int n);//2019年7月25日 21:27:13
int LocateElem(LinkList *L, int e);//2019年7月25日 21:30:44
void InsertElem(LinkList *& L, int x, int i);//因为可能是在一个空链表插入第一个结点,因此头结点指针域可能会被修改;//已考虑插入位置不对的情况(2019年7月25日 22:40:45);//2019年7月25日 21:36:09
void DispLinkList(LinkList *L);//2019年7月25日 22:50:32
void DeleteNode(LinkList *& L, int i);//2019年7月25日 22:50:27
void MergeLinkList(LinkList *L1, LinkList *L2, LinkList *&L3);//2019年7月26日 22:08:02