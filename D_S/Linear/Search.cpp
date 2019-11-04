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
	//感觉答案写的不对,已自行修改.
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

int LBTInsert_czy(LBTNode *& p, KeyType key) {
	if (p == NULL) {//根据整个函数的算法逻辑,知只有当p为一颗空树时才进行此if内的操作
		p = (LBTNode *)malloc(sizeof(LBTNode));
		p->key = key;
		p->lchild = p->rchild = NULL;
	}
	else if (p->key == key) {//即要插入的关键字的值在该二叉排序树中已有,则return 0;
		return 0;
	}
	else if (p->key < key && p->lchild == NULL) {//key值小于当前结点的关键字值,且当前结点的左孩子指向NULL,则应该插入的位置为当前结点的左孩子,为新结点分配内存空间并进行相关赋值后,将该结点的左孩子指针指向该新结点,完成插入操作
		LBTNode *Newnode;
		Newnode = (LBTNode *)malloc(sizeof(LBTNode));
		Newnode->key = key;
		Newnode->lchild = Newnode->rchild = NULL;
		p->lchild = Newnode;
		return 1;
	}
	else if (p->key < key && p->lchild != NULL) {//key值小于当前结点的关键字值且当前结点的左孩子不为空,则继续沿当前结点的左孩子进行遍历
		return LBTInsert_czy(p->lchild, key);
	}
	else if (p->key > key && p->rchild != NULL) {//key值大于当前结点的关键字值,且当前结点的右孩子指向NULL,则应该插入的位置为当前结点的右孩子,为新结点分配内存空间并进行相关赋值后,将该结点的右孩子指针指向该新结点,完成插入操作
		return LBTInsert_czy(p->rchild, key);
	}
	else if (p->key > key && p->rchild == NULL) {//key值大于当前结点的关键字值且当前结点的右孩子不为空,则继续沿当前结点的右孩子进行遍历
		LBTNode *Newnode;
		Newnode = (LBTNode *)malloc(sizeof(LBTNode));
		Newnode->key = key;
		Newnode->lchild = Newnode->rchild = NULL;
		p->rchild = Newnode;
		return 1;
	}
}

void CreateLBT(LBTNode *& bt, KeyType str[], int n) {
	//二叉排序树的构造算法
	//算法思路:首先置该二叉排序树的根结点为NULL,即为空树.利用LBTInsert函数将str数组的所有关键字值依次按照二叉排序树的逻辑结构依次插入结点到二叉排序树bt中
	bt = NULL;
	for (int i = 0; i < n; i++) {
		LBTInsert_czy(bt, str[i]);
	}
}

int LBTDelete(LBTNode *& bt, KeyType key) {
	//删除二叉排序树中关键字值为key的结点的算法
	//平均时间复杂度为O(log2(n))
	LBTNode *p = bt, *f;//p用以遍历整个二叉排序树,f指向当前遍历到的结点的双亲结点
	LBTNode *f1, *r;//当被删除结点既有左子树又有右子树时需要用到
	f = NULL;
	while (p != NULL && p->key != key) {
		f = p;
		if (p->key < key) {
			p = p->lchild;
		}
		else {
			p = p->rchild;
		}
	}
	//此时要么p == NULL,要么p为找到的关键字值为key的结点;
	if (p == NULL) return 0;//未找到关键字值值为key的结点
	else if (p->lchild == NULL) {//p为待删除结点,此时对应p无左孩子的情况
		if (f == NULL) {//对应p为根结点且p无左孩子的情况
			bt = p->rchild;//特殊情况若p也无右孩子,则相当于bt = NULL;
			//free(p);
		}
		else if (p->rchild = NULL) {//对应p为叶子结点的情况
			//free(p);
		}
		//除去上面两种情况,剩余情况为:1)p不为根结点;2)p为分支结点,即p有右子树无左子树,则根据该结点是其双亲结点的左孩子还是右孩子将其双亲结点的对应孩子结点指针指向该结点的右孩子结点,再释放该结点的内存空间.
		else if (f->lchild == p) {//p为其双亲结点的左孩子,则将其双亲结点的左孩子指针指向该结点的左子树,并释放该结点
			f->lchild = p->rchild;
			//free(p);
		}
		else if (f->rchild == p) {//p为其双亲结点的右孩子,则将其双亲结点的右孩子指针指向该结点的右子树,并释放该结点
			f->rchild = p->rchild;
			//free(p);
		}
		free(p);
	}
	else if (p->rchild == NULL) {//p为待删除结点,此时对应p无右孩子的情况
		if (f == NULL) {//对应p为根结点且p无右孩子的情况
			bt = p->lchild;
			//free(p);
		}
		else if (p->lchild == NULL) {//对应p结点为叶子结点的情况
			//free(p);
		}
		//除去上面两种情况,剩余情况为:1)p不为根结点;2)p为分支结点,即p有左子树无右子树,则根据该结点是其双亲结点的左孩子还是右孩子将其双亲结点的对应孩子结点指针指向该结点的左孩子结点,再释放该结点的内存空间.
		else if (f->lchild == p) {//p为其双亲结点的左孩子,则将其双亲结点的左孩子指针指向该结点的左子树,并释放该结点的内存空间
			f->lchild = p->lchild;
			//free(p);
		}
		else if (f->rchild == p) {//p为其双亲结点的右孩子,则将其双亲结点的右孩子指针指向该结点的左子树,并释放该结点的内存空间
			f->rchild = p->lchild;
			//free(p);
		}
		free(p);
	}
	else {//p为待删除结点,此时对应p既有左孩子,又有右孩子的情况
		//此时有两种方案,1)将p结点的左子树的最右下结点*r替代*p结点;2)将p结点的右子树的最左下结点*r替代*p结点;此处采用第一种方案
		f1 = p, r = p->lchild;//f1指向最右下结点的双亲结点,r用以从待删除结点的左孩子结点开始遍历,寻找待删除结点的左子树的最右下结点
		while (r->rchild != NULL) {
			f1 = r;
			r = r->rchild;
		}
		//此时f1指向最右下结点的双亲结点,即为r的双亲结点;r指向待删除结点p的左子树的最右下结点,该最右下结点必定无右子树,但可能有左子树
		if (f1->lchild == r) {//r为其双亲结点的左孩子
			f1->lchild = r->lchild;
		}
		else if (f1->rchild == r) {
			f1->rchild = r->lchild;
		}
		//接下来实现用*r 代替 *p
		r->lchild = p->lchild;
		r->rchild = p->rchild;
		if (f == NULL) {//p的双亲结点为空,即p为根结点,则此时r为根结点
			bt = r;
		}
		else if (f->lchild == p) {//p为其双亲结点的左孩子,则令其双亲结点的左孩子指针指向r,再释放p的内存空间
			f->lchild = r;
		}
		else if (f->rchild == p) {//p为其双亲结点的右孩子,则令其双亲结点的右孩子指针指向r,再释放p的内存空间
			f->rchild = r;
		}
		free(p);
	}
}