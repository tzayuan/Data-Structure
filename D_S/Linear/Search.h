#pragma once
#include "pch.h"

//˳�������������,Ӧ�������Ա��е�˳����ҺͶ��ֲ���(��˳���Ϊ�洢�ṹ)
typedef struct SearchNodeType {
	KeyType key;
	SearchInfoType data;
} SearchNodeType;
typedef SearchNodeType SeqList[MaxSize];

//˳���/�����������������,Ӧ�������Ա��еķֿ����(����������˳���Ϊ�洢�ṹ)
typedef struct IdxType{
	KeyType key;
	int link;
} IdxType;
typedef IdxType IDX[MaxSize];

//���Ա�Ĳ����㷨
//˳����ҡ����ֲ��ҡ��ֿ����
//ƽ�����ҳ���:���ֲ���<�ֿ����<˳�����
//�洢�ṹ:˳����ҡ��ֿ����������˳���/�������;���ֲ��ҽ�������˳���;
//����߼��ṹ:˳����ҵ����Ա������������;���ֲ��ҽ������������;�ֿ��������Ҫ�����Ա������Ԫ�طֿ�����,����n����(n=1,2,3,...)����Сֵ���ڵ�n-1��������ֵ
//����,�ֿ�����ۺ���˳����ҺͶ��ֲ��ҵ��ŵ�,���ܹ��Ͽ��ٵز���,������Ӧ��̬�仯��Ҫ��.���Ƕ��������˱���������Ŀ���.
//��������⡿�������������ڴ�����,��Ȼ�����˴��̵Ŀ���,��ͨ������������key,����ٴ���I/O����,������һ��B-Tree���߼��ṹ,���Ӷ�·ƽ�������������
//˳�����
int SeqSearch(SeqList R, int length, KeyType key);//2019��10��10�� 11:37:20
//���ֲ���
int BinSearch(SeqList R, int length, KeyType key);//2019��10��10�� 11:37:22
//�ֿ����(���ö��ֲ���������,˳����ҿ���˳��������еķֿ�����㷨)
int IdxSearch(IDX I, int IDXTableLength, SeqList R, int length, KeyType key);//2019��10��29�� 20:54:42

//����Ĳ���
//����������(Binary sort tree,BST)��ƽ�������(AVL��,AVL�����������ķ�����G. M. Adelson-Velsky��E. M. Landis)��B-Tree��B+��
//����������
LBTNode *BSTSearch(LBTNode *bt, KeyType key) {

}
//��ĳ�����������Ľ����������,���õ�һ��key�������������


//��ϣ��Ĳ���

