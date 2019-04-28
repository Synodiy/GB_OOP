#ifndef _ARRAYINT_H
#define _ARRAYINT_H

#include <cassert>
#include <iostream>
using namespace std;
class ArrayInt
{
private:
	int aiLength;
	int *aiData;
	void SwapElements(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
public:
	ArrayInt()
		: aiLength(0), aiData(nullptr)
	{

	}

	ArrayInt(int length)
		: aiLength(length)
	{
		assert(length >= 0);

		if (length > 0)
		{
			aiData = new int[length];
		}
		else
		{
			aiData = nullptr;
		}

	}

	~ArrayInt()
	{
		delete[] aiData;
	}

	void Erase()
	{
		delete[] aiData;
		aiData = nullptr;
		aiLength = 0;
	}
	int GetLength()
	{
		return aiLength;
	}
	int& operator[](int index)
	{
		assert(index >= 0 && index < aiLength);
		return aiData[index];
	}
	void Resize(int newLength)
	{
		if (newLength == aiLength)
		{
			return;
		}

		if (newLength <= 0)
		{
			Erase();
			return;
		}

		int *data = new int[newLength];

		if (aiLength > 0)
		{
			int elementsToCopy = (newLength > aiLength) ? aiLength : newLength;

			for (int i = 0; i < elementsToCopy; i++)
			{
				data[i] = aiData[i];
			}

		}

		delete[] aiData;

		aiData = data;
		aiLength = newLength;
	}
	void Print()
	{
		assert(aiLength > 0);

		for (int i = 0; i < aiLength; i++)
		{
			cout << aiData[i] << endl;
		}
	}

	void InsertBefore(int value, int index)
	{
		assert(index >= 0 && index <= aiLength);

		int *data = new int[aiLength + 1];

		for (int i = 0; i < index; i++)
		{
			data[i] = aiData[i];
		}

		data[index] = value;

		for (int i = index; i < aiLength; i++)
		{
			data[i + 1] = aiData[i];
		}

		delete[] aiData;
		aiData = data;
		aiLength++;
	}
	void DeleteItem(int index)
	{
		assert(index >= 0 && index < aiLength);

		int *data = new int[aiLength - 1];

		for (int i = 0; i < index; i++)
		{
			data[i] = aiData[i];
		}
		for (int i = index; i < aiLength; i++)
		{
			data[i] = aiData[i + 1];
		}

		delete[] aiData;
		aiData = data;
		aiLength--;
	}
	void InsertArray(int *value, int length, int index)
	{
		assert(index >= 0 && index <= aiLength);

		assert(length > 0);

		for (int i = 0; i < length; i++)
		{
			InsertBefore(value[i], index + i);
		}
	}

	void PopBack()
	{
		DeleteItem(aiLength - 1);
	}
	void PushBack(int value)
	{
		InsertBefore(value, aiLength);
	}

	void Sort()
	{
		assert(aiLength > 0);

		for (int i = 0; i < aiLength; i++)
		{
			int temp = aiData[i];
			int k = i;
			
			while ((k > 0) && (aiData[k - 1] > temp))
			{
				SwapElements(&aiData[k], &aiData[k - 1]);
				k--;
			}
		}
	}
};













#endif
