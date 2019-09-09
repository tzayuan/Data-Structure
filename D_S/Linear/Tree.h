#pragma once//保证头文件只被编译一次,防止某个头文件被多次include

#include "pch.h"
#include <cstdio>
#include <cstdlib>

//树的存储结构
//	1).双亲存储结构.缺点:求某个结点的孩子结点时需要遍历整个结构
//顺序存储结构, 用一组连续空间存储树的所有结点, 同时在结点中附设一个伪指针指示其双亲结点的位置(具体位置而非层数).
typedef struct {
	int data;//数据域
	int pos;//双亲域
} STree[MaxSize];

//	2).孩子链存储结构,缺点:浪费较多的指针空间,从当前结点查找双亲结点比较麻烦.
//孩子链存储结构按树的度(即树中所有结点度的最大值)设计结点的孩子结点指针域个数.
typedef struct TNode {
	int data;//数据域
	struct TNode *child[M];//孩子指针域,M为树的度,该常量M在pch.h中定义为constexpr auto M = 3;
}CTree;

//	3).孩子兄弟链存储结构,可方便地实现树和二叉树的相互转换.缺点:从当前结点查找双亲结点比较麻烦.
//每个结点设计3个域: 一个数据元素域, 一个该结点的第一个孩子结点指针域, 一个该结点的下一个兄弟结点指针域.
typedef struct CBNode {
	int data;//数据域
	struct CBNode *child;//孩子指针域
	struct CBNode *brother;//兄弟指针域
}CBTree;