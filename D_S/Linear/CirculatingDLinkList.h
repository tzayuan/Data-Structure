#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include "SqList.h"
#include "DLinkList.h"

void CreateCDListR(DLinkList *&L, SqList L1, int n);//2019��8��8�� 22:09:44
int FindCDListNode(DLinkList *L, int x);//2019��8��8�� 22:08:28
void CDListInsert(DLinkList *&L, int x, int n);//2019��8��8�� 22:21:02
void CDListDelete(DLinkList *&L, int n);
void DispCDLinkList(DLinkList *L);//2019��8��8�� 22:09:46