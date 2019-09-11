#include "pch.h"

#include "LinkList.h"

void CreateListF(LinkList *& L, SqList L1, int n) {
	//ͷ�巨����������,��һ���ձ�ʼ,��ȡ˳���a�е�Ԫ��,�����½��,����ȡ�����ݴ�ŵ��½�����������,Ȼ���½����뵽��ǰ����ı�ͷ��, ֱ������Ϊֹ.
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));//����ͷ���
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));//�����½��
		s->data = L1.data[i];
		s->next = L->next;
		L->next = s;
	}
	/*
	//��һ��дʱ������д����β��,����ֻ��¼����β�ĵ�ַ��û�м�¼�������ʼλ��λ��,����ͷλ��,�Ҳ���ͷ���.//2019��7��24�� 21:27:19
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = L1.data[i];
		L->next = s;
	}
	L->next = NULL;
	*/
}

void CreateListR(LinkList *& L, SqList L1, int n) {
	LinkList *s, *r;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = L1.data[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int LocateElem(LinkList * L, int e) {
	LinkList *p = L->next;
	int n = 1;
	while (p != NULL && p->data != e) {
		p = p->next;
		n++;
	}
	if (p == NULL) return 0;
	else return n;
}

void InsertElem(LinkList *& L, int x, int i) {//��Ϊ��������һ������������һ�����,���ͷ���ָ������ܻᱻ�޸�
	LinkList *s, *p = L;
	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = x;
	for (int j = 0; j < i - 1; j++) {//��һ��дʱint i = 0�� �Ѵ��ݽ�������ʽ������ֵ���ǵ���;
		p = p->next;
		if (p->next == NULL && j != i - 2) {
			printf_s("Insert location is wrong!\n");
			return;
		};//���ǲ���λ�ò��Ե����
	}
	s->next = p->next;
	p->next = s;
}

void DispLinkList(LinkList * L) {
	if (L == NULL) {//2019��8��3�� 21:22:57 Ϊ��Ӧ����2-3-34ɾ�������н��(����ͷ���)���ӵ��ж����
		printf_s("The LinkList is empty and have no head node.\n");
		return;
	}
	LinkList *p = L->next;
	int n = 0;
	printf_s("The LinkList is :");
	while (p != NULL) {
		printf_s("%3d ", p->data);//��һ��д����L->data;
		n++;
		p = p->next;
	}
	printf_s("\n");
	printf_s("The Length is : %d", n);
	printf_s("\n");
}

void DeleteNode(LinkList *& L, int i) {
	LinkList *s, *p = L;
	for (int j = 0; j < i - 1; j++) {
		p = p->next;
		if (p->next == NULL) {
			printf_s("Delete location is wrong!\n");
			return;
		}
	}
	s = p->next;
	p->next = s->next;
	free(s);
}

void MergeLinkList(LinkList * L1, LinkList * L2, LinkList *& L3) {
	//L1��L2�ϲ���һ���µĵ�����L3��,����ָ��p��q�ֱ��L1��L2�ĵ�һ�����ݽ�㿪ʼ,ֻҪp��q��δ��β����NULL,������һ��һ����,ÿ�αȽ�p��q��ָ������ݽ�����������ֵ��С,��Ϊ3�����:
	//	1)p��q��ָ�����ݽ�����������ֵ��ͬ,��L3�з��������½��,�������Ϊ��ǰp��ָ�����ݽ������������ֵ,Ȼ��p��q�ֱ�ָ��p��q�ĺ�̽��;
	//	2)p��ָ�����ݽ�����������ֵС��q��ָ�����ݽ�����������ֵ,��L3�з���һ���½��,������Ϊ��ǰp��ָ�����ݽ������������ֵ,Ȼ��pָ��p�ĺ�̽��;
	//	3)q��ָ�����ݽ�����������ֵС��p��ָ�����ݽ�����������ֵ,��L3�з���һ���½��,������Ϊ��ǰq��ָ�����ݽ������������ֵ,Ȼ��qָ��q�ĺ�̽��;
	//��p��q����һ������β����NULL,������ж�,��δ����NULL��L1/L2���ν�ʣ������ӵ�L3��β��������Ϊβ��Ԫ��.
	LinkList *p = L1->next, *q = L2->next, *t, *s;
	L3 = (LinkList *)malloc(sizeof(LinkList));
	L3->next = NULL;
	t = L3;
	while (p != NULL && q != NULL) {
		if (p->data == q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			p = p->next;
			q = q->next;
			s->next = t->next;//�𰸺����Ƿ�����������,ǰ��Ӳ��Ӳ�Ӱ��
			t->next = s;
			t = s;
			//free(s);//������һ����쳣����
			s = (LinkList *)malloc(sizeof(LinkList));//�ǳ���Ҫ,���ӾͲ�����;
			s->data = t->data;
			s->next = t->next;
			t->next = s;
			t = s;
		}
		else if (p->data < q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			p = p->next;
			s->next = t->next;
			t->next = s;
			t = s;
		}
		else {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = q->data;
			q = q->next;
			s->next = t->next;
			t->next = s;
			t = s;
		}
	}
	while (p != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = p->data;
		p = p->next;
		s->next = t->next;
		t->next = s;
		t = s;
	}
	while (q != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = q->data;
		q = q->next;
		s->next = t->next;
		t->next = s;
		t = s;
	}
	t->next = NULL;
}