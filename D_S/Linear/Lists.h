#pragma once
#include "pch.h"

//表头表尾存储结构
typedef struct glnode1 {
	int tag;//0或1, 0表示原子结点, 1表示表/子表结点
	struct glnode1 *tail;//由于表尾也是一个广义表,所以任何表尾(若存在)都是一个带表结点的子表.
	union {
		int data;//原子的值
		struct glnode1 *head;//指向表头的指针
	}val;
}GLNODE1;