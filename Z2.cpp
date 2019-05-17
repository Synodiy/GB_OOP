/*
	Задание 2.
	Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
	инициализирующий x значением параметра. 
	Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) 
	и имеющий метод set с единственным вещественным параметром a. 
	Если y + a > 100, возбуждается исключение типа Ex с данными ay, иначе в y заносится значение a. 
	В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
	Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
	В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Ex
{
private:
	double x;
public:
	Ex(double num)
		: x(num)
	{

	}
	double GetX() const
	{
		return x;
	}
};
class Bar
{
private:
	double y;
public:
	Bar()
		: y(0)
	{

	}
	void Set(double a)
	{
		if (y + a > 100)
		{
			throw Ex(y * a);
		}
		else
		{
			y = a;
		}
	}
	double GetY() const
	{
		return y;
	}
};

int main(int argc, char** args)
{
	Bar test;

	int input;

	do
	{
		cout << "Input any number: ";
		cin >> input;
		try
		{
			test.Set(input);
		}
		catch (Ex obj)
		{
			cout << "Exception!" << endl;
			cout << "X = " << obj.GetX() << "\t" << "Y = " << test.GetY() << endl;
		}
		cout << endl;
	} while (input != 0);
	
	system("Pause");
	return 1;
}