#pragma once
#include "pch.h"
#include <cstdio>
#include <cstdlib>
//链串组织形式与一般的单链表类似.主要区别在于,链串中结点存储存放只是字符值.通常将链串中每个结点所存储的字符个数称为结点大小.
//结点越大,存储密度越大,随之带来操作(增删改等)的不便,且可能引起大量字符移动.
//结点越小(如结点大小为1),运算处理越方便,存储密度下降,为简明,学习和练习时规定链串大小为1.
typedef struct snode {
	char data;
	struct snode *next;
}LiString;

void LiStrAssign(LiString *&s, char t[]);//s创建为带头结点的单链表
void StrCopy(LiString *&s, LiString *t);
int LiStrLength(LiString *s);
LiString *LiStrConcat(LiString *s, LiString *t);//通过这里需要*函数体会struct结构体前的snode和结构体后的LiString;
LiString *SubLiStr(LiString *s, int i, int j);
LiString *InsLiStr(LiString *s, int i, LiString *t);
LiString *DelLiStr(LiString *s, int i, int j);
void DispLiStr(LiString *s);