#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include "SqList.h"
#include "DLinkList.h"

void CreateCDListR(DLinkList *&L, SqList L1, int n);//2019年8月8日 22:09:44
int FindCDListNode(DLinkList *L, int x);//2019年8月8日 22:08:28
void CDListInsert(DLinkList *&L, int x, int n);//2019年8月8日 22:21:02
void CDListDelete(DLinkList *&L, int n);
void DispCDLinkList(DLinkList *L);//2019年8月8日 22:09:46