// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H
constexpr auto MaxSize = 10000;
//#define MaxSize = 10000;
constexpr auto M6118 = 20;
constexpr auto N6118 = 20;
constexpr auto M = 3;//Tree.h中树的度数;
constexpr auto Sort_MAXITEM = 20;//Sort.h中
#define random(x) (rand() % x);
typedef int KeyType;//Sort、Search、Tree用到
typedef char InfoType;//Tree中用到
typedef char Sort_ElemType[10];//Sort用到
typedef char SearchInfoType[10];//Search用到
// TODO: 添加要在此处预编译的标头

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "SqList.h"
#include "SqString.h"
#include "LinkList.h"
#include "DLinkList.h"
#include "CirculatingLinkList.h"
#include "CirculatingDLinkList.h"
#include "SqStack.h"
#include "LinkStack.h"
#include "SqQueue.h"
#include "LinkQueue.h"
#include "LinkString.h"
#include "Tree.h"
#include "BinaryTree.h"
#include "Lists.h"
#include "Graphs.h"
#include "Sort.h"

#endif //PCH_H