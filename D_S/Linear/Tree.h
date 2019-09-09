#pragma once

#include "pch.h"
#include <cstdio>
#include <cstdlib>

//���Ĵ洢�ṹ
//	1).˫�״洢�ṹ.ȱ��:��ĳ�����ĺ��ӽ��ʱ��Ҫ���������ṹ
//˳��洢�ṹ, ��һ�������ռ�洢�������н��, ͬʱ�ڽ���и���һ��αָ��ָʾ��˫�׽���λ��(����λ�ö��ǲ���).
typedef struct {
	int data;//������
	int pos;//˫����
} STree[MaxSize];

//	2).�������洢�ṹ,ȱ��:�˷ѽ϶��ָ��ռ�,�ӵ�ǰ������˫�׽��Ƚ��鷳.
//�������洢�ṹ�����Ķ�(���������н��ȵ����ֵ)��ƽ��ĺ��ӽ��ָ�������.
typedef struct TNode {
	int data;//������
	struct TNode *child[M];//����ָ����,MΪ���Ķ�,�ó���M��pch.h�ж���Ϊconstexpr auto M = 3;
}CTree;

//	3).�����ֵ����洢�ṹ,�ɷ����ʵ�����Ͷ��������໥ת��.ȱ��:�ӵ�ǰ������˫�׽��Ƚ��鷳.
//ÿ��������3����: һ������Ԫ����, һ���ý��ĵ�һ�����ӽ��ָ����, һ���ý�����һ���ֵܽ��ָ����.
typedef struct CBNode {
	int data;//������
	struct CBNode *child;//����ָ����
	struct CBNode *brother;//�ֵ�ָ����
}CBTree;