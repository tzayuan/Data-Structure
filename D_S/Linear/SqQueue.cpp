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
	qu.front = (qu.front + 1) % MaxSize;//С����:ֻҪ����front+1����rear+1�ĵط�,����Ҫ��MaxSizeȡ��
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
	if (qu.front == qu.rear && qu.tag == 1) return 0;//tag==1��ζ�Ŷ�������Ԫ��,��֮front==rear��ζ����Ԫ�صļ������,������Ϊ��״̬
	qu.rear = (qu.rear + 1) % MaxSize;//��������С����:���ڶ���,������Ҫ+1�ĵط�����Ҫ��MaxSizeȡ����
	qu.data[qu.rear] = x;
	qu.tag = 1;//���Ϊtag = 1��ʾΪ�ɳ��ӵı�Ҫ����֮һ
	return 1;
}

int DeQueue_3(QuType_2 & qu, int & x) {
	if (qu.front == qu.rear && qu.tag == 0) return 0;//tag==0��ζ�Ŷ��ж��в���,��Ȼ�п�λ,��֮front==rear��ζ�Ŷ��в����ļ������,������Ϊ��״̬
	qu.front = (qu.front + 1) % MaxSize;//��һ��дʱд����==,�ɱ�������������:δʹ�ñ��ʽ���
	x = qu.data[qu.front];
	//if (qu.front == qu.rear) //ÿ�γ��Ӳ���if�ж϶���ÿ�ζ���tag = 0?��Ϊֻ����Ӳ��п���ʹ�ö�����//���߽�tag=0���Ϊ��ʣ�����ӵĿ�λ,��������ȫ��
	qu.tag = 0;//���Ϊtag = 0 ��ʾ���в���,����ӵı�Ҫ����֮һ,��֮front==rear������Ϊ���пյĳ�Ҫ����.
	return 1;
}
