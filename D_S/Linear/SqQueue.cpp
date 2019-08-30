#include "pch.h"
#include "SqQueue.h"

void initSqQueue(SqQueue & qu) {
	qu.front = qu.rear = 0;
}

int enQueue(SqQueue & qu, int x) {
	if ((qu.rear + 1) % MaxSize == qu.front) return 0;
	qu.rear = (qu.rear + 1) % MaxSize;
	qu.data[qu.rear] = x;
	return 1;
}

int deQueue(SqQueue & qu, int & x) {
	if (qu.rear == qu.front) return 0;
	qu.front = (qu.front + 1) % MaxSize;
	x = qu.data[qu.front];
	return 1;
}

int isEmptyQueue(SqQueue qu) {
	return (qu.rear == qu.front);
}

int isFullQueue(SqQueue qu) {
	return ((qu.rear + 1) % MaxSize == qu.front);
}

void initSqQueue_2(QuType & qu) {
	qu.front = -1;
	qu.count = 0;
}

int isEmptyQueue_2(QuType qu) {
	if (qu.count == 0) return 1;
	else return 0;
}

int isFullQueue_2(QuType qu) {
	if (qu.count == MaxSize) return 1;
	else return 0;
}

void headQueue_2(QuType & qu, int & x) {
	if (qu.count == 0) return;
	x = qu.data[qu.front + 1];
}

int EnQueue_2(QuType & qu, int x) {
	if (qu.count == MaxSize) return 0;
	int rear = (qu.front + qu.count) % MaxSize;
	rear++;
	qu.data[rear] = x;
	qu.count++;
	return 1;
}

int DeQueue_2(QuType & qu, int & x) {
	if (qu.count == 0) return 0;
	qu.front = (qu.front + 1) % MaxSize;//小技巧:只要遇到front+1或者rear+1的地方,就需要对MaxSize取余
	x = qu.data[qu.front];
	qu.count--;
	return 1;
}

void initSqQueue_3(QuType_2 & qu) {
	qu.front = qu.rear = 0;
	qu.tag = 0;
}

int isEmptyQueue_3(QuType_2 qu) {
	return (qu.front == qu.rear && qu.tag == 0);
}

int isFullQueue_3(QuType_2 qu) {
	return (qu.rear == qu.front && qu.tag == 1);
}

int EnQueue_3(QuType_2 & qu, int x) {
	if (qu.front == qu.rear && qu.tag == 1) return 0;//tag==1意味着队列中有元素,加之front==rear意味着有元素的极端情况,即队列为满状态
	qu.rear = (qu.rear + 1) % MaxSize;//又忘记了小技巧:对于队列,凡是需要+1的地方就需要对MaxSize取余数
	qu.data[qu.rear] = x;
	qu.tag = 1;//理解为tag = 1表示为可出队的必要条件之一
	return 1;
}

int DeQueue_3(QuType_2 & qu, int & x) {
	if (qu.front == qu.rear && qu.tag == 0) return 0;//tag==0意味着队列队列不满,仍然有空位,加之front==rear意味着队列不满的极端情况,即队列为空状态
	qu.front = (qu.front + 1) % MaxSize;//第一次写时写成了==,由编译器检查出错误:未使用表达式结果
	x = qu.data[qu.front];
	//if (qu.front == qu.rear) //每次出队不加if判断而是每次都让tag = 0?因为只有入队才有可能使得队列满//或者将tag=0理解为有剩余可入队的空位,而不是完全空
	qu.tag = 0;//理解为tag = 0 表示队列不满,可入队的必要条件之一,加之front==rear可以作为队列空的充要条件.
	return 1;
}
