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