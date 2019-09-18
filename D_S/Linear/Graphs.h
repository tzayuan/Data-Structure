#pragma once
#include "pch.h"

typedef char ElemType;

//ͼ���ڽӾ����ʾ��
typedef struct {
	//����
	int No;//������
	ElemType info;//����������Ϣ
}VertexType;//��������

typedef struct {
	//ͼ
	int edges[MaxSize][MaxSize];//�ڽӾ���,˳��洢�ṹ
	int n, e;//nΪ������, eΪ����
	VertexType vexs[MaxSize];//��Ŷ�����Ϣ
}MGraph;//ͼ���ڽӾ�������

//ͼ���ڽӱ��ʾ��

//ͼ�Ļ������㼰��ʵ���㷨
void CreateMat(MGraph &g, int A[][MaxSize], int n);//����ͼ���ڽӾ���
void DispMat(MGraph g);//���ͼ���ڽӾ���