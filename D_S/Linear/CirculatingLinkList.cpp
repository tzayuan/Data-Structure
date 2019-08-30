#include "pch.h"
#include "CirculatingLinkList.h"

void CreateCListR(LinkList *& L, SqList L1, int n) {
	L = (LinkList *)malloc(sizeof(LinkList));
	LinkList *s, *r = L;
	r->next = NULL;
	for (int i = 0; i < L1.length; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = L1.data[i];
		r->next = s;
		r = s;//第一次写时忘记写了;
	}
	r->next = L;//第一次写时写成了r->next = NULL;
}

int FindCListNode(LinkList * L, int x) {
	LinkList *p = L->next;
	int n = 1;
	while (p != L && p->data != x) {
		p = p->next;
		n++;
	}
	if (p == L) return 0;
	else return n;
}

void CListInsert(LinkList *& L, int x, int n) {
	LinkList *p = L->next, *q = L, *s;
	int j = n - 1;
	while ((j--) && p != L) {
		q = q->next;
		p = p->next;
	}
	if (j != -1) {
		printf_s("The inserted position is wrong!\n");
		return;
	}
	else {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = x;
		s->next = q->next;
		q->next = s;
	}
}

void CListDelete(LinkList *& L, int n) {
	LinkList *p = L->next, *q = L, *temp;
	int j = n - 1;
	while ((j--) && p != L) {
		p = p->next;
		q = q->next;
	}
	if (p == L) {//第一次写成了j != -1,特殊情况出问题:删除位置为结点数+1时,此时q指向尾结点, j == -1, p == L,则进入else,temp = L, 将头结点释放掉了.
		printf_s("The deleted position is wrong!\n");
		return;
	}
	else {
		temp = q->next;
		q->next = q->next->next;
		free(temp);
	}

}

void DispCLinkList(LinkList * L) {
	LinkList *p = L->next;
	int n = 0;
	printf_s("The CirculatingLinkList is:");
	while (p != L) {
		printf_s("%3d ", p->data);
		p = p->next;
		n++;
	}
	printf_s("\n");
	printf_s("The length of circulatingLinkList is : %d", n);
	printf_s("\n");
}