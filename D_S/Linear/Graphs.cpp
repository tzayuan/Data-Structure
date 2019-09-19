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
		G->adjlist->firstarc = NULL;//给邻接表中所有头结点的指针域置初值
	}
	for (int i = 0; i < n; i++) {//检查邻接矩阵的每个元素
		for (int j = n - 1; j >= 0; j++) {
			if (A[i][j] != 0) {//邻接矩阵的当前元素不为0
				p = (ArcNode *)malloc(sizeof(ArcNode));//创建一个边结点p
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;//将*p链到i顶点为头结点的边单链表上
				G->adjlist[i].firstarc = p;
				G->e++;//边数增加1
			}
		}
	}
}

void DispAdj(AGraph * G) {
	ArcNode *p;
	for (int i = 0; i < G->n; i++) {
		printf_s("[%d]->", i);
		p = G->adjlist[i].firstarc;//找顶点i的第一个邻接顶点. 注意.而不是->
		while (p != NULL) {//存在顶点i的邻接顶点时循环
			printf_s("[%d]->", p->adjvex);
			p = p->nextarc;
		}
		printf_s("^\n");
	}
}
