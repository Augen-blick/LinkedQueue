#pragma once
#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct qnode
{
	ElemType data;									//存放元素
	struct qnode* next;								//下一个结点指针
} DataNode;

typedef struct
{
	DataNode* front;								//指向队首结点
	DataNode* rear;									//指向队尾结点
} LinkQuNode;										//链队结点的类型

void InitQueue(LinkQuNode*& q);						//初始化队列
void DestroyQueue(LinkQuNode*& q);					//销毁队列
bool QueueEmpty(LinkQuNode* q);						//判断队列是否为空
void enQueue(LinkQuNode*& q, ElemType e);			//进队列
bool deQueue(LinkQuNode*& q, ElemType& e);			//出队列

void InitQueue(LinkQuNode*& q)						//初始化队列
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

void DestroyQueue(LinkQuNode*& q)					//销毁队列
{
	DataNode* pre = q->front, * p;					//pre指向队首结点
	if (pre != NULL)
	{
		p = pre->next;								//p指向结点pre的后继结点
		while (p != NULL)							//p不空循环
		{
			free(pre);								//释放p结点
			pre = p;								//pre、p同步后移
			p = p->next;
		}
		free(pre);									//释放最后一个结点
	}
	free(q);										//释放链队结点
}

bool QueueEmpty(LinkQuNode* q)						//判断队列是否为空
{
	return(q->rear == NULL);
}

void enQueue(LinkQuNode*& q, ElemType e)			//进队列
{
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));		//创建新结点
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)							//若链队为空，则新结点既是队首结点又是队尾结点
		q->front = q->rear = p;
	else											//若链队不空
	{
		q->rear->next = p;							//将结点p链到队尾，并将rear指向它
		q->rear = p;
	}
}

bool deQueue(LinkQuNode*& q, ElemType& e)			//出队列
{
	DataNode* p;
	if (q->rear == NULL)							//若队列为空
		return false;
	p = q->front;									//q指向首结点
	if (q->front == q->rear)						//队列中只有一个数据结点时
		q->front = q->rear = NULL;
	else											//队列有两个以上结点时
		q->front = q->front->next;
	e = p->data;
	free(p);
	return true;
}