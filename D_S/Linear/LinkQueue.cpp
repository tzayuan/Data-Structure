#include "pch.h"
#include "LinkQueue.h"

void initLinkQueue(LinkQueue *& lqu) {
	lqu = (LinkQueue *)malloc(sizeof(LinkQueue));
	lqu->front = lqu->rear = NULL;
}

int isEmptyLinkQueue(LinkQueue * lqu) {
	return (lqu->front == NULL);//����ֻ�ж���rearΪNULL,�Ƿ�������
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
	if (rear == NULL) {//��һ��дʱδ���Ƕӿ�״��
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
	rear = (LQNode *)malloc(sizeof(LQNode));//��rear��ʱΪͷ���
	rear->next = rear;
}

int isEmptyCLinkQueueWithHead(LQNode * rear) {
	return (rear->next == rear);//����ֻ��һ��rear���ʱ,rear�����Ϊͷ���,��ö���Ϊ�ն�.
}

void EnCLinkQueueWithHead(LQNode *& rear, int x) {
	//�ն�ʱ,rearΪͷ���,rearͬ����һ���Ե����ݽ��һ��,�����к��ָ��ָ������Ԫ��,������ָ��Ƚ�����,ָ��������
	//����½��Ĳ���������Ƿ�Ϊ���޹�,������Ϊ�½��ָ��rear�ĺ�̽��(��ͷ���),����rearָ���²���Ľ��
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
		rear->next->next = p->next;//�˴��Դ�������,Page129//��û����,β��㲻��,��Ȼָ��ͷ���(�����if�Ѿ������ֻ�ж�����ֻ��һ�����ݽ������),ͷ���ָ���ͷ����һ�����ݽ��
		free(p);
	}
	return 1;
}