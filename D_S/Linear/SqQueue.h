#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>

//顺序队中，通常让队尾指针rear指向刚进队的元素位置,队头指针front指向刚出队的元素位置,即队首元素的前一个位置
//假溢出: 若采用qu.rear == MaxSize - 1 或 qu.front == MaxSize - 1作为队满条件,就会出现"假溢出",即该条件为真时队列仍可能存在可存放元素的空间.
//为解决假溢出问题,采用环形队列的方式,队列的基本要素如下:
//	队空条件: qu.front == qu.rear
//	队满条件: (qu.rear + 1) % MaxSize == qu.front
//	元素x进队操作(需移动队尾指针): qu.rear = (qu.rear + 1) % MaxSize; qu.data[qu.rear] = x;
//	出队x操作(需移动队首指针): qu.front = (qu.front + 1) % MaxSize; x = qu.data[qu.front];
//注意: 为了区别队空和队满,在上述环形队列中最多只能存放MaxSize - 1 个元素
typedef struct SqQueue {
	int data[MaxSize];
	int front, rear;
}SqQueue;

void initSqQueue(SqQueue &qu);
int enQueue(SqQueue &qu, int x);
int deQueue(SqQueue &qu, int &x);
int isEmptyQueue(SqQueue qu);
int isFullQueue(SqQueue qu);


//对于顺序队来说,如果知道队首元素的位置和队列中元素个数,则队尾元素所在位置显然是可以计算的.也就是说,可以用队列中元素个数代替队尾指针,设计出这种环形顺序队的初始化、入队、出队和判空算法.
//	当已知队首元素的位置front和队列中元素个数count后,队列的基本要素如下:
//		队空的条件:count == 0;
//		队满的条件:count == MaxSize
//		计算队尾位置: rear = (front + count) % MaxSize
typedef struct {
	int data[MaxSize];
	int front;
	int count;
}QuType;

void initSqQueue_2(QuType &qu);
int isEmptyQueue_2(QuType qu);
int isFullQueue_2(QuType qu);
void headQueue_2(QuType &qu, int &x);
int EnQueue_2(QuType &qu, int x);//与课本写法有不同,对课本写法的正确性存在疑义.
int DeQueue_2(QuType &qu, int &x);


//设计一个环形队列,用front和rear分别作为队头和队尾指针,另外用一个标志tag表示队列是空(0)还是不空(1),这样就可以用front==rear作为队满的条件.要求设计队列的相关基本运算算法.
//	初始时tag = 0,进行成功的插入操作后tag = 1,进行成功的删除操作后tag = 0;因为只有在插入操作后队列才有可能满,在删除操作后队列才有可能空,因此,这样的队列的基本要素如下:
//		初始时:tag = 0, front = rear
//		队空条件:qu.front == qu.rear && tag == 0
//		队满条件:qu.front == qu.rear && tag == 1
typedef struct {
	int data[MaxSize];
	int front, rear;
	int tag;
}QuType_2;

void initSqQueue_3(QuType_2 &qu);
int isEmptyQueue_3(QuType_2 qu);
int isFullQueue_3(QuType_2 qu);
int EnQueue_3(QuType_2 &qu, int x);
int DeQueue_3(QuType_2 &qu, int &x);

//采用队列求解迷宫问题
//*