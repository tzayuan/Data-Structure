#pragma once
#include "pch.h"

//��ͷ��β�洢�ṹ
typedef struct glnode1 {
	int tag;//0��1, 0��ʾԭ�ӽ��, 1��ʾ��/�ӱ���
	struct glnode1 *tail;//���ڱ�βҲ��һ�������,�����κα�β(������)����һ����������ӱ�.
	union {
		int data;//ԭ�ӵ�ֵ
		struct glnode1 *head;//ָ���ͷ��ָ��
	}val;
}GLNODE1;