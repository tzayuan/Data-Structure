#pragma once //不加会导致pch.h和下面的struct两次定义结构体,导致重定义
#include "pch.h"
#include <cstdio>
#include <cstdlib>

typedef int KeyType;
typedef char Sort_ElemType[10];
typedef struct{
	KeyType key;
	Sort_ElemType data;
}InSort_SqList;

InSort_SqList* InitRandomSqList();//这里写的不好,用了static,对于结构体数组作为形参和返回结构体数组的问题理解上不够清晰,需要理清思路

void DispInitKey(InSort_SqList *R);

void Bubble_Sort(InSort_SqList *R, int length);