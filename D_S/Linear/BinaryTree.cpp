#include "pch.h"

void PreOrder(LBTNode *b) {
	//������ʽ�洢�ṹ�Ķ���������������ĵݹ��㷨;
	//�㷨˼·:�ݹ���ʸ����, ������, ������.
	if (b != NULL) {
		printf_s("%c ", b->data);
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
	//������ʽ�洢�ṹ�Ķ���������������ĵݹ��㷨;
	//�㷨˼·:�ݹ����������, �����, ������.
	if (b != NULL) {
		InOrder(b->lchild);
		printf_s("%c", b->data);
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
				printf_s("%c", p->data);
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
		printf_s("%c", b->data);
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
	//���ҽ����㷨
	//�㷨˼·: ������������ݹ��㷨����ֵΪx�Ľ��.�ҵ��󷵻���ָ��,���򷵻�NULL.
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
	//�������ӽ����㷨
	//ֱ�ӷ���ָ��b�������ӽ���ָ��
	return b->lchild;
}

LBTNode * RchildNode(LBTNode * b) {
	//�����Һ��ӽ����㷨
	//ֱ�ӷ���ָ��b�����Һ��ӽ���ָ��
	return b->rchild;
}

int LBTNodeDepth(LBTNode * b) {
	//��������ĸ߶�
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
	//��ǰ�����к��������й��������
	//�㷨˼·: pre�����������, in�����������,nΪin���ַ�����,���㷨ִ�к󷵻ع���Ķ������ĸ����ָ��
	LBTNode *s;
	char *p;
	int k;
	if (n <= 0) return NULL;
	s = (LBTNode *)malloc(sizeof(LBTNode));//�������������*s
	s->data = *pre;
	for (p = in; p < in + n; p++) {//�������������ҵ���*pre��λ��k
		if (*p == *pre) break;
	}
	k = p - in;
	s->lchild = CreateLBT1(pre + 1, in, k);//�ݹ鹹��������
	s->rchild = CreateLBT1(pre + k + 1, p + 1, n - k - 1);//�ݹ鹹��������
	return s;
}
