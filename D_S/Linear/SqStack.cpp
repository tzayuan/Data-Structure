#include "pch.h"
#include "SqStack.h"

void InitStack(SqStack & st) {
	st.top = -1;
}

int StackEmpty(SqStack st) {
	if (st.top == -1) return 1;
	else return 0;
	//return st.top == -1;//�𰸵�д��,��Ϊ����
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
	//�����������ʽֻ����"+"��"-"��"*"��"/"�������������ŵĺϷ���ѧ���ʽ.���������ʽֵ�Ĺ�����:�Ƚ��������ʽ(��׺���ʽ)ת���ɺ�׺���ʽ(����沨�����ʽ),Ȼ��Ըú�׺���ʽ��ֵ.
	//trans()����ʵ����׺���ʽת���ɺ�׺���ʽ
	//�㷨˼·: char���͵�ch�������Խ��ձ�����׺���ʽexp[]������ÿһ���ַ�,i�±����Լ�¼exp[]���±�λ��,j���Լ�¼postexp���±�λ��,opStackջ��Ϊ�����ջ
	//	���δ�exp[]�ж�ȡ�ַ���¼��ch,ֱ��ch == '\0'�������ַ����Ѵ�exp[]ȡ��,��exp[]ɨ�����.��ȡ����ÿһ���ַ�ch�����ж�:
	//		��chΪ"(":��chѹ��opStack;
	//		��chΪ")":ѭ������opStack��ջ��Ԫ��(��ʱ���߼��ж�,ǰ��ض���һ��'('����,����Ҫ�п�),ֻҪջ��Ԫ�ز�Ϊ'(',��ջ��Ԫ�����γ�ջ�������postexp[],�˳�ѭ����"("��ջ;
	//		��chΪ�����"+"��"-"��"*"��"/",��opStackջ�д�ջ���ַ���ʼ��������ȼ����ڵ���ch����������ȼ����ַ�(ջ�������Ϊ'('����)���γ�ջ�������postexp[],Ȼ��ch��ջ;�����������:
	//			��chΪ"+"��"-":ѭ������opStack��ջ��Ԫ��,ֻҪջ��Ϊ��(��opStack.top != -1)��ջ��Ԫ�ز�Ϊ'(',��opStack��ջ��Ԫ�����γ�ջ�������opstexp[],�˳�ѭ����chѹ��opStack;
	//			��chΪ"*"��"/":ѭ������opStack��ջ��Ԫ��,ֻҪջ��Ϊ����ջ��Ԫ�ز�Ϊ"("��ջ��Ԫ��Ϊ"*"��"/",��opStack��ջ��Ԫ�����γ�ջ�������postexp[]��,�˳�ѭ����chѹ��opStackջ;
	//			(��Ȼ��ջ��Ԫ��Ϊ"*"��"/"ʱջ�϶���Ϊ����ջ��Ԫ�ز�Ϊ"(";ջ��Ϊ����ջ��Ԫ�ز�Ϊ"("��Ϊ���ܹ��˳�ѭ��,��"*"��"/"��Ϊ�˽�opStack��ջ��Ԫ���������ȼ����ڵ���(�ڸ���ֻ�����ǵ���,��"*"����"/")ch�������ȼ����������ջ�������postexp[])
	//		��chΪ" ":�����ַ�,�������κβ���,�˳���ǰ��switch,��exp��һ���ַ���ֵ��ch;
	//		��chΪ"0"~'9',����Ϊ�����κ����֮һ(�����߼������´�ʱ��chΪ����0~9):��ch�����postexp[]��,Ȼ���ڴ�case��,��������exp�ĺ���Ԫ�ز���ֵ��ch,ֻҪchΪ����,��ch�����postexp[],ֱ��ch��Ϊ����,��ʱ��Ҫע��i�±���Ҫ-1,���ǵ�һ��������Ԫ�ص�λ��,Ȼ��'#'�����postexp[]��;
	//	exp[]ɨ����Ϻ�,���opStack���Ƿ���ʣ��Ԫ��,����,�����������opstexp[]��,ֱ��opStackΪ��,��ʱ���յõ�postexp[]��Ϊ�����������ʽ(��׺���ʽ)����Ӧ�ĺ�׺���ʽ.
	char ch;
	int i = 0, j = 0;//i��Ϊexp���±�,j��Ϊpostexp���±�
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
	//�����������ʽֻ����"+"��"-"��"*"��"/"�������������ŵĺϷ���ѧ���ʽ.���������ʽֵ�Ĺ�����:�Ƚ��������ʽ(��׺���ʽ)ת���ɺ�׺���ʽ(����沨�����ʽ),Ȼ��Ըú�׺���ʽ��ֵ.
	//computeValue()���Լ����׺���ʽ��ֵ.
	//�㷨˼·: numStackջ��Ϊ��ֵջ,���Դ�ź�׺���ʽ�е�һ����ֵ�����������õ�����ֵ,ch���Խ��ձ���postexp[]�е�ÿһ���ַ�,i���Ա�ʾpostexp���±���������ʱ��,num���Լ���postexp[]��һ�����������ֵ
	//	������i�±��postexp[]�ж�ȡ�ַ�����ֵ��ch��,ֱ��postexp[]ɨ�����,ÿ��ȡ��һ���ַ��Ĳ�������:
	//		��chΪ"+"��"-"��"*"��"/":��numStack�е�������Ԫ�ؽ�����Ӧ������,�������������numStack;�����,"/"��Ҫ����ջ��Ԫ��(��������)��Ϊ0(��Ϊ0�򱨴�);
	//		��chΪ��ֵ,�����δ�postexp�ж�ȡ�ַ�,ֱ���ַ���Ϊ����,��ʱͨ��num��ʱ���ȡ��������(ÿ��numҪ����),ÿ����ȡ��һ��,��ʹ��num*10+ch-'0',Ȼ�����յ�num��ֵѹ��numStackջ.
	//	postexp[]ɨ����Ϻ�,numStackջ��Ԫ�ؼ�Ϊ���ս��,�㷨����.
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
				}//while����������i++,�պð�#������,��ʱpostexp[i]�е�Ԫ��Ϊ#�ĺ�һ��Ԫ��;
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
	top++;//��ʼ�����ջ
	St[top].i = x1;
	St[top].j = y1;
	St[top].di = -1;
	maze[x1][y1] = -1;
	while (top != -1) {//ջ����ʱѭ��
		i = St[top].i;
		j = St[top].j;
		di = St[top].di;
		if (i == x2 && j == y2) {//�ҵ��˳���,���·��
			printf_s("The distance of the maze is :\n");
			for (int k = 0; k <= top; k++) {
				printf_s("\t(%d, %d)", St[k].i, St[k].j);
				if ((k + 1) % 5 == 0) printf_s("\n");//ÿ���5�������һ��
			}
			printf_s("\n");
			return;
		}
		find = 0;
		while (di < 4 && find == 0) {//����һ�����߷���
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
		if (find == 1) {//�ҵ�����һ�����߷���
			St[top].di = di;//�޸�ԭջ��Ԫ�ص�diֵ
			top++;//��һ�����߷����ջ
			St[top].i = i;
			St[top].j = j;
			St[top].di = -1;
			maze[i][j] = -1;//�����ظ��ߵ��÷���
		}
		else {//û��·������,����ջ
			maze[St[top].i][St[top].j] = 0;//�ø�λ�ñ�Ϊ����·�����߷���
			top--;
		}
	}
	printf_s("There is no path!\n");
}