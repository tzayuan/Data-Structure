#pragma once //���ӻᵼ��pch.h�������struct���ζ���ṹ��,�����ض���
#include "pch.h"
#include <cstdio>
#include <cstdlib>

//�ȶ���:���壺�ٶ��ڴ�����ļ�¼�����У����ڶ��������ͬ�Ĺؼ��ֵļ�¼��
//	������������Щ��¼����Դ��򱣳ֲ��䣬����ԭ�����У�r[i]=r[j]����r[i]��r[j]֮ǰ��
//		���������������У�r[i]����r[j]֮ǰ��������������㷨���ȶ��ģ�
//	�����Ϊ���ȶ��ġ�
//�ȶ�������ֱ�Ӳ�������ð�����򡢹鲢����
//���ȶ�������ϣ������ֱ��ѡ�����򡢶����򡢿�������

typedef int KeyType;
typedef char Sort_ElemType[10];
typedef struct Insort_SqList{
	KeyType key;
	Sort_ElemType data;
}InSort_SqList;

InSort_SqList* InitRandomSqList();//����д�Ĳ���,����static,���ڽṹ��������Ϊ�βκͷ��ؽṹ���������������ϲ�������,��Ҫ����˼·

void DispInitKey(InSort_SqList *R);

//�������㷨
	//���ڽ���˼��ıȽ������㷨
void Bubble_Sort(InSort_SqList *R, int length);
void Quick_Sort(InSort_SqList *R, int s, int t);
	//���ڲ���˼��ıȽ������㷨
void Insert_Sort(InSort_SqList *R, int length);
void Shell_Sort(InSort_SqList *R, int length);
	//����ѡ��˼��ıȽ������㷨
void Select_Sort(InSort_SqList *R, int length);
void Sift(InSort_SqList *R, int low, int high);
void Heap_Sort(InSort_SqList *R, int length);
	//�鲢�����㷨
void Merge(InSort_SqList *R, int low, int mid, int high);
void MergePass(InSort_SqList *R, int subLength, int length);
void MergeSort(InSort_SqList *R, int length);
	//���������㷨
