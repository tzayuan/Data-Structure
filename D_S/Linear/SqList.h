#pragma once
#include "pch.h"
typedef struct SqList{
	int data[MaxSize];
	int length;
}SqList;


SqList InitSqlist();//构造一个空的顺序表L,实际上只需要将length成员设置为0即可.
int GetElem(SqList L, int i, int &e);//用e返回L中第i个元素的值.
int LocateElem(SqList L, int e);//顺序查找第一个元素值等于e的元素的逻辑序号,若不存在则返回0.
int ListInsert(SqList &L, int i, int e);//在顺序表的第i个位置上插入新的元素e,若i不正确则返回0.
int ListDelete(SqList &L, int i, int &e);//删除顺序表L的第i个元素，若i不正确则返回0.
void Merge(SqList L1, SqList L2, SqList &L3);//有序顺序表的归并算法.
void DispSqlist(SqList L);
void SqListSort(SqList &L);
void MergeWithoutSort(SqList &L1, SqList L2);