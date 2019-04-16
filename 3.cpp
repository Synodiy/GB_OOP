/*
	Задание 3.

	Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
	private-массив целых чисел длиной 10;
	private целочисленное значение для отслеживания длины стека;
	public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
	public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
	public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
	public-метод с именем print(), который будет выводить все значения стека.
*/

#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Stack
{
private:
	static const int StackSize = 10;
	int StackArray[StackSize];
	int CurrentStackSize;

public:
	void reset()
	{
		CurrentStackSize = 0;

		for (int i = 0; i < StackSize; i++)
		{
			StackArray[i] = 0;
		}		
	}

	bool push(int num)
	{
		if (CurrentStackSize == StackSize)
		{
			return false;
		}
		else
		{
			StackArray[CurrentStackSize++] = num;
			return true;
		}
	}

	int pop()
	{
		if (CurrentStackSize == 0)
		{
			cout << "Stack empty!" << endl;
		}
		else
		{
			return StackArray[--CurrentStackSize];
		}
	}

	void print()
	{
		cout << "( ";
		for (int i = 0; i < CurrentStackSize; i++)
		{
			cout << StackArray[i] << " ";
		}
		cout << ")" << endl;
	}
};


int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(6);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();


	stack.pop();
	
	for (int i = 0; i < 15; i++)
	{
		if (!stack.push(i))
		{
			cout << "Stack overflow!" << endl;
		}			
	}
	stack.print();

	stack.reset();
	stack.print();

	system("Pause");
	return 1;
}