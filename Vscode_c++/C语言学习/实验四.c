#include<stdio.h>
#include<stdlib.h>

// ������н�� 
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*Queueptr;
 
// �������ͷָ���βָ�� 
typedef struct{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

// ��ʼ������
LinkQueue InitQueue(LinkQueue Q){
	Q.front=Q.rear=(Queueptr)malloc(sizeof(QNode));
	if(!Q.front){
		printf("�ڴ����ʧ��");
		exit(0);
	}
	Q.front->next=NULL;
	printf("��ʼ���ն��гɹ�\n"); 
}

// �����п�
int QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear){
		printf("�ӿգ�\n");
		return 0;
	}
	printf("�Ӳ���\n");
	return 0;
} 

// ���
void EnQueue(LinkQueue Q,int e){
	QNode *p=(Queueptr)malloc(sizeof(QNode));
	if(!p){
		printf("�������ʧ��");
		exit(0); 
	}
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	printf("�ɹ������");
} 

int main(){
	int i=0;
	int e;
	LinkQueue Q;
	InitQueue(Q);
	while(i<5){
		scanf("%d",&e);
		EnQueue(Q,e);
	}
	QueueEmpty(Q);
	
	return 0;
}
