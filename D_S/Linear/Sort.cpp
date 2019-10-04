#include "pch.h"
#include "Sort.h"

InSort_SqList* InitRandomSqList() {
	static InSort_SqList R[Sort_MAXITEM];//����static�Ļ�ֻ�᷵�ص�һ����ֵ
	for (int i = 0; i < Sort_MAXITEM; i++) {
		int j = random(100);
		R[i].key = j;
	}
	InSort_SqList *RR = R;
	return RR;
}

void DispInitKey(InSort_SqList *R) {
	for (int i = 0; i < Sort_MAXITEM; i++) {
		printf_s("%3d ", R[i].key);
	}
	printf_s("\n");
}

void Bubble_Sort(InSort_SqList *R, int length) {
	int flag, temp;//flag���ڼ�¼����ð���Ƿ���������,temp��ð�ݹ����з�����������ʱ�䵱�н��ɫ
	for (int i = 0; i < length - 1; i++) {
		flag = 0;//һ��������һ�ν���,����flag = 1;�����һ������δ��������,���������������ź���,���flagδ��Ϊ1,forѭ��������,�ж�flagΪ0���˳�����,�������
		for (int j = 0; j < length - i - 1; j++) {//ÿһ��ʹ������Ԫ�������Ҷ�;
			if (R[j].key > R[j + 1].key) {
				flag = 1;
				temp = R[j].key;
				R[j].key = R[j + 1].key;
				R[j + 1].key = temp;
			}
		}
		if (flag == 0) return;
	}
	return;
}

void Quick_Sort(InSort_SqList * R, int s, int t) {
	//ð�ݺͿ��Ŷ��ǻ��ڽ�����˼��.����ÿһ�����������ʹ��һ��Ԫ��λ��������λ��,���������λ�õĲ�ͬ���½�������Ҫ���������(����������Ԫ�����Ԫ��)�Ĺ�ģ�����ı�,ʹ�ÿ��ź�ð�ݵĸ��Ӷ��нϴ�Ĳ��
	//ð����ÿ�������ڵ�Ԫ�ؽ��������Ƚ�����ÿһ��ð��ʹ��һ��Ԫ��λ��������λ��.��������临�Ӷ�,ÿһ��ð�ݵ������Ƚϴ�����Ϊ����Ԫ�ظ�����һ,
	//	��ÿһ��ð�ݽ�������һ����ð�ݵ����еĹ�ģ��Ϊ��ǰ��ģ��һ�����ǿ��ŸĽ����ص�,Ҳ�Ƿֶ���֮�зֵķ�ʽ��ͬ��������ʱ�临�Ӷȵķ����Ըı䡿
	//����ʵ������ѡȡ��ĳһ��ŦԪ��(lomotoȡ��һ��Ԫ��Ϊ��ŦԪ��)�ʹӾ�������Զ��Ԫ�ؿ�ʼ�����ȽϽ���,
	//	���ʹ��ֻ�е���������ʱ,�Ż���������Ƚϴ���Ϊ����Ԫ�ظ�����һ�����(����ð��һ����),������������Ƚϴ�������������Ԫ�ظ�����һ��ע������뷨�ƺ�����,ÿһ�˿��ŵ������Ƚϴ�����Ϊ���й�ģ��һ��
	//	���Ǵ�ʱʵ���������Ԫ�ذ����зֳ������������������,�����������еĹ�ģ��С�����й�ģ��һ(�������,��������������������,��ʱֻ��һ��������,��������й�ģ��Ϊ���й�ģ��һ)
	//	�����������й�ģ������ÿ�μ�һ���ٶȼ���,��ʹ�ý������������е������Ƚϴ���������,���������������о�����ð�����Ƚ�,�����Ƚϴ����Ӻ�ҲԶ�ȴ����й�ģ��һ����ÿ�μ�һ,һֱ�ӵ�1Ϊֹ�ĺ�ҪС
	//		(���9������������,����ð����Ҫ8+7+6+5+������+1 = 36�αȽ�;�����ڿ���,ֻҪ��������������ļ������,����һ�ο���(�Ƚϴ���Ϊ8)ʹ�������Ԫ���ǵ�5��Ԫ��,�����ǽ����������������ж���ð��,Ҳֻ��2*(3+2+1)=12��,�ܹ�20�αȽ�,����36�αȽ�)
	//	���,���ź�ð�ݵĸ��ӶȲ�������������,��ÿ�������������һ��������Ҫ����������й�ģ,�����ģ�ļ���,�����ɱ����������㷨��ʱ�临�Ӷȡ���������ƽ�һ��,����һ������ѧ�ϵıȽϡ�
	//	���ž��ǳ�������˷ֶ���֮�еķ�,ʹ�÷ֺ�����й�ģ�����Լ���,Ȼ���εĸ��ӶȾͲ����Լ�����
	//
	//���յõ�ð�������ʱ�临�Ӷ�Ϊ:
	//T_best(n) = n;(Ԫ��������,��Ƚϴ���Ϊn-1��)
	//T_worst(n) = n^2;
	//T_average(n) = n^2;
	//�ռ临�Ӷ�ΪS(n) = O(1),���䵱�н��ɫ��temp
	//���������ʱ�临�Ӷ�Ϊ:
	//T_best(n) = nlog2(n);
	//T_worst(n) = n^2;(Ԫ��������,��ÿ���ź����Ԫ��λ��Ϊ����ͷ,�ͺ�ð��һ����,��Ϊÿ�������������ֻ��һ���ҹ�ģΪ��ǰ���й�ģ��һ,û�з����Եļ���,���ʱ�临�ӶȲ�δ��ð���Ż�)
	//T_average(n) = nlog2(n);
	//�ռ临�Ӷ�S(n) = nlog2(n),��ݹ�Ĳ����й�,���ݹ�nlog2(n)�㡾�˴����ɻ�,δ����������顿
	if (s < t) {//�ݹ�߽�,ʹ�õݹ����ܹ��˳�����
		int i = s, j = t;//i��������ɨ,j��������ɨ
		InSort_SqList pivot = R[i];//��ŦԪ����Ϊ��ǰ�������еĵ�һ��Ԫ��
		while (i < j) {
			while (R[j].key > pivot.key && i < j) {//��Ϊû��ȡ�Ⱥ�,��˵���ŦԪ�غ͵�ǰɨ�赽��Ԫ��keyֵ��ͬʱ,�˳�ѭ��,��ʱi��j��ֵ����i<j,��˰�keyֵ��ͬ������Ԫ�ؽ�����,��˸��㷨���ȶ�
				j--;
			}
			if (i < j) {
				R[i] = R[j];
				i++;
			}//��ʱj���ұߵ�����Ԫ��keyֵ������pivot��keyֵ
			while (R[i].key < pivot.key && i < j) {
				i++;
			}
			if (i < j) {
				R[j] = R[i];
				j--;
			}//��ʱi����ߵ�����Ԫ��keyֵ��С��pivot��keyֵ
			R[i] = pivot;//��ʱi = j,ͬʱ��ʱi��ָ��Ԫ�ص�keyֵ�������������Ԫ�ص�keyֵ��С�����Ҳ�����Ԫ�ص�keyֵ,����pivot������λ��Ϊi,���ִ�д˲���ʹ��pivotԪ������������λ��
		}
		DispInitKey(R);
		Quick_Sort(R, s, i - 1);//�Դ�ʱ�����뺯����������е�pivot����λ�õ��������н��п�������,ʹ������е���Ԫ������������λ�ò�����Ԫ������λ�õ��������������еݹ����,ֱ��������s<t(�ݹ�߽�)
		Quick_Sort(R, i + 1, t);//�Դ�ʱ�����뺯����������е�pivot����λ�õ��������н��п�������,ʹ�ұ����е���Ԫ������������λ�ò�����Ԫ������λ�õ��������������еݹ����,ֱ��������s<t(�ݹ�߽�)
	}
	else {
		return;
	}
}

void Insert_Sort(InSort_SqList * R, int length) {
	//ֱ�Ӳ�������
	//����һ��������������,�������α��������е�ÿһ�����,�������з�Ϊǰ�벿�ֵ��������кͺ�벿�ֵ���������
	//�ɴ˹���,���Ǽٶ���һ��Ԫ��������,���i���±�Ϊ1��Ԫ�ؿ�ʼ����,һֱ�������±�Ϊlength - 1��Ԫ��,����ǰ��������(��Ҫ���뵽�������еĵ�ǰ����Ԫ��)���浽temp������
	//��j���α�����i���ڵ�ǰһ��Ԫ��(j=i-1)��ǰֱ���±�Ϊ0��Ԫ��,�����αȽϽ��Ϊi�ؼ��ֽ�С,��i�ڵ�ǰjԪ�ص�ǰ��,
	//	���jԪ����Ҫ����ƶ�һ��λ��,��R[j+1]=R[j],ͬʱj��ǰ�ƶ�һ��λ������һ��δ�Ƚ�Ԫ�ش�����ѭ���Ƚ�,
	//	ֱ����ǰjԪ�عؼ���ֵС��iԪ�عؼ���ֵ,��˵��iҪ�����λ��ΪjԪ�صĺ���(��ΪjԪ�����ڵ�������Ϊ��������,���jԪ��֮ǰ��Ԫ�عؼ���ֵ�ض�С�ڵ���jԪ�صĹؼ���ֵ)
	//	��ʱ�˳�ѭ��,��i���뵽jԪ�صĺ���,��R[j + 1] = temp,���ʾ���β����������,ʹ��ǰ�벿�ֵ��������й�ģ��һ,�������еĹ�ģ��һ,����forѭ��i�Լ�1����˳�α�����ǰ�������еĵ�һ��Ԫ��.
	//	ֱ��i������ȫ����������,�㷨����,��ǰ����Ϊȫ����������
	InSort_SqList temp;
	for (int i = 1; i < length; i++) {
		temp = R[i];
		int j = i - 1;
		while (j >= 0 && temp.key < R[j].key) {
			R[j + 1] = R[j];
			j--;
		}
		R[j + 1] = temp;
	}
}

void Shell_Sort(InSort_SqList * R, int length) {
	//ϣ������
	int gap = length / 2;
	InSort_SqList temp;
	while (gap > 0) {
		//while����ĳ������ֱ�Ӳ�������ĳ���κ�˼�����һ��,������ϣ����������ǰ�Ƚ�ʱ,����һ��һ����ǰ�Ƚ�,���Ǹ�gap��Ԫ�رȽ�һ��,���jÿ�β��Ǽ�1,���Ǽ�gap.
		//���Կ���,��gapΪ1ʱ,ϣ��������ð��ȫ������һ��.
		//	gap������,�൱�ڰ��������зֳ�gap��������,��ÿ�������н���ֱ�Ӳ�������.��i��gap��ʼ������,��֤ÿ�������ж��ᱻֱ������.
		for (int i = gap; i < length; i++) {
			temp = R[i];
			int j = i - gap;
			while (j >= 0 && temp.key < R[j].key) {
				R[j + gap] = R[j];
				j = j - gap;
			}
			R[j + gap] = temp;
		}
		gap = gap / 2;
	}
}