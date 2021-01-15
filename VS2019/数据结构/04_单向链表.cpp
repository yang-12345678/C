#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;  // ������
	struct Node* pNext;  // ָ����
}NODE, * PNODE;

PNODE create_list();  // ����������
void traverse_list(PNODE pHead);  // �������
bool is_empty(PNODE pHead);  // �п�
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int*);
void sort_list(PNODE);

int main()
{
	PNODE pHead = NULL;
	pHead = create_list();  // ����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);
	if (is_empty(pHead))
		printf("����Ϊ�գ�");
	else
		printf("�����գ�");
	return 0;
}

PNODE create_list()
{
	int len;  // ���������Ч�ڵ�ĸ���
	int i;
	int val;  // ������ʱ����û�����Ľڵ��ֵ

	// ������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("����ʧ�ܣ�������ֹ!\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len = ");
	scanf_s("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("�������%d�ڵ��ֵ��", i + 1);
		scanf_s("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("����ʧ�ܣ�������ֹ!\n");
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
	PNODE p = pHead->pNext;  // ָ���һ����Ч�ڵ�
	printf("���������Ϊ��");
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