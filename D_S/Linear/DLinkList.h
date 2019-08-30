#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include "SqList.h"

typedef struct DLinkList {
	int data;
	struct DLinkList *prior;
	struct DLinkList *next;
}DLinkList;

typedef struct DLinkList_2412 {
	int data;
	struct DLinkList_2412 *prior;
	struct DLinkList_2412 *next;
	int freq = 0;
}DLinkList_2412;

void CreateDListR(DLinkList *&L, SqList L1, int n);//2019年8月5日 21:01:20
void CreateDListR_2412(DLinkList_2412 *&L, SqList L1, int n);//2019年8月6日 22:20:42
int findNode(DLinkList *L, int x);//2019年8月5日 21:04:04
int DLinkListInsert(DLinkList *&L, int i, int x);//2019年8月5日 21:16:17
void DispDLinkList(DLinkList *L);//2019年8月5日 21:37:51
void DispDLinkList_2412(DLinkList_2412 *L);
int DListDeleteNode(DLinkList *&L, int i);
void deleteDuplicateNode(DLinkList_2412 *&L);//2019年8月7日 22:15:11