
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;	//������������ֵ������Ϊ�ַ���
const int MaxLength = 10;	//������������10��

int LEAFCOUNT = 0;
int NODECOUNT = 0;

typedef struct BiTNode
{
	ElemType data;  // �ڵ��������
	struct BiTNode* lchild, * rchild;  // ���Һ���ָ��
}BiTNode, * BiTree;

void CreateBiTree(BiTree& T)//������������룬�������ַ���ʾ����
{  
	char ch;
	scanf_s("%c", &ch);
	if (ch == ' ')  // �Կո��ʾ����
		T == NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));  // ����һ���������ڵ�
		T -> data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

}

void PreOrderTraverse(BiTree T)//�������
{
	//����д����
	//..........
}

void InOrderTraverse(BiTree T)//�������
{
	//����д����
	//..........
}

void PostOrderTraverse(BiTree T)//�������
{
	//����д����
	//..........
}

void LevelOrderTraverse(BiTree T)//�������
{
	BiTree Q[MaxLength];
	int front = 0, rear = 0;
	BiTree p;
	if (T)				//��������
	{
		Q[rear] = T;
		rear = (rear + 1) % MaxLength;
	}
	while (front != rear)
	{
		p = Q[front];		//��ͷԪ�س���
		front = (front + 1) % MaxLength;
		printf("%c ", p->data);
		if (p->lchild)  //���Ӳ�Ϊ�գ����
		{
			Q[rear] = p->lchild;
			rear = (rear + 1) % MaxLength;
		}
		if (p->rchild) //�Һ��Ӳ�Ϊ�գ����
		{
			Q[rear] = p->rchild;
			rear = (rear + 1) % MaxLength;
		}
	}
}

void NRPreOrder(BiTree bt) {//�ǵݹ����������㷨
	BiTree stack[MaxLength];
	int top = 0;
	if (!bt)
	{
		printf("����!\n");
		return;
	}
	while (bt || top != 0)
	{
		while (bt)
		{
			stack[top++] = bt;
			printf("%c ", bt->data);
			bt = bt->lchild;
		}
		bt = stack[--top];
		bt = bt->rchild;
	}
}

void NRInOrder(BiTree bt)//�ǵݹ����������㷨
{
	//����д����
	//..........
}

/*�ǵݹ�ĺ�������㷨
bt��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ����������������ٷ��ʸ�����Ҫ�жϸ��������������Ƿ����������
�ɲ��ñ�Ƿ��������ջʱ����һ����־tagһͬ��ջ(1������������ǰ���ֳ�������2������������ǰ���ֳ�����)��
���Ƚ�bt��tag(Ϊ1)��ջ�����������������غ��޸�ջ��tagΪ2�������������������ʸ���㡣*/
typedef struct
{
	BiTree ptr;
	int tag;
}stacknode;

void NRPostOrder(BiTree bt)//�ǵݹ�ĺ�������㷨
{
	stacknode s[MaxLength], x;
	BiTree p = bt;
	int top;
	if (bt != NULL) {
		top = 0;
		p = bt;
		do {
			while (p != NULL)//����������
			{
				s[top].ptr = p;
				s[top].tag = 1;			//���Ϊ������
				top++;
				p = p->lchild;
			}
			while (top > 0 && s[top - 1].tag == 2)
			{
				x = s[--top];
				p = x.ptr;
				printf("%c ", p->data);	//tagΪR����ʾ������������ϣ��ʷ��ʸ����
			}
			if (top > 0)
			{
				s[top - 1].tag = 2;		//����������
				p = s[top - 1].ptr->rchild;
			}
		} while (top > 0);
	}
}

int BTDepth(BiTree T)//������������
{
	//����д����
	//..........
	return 0;
}

void Leaf(BiTree T)//���������Ҷ����, ʹ��ȫ�ֱ���
{
	//����д����
	//..........
}

void NodeCount(BiTree T)//��������Ľ������, ʹ��ȫ�ֱ���
{
	//����д����
	//..........
}

void main()
{
	BiTree T = NULL;
	int select;
	while (1)
	{
		printf("\n1.����������\n");
		printf("2.�������ĵݹ�����㷨����,��,��\n");
		printf("3.�������Ĳ�α����㷨\n");
		printf("4.������������\n");
		printf("5.���������Ҷ�ӽ��\n");
		printf("6.��������Ľ������\n");
		printf("7.�������ķǵݹ�����㷨����,��,��\n");
		printf("0.�˳�\n");
		printf("��ѡ��Ҫִ�еĲ���: ");

		scanf("%d", &select);
		printf("---------------------- ");
		switch (select)
		{
		case 0:
			return;
		case 1:
			printf("\n������������������ֵ���Կո��ʾ����(����ʱ����������):\n");
			fflush(stdin);//������뻺��
			CreateBiTree(T);
			printf("�����������ɹ�!\n");
			break;
		case 2:
			if (!T)
				printf("δ�����������Ƚ�����\n");
			else {
				printf("\n�������: ");
				PreOrderTraverse(T);
				printf("\n�������: ");
				InOrderTraverse(T);
				printf("\n�������: ");
				PostOrderTraverse(T);
				printf("\n");
			}
			break;
		case 3:
			printf("\n�������: ");
			LevelOrderTraverse(T);
			printf("\n");
			break;
		case 4:
			printf("\n�����������Ϊ: ");
			printf("%d\n", BTDepth(T));
			break;
		case 5:
			printf("\nҶ�ӽڵ���: ");
			LEAFCOUNT = 0;
			Leaf(T);
			printf("%d\n", LEAFCOUNT);
			break;
		case 6:
			printf("\n�ܽڵ���: ");
			NODECOUNT = 0;
			NodeCount(T);
			printf("%d\n", NODECOUNT);
			break;
		case 7:
			if (!T)
				printf("δ�����������Ƚ�����");
			else
			{
				printf("\n�������: ");
				NRPreOrder(T);
				printf("\n�������: ");
				NRInOrder(T);
				printf("\n�������: ");
				NRPostOrder(T);
				printf("\n");
			}
			break;
		default:
			printf("��ȷ��ѡ����:\n");
		}
	}
}