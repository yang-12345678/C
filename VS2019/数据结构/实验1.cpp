// ʵ��һ

#include<stdio.h>	//����printf,scanf,getchar,putchar,gets,puts�����������ͷ�ļ�
#include<malloc.h>	//��malloc,free,realloc�����������ͷ�ļ�
#include<conio.h>	//����getch()ʹ����Ļ��ͣ���������ͷ�ļ�
#include<stdlib.h>

#define MAXSIZE 100		//�����Ա��ʼ����ռ��С
typedef int ElemType;	//���趨����Ԫ�ص�����Ϊ����

//����˳���Ľṹ����
typedef struct {
	ElemType* elem;  // ����Ԫ�صĴ洢�ռ��ַ
	int length;  // ��ǰ����
	int listsize;  // ��ǰ����Ĵ洢�ռ��С

}SqList;

//��ʼ��˳���
int InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (L.elem == NULL)  return 0;
	L.length = 0;
	L.listsize = MAXSIZE;
	return 1;
}

//��λԪ��
int Location_Sq(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] = e)
			return i + 1;
	}
	return 0;
}

//����
int ListInsert_Sq(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return 0;
	ElemType* newbase;
	ElemType* p;
	ElemType* q;  // q ָ�����λ��
	if (i >= L.length) {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
		if (newbase == NULL)
			return 0;
		L.elem = newbase;  // ֻ�ı��˿ռ䳤�ȣ�length��û�иı�
	}
	q = &(L.elem[i - 1]);
	for (p = q; p <= &L.elem[L.length - 1]; p++)
		*(p + 1) = *p;
	*q = e;
	L.length++;
}

//ɾ��
int ListDelete_Sq(SqList& L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length))
		return 0;
	ElemType* p, * q;
	q = &L.elem[i - 1];  // ָ��ɾ��Ԫ�ص�λ��
	e = *q;
	for (p = q; p < &L.elem[L.length]; p++)
	{
		*p = *(p + 1);
	}
	L.length--;
	return 1;
}

//��ת��
void ReverseList(SqList& L) {
	for (int i = 0; i < L.length / 2; i++)
	{
		ElemType j;
		j = L.elem[i];
		L.elem[i] = L.elem[L.length - 1 - i];
		L.elem[L.length - 1 - i] = j;
	}
}

//�ϲ����������
void MergeList(SqList La, SqList Lb, SqList& Lc) {
	if (La.length + Lb.length > Lc.listsize)
	{
		Lc.elem = (ElemType*)realloc(Lc.elem, (La.length + Lb.length) * sizeof(ElemType));
		if (Lc.elem == NULL)
			exit(-1);
	}
	int i = 0, j = 0, k = 0;
	while ((i < La.length) && (j < Lb.length))
	{
		if (La.elem[i] <= Lb.elem[j])
		{
			Lc.elem[k] = La.elem[i];
			k++; i++;
			// Lc.elem[k++] = La.elem[i++]
		}
		else
		{
			Lc.elem[k] = Lb.elem[j];
			k++; j++;
		}
	}
	while (i < La.length)
	{
		for (; i < La.length; i++)
			Lc.elem[k++] = La.elem[i++];
	}
	while (j < Lb.length)
	{
		for (j; j < Lb.length; j++)
			Lc.elem[k++] = Lb.elem[j++];
	}
	Lc.length = k;

}

//��ӡ����Ԫ��ֵ
void PrintList(SqList& L) {
	int i;
	for (i = 0; i < L.length; i++)
		printf("%d\n", L.elem[i]);
}

//������
void main()
{
	SqList La, Lb, Lc;
	int i, n, e;

	//������һ����
	printf("1. ����һ���� \n");
	InitList_Sq(La);
	printf("������Ҫ��La���в���Ԫ�صĸ�����");
	scanf_s("%d", &n);
	printf("����%d�����������������\n", n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &e);
		ListInsert_Sq(La, i, e);
	}
	printf("La��Ϊ��%d\n", La.length);
	PrintList(La);
	//_getch();  //��Ļ��ͣ���Ⱥ��κμ�����

	//ɾ��
	printf("\n2.ɾ��\n");
	printf("������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf_s("%d", &i);
	ListDelete_Sq(La, i, e);
	printf("��ɾ����Ԫ���ǣ�%d\n", e);
	printf("ɾ����La��\n");
	PrintList(La);
	printf("La���Ϊ��%d\n", La.length);

	//�����ڶ�����
	printf("\n3.���ڶ�����\n");
	InitList_Sq(Lb);
	printf("������Ҫ��Lb���в���Ԫ�صĸ�����");
	scanf_s("%d", &n);
	printf("����%d�����������������\n", n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &e);
		ListInsert_Sq(Lb, i, e);
	}
	printf("Lb��Ϊ��%d\n", Lb.length);
	//_getch();

	//�ϲ������
	printf("\n4. �ϲ��������La,Lb����Ԫ�غϲ���Lc���У��Ա�������\n");
	InitList_Sq(Lc);
	MergeList(La, Lb, Lc);
	printf("�ϲ�������Lc��Ԫ��Ϊ��\n");
	PrintList(Lc);
	printf("�ϲ�������Lc���Ϊ��%d", Lc.length);
	//_getch();

	//��ת��
	printf("\n5. ��תLc��\n");
	ReverseList(Lc);
	printf("��תLc���Lc��Ԫ��Ϊ��\n");
	PrintList(Lc);
	_getch();
}