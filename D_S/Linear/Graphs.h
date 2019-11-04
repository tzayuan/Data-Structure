#pragma once
#include "pch.h"

constexpr auto MaxV = 200;

typedef char ElemType;

//图的邻接矩阵表示法
typedef struct Vertextype {
	//顶点
	int No;//顶点编号
	ElemType info;//顶点其他信息
}VertexType;//顶点类型

typedef struct Mgraph {
	//图的邻接矩阵类型
	int edges[MaxV][MaxV];//邻接矩阵,顺序存储结构
	int n, e;//n为顶点数, e为边数
	VertexType vexs[MaxV];//存放顶点信息
}MGraph;//图的邻接矩阵类型

//图的邻接表表示法
typedef struct ANode {
	//边的结点结构类型
	int adjvex;//该边的终点位置
	struct ANode *nextarc;//指向下一条边的指针
	InfoType info;//该边的相关信息
} ArcNode;
typedef struct Vnode {
	//邻接表头结点的结构类型
	ElemType data;//顶点信息
	ArcNode *firstarc;//指向第一条边
}VNode;
typedef VNode AdjList[MaxV];//AdjList是邻接表类型
typedef struct Agraph {
	AdjList adjlist;
	int n, e;
}AGraph;

//图的基本运算及其实现算法
void CreateMat(MGraph &g, int A[][MaxV], int n);//生成图的邻接矩阵 //2019年9月19日 20:18:08
void DispMat(MGraph g);//输出图的邻接矩阵 //2019年9月19日 20:18:11
void CreateAdj(AGraph *&G, int A[][MaxV], int n);//生成图的邻接表 //2019年9月19日 20:53:47
void DispAdj(MGraph *G);//输出图的邻接表