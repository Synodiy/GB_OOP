#ifndef _QUEUEINT_H
#define _QUEUEINT_H

#include <cassert>
#include <iostream>
using namespace std;

class QueueInt
{
private:
	static const int arrsize = 100;
	int *queue;
	int last;	//номер элемента, куда следует писать следующий элемент
public:
	QueueInt()
	{
		queue = new int[arrsize];
		last = 0;
	}
	~QueueInt()
	{
		delete[] queue;
	}
	
	int size()
	{
		return last;
	}

	void push(int x)
	{
		if (last == arrsize)
		{
			cout << "Переполнение очереди!" << endl;
			return;
		}

		queue[last++] = x;
	}
	void pop()
	{
		if (last == 0)
		{
			cout << "Нет элементов в очереди!" << endl;
			return;
		}

		last--;

		int *temp = new int[last];

		for (int i = 0; i < last; i++)
		{
			temp[i] = queue[i + 1];
		}

		for (int i = 0; i < last; i++)
		{
			queue[i] = temp[i];
		}

		delete[] temp;
	}

	int front()
	{
		return queue[0];
	}
	int back()
	{
		return queue[last - 1];
	}
};



#endif
