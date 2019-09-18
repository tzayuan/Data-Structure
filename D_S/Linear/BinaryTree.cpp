#include "pch.h"

void PreOrder(LBTNode *b) {
	//基于链式存储结构的二叉树的先序遍历的递归算法;
	//算法思路:递归访问根结点, 左子树, 右子树.
	if (b != NULL) {
		printf_s("%c ", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void PreOrder1(LBTNode * b) {
	//基于链式存储结构的二叉树的先序遍历的非递归算法;
	//算法思路:开辟一个数组,数组的元素为指向二叉树结点的指针,若二叉树不为空,则首先让根结点入栈,在栈不空时循环:栈顶结点出栈并让p指向该出栈元素,将p所指向的结点数据域输出,再将p的右孩子进栈,再将p的左孩子进栈.
	//直至栈空时,即实现了按照先遍历根结点,再遍历左孩子,再遍历右孩子的先序遍历算法.
	LBTNode *St[MaxSize], *p;
	int top = -1;
	if (b != NULL) {
		top++;
		St[top] = b;
		while (top != -1) {
			p = St[top--];
			printf_s("%c ", p->data);
			if (p->rchild != NULL) {
				top++;
				St[top] = p->rchild;
			}
			if (p->lchild != NULL) {
				top++;
				St[top] = p->rchild;
			}
		}
		printf_s("\n");
	}
}

void InOrder(LBTNode * b) {
	//基于链式存储结构的二叉树的中序遍历的递归算法;
	//算法思路:递归访问左子树, 根结点, 右子树.
	if (b != NULL) {
		InOrder(b->lchild);
		printf_s("%c", b->data);
		InOrder(b->rchild);
	}
}

void InOrder1(LBTNode * b) {
	//基于链式存储结构的二叉树的中序遍历的非递归算法;
	LBTNode *St[MaxSize], *p;
	int top = -1;
	if (b != NULL) {
		p = b;
		while (top != -1 || p != NULL) {
			while (p != NULL) {
				top++;
				St[top] = p;
				p = p->lchild;
			}
			if (top != -1) {//此时top的结点要么无左孩子要么左孩子(严格说是左孩子为根结点的子树)已遍历完,则此时即相当于已访问完当前结点的左子树,按照中序遍历的定义,输出top的结点即相当于输出完左孩子再输出的根结点
				p = St[top];
				top--;
				printf_s("%c", p->data);
				p = p->rchild;
			}
		}
		printf_s("\n");
	}
}

void PostOrder(LBTNode * b) {
	//基于链式存储结构的二叉树的后序遍历的递归算法
	//算法思路: 递归访问左子树, 右子树, 根结点.
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf_s("%c", b->data);
	}
}

void PostOrder1(LBTNode * b) {
	//基于链式存储结构的二叉树的后序遍历的非递归算法
	LBTNode *St[MaxSize], *p;
	int flag, top = -1;
	if (b != NULL) {
		do {
			while (b != NULL) {
				top++;
				St[top] = b;
				b = b->lchild;
			}
			p = NULL;
			flag = 1;
			while (top != -1 && flag) {
				b = St[top];
				if (b->rchild == p) {
					printf_s("%c", b->data);
					top--;
					p = b;
				}
				else {
					b = b->rchild;
					flag = 0;
				}
			}
		} while (top != -1);
		printf_s("\n");
	}
}

void CreateLBTNode(LBTNode *& b, char * str) {
	//P200, 括号表示法二叉树字符串A转换为(或称之为生成)链式存储结构的二叉树
	LBTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (LBTNode *)malloc(sizeof(LBTNode)); p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
			break;
		}
		ch = str[++j];
	}
}

LBTNode * FindNode(LBTNode * b, int x) {
	//查找结点的算法
	//算法思路: 采用先序遍历递归算法查找值为x的结点.找到后返回其指针,否则返回NULL.
	LBTNode *p;
	if (b == NULL) {
		return NULL;
	}
	else if (b->data == x) {
		return b;
	}
	else {
		p = FindNode(b->lchild, x);
		if (p != NULL) return p;
		else return FindNode(b->rchild, x);
	}
}

LBTNode * LchildNode(LBTNode * b) {
	//查找左孩子结点的算法
	//直接返回指向b结点的左孩子结点的指针
	return b->lchild;
}

LBTNode * RchildNode(LBTNode * b) {
	//查找右孩子结点的算法
	//直接返回指向b结点的右孩子结点的指针
	return b->rchild;
}

int LBTNodeDepth(LBTNode * b) {
	//求二叉树的高度
	int LchildDep, RchildDep;
	if (b == NULL) return 0;
	else {
		LchildDep = LBTNodeDepth(b->lchild);
		RchildDep = LBTNodeDepth(b->rchild);
		return (LchildDep > RchildDep) ? (LchildDep + 1) : (RchildDep + 1);
	}
	return 0;
}

void DispLBTNode(LBTNode * b) {
	if (b != NULL) {
		printf_s("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf_s("(");
			DispLBTNode(b->lchild);
			if (b->rchild != NULL) {
				printf_s(",");
			}
			DispLBTNode(b->rchild);
			printf_s(")");
		}
	}
}

LBTNode * CreateLBT1(char * pre, char * in, int n) {
	//由前序序列和中序序列构造二叉树
	//算法思路: pre存放先序序列, in存放中序序列,n为in中字符个数,本算法执行后返回构造的二叉链的根结点指针
	LBTNode *s;
	char *p;
	int k;
	if (n <= 0) return NULL;
	s = (LBTNode *)malloc(sizeof(LBTNode));//创建二叉树结点*s
	s->data = *pre;
	for (p = in; p < in + n; p++) {//在中序序列中找等于*pre的位置k
		if (*p == *pre) break;
	}
	k = p - in;
	s->lchild = CreateLBT1(pre + 1, in, k);//递归构造左子树
	s->rchild = CreateLBT1(pre + k + 1, p + 1, n - k - 1);//递归构造右子树
	return s;
}

LBTNode * CreateLBT2(char * post, char * in, int n, int m) {
	//由后序序列和中序序列构造二叉树
	//算法思路: post存放后序序列,in存放中序序列,n为in中字符个数,m为二叉树中结点总个数.返回构造的二叉链的根结点指针
	LBTNode *s;
	char *p, *q, *maxp;
	int maxpost, maxin, k;
	if (n <= 0) return NULL;
	maxpost = -1;
	for (p = in; p < in + n; p++) {
		for (q = post; q < post + m; q++) {
			if (*q == *q) {
				k = q - post;
				if (k > maxpost) {
					maxpost = k;
					maxp = p;
					maxin = p - in;
				}
			}
		}
	}
	s = (LBTNode *)malloc(sizeof(LBTNode));
	s->data = post[maxpost];
	s->lchild = CreateLBT2(post, in, maxin, m);
	s->rchild = CreateLBT2(post, maxp + 1, n - maxin, m);
	return s;
}

void CreateHT(HTNode ht[], int n) {
	float min1, min2;
	int lnode, rnode;
	for (int i = 0; i < 2 * n - 1; i++) {
		ht[i].lchild = ht[i].rchild = ht[i].parent = -1;
	}
	for (int i = n; i < 2 * n - 1; i++) {
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for (int k = 0; k <= i - 1; k++) {
			if (ht[k].parent == -1) {
				if (ht[k].weight < min1) {//保证了min1始终是两者中的最小值,min2是次小值
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2) {//对应比最小值大,但是比此时的次小值要小的情况
					rnode = k;
					min2 = ht[k].weight;
				}
			}
		}
		ht[lnode].parent = ht[rnode].parent = i;
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
	}
}