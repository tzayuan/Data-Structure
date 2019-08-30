#include "pch.h"
#include "SqStack.h"

void InitStack(SqStack & st) {
	st.top = -1;
}

int StackEmpty(SqStack st) {
	if (st.top == -1) return 1;
	else return 0;
	//return st.top == -1;//答案的写法,更为精简
}

int PushStack(SqStack & st, int x) {
	if (st.top == MaxSize - 1) return 0;
	st.top++;
	st.data[st.top] = x;
	return 1;
}

int PopStack(SqStack & st, int & x) {
	if (st.top == -1) return 0;
	x = st.data[st.top];
	st.top--;
	return 1;
}

void trans(char exp[], char postexp[]) {
	//假设算术表达式只包含"+"、"-"、"*"、"/"、正整数和括号的合法数学表达式.求算术表达式值的过程是:先将算术表达式(中缀表达式)转换成后缀表达式(亦称逆波兰表达式),然后对该后缀表达式求值.
	//trans()函数实现中缀表达式转换成后缀表达式
	//算法思路: char类型的ch变量用以接收遍历中缀表达式exp[]传来的每一个字符,i下标用以记录exp[]的下标位置,j用以记录postexp的下标位置,opStack栈作为运算符栈
	//	依次从exp[]中读取字符记录到ch,直至ch == '\0'则所有字符均已从exp[]取出,即exp[]扫描完毕.将取出的每一个字符ch进行判断:
	//		若ch为"(":将ch压入opStack;
	//		若ch为")":循环访问opStack的栈顶元素(此时从逻辑判断,前面必定有一个'('存在,则不需要判空),只要栈顶元素不为'(',则将栈顶元素依次出栈并添加至postexp[],退出循环后将"("出栈;
	//		若ch为运算符"+"、"-"、"*"、"/",则将opStack栈中从栈顶字符开始运算符优先级大于等于ch的运算符优先级的字符(栈顶运算符为'('除外)依次出栈并添加至postexp[],然后将ch进栈;具体规则如下:
	//			若ch为"+"或"-":循环访问opStack的栈顶元素,只要栈不为空(即opStack.top != -1)且栈顶元素不为'(',则将opStack中栈顶元素依次出栈并添加至opstexp[],退出循环后将ch压入opStack;
	//			若ch为"*"或"/":循环访问opStack的栈顶元素,只要栈不为空且栈顶元素不为"("且栈顶元素为"*"或"/",则将opStack中栈顶元素依次出栈并添加至postexp[]中,退出循环后将ch压入opStack栈;
	//			(显然若栈顶元素为"*"或"/"时栈肯定不为空且栈顶元素不为"(";栈不为空且栈顶元素不为"("是为了能够退出循环,而"*"和"/"是为了将opStack中栈顶元素运算优先级大于等于(在该题只可能是等于,即"*"或者"/")ch运算优先级的运算符出栈并添加至postexp[])
	//		若ch为" ":干扰字符,不进行任何操作,退出当前的switch,将exp下一个字符赋值给ch;
	//		若ch为"0"~'9',即不为上述任何情况之一(根据逻辑推论下此时的ch为数字0~9):将ch添加至postexp[]中,然后在此case中,继续遍历exp的后续元素并赋值给ch,只要ch为数字,则将ch添加至postexp[],直至ch不为数字,此时需要注意i下标需要-1,才是第一个非数字元素的位置,然后将'#'添加至postexp[]中;
	//	exp[]扫描完毕后,检查opStack中是否有剩余元素,若有,则依次添加至opstexp[]中,直至opStack为空,此时最终得到postexp[]即为给定算术表达式(中缀表达式)所对应的后缀表达式.
	char ch;
	int i = 0, j = 0;//i作为exp的下标,j作为postexp的下标
	op opStack;
	opStack.top = -1;
	ch = exp[i++];
	while (ch != '\0') {
		switch (ch) {
		case '(':
			opStack.top++;
			opStack.data[opStack.top] = ch;
			break;
		case ')':
			while (opStack.data[opStack.top] != '(') {
				postexp[j++] = opStack.data[opStack.top--];
			}
			opStack.top--;
			break;
		case '+':
		case '-':
			while (opStack.top != -1 && opStack.data[opStack.top] != '(') {
				postexp[j++] = opStack.data[opStack.top--];
			}
			opStack.top++;
			opStack.data[opStack.top] = ch;
			break;
		case '*':
		case '/':
			while (opStack.top != -1 && opStack.data[opStack.top] != '(' && (opStack.data[opStack.top] == '*' || opStack.data[opStack.top] == '/')) {
				postexp[j++] = opStack.data[opStack.top--];
			}
			opStack.top++;
			opStack.data[opStack.top] = ch;
			break;
		case ' ':
			break;
		default:
			while (ch >= '0' && ch <= '9') {
				postexp[j++] = ch;
				ch = exp[i++];
			}
			i--;
			postexp[j++] = '#';
			break;
		}
		ch = exp[i++];
	}
	while (opStack.top != -1) {
		postexp[j++] = opStack.data[opStack.top--];
	}
	postexp[j] = '\0';
}

float computeValue(char postexp[]) {
	//假设算术表达式只包含"+"、"-"、"*"、"/"、正整数和括号的合法数学表达式.求算术表达式值的过程是:先将算术表达式(中缀表达式)转换成后缀表达式(亦称逆波兰表达式),然后对该后缀表达式求值.
	//computeValue()用以计算后缀表达式的值.
	//算法思路: numStack栈作为数值栈,用以存放后缀表达式中的一个数值整体或计算所得到的数值,ch用以接收遍历postexp[]中的每一个字符,i用以表示postexp的下标以作遍历时用,num用以计算postexp[]中一个整数整体的值
	//	依次用i下标从postexp[]中读取字符并赋值到ch中,直至postexp[]扫描完毕,每读取到一个字符的操作如下:
	//		若ch为"+"、"-"、"*"、"/":从numStack中弹出两个元素进行相应的运算,并将结果保存至numStack;特殊的,"/"需要考虑栈顶元素(即被除数)不为0(若为0则报错);
	//		若ch为数值,则依次从postexp中读取字符,直至字符不为数字,此时通过num暂时存放取出的数字(每次num要归零),每连续取出一个,则使得num*10+ch-'0',然后将最终的num数值压入numStack栈.
	//	postexp[]扫描完毕后,numStack栈顶元素即为最终结果,算法结束.
	st numStack;
	numStack.top = -1;
	char ch;
	int i = 0;
	float num;
	ch = postexp[i++];
	while (ch != '\0') {
		switch (ch) {
			case '+':
				numStack.data[numStack.top - 1] = numStack.data[numStack.top - 1] + numStack.data[numStack.top];
				numStack.top--;
				break;
			case '-':
				numStack.data[numStack.top - 1] = numStack.data[numStack.top - 1] - numStack.data[numStack.top];
				numStack.top--;
				break;
			case '*':
				numStack.data[numStack.top - 1] = numStack.data[numStack.top - 1] * numStack.data[numStack.top];
				numStack.top--;
				break;
			case '/':
				if (numStack.data[numStack.top] != 0) {
					numStack.data[numStack.top - 1] = numStack.data[numStack.top - 1] / numStack.data[numStack.top];
					numStack.top--;
					break;
				}
				else {
					printf_s("Can not divide zero!\n");//cstdio
					exit(0);//cstdlib
				}
			default:
				num = 0;
				while (ch >= '0' && ch <= '9') {
					num = num * 10 + ch - '0';
					ch = postexp[i++];
				}//while结束后由于i++,刚好把#跳过了,此时postexp[i]中的元素为#的后一个元素;
				numStack.top++;
				numStack.data[numStack.top] = num;
				break;
		}
		ch = postexp[i++];
	}
	return numStack.data[numStack.top];
}

void mazePath(int x1, int y1, int x2, int y2) {
	struct {
		int i;
		int j;
		int di;
	} St[MaxSize];
	int top = -1;
	int i, j, di, find;
	top++;//初始方块进栈
	St[top].i = x1;
	St[top].j = y1;
	St[top].di = -1;
	maze[x1][y1] = -1;
	while (top != -1) {//栈不空时循环
		i = St[top].i;
		j = St[top].j;
		di = St[top].di;
		if (i == x2 && j == y2) {//找到了出口,输出路径
			printf_s("The distance of the maze is :\n");
			for (int k = 0; k <= top; k++) {
				printf_s("\t(%d, %d)", St[k].i, St[k].j);
				if ((k + 1) % 5 == 0) printf_s("\n");//每输出5个方块后换一行
			}
			printf_s("\n");
			return;
		}
		find = 0;
		while (di < 4 && find == 0) {//找下一个可走方块
			di++;
			switch (di) {
				case 0:
					i = St[top].i - 1;
					j = St[top].j;
					break;
				case 1:
					i = St[top].i;
					j = St[top].j + 1;
					break;
				case 2:
					i = St[top].i + 1;
					j = St[top].j;
					break;
				case 3:
					i = St[top].i;
					j = St[top].j - 1;
					break;
					/*
				default:
					printf_s("Running error!\n");
					exit(0);
					*/
			}
			if (maze[i][j] == 0) find = 1;
		}
		if (find == 1) {//找到了下一个可走方块
			St[top].di = di;//修改原栈顶元素的di值
			top++;//下一个可走方块进栈
			St[top].i = i;
			St[top].j = j;
			St[top].di = -1;
			maze[i][j] = -1;//避免重复走到该方块
		}
		else {//没有路径可走,则退栈
			maze[St[top].i][St[top].j] = 0;//让该位置变为其他路径可走方块
			top--;
		}
	}
	printf_s("There is no path!\n");
}