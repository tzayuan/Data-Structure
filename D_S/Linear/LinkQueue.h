#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
//(!!!!!)lqu.front == lqu.rear == NULL��д���Ǵ����,==ֻ���ж������Ƿ����,������������,����Ҫ��дΪlqu.front == NULL && lqu.rear == NULL

typedef struct qNode{
	int data;
	struct qNode *next;
}LQNode;
//����ڵ�����Ĵ洢�ṹ��ջ(�߼��ṹ)��ȣ�ջ��һ�߼��ṹֻ������ջ�����в���,��ͷ�巨���н�ջ,��ջʱȡ���׸�����Ԫ��,���в������Ƕ��׸����ݽ����е�,���ֻ��Ҫͷ����ָ�뼴��O(1)���ջ���߼������޶�����ز���,
//��������һ�߼��ṹ��������ҪƵ�������������ͷ���в���,���׸����ݽ���β���,��������������β���ָ��,����Ҫ��ͷ��������β���,��ζ��ÿ����Ӷ���Ҫ����ʱ�临�Ӷ�ΪO(n)��ɨ����β��㴦�Ĳ���,
//��˶��ڻ��ڵ�����洢�ṹ��ѭ��������һ�߼��ṹ,�ڶ�����ÿһ����������Ľṹ���������ͺ�,��Ҫ�����������ٽ���һ�νṹ�����Ͷ���,�������и�������׸����ݽ���β���,�Ը�Ч����ɶ�����һ�߼��ṹ������㷨����
typedef struct LinkQueue{
	LQNode *front;//frontָ���һ�����ݽ��,������ͷ���
	LQNode *rear;
}LinkQueue;

//����lqu��4��Ԫ������:
//	���п�����:NULL == lqu->front��NULL == lqu->rear;
//	����������:һ�㲻���ڶ����������
//	Ԫ��*p���Ӳ���:lqu->rear->next = p; lqu->rear = p;
//	�����в���:p = lqu->front; lqu->front = p->next; x = p->data; free(p);//ͷ��㵽��һ�����ݽ�����·������???��ʵ��û��ͷ���,������һ��frontֱ��ָ���һ�����ݽ��,rearֱ��ָ��β���
void initLinkQueue(LinkQueue *&lqu);
int isEmptyLinkQueue(LinkQueue *lqu);
//int isFullLinkQueue(LinkQueue *lqu);//һ�㲻���ڶ������
void EnLinkQueue(LinkQueue *&lqu, int x);
int DeLinkQueue(LinkQueue *&lqu, int &x);

//P127, ��4-3-11, ������һ��ѭ���������ʾ����,����ֻ��һ��ָ��rearָ���β���,������ͷָ��,��Ƴ���Ӧ�Ķӳ�ʼ������ӡ����Ӻ��пնӵ��㷨.
//�ⷨһ:���������ǲ���ͷ����ѭ��������,�����Ҫ������:
//	�ӿ�����:lqu.front == lqu.rear == NULL;
//	���:��rear���֮������㲢��rearָ��ý��
//	����:ɾ��rear���֮��ĵ�һ�����.
//��Ӧ���㷨����:
void initCLinkQueue(LQNode *&rear);
int isEmptyCLinkQueue(LQNode *rear);
void EnCLinkQueue(LQNode *&rear, int x);
int DeCLinkQueue(LQNode *&rear, int &x);
//P127, ��4-3-11, ������һ��ѭ���������ʾ����,����ֻ��һ��ָ��rearָ���β���,������ͷָ��,��Ƴ���Ӧ�Ķӳ�ʼ������ӡ����Ӻ��пնӵ��㷨.
//�ⷨ��:���������Ǵ�ͷ����ѭ��������,�����Ҫ������:
//	�ӿ�����:rear.next == rear
//	���:��rear���֮������㲢��rearָ��ý��
//	����:ɾ��rear->next֮��ĵ�һ�����
void initCLinkQueueWithHead(LQNode *&rear);
int isEmptyCLinkQueueWithHead(LQNode *rear);
void EnCLinkQueueWithHead(LQNode *&rear, int x);
int DeCLinkQueueWithHead(LQNode *&rear, int &x);