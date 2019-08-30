#include "pch.h"
#include "DLinkList.h"

void CreateDListR(DLinkList *& L, SqList L1, int n) {
	DLinkList *s, *r;
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
	r->next = NULL;
}

void CreateDListR_2412(DLinkList_2412 *& L, SqList L1, int n) {
	DLinkList_2412 *s, *r;
	L = (DLinkList_2412 *)malloc(sizeof(DLinkList_2412));
	L->next = NULL;
	r = L;
	for (int i = 0; i < L1.length; i++) {
		s = (DLinkList_2412 *)malloc(sizeof(DLinkList_2412));
		s->data = L1.data[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

int findNode(DLinkList * L, int x) {
	DLinkList *p = L->next;
	int i = 1;
	while (p != NULL && p->data != x) {//要把 p != NULL 写在前面,否则当p == NULL时 先判断p->data 出现 NULL 异常.
		i++;
		p = p->next;
	}
	if (p != NULL) return i;
	else return 0;
}

int DLinkListInsert(DLinkList *& L, int i, int x) {
	DLinkList *p = L, *s;
	int j = i - 1;
	while (j != 0 && p != NULL) {
		p = p->next;
		j--;
	}
	if (p == NULL) return 0;
	s = (DLinkList *)malloc(sizeof(DLinkList));
	s->data = x;
	s->next = p->next;
	if(p->next != NULL) p->next->prior = s;
	s->prior = p;
	p->next = s;
	return 1;
}

void DispDLinkList(DLinkList * L) {
	int n = 0;
	DLinkList *p = L->next;
	printf_s("DLinkedList is  :");
	while (p != NULL) {
		printf_s("%3d ", p->data);
		n++;
		p = p->next;
	}
	printf_s("\n");
	printf_s("The length is : %d", n);
	printf_s("\n");
}

void DispDLinkList_2412(DLinkList_2412 * L) {
	int n = 0;
	DLinkList_2412 *p = L->next;
	printf_s("DLinkedList is  :");
	while (p != NULL) {
		printf_s("%3d ", p->data);
		n++;
		p = p->next;
	}
	printf_s("\n");
	printf_s("The length is : %d", n);
	printf_s("\n");
}

int DListDeleteNode(DLinkList *& L, int i) {
	DLinkList *p = L, *q;
	int j = i - 1;
	while (j != 0 && p != NULL) {
		p = p->next;
		j--;
	}
	if (p == NULL) return 0;
	q = p->next;
	if(q == NULL) return 0;
	if (q->next != NULL) q->next->prior = p;
	p->next = q->next;
	free(q);
	return 1;
}

void deleteDuplicateNode(DLinkList_2412 *& L) {
	DLinkList_2412 *p = L->next, *q, *qTemp;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			while (q != NULL && q->data != p->data) {
				q = q->next;
			}
			while (q != NULL && q->data == p->data) {
				qTemp = q;
				q = q->next;//第一次写时这句放在了free(qTemp)之后,则无效.
				qTemp->prior->next = qTemp->next;
				if (qTemp->next != NULL) qTemp->next->prior = qTemp->prior;
				free(qTemp);
			}
		}
		p = p->next;
	}
}
