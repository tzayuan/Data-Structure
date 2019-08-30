#include "pch.h"
#include "SqString.h"

SqString InitStr()
{
	SqString str;
	str.Length = 0;
	return str;
}

void StrAssign(SqString &str, char cstr[]) {
	//该算法将一个char字符串复制到string中的char字符串中,String与char相比,String结构体数据类型中多了一个变量Length保存该串的长度.
	int i;
	for (i = 0; cstr[i] != '\0'; i++) {
		str.ch[i] = cstr[i];
	}
	str.Length = i;
}

void StrCopy(SqString &s, SqString t) {
	//与StrAssign相比,该算法不是将char字符串复制到String中,而是将一个String复制到另一个String中,注意两者的区分不同.
	for (int i = 0; i < t.Length; i++) {
		s.ch[i] = t.ch[i];
	}
	s.Length = t.Length;
}

int StrLength(SqString s) {
	return s.Length;
}

SqString Concat(SqString s, SqString t) {
	SqString str;
	for (int i = 0; i < s.Length; i++) {
		str.ch[i] = s.ch[i];
	}
	for (int i = 0; i < t.Length; i++) {
		str.ch[i + s.Length] = t.ch[i];
	}
	str.Length = s.Length + t.Length;
	return str;
}

SqString SubStr(SqString s, int i, int j) {
	SqString str;
	str.Length = 0;//例5-2-8中,若str初始化不给Length域赋值为0,则会报错.
	if (i < 1 || i > s.Length || j <0 || i + j - 1 > s.Length) return str;//第一次写时i > s.Length写成了i < s.Length
	for (int k = i - 1; k < i + j - 1; k++) {
		str.ch[k - i + 1] = s.ch[k];
	}
	str.Length = j;
	return str;
}

SqString InsStr(SqString s1, int i, SqString s2) {
	SqString str;
	str.Length = 0;
	if (i < 1 || i > s1.Length + 1) return str;
	for (int j = 0; j < i - 1; j++) {
		str.ch[j] = s1.ch[j];
	}
	for (int j = 0; i < s2.Length; j++) {
		str.ch[j + i - 1] = s2.ch[j];
	}
	for (int j = i - 1; j < s1.Length; j++) {
		str.ch[s2.Length + j] = s1.ch[j];
	}
	str.Length = s1.Length + s2.Length;
	return str;
}

SqString DelStr(SqString s, int i, int j) {
	SqString str;
	str.Length = 0;
	if (i < 1 || i > s.Length || i + j - 1 > s.Length) return str;
	for (int k = 0; k < i - 1; k++) {
		str.ch[k] = s.ch[k];
	}
	for (int k = i + j - 1; k < s.Length; k++) {
		str.ch[k - j] = s.ch[k];
	}
	str.Length = s.Length - j;
	return str;
}

void DispStr(SqString s) {
	if (s.Length > 0) {
		for (int i = 0; i < s.Length; i++) {
			printf_s("%c", s.ch[i]);
		}
		printf_s("\n");
		printf_s("The Length is : %d", s.Length);
		printf_s("\n");
	}
}

int BFMatching1(SqString s, SqString t) {
	int i = 0, j, k;
	while (i < s.Length) {
		for (j = i, k = 0; s.ch[j] == t.ch[k] && j < s.Length && k < t.Length; j++, k++);
		if (k == t.Length) return i;
		i++;
	}
	return -1;
}

int BFMatching2(SqString s, SqString t) {
	int i = 0, j = 0, k;
	while (i < s.Length && j < t.Length) {
		if (s.ch[i] == t.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.Length) k = i - t.Length;
	else k = -1;
	return k;
}

void GetNext(SqString t, int next[]) {
	int j = 0, k = -1;
	next[0] = -1;

}

int KMPIndex(SqString s, SqString t) {
	int next[MaxSize], i = 0, j = 0, v;
	GetNext(t, next);
	while (i < s.Length && j < t.Length) {
		if (j = -1 || s.ch[i] == t.ch[j]) {
			i++;j++;
		}
		else j = next[j];
	}
	if (j >= t.Length) v = i - t.Length;
	else v = -1;
	return v;
}