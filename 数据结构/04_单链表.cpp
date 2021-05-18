#include <iostream>
#include <malloc.h>
using namespace std;

typedef int ElemType;

// 定义类型
typedef struct LNode {
	ElemType data;  // 数据域
	struct LNode* next;  // 指针域
}LNode, *LinkList;

// 求表长
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

// 查找元素，获取表中第i个元素的值
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

// 判断元素e是否在该链表中
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

// 打印表中元素的值
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