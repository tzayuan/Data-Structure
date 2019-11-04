#pragma once
#include "pch.h"

constexpr auto MaxV = 200;

typedef char ElemType;

//ͼ���ڽӾ����ʾ��
typedef struct Vertextype {
	//����
	int No;//������
	ElemType info;//����������Ϣ
}VertexType;//��������

typedef struct Mgraph {
	//ͼ���ڽӾ�������
	int edges[MaxV][MaxV];//�ڽӾ���,˳��洢�ṹ
	int n, e;//nΪ������, eΪ����
	VertexType vexs[MaxV];//��Ŷ�����Ϣ
}MGraph;//ͼ���ڽӾ�������

//ͼ���ڽӱ��ʾ��
typedef struct ANode {
	//�ߵĽ��ṹ����
	int adjvex;//�ñߵ��յ�λ��
	struct ANode *nextarc;//ָ����һ���ߵ�ָ��
	InfoType info;//�ñߵ������Ϣ
} ArcNode;
typedef struct Vnode {
	//�ڽӱ�ͷ���Ľṹ����
	ElemType data;//������Ϣ
	ArcNode *firstarc;//ָ���һ����
}VNode;
typedef VNode AdjList[MaxV];//AdjList���ڽӱ�����
typedef struct Agraph {
	AdjList adjlist;
	int n, e;
}AGraph;

//ͼ�Ļ������㼰��ʵ���㷨
void CreateMat(MGraph &g, int A[][MaxV], int n);//����ͼ���ڽӾ��� //2019��9��19�� 20:18:08
void DispMat(MGraph g);//���ͼ���ڽӾ��� //2019��9��19�� 20:18:11
void CreateAdj(AGraph *&G, int A[][MaxV], int n);//����ͼ���ڽӱ� //2019��9��19�� 20:53:47
void DispAdj(MGraph *G);//���ͼ���ڽӱ�