#include "pch.h"
#include "SqList.h"
#include <cstdio>
#include <iostream>
#pragma once
SqList InitSqlist() {
	SqList L;
	L.length = 0;
	return L;
}

int GetElem(SqList L, int i, int &e) {
	if (i < 0 || i > L.length) return 0;
	e = L.data[i - 1];
	return 1;
}

int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) return i + 1;
	}
	return 0;
}
/*
int LocateElem(SqList L, int e) {
	int i = 0;
	while (i < L.length && L.data[i] != e) i++;
	if (i >= L.length) return 0;
	else return i + 1;
}*/

int ListInsert(SqList & L, int i, int e)
{
	if (i < 1 || i > L.length + 1) return 0;//调用时以为i是顺序表的下标,结果循环添加20个数,只有19个,虽然少了一个,但是这句判断显然规避了错误,其作用便在此.
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.data[j + 1] = L.data[j];
	}
	L.data[i - 1] = e;
	L.length++;
	return 1;
}

int ListDelete(SqList & L, int i, int & e)
{
	if(i < 1 || i > L.length) return 0;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return 1;
}

void Merge(SqList L1, SqList L2, SqList & L3) {
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] < L2.data[j]) {
			L3.data[k++] = L1.data[i++];
		} else if (L1.data[i] > L2.data[j]) {
			L3.data[k++] = L2.data[j];
	    } else if (L1.data[i] == L2.data[j]) {
			L3.data[k++] = L1.data[i++];
			j++;
		}
	}
}

void DispSqlist(SqList L) {
	printf_s("The SqList   is :");
	for(int i = 0; i < L.length; i++) {
		printf_s("%3d ", L.data[i]);
	}
	printf_s("\n");
	printf_s("The Length is : %d", L.length);
	printf_s("\n");
}

void SqListSort(SqList &L) {
	//王道 P287 冒泡排序;
	int i, j;
	bool flag;
	for (i = 0; i < L.length - 1; i++) {
		flag = false;
		for (j = L.length - 1; j > i; j--) {
			if (L.data[j - 1] > L.data[j]) {
				int temp;
				temp = L.data[j - 1];
				L.data[j - 1] = L.data[j];
				L.data[j] = temp;
				flag = true;
			}
		}
		if (flag == false) return;
		//printf_s("L1.data[%d]=%d\n", i, L.data[i]);
	}
	/*
	//2019年7月19日 21:31:25 自己写排序没写出来...
	int minNum = 99999, i, j;
	SqList L1 = InitSqlist();
	for (i = 0; i < L.length; i++) {
		for (j = i; j < L.length; j++) {
			if (L.data[j] < minNum) minNum = L.data[j];
		}
		L1.data[i] = minNum;
		printf_s("L1.data[%d]=%d\n", i, L1.data[i]);
		L1.length++;
		minNum = 99999;
	}
	DispSqlist(L1);
	return L1;
	*/
}

void MergeWithoutSort(SqList & L1, SqList L2) {
	for (int i = 0; i < L2.length; i++) {
		ListInsert(L1, L1.length + 1, L2.data[i]);
	}
}