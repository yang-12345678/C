//#include <iostream>
//#include <malloc.h>
//using namespace std;
//
//#define MAXSIZE 100  // �����Ա��ʼ����ռ��С
//
//typedef int ElemType;  // ���趨����Ԫ������Ϊ����
//
//// ����˳���Ľṹ����
//typedef struct {
//	ElemType* elem;  // ����Ԫ�صĴ洢�ռ��ַ
//	int length;  // ��ǰ����
//	int listsize;  // ��ǰ����Ĵ洢�ռ��С
//}SqList;
//
//// ��ʼ�����Ա�
//int InitList_Sq(SqList& L) {
//	L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	if (!L.elem) return 0;
//	L.length = 0;
//	L.listsize = MAXSIZE;
//	return 1;
//}
//
//// ��λԪ��
//int Location_Sq(SqList L, ElemType e) {
//	for (int i = 0; i < L.length; i++) {
//		if (L.elem[i] == e)
//			return i + 1;
//	}
//	return 0;  // û�ҵ�
//}
//
//// ����
//int ListInsert_Sq(SqList& L, int i, ElemType e) {
//	if (i<1 || i>L.length + 1)  // �Գ���5Ϊ�������ܲ����0��λ�ú͵�7��λ��
//		return 0;
//
//	ElemType* newbase;
//	ElemType* p;
//	ElemType* q;  // ָ�����λ��
//
//	if (L.length >= L.listsize)  // ������
//	{
//		newbase = (ElemType*)realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
//		if (!newbase)
//			return 0;
//		L.elem = newbase;  // ��ʵҲ���Բ�������newbase,ֱ����L.elem
//		L.listsize = L.listsize + 10;
//	}
//
//	q = &(L.elem[i - 1]);  // qָ�����λ��
//	for (p = &(L.elem[L.length - 1]); p >= q; p--)
//		*(p + 1) = *p;
//	*q = e;
//	L.length++;  
//	
//	// ��ͬ��Ч��
//	/*for (int j = L.elem[L.length - 1]; j >= i - 1; j--) {
//		L.elem[j + 1] = L.elem[j];
//	}
//	L.elem[i - 1] = e;
//	L.length++;*/
//
//	return 1;
//}
//
//// ɾ��
//int ListDelete_Sq(SqList& L, int i, ElemType& e) {
//	if (i<1 || i>L.length)
//		return 0;
//	ElemType* p, * q;
//	// p �Ǳ�Ҫ�ģ���Ϊ���eֱ������Ҫɾ����Ԫ�أ���ôԪ��ǰ�ƺ�e���õ�ֵ������ԭ��ɾ����ֵ
//	p = &(L.elem[i - 1]);
//	e = *p;
//	q = L.elem + L.length - 1;  // q ����ʡ�ԣ�����q��������
//	for (p;p<=q;p++)
//	{
//		*(p) = *(p + 1);
//	}
//	L.length--;
//	return 1;
//}
//
//// ��ת��
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
//// �ϲ����������
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
//		Lc.elem[k++] = La.elem[i++];	//����La��ʣ��Ԫ��
//	while (j < Lb.length)
//		Lc.elem[k++] = Lb.elem[j++];	//����Lb��ʣ��Ԫ��
//	Lc.length = k;
//	return 1;
//}
//
////��ӡ����Ԫ��ֵ
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
//	//������һ����
//	printf("1. ����һ���� \n");
//	InitList_Sq(La);
//	printf("������Ҫ��La���в���Ԫ�صĸ�����");
//	cin >> n;
//	printf("����%d�����������������\n", n);
//	for (i = 1; i <= n; i++) {
//		cin >> e;
//		ListInsert_Sq(La, i, e);
//	}
//	printf("La��Ϊ��%d\n", La.length);
//	PrintList(La);
//
//	//ɾ��
//	printf("\n2.ɾ��\n");
//	printf("������Ҫɾ��Ԫ�ص�λ�ã�");
//	cin >> i;
//	ListDelete_Sq(La, i, e);
//	printf("��ɾ����Ԫ���ǣ�%d\n", e);
//	printf("ɾ����La��\n");
//	PrintList(La);
//	printf("La���Ϊ��%d\n", La.length);
//
//	//�����ڶ�����
//	printf("\n3.���ڶ�����\n");
//	InitList_Sq(Lb);
//	printf("������Ҫ��Lb���в���Ԫ�صĸ�����");
//	cin >> n;
//	printf("����%d�����������������\n", n);
//	for (i = 1; i <= n; i++) {
//		cin >> e;
//		ListInsert_Sq(Lb, i, e);
//	}
//	printf("Lb��Ϊ��%d\n", Lb.length);
//
//	//�ϲ������
//	printf("\n4. �ϲ��������La,Lb����Ԫ�غϲ���Lc���У��Ա�������\n");
//	InitList_Sq(Lc);
//	MergeList(La, Lb, Lc);
//	printf("�ϲ�������Lc��Ԫ��Ϊ��\n");
//	PrintList(Lc);
//	printf("�ϲ�������Lc���Ϊ��%d", Lc.length);
//
//	//��ת��
//	printf("\n5. ��תLc��\n");
//	ReverseList(Lc);
//	printf("��תLc���Lc��Ԫ��Ϊ��\n");
//	PrintList(Lc);
//}