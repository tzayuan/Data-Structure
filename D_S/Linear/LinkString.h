#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
//������֯��ʽ��һ��ĵ���������.��Ҫ��������,�����н��洢���ֻ���ַ�ֵ.ͨ����������ÿ��������洢���ַ�������Ϊ����С.
//���Խ��,�洢�ܶ�Խ��,��֮��������(��ɾ�ĵ�)�Ĳ���,�ҿ�����������ַ��ƶ�.
//���ԽС(�����СΪ1),���㴦��Խ����,�洢�ܶ��½�,Ϊ����,ѧϰ����ϰʱ�涨������СΪ1.
typedef struct snode {
	char data;
	struct snode *next;
}LiString;

void LiStrAssign(LiString *&s, char t[]);//s����Ϊ��ͷ���ĵ�����
void StrCopy(LiString *&s, LiString *t);
int LiStrLength(LiString *s);
LiString *LiStrConcat(LiString *s, LiString *t);//ͨ��������Ҫ*�������struct�ṹ��ǰ��snode�ͽṹ����LiString;
LiString *SubLiStr(LiString *s, int i, int j);
LiString *InsLiStr(LiString *s, int i, LiString *t);
LiString *DelLiStr(LiString *s, int i, int j);
void DispLiStr(LiString *s);