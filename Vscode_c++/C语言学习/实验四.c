#include<stdio.h>
#include<stdlib.h>

// 定义队列结点 
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*Queueptr;
 
// 定义队列头指针和尾指针 
typedef struct{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

// 初始化队列
LinkQueue InitQueue(LinkQueue Q){
	Q.front=Q.rear=(Queueptr)malloc(sizeof(QNode));
	if(!Q.front){
		printf("内存分配失败");
		exit(0);
	}
	Q.front->next=NULL;
	printf("初始化空队列成功\n"); 
}

// 队列判空
int QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear){
		printf("队空！\n");
		return 0;
	}
	printf("队不空\n");
	return 0;
} 

// 入队
void EnQueue(LinkQueue Q,int e){
	QNode *p=(Queueptr)malloc(sizeof(QNode));
	if(!p){
		printf("结点生成失败");
		exit(0); 
	}
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	printf("成功入队列");
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
