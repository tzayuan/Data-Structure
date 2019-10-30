#include "pch.h"
#include "Search.h"


int SeqSearch(SeqList R, int length, KeyType key) {
	//	顺序查找
	//	ASL_seq=(n+1)/2
	//	T(n)=O(n)
	int i = 0;
	while (i < length && R[i].key != key) {
		i++;
	}
	if (i >= length) return -1;
	else return i;
}

int BinSearch(SeqList R, int length, KeyType key) {
	//	二分查找
	//	ASL_bin=log2(n)
	//	T(n)=O(log2(n))
	int low = 0, high = length - 1, mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (R[mid].key == key) {
			return mid;
		}
		else if (R[mid].key < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int IdxSearch(IDX I, int IDXTableLength, SeqList R, int length, KeyType key) {
	//采用二分查找索引表,顺序查找线性表(块内子表)的分块查找算法;
	//索引表的长度为IDXTableLength,顺序表的长度为lenghth, 要查找的关键字值为key;
	//分块查找要求表中元素至少是分块有序的,即第n个块(n=1,2,3,...)的最小值大于第n-1个块的最大值
	//分块查找的算法效率介于顺序查找和二分查找之间.
	int low = 0, high = IDXTableLength - 1, mid, i;//为对索引表的关键字值进行二分查找做准备,建立low high mid,i作为若找到对应的索引表子块后的顺序查找的游标
	int subBlockLength = length / IDXTableLength;//subBlockLength为每块的记录个数
	while (low <= high) {//在索引表中对关键字进行二分查找,将找到的位置存放在low中
		//high必定会在最后进入括号内的特殊情况(即索要查找的key值与当前mid的关键字值相等的情况,也包括当前high所在的子块即为最终找到的子块时),此时将必定走到应在子块的前一个子块的位置,此时接下来的所有新的mid都将小于所要查找的关键字值,
		//则low每次循环low++,直至low>high退出while循环,也即刚好处于极端情况下应在子块的位置,此时low的值为所要查找的子块的位置.
		mid = (low + high) / 2;
		if (I[mid].key >= key) {
			high = mid - 1;
		}
		else {// if (I[mid].key < key)
			low = mid + 1;
		}
	}
	if (low < IDXTableLength) {//在索引表中查找成功后,对该子块进行顺序查找
		i = I[low].link;
		while (i <= I[low].link + subBlockLength - 1 && R[i].key != key) {
			i++;
		}
		if (i <= I[low].link + subBlockLength - 1) {
			return i;//返回顺序查找第一个关键字值为key的元素的下标
		}
		else {
			return -1;
		}
	}
	return -1;//对应索引表查找不成功的情况,确保所有情况都能够return.
}

LBTNode *BSTSearch(LBTNode *bt, KeyType key) {
	//查找结点的算法
	//算法思路:该二叉排序树采用二叉链式存储结构,从bt所指向的根结点开始递归遍历整颗二叉树,直至找到对应结点或直至叶子结点都不满足条件则返回NULL即未找到
	//首先判断当前所遍历到的结点是否为NULL,若为NULL,则直接返回NULL,表示未找到关键字值为key的结点;
	//若当前遍历结点的的关键字值等于所要查找的key值,则返回该结点,即查找到了关键字值为key的结点
	//否则,若key值小于要当前遍历到的结点的关键字值,按照平衡二叉树的逻辑结构,递归该函数主体,bt为当前结点的左孩子结点;
	//均不是以上情况,即key值大于当前遍历到的结点的关键字值,则递归该函数主体,bt为当前结点的右孩子结点;
	if (bt == NULL) {
		return NULL;
	}
	else if (bt->key == key) {
		return bt;
	}
	else if (key < bt->key) {
		return BSTSearch(bt->lchild, key);
	}
	else {
		return BSTSearch(bt->rchild, key);
	}
}

int LBTInsert(LBTNode *& p, KeyType key) {
	//二叉排序树的结点插入算法
	//平均时间复杂度为O(log2(n))
	//算法思路:可以将插入过程看作一个遍历整个已知二叉排序树(或者一颗空树)直至该关键字该插入的逻辑位置,即某叶子结点的左孩子结点或右孩子结点(注意其实此时该孩子结点为NULL,是逻辑上应该插入的位置)
	if (p == NULL) {
		p = (LBTNode *)malloc(sizeof(LBTNode));//给指向NULL的指针赋值??好像是可以...那链表可以吗?考后需要测试验证.
		p->key = key;
		p->lchild = p->rchild = NULL;
		return 1;
	}
	else if (key == p->key) {
		return 0;
	}
	else if (key < p->key) {
		return LBTInsert(p->lchild, key);
	}
	else {
		return LBTInsert(p->rchild, key);
	}
}

void CreateLBT(LBTNode *& bt, KeyType str[], int n) {
	//二叉排序树的构造算法
	//算法思路:首先置该二叉排序树的根结点为NULL,即为空树.利用LBTInsert函数将str数组的所有关键字值依次按照二叉排序树的逻辑结构依次插入结点到二叉排序树bt中
	bt = NULL;
	for (int i = 0; i < n; i++) {
		LBTInsert(bt, str[i]);
	}
}

int LBTDelete(LBTNode *& bt, KeyType key) {
	//删除结点的算法
	//平均时间复杂度为O(log2(n))
}
