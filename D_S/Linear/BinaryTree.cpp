#include "pch.h"

void PreOrder(LBTNode *b) {
	//������ʽ�洢�ṹ�Ķ���������������ĵݹ��㷨;
	//�㷨˼·:�ݹ���ʸ����, ������, ������.
	if (b != NULL) {
		printf_s("%d ", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void PreOrder1(LBTNode * b) {
	//������ʽ�洢�ṹ�Ķ���������������ķǵݹ��㷨;
	//�㷨˼·:����һ������,�����Ԫ��Ϊָ�����������ָ��,����������Ϊ��,�������ø������ջ,��ջ����ʱѭ��:ջ������ջ����pָ��ó�ջԪ��,��p��ָ��Ľ�����������,�ٽ�p���Һ��ӽ�ջ,�ٽ�p�����ӽ�ջ.
	//ֱ��ջ��ʱ,��ʵ���˰����ȱ��������,�ٱ�������,�ٱ����Һ��ӵ���������㷨.
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
	//������ʽ�洢�ṹ�Ķ���������������ĵݹ��㷨;
	//�㷨˼·:�ݹ����������, �����, ������.
	if (b != NULL) {
		InOrder(b->lchild);
		printf_s("%d", b->data);
		InOrder(b->rchild);
	}
}

void InOrder1(LBTNode * b) {
	//������ʽ�洢�ṹ�Ķ���������������ķǵݹ��㷨;
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
			if (top != -1) {//��ʱtop�Ľ��Ҫô������Ҫô����(�ϸ�˵������Ϊ����������)�ѱ�����,���ʱ���൱���ѷ����굱ǰ����������,������������Ķ���,���top�Ľ�㼴�൱�����������������ĸ����
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
	//������ʽ�洢�ṹ�Ķ������ĺ�������ĵݹ��㷨
	//�㷨˼·: �ݹ����������, ������, �����.
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf_s("%d", b->data);
	}
}

void PostOrder1(LBTNode * b) {
	//������ʽ�洢�ṹ�Ķ������ĺ�������ķǵݹ��㷨
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
	//P200, ���ű�ʾ���������ַ���Aת��Ϊ(���֮Ϊ����)��ʽ�洢�ṹ�Ķ�����
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