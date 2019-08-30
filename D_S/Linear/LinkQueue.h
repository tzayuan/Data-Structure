#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
//(!!!!!)lqu.front == lqu.rear == NULL的写法是错误的,==只能判断两者是否相等,若上述的三者,则需要改写为lqu.front == NULL && lqu.rear == NULL

typedef struct qNode{
	int data;
	struct qNode *next;
}LQNode;
//与基于单链表的存储结构的栈(逻辑结构)相比，栈这一逻辑结构只允许在栈顶进行操作,以头插法进行进栈,退栈时取出首个数据元素,所有操作都是对首个数据结点进行的,因此只需要头结点的指针即可O(1)完成栈在逻辑上所限定的相关操作,
//而队列这一逻辑结构决定了需要频繁的在链表的两头进行操作,即首个数据结点和尾结点,而链表若不设置尾结点指针,就需要从头结点遍历至尾结点,意味着每次入队都需要进行时间复杂度为O(n)的扫描至尾结点处的操作,
//因此对于基于单链表存储结构的循环队列这一逻辑结构,在定义了每一个单链表结点的结构体数据类型后,需要对整个链表再进行一次结构体类型定义,即包含有该链表的首个数据结点和尾结点,以高效的完成队列这一逻辑结构的相关算法操作
typedef struct LinkQueue{
	LQNode *front;//front指向第一个数据结点,而不是头结点
	LQNode *rear;
}LinkQueue;

//链队lqu的4个元素如下:
//	队列空条件:NULL == lqu->front或NULL == lqu->rear;
//	队列满条件:一般不存在队列满的情况
//	元素*p进队操作:lqu->rear->next = p; lqu->rear = p;
//	出队列操作:p = lqu->front; lqu->front = p->next; x = p->data; free(p);//头结点到第一个数据结点的链路不考虑???事实上没有头结点,而是有一个front直接指向第一个数据结点,rear直接指向尾结点
void initLinkQueue(LinkQueue *&lqu);
int isEmptyLinkQueue(LinkQueue *lqu);
//int isFullLinkQueue(LinkQueue *lqu);//一般不存在队满情况
void EnLinkQueue(LinkQueue *&lqu, int x);
int DeLinkQueue(LinkQueue *&lqu, int &x);

//P127, 例4-3-11, 假设用一个循环单链表表示队列,并且只设一个指针rear指向队尾结点,但不设头指针,设计出响应的队初始化、入队、出队和判空队的算法.
//解法一:假设链队是不带头结点的循环单链表,则基本要素如下:
//	队空条件:lqu.front == lqu.rear == NULL;
//	入队:在rear结点之后插入结点并将rear指向该结点
//	出队:删除rear结点之后的第一个结点.
//相应的算法如下:
void initCLinkQueue(LQNode *&rear);
int isEmptyCLinkQueue(LQNode *rear);
void EnCLinkQueue(LQNode *&rear, int x);
int DeCLinkQueue(LQNode *&rear, int &x);
//P127, 例4-3-11, 假设用一个循环单链表表示队列,并且只设一个指针rear指向队尾结点,但不设头指针,设计出响应的队初始化、入队、出队和判空队的算法.
//解法二:假设链队是带头结点的循环单链表,则基本要素如下:
//	队空条件:rear.next == rear
//	入队:在rear结点之后插入结点并让rear指向该结点
//	出队:删除rear->next之后的第一个结点
void initCLinkQueueWithHead(LQNode *&rear);
int isEmptyCLinkQueueWithHead(LQNode *rear);
void EnCLinkQueueWithHead(LQNode *&rear, int x);
int DeCLinkQueueWithHead(LQNode *&rear, int &x);