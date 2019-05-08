/*
	Задание 3.
	Создать программу, которая считывает целое число типа int. 
	И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, 
	нужно вывести сообщение об ошибке и предложить ввести число еще раз.
	Задание 4.
	Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/

#include <iostream>
#include <string>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class CheckInt
{
private:
	string ciValue;
	bool notInt;
public:
	CheckInt()
	{
		notInt = true;
	}

	bool getStatus() const
	{
		return notInt;
	}
	friend istream& operator>> (istream& in, CheckInt &ci);
};

istream& operator>> (istream& in, CheckInt &ci)
{
	string str;
	getline(in, str);
	if (str.find_first_not_of("0123456789") != string::npos)
	{
		ci.notInt = true;
	}
	else
	{
		ci.notInt = false;
		ci.ciValue = str;
	}

	return in;
}

ostream& endll (ostream& out)
{
	cout << endl << endl;
	out.clear();

	return out;
}

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	CheckInt ci;

	while (ci.getStatus())
	{
		cout << "Input only integer value: ";
		cin >> ci;
		cout << endll;
	}

	
	

	system("Pause");
	return 1;
}