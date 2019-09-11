#include "pch.h"

void PreOrder(LBTNode *b) {
	//基于链式存储结构的二叉树的先序遍历的递归算法;
	//算法思路:递归访问根结点, 左子树, 右子树.
	if (b != NULL) {
		printf_s("%d ", b->data);
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
			printf_s("%d ", p->data);
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
		printf_s("%d", b->data);
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
				printf_s("%d", p->data);
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
		printf_s("%d", b->data);
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
					printf_s("%d", b->data);
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
					St[top]->lchild = p; break;
				case 2:
					St[top]->rchild = p; break;
				}
			}
			break;
		}
		ch = str[++j];
	}
}