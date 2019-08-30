#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include "SqList.h"
#include "LinkList.h"

void CreateCListR(LinkList *&L, SqList L1, int n);//2019年8月8日 20:13:35
int FindCListNode(LinkList *L, int x);//2019年8月8日 20:16:30
void CListInsert(LinkList *&L, int x, int n);//2019年8月8日 20:31:24
void CListDelete(LinkList *&L, int n);//2019年8月8日 21:27:33
void DispCLinkList(LinkList *L);//2019年8月8日 20:53:21