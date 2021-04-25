//#include <iostream>
//#include <malloc.h>
//using namespace std;
//
//#define MAXSIZE 100  // 设线性表初始分配空间大小
//
//typedef int ElemType;  // 先设定数据元素类型为整型
//
//// 定义顺序表的结构类型
//typedef struct {
//	ElemType* elem;  // 数据元素的存储空间基址
//	int length;  // 当前长度
//	int listsize;  // 当前分配的存储空间大小
//}SqList;
//
//// 初始化线性表
//int InitList_Sq(SqList& L) {
//	L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	if (!L.elem) return 0;
//	L.length = 0;
//	L.listsize = MAXSIZE;
//	return 1;
//}
//
//// 定位元素
//int Location_Sq(SqList L, ElemType e) {
//	for (int i = 0; i < L.length; i++) {
//		if (L.elem[i] == e)
//			return i + 1;
//	}
//	return 0;  // 没找到
//}
//
//// 插入
//int ListInsert_Sq(SqList& L, int i, ElemType e) {
//	if (i<1 || i>L.length + 1)  // 以长度5为例，不能插入第0个位置和第7个位置
//		return 0;
//
//	ElemType* newbase;
//	ElemType* p;
//	ElemType* q;  // 指向插入位置
//
//	if (L.length >= L.listsize)  // 表已满
//	{
//		newbase = (ElemType*)realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
//		if (!newbase)
//			return 0;
//		L.elem = newbase;  // 其实也可以不用声明newbase,直接用L.elem
//		L.listsize = L.listsize + 10;
//	}
//
//	q = &(L.elem[i - 1]);  // q指向插入位置
//	for (p = &(L.elem[L.length - 1]); p >= q; p--)
//		*(p + 1) = *p;
//	*q = e;
//	L.length++;  
//	
//	// 相同的效果
//	/*for (int j = L.elem[L.length - 1]; j >= i - 1; j--) {
//		L.elem[j + 1] = L.elem[j];
//	}
//	L.elem[i - 1] = e;
//	L.length++;*/
//
//	return 1;
//}
//
//// 删除
//int ListDelete_Sq(SqList& L, int i, ElemType& e) {
//	if (i<1 || i>L.length)
//		return 0;
//	ElemType* p, * q;
//	// p 是必要的，因为如果e直接引用要删除的元素，那么元素前移后，e引用的值将不是原来删除的值
//	p = &(L.elem[i - 1]);
//	e = *p;
//	q = L.elem + L.length - 1;  // q 可以省略，声明q代码清晰
//	for (p;p<=q;p++)
//	{
//		*(p) = *(p + 1);
//	}
//	L.length--;
//	return 1;
//}
//
//// 翻转表
//int ReverseList(SqList& L)
//{
//	int n = L.length / 2;
//	ElemType temp;
//	for (int i = 0; i <= n; i++) {
//		temp = L.elem[i];
//		L.elem[i] = L.elem[L.length - i - 1];
//		L.elem[L.length - i - 1] = temp;
//	}
//	return 0;
//}
//
//// 合并两个有序表
//int MergeList(SqList La, SqList Lb, SqList& Lc) {
//	int i = 0,j = 0, k = 0;
//	if (La.length + Lb.length > Lc.listsize) {
//		Lc.elem = (ElemType*)realloc(Lc.elem, (La.length + Lb.length) * sizeof(ElemType));
//	} 
//	while ((i < La.length) && (j < Lb.length)) {
//		if (La.elem[i] <= Lb.elem[j])
//			Lc.elem[k++] = La.elem[i++];
//		else
//			Lc.elem[k++] = Lb.elem[j++];
//	}
//	while (i < La.length)
//		Lc.elem[k++] = La.elem[i++];	//插入La中剩余元素
//	while (j < Lb.length)
//		Lc.elem[k++] = Lb.elem[j++];	//插入Lb中剩余元素
//	Lc.length = k;
//	return 1;
//}
//
////打印表中元素值
//void PrintList(SqList& L) {
//	int i;
//	for (i = 0; i < L.length; i++)
//		cout << L.elem[i] << endl;
//}
//
//int main()
//{
//	SqList La, Lb, Lc;
//	int i, n, e;
//
//	//创建第一个表
//	printf("1. 建第一个表 \n");
//	InitList_Sq(La);
//	printf("请输入要往La表中插入元素的个数：");
//	cin >> n;
//	printf("输入%d个递增有序的整数：\n", n);
//	for (i = 1; i <= n; i++) {
//		cin >> e;
//		ListInsert_Sq(La, i, e);
//	}
//	printf("La表长为：%d\n", La.length);
//	PrintList(La);
//
//	//删除
//	printf("\n2.删除\n");
//	printf("请输入要删除元素的位置：");
//	cin >> i;
//	ListDelete_Sq(La, i, e);
//	printf("被删除的元素是：%d\n", e);
//	printf("删除后La表：\n");
//	PrintList(La);
//	printf("La表表长为：%d\n", La.length);
//
//	//创建第二个表
//	printf("\n3.建第二个表\n");
//	InitList_Sq(Lb);
//	printf("请输入要往Lb表中插入元素的个数：");
//	cin >> n;
//	printf("输入%d个递增有序的整数：\n", n);
//	for (i = 1; i <= n; i++) {
//		cin >> e;
//		ListInsert_Sq(Lb, i, e);
//	}
//	printf("Lb表长为：%d\n", Lb.length);
//
//	//合并有序表
//	printf("\n4. 合并有序表，将La,Lb表中元素合并到Lc表中，仍保持有序。\n");
//	InitList_Sq(Lc);
//	MergeList(La, Lb, Lc);
//	printf("合并有序表后，Lc表元素为：\n");
//	PrintList(Lc);
//	printf("合并有序表后，Lc表表长为：%d", Lc.length);
//
//	//翻转表
//	printf("\n5. 翻转Lc表\n");
//	ReverseList(Lc);
//	printf("翻转Lc表后，Lc表元素为：\n");
//	PrintList(Lc);
//}