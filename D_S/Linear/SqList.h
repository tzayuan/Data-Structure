#pragma once
#include "pch.h"
typedef struct SqList{
	int data[MaxSize];
	int length;
}SqList;


SqList InitSqlist();//����һ���յ�˳���L,ʵ����ֻ��Ҫ��length��Ա����Ϊ0����.
int GetElem(SqList L, int i, int &e);//��e����L�е�i��Ԫ�ص�ֵ.
int LocateElem(SqList L, int e);//˳����ҵ�һ��Ԫ��ֵ����e��Ԫ�ص��߼����,���������򷵻�0.
int ListInsert(SqList &L, int i, int e);//��˳���ĵ�i��λ���ϲ����µ�Ԫ��e,��i����ȷ�򷵻�0.
int ListDelete(SqList &L, int i, int &e);//ɾ��˳���L�ĵ�i��Ԫ�أ���i����ȷ�򷵻�0.
void Merge(SqList L1, SqList L2, SqList &L3);//����˳���Ĺ鲢�㷨.
void DispSqlist(SqList L);
void SqListSort(SqList &L);
void MergeWithoutSort(SqList &L1, SqList L2);