#include "pch.h"
#include "CirculatingDLinkList.h"

void CreateCDListR(DLinkList *& L, SqList L1, int n) {
	DLinkList *r, *s;
	L = (DLinkList *)malloc(sizeof(DLinkList));
	L->next = NULL;
	r = L;
	for (int i = 0; i < L1.length; i++) {
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = L1.data[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
	L->prior = r;
}

int FindCDListNode(DLinkList * L, int x) {
	DLinkList *p = L->next;
	int n = 1;
	while (p != L && p->data != x) {
		p = p->next;
		n++;
	}
	if (p == L) return 0;
	else return n;
}

void CDListInsert(DLinkList *& L, int x, int n) {
	DLinkList *p = L->next, *q = L, *s;
	int j = n - 1;
	while (j-- && p != L) {
		p = p->next;
		q = q->next;
	}
	if (j != -1) return;
	else {//第一次写时写成了p,应该用q,q指向的结点为要插入位置的前驱位置
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = x;
		s->next = q->next;
		q->next->prior = s;
		q->next = s;
		s->prior = q;
	}
}

void CDListDelete(DLinkList *& L, int n) {
	DLinkList *p = L->next, *q = L, *temp;
	int j = n - 1;
	while (j-- && p != L) {
		p = p->next;
		q = q->next;
	}
	if (p == L) {
		printf_s("The deleted number is wrong!\n");
		return;
	}
	else {
		temp = q->next;
		q->next = q->next->next;
		q->next->next->prior = q;
		free(temp);
	}
}

void DispCDLinkList(DLinkList * L) {
	DLinkList *p = L->next;
	int n = 0;
	printf_s("The CirculatingDoubleLinkedList is : ");
	while (p != L) {
		printf_s("%3d ", p->data);
		p = p->next;
		n++;
	}
	printf_s("\n");
	printf_s("The length of CirculatingDoubleLinkedList is :%d", n);
	printf_s("\n");
}
