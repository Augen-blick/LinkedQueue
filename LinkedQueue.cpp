#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main()
{
	//��������
	LinkQuNode* q;

	//��ʼ������
	InitQueue(q);

	cout << "������֮ǰ" << endl;

	//�ж϶����Ƿ�Ϊ��
	if (QueueEmpty(q))
		cout << "�ö���Ϊ��" << endl;
	else
		cout << "�ö��в�Ϊ��" << endl;
	
	//������
	for (int i = 0; i < 5; i++)
	{
		enQueue(q, 'a' + i);
	}

	cout << "������֮��" << endl;

	//�ж϶����Ƿ�Ϊ��
	if (QueueEmpty(q))
		cout << "�ö���Ϊ��" << endl;
	else
		cout << "�ö��в�Ϊ��" << endl;

	//������
	char e;
	for (int i = 0; i < 5; i++)
	{
		deQueue(q, e);
		cout << e << " ";
	}
	cout << endl;

	cout << "������֮��" << endl;

	//�ж϶����Ƿ�Ϊ��
	if (QueueEmpty(q))
		cout << "�ö���Ϊ��" << endl;
	else
		cout << "�ö��в�Ϊ��" << endl;

	//���ٶ���
	DestroyQueue(q);

	return 0;
}