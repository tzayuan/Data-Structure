#include "pch.h"
#include "LinkStack.h"

void InitLStack(LStackNode *& lst) {
	lst = (LStackNode *)malloc(sizeof(LStackNode));
	lst->next = NULL;
}

int isEmptyLStack(LStackNode * lst) {
	return (lst->next == NULL);//带头结点
}

void pushLStack(LStackNode *& lst, int x) {
	LStackNode *p;
	p = (LStackNode *)malloc(sizeof(LStackNode));
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}

int popLStack(LStackNode *& lst, int & x) {
	if (lst->next == NULL) return 0;
	LStackNode *p;
	p = lst->next;
	lst->next = p->next;
	x = p->data;
	free(p);
	return 1;
}

void InitLStackWithoutHead(LStackNode *& lst) {
	lst = NULL;
}

int isEmptyLStackWithoutHead(LStackNode * lst) {
	return (lst == NULL);
}

void pushLStackWithoutHead(LStackNode *& lst, int x) {
	LStackNode *p;
	p = (LStackNode *)malloc(sizeof(LStackNode));
	p->data = x;
	p->next = lst;
	lst = p;
}

int popLStackWithoutHead(LStackNode *& lst, int & x) {
	if (NULL == lst) return 0;
	else {
		LStackNode *p;
		p = lst;
		x = p->data;//第一次写时忘记加了
		lst = p->next;
		free(p);
		return 1;
	}
}
