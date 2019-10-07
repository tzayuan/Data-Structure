#pragma once //不加会导致pch.h和下面的struct两次定义结构体,导致重定义
#include "pch.h"
#include <cstdio>
#include <cstdlib>

//稳定性:定义：假定在待排序的记录序列中，存在多个具有相同的关键字的记录，
//	若经过排序，这些记录的相对次序保持不变，即在原序列中，r[i]=r[j]，且r[i]在r[j]之前，
//		而在排序后的序列中，r[i]仍在r[j]之前，则称这种排序算法是稳定的；
//	否则称为不稳定的。
//稳定的排序：直接插入排序、冒泡排序、归并排序
//不稳定的排序：希尔排序、直接选择排序、堆排序、快速排序

typedef int KeyType;
typedef char Sort_ElemType[10];
typedef struct Insort_SqList{
	KeyType key;
	Sort_ElemType data;
}InSort_SqList;

InSort_SqList* InitRandomSqList();//这里写的不好,用了static,对于结构体数组作为形参和返回结构体数组的问题理解上不够清晰,需要理清思路

void DispInitKey(InSort_SqList *R);

//内排序算法
	//基于交换思想的比较排序算法
void Bubble_Sort(InSort_SqList *R, int length);
void Quick_Sort(InSort_SqList *R, int s, int t);
	//基于插入思想的比较排序算法
void Insert_Sort(InSort_SqList *R, int length);
void Shell_Sort(InSort_SqList *R, int length);
	//基于选择思想的比较排序算法
void Select_Sort(InSort_SqList *R, int length);
void Sift(InSort_SqList *R, int low, int high);
void Heap_Sort(InSort_SqList *R, int length);
	//归并排序算法
void Merge(InSort_SqList *R, int low, int mid, int high);
void MergePass(InSort_SqList *R, int subLength, int length);
void MergeSort(InSort_SqList *R, int length);
	//基数排序算法
