/* 
Function:
    Some simulation of Data Structure's algorithms;
New Learning:
    #define without ";"
Date:
	1)2019年7月11日 00:05:26 Linear List;
	2)2019年7月17日 14:37:48 Rewrittering Linear List;
	3)2019年7月18日 07:32:55 KMP Algorithm;
	4)2019年7月18日 20:53:44 Sequence list;
	5)2019年7月18日 22:07:42 Pattern Matching BF Algorithm & a part of KMP;
	6)2019年7月19日 22:17:33 E.X. 2-2-10
	7)2019年11月25日 20点48分 升级至Visual Studio Community 2019;
*/

#include "pch.h"

//SequenceList
void insert2210_czy(SqList &L, int x);//2019年7月19日 22:17:23;
void reverse2211_czy(SqList &L);//2019年7月22日 19:46:34
void delete2212_czy(SqList &L, int x);//2019年7月22日 21:07:17
void delete2212_2rd(SqList &L, int x);//2019年7月22日 22:05:07
void delete2212_3rd(SqList &L, int x);//2019年7月22日 22:14:35
void deletexy2213_czy(SqList &L, int x, int y);//2019年7月22日 22:38:42
void deletexy2213_czy_2rd(SqList &L, int x, int y);//2019年7月23日 19:37:46
void move2214_czy(SqList &L);//2019年7月23日 19:55:39
void move2214_2rd(SqList &L);//2019年7月23日 20:06:22
void deleteSame2215_czy(SqList &L);//2019年7月23日 20:23:29
void deleteSame2215_2rd(SqList &L);//2019年7月23日 20:56:16
SqList intersaction2216_czy(SqList L1, SqList L2);//2019年7月23日 21:17:53
SqList unionAlg2217_czy(SqList L1, SqList L2);//2019年7月23日 21:33:52
SqList diffSet2218_czy(SqList L1, SqList L2);//2019年7月23日 22:00:06
SqList Merge2219_1_czy(SqList L1, SqList L2);//2019年7月24日 20:10:37
void Merge2219_2_czy(SqList L1, SqList &L2);//2019年7月24日 20:33:14
SqList Merge2219_3_czy(SqList L1);//2019年7月24日 20:33:14

//SingleLinkedList
void deleteMinNode(LinkList *&L);//2019年8月4日 19:35:01
int deleteX2317_czy(LinkList *L, int x);//2019年7月26日 22:39:13
void splitLinkList2318_czy(LinkList *hc, LinkList *&ha, LinkList *&hb);//2019年7月27日 22:34:35


//void MergeLinkList(LinkList * L1, LinkList * L2, LinkList *& L3);//2319, 该基本算法即为2-3-19的算法
int deleteNode2320_czy(LinkList *L, int min, int max);//2019年7月28日 22:38:37
void deleteNode2320_2rd(LinkList *&L, int min, int max);//2019年7月29日 23:05:53
void deleteNode2321_czy(LinkList *&L, int min, int max);//2019年7月30日 21:57:40
void deleteNode2322_czy(LinkList *&L);//2019年7月31日 20:27:42
void deleteNode2323_czy(LinkList *&L);//2019年7月31日 20:45:11
int isIncrease2324_czy(LinkList *L);//2019年7月31日 20:56:52
void LinkListMergeSort();//排序算法,暂时跳过
void deleteMinNode2326_czy(LinkList *L);//2019年7月31日 21:16:38
void reverseLinkList2327_czy(LinkList *&L);//2019年7月31日 21:48:53
void interset2328_czy(LinkList *A, LinkList *B, LinkList *&C);//2019年7月31日 22:38:16(头插法)
void diffset2329_czy(LinkList *A, LinkList *B, LinkList *&C);//2019年8月1日 21:24:33
void unionset2330_czy(LinkList *A, LinkList *B, LinkList *&C);//2019年8月1日 21:47:03
void interset2331_czy(LinkList *A, LinkList *B, LinkList *&C);//2019年8月2日 21:48:48
void unionsetIncrease2331_czy(LinkList *A, LinkList *B, LinkList *&C);//2019年8月2日 22:28:47
void operator2331_czy_ref(LinkList *A, LinkList *B, LinkList *C, LinkList *&D, LinkList *&E);//2019年8月2日 22:33:10//时间复杂度比较特殊,值得探究和思考,以对时间复杂度O()表示法的定义有再次的复习
void operator2331_2rd(LinkList *&A, LinkList *B, LinkList *C);
void inorderList2332_czy(LinkList *&L, int x);//2019年8月2日 22:58:00
void splitTwo2333_czy(LinkList *&A, LinkList *&B);//2019年8月3日 20:59:35
void deleteAllNode2334_czy(LinkList *&h);//2019年8月3日 21:11:38
void deleteAllNode2334_2rd(LinkList *&h);//2019年8月3日 21:35:58
void pubSolo2335_czy(LinkList *&A, LinkList *B, LinkList *C);//2019年8月4日 00:31:01
void isSubSeq2336_czy(LinkList *A, LinkList *B);//模式匹配, Brute-Force Matching Alogorithm & KMP Matching Alogorithm(2019年8月3日 21:40:51)

//DoubleLinkedList
void insBefore2410_1_czy(DLinkList *&L, int x, int y);//2019年8月5日 22:24:58
void insAfter2410_2_czy(DLinkList *L, int x, int y);//2019年8月5日 22:40:25
void swapDListNode2411_czy(DLinkList *h, int x);//2019年8月6日 21:40:29
void swapDListNode2411_2rd(DLinkList *h, int x);//2019年8月6日 21:54:23
void locateDListNode2412_czy(DLinkList_2412 *h, int x);//2019年8月6日 22:10:51
void locateDListNode2412_2rd(DLinkList_2412 *h, int x);//2019年8月7日 22:35:17

//CirculatingSingleLinkedList
void invertList2513_czy(LinkList *&head);//2019年8月10日 20:48:55
void invertList2513_2rd(LinkList *&head);//2019年8月10日 21:08:33

//CirculatingDoubleLinkedList
void deleteCDListNode2514_czy(DLinkList *&L, int x);//2019年8月10日 21:16:55
void swapCDListNode2515_czy(DLinkList *&L, int x);//2019年8月10日 21:25:44
void reverseCDList2516_czy(DLinkList *&L);//2019年8月10日 21:42:22
void reverseCDList2516_2rd(DLinkList *&L);//2019年8月10日 21:55:24

//SequenceStack
int bracketMatch3207_czy(char exp[]);//2019年8月15日 20:12:21
void isPopSq3208_ans(int pos, int path[], int curp, int total, SqStack seq);
void initSharedStack3209_1_czy(sharedSt &sst);//2019年8月15日 21:41:24
int isEmptySharedStack2309_2_czy(sharedSt sst, int i);//2019年8月15日 21:44:30
int pushSharedStack2309_3_czy(sharedSt &sst, int i, int x);//2019年8月15日 21:50:27
int popSharedStack2309_4_czy(sharedSt &sst, int i, int &x);//2019年8月15日 21:55:37
int stackBottom3210_czy(SqStack st);//2019年8月15日 22:26:30
void mazePath2311_czy2();

//LinkedStack
int judge338_czy(int A[], int n);//2019年8月16日 20:50:39
int nodeCount339_czy(LStackNode *lst);//2019年8月16日 21:07:39
//void WithoutHead3310_czy();//见LinkStack.h

//Recursion


//SequenceQueue
int rearQueue4210_czy(SqQueue qu);//2019年8月17日 21:41:29
//4-2-11见SqQueue.h
//4-2-12见SqQueue.h
//4-2-13见SqQueue.h,迷宫问题,暂未做

//LinkedQueue
//4-3-11见LinkQueue.h
void Insert4312_czy(LQNode *QH[], LQNode *QT[], int x);//2019年8月20日 21:59:25
void Create4312_czy(LQNode *QH[], LQNode *QT[]);//2019年8月20日 21:59:27
void Link4312_czy(LQNode *QH[], LQNode *QT[]);//2019年8月20日 21:59:29
void SeeDoctor4313_czy();//2019年8月21日 11:19:40

//SequenceString
void count525_czy(SqString s);//2019年8月21日 21:09:05
SqString RepStr526_czy(SqString s, int i, int j, SqString t);//2019年8月21日 22:38:31
int StrCmp527_czy(SqString s, SqString t);//2019年8月22日 19:29:12//感觉题目设定不全
//SequenceString with recursion
int Find528_ans(SqString s, char x);//2019年8月22日 20:30:09!!!!!!!!--------!!!!!!!!!!!!!!-----------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------
void reverse529_ans(SqString &s);//2019年8月22日 20:35:53!!!!!!!!!!!--------!!!!!!!!!!!!!!-----------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------

//LinkedString
LiString *RepLiStr533_czy(LiString *s, int i, int j, LiString *t);//2019年8月23日 09:33:46
void delSubLiStr534_czy(LiString *&s);//2019年8月23日 09:53:31
int isIncreaseLiStr535_czy(LiString *s);//2019年8月23日 20:55:50

//Array
int findk6116_czy(int i, int j);//2019年8月27日 21:35:29对答案有疑义
int findij6116_czy(int k, int &i, int &j);//2019年8月27日 22:23:07
void move6117_czy(int A[], int n);//2019年8月27日 22:23:05
void Find(int B[M6118][N6118], int x, int &i, int &j);//2019年8月27日 22:23:04

//Sparse Matrix

//Binary Tree

//Search
LBTNode *LBTSearch10228_czy(LBTNode *bt, KeyType key);

//Sort

//Shandong Normal University previous exam papers, Data structure A, Algorithm design
void deleteDuplicatedNode_SDNU_2011_1_czy(LinkList *L);//LinkList//2019年11月18日 22:16:59


int main() {
	srand((int)time(0));
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		deleteDuplicatedNode_SDNU_2011_1_czy(L1);
		DispLinkList(L1);

	/*
	//顺序表的练习及功能测试
	SqList L = InitSqlist();//定义一个线性表结构体变量并初始化线性表,置线性表的长度为0;
	ListInsert(L, 1, 3);
	ListInsert(L, 2, 3);
	printf_s("L.length = %d, L.data[0] = %d", L.length, L.data[0]);

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------
	//P25, 例2-2-10, 已知一个顺序表L,其中的元素递增有序排列,设计一个算法插入一个元素x后保持该顺序表仍递增有序排列.//MaxSize = 100000直接溢出？
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(100);
			ListInsert(L, i + 1, j);//random()不行？
		}
		SqListSort(L);
		DispSqlist(L);
		//ListInsert(L, 1, 0);
		//DispSqlist(L);
		int insertNum = random(100);
		printf_s("The inserted number is : %d\n", insertNum);
		insert2210_czy(L, insertNum);
		DispSqlist(L);
		printf_s("\n");
	}

	//P26, 例2-2-11, 设计一个算法，将顺序表的所有元素逆置,要求算法空间复杂度为O(1).
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(100);
			ListInsert(L, i + 1, j);//random()不行？
		}
		DispSqlist(L);
		reverse2211_czy(L);
		DispSqlist(L);
		printf_s("\n");
	}

	//P26, 例2-2-12, 设计一个算法,从顺序表中删除所有元素值为x的元素,要求空间复杂度为O(1).
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		DispSqlist(L);
		int randomNum = random(10);
		printf_s("The random number is : %d\n", randomNum);
		delete2212_3rd(L, randomNum);
		DispSqlist(L);
		printf_s("\n");
	}

	//P27, 例2-2-13, 设计一个算法,从一给定的顺序表L中删除元素值在x到y (x <= y) 之间的所有元素,要求以较高的效率来实现,空间复杂度为O(1).
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//random()不行？
		}
		DispSqlist(L);
		int numMin = random(10);
		int numMax = random(10);
		if (numMax < numMin) {
			int temp;
			temp = numMax;
			numMax = numMin;
			numMin = temp;
		}
		printf_s("The min number is : %d, the max number is : %d\n", numMin, numMax);
		deletexy2213_czy_2rd(L, numMin, numMax);
		DispSqlist(L);
		printf_s("\n");
	}

	//P27, 例2-2-14, 设有一个顺序表,其元素为整型数据,设计一个算法将L中所有的小于0的整数放在前半部分,大于等于0的整数放在后半部分.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20 - 10);
			ListInsert(L, i + 1, j);//random()不行？
		}
		DispSqlist(L);
		move2214_2rd(L);
		DispSqlist(L);
		printf_s("\n");
	}
	
	//P28, 例2-2-15, 设计一个算法从顺序表中删除重复的元素,并使剩余元素间的相对次序保持不变.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		DispSqlist(L);
		deleteSame2215_2rd(L);
		DispSqlist(L);
		printf_s("\n");
	}

	//P28, 例2-2-16, 用顺序表表示集合,设计一个算法实现集合的求交集运算.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(100);
			int k = random(100);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
		}
		DispSqlist(L1);
		DispSqlist(L2);
		SqList L3 = intersaction2216_czy(L1, L2);
		DispSqlist(L3);
		printf_s("\n");
	}

	//P29, 例2-2-16\17\18, 用顺序表表示集合,设计一个算法实现集合的求差集运算.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		for (int i = 0; i < 5; i++) {
			int j = random(10);
			int k = random(10);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
		}
		DispSqlist(L1);
		DispSqlist(L2);
		SqList L3 = diffSet2218_czy(L1, L2);
		DispSqlist(L3);
		printf_s("\n");
	}

	//P29, 例2-2-19-1, 用顺序表A和B表示的两个线性表,元素的个数分别为m和n,若表中数据都是由小到大顺序排列的,且这(m+n)个数据没有重复的.
	// 1) 设计一个算法将此两个线性表合并为一个,仍是数据由小到大排列的线性表,存储到另一个顺序表C中.
	// 2) 顺序表B的大小为(m+n)个单元,将合并成的线性表存放于顺序表B中,设计此算法.
	// 3) 设顺序表A有m+n个元素,且前m个有序,后n个有序,设计一个算法,使得整个顺序表有序.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		for (int i = 0; i < 5; i++) {
			int j = random(10);
			int k = random(10);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
		}
		SqListSort(L1);
		SqListSort(L2);
		DispSqlist(L1);
		DispSqlist(L2);
		MergeWithoutSort(L1, L2);
		DispSqlist(L1);
		SqList L3 = Merge2219_3_czy(L1);
		DispSqlist(L3);
		printf_s("\n");
	}

	//

	*/

	/*
	//单链表的练习及功能测试
	//
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		LinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		DispSqlist(L);
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		InsertElem(L1, 10, 8);
		DispLinkList(L1);
		DeleteNode(L1, 12);
		DispLinkList(L1);
		printf_s("\n");
	}

	//有序单链表的归并算法
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		LinkList *L3, *L4, *L5;
		for (int i = 0; i < 10; i++) {
			int j = random(20);
			int k = random(20);
			ListInsert(L1, i + 1, j);//直接random()不行？
			ListInsert(L2, i + 1, k);
		}
		SqListSort(L1);
		SqListSort(L2);
		CreateListR(L3, L1, L1.length);
		DispLinkList(L3);
		CreateListR(L4, L2, L2.length);
		DispLinkList(L4);
		MergeLinkList(L3, L4, L5);
		DispLinkList(L5);
		printf_s("\n");
	}

	//

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------
	//SDNU 2018 数据结构A 算法设计题 删除单链表L的最小值结点.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(50);
			ListInsert(L1, i + 1, j);//random()不行？
		}
		//SqListSort(L1);
		LinkList *L2;
		CreateListR(L2, L1, L1.length);
		DispLinkList(L2);
		deleteMinNode(L2);
		DispLinkList(L2);
		printf_s("\n");
	}

	//P38, 例2-3-17, 设计一个算法删除单链表L中值为x的结点的直接前驱结点.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		int k = random(20);
		printf_s("The random number is : %d \n", k);
		deleteX2317_czy(L1, k);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P39, 例2-3-18, 设C = {a1, b1, a2, b2, ... , an, bn}为一线性表,采用带头结点的hc单链表存放,设计一个就地算法,将其拆分层两个线性表,使得 A = {a1, a2, ... , an}, B = {b1, b2, ..., bn}.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1, *L2, *L3;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		splitLinkList2318_czy(L1, L2, L3);
		DispLinkList(L2);
		DispLinkList(L3);
		printf_s("\n");
	}

	//P40, 例2-3-20, 已知单链表L(带头结点)是一个递增有序表,设计一个高效算法,删除表中data值在大于或等于min且小于或等于max之间的结点(若表中有这样的结点),同时释放被删结点的空间,这里min和max是两个给定的参数.并分析算法的时间复杂度.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		SqListSort(L);
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		int numMin = random(20);
		int numMax = random(20);
		if (numMax < numMin) {
			int temp;
			temp = numMax;
			numMax = numMin;
			numMin = temp;
		}
		printf_s("The minimum number is : %d \n", numMin);
		printf_s("The maximum number is : %d \n", numMax);
		deleteNode2320_czy(L1, numMin, numMax);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P41, 例2-3-21, 已知单链表L(带头结点)是一个非有序表,设计一个算法,删除表中data值在大于或等于min且小于或等于max之间的结点(若表中有这样的结点),同时释放呗删除结点的空间,这里min和max是两个给定的参数.并分析算法的时间复杂度.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		int numMin = random(20);
		int numMax = random(20);
		if (numMax < numMin) {
			int temp;
			temp = numMax;
			numMax = numMin;
			numMin = temp;
		}
		printf_s("The minimum number is : %d \n", numMin);
		printf_s("The maximum number is : %d \n", numMax);
		deleteNode2321_czy(L1, numMin, numMax);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P41, 例2-3-22, 有一个递增单链表(允许出现值域重复的结点),设计一个算法删除值域重复的结点.并分析算法的时间复杂度.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		SqListSort(L);
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		deleteNode2322_czy(L1);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P41, 例2-3-23, 有一个非有序单链表(允许出现值域重复的结点),设计一个算法删除值域重复的结点.并分析算法的时间复杂度.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		deleteNode2323_czy(L1);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P42, 例2-3-24, 设计一个算法判定单链表L(带头结点)是否是递增的.	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		int a = isIncrease2324_czy(L1);
		DispLinkList(L1);
		printf_s("%d\n", a);
		printf_s("\n");
	}

	//P43, 例2-3-26, 设计一个在带头结点的单链表L中删除一个最小值结点的算法.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(200);
			ListInsert(L, i + 1, j);//random()不行？
		}
		SqListSort(L);
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		deleteMinNode2326_czy(L1);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P43, 例2-3-27, 有一个线性表(a1,a2,...,an),采用带头结点的单链表L存储,设计一个算法将其就地逆置.所谓"就地"指辅助空间应为O(1).
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(200);
			ListInsert(L, i + 1, j);//random()不行？
		}
		SqListSort(L);
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		reverseLinkList2327_czy(L1);
		DispLinkList(L1);
		printf_s("\n");
	}

	//P44, 例2-3-28, 用单链表表示集合,设计一个算法求两个集合的交.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			int k = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
		}
		SqListSort(L1);
		SqListSort(L2);
		LinkList *L3, *L4, *L5;
		L5 = (LinkList *)malloc(sizeof(LinkList));//第一次写时忘记加了
		L5->next = NULL;
		CreateListR(L3, L1, L1.length);
		CreateListR(L4, L2, L2.length);
		DispLinkList(L3);
		DispLinkList(L4);
		interset2328_czy(L3, L4, L5);
		DispLinkList(L5);
		printf_s("\n");
	}

	//P45, 例2-3-29, 用单链表表示集合,设计一个算法求两个集合的差.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			int k = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
		}
		SqListSort(L1);
		SqListSort(L2);
		LinkList *L3, *L4, *L5;
		L5 = (LinkList *)malloc(sizeof(LinkList));//第一次写时忘记加了
		L5->next = NULL;
		CreateListR(L3, L1, L1.length);
		CreateListR(L4, L2, L2.length);
		DispLinkList(L3);
		DispLinkList(L4);
		diffset2329_czy(L3, L4, L5);
		DispLinkList(L5);
		printf_s("\n");
	}

	//P45, 例2-3-30, 用单链表表示集合,设计一个算法求两个集合的并.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			int k = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
		}
		SqListSort(L1);
		SqListSort(L2);
		LinkList *L3, *L4, *L5;
		L5 = (LinkList *)malloc(sizeof(LinkList));//第一次写时忘记加了
		L5->next = NULL;
		CreateListR(L3, L1, L1.length);
		CreateListR(L4, L2, L2.length);
		DispLinkList(L3);
		DispLinkList(L4);
		unionset2330_czy(L3, L4, L5);
		DispLinkList(L5);
		printf_s("\n");
	}

	//P46, 例2-3-31, 已知递增有序的单链表A、B和处分别存储了一个结合,设计一个算法实现A = A ∪ ( B ∩ C ), 并使求解结果A仍保持递增.要求算法的时间复杂度为O(|A|+|B|+|C|).其中|A|为集合A的元素个数.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		SqList L3 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			int k = random(20);
			int l = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
			ListInsert(L3, i + 1, l);
		}
		SqListSort(L1);
		SqListSort(L2);
		SqListSort(L3);
		LinkList *L4, *L5, *L6, *L7, *L8;
		L7 = (LinkList *)malloc(sizeof(LinkList));//第一次写时忘记加了
		L7->next = NULL;
		L8 = (LinkList *)malloc(sizeof(LinkList));
		L8->next = NULL;
		CreateListR(L4, L1, L1.length);
		CreateListR(L5, L2, L2.length);
		CreateListR(L6, L3, L3.length);
		DispLinkList(L4);
		DispLinkList(L5);
		DispLinkList(L6);
		operator2331_czy_ref(L4, L5, L6, L7, L8);
		DispLinkList(L7);
		DispLinkList(L8);
		printf_s("\n");
	}

	//P48, 例2-3-32, 有一个有序单链表(从小到大排列),表头指针为L, 设计一个算法向该单链表中插入一个元素为x的结点, 使插入后该链表仍然有序.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
		}
		SqListSort(L1);
		LinkList *L2;
		CreateListR(L2, L1, L1.length);
		DispLinkList(L2);
		int x = random(20);
		printf_s("The inserted number is : %d\n", x);
		inorderList2332_czy(L2, x);
		DispLinkList(L2);
		printf_s("\n");
	}

	//P49, 例2-3-33, 设计一个算法,将一个头结点指针为A的单链表(其数据域为整数)分解成两个单链表A和B, 使得A链表只含有原链表A中data域为奇数的结点, 而B链表只含有原链表A中data域为偶数的结点,且保持原来的相对顺序.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
		}
		SqListSort(L1);
		LinkList *L2;
		CreateListR(L2, L1, L1.length);
		DispLinkList(L2);
		LinkList *L3;
		splitTwo2333_czy(L2, L3);
		DispLinkList(L2);
		DispLinkList(L3);
		printf_s("\n");
	}

	//P49, 例2-3-34, 设计一个算法删除并释放以h为表头指针的单链表的所有结点.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
		}
		SqListSort(L1);
		LinkList *L2;
		CreateListR(L2, L1, L1.length);
		LinkList * testNode = L2->next;
		DispLinkList(L2);
		printf_s("The first data node before being deleted is : %d\n", testNode->data);
		deleteAllNode2334_czy(L2);
		DispLinkList(L2);
		printf_s("The first data node after being deleted is : %d\n", testNode->data);
		printf_s("\n");
	}

	//P50, 例2-3-35, 已知3个单链表A、B和C中的结点均依元素值自小至大非递减排列(可能存在两个以上值相同的结点), 设计一个算法使链表A中仅留下3个灬中均包含的数据元素的结点, 且没有值相同的结点,并释放所有无用结点.
	//	限定算法的时间复杂度为O(m+n+p), 其中m、n和p分别为3个表的长度.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L1 = InitSqlist();
		SqList L2 = InitSqlist();
		SqList L3 = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			int k = random(20);
			int l = random(20);
			ListInsert(L1, i + 1, j);//random()不行？
			ListInsert(L2, i + 1, k);
			ListInsert(L3, i + 1, l);
		}
		SqListSort(L1);
		SqListSort(L2);
		SqListSort(L3);
		LinkList *L4, *L5, *L6;
		CreateListR(L4, L1, L1.length);
		CreateListR(L5, L2, L2.length);
		CreateListR(L6, L3, L3.length);
		DispLinkList(L4);
		DispLinkList(L5);
		DispLinkList(L6);
		pubSolo2335_czy(L4, L5, L6);
		DispLinkList(L4);
		printf_s("\n");
	}

	//

	*/

	/*
	//双链表的练习及功能测试
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		DispSqlist(L);
		CreateDListR(L1, L, L.length);
		DispDLinkList(L1);
		int num = random(20);
		int loc = random(21);
		printf_s("The inserted number is : %d\n", num);
		printf_s("The inserted location is :%d\n", loc);
		DLinkListInsert(L1, loc, num);
		DispDLinkList(L1);
		int locX = findNode(L1, 5);
		printf("the first find of number 5's location is : %d\n", locX);
		int deleteNum;
		DListDeleteNode(L1, 21);
		DispDLinkList(L1);
		printf_s("\n");
	}

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------
	//P56, 例2-4-10-(1), 在带头结点head的双链表中的元素值为x的结点之前插入元素值为y的结点,编写该算法(假设在双链表中不存在值域相同的两个结点).
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 20; i++) {
			int j = random(30);
			ListInsert(L, i + 1, j);//random()不行？
		}
		CreateDListR(L1, L, L.length);
		DispDLinkList(L1);
		insBefore2410_1_czy(L1, 18, 10);
		DispDLinkList(L1);
		printf_s("\n");
	}

	//P56, 例2-4-10-(2), 在带头结点head的双链表中的元素值为x的结点之后插入元素值为y的结点,编写该算法(假设在双链表中不存在值域相同的两个结点)
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 20; i++) {
			int j = random(30);
			ListInsert(L, i + 1, j);//random()不行？
		}
		CreateDListR(L1, L, L.length);
		DispDLinkList(L1);
		insAfter2410_2_czy(L1, 29, 10);
		DispDLinkList(L1);
		printf_s("\n");
	}

	//P57, 例2-4-11, 设有一个双链表h, 设计一个算法查找第一个元素值为x的结点, 将其与后继结点进行交换.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		CreateDListR(L1, L, L.length);
		DispDLinkList(L1);
		swapDListNode2411_czy(L1, 10);
		DispDLinkList(L1);
		printf_s("\n");
	}

	//P57, 例2-4-12, 设有一个双链表h, 每个结点中除有prior、data和next3个域外,还有一个访问频度域freq,在链表被起用之前,每个结点中的freq域的值均被初始化为零.
	//	每当进行LocateNode(h,x)运算时,令元素值为x的结点中freq域的值加1, 并调整表中结点的次序, 使其按访问频度的递减序列排序, 以便使频繁访问的结点总是靠近表头.试写一符合上述要求的算法.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList_2412 *L1;
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		SqListSort(L);
		CreateDListR_2412(L1, L, L.length);
		deleteDuplicateNode(L1);
		DispDLinkList_2412(L1);
		locateDListNode2412_2rd(L1, 5);
		locateDListNode2412_2rd(L1, 5);
		locateDListNode2412_2rd(L1, 5);
		locateDListNode2412_2rd(L1, 7);
		locateDListNode2412_2rd(L1, 6);
		locateDListNode2412_2rd(L1, 9);
		DispDLinkList_2412(L1);
		printf_s("\n");
	}

	//

	*/

	/*循环单链表的练习及功能测试
	//
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		LinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		DispSqlist(L);
		CreateCListR(L1, L, L.length);
		DispCLinkList(L1);
		CListInsert(L1, 12, 11);
		DispCLinkList(L1);
		CListDelete(L1, 12);
		DispCLinkList(L1);
		int locX = FindCListNode(L1, 6);
		printf_s("The location of number 6's first appear is : %d\n", locX);
		printf_s("\n");
	}


	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------
	//P64, 例2-5-13, 已知一个循环单链表的逻辑关系为:顺时针链接,head指向尾结点.设计一个算法将逻辑关系改为逆时针链接.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		LinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		CreateCListR(L1, L, L.length);
		LinkList *head = L1;
		LinkList *p = L1->next;
		while (p->next != head) {
			p = p->next;
		}
		DispCLinkList(L1);
		invertList2513_czy(p);
		DispCLinkList(L1);
		printf_s("\n");
	}

	*/

	/*循环双链表的练习及功能测试
	//
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		DispSqlist(L);
		CreateCDListR(L1, L, L.length);
		DispCDLinkList(L1);
		CDListInsert(L1, 20, 12);
		DispCDLinkList(L1);
		CDListDelete(L1, 12);
		DispCDLinkList(L1);
		int locX = FindCDListNode(L1, 5);
		printf_s("The position of number 5's first appearence is : %d\n", locX);
		printf_s("\n");
	}

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------

	//P65, 例2-5-14, 有一个循环双链表, p指向第一个元素值为x的结点, 设计一个算法从该循环双链表中删除*p结点.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		CreateCDListR(L1, L, L.length);
		DispCDLinkList(L1);
		deleteCDListNode2514_czy(L1, 5);
		DispCDLinkList(L1);
		printf_s("\n");
	}

	//P65, 例2-5-15, 设有一个含两个以上结点的循环双链表, p指向第一个元素值为x的结点, 设计一个算法将*p与其后继结点进行交换.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		CreateCDListR(L1, L, L.length);
		DispCDLinkList(L1);
		swapCDListNode2515_czy(L1, 2);
		DispCDLinkList(L1);
		printf_s("\n");
	}

	//P66, 例2-5-16,设计一个算法倒置一个含两个以上结点的循环双链表.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList L = InitSqlist();
		DLinkList *L1;
		for (int i = 0; i < 10; i++) {
			int j = random(10);
			ListInsert(L, i + 1, j);//直接random()不行？
		}
		CreateCDListR(L1, L, L.length);
		DispCDLinkList(L1);
		reverseCDList2516_czy(L1);
		DispCDLinkList(L1);
		printf_s("\n");
	}

	*/


	/*栈的练习及功能测试
	//
	//假设算术表达式只包含"+"、"-"、"*"、"/"、正整数和括号的合法数学表达式.求算术表达式值的过程是:先将算术表达式(中缀表达式)转换成后缀表达式(亦称逆波兰表达式),然后对该后缀表达式求值.
	char exp[] = "(37+46*2)/5+2-(6/7)";
	char postexp[MaxSize];
	trans(exp, postexp);//postexp可以直接传进来,数值会保存?
	float ans = computeValue(postexp);
	printf_s("The answer of ");
	int i = 0;
	char ch = exp[i++];
	while (ch != '\0') {
		printf_s("%c ", ch);
		ch = exp[i++];
	}
	printf_s("is : %f\n", ans);
	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------
	
	//P81, 例3-2-7, 假设表达式中允许包含3种括号:圆括号、方括号和大括号.设计一个算法采用顺序栈判断表达式中的括号是否正确配对.
	char exp[] = "{1÷{2÷[(3+4+5)÷6]}+7}÷8+{5*3+[(7*6)-8]/4}";//right
	//char exp[] = "{1÷{2÷[(3+4+5)÷6]}+7}÷8+{5*3+[(7*6)-8]/4}";//wrong
	//char exp[] = "()";//right
	int flag = bracketMatch3207_czy(exp);
	printf("%d\n", flag);

	//P82, 例3-2-8, 设以整数序列1, 2, 3, 4作为顺序栈st的输入, 利用push(进栈)和pop(出栈)操作, 写出所有可能的输出并编程实现算法.
	SqStack seq;
	seq.top = -1;
	const int totalSeq = 4;
	int path[totalSeq + 1];
	isPopSq3208_ans(1, path, 0, totalSeq, seq);

	//P84, 例3-2-10, 设计一个算法, 利用栈的InitStack()、 Push()、 Pop()和StackEmpty()等基本运算返回指定栈中栈底元素.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		SqList list1 = InitSqlist();
		SqStack st;
		InitStack(st);
		for (int i = 0; i < 20; i++) {
			int j = random(100);
			ListInsert(list1, i + 1, j);//random()不行？
		}
		DispSqlist(list1);
		for (int i = 0; i < 20; i++) {
			PushStack(st, list1.data[i]);
		}
		int bottom = stackBottom3210_czy(st);
		printf_s("The bottom number of stack is : %d\n", bottom);
		printf_s("\n");
	}

	//P89, 例3-3-8, (略有修改)假设以1和0分别表示入栈和出栈操作, 栈的初态和终态均为空, 入栈和出栈的操作序列可表示为仅由1和0组成的序列.写出一个算法判定所给的操作序列是否合法.若合法返回1;否则返回0(假设被判定的操作序列已存入一维数组中).
	srand((int)time(0));
	int times = 20;
	while (times--) {
		int A[6];
		SqStack st;
		InitStack(st);
		for (int i = 0; i < 6; i++) {
			int j = random(2);
			A[i] = j;
		}
		printf_s("The random sequence is :");
		for (int i = 0; i < 6; i++) {
			printf_s("%3d ", A[i]);
		}
		printf_s("\n");
		int judgeAns = judge338_czy(A, 6);
		printf_s("%d\n", judgeAns);
		printf_s("\n");
	}

	//P89, 例3-3-9, 在栈顶头结点为lst的链栈中, 设计一个算法计算该链栈中结点个数.
	srand((int)time(0));
	int times = 20;
	while (times--) {
		LStackNode *testNode;
		SqList L = InitSqlist();
		InitLStack(testNode);
		int countRandom = random(20);
		for (int i = 0; i < countRandom; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);
			pushLStack(testNode, j);
		}
		DispSqlist(L);
		int count = nodeCount339_czy(testNode);
		printf_s("The count of known stack is : %d\n", count);
		printf_s("\n");
	}

	//P130, 例4-3-12, 由用户输入n个10以内的数,每输入i(0≤i≤9),就把它插入到第i号队列中.最后把10个队中非空队列,按队列号从小到大的顺序串接成一条链,并输出该链的所有元素.
	LQNode *QH[10], *QT[10];
	for (int i = 0; i < 10; i++) {
		QH[i] = QT[i] = NULL;
	}
	Create4312_czy(QH, QT);
	Link4312_czy(QH, QT);

	//P131, 例3-4-13, 采用链队设计一个算法,反映病人到医院看病、排队看医生的情况.在病人排队过程中,主要重复两件事:
	//		1)病人到达诊室,将病历交给护士,排到等待队列中候诊.
	//		2)护士从等待队列中取出下一位病人的病历,该病人进入诊室就诊.
	//	要求模拟病人等待就诊这一过程.程序采用菜单方式,下面将对其选项及功能进行说明.
	//		1:排队 输入排队病人的病历号,加入到病人排队队列中.
	//		2:就诊 病人排队队列中最前面的病人就诊,并将其从队列中删除.
	//		3:查看排队 从队首到队尾列出所有的排队病人的病历号.
	//		4:不再排队,余下依次就诊 从队首到队尾列出所有的排队病人的病历号,并退出运行.
	//		5:下班 退出运行
	SeeDoctor4313_czy();

	//

	*/

	/*顺序串的练习及功能测试
	//
	SqString SStr = InitStr();
	SqString TStr = InitStr();
	    //char s[6] = "52665";//char数组写法测试.
	char s[6] = { '5', '2','6','6','5' };
	char t[4] = "665";
	    //int a[] = { 1, 2, 3, 4 };//另一种写法测试.
	StrAssign(SStr, s);
	StrAssign(TStr, t);
	int loc = BFMatching1(SStr,TStr);
	printf_s("The first character of matching string is : %d", loc);

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------

	//P140, 例5-2-5, 设计一个算法, 计算一个串s中每一个字符出现的次数.
	char s[] = "appletree";//若字符串中有换行符\n则输出显示从用户体验角度不好,出现疑惑
	SqString sqstr = InitStr();
	StrAssign(sqstr, s);
	DispStr(sqstr);
	count525_czy(sqstr);

	//P140, 例5-2-6, 设计一个算法RepStr(),在串s中将第i(1≤i≤n)个字符开始的j个字符构成的子串用串t替换,并返回产生的新串.
	char s[] = "Beautifulgirlisme";//若字符串中有换行符\n则输出显示从用户体验角度不好,出现疑惑
	char s1[] = "boy";
	SqString sqStr = InitStr();
	StrAssign(sqStr, s);
	SqString subsqStr = InitStr();
	StrAssign(subsqStr, s1);
	SqString newStr = RepStr526_czy(sqStr, 10, 4, subsqStr);
	DispStr(newStr);

	//P141, 例5-2-7, 设计StrCmp(s, t)算法,实现两个串s和t的比较.
	char s[] = "I have 3 apples.";//若字符串中有换行符\n则输出显示从用户体验角度不好,出现疑惑
	char s1[] = "20";
	SqString sqStr = InitStr();
	StrAssign(sqStr, s);
	SqString subsqStr = InitStr();
	StrAssign(subsqStr, s1);
	SqString newStr = RepStr526_czy(sqStr, 8, 1, subsqStr);
	DispStr(newStr);

	//P142, 例5-2-8, 设计一个递归算法,利用串的基本运算SubStr()判断字符x是否在串s中.
	char s[] = "WhAt Are you doing";//若字符串中有换行符\n则输出显示从用户体验角度不好,出现疑惑
	char s1 = 'a';
	SqString sqStr = InitStr();
	StrAssign(sqStr, s);
	int flag = Find528_ans(sqStr, s1);
	printf_s("%d", flag);

	//P142, 例5-2-9, 设计一个递归算法,利用串的基本运算StrLength()、SubStr()、Concat()将非空串s的所有字符逆置.
	char s[] = "apple";
	SqString sqStr = InitStr();
	StrAssign(sqStr, s);
	DispStr(sqStr);
	reverse529_ans(sqStr);
	DispStr(sqStr);
	
	*/

	/*链串的练习及功能测试
	//
	char s1[] = "advertisement";
	char s2[] = "pp";
	LiString *LiStr1, *LiStr2;
	LiStrAssign(LiStr1, s1);
	LiStrAssign(LiStr2, s2);
	DispLiStr(LiStr1);
	DispLiStr(LiStr2);
	//LiString *Str = LiStrConcat(LiStr1, LiStr2);//穷举试出来的正确写法,不懂原理.2019年8月22日 21:25:30
	//DispLiStr(Str);
	//LiString *SubStr = SubLiStr(Str, 2, 3);
	//DispLiStr(SubStr);
	//LiString *SubStr1 = SubLiStr(Str, 2, 10);
	//DispLiStr(SubStr1);
	//LiString *InsStr = InsLiStr(LiStr1, 2, LiStr2);
	//DispLiStr(InsStr);
	LiString *DelStr = DelLiStr(LiStr1, 2, 10);
	DispLiStr(DelStr);

	//
	SqString SStr = InitStr();
	SqString TStr = InitStr();
		//char s[6] = "52665";//char数组写法测试.
	char s[6] = { '5', '2','6','6','5' };
	char t[4] = "665";
		//int a[] = { 1, 2, 3, 4 };//另一种写法测试.
	StrAssign(SStr, s);
	StrAssign(TStr, t);
	int loc = BFMatching1(SStr,TStr);
	printf_s("The first character of matching string is : %d", loc);

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------

	//P147, 例5-3-3, 设计一个算法,在链串s中,将第i(1≤i≤n)个字符开始的j个字符构成的子串用串t替换,并返回产生的新串.
	char s1[] = "advertisement";
	char s2[] = "MENT";
	LiString *LiStr1, *LiStr2;
	LiStrAssign(LiStr1, s1);
	LiStrAssign(LiStr2, s2);
	DispLiStr(LiStr1);
	DispLiStr(LiStr2);
	LiString *NewStr = RepLiStr533_czy(LiStr1, 10, 4, LiStr2);
	DispLiStr(NewStr);

	//P148, 例5-3-5, 设计一个算法判断链串s中所有元素是否为递增排列的.
	char s1[] = "acddr";
	char s2[] = "";
	char s3[] = "aoodb";
	LiString *LiStr1;
	LiStrAssign(LiStr1, s1);
	DispLiStr(LiStr1);
	LiString *LiStr2;
	LiStrAssign(LiStr2, s2);
	DispLiStr(LiStr2);
	LiString *LiStr3;
	LiStrAssign(LiStr3, s3);
	DispLiStr(LiStr3);
	int flag1 = isIncreaseLiStr535_czy(LiStr1);
	int flag2 = isIncreaseLiStr535_czy(LiStr2);
	int flag3 = isIncreaseLiStr535_czy(LiStr3);
	printf_s("%d\n%d\n%d\n", flag1, flag2, flag3);

	*/

	/*数组和系数矩阵
	//
	char s1[] = "advertisement";

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------

	//P147, 例5-3-3, 设计一个算法,在链串s中,将第i(1≤i≤n)个字符开始的j个字符构成的子串用串t替换,并返回产生的新串.
	
	//

	*/

	/*
	//二叉树的练习及功能测试
	//
	SBTree a = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		printf_s("%d\n", a[i]);
	}
	
	//

	--------------------------------------------------------------------------
	-------------------------------习题部分------------------------------------
	--------------------------------------------------------------------------

	//

	*/

	/*
	//排序算法
	//
	srand((int)time(0));
	int times = 20;
	while (times--) {
		InSort_SqList *ssq = InitRandomSqList();
		printf_s("The random sequnence is:\n");
		DispInitKey(ssq);
		//Bubble_Sort(ssq, Sort_MAXITEM);
		//Quick_Sort(ssq, 0, 19);
		//Insert_Sort(ssq, 20);
		//Shell_Sort(ssq, 20);
		//Select_Sort(ssq, 20);
		//Heap_Sort(ssq, 20);
		MergeSort(ssq, 20);
		printf_s("The increase sequence is :\n");
		DispInitKey(ssq);
		printf_s("\n");
	}

	*/

	/*
	//Shandong Normal University previous exam papers, Data structure A, Algorithm design
		//山东师范大学-2011年-数据结构A-算法设计题1, 设计在单链表中删除值相同的多余结点的算法.
		srand((int)time(0));
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		deleteDuplicatedNode_SDNU_2011_1_czy(L1);
		DispLinkList(L1);

		//

		//

		//

	*/
/*
	srand((int)time(0));
		SqList L = InitSqlist();
		for (int i = 0; i < 20; i++) {
			int j = random(20);
			ListInsert(L, i + 1, j);//random()不行？
		}
		LinkList *L1;
		CreateListR(L1, L, L.length);
		DispLinkList(L1);
		deleteDuplicatedNode_SDNU_2011_1_czy(L1);
		DispLinkList(L1);
	return 0;
	*/
}

//P25, 例2-2-10, 已知一个顺序表L,其中的元素递增有序排列,设计一个算法插入一个元素x后保持该顺序表仍递增有序排列.//MaxSize = 100000直接溢出？
//算法思路:找到x要插入的位置后,将该位置元素及后续直到最后一个元素,从最后一个开始,到待插入位置的元素,依次向后移动一个位置,最后将待插入元素插入待插入位置.
void insert2210_czy(SqList &L, int x) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] < x) continue;
		else break;
	}
	ListInsert(L, i + 1, x);
}

//P26, 例2-2-11, 设计一个算法，将顺序表的所有元素逆置,要求算法空间复杂度为O(1).
//将顺序表的第i(i=1,2,3,...,L.length/2)与顺序表的第j(j=L.length - i + 1)互换.
void reverse2211_czy(SqList &L) {
	int temp;
	for (int i = 0; i < (L.length / 2); i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}

//P26, 例2-2-12, 设计一个算法,从顺序表中删除所有元素值为x的元素,要求空间复杂度为O(1).自己写的
//空间复杂度O(1)表示表示该程序所占用的空间和所用数据量无关.
//算法思路:通过i循环遍历整个顺序表的每一个元素,令j与i的数值一致,即若当前访问到的元素数值为x,则
void delete2212_czy(SqList & L, int x) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == x) {
			for (int j = i; j < L.length; j++) {
				L.data[j] = L.data[j + 1];
			}
			L.length--;
		}
	}
}

//P26, 例2-2-12, 设计一个算法,从顺序表中删除所有元素值为x的元素,要求空间复杂度为O(1).答案算法1
void delete2212_2rd(SqList & L, int x) {
	int i = 0, j;
	while (i < L.length && L.data[i] != x) i++;
	for (j = i + 1; j < L.length; j++) {
		if (L.data[j] != x) {
			L.data[i] = L.data[j];
			i++;
		}
	}
	L.length = i;
}

//P26, 例2-2-12, 设计一个算法,从顺序表中删除所有元素值为x的元素,要求空间复杂度为O(1).答案算法2
void delete2212_3rd(SqList & L, int x) {
	int i = 0, k = 0;
	while (i < L.length) {
		if (L.data[i] == x) k++;
		else L.data[i - k] = L.data[i];
		i++;
	}
	L.length -= k;
}

//P27, 例2-2-13, 设计一个算法,从一给定的顺序表L中删除元素值在x到y (x <= y) 之间的所有元素,要求以较高的效率来实现,空间复杂度为O(1).
//算法思路:首先i遍历顺序表L,直到i所在的结点数据域满足删除条件,
void deletexy2213_czy(SqList & L, int x, int y) {
	int i = 0, j;
	while (i < L.length && (L.data[i] < x || L.data[i] > y)) i++;
	for (j = i + 1; j < L.length; j++) {
		if (L.data[j] < x || L.data[j] > y) {
			L.data[i] = L.data[j];
			i++;
		}
	}
	L.length = i;
}

//P27, 例2-2-13, 设计一个算法,从一给定的顺序表L中删除元素值在x到y (x <= y) 之间的所有元素,要求以较高的效率来实现,空间复杂度为O(1).
void deletexy2213_czy_2rd(SqList & L, int x, int y) {
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] < x || L.data[i] > y) L.data[i - k] = L.data[i];
		else k++;
	}
	L.length -= k;
}

//P27, 例2-2-14, 设有一个顺序表,其元素为整型数据,设计一个算法将L中所有的小于0的整数放在前半部分,大于等于0的整数放在后半部分.
void move2214_czy(SqList & L) {
	//参考了答案的思路
	int temp, i = 0, j = L.length - 1;
	while (i < j) {
		if (L.data[i] >= 0 && L.data[j] < 0) {
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
			i++;
			j--;
		}
		else if (L.data[i] < 0) i++;
		else j--;
	}
}

//P27, 例2-2-14, 设有一个顺序表,其元素为整型数据,设计一个算法将L中所有的小于0的整数放在前半部分,大于等于0的整数放在后半部分.
void move2214_2rd(SqList & L) {
	int temp;
	int i = 0, j = L.length - 1;
	while (i < j) {
		while (i < j && L.data[i] < 0) i++;
		while (i < j && L.data[j] >= 0) j--;
		if (i < j) {
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
}

//P28, 例2-2-15, 设计一个算法从顺序表中删除重复的元素,并使剩余元素间的相对次序保持不变.
void deleteSame2215_czy(SqList & L) {
	int i = 0, k = 0, j, temp;
	while (i < L.length) {
		temp = L.data[i];
		k = 0;//第一次写时考虑不周把k = 0写在下面的for循环里了;
		for (j = i + 1; j < L.length; j++) {
			if (L.data[j] != temp) L.data[j - k] = L.data[j];
			else k++;
		}
		L.length -= k;
		i++;
	}
}

//P28, 例2-2-15, 设计一个算法从顺序表中删除重复的元素,并使剩余元素间的相对次序保持不变.
void deleteSame2215_2rd(SqList & L) {
	int i, j, k;
	if (L.length > 0) {
		j = 0;
		for (i = j + 1; i < L.length; i++) {//int i改为了i 因为前面定义了int i 2019年7月29日 23:00:47
			k = 0;
			while (k <= j && L.data[k] != L.data[i]) k++;
			if (k > j) {
				j++;
				L.data[j] = L.data[i];
			}
		}
		L.length = j + 1;
	}
}

//P28, 例2-2-16, 用顺序表表示集合,设计一个算法实现集合的求交集运算.
SqList intersaction2216_czy(SqList L1, SqList L2) {
	SqList L3 = InitSqlist();
	int k = 0, temp;
	for (int i = 0; i < L1.length; i++) {
		temp = L1.data[i];
		for (int j = 0; j < L2.length; j++) {
			if (temp == L2.data[j]) {
				L3.data[k++] = temp;
				break;
			}
		}
	}
	L3.length = k;
	return L3;
}

//P28, 例2-2-16, 用顺序表表示集合,设计一个算法实现集合的求并集运算.
SqList unionAlg2217_czy(SqList L1, SqList L2) {
	SqList L3 = L2;
	int i, j, temp, k = 0;
	for (i = 0; i < L1.length; i++) {
		temp = L1.data[i];
		for (j = 0; j < L2.length; j++) {
			if (L2.data[j] == temp) break;
		}
		if (j == L2.length) {
			L3.data[L3.length] = temp;
			L3.length++;
		}
	}
	return L3;
}

//P28, 例2-2-16, 用顺序表表示集合,设计一个算法实现集合的求差集运算.
SqList diffSet2218_czy(SqList L1, SqList L2) {
	SqList L3 = InitSqlist();
	int i, j, temp, k = 0;
	for (i = 0; i < L1.length; i++) {
		temp = L1.data[i];
		for (j = 0; j < L2.length; j++) {
			if (L2.data[j] == temp) break;
		}
		if (j == L2.length) {//第一次写时 == 写成了 =;
			L3.data[k++] = temp;
		}
	}
	L3.length = k;
	return L3;
}

//P29, 例2-2-19-1, 用顺序表A和B表示的两个线性表,元素的个数分别为m和n,若表中数据都是由小到大顺序排列的,且这(m+n)个数据没有重复的.
// 1) 设计一个算法将此两个线性表合并为一个,仍是数据由小到大排列的线性表,存储到另一个顺序表C中.
SqList Merge2219_1_czy(SqList L1, SqList L2) {
	SqList L3 = InitSqlist();
	int i = 0, j = 0;
	while (i != L1.length && j != L2.length) {
		if (L1.data[i] == L2.data[j]) {
			 L3.data[L3.length++] = L1.data[i];
			 L3.data[L3.length++] = L1.data[i];//重复元素要输出两遍
			i++;
			j++;
		}
		else if (L1.data[i] < L2.data[j]) {
			L3.data[L3.length++] = L1.data[i];
			i++;
		} else {
			L3.data[L3.length++] = L2.data[j];
			j++;
		}
	}
	//if (j == L2.length) {
		while (i < L1.length) {
			L3.data[L3.length++] = L1.data[i];
			i++;
		}
	//}
	//if (i == L1.length) {
		while (j < L2.length) {
			L3.data[L3.length++] = L2.data[j];
			j++;
		}
	//}
	return L3;
}

//P29, 例2-2-19-1, 用顺序表A和B表示的两个线性表,元素的个数分别为m和n,若表中数据都是由小到大顺序排列的,且这(m+n)个数据没有重复的.
// 2) 顺序表B的大小为(m+n)个单元,将合并成的线性表存放于顺序表B中,设计此算法.
void Merge2219_2_czy(SqList L1, SqList & L2) {
	int i = 0, j = 0, k = 0;
	while (i != L1.length && j != L2.length) {
		if (L1.data[i] == L2.data[j]) {
			for (int m = L2.length - 1; m >= j; m--) {
				L2.data[m + 1] = L2.data[m];
			}
			L2.data[j] = L2.data[j + 1];
			L2.length++;
			j++;
			i++;
		}
		else if (L1.data[i] < L2.data[j]) {
			for (int m = L2.length - 1; m >= j; m--) {
				L2.data[m + 1] = L2.data[m];
			}
			L2.data[j] = L1.data[i];
			L2.length++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	while (i < L1.length) {
		L2.data[j++] = L1.data[i];
		i++;
		L2.length++;
	}
	while (j < L2.length) {
		j++;
	}
}

//P29, 例2-2-19-1, 用顺序表A和B表示的两个线性表,元素的个数分别为m和n,若表中数据都是由小到大顺序排列的,且这(m+n)个数据没有重复的.
// 3) 设顺序表A有m+n个元素,且前m个有序,后n个有序,设计一个算法,使得整个顺序表有序.
//算法思路:开辟一个新的顺序表L2,k不断自增记录L2的1)长度和2)所要插入的位置
//	i和j分别遍历第1~m个、第m+1~m+n个元素,相当于分成了front段和rear段,即i和j分别指向front段的第一个元素和rear段的第一个元素,将front段和rear段从第一个元素开始依次根据i和j所指向素位置的元素进行比较,
//	1)若相等,则将front段的第一个数据结点的数据域复制给新的顺序表两次,并使得k自增1两次,i和j分别增加1
//	2)若front段的第一个元素小于rear段的第一个元素,则将front段的第一个元素赋值给L2,i自增1
//	3)若rear段的第一个元素大于rear段的第一个元素,则将rear段的第一个元素赋值给L2,j自增1
//	4)将i和j所指的元素依次进行上述1)~3)的比较,并按照要求依次比较、自增,直到front或rear之一遍历完毕了,则将未遍历完毕的front/rear剩余元素赋值给L2
//	最后根据k的数值将L2表示顺序表长度的数据域赋值,结束.
SqList Merge2219_3_czy(SqList L1) {
	SqList L2 = InitSqlist();
	int i = 0, j = 5, k = 0;
	while (i != 5 && j != L1.length) {
		if (L1.data[i] == L1.data[j]) {
			L2.data[k++] = L1.data[i];
			L2.data[k++] = L1.data[i];
			//L2.length += 2;
			i++;
			j++;
		}
		else if (L1.data[i] < L1.data[j]) {
			L2.data[k++] = L1.data[i];
			i++;
			//L2.length++;
		}
		else {
			L2.data[k++] = L1.data[j];
			j++;
			//L2.length++;
		}
	}
	while (i < 5) {
		L2.data[k++] = L1.data[i];
		i++;
		//L2.length++;
	}
	while (j < L1.length) {
		L2.data[k++] = L1.data[j];
		j++;
		//L2.length++;
	}
	L2.length = k;
	return L2;
}

void deleteMinNode(LinkList *& L) {
	//SDNU 2018 数据结构A 算法设计题 删除单链表L的最小值结点.
	//算法思路: r指针(通过r的后继结点)来遍历整个单链表L, p用来指向最小值结点的前驱结点,q用以删除结点时释放被删除结点的内存
	//	因单链表必定有一最小值,因此最开始假定第一个数据结点为最小值结点,此时p指向第一个数据结点的前驱结点,即头结点
	//	通过r遍历链表L, 遍历r的后继结点的数据域与min进行比较,若被遍历的结点的后继结点的数据域数值小于min,则p更新为新的待定最小值数据结点的前驱结点,同时更新min的数值
	//	r遍历完毕单链表L, 即r的后继结点为NULL, 则此时全部遍历完毕.通过p来删除并释放最小值结点,算法结束.
	LinkList *p = L, *q, *r = L;
	int min = r->next->data;
	while (r->next != NULL) {
		if (r->next->data < min) {
			min = r->next->data;//第一次写时忘记加了
			p = r;
		}
		r = r->next;
	}
	printf_s("The min number is : %d\n", p->next->data);
	q = p->next;
	p->next = q->next;
	free(q);
}

int deleteX2317_czy(LinkList * L, int x) {
	//P38, 例2-3-17, 设计一个算法删除单链表L中值为x的结点的直接前驱结点.
	//算法思路:三个指针分别指向前驱结点,当前结点,后继结点,当后继结点的数据域为目标数值x时,通过当前结点的前驱结点的指针域指向当前结点的后继结点,然后释放掉当前结点;
	LinkList *p = L->next, *q = p->next, *s = L;
	if (p->data == x) return 0;
	while (q != NULL) {
		if (q->data == x) {
			s->next = p->next;
			free(p);
			return 1;
		}
		s = s->next;
		p = p->next;
		q = q->next;
	}
	return 0;
}

void splitLinkList2318_czy(LinkList * hc, LinkList *& ha, LinkList *& hb) {
	//P39, 例2 - 3 - 18, 设C = { a1, b1, a2, b2, ... , an, bn }为一线性表, 采用带头结点的hc单链表存放, 设计一个就地算法, 将其拆分层两个线性表, 使得 A = { a1, a2, ... , an }, B = { b1, b2, ..., bn }.
	//算法思路:定义两个新的链表ha和hb用以存放拆分后的线性表,两个指针分别指向ha和hb的链表元素
	//	while循环体(判断条件为当前p所指向结点是否为NULL)用指针p遍历hc单链表,第一次将第一个结点给ha,然后循环体内if判断下一个结点是否为NULL,不为NULL则将下一个结点赋值给hb,重复循环体直到结束.
	//	最后将ha和hb的链尾结点的指针域赋值为NULL
	LinkList *p = hc->next, *har, *hbr, *s;
	ha = (LinkList *)malloc(sizeof(LinkList));
	ha->next = NULL;
	har = ha;
	hb = (LinkList *)malloc(sizeof(LinkList));
	hb->next = NULL;
	hbr = hb;
	while (p != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = p->data;
		s->next = har->next;
		har->next = s;
		har = s;
		p = p->next;
		if (p != NULL) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = hbr->next;
			hbr->next = s;
			hbr = s;
			p = p->next;
		}
	}
	har->next = NULL;
	hbr->next = NULL;
}

void deleteDuplicatedNode_SDNU_2011_1_czy(LinkList * L) {
	//山东师范大学-2011年-数据结构A-算法设计题1, 设计在单链表中删除值相同的多余结点的算法.
	//算法思路:若该单链表为空链表(即头结点的指针域为NULL,则直接return,无需删除),否则(即该单链表不为空)执行下面的算法
	//	令p指针首先指向该单链表的第一个数据结点,第二个结点,第三个结点(注意这里的第1、2、3…个结点并不是静态、不变的,随着每次向后遍历删除重复结点而可能不断改变)…
	//  p每指向一个新结点,就从该结点开始向后遍历至表尾,将关键字值与当前p所指向的结点的关键字值相等的结点删除;直至p无后继节点(即p.next == NULL)
	//p指向一个新结点后,令fro指向p所指向的结点,rea指向pro所指向结点的后继结点,用fro和rea指针相继遍历当前p后的所有结点直至链尾(即rea指向NULL时)
	//  fro和rea相继遍历p之后的所有结点思路(下面的逻辑使得fro和rea所指向的结点在完成相关操作后一直为相邻接点或fro指向尾结点而rea指向NULL):
	//	若rea所指向的结点的关键字值与当前p所指向结点的关键字值相等,则需要将该rea所指向的结点删除,即令fro指向rea的后继结点,释放rea所指向的结点,
	//		再根据此时fro的后继结点对rea赋值(若该后继结点为NULL,则令rea = NULL;否则令rea指向fro的后继结点.这里注意直接令rea = fro.next即可同时完成上面两种分支)
	//	若rea所指向的结点的关键字值与当前p所指向的关键字值不相等,则令fro和rea所指向的结点均向后移动一个结点,再次根据rea指向NULL与否判断是否进入下一次while循环
	if (L->next == NULL) return;
	LinkList *p = L->next;
	while (p->next != NULL) {
		LinkList *fro = p, *rea = p->next;
		while (rea != NULL) {
			if (rea->data == p->data) {
				fro->next = rea->next;
				free(rea);
				//下面两行代码可以简化
				//if (fro->next != NULL) rea = fro->next;//第一次写时忽略掉了fro->next == NULL的情况
				//else rea = NULL;
				rea = fro->next;
				
			}
			else {
				fro = rea;
				rea = rea->next;
			}
		}
		p = p->next;
	}
	return;
}

int deleteNode2320_czy(LinkList * L, int min, int max) {
	//P40, 例2-3-20, 已知单链表L(带头结点)是一个递增有序表,设计一个高效算法,删除表中data值在大于或等于min且小于或等于max之间的结点(若表中有这样的结点),同时释放被删结点的空间,这里min和max是两个给定的参数.并分析算法的时间复杂度.
	//算法思路:两个指针q和p分别指向头结点和第一个数据结点,s用来存放当前需要删除的元素结点
	//	首先依照p所指向结点的数据域大小和min的数值关系,q和p依次向后一个接一个的遍历,直到p所指向的结点为满足删除条件的结点
	//	依照q和p删掉第一个满足删除条件的元素后,p指向q的后继结点,即p原本所指向结点的下一个结点,然后whle循环判断一个接一个的下一个p所指向元素的数据和max的关系,满足条件则删除结点
	//	最后,1)p遍历到某个结点不满足删除条件,则退出循环,完成算法.2)直到最后一个元素都满足删除条件,删掉最后一个结点后(此时q->next == NULL),手动将p指向NULL(直接p = q->next会报错,具体原因暂未找出).
	LinkList *p = L->next, *q = L, *s;
	while (p != NULL && p->data < min) {//这里有问题，如果最小的元素都大于max的话,就不行了
		//以及传参时需要 *&L,否则当第一个结点就满足条件时？？？？不加&也可以？？？
		p = p->next;
		q = q->next;
	}
	if (p == NULL) return 0;
	s = p;
	q->next = p->next;
	free(s);
	p = q->next;
	while (p->data <= max && p != NULL) {
		s = p;
		q->next = p->next;
		free(s);
		//p = q->next;//改写为下面的if-else判断形式就可以了,否则当max大于或等于最后一个结点的测试链表会报错.
		if (q->next == NULL) {
			p = NULL;//== 改为了 = 2019年7月29日 23:01:21
			break;
		}
		else {
			p = q->next;
		}
	}
	return 1;
}

void deleteNode2320_2rd(LinkList *&L, int min, int max) {
	LinkList *p = L->next, *r = L, *q;//p指向第一个元素结点,r指向p的前驱结点
	while (p->data < min && p != NULL) {
		r = p;
		p = p->next;
	}
	q = p;
	while (q != NULL && q->data <= max) {//q指向刚大于max的结点
		q = q->next;
	}
	r->next = q;
	r = p->next;
	while (r != q) {
		free(p);
		p = r;
		r = r->next;
	}
	printf_s("p.data = %d\n", p->data);
	free(p);
}

void deleteNode2321_czy(LinkList *& L, int min, int max) {
	//P41, 例2-3-21, 已知单链表L(带头结点)是一个非有序表,设计一个算法,删除表中data值在大于或等于min且小于或等于max之间的结点(若表中有这样的结点),同时释放被删除结点的空间,
	//	这里min和max是两个给定的参数.并分析算法的时间复杂度.
	//算法思路:q一开始指向第一个数据结点,依次向后一个接一个的行进,p指向q结点的前驱结点,在释放满足删除条件的q结点时需要使用,
	//	当q所指向的结点数据域满足删除条件时,将q结点的前驱结点,即当前的p的指针域修改为q结点的后继结点,进而释放q当前所指的结点,然后将q指向p结点的后继结点,即之前释放的q结点的后继结点,然后继续通过q来遍历
	//	当q所指向的结点数据域不满足删除条件时,将p结点指向q结点,即p结点的后继结点,q指向当前q的后继结点,整个过程即q向后遍历了一个新的结点(向前行进了一步),进而转向循环判断继续遍历,直至q遍历完整个单链表.
	LinkList *p = L, *q = L->next;
	//LinkList *r;
	while (q != NULL) {
		if (q->data >= min && q->data <= max) {
			//r = p;
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = q;
			q = q->next;
		}
	}
}

void deleteNode2322_czy(LinkList *& L) {
	//P41, 例2-3-22, 有一个递增单链表(允许出现值域重复的结点),设计一个算法删除值域重复的结点.并分析算法的时间复杂度.
	//算法思路: p指针从第一个元素结点开始向后一个接一个遍历,q指针指向p指针所指结点的后继结点.
	//	若p所指向的结点的数据域与q所指向的数据域数值一致,则满足删除条件,需要删除当前q所指向的元素,则将p的指针域指向q(即需要删除的结点)的后继结点,然后将q重新指向p的新后继结点
	//	循环体,q不为NULL,即q未到最后的链尾,一直重复上述判断,直至结束.
	LinkList *p = L->next, *q = L->next->next;
	while (q != NULL) {
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
}

void deleteNode2323_czy(LinkList *&L) {
	////P41, 例2-3-23, 有一个非有序单链表(允许出现值域重复的结点),设计一个算法删除值域重复的结点.并分析算法的时间复杂度.
	//算法思路: flag指针从第一个数据结点依次向后遍历,每到一个新的结点,就将该节点之后的所有结点的数据域与之数据域比较,
	//	若满足条件,则将满足条件的结点的前驱结点指向满足条件结点的后继结点,然后删除满足条件的结点,直至该结点的之后所有结点全部完成此判定操作,则进入下一个结点的依次判定.直至flag遍历完整个链表.
	LinkList *flag = L->next, *p, *q;
	while (flag!= NULL) {
		q = flag->next;
		p = flag;
		while (q != NULL) {
			if (q->data == flag->data) {
				p->next = q->next;
				free(q);
				q = p->next;
			}
			else {
				p = p->next;
				q = q->next;
			}
		}
		flag = flag->next;
	}
}

int isIncrease2324_czy(LinkList * L) {
	//P42, 例2-3-24, 设计一个算法判定单链表L(带头结点)是否是递增的.
	//算法思路: 将q指针指向第一个数据结点,q指针指向第二个数据结点,两指针同时向后一个接一个的遍历,每次同时向后移动一个,则判断当前p和q所指结点的数据域是否满足前小后大的条件
	//	若满足条件,则p和q所指向的数据结点向后移动一个位置,直至q遍历完毕指向NULL,则此时整个链表是递增的,函数返回1表示有序
	//	若中间某p和q所指向的相邻接点不满足前小后大的条件,则直接进入else 返回0表示不严格满足题设条件.
	LinkList * p = L->next, *q = L->next->next;
	while (q != NULL) {
		if (p->data < q->data) {
			p = p->next;
			q = q->next;
		}
		else {
			return 0;
		}
	}
	return 1;
}

void deleteMinNode2326_czy(LinkList *L) {
	LinkList *p = L, *q = L->next, *r, *t;
	int min = q->data;
	r = p;//一开始写时没有加,极端情况,当删除元素为第一个元素时,r和t将没有初始化的机会;
	t = q;
	while (q != NULL) {
		if (q->data < min) {
			min = q->data;
			r = p;
			t = q;
		}
		p = p->next;
		q = q->next;
	}
	r->next = r->next->next;
	free(t);
}

void reverseLinkList2327_czy(LinkList *& L) {
	//P43, 例2-3-27, 有一个线性表(a1,a2,...,an),采用带头结点的单链表L存储,设计一个算法将其就地逆置.所谓"就地"指辅助空间应为O(1).
	//算法思路: 将p指针指向该链表的第一个数据元素,然后将L置空
	//	将p指针所指向的结点及后继结点依次给新创建的结点s(结点s需要每一个新结点都malloc依次)采用头插法插入链表L中.
	LinkList *p = L->next, *s;
	//s = (LinkList *)malloc(sizeof(LinkList));//将该句写在while里即可实现.
	L->next = NULL;
	while (p != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = p->data;
		s->next = L->next;
		L->next = s;
		p = p->next;
	}
}

void interset2328_czy(LinkList *A, LinkList *B, LinkList *&C) {
	//P44, 例2-3-28, 用单链表表示集合,设计一个算法求两个集合的交.
	//算法思路: 将链表B的第i(1<=i<=B.length)个元素与链表A的所有元素结点依次比较,若存在数据域等值的情况,则将链表B的第i个元素插入链表C作为新结点
	//头插法
	LinkList *p = A->next, *q = B->next, *r;
	while (p != NULL) {
		q = B->next;//第一次写时忘记加了.
		while (q != NULL) {
			if (q->data == p->data) {
				r = (LinkList *)malloc(sizeof(LinkList));
				r->data = q->data;
				r->next = C->next;
				C->next = r;
				q = q->next;
				break;
			}
			else {
				q = q->next;
			}
		}
		p = p->next;
	}
}

void diffset2329_czy(LinkList * A, LinkList * B, LinkList *& C)	{
	//P45, 例2-3-29, 用单链表表示集合,设计一个算法求两个集合的差.
	//算法思路: C = A - B, 将A集合中的每一个结点依次在B中(每次都从B的首个结点开始)遍历,
	//	若该结点在与B结点依次遍历过程中出现数据域相等,则退出当前次遍历,p指向A的下一个元素重复上述操作
	//	若当前p结点与B集合中所有元素遍历完毕未出现数据域相等的情况(即q当前指向NULL),则满足条件,将数据域为p结点所指结点的数据域的结点用尾插法插入C链表
	LinkList *p = A->next, *q = B->next, *s, *r;
	r = C;
	while (p != NULL) {
		q = B->next;//第一次写时忘记加,第二次写时加在了 while (q != NULL) 里面;
		while (q != NULL) {
			if (q->data == p->data) {
				break;
			}
			else {
				q = q->next;
			}
		}
		if (q == NULL) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = r->next;
			r->next = s;//第一次写时忘记加(尾插法的算法操作:待插入的新结点的指针域指向尾结点的指针域所指向的内容,即NULL,尾结点的指针域指向新结点,尾结点指向新结点完成插入).
			r = s;
		}
		p = p->next;
	}
}

void unionset2330_czy(LinkList * A, LinkList * B, LinkList *& C) {
	//P45, 例2-3-30, 用单链表表示集合,设计一个算法求两个集合的并.
	//算法思路: 首先遍历B链表的所有结点依次添加至链表C,进而用p遍历A链表,将A链表的所有结点(从第一个数据结点开始)的数据域依次与B链表的所有结点的数据域(用q遍历)比对
	//	若数据域出现相等情况,则当前p所指向的A链表的结点不满足添加条件,退出循环,p指向下一个结点继续遍历
	//	若q遍历完毕链表B(即q指向NULL),未出现与p所指向结点数据域相等的情况,则满足添加条件,将数据域为当前p所指向结点的数据域的数据结点添加至C的尾部.直至p遍历完A链表结束.
	LinkList *p = A->next, *q = B->next, *s, *r;
	r = C;
	while (q != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = q->data;
		s->next = r->next;
		r->next = s;
		r = s;
		q = q->next;//第一次写时忘记加了
	}
	q = B->next;
	while (p != NULL) {
		q = B->next;
		while (q != NULL) {
			if (p->data == q->data) {
				break;
			}
			else {
				q = q->next;
			}
		}
		if (NULL == q) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = r->next;
			r->next = s;
			r = s;
		}
		p = p->next;
	}
}

void interset2331_czy(LinkList * A, LinkList * B, LinkList *& C) {
	//P46, 例2-3-31, 已知递增有序的单链表A、B和处分别存储了一个结合,设计一个算法实现A = A ∪ ( B ∩ C ), 并使求解结果A仍保持递增.要求算法的时间复杂度为O(|A|+|B|+|C|).其中|A|为集合A的元素个数.
	//算法思路: 首先实现B ∩ C, 因为B和C均为递增有序的单链表,因此p和q指针分别从B的第一个数据结点和C的第一个数据结点分别向后一个接一个的遍历,
	//	若当前p和q所指向的数据结点的数据域相等,则新链表(假设为D)中尾插法增加新结点,数据域为当前p所指向结点的数据域,然后p和q分别指向各自的后继结点
	//	若当前p所指向的数据结点的数据域小于q所指向的数据结点的数据域,则p指向p当前所指结点的后继结点
	//	若当前p所指向的数据结点的数据域大于q所指向的数据结点的数据域,则q指向q当前所指结点的后继结点
	//	循环上述,直至q或q遍历完毕

	LinkList *p = A->next, *q = B->next, *s, *r;
	r = C;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			p = p->next;
		}
		else if (p->data == q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = r->next;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
		else if (p->data > q->data) {
			q = q->next;
		}
	}
}

void unionsetIncrease2331_czy(LinkList * A, LinkList * B, LinkList *& C) {
	//P46, 例2-3-31, 已知递增有序的单链表A、B和处分别存储了一个结合,设计一个算法实现A = A ∪ ( B ∩ C ), 并使求解结果A仍保持递增.要求算法的时间复杂度为O(|A|+|B|+|C|).其中|A|为集合A的元素个数.
	//算法思路: 其次实现A ∪ D (D = B ∩ C), p和q分别指向A和D的首个数据结点,并分别遍历A和D.
	//	若p所指向结点的数据域小于q所指向结点的数据域,则在新链表(假设为E)中尾插法增加数据域为p所指结点的数据域数值的新结点,然后p指向p当前所指结点的后继结点
	//	若p所指向结点的数据域大于q所指向结点的数据域,则在新链表中尾插法增加数据域为q所指结点的数据域数值的新结点,然后q指向q当前所指结点的后继结点
	//	若p和q所指向结点的数据域等于q所指向结点的数据域,则在新链表中尾插法增加数据域为p/q所指结点的数据域数值的新结点,然后p和q分别指向p和q当前所指结点的后继结点
	// 当p和q之一遍历完毕,则将未遍历完毕的那个链表剩余结点依次利用尾插法添加至新链表的尾部,算法结束.
	LinkList *p = A->next, *q = B->next, *s, *r;
	r = C;
	while (p != NULL && q != NULL) {
		if (p->data == q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = r->next;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
		else if (p->data > q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = q->data;
			s->next = r->next;
			r->next = s;
			r = s;
			q = q->next;
		}
		else if (p->data < q->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = r->next;
			r->next = s;
			r = s;
			p = p->next;
		}
	}
	if (p != NULL) q = p;//第一次写时忘记加把未遍历完的链表全部输出了.
	while (q != NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = q->data;
		s->next = r->next;
		r->next = s;
		r = s;
		q = q->next;
	}
}

void operator2331_czy_ref(LinkList * A, LinkList * B, LinkList * C, LinkList *& D, LinkList *& E) {
	//P46, 例2-3-31, 已知递增有序的单链表A、B和处分别存储了一个结合,设计一个算法实现A = A ∪ ( B ∩ C ), 并使求解结果A仍保持递增.要求算法的时间复杂度为O(|A|+|B|+|C|).其中|A|为集合A的元素个数.
	//算法思路: 首先实现B ∩ C， 并将生成的新链表保存至D, 其次实现A ∪ D (D = B ∩ C), 并将生成的新链表保存至E.
	interset2331_czy(B, C, D);
	unionsetIncrease2331_czy(A, D, E);
}

void inorderList2332_czy(LinkList *& L, int x) {
	LinkList * p = L, *q = L->next, *s;
	while (q != NULL) {
		if (q->data >= x) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = x;
			s->next = q;
			p->next = s;
			break;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	if (q == NULL) {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = x;
		s->next = NULL;
		p->next = s;
	}
}

void splitTwo2333_czy(LinkList *& A, LinkList *& B) {
	//P49, 例2-3-33, 设计一个算法,将一个头结点指针为A的单链表(其数据域为整数)分解成两个单链表A和B, 使得A链表只含有原链表A中data域为奇数的结点, 而B链表只含有原链表A中data域为偶数的结点,且保持原来的相对顺序.
	//算法思路: 将p指针指向A链表的第一个数据结点,然后将A链表置为空,即A链表头结点的指针域为NULL,使rA指向新的A链表的尾结点(最开始指向头结点),建立新链表B的头结点,并使得rB指向B链表的尾结点(最开始指向头结点)
	//	p依次遍历原有单链表的每一个数据结点,并判断其数据域奇数/偶数,
	//	若p当前所指向结点的数据域为偶数,则利用尾插法将数据域为p当前所指向数据结点的数据域数值的新结点插入链表B,并使得p指向p当前所指向数据结点的后继结点
	//	若p当前所指向结点的数据域为奇数,则利用尾插法将数据域为p当前所指向数据结点的数据域数值的新结点插入新链表A,并使得p指向p当前所指向数据结点的后继结点
	//	直至p遍历完毕原有单链表,即p == NULL时,遍历结束, 算法步骤完成, 显然算法时间复杂度为O(n).
	LinkList *p = A->next, *s, *rA, *rB;
	A->next = NULL;
	rA = A;
	B = (LinkList *)malloc(sizeof(LinkList));
	B->next = NULL;
	rB = B;
	while (p != NULL) {
		if (p->data % 2 == 0) {//p当前所指向结点的数据域为偶数
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = rB->next;
			rB->next = s;
			rB = s;
			p = p->next;
		}
		else if (p->data % 2 != 0) {//p当前所指向结点的数据域为奇数
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = p->data;
			s->next = rA->next;
			rA->next = s;
			rA = s;
			p = p->next;
		}
	}
}

void deleteAllNode2334_czy(LinkList *& h) {
	//P49, 例2-3-34, 设计一个算法删除并释放以h为表头指针的单链表的所有结点.
	//算法思路: 使得p指向头结点,q指向第一个数据结点
	//	释放p的内存空间,然后使得p指向q,q指向q的后继结点,直至q遍历完毕所有结点,即q此时为NULL,跳出循环,则此时整个单链表包括头结点只剩下最后一个数据结点,即p所指向的结点未释放,free(p)即可,然后使得 h = NULL
	//头结点h被释放为什么还可以h = NULL?
	LinkList * p = h, *q = p->next;
	while (q != NULL) {
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
	h = NULL;//h结点不是被free掉了么？？？
	/*
	//保留头结点的写法(未仔细审题,题目显然要求删除所有结点,即包括头结点
	LinkList * p = h->next, *q = p->next;
	h->next = NULL;
	while (q != NULL) {
		free(p);
		p = q;
		q = q->next;
	}
	free(p);
	*/
}

void deleteAllNode2334_2rd(LinkList *& h) {
	//P49, 例2-3-34, 设计一个算法删除并释放以h为表头指针的单链表的所有结点.
	//算法思路: 以h指针遍历整个以h所指向结点为头结点的链表
	//	新建链表结点指针p,p指向h当前所指向的结点, h指向h的后继结点,释放p结点,即h的前驱结点,则当h = NULL时,全部结点,包括头结点全部释放内存, 此时h指向NULL
	LinkList *p;
	while (h != NULL) {
		p = h;
		h = h->next;
		free(p);
	}
}

void pubSolo2335_czy(LinkList *& A, LinkList * B, LinkList * C) {
	//	//P50, 例2-3-35, 已知3个单链表A、B和C中的结点均依元素值自小至大非递减排列(可能存在两个以上值相同的结点), 设计一个算法使链表A中仅留下3个灬中均包含的数据元素的结点, 且没有值相同的结点,并释放所有无用结点.
	//	限定算法的时间复杂度为O(m+n+p), 其中m、n和p分别为3个表的长度.
	//算法思路: 首先将链表A中的重复元素删除,则删除完成后A中结点为数据域递增有序且无重复的结点
	//	设置指针pA、pB、pC分别指向A、B和C链表第一个数据结点,另外设置一指针qA指向pA的后继结点,方便释放pA的空间仍然使得pA顺利向后遍历
	//	若B链表结点数据域小于A结点,则B持续向后遍历,直至当前B链表所遍历到的结点的数据域数值不小于A结点当前遍历到的结点的数据域数值或B链表遍历结束,遍历指针指向NULL,并将A未遍历结点一一释放
	//	若C链表结点数据域小于A结点,则C持续向后遍历,直至当前C链表所遍历到的结点的数据域数值不小于A结点当前遍历到的结点的数据域数值或C链表遍历结束,遍历指针指向NULL,并将A未遍历结点一一释放
	//	若原来的A链表遍历到的结点的数据域数值小于B链表当前所遍历到的结点的数据域的数值或者原来的A链表遍历到的结点的数据域数值小于C链表当前所遍历到的结点的数据域的数值,
	//		则使遍历A链表的指针pA指向原来的A链表的当前所遍历结点的后继结点,并使得qA指向后继结点,直至当前A链表pA所遍历的结点数据域数值不小于B和C的结点的数据域数值或A链表遍历结束(此时pA指向NULL)
	//	若pA、pB和pC所指向的结点数据域相等,则将数据域为该结点的数据域的新结点尾插法插入A的新链表.并使得pA、pB、pC和qA分别指向其后一个数据结点
	LinkList * pA = A->next, *pB = B->next, *pC = C->next, *qA = pA->next, *qB = pB->next, *qC = pC->next, *s, *r;
	while (qA != NULL) {
		if (pA->data == qA->data) {
			pA->next = qA->next;
			free(qA);
			qA = pA->next;
		}
		else {
			pA = pA->next;
			qA = qA->next;
		}
	}
	DispLinkList(A);
	/*
	while (qB != NULL) {
		if (pB->data == qB->data) {
			pB->next = qB->next;
			free(qB);
			qB = pB->next;
		}
		else {
			pB = pB->next;
			qB = qB->next;
		}
	}
	DispLinkList(B);
	while (qC != NULL) {
		if (pC->data == qC->data) {
			pC->next = qC->next;
			free(qC);
			qC = pC->next;
		}
		else {
			pC = pC->next;
			qC = qC->next;
		}
	}
	DispLinkList(C);
	*/
	pA = A->next, pB = B->next, pC = C->next, qA = pA->next;
	A->next = NULL;
	r = A;
	while (pA != NULL && pB != NULL && pC != NULL) {
		while (pB->data < pA->data) {
			pB = pB->next;
			if (pB == NULL) {
				if (pA != NULL) {
					free(pA);
					pA = qA;
					if (qA != NULL) qA = qA->next;
				}
				return;
			}
		}
		while (pC->data < pA->data) {
			pC = pC->next;;
			if (pC == NULL) {
				if (pA != NULL) {
					free(pA);
					pA = qA;
					if (qA != NULL) qA = qA->next;
				}
				return;
			}
		}
		while (pA->data < pB->data || pA->data < pC->data) {
			free(pA);
			pA = qA;
			if(pA == NULL) return;//第一次写时忘记加
			qA = qA->next;//上一行添加后忘记加该行
		}
		if (pA->data == pB->data && pA->data == pC->data) {
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = pA->data;
			s->next = r->next;
			r->next = s;
			r = s;
			free(pA);
			pA = qA;
			if(qA != NULL) qA = qA->next;
			pB = pB->next;
			pC = pC->next;
		}
	}
	/*
	if (pA != NULL) {
		free(pA);
		pA = qA;
		if(qA != NULL) qA = qA->next;
	}
	*/
}

void insBefore2410_1_czy(DLinkList *& L, int x, int y) {
	//P56, 例2-4-10-(1), 在带头结点head的双链表中的元素值为x的结点之前插入元素值为y的结点,编写该算法(假设在双链表中不存在值域相同的两个结点).
	//算法思路: 用指针p遍历双链表L, 直至p的后继结点为NULL或者p的后继结点的数据域为x(即p->next->data == x)
	//	若p的后继结点为NULL, 则链表中无元素值为x的结点,不插入,算法结束
	//	若p的后继结点的数据域为x,则插入位置为p之后,尾插法将数据域数值为y的新结点插入到p之后,算法结束
	DLinkList *p = L, *s;
	while (p->next != NULL && p->next->data != x) {// 第一次写时写成了 p != NULL
		p = p->next;
	}
	if (p->next == NULL) return;//第一次写时写成了 p == NULL
	s = (DLinkList *)malloc(sizeof(DLinkList));
	s->data = y;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}

void insAfter2410_2_czy(DLinkList * L, int x, int y) {
	//P56, 例2-4-10-(2), 在带头结点head的双链表中的元素值为x的结点之后插入元素值为y的结点,编写该算法(假设在双链表中不存在值域相同的两个结点).
	//算法思路: 用p指针遍历双链表L, 直至p所指结点的数据域数值为x(此时新结点的插入位置为p结点之后)或p的后继结点为NULL(此时p结点数据域或为x或不为x)
	//	判断p所指结点的数据域数值,若为x,则用尾插法在p结点之后插入数据域数值为y的新结点,同时注意若插入位置为链表尾部,则不需要将之前的尾部(即NULL)的前驱指针指向新结点.
	DLinkList *p = L->next, *s;
	while (p->next != NULL && p->data != x) {
		p = p->next;
	}
	if (p->data == x) {
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = y;
		s->next = p->next;
		if (p->next != NULL) p->next->prior = s;
		s->prior = p;
		p->next = s;
		return;
	}
}

void swapDListNode2411_czy(DLinkList * h, int x) {
	//P57, 例2-4-11, 设有一个双链表h, 设计一个算法查找第一个元素值为x的结点, 将其与后继结点进行交换.
	//算法思路: 指针p遍历整个双链表,直至当前遍历结点数据域数值为x或者p遍历完毕(此时p指向尾结点的后继结点, 即NULL)
	//	若退出循环时p指向NULL(双链表中不存在元素值为x的结点)或p指向最有一个结点(该结点无后继结点,无法与后继结点进行交换),则不进行任何操作,函数返回,算法结束
	//	除此之外的情况满足交换条件,则将后继节点的元素值赋值给temp,再将p指针所指结点(元素值为x)的数据域数值)赋值给p结点的后继结点的数据域,再将temp赋值给p指针所指结点的数据域,算法结束
	DLinkList *p = h->next;
	int temp;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	if (p == NULL || p->next == NULL) return;
	temp = p->next->data;
	p->next->data = p->data;
	p->data = temp;
}

void swapDListNode2411_2rd(DLinkList * h, int x) {
	//P57, 例2-4-11, 设有一个双链表h, 设计一个算法查找第一个元素值为x的结点, 将其与后继结点进行交换.
	//算法思路: 指针p遍历整个双链表,直至当前遍历结点数据域数值为x或者p遍历完毕(此时p指向尾结点的后继结点, 即NULL)
	// 若p指向NULL,则未找到元素值为x的结点,直接返回
	// 若p的后继结点q为NULL,则p结点为尾结点,无法与后继结点进行交换,直接返回
	// 若p的后继结点为正常结点,则需要交换,
	//	此时采取的思路是将p的前驱结点链接至p的后继结点q(也可以理解为删除结点p),
	//	再将p结点尾插法插入到q的后面,插入时需要注意q结点是否为此时的尾结点,若q结点为尾结点,则不需要将q的后继结点的前驱指针指向p.
	DLinkList *p = h->next, *q;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	if (p == NULL) return;
	else {
		q = p->next;
		if (q != NULL) {
			p->prior->next = q;
			q->prior = p->prior;
			p->next = q->next;
			if (q->next != NULL) q->next->prior = p;
			p->prior = q;
			q->next = p;
			return;
		}
		else return;
	}
}

void locateDListNode2412_czy(DLinkList_2412 *h, int x) {
	DLinkList_2412 *p = h->next, *q;
	while (p != NULL) {
		if (p->data == x) {
			p->freq++;
			q = p->prior;
			if (q != h) {
				p->prior->next = p->next;
				if (p->next != NULL) p->next->prior = p->prior;
				return;
			}
			else return;
		}
		p = p->next;
	}
}

void locateDListNode2412_2rd(DLinkList_2412 * h, int x) {
	//P57, 例2-4-12, 设有一个双链表h, 每个结点中除有prior、data和next3个域外,还有一个访问频度域freq,在链表被起用之前,每个结点中的freq域的值均被初始化为零.
	//	每当进行LocateNode(h,x)运算时,令元素值为x的结点中freq域的值加1, 并调整表中结点的次序, 使其按访问频度的递减序列排序, 以便使频繁访问的结点总是靠近表头.试写一符合上述要求的算法.
	//算法思路: 首先p指针循环遍历到数据域数值为x的结点处,此时退出循环有两种情况,1)无数据域数值为x的结点,则直接返回主函数; 2)找到了数据域数值为x的结点,则令指针q指向p的前驱结点,若:
	//	1)若q指向头结点,则该结点为第一个数据结点,则该结点的freq+1后直接返回主函数;
	//	2)若q不指向头结点,则该结点不是第一个数据结点,则首先将p结点从双链表删除,再用q指针向前遍历双链表,直至1)q指向头结点, 2)q所指结点的freq域数值大于p的freq域,则此时p插入位置应为q所指结点之后，插入即算法完成.
	DLinkList_2412 *p = h->next, *q;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	if (p == NULL) return;
	else {
		q = p->prior;
		p->freq++;
		if (q != h) {
			q->next = p->next;
			if(p->next != NULL) p->next->prior = q;
			while (q != h && q->freq < p->freq) {
				q = q->prior;
			}
			p->next = q->next;
			if(q->next != NULL) q->next->prior = p;
			q->next = p;
			p->prior = q;
		}
		else {
			return;
		}
	}
}

void invertList2513_czy(LinkList *& head) {
	//P64, 例2-5-13, 已知一个循环单链表的逻辑关系为:顺时针链接,head指向尾结点.设计一个算法将逻辑关系改为逆时针链接.
	//算法思路: head指向循环单链表的尾结点,使p指向head的后继结点,即循环单链表的头结点,q指向p的后继结点,即第一个数据结点
	//	首先实现除头结点指针域指向尾结点的指针之外的指针(即除头结点之外的所有结点的指针域)依次逆置,方法如下:
	//		首先令pTemp结点指向当前的p所指向的结点,qTemp指向当前的q所指向的结点,
	//		再使得p和q分别向后移动一个位置
	//		使qTemp的指针域指向pTemp
	//	重复上述三步,直至p指向尾结点,即指向head结点,此时除头结点的指针域指向尾结点之外的所有链接指针均已逆置,最后将q的指针域指向p,算法完成.
	LinkList *p = head->next;
	LinkList *q = p->next;
	LinkList *pTemp, *qTemp;
	while (p != head) {
		pTemp = p;
		qTemp = q;
		p = q;
		q = q->next;
		qTemp->next = pTemp;
	}
	q->next = p;
}

void invertList2513_2rd(LinkList *& head) {
	LinkList *p, *q, *r;
	p = head->next;
	q = p->next;
	p->next = head;
	while (p != head) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
}

void deleteCDListNode2514_czy(DLinkList *& L, int x) {
	//有一个循环双链表,p指向第一个元素值为x的结点,设计一个算法从该循环双链表中删除*p结点.
	DLinkList *p = L->next;//可以不用*q
	//DLinkList *q;
	while (p != L && p->data != x) {
		p = p->next;
	}
	if (p == L) return;
	else {
		//q = p;
		p->next->prior = p->prior;
		p->prior->next = p->next;
		//free(q);
		free(p);
	}
}

void swapCDListNode2515_czy(DLinkList *& L, int x) {
	//设有一个含两个以上结点的循环双链表,p指向第一个元素值为x的结点,设计一个算法将*p与其后继结点进行交换.
	//算法思路: p指针自第一个数据结点开始遍历循环双链表,直到1)p指向头结点或2)p指向数据域为x的元素结点
	//	若为1),则直接返回主函数,不进行任何操作
	//	若为2)则满足交换条件,分为1)满足条件的结点为尾结点或2)满足条件的结点不为尾结点
	//		若为1),则需要将尾结点的数据域与头结点之后的第一个数据结点的数据域进行交换
	//		若为2),则将p所指向的数据结点的数据域与p的后继结点的数据域交换数值即可
	DLinkList *p = L->next;
	int temp;
	while (p != L && p->data != x) {
		p = p->next;
	}
	if (p == L) return;
	if (p->next == L) {
		temp = p->data;
		p->data = L->next->data;
		L->next->data = temp;
	}
	else {
		temp = p->data;
		p->data = p->next->data;
		p->next->data = temp;
	}
}

void reverseCDList2516_czy(DLinkList *& L) {
	//P66, 例2-5-16,设计一个算法倒置一个含两个以上结点的循环双链表.
	//算法思路: p指针从第一个数据结点开始,首先使q指向p的后继结点,然后使当前p的前驱指针域和后继指针域互换,再使得p指向q,重复上述,直至最后一个数据结点
	//	至此,除头结点外的所有数据结点的指针域均已倒置,最后使得q指向p(此时为头结点)的后继结点,然后使当前p(头结点)的前驱指针域和后继指针域(q)互换
	DLinkList *p = L->next, *q;
	while (p != L) {
		q = p->next;
		p->next = p->prior;
		p->prior = q;//第一次写时忘记加了
		p = q;
	}
	q = p->next;
	p->next = p->prior;
	p->prior = q;
}

void reverseCDList2516_2rd(DLinkList *& L) {
	DLinkList *p = L, *q;
	do {
		q = p->next;
		p->next = p->prior;
		p->prior = q;
		p = q;
	} while (p != L);
}

int bracketMatch3207_czy(char exp[]) {
	//P81, 例3-2-7, 假设表达式中允许包含3种括号:圆括号、方括号和大括号.设计一个算法采用顺序栈判断表达式中的括号是否正确配对.
	//算法思路: 用opStack存储所有的左括号,用ch保存遍历整个exp[]数组,直至flag为0或者遍历完整个exp[]数组,flag用以实时更新遍历到当前进度字符串的配对正确与否(初始设为1),
	//	若遍历字符为任一左括号,则压入opStack栈,
	//	若遍历字符为非括号(即为数字或+-*/运算符),则直接跳过,进入下一个字符的匹配,
	//	若遍历字符为右括号,则对opStack的栈顶字符进行判断,
	//		若栈顶字符与当前遍历字符为匹配括号对,则将栈顶元素出栈,进入下一个字符的遍历,
	//		若栈顶字符与当前遍历到的字符不匹配,则说明未能正确配对,置flag为0
	//	flag为0或者exp[]全部扫描遍历完后,若opStack不为空,则说明有左括号没有与之配对的右括号,则说明未能正确配对,置flag为0.
	//	最后,flag为1,则说明算术表达式正确配对,flag为0,则说明算术表达式未能正确配对,算法结束.
	st opStack;
	opStack.top = -1;
	int i = 0, flag = 1;
	char ch = exp[i];
	while (ch != '\0' && flag == 1) {//字符串的结束标识符为\0,不是\n,\n是换行符,不要迷糊。
		switch (ch) {
			case '[':
			case '(':
			case '{':
				opStack.top++;
				opStack.data[opStack.top] = ch;
				break;
			case ')':
				if (opStack.data[opStack.top] == '(') {
					opStack.top--;
					break;
				}
				else {
					flag = 0;
					break;
				}
			case ']':
				if (opStack.data[opStack.top] == '[') {
					opStack.top--;
					break;
				}
				else {
					flag = 0;
					break;
				}
			case '}':
				if (opStack.data[opStack.top] == '{') {
					opStack.top--;
					break;
				}
				else {
					flag = 0;
					break;
				}
			default:
				//while (exp[i] != '\n' && exp[i] != '(' && exp[i] != '[' && exp[i] != '{' && exp[i] != ')' && exp[i] != ']' && exp[i] != '}') {
					//i++;
				//}
				//if (exp[i] == '\n') flag = 0;
				//i--;
				break;
		}
		i++;
		ch = exp[i];
	}
	if (opStack.top != -1) flag = 0;
	return flag;
}

void isPopSq3208_ans(int pos, int path[], int curp, int totalSeq, SqStack seq) {
	//P82, 例3-2-8, 设以整数序列1, 2, 3, 4作为顺序栈st的输入, 利用push(进栈)和pop(出栈)操作, 写出所有可能的输出并编程实现算法.
	//算法思路: 
	int m, x;
	if (pos <= totalSeq) {
		PushStack(seq, pos);
		isPopSq3208_ans(pos + 1, path, curp, totalSeq, seq);
		PopStack(seq, x);
	}
	if (!StackEmpty(seq)) {
		PopStack(seq, m);
		path[curp] = m;
		curp++;
		isPopSq3208_ans(pos, path, curp, totalSeq, seq);
		PushStack(seq, m);
	}
	if (pos > totalSeq && StackEmpty(seq)) {
		printf_s(" ");
		for (int i = 0; i < curp; i++) {
			printf_s("%d ", path[i]);
		}
		printf_s("\n");
	}
}

void initSharedStack3209_1_czy(sharedSt &sst) {
	//P82, 例3-2-9, 用一个一维数组S(设大小为MaxSize)作为两个栈的共享空间.请说明共享方法,栈满、栈空的判断条件,
	//	并用C/C++语言设计公用的初始化栈运算、栈判空运算、入栈运算和出栈运算,其中i为1或2, 用于表示栈号,x为入栈或出栈元素.
	//P82, 例3-2-9-1, 两个栈共享一个一位数组空间构成共享栈, 实现共享栈的初始化的算法
	sst.top1 = -1;
	sst.top2 = MaxSize;
}

int isEmptySharedStack2309_2_czy(sharedSt sst, int i) {
	//P82, 例3-2-9, 用一个一维数组S(设大小为MaxSize)作为两个栈的共享空间.请说明共享方法,栈满、栈空的判断条件,
	//	并用C/C++语言设计公用的初始化栈运算、栈判空运算、入栈运算和出栈运算,其中i为1或2, 用于表示栈号,x为入栈或出栈元素.
	//P82, 例3-2-9-2, 实现判断共享栈中栈i是否为空的算法
	if (i == 1) return (sst.top1 == -1);
	else if (i == 2) return (sst.top2 == MaxSize);
	else return 0;//否则出现不是所有的控件路径都返回
}

int pushSharedStack2309_3_czy(sharedSt & sst, int i, int x) {
	//P82, 例3-2-9, 用一个一维数组S(设大小为MaxSize)作为两个栈的共享空间.请说明共享方法,栈满、栈空的判断条件,
	//	并用C/C++语言设计公用的初始化栈运算、栈判空运算、入栈运算和出栈运算,其中i为1或2, 用于表示栈号,x为入栈或出栈元素.
	//P82, 例3-2-9-3, 实现对共享栈中栈i进行进栈操作的算法
	if (sst.top1 == sst.top2 - 1) return 0;
	if (i == 1) {
		sst.top1++;
		sst.data[sst.top1] = x;
	}
	else if (i == 2) {
		sst.top2--;
		sst.data[sst.top2] = x;
	}
	else return 0;
	return 1;
}

int popSharedStack2309_4_czy(sharedSt & sst, int i, int & x) {
	//P82, 例3-2-9, 用一个一维数组S(设大小为MaxSize)作为两个栈的共享空间.请说明共享方法,栈满、栈空的判断条件,
	//	并用C/C++语言设计公用的初始化栈运算、栈判空运算、入栈运算和出栈运算,其中i为1或2, 用于表示栈号,x为入栈或出栈元素.
	//P82, 例3-2-9-4, 实现对共享栈中栈i进行出栈操作的算法
	if (i == 1) {
		if (sst.top1 == -1) return 0;
		else {
			x = sst.data[sst.top1];
			sst.top1--;
		}
	}
	else if (i == 2) {
		if (sst.top2 == MaxSize) return 0;
		else {
			x = sst.data[sst.top2];
			sst.top2++;
		}
	} 
	else return 0;
	return 1;
}

int stackBottom3210_czy(SqStack st) {
	//P84, 例3-2-10, 设计一个算法, 利用栈的InitStack()、 Push()、 Pop()和StackEmpty()等基本运算返回指定栈中栈底元素.
	//算法思路: 开辟一个临时栈,逐个弹出给定栈的元素,利用中间变量x接收弹出的元素并赋值给临时栈,直到给定栈全部弹出,此时x的值恰为栈底元素的值,此时临时栈的元素顺序为给定栈元素顺序的逆序
	//	从临时栈中逐个弹出全部元素,用临时变量y接收弹出的元素并压入给定栈,重复该操作直至临时栈为空.
	//	则此时x的值为给定栈的栈底元素的值,且给定栈已恢复至原貌,算法结束.
	SqStack tempSt;
	InitStack(tempSt);
	int x, y;
	while (!StackEmpty(st)) {
		PopStack(st, x);
		PushStack(tempSt, x);
	}
	while (!StackEmpty(tempSt)) {
		PopStack(tempSt, y);
		PushStack(st, y);
	}
	return x;
}

int judge338_czy(int A[], int n) {
	//	P89, 例3-3-8, (略有修改)假设以1和0分别表示入栈和出栈操作, 栈的初态和终态均为空, 入栈和出栈的操作序列可表示为仅由1和0组成的序列.写出一个算法判定所给的操作序列是否合法.若合法返回1;否则返回0(假设被判定的操作序列已存入一维数组中).
	//算法思路: 开辟一个空的单链表栈以模拟IO过程.
	//	对已知操作序列A[]进行逐个操作遍历,
	//	若操作为1,则将该操作(即int类型的数字1入栈);
	//	若操作为0,则对模拟IO栈进行出栈操作,根据出栈结果的返回值,判断出栈成功与否
	//		若返回值为1,则出栈成功,继续遍历操作序列;
	//		若返回值为0,则出栈失败,表明该操作序列为不合法序列,直接返回0;
	//	若操作既不为1,也不为0,则出现非法操作,直接返回0;
	//	全部遍历结束后,即全部的入栈、出栈操作均为合法操作,此时对模拟IO栈进行判空,若不为空,则不满足题意(终态不为空),返回0;若为空,则满足题意,返回1;算法结束.
	LStackNode *lst;
	InitLStack(lst);
	int x;
	for (int i = 0; i < n; i++) {
		if (A[i] == 1) {
			pushLStack(lst, A[i]);
		}
		else if (A[i] == 0) {//第一次写错了,需要用temp接收是否出栈成功以对是否合法做出判断.
			int temp = popLStack(lst, x);
			if (temp == 0) return 0;
		}
		else {
			return 0;
		}
	}
	return (lst->next == NULL);
}

int nodeCount339_czy(LStackNode * lst) {
	//P89, 例3-3-9, 在栈顶头结点为lst的链栈中, 设计一个算法计算该链栈中结点个数.
	//算法思路: 单链表栈结点指针p指向头结点,从头结点开始逐个遍历以lst为头结点的单链表,直至栈底;count用以计数栈中结点个数,初始值为1;
	//	若p当前所指结点的后继结点不为空,则count++并且p更新为指向p的后继结点,直至p的后继结点为NULL,此时count值即为该链栈中结点个数.
	LStackNode *p = lst;
	int count = 0;
	while (p->next != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

int rearQueue4210_czy(SqQueue qu) {
	//设计一个算法,利用队列的基本运算返回指定队列的队尾元素.
	//算法思路: 
	int x;
	SqQueue tempQu;
	initSqQueue(tempQu);
	while (!isEmptyQueue(qu)) {
		deQueue(qu, x);
		enQueue(tempQu, x);
	}
	while (!isEmptyQueue(tempQu)) {
		deQueue(tempQu, x);
		enQueue(qu, x);
	}
	return x;
}

void Insert4312_czy(LQNode * QH[], LQNode * QT[], int x) {
	//P130, 例4-3-12, 由用户输入n个10以内的数,每输入i(0≤i≤9),就把它插入到第i号队列中.最后把10个队中非空队列,按队列号从小到大的顺序串接成一条链,并输出该链的所有元素.
	//算法思路: 根据题目要求,产生十个基于不带头结点的单链表为存储结构的队列,十个队列(十个队头指针和十个队尾指针)以数组指针的形式给出
	//	首先scanf_s获取数的数量n,通过0~n-1的for循环获取到n个10以内的数字(每次输入数字判断该数字是否为10以内的数,若不是则要求重新输入,直至满足"输入的数字为10以内的数字"的要求)
	//	for循环中每获取一个10以内的数字,通过Insert函数将该数字x添加至以*QH[x]为头结点,*QH[x]为尾结点的单链表中,Insert函数的算法思路如下:
	//		新建LQNode类型的单链表结点,将该结点数据域赋值为父函数Create当次for循环内由用户输入的x变量的数值,指针域置为NULL(因插入队尾,单链表链尾结点的指针域必为NULL),
	//		然后判断本次插入到的队列是否为空队列(判断方法为QH[x]==NULL),若为空队列,则将QH[x]和QT[x]均指向该新建的结点;若该队列不为空,则尾插法将新结点插入到单链表的尾部
	//	for循环结束后,已完成n个10以内的数已响应的插入到对应队列,建立Link函数依次遍历所有队列,将所有非空队列按照队列号从小到大的顺序串接至以*head为队头,*tail为队尾的单链表中,Link函数具体思路如下:
	//		为要串起所有非空队列,将所有非空队列的元素按照要求保存至一个新队列,则开辟新队列的队头指针*head和队尾指针*tail
	//		因基于单链表的空队列的添加结点和非空队列的添加结点算法不一致,设置一个first变量并置数值为1,每次添加结点时判断语句(判断链表是否为空)中均包含对first的判断,
	//		则在进入空链表插入新结点的操作算法的判断分支中,first == 1 作为必要条件,则链表为空时进入空链表插入新结点的操作算法,并且在该算法最后置first为0
	//		在进入非空链表插入新结点的操作算法的判断分支中,first == 0 作为必要条件,则当且仅当第一次,即链表为空时进入空链表添加结点的算法,其余情况均进入非空链表的添加结点的算法分支
	//		关于结点插入的具体算法思路:因该链队为多个非空链队所组成的新链队,因此不再单个结点插入,而是直接将整个非空子链队链接至新链队上,具体如下:
	//			若新链队为空,即first == 1,则将新链队队头head指向按顺序非空子链队的队头,新链队队尾tail指向按顺序第一个非空子链队的队尾,随后置first = 0,此时完成了基于无头结点单链表存储结构的空队列的第一次插入操作
	//			若新链队不为空,即first == 0,则将新链队队尾的next域指向当前遍历到的非空子链队的队头,新链队的队尾指向非空子队列的队尾,重复遍历所有非空子链队,并依次添加至新链队队尾,算法结束,此时新链队即为非空队列按队列号从小到大的顺序串接成的一条链,输出即可.
	LQNode *s = (LQNode *)malloc(sizeof(LQNode));
	s->data = x;
	s->next = NULL;
	if (QH[x] == NULL) {
		QH[x] = QT[x] = s;
	}
	else {
		QT[x]->next = s;
		QT[x] = s;
	}
}

void Create4312_czy(LQNode * QH[], LQNode * QT[]) {
	//P130, 例4-3-12, 由用户输入n个10以内的数,每输入i(0≤i≤9),就把它插入到第i号队列中.最后把10个队中非空队列,按队列号从小到大的顺序串接成一条链,并输出该链的所有元素.
	int n, x;
	printf_s("Please input 'n':");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf_s("Please input No%d numbers in orders:", i + 1);
		scanf_s("%d", &x);
		while (x < 0 || x > 10) {
			printf_s("Input error.Please input again:");
			scanf_s("%d", &x);
		}
		Insert4312_czy(QH, QT, x);
	}
}

void Link4312_czy(LQNode * QH[], LQNode * QT[]) {
	//P130, 例4-3-12, 由用户输入n个10以内的数,每输入i(0≤i≤9),就把它插入到第i号队列中.最后把10个队中非空队列,按队列号从小到大的顺序串接成一条链,并输出该链的所有元素.
	LQNode *head = NULL, *tail = NULL;
	int first = 1;
	for (int i = 0; i < 10; i++) {
		if (QH[i] != NULL && first == 1) {
			head = QH[i];
			tail = QT[i];
			first = 0;
		}
		if (QH[i] != NULL && first == 0) {
			tail->next = QH[i];
			tail = QT[i];
		}
	}
	printf_s("The whole numbers are as follow:");
	while (head != NULL) {
		printf_s("%d ", head->data);
		head = head->next;
	}
	printf_s("\n");
}

void SeeDoctor4313_czy() {
	//data域的数据类型为int 范围较小且若0开头就丢掉了,需要改成char或者double
	//P131, 例3-4-13, 采用链队设计一个算法,反映病人到医院看病、排队看医生的情况.在病人排队过程中,主要重复两件事:
	//		1)病人到达诊室,将病历交给护士,排到等待队列中候诊.
	//		2)护士从等待队列中取出下一位病人的病历,该病人进入诊室就诊.
	//	要求模拟病人等待就诊这一过程.程序采用菜单方式,下面将对其选项及功能进行说明.
	//		1:排队 输入排队病人的病历号,加入到病人排队队列中.
	//		2:就诊 病人排队队列中最前面的病人就诊,并将其从队列中删除.
	//		3:查看排队 从队首到队尾列出所有的排队病人的病历号.
	//		4:不再排队,余下依次就诊 从队首到队尾列出所有的排队病人的病历号,并退出运行.
	//		5:下班 退出运行
	LinkQueue *qu = (LinkQueue *)malloc(sizeof(LinkQueue));//需要为qu分配内存空间！！否则出现使用了未初始化的局部变量"qu"
	LQNode *s, *temp;//s需要在switch外定义,否则会出现跳过case标签的错误
	qu->front = NULL;
	qu->rear = NULL;
	int num, count = 0;
	printf_s("输入'1':添加排队病人至排队队列尾部\n");
	printf_s("\n");
	printf_s("输入'2':安排病人排队队列中最前面的病人就诊,并将其从队列中删除\n");
	printf_s("\n");
	printf_s("输入'3':从队首到队尾列出所有的排队病人的病历号\n");
	printf_s("\n");
	printf_s("输入'4':不再排队,从队首到队尾列出所有的排队病人的病历号,并退出运行\n");
	printf_s("\n");
	printf_s("输入'5':下班,程序退出运行\n");
	printf_s("\n");
	printf_s("---------------------------------------------------------------\n");
	printf_s("\n");
	while (1) {
		printf_s("  请输入要进行的操作,并按回车执行该操作:");
		scanf_s("%d", &num);
		printf_s("\n");
		switch (num) {
		case 1:
			s = (LQNode *)malloc(sizeof(LQNode));
			s->next = NULL;
			printf_s("   请输入病人病历号,按回车后系统将自动将该病人加入到排队队列的最后:");
			scanf_s("%d", &s->data);
			printf_s("\n");
			if (qu->rear == NULL) {
				qu->front = qu->rear = s;
				count++;
				printf_s("	系统已将病历号为 \"%d\" 的病人添加至排队队列的最后,当前排队人数为: %d.\n", qu->rear->data, count);
				printf_s("\n");
			}
			else {
				qu->rear->next = s;
				qu->rear = s;
				count++;
				printf_s("	系统已将病历号为 \"%d\" 的病人添加至排队队列的最后,当前排队人数为: %d.\n", qu->rear->data, count);//第一次写时写成了qu->front->data
				printf_s("\n");
			}
			break;
		case 2:
			if (qu->rear == NULL) {
				printf_s("	暂无等待病人！\n");
				printf_s("\n");
				break;
			}
			printf_s("	下面将安排病历号为 %d 的病人就诊\n", qu->front->data);
			printf_s("	已成功安排病历号为 %d 的病人就诊\n", qu->front->data);
			count--;
			if (qu->front == qu->rear && qu->rear != NULL) {
				qu->rear = qu->front = NULL;
				printf_s("	队列中已无候诊病人！\n");
				printf_s("\n");
			}
			else {
				temp = qu->front;
				qu->front = qu->front->next;
				free(temp);
				printf_s("	队列中有 %d 个病人候诊\n", count);
				printf_s("\n");
			}
			break;
		case 3:
			if (qu->front == NULL) {
				printf_s("	暂无排队病人!\n");
				printf_s("\n");
				break;
			}
			printf_s("	当前队列中有 %d 个人排队,所有的排队病人的病历号依次为:(按照最先就诊到最后就诊的患者顺序依次输出:)\n", count);
			temp = qu->front;
			while (temp != NULL) {
				printf_s("	 %d  ", temp->data);
				temp = temp->next;
			}
			printf_s("\n");
			printf_s("\n");
			break;
		case 4:
			if (qu->front == NULL) {
				printf_s("	已设置不再接收新病人,当前暂无排队病人!\n");
				exit(0);
			}
			printf_s("	已设置不再接收新病人,当前队列中有 %d 个人排队,所有的排队病人的病历号依次为:\n", count);
			temp = qu->front;
			while (temp != NULL) {
				printf_s("	 %d  ", temp->data);
				temp = temp->next;
			}
			printf_s("\n");
			exit(0);
		case 5:
			if (qu->rear != NULL) printf_s("	请排队的病人明天就诊\n");//为什么print和if放在一行tab感觉变长了,但是实际运行的效果是一致的？
			printf_s("	下班！\n");
			exit(0);
		}
	}
}

void count525_czy(SqString s) {
	//P140, 例5-2-5, 设计一个算法, 计算一个串s中每一个字符出现的次数.
	//算法思路: i用以遍历已知字符串s,j用以遍历字符种类数组C[].
	//	新开一个结构体Cch,开辟一个该结构体类型的数组,结构体包含单个字符和该字符int类型的出现次数变量count.每出现一个新的字符种类,则依次存入数组的ch域中.
	//	n用来记录已经出现的字符种类数,用于最后输出所有情况及用于每次遍历整个已有的字符种类数组C[j].
	//逐个遍历已有字符串s,将当前字符s.ch[i]与C[0].ch~C[j].ch(0<j<n)逐个比对,
	//	若出现比对一致,则令c[j].count++,跳出j的循环,继续遍历比对s的下一个字符.
	//	若C[0].ch~C[n - 1]全部比对失败,即for循环不是通过break跳出的,即此时j = n,则标明当前遍历到的s中的该字符未存于字符类型数组中,则顺次将C[n](第n+1种字符)添加至字符类型数组,并令C[n].count = 1,然后令字符种类数目加1,即n++
	//	【注意】因上述j = n需要借助j来判断,并且该判断是在j的for循环之外,因此j的创建需要在开头创建,而不能在j的for循环中临时int j.
	//s遍历完毕后,通过while(n--),即n次循环,依次把C[n - 1](即第n种字符)~C[0](第1种字符)的出现次数情况依次打印,算法结束.
	typedef struct {
		char ch;
		int count;
	}Cch;
	Cch C[MaxSize];
	int n = 0;
	int i = 0, j = 0;
	for (i = 0; i < s.Length; i++) {
		for (j = 0; j < n; j++) {//第一次写时<=写成了<
			if (C[j].ch == s.ch[i]) {
				C[j].count++;
				break;
			}
		}
		if (j == n) {//==写成了=,另外一开始写进了j的for循环里
			C[n].ch = s.ch[i];
			C[n].count = 1;
			n++;
		}
	}
	while (n--) {
		printf_s("The character %c's appearence times are: %d\n", C[n].ch, C[n].count);
	}
	printf_s("\n");
}

SqString RepStr526_czy(SqString s, int i, int j, SqString t) {
	//参考答案,while循环可以全部改为for循环,k初值设为while的上一行设置的k初值即可
	//P140, 例5-2-6, 设计一个算法RepStr(),在串s中将第i(1≤i≤n)个字符开始的j个字符构成的子串用串t替换,并返回产生的新串.
	//算法思路: 建立一个新串str用以保存根据题目要求生成的新串,变量k用以顺序读取题目要求的原串的下标位置以顺序读取应读取的字符.
	//	首先将串s中第1~第i-1个字符依次保存至新串,再将串t所有字符依次保存至新串的末尾,最后将串s中第i+j个字符到最后一个字符依次保存至新串的末尾.至此,算法结束.
	SqString str;
	int k;
	str.Length = 0;
	if (i <= 0 || i + j - 1 > s.Length) return str;//第一次写时忘记了i<=0的情况,另个人认为i>length的情况包含在i + j - 1 > s.Length中了
	for (k = 0; k < i - 1; k++) {
		str.ch[k] = s.ch[k];
	}
	str.Length = i - 1;
	k = 0;
	while (k < t.Length) {//不能用t.ch[k] != '\0'，为什么？？？
		str.ch[str.Length++] = t.ch[k++];
	}
	k = i + j - 1;
	while (k < s.Length) {
		str.ch[str.Length++] = s.ch[k++];
	}
	return str;
}

int StrCmp527_czy(SqString s, SqString t) {
	//P141, 例5-2-7, 设计StrCmp(s, t)算法,实现两个串s和t的比较.
	int comLen;
	if (s.Length < t.Length) comLen = s.Length;
	else comLen = t.Length;
	for (int i = 0; i < comLen; i++) {
		if (s.ch[i] < t.ch[i]) return -1;
		else if (s.ch[i] > t.ch[i]) return 1;
		else continue;//不写效果一样
	}
	if (s.Length == t.Length) return 0;
	else if (s.Length < t.Length) return -1;
	else return 1;
}

int Find528_ans(SqString s, char x) {
	//P142, 例5-2-8, 设计一个递归算法,利用串的基本运算SubStr()判断字符x是否在串s中.
	SqString s1;
	if (s.Length == 0) return 0;
	else if (s.ch[0] == x) return 1;
	else {
		s1 = SubStr(s, 2, s.Length - 1);
		return Find528_ans(s1, x);
	}
}

void reverse529_ans(SqString & s) {
	//P142, 例5-2-9, 设计一个递归算法,利用串的基本运算StrLength()、SubStr()、Concat()将非空串s的所有字符逆置.
	SqString s1, s2;
	if (StrLength(s) > 1) {
		s1 = SubStr(s, 1, 1);
		s2 = SubStr(s, 2, s.Length - 1);
		reverse529_ans(s2);
		s = Concat(s2, s1);
	}
}

LiString * RepLiStr533_czy(LiString * s, int i, int j, LiString * t) {
	//P147, 例5-3-3, 设计一个算法,在链串s中,将第i(1≤i≤n)个字符开始的j个字符构成的子串用串t替换,并返回产生的新串.
	//算法思路: 建立一个新链表str,p指向s的头结点用以遍历str;p1指向t的头结点用以遍历t;
	//若i <= 0 或 i + j - 1 > s.length,则代表i~j - 1所代表的的替换不对;
	//将链串s中第1`第i - 1个(特殊的,i = 1 时,直接跳过第一阶段猪哥添加s中结点至str的循环遍历添加过程)结点利用尾插法依次添加至str.
	//跳过链串s中第i~第j - 1(即第i个字符开始的j个字符),此时p指向
	//将t的所有结点利用尾插法添加至str的尾部.
	//将p所指向的结点,即str第i + j个字符直至最后一个字符添加至str尾部(需要特别注意str的尾结点的指针域赋值为NULL),算法结束.
	LiString *str = (LiString *)malloc(sizeof(LiString)), *p = s->next, *p1 = t->next, *q, *r;
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

void delSubLiStr534_czy(LiString *& s) {
	//P147, 例5-3-4, 设计一个算法将一个链串s中的所有子串"abc"删除.
	//算法思路: 令指针p指向s的头结点,通过指针p遍历s得到s的长度Length;
	//若count >= 3 ,则代表串长度大于等于3,则至少满足存在一长度为3的子串,此时新建三个指针q、r、t,依次指向p的后继结点(即第一个数据结点)、第二个数据结点、第三个数据结点
	//	若此时的p、q、r 恰等于子串"abc",则将p的指针域指向r的后继结点,并free掉此时q、r、t所指向的结点,同时令Length = Length - 3,回到对Length >= 3 的while判断继续循环
	//	若此时的p、q、r 不等于子串"abc",则至少第一个数据结点必不是被删除结点,即此时q所指向的结点被排除在外,则令p指向此时q所指向的结点,并使得Length--(Length从实际作用上应该理解为链串总长度-必然不会被删除的结点数,即剩余待判断结点数,显然Length < 3时剩余的结点已经没有被判断的意义了)
	//Length < 3 s时,即已对随着满足条件的3个一组的结点的释放而不断更新的所有的三个连续的子串进行了与"abc"子串的比对,此时s即为不包含子串"abc"的链串,算法结束.
	LiString *p = s, *q, *r, *t;
	int Length = 0;
	while (p->next != NULL) {
		p = p->next;
		Length++;
	}
	p = s;
	while (Length >= 3) {
		q = p->next;
		r = q->next;
		t = r->next;
		if (q->data == 'a' && r->data == 'b' && t->data == 'c') {
			p->next = t->next;
			free(q);
			free(r);
			free(t);
			Length = Length - 3;
		}
		else {
			p = p->next;
			Length--;
		}
	}
}

int isIncreaseLiStr535_czy(LiString * s) {
	//P148, 例5-3-5, 设计一个算法判断链串s中所有元素是否为递增排列的.
	//算法思路: 首先使得指针p指向s的第一个数据结点,若第一个数据结点不为NULL(即链串s不为空),则进入循环分支,循环条件为p存在后继结点,即至少存在一对结点,则进入循环依次比对每两个连续的结点,若第一个数据结点为NULL,则标明该链串为空链串,直接返回0,算法结束.
	//	若此时p和q所指向的结点的元素满足递增关系,则令p指向p的后继结点即q,进入下一次循环判断,需再次判断此时的p是否有后继结点,如此循环判断,直至某一对结点不满足递增关系或p的后继结点为NULL;
	//	若某一对p和q所指向的结点的元素不满足递增关系,则该链串至少有一对结点不满足题设递增关系,则直接返回0,不再继续遍历接下来可能存在的每一对链串是否递增,算法结束,
	//	若p的后继节点为NULL,则表示该链串所有的紧邻的两个结点满足递增排列的关系,即满足题设,返回1,算法结束.
	LiString *p = s->next, *q;
	if (p != NULL) {
		while (p->next != NULL) {
			q = p->next;
			if (p->data <= q->data) {
				p = q;
			}
			else {
				return 0;
			}
		}
		return 1;
	} else {
		return 0;
	}
}

int findk6116_czy(int i, int j) {
	//P169, 例6-1-16, 一个n阶对称矩阵A[0..n-1,0..n-1]采用一维数组B按行优先顺序存放其上三角各元素,给出B[k]和A[i][j]的关系.
	//算法思路: 
	if (i >= j) return (i * (i + 1) / 2 + j);
	else return (j * (j + 1) / 2 + i);
}

int findij6116_czy(int k, int & i, int & j) {
	//P169, 例6-1-16, 一个n阶对称矩阵A[0..n-1,0..n-1]采用一维数组B[k]按行优先顺序存放其上三角各元素,给出B[k]和A[i][j]的关系.
	//算法思路: 

	return 0;
}

void move6117_czy(int A[], int n) {
	//P170, 例6-1-17, 设一系列正整数存放在一个数组中, 试设计算法, 将所有奇数存放在数组的前半部分, 将所有的偶数存放在数组的后半部分. 要求尽可能少用临时存储单元并使时间最少.分析算法的时间复杂度及空间复杂度.
	//算法思路: i从数组头元素向后遍历,一旦遇到偶数或者i>=j就停止遍历;j从数组尾元素向前遍历,一旦遇到奇数或者i>=j就停止遍历;
	//	此时的i和j若满足i<j,则直接将A[i]和A[j]交换,交换完毕后i继续向后遍历,j继续向前遍历,直至不满足i>=j,则此时前半不分都是奇数,后半部分都是偶数.
	//空间复杂度O(1),时间复杂度O(n)
	int i = 0, j = n - 1, temp;
	while (i < j) {
		while (i < j && A[i] % 2 != 0) {
			i++;
		}
		while (i < j && A[j] % 2 == 0) {
			j--;
		}
		if (i < j) {
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
}

void Find(int B[M6118][N6118], int x, int & i, int & j) {
	//P170, 例6-1-18, 设二维整数数组B[0..m-1,0..n-1]的数据在行、列方向上都按从小到大的顺序排列,且整型变量x中的数据在B中存放.试设计一个算法,找出一对满足B[i][j]=x的i,j值.要求比较次数不超过m+n.
	//算法思路:
	int M = 0, N = N6118 - 1;
	while (B[M][N] != x) {
		if (B[M][N] > x) N--;
		else M++;
	}
	if (B[M][N] == x) {
		i = M;
		j = N;
	}
	else {
		i = j = -1;
	}
}

LBTNode * LBTSearch10228_czy(LBTNode * bt, KeyType key) {
	//P367, 例10-2-28, 设计在二叉排序树中查找指定关键字的结点的非递归算法
	//算法思路: 
	LBTNode *p = bt;
	while (p != NULL && p->key != key) {
		if (p->key < key) {
			p = p->lchild;
		}
		else if (p->key > key) {
			p = p->rchild;
		}
	}
	//if (p->key == key) { 因为此时p要么为NULL(即未找到关键字值为p的结点),要么p所指向的结点关键字值为key
		return p;
	//}
	//else {
	//	return NULL;
	//}
}
