#include "pch.h"
#include "Search.h"


int SeqSearch(SeqList R, int length, KeyType key) {
	//	˳�����
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
	//	���ֲ���
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
	//���ö��ֲ���������,˳��������Ա�(�����ӱ�)�ķֿ�����㷨;
	//������ĳ���ΪIDXTableLength,˳���ĳ���Ϊlenghth, Ҫ���ҵĹؼ���ֵΪkey;
	//�ֿ����Ҫ�����Ԫ�������Ƿֿ������,����n����(n=1,2,3,...)����Сֵ���ڵ�n-1��������ֵ
	//�ֿ���ҵ��㷨Ч�ʽ���˳����ҺͶ��ֲ���֮��.
	int low = 0, high = IDXTableLength - 1, mid, i;//Ϊ��������Ĺؼ���ֵ���ж��ֲ�����׼��,����low high mid,i��Ϊ���ҵ���Ӧ���������ӿ���˳����ҵ��α�
	int subBlockLength = length / IDXTableLength;//subBlockLengthΪÿ��ļ�¼����
	while (low <= high) {//���������жԹؼ��ֽ��ж��ֲ���,���ҵ���λ�ô����low��
		//high�ض����������������ڵ��������(����Ҫ���ҵ�keyֵ�뵱ǰmid�Ĺؼ���ֵ��ȵ����,Ҳ������ǰhigh���ڵ��ӿ鼴Ϊ�����ҵ����ӿ�ʱ),��ʱ���ض��ߵ�Ӧ���ӿ��ǰһ���ӿ��λ��,��ʱ�������������µ�mid����С����Ҫ���ҵĹؼ���ֵ,
		//��lowÿ��ѭ��low++,ֱ��low>high�˳�whileѭ��,Ҳ���պô��ڼ��������Ӧ���ӿ��λ��,��ʱlow��ֵΪ��Ҫ���ҵ��ӿ��λ��.
		mid = (low + high) / 2;
		if (I[mid].key >= key) {
			high = mid - 1;
		}
		else {// if (I[mid].key < key)
			low = mid + 1;
		}
	}
	if (low < IDXTableLength) {//���������в��ҳɹ���,�Ը��ӿ����˳�����
		i = I[low].link;
		while (i <= I[low].link + subBlockLength - 1 && R[i].key != key) {
			i++;
		}
		if (i <= I[low].link + subBlockLength - 1) {
			return i;//����˳����ҵ�һ���ؼ���ֵΪkey��Ԫ�ص��±�
		}
		else {
			return -1;
		}
	}
	return -1;//��Ӧ��������Ҳ��ɹ������,ȷ������������ܹ�return.
}

LBTNode *BSTSearch(LBTNode *bt, KeyType key) {
	//���ҽ����㷨
	//�㷨˼·:�ö������������ö�����ʽ�洢�ṹ,��bt��ָ��ĸ���㿪ʼ�ݹ�������Ŷ�����,ֱ���ҵ���Ӧ����ֱ��Ҷ�ӽ�㶼�����������򷵻�NULL��δ�ҵ�
	//�����жϵ�ǰ���������Ľ���Ƿ�ΪNULL,��ΪNULL,��ֱ�ӷ���NULL,��ʾδ�ҵ��ؼ���ֵΪkey�Ľ��;
	//����ǰ�������ĵĹؼ���ֵ������Ҫ���ҵ�keyֵ,�򷵻ظý��,�����ҵ��˹ؼ���ֵΪkey�Ľ��
	//����,��keyֵС��Ҫ��ǰ�������Ľ��Ĺؼ���ֵ,����ƽ����������߼��ṹ,�ݹ�ú�������,btΪ��ǰ�������ӽ��;
	//�������������,��keyֵ���ڵ�ǰ�������Ľ��Ĺؼ���ֵ,��ݹ�ú�������,btΪ��ǰ�����Һ��ӽ��;
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
	//�����������Ľ������㷨
	//ƽ��ʱ�临�Ӷ�ΪO(log2(n))
	//�㷨˼·:���Խ�������̿���һ������������֪����������(����һ�ſ���)ֱ���ùؼ��ָò�����߼�λ��,��ĳҶ�ӽ������ӽ����Һ��ӽ��(ע����ʵ��ʱ�ú��ӽ��ΪNULL,���߼���Ӧ�ò����λ��)
	if (p == NULL) {
		p = (LBTNode *)malloc(sizeof(LBTNode));//��ָ��NULL��ָ�븳ֵ??�����ǿ���...�����������?������Ҫ������֤.
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
	//�����������Ĺ����㷨
	//�㷨˼·:�����øö����������ĸ����ΪNULL,��Ϊ����.����LBTInsert������str��������йؼ���ֵ���ΰ��ն������������߼��ṹ���β����㵽����������bt��
	bt = NULL;
	for (int i = 0; i < n; i++) {
		LBTInsert(bt, str[i]);
	}
}

int LBTDelete(LBTNode *& bt, KeyType key) {
	//ɾ�������㷨
	//ƽ��ʱ�临�Ӷ�ΪO(log2(n))
}
