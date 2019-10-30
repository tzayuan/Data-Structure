#pragma once
#include "pch.h"

//顺序表结点数据类型,应用于线性表中的顺序查找和二分查找(以顺序表为存储结构)
typedef struct SearchNodeType {
	KeyType key;
	SearchInfoType data;
} SearchNodeType;
typedef SearchNodeType SeqList[MaxSize];

//顺序表/索引表结点的数据类型,应用于线性表中的分块查找(本质上仍以顺序表为存储结构)
typedef struct IdxType{
	KeyType key;
	int link;
} IdxType;
typedef IdxType IDX[MaxSize];

//线性表的查找算法
//顺序查找、二分查找、分块查找
//平均查找长度:二分查找<分块查找<顺序查找
//存储结构:顺序查找、分块查找适用于顺序表/链表均可;二分查找仅适用于顺序表;
//表的逻辑结构:顺序查找的线性表无序、有序均可;二分查找仅适用于有序表;分块查找至少要求线性表的所有元素分块有序,即第n个块(n=1,2,3,...)的最小值大于第n-1个块的最大值
//其中,分块查找综合了顺序查找和二分查找的优点,既能够较快速地查找,又能适应动态变化的要求.但是额外增加了保存索引表的开销.
//【个人理解】增加索引表保存在磁盘上,虽然增加了磁盘的开销,但通过索引来查找key,会减少磁盘I/O次数,即满足一个B-Tree的逻辑结构,发挥多路平衡查找树的优势
//顺序查找
int SeqSearch(SeqList R, int length, KeyType key);//2019年10月10日 11:37:20
//二分查找
int BinSearch(SeqList R, int length, KeyType key);//2019年10月10日 11:37:22
//分块查找(采用二分查找索引表,顺序查找块内顺序表子序列的分块查找算法)
int IdxSearch(IDX I, int IDXTableLength, SeqList R, int length, KeyType key);//2019年10月29日 20:54:42

//树表的查找
//二叉排序树(Binary sort tree,BST)、平衡二叉树(AVL树,AVL树得名于它的发明者G. M. Adelson-Velsky和E. M. Landis)、B-Tree、B+树
//二叉排序树
LBTNode *BSTSearch(LBTNode *bt, KeyType key) {

}
//对某二叉排序树的进行中序遍历,将得到一个key递增有序的序列


//哈希表的查找

