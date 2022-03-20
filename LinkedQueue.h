#pragma once
#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct qnode
{
	ElemType data;									//���Ԫ��
	struct qnode* next;								//��һ�����ָ��
} DataNode;

typedef struct
{
	DataNode* front;								//ָ����׽��
	DataNode* rear;									//ָ���β���
} LinkQuNode;										//���ӽ�������

void InitQueue(LinkQuNode*& q);						//��ʼ������
void DestroyQueue(LinkQuNode*& q);					//���ٶ���
bool QueueEmpty(LinkQuNode* q);						//�ж϶����Ƿ�Ϊ��
void enQueue(LinkQuNode*& q, ElemType e);			//������
bool deQueue(LinkQuNode*& q, ElemType& e);			//������

void InitQueue(LinkQuNode*& q)						//��ʼ������
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

void DestroyQueue(LinkQuNode*& q)					//���ٶ���
{
	DataNode* pre = q->front, * p;					//preָ����׽��
	if (pre != NULL)
	{
		p = pre->next;								//pָ����pre�ĺ�̽��
		while (p != NULL)							//p����ѭ��
		{
			free(pre);								//�ͷ�p���
			pre = p;								//pre��pͬ������
			p = p->next;
		}
		free(pre);									//�ͷ����һ�����
	}
	free(q);										//�ͷ����ӽ��
}

bool QueueEmpty(LinkQuNode* q)						//�ж϶����Ƿ�Ϊ��
{
	return(q->rear == NULL);
}

void enQueue(LinkQuNode*& q, ElemType e)			//������
{
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));		//�����½��
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)							//������Ϊ�գ����½����Ƕ��׽�����Ƕ�β���
		q->front = q->rear = p;
	else											//�����Ӳ���
	{
		q->rear->next = p;							//�����p������β������rearָ����
		q->rear = p;
	}
}

bool deQueue(LinkQuNode*& q, ElemType& e)			//������
{
	DataNode* p;
	if (q->rear == NULL)							//������Ϊ��
		return false;
	p = q->front;									//qָ���׽��
	if (q->front == q->rear)						//������ֻ��һ�����ݽ��ʱ
		q->front = q->rear = NULL;
	else											//�������������Ͻ��ʱ
		q->front = q->front->next;
	e = p->data;
	free(p);
	return true;
}