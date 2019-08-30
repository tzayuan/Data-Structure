#pragma once
#include "pch.h"
#include <cstdio>
typedef struct SqString {
	char ch[MaxSize];
	int Length;
}SqString;

SqString InitStr();//��ʼ��һ����s.
void StrAssign(SqString &str, char cstr[]);//��һ���ַ�������cstr������str,������һ����ֵ����cstr�Ĵ�s.
void StrCopy(SqString &s, SqString t);//����t���Ƹ���s.
int StrLength(SqString s);//���ش�s���ַ��ĸ���.
SqString Concat(SqString s, SqString t);//�����ӵ��㷨
SqString SubStr(SqString s, int i, int j);//���ش�s�дӵ�i(1<=i<=n)���ַ���ʼ��,������j���ַ���ɵ��Ӵ�.
SqString InsStr(SqString s1, int i, SqString s2);//����s2���뵽��s1�ĵ�i���ַ���.
SqString DelStr(SqString s, int i, int j);//�Ӵ�s��ɾȥ��i���ַ���ʼ�ĳ���Ϊj���Ӵ�,�����ز������´�.
void DispStr(SqString s);//�����s������Ԫ��ֵ.
int BFMatching1(SqString s, SqString t);//Brute-Force Pattern Matching with i(Scanning s one by one), j(Scanning s) & k(Scanning t).
int BFMatching2(SqString s, SqString t);//Brute-Force Pattern Matching with i(Scanning s) & j(Scanning t), character k is used for return the final location of i.
//KMP�㷨
void GetNext(SqString t, int next[]);
int KMPIndex(SqString s, SqString t);
