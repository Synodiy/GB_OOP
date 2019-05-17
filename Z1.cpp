/*
	Задание 1.
	Написать функцию div, которая должна вычислять результат деления двух целых чисел и запускать исключение DivisionByZero, 
	если делитель равен 0. В функции main ввести два целых числа и вывести их неполное частное, 
	если делитель не равен нулю, и сообщение об ошибке, если равен.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int divide(int a, int b)
{
	if (b == 0)
	{
		throw "Error! Cannot divided by zero.";
	}
	else
	{
		return a / b;
	}
}

int main(int argc, char** args)
{
	int a, b;
	cout << "Input first integer number: ";
	cin >> a;
	cout << "Input second integer number: ";
	cin >> b;
	
	try
	{
		int res = divide(a, b);
		cout << "The result of dividing " << a << " by " << b << " is " << res << endl;
	}
	catch (const char* err)
	{
		cout << err << endl;
	}

	system("Pause");
	return 1;
}