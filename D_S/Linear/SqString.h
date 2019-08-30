#pragma once
#include "pch.h"
#include <cstdio>
typedef struct SqString {
	char ch[MaxSize];
	int Length;
}SqString;

SqString InitStr();//初始化一个串s.
void StrAssign(SqString &str, char cstr[]);//将一个字符串常量cstr赋给串str,即生成一个其值等于cstr的串s.
void StrCopy(SqString &s, SqString t);//将串t复制给串s.
int StrLength(SqString s);//返回串s中字符的个数.
SqString Concat(SqString s, SqString t);//串连接的算法
SqString SubStr(SqString s, int i, int j);//返回串s中从第i(1<=i<=n)个字符开始的,由连续j个字符组成的子串.
SqString InsStr(SqString s1, int i, SqString s2);//将串s2插入到串s1的第i个字符中.
SqString DelStr(SqString s, int i, int j);//从串s中删去第i个字符开始的长度为j的子串,并返回产生的新串.
void DispStr(SqString s);//输出串s的所有元素值.
int BFMatching1(SqString s, SqString t);//Brute-Force Pattern Matching with i(Scanning s one by one), j(Scanning s) & k(Scanning t).
int BFMatching2(SqString s, SqString t);//Brute-Force Pattern Matching with i(Scanning s) & j(Scanning t), character k is used for return the final location of i.
//KMP算法
void GetNext(SqString t, int next[]);
int KMPIndex(SqString s, SqString t);
