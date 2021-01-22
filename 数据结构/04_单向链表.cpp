#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;  // 数据域
	struct Node* pNext;  // 指针域
}NODE, * PNODE;

PNODE create_list();  // 创建单链表
void traverse_list(PNODE pHead);  // 输出链表
bool is_empty(PNODE pHead);  // 判空
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int*);
void sort_list(PNODE);

int main()
{
	PNODE pHead = NULL;
	pHead = create_list();  // 创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
	traverse_list(pHead);
	if (is_empty(pHead))
		printf("链表为空！");
	else
		printf("链表不空！");
	return 0;
}

PNODE create_list()
{
	int len;  // 用来存放有效节点的个数
	int i;
	int val;  // 用来临时存放用户输入的节点的值

	// 分配了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("分配失败，程序终止!\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入您需要生成的链表节点的个数：len = ");
	scanf_s("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d节点的值：", i + 1);
		scanf_s("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("分配失败，程序终止!\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;  // 指向第一个有效节点
	printf("输出该链表为：");
	while (p != NULL)
	{
		printf("%2d", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

int length_list()