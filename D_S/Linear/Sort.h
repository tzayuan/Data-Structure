#pragma once //���ӻᵼ��pch.h�������struct���ζ���ṹ��,�����ض���
#include "pch.h"
#include <cstdio>
#include <cstdlib>

typedef int KeyType;
typedef char Sort_ElemType[10];
typedef struct{
	KeyType key;
	Sort_ElemType data;
}InSort_SqList;

InSort_SqList* InitRandomSqList();//����д�Ĳ���,����static,���ڽṹ��������Ϊ�βκͷ��ؽṹ���������������ϲ�������,��Ҫ����˼·

void DispInitKey(InSort_SqList *R);

void Bubble_Sort(InSort_SqList *R, int length);