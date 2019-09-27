#include "pch.h"
#include "Sort.h"

InSort_SqList* InitRandomSqList() {
	static InSort_SqList R[Sort_MAXITEM];//����static�Ļ�ֻ�᷵�ص�һ����ֵ
	for (int i = 0; i < Sort_MAXITEM; i++) {
		int j = random(100);
		R[i].key = j;
	}
	InSort_SqList *RR = R;
	return RR;
}

void DispInitKey(InSort_SqList *R) {
	for (int i = 0; i < Sort_MAXITEM; i++) {
		printf_s("%3d ", R[i].key);
	}
	printf_s("\n");
}

void Bubble_Sort(InSort_SqList *R, int length) {
	int flag, temp;
	for (int i = 0; i < length - 1; i++) {
		flag = 0;
		for (int j = 0; j < length - i - 1; j++) {//ÿһ��ʹ������Ԫ�������Ҷ�;
			if (R[j].key > R[j + 1].key) {
				flag = 1;
				temp = R[j].key;
				R[j].key = R[j + 1].key;
				R[j + 1].key = temp;
			}
		}
		if (flag == 0) return;
	}
	return;
}