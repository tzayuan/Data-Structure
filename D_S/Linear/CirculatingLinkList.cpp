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
		r = s;//��һ��дʱ����д��;
	}
	r->next = L;//��һ��дʱд����r->next = NULL;
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
	if (p == L) {//��һ��д����j != -1,�������������:ɾ��λ��Ϊ�����+1ʱ,��ʱqָ��β���, j == -1, p == L,�����else,temp = L, ��ͷ����ͷŵ���.
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