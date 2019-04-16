/*
	Задание 1.

	Создать класс Power, который содержит два вещественных числа. 
	Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
	Еще создать два метода: один с именем set, который позволит присваивать значения переменным, 
	второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
	Задать значения этих двух чисел по умолчанию.
*/

#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Power
{
private:
	float BaseNum = 5;
	float ExpNum = 2;
public:
	void set(float base, float exp)		
	{
		BaseNum = base;
		ExpNum = exp;
	}
	void calculate()
	{
		cout << pow(BaseNum, ExpNum) << endl;
	}
};


int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	Power first;
	first.calculate();

	Power second;
	second.set(2.1, 5.8);
	second.calculate();

	system("Pause");
	return 1;
}