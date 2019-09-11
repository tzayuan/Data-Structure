#include "pch.h"

#include "LinkList.h"

void CreateListF(LinkList *& L, SqList L1, int n) {
	//头插法建立单链表,从一个空表开始,读取顺序表a中的元素,生成新结点,将读取的数据存放到新结点的数据域中,然后将新结点插入到当前链表的表头上, 直到结束为止.
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));//创建头结点
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));//创建新结点
		s->data = L1.data[i];
		s->next = L->next;
		L->next = s;
	}
	/*
	//第一次写时理解错误写成了尾插,并且只记录了链尾的地址而没有记录链表的起始位置位置,即链头位置,且不带头结点.//2019年7月24日 21:27:19
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = L1.data[i];
		L->next = s;
	}
	L->next = NULL;
	*/
}

void CreateListR(LinkList *& L, SqList L1, int n) {
	LinkList *s, *r;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = L1.data[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int LocateElem(LinkList * L, int e) {
	LinkList *p = L->next;
	int n = 1;
	while (p != NULL && p->data != e) {
		p = p->next;
		n++;
	}
	if (p == NULL) return 0;
	else return n;
}

void InsertElem(LinkList *& L, int x, int i) {//因为可能是在一个空链表插入第一个结点,因此头结点指针域可能会被修改
	LinkList *s, *p = L;
	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = x;
	for (int j = 0; j < i - 1; j++) {//第一次写时int i = 0， 把传递进来的形式参数的值覆盖掉了;
		p = p->next;
		if (p->next == NULL && j != i - 2) {
			printf_s("Insert location is wrong!\n");
			return;
		};//考虑插入位置不对的情况
	}
	s->next = p->next;
	p->next = s;
}

void DispLinkList(LinkList * L) {
	if (L == NULL) {//2019年8月3日 21:22:57 为了应对例2-3-34删掉了所有结点(包括头结点)而加的判断语句
		printf_s("The LinkList is empty and have no head node.\n");
		return;
	}
	LinkList *p = L->next;
	int n = 0;
	printf_s("The LinkList is :");
	while (p != NULL) {
		printf_s("%3d ", p->data);//第一次写成了L->data;
		n++;
		p = p->next;
	}
	printf_s("\n");
	printf_s("The Length is : %d", n);
	printf_s("\n");
}

void DeleteNode(LinkList *& L, int i) {
	LinkList *s, *p = L;
	for (int j = 0; j < i - 1; j++) {
		p = p->next;
		if (p->next == NULL) {
			printf_s("Delete location is wrong!\n");
			return;
		}
	}
	s = p->next;
	p->next = s->next;
	free(s);
}

void MergeLinkList(LinkList * L1, LinkList * L2, LinkList *& L3) {
	//L1和L2合并在一个新的单链表L3中,两个指针p、q分别从L1和L2的第一个数据结点开始,只要p和q均未到尾部的NULL,就往后一个一个走,每次比较p和q所指向的数据结点的数据域数值大小,分为3种情况:
	//	1)p和q所指的数据结点的数据域数值相同,则L3中放置两个新结点,数据域均为当前p所指向数据结点的数据域的数值,然后p和q分别指向p和q的后继结点;
	//	2)p所指的数据结点的数据域数值小于q所指的数据结点的数据域数值,则L3中放置一个新结点,数据域为当前p所指向数据结点的数据域的数值,然后p指向p的后继结点;
	//	3)q所指的数据结点的数据域数值小于p所指的数据结点的数据域数值,则L3中放置一个新结点,数据域为当前q所指向数据结点的数据域的数值,然后q指向q的后继结点;
	//当p或q任意一个到达尾部的NULL,则进行判断,将未到达NULL的L1/L2依次将剩余结点添加到L3的尾部依次作为尾部元素.
	LinkList *p = L1->next, *q = L2->next, *t, *s;
	L3 = (LinkList *)malloc(sizeof(LinkList));
	L3->next = NULL;
	t = L3;
	while (p != NULL && q != NULL) {
		if (p->data == q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			p = p->next;
			q = q->next;
			s->next = t->next;//答案好像是放在了最后面加,前面加不加不影响
			t->next = s;
			t = s;
			//free(s);//加上这一句后异常混乱
			s = (LinkList *)malloc(sizeof(LinkList));//非常重要,不加就不对了;
			s->data = t->data;
			s->next = t->next;
			t->next = s;
			t = s;
		}
		else if (p->data < q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			p = p->next;
			s->next = t->next;
			t->next = s;
			t = s;
		}
		else {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = q->data;
			q = q->next;
			s->next = t->next;
			t->next = s;
			t = s;
		}
	}
	while (p != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = p->data;
		p = p->next;
		s->next = t->next;
		t->next = s;
		t = s;
	}
	while (q != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = q->data;
		q = q->next;
		s->next = t->next;
		t->next = s;
		t = s;
	}
	t->next = NULL;
}