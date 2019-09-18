#pragma once
#include "pch.h"

typedef char ElemType;

//图的邻接矩阵表示法
typedef struct {
	//顶点
	int No;//顶点编号
	ElemType info;//顶点其他信息
}VertexType;//顶点类型

typedef struct {
	//图
	int edges[MaxSize][MaxSize];//邻接矩阵,顺序存储结构
	int n, e;//n为顶点数, e为边数
	VertexType vexs[MaxSize];//存放顶点信息
}MGraph;//图的邻接矩阵类型

//图的邻接表表示法

//图的基本运算及其实现算法
void CreateMat(MGraph &g, int A[][MaxSize], int n);//生成图的邻接矩阵
void DispMat(MGraph g);//输出图的邻接矩阵