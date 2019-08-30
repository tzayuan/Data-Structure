#include "pch.h"
#include "LinkString.h"

void LiStrAssign(LiString *& s, char t[]) {
	LiString *p, *r;;
	s = (LiString *)malloc(sizeof(LiString));
	s->next = NULL;
	r = s;
	for (int i = 0; t[i] != '\0'; i++) {
		p = (LiString *)malloc(sizeof(LiString));
		p->data = t[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void StrCopy(LiString *& s, LiString * t) {
	LiString *q, *r, *p = t->next;
	s = (LiString *)malloc(sizeof(LiString));
	s->next = NULL;
	r = s;
	while (p != NULL) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	r->next = NULL;
}

int LiStrLength(LiString * s) {
	LiString *p = s;
	int count = 0;
	while (p->next != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

LiString *LiStrConcat(LiString * s, LiString * t) {
	LiString *str, *r, *q, *p = s->next;
	str = (LiString *)malloc(sizeof(LiString));
	str->next = NULL;
	r = str;
	while (p != NULL) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	p = t->next;
	while (p != NULL) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	r->next = NULL;
	return str;
}

LiString * SubLiStr(LiString * s, int i, int j) {
	LiString *str = (LiString *)malloc(sizeof(LiString)), *p = s->next, *q, *r;
	str->next = NULL;
	r = str;
	if (i <= 0 || i + j - 1 > LiStrLength(s)) return str;
	for (int k = 0; k < i - 1; k++) {
		p = p->next;
	}
	for (int k = 0; k < j; k++) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	r->next = NULL;
	return str;
}

LiString * InsLiStr(LiString * s, int i, LiString * t) {
	LiString *str = (LiString *)malloc(sizeof(LiString)), *p = s->next, *p1 = t->next, *q, *r;
	str->next = NULL;
	r = str;
	if (i <= 0 || i > LiStrLength(s) + 1) return str;
	for (int k = 0; k < i - 1; k++) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	while (p1 != NULL) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p1->data;
		p1 = p1->next;
		r->next = q;
		r = q;
	}
	while (p != NULL) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	r->next = NULL;
	return str;
}

LiString * DelLiStr(LiString * s, int i, int j) {
	LiString *str = (LiString *)malloc(sizeof(LiString)), *p = s->next, *q, *r;
	str->next = NULL;
	r = str;
	if (i <= 0 || i + j - 1 > LiStrLength(s)) return str;
	for (int k = 0; k < i - 1; k++) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	for (int k = 0; k < j; k++) {
		p = p->next;
	}
	while (p != NULL) {
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		p = p->next;
		r->next = q;
		r = q;
	}
	r->next = NULL;
	return str;
}

void DispLiStr(LiString * s) {
	LiString *p = s->next;
	int count = 0;
	while (p != NULL) {
		printf_s("%c", p->data);
		p = p->next;
		count++;
	}
	printf_s("\n");
	printf_s("The Length is : %d", count);
	printf_s("\n");
}