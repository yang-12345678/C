// 实验一

#include<stdio.h>	//若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>	//用malloc,free,realloc函数需包含该头文件
#include<conio.h>	//若用getch()使得屏幕暂停，需包含该头文件
#include<stdlib.h>

#define MAXSIZE 100		//设线性表初始分配空间大小
typedef int ElemType;	//先设定数据元素的类型为整型

//定义顺序表的结构类型
typedef struct {
	ElemType* elem;  // 数据元素的存储空间基址
	int length;  // 当前长度
	int listsize;  // 当前分配的存储空间大小

}SqList;

//初始化顺序表
int InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (L.elem == NULL)  return 0;
	L.length = 0;
	L.listsize = MAXSIZE;
	return 1;
}

//定位元素
int Location_Sq(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] = e)
			return i + 1;
	}
	return 0;
}

//插入
int ListInsert_Sq(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return 0;
	ElemType* newbase;
	ElemType* p;
	ElemType* q;  // q 指向插入位置
	if (i >= L.length) {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
		if (newbase == NULL)
			return 0;
		L.elem = newbase;  // 只改变了空间长度，length并没有改变
	}
	q = &(L.elem[i - 1]);
	for (p = q; p <= &L.elem[L.length - 1]; p++)
		*(p + 1) = *p;
	*q = e;
	L.length++;
}

//删除
int ListDelete_Sq(SqList& L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length))
		return 0;
	ElemType* p, * q;
	q = &L.elem[i - 1];  // 指向删除元素的位置
	e = *q;
	for (p = q; p < &L.elem[L.length]; p++)
	{
		*p = *(p + 1);
	}
	L.length--;
	return 1;
}

//翻转表
void ReverseList(SqList& L) {
	for (int i = 0; i < L.length / 2; i++)
	{
		ElemType j;
		j = L.elem[i];
		L.elem[i] = L.elem[L.length - 1 - i];
		L.elem[L.length - 1 - i] = j;
	}
}

//合并两个有序表
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

//打印表中元素值
void PrintList(SqList& L) {
	int i;
	for (i = 0; i < L.length; i++)
		printf("%d\n", L.elem[i]);
}

//主函数
void main()
{
	SqList La, Lb, Lc;
	int i, n, e;

	//创建第一个表
	printf("1. 建第一个表 \n");
	InitList_Sq(La);
	printf("请输入要往La表中插入元素的个数：");
	scanf_s("%d", &n);
	printf("输入%d个递增有序的整数：\n", n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &e);
		ListInsert_Sq(La, i, e);
	}
	printf("La表长为：%d\n", La.length);
	PrintList(La);
	//_getch();  //屏幕暂停，等候按任何键继续

	//删除
	printf("\n2.删除\n");
	printf("请输入要删除元素的位置：");
	scanf_s("%d", &i);
	ListDelete_Sq(La, i, e);
	printf("被删除的元素是：%d\n", e);
	printf("删除后La表：\n");
	PrintList(La);
	printf("La表表长为：%d\n", La.length);

	//创建第二个表
	printf("\n3.建第二个表\n");
	InitList_Sq(Lb);
	printf("请输入要往Lb表中插入元素的个数：");
	scanf_s("%d", &n);
	printf("输入%d个递增有序的整数：\n", n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &e);
		ListInsert_Sq(Lb, i, e);
	}
	printf("Lb表长为：%d\n", Lb.length);
	//_getch();

	//合并有序表
	printf("\n4. 合并有序表，将La,Lb表中元素合并到Lc表中，仍保持有序。\n");
	InitList_Sq(Lc);
	MergeList(La, Lb, Lc);
	printf("合并有序表后，Lc表元素为：\n");
	PrintList(Lc);
	printf("合并有序表后，Lc表表长为：%d", Lc.length);
	//_getch();

	//翻转表
	printf("\n5. 翻转Lc表\n");
	ReverseList(Lc);
	printf("翻转Lc表后，Lc表元素为：\n");
	PrintList(Lc);
	_getch();
}