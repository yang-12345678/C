#include <iostream>
#include <malloc.h>
using namespace std;

typedef int ElemType;

// ��������
typedef struct LNode {
	ElemType data;  // ������
	struct LNode* next;  // ָ����
}LNode, *LinkList;

// ���
int ListLength(LinkList L) {
	LNode* p = L->next;
	int k = 0;
	while (p)
	{
		p = p->next;
		k++;
	}
	return k;
}

// ����Ԫ�أ���ȡ���е�i��Ԫ�ص�ֵ
int GetElem(LinkList L, int i, ElemType& e)
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>=i)
		return 0;
	e = p->data;
	return 1;
}

// �ж�Ԫ��e�Ƿ��ڸ�������
int LocateElem(LinkList La, ElemType e)
{
	LinkList p = La;
	p = La;
	int i = 0;
	while (p->next)
	{
		p = p->next;
		i++;
		if (p->data == e)
			return i;
	}
	return 0;
}

// ��ӡ����Ԫ�ص�ֵ
void PrintList(LinkList L)
{
	LinkList p = L;
	while (p->next)
	{
		p = p->next;
		cout << p->data << endl;
	}
}

int main()
{

	return 0;
}