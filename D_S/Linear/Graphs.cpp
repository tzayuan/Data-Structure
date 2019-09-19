#include "pch.h"

void CreateMat(MGraph & g, int A[][MaxV], int n) {
	g.n = n;
	g.e = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g.edges[i][j] = A[i][j];
			if (g.edges[i][j] != 0) {
				g.e++;
			}
		}
	}
}

void DispMat(MGraph g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			printf("%4d", g.edges[i][j]);
		}
		printf_s("\n");
	}
}

void CreateAdj(AGraph *& G, int A[][MaxV], int n) {
	ArcNode *p;
	G = (AGraph *)malloc(sizeof(AGraph));
	G->n = n;
	G->e = 0;
	for (int i = 0; i < n; i++) {
		G->adjlist->firstarc = NULL;//���ڽӱ�������ͷ����ָ�����ó�ֵ
	}
	for (int i = 0; i < n; i++) {//����ڽӾ����ÿ��Ԫ��
		for (int j = n - 1; j >= 0; j++) {
			if (A[i][j] != 0) {//�ڽӾ���ĵ�ǰԪ�ز�Ϊ0
				p = (ArcNode *)malloc(sizeof(ArcNode));//����һ���߽��p
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;//��*p����i����Ϊͷ���ıߵ�������
				G->adjlist[i].firstarc = p;
				G->e++;//��������1
			}
		}
	}
}

void DispAdj(AGraph * G) {
	ArcNode *p;
	for (int i = 0; i < G->n; i++) {
		printf_s("[%d]->", i);
		p = G->adjlist[i].firstarc;//�Ҷ���i�ĵ�һ���ڽӶ���. ע��.������->
		while (p != NULL) {//���ڶ���i���ڽӶ���ʱѭ��
			printf_s("[%d]->", p->adjvex);
			p = p->nextarc;
		}
		printf_s("^\n");
	}
}
