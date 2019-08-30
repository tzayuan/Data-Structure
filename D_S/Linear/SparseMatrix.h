#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
typedef struct {
	int i;
	int j;
	int data;
}TupNode;

typedef struct {
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;