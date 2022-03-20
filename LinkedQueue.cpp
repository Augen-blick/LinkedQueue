#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main()
{
	//定义链队
	LinkQuNode* q;

	//初始化队列
	InitQueue(q);

	cout << "进队列之前" << endl;

	//判断队列是否为空
	if (QueueEmpty(q))
		cout << "该队列为空" << endl;
	else
		cout << "该队列不为空" << endl;
	
	//进队列
	for (int i = 0; i < 5; i++)
	{
		enQueue(q, 'a' + i);
	}

	cout << "进队列之后" << endl;

	//判断队列是否为空
	if (QueueEmpty(q))
		cout << "该队列为空" << endl;
	else
		cout << "该队列不为空" << endl;

	//出队列
	char e;
	for (int i = 0; i < 5; i++)
	{
		deQueue(q, e);
		cout << e << " ";
	}
	cout << endl;

	cout << "出队列之后" << endl;

	//判断队列是否为空
	if (QueueEmpty(q))
		cout << "该队列为空" << endl;
	else
		cout << "该队列不为空" << endl;

	//销毁队列
	DestroyQueue(q);

	return 0;
}