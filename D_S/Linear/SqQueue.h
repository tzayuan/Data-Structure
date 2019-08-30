#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>

//˳����У�ͨ���ö�βָ��rearָ��ս��ӵ�Ԫ��λ��,��ͷָ��frontָ��ճ��ӵ�Ԫ��λ��,������Ԫ�ص�ǰһ��λ��
//�����: ������qu.rear == MaxSize - 1 �� qu.front == MaxSize - 1��Ϊ��������,�ͻ����"�����",��������Ϊ��ʱ�����Կ��ܴ��ڿɴ��Ԫ�صĿռ�.
//Ϊ������������,���û��ζ��еķ�ʽ,���еĻ���Ҫ������:
//	�ӿ�����: qu.front == qu.rear
//	��������: (qu.rear + 1) % MaxSize == qu.front
//	Ԫ��x���Ӳ���(���ƶ���βָ��): qu.rear = (qu.rear + 1) % MaxSize; qu.data[qu.rear] = x;
//	����x����(���ƶ�����ָ��): qu.front = (qu.front + 1) % MaxSize; x = qu.data[qu.front];
//ע��: Ϊ������ӿպͶ���,���������ζ��������ֻ�ܴ��MaxSize - 1 ��Ԫ��
typedef struct SqQueue {
	int data[MaxSize];
	int front, rear;
}SqQueue;

void initSqQueue(SqQueue &qu);
int enQueue(SqQueue &qu, int x);
int deQueue(SqQueue &qu, int &x);
int isEmptyQueue(SqQueue qu);
int isFullQueue(SqQueue qu);


//����˳�����˵,���֪������Ԫ�ص�λ�úͶ�����Ԫ�ظ���,���βԪ������λ����Ȼ�ǿ��Լ����.Ҳ����˵,�����ö�����Ԫ�ظ��������βָ��,��Ƴ����ֻ���˳��ӵĳ�ʼ������ӡ����Ӻ��п��㷨.
//	����֪����Ԫ�ص�λ��front�Ͷ�����Ԫ�ظ���count��,���еĻ���Ҫ������:
//		�ӿյ�����:count == 0;
//		����������:count == MaxSize
//		�����βλ��: rear = (front + count) % MaxSize
typedef struct {
	int data[MaxSize];
	int front;
	int count;
}QuType;

void initSqQueue_2(QuType &qu);
int isEmptyQueue_2(QuType qu);
int isFullQueue_2(QuType qu);
void headQueue_2(QuType &qu, int &x);
int EnQueue_2(QuType &qu, int x);//��α�д���в�ͬ,�Կα�д������ȷ�Դ�������.
int DeQueue_2(QuType &qu, int &x);


//���һ�����ζ���,��front��rear�ֱ���Ϊ��ͷ�Ͷ�βָ��,������һ����־tag��ʾ�����ǿ�(0)���ǲ���(1),�����Ϳ�����front==rear��Ϊ����������.Ҫ����ƶ��е���ػ��������㷨.
//	��ʼʱtag = 0,���гɹ��Ĳ��������tag = 1,���гɹ���ɾ��������tag = 0;��Ϊֻ���ڲ����������в��п�����,��ɾ����������в��п��ܿ�,���,�����Ķ��еĻ���Ҫ������:
//		��ʼʱ:tag = 0, front = rear
//		�ӿ�����:qu.front == qu.rear && tag == 0
//		��������:qu.front == qu.rear && tag == 1
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

//���ö�������Թ�����
//*