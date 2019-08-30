#include "pch.h"
#include "LinkQueue.h"

void initLinkQueue(LinkQueue *& lqu) {
	lqu = (LinkQueue *)malloc(sizeof(LinkQueue));
	lqu->front = lqu->rear = NULL;
}

int isEmptyLinkQueue(LinkQueue * lqu) {
	return (lqu->front == NULL);//书上只判断了rear为NULL,是否有区别？
}

void EnLinkQueue(LinkQueue *& lqu, int x) {
	LQNode *p = (LQNode *)malloc(sizeof(qNode));
	p->data = x;
	p->next = NULL;
	if (lqu->front == lqu->rear == NULL) lqu->front = lqu->rear = p;
	else {
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

int DeLinkQueue(LinkQueue *& lqu, int & x) {
	if (lqu->front == NULL) return 0;
	LQNode *p = lqu->front;
	if (lqu->front == lqu->rear) lqu->front = lqu->rear = NULL;
	else lqu->front = p->next;
	x = p->data;
	free(p);
	return 1;
}

void initCLinkQueue(LQNode *& rear) {
	rear = NULL;
}

int isEmptyCLinkQueue(LQNode * rear) {
	return (rear == NULL);
}

void EnCLinkQueue(LQNode *& rear, int x) {
	LQNode *p = (LQNode *)malloc(sizeof(LQNode));
	p->data = x;
	if (rear == NULL) {//第一次写时未考虑队空状况
		p->next = p;
		rear = p;
	}
	else {
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
}

int DeCLinkQueue(LQNode *& rear, int & x) {
	if (rear == NULL) return 0;
	LQNode *p;
	if (rear->next == rear) {
		p = rear;
		rear = NULL;
		free(p);
	}
	else {
		p = rear->next;
		x = p->data;
		rear->next = p->next;
		free(p);
	}
	return 1;
}

void initCLinkQueueWithHead(LQNode *& rear) {
	rear = (LQNode *)malloc(sizeof(LQNode));//即rear此时为头结点
	rear->next = rear;
}

int isEmptyCLinkQueueWithHead(LQNode * rear) {
	return (rear->next == rear);//链表只有一个rear结点时,rear结点作为头结点,则该队列为空队.
}

void EnCLinkQueueWithHead(LQNode *& rear, int x) {
	//空队时,rear为头结点,rear同其他一般性的数据结点一致,均具有后继指针指向其后继元素,而其后继指针比较特殊,指向其自身
	//因此新结点的插入与队列是否为空无关,操作均为新结点指向rear的后继结点(即头结点),再让rear指向新插入的结点
	LQNode *p = (LQNode *)malloc(sizeof(LQNode));
	p->data = x;
	p->next = rear->next;
	rear->next = p;
	rear = p;
}

int DeCLinkQueueWithHead(LQNode *& rear, int &x) {
	if (rear->next == rear) return 0;
	LQNode *p;
	if (rear->next->next == rear) {
		p = rear;
		x = p->data;
		free(p);
		rear->next = rear;
	}
	else {
		p = rear->next->next;
		x = p->data;
		rear->next->next = p->next;//此处对答案有疑义,Page129//答案没问题,尾结点不动,仍然指向头结点(上面的if已经规避了只有队列中只有一个数据结点的情况),头结点指向队头的下一个数据结点
		free(p);
	}
	return 1;
}