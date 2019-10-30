#include "pch.h"
#include "Search.h"


int SeqSearch(SeqList R, int length, KeyType key) {
	//	顺序查找
	//	ASL_seq=(n+1)/2
	//	T(n)=O(n)
	int i = 0;
	while (i < length && R[i].key != key) {
		i++;
	}
	if (i >= length) return -1;
	else return i;
}

int BinSearch(SeqList R, int length, KeyType key) {
	//	二分查找
	//	ASL_bin=log2(n)
	//	T(n)=O(log2(n))
	int low = 0, high = length - 1, mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (R[mid].key == key) {
			return mid;
		}
		else if (R[mid].key < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int IdxSearch(IDX I, int IDXTableLength, SeqList R, int length, KeyType key) {
	//采用二分查找索引表,顺序查找线性表(块内子表)的分块查找算法;
	//索引表的长度为IDXTableLength,顺序表的长度为lenghth, 要查找的关键字值为key;
	//分块查找要求表中元素至少是分块有序的,即第n个块(n=1,2,3,...)的最小值大于第n-1个块的最大值
	//分块查找的算法效率介于顺序查找和二分查找之间.
	int low = 0, high = IDXTableLength - 1, mid, i;//为对索引表的关键字值进行二分查找做准备,建立low high mid,i作为若找到对应的索引表子块后的顺序查找的游标
	int subBlockLength = length / IDXTableLength;//subBlockLength为每块的记录个数
	while (low <= high) {//在索引表中对关键字进行二分查找,将找到的位置存放在low中
		//high必定会在最后进入括号内的特殊情况(即索要查找的key值与当前mid的关键字值相等的情况,也包括当前high所在的子块即为最终找到的子块时),此时将必定走到应在子块的前一个子块的位置,此时接下来的所有新的mid都将小于所要查找的关键字值,
		//则low每次循环low++,直至low>high退出while循环,也即刚好处于极端情况下应在子块的位置,此时low的值为所要查找的子块的位置.
		mid = (low + high) / 2;
		if (I[mid].key >= key) {
			high = mid - 1;
		}
		else {// if (I[mid].key < key)
			low = mid + 1;
		}
	}
	if (low < IDXTableLength) {//在索引表中查找成功后,对该子块进行顺序查找
		i = I[low].link;
		while (i <= I[low].link + subBlockLength - 1 && R[i].key != key) {
			i++;
		}
		if (i <= I[low].link + subBlockLength - 1) {
			return i;//返回顺序查找第一个关键字值为key的元素的下标
		}
		else {
			return -1;
		}
	}
	return -1;//对应索引表查找不成功的情况,确保所有情况都能够return.
}