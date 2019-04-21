/*
	Задание 1.
	
	Создайте класс, который будет генерировать рандомные числа. 
	У этого класса должны быть обязательно два константных метода:
	один из них (Current) должен возвращать текущее сгенерированное число, 
	второй (Next) - следующее случайное число. 
	Если самым первым методом вызвать Current, то выдать предупреждение, что число не сгенерировано еще. 
	В классе должен быть конструктор по умолчанию, с параметрами, а также копирующий конструктор. 
	Создать кэширование текущего случайного числа.
	(Подсказка: чтобы константный метод мог все-таки изменять кэшируемое значение, 
	переменную необходимо объявить с помощью ключевого слова mutable).
*/

#include <iostream>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Randomizer
{
private:
	mutable int RandomNumber;
	mutable bool RandomNumberIsPrepared = false;
	int Maximum, Minimum;
public:
	Randomizer()
	{
		Maximum = 100;
		Minimum = 1;
	}
	Randomizer(int min, int max)
	{
		if (max < min)
		{
			cout << "Maximum must been >= minimum!" << endl;
			int temp = max;
			max = min;
			min = temp;
		}

		Maximum = max;
		Minimum = min;
	}
	Randomizer(Randomizer &rN)
	{
		RandomNumber = rN.RandomNumber;
		RandomNumberIsPrepared = rN.RandomNumberIsPrepared;
		Maximum = rN.Maximum;
		Minimum = rN.Minimum;
	}
	const int GetCurrentRandomNumber()
	{
		if (RandomNumberIsPrepared)
		{
			return RandomNumber;
		}
		else
		{
			cout << "Random number is not generated!" << endl;
			cout << "But we generate it for you :)" << endl;
			return PrepareRandomNumber();
		}
	}
	const int PrepareRandomNumber()
	{
		RandomNumberIsPrepared = true;
		RandomNumber = rand() % (Maximum - Minimum + 1) + Minimum;
		return RandomNumber;
	}
};

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	Randomizer r1;
	cout << r1.GetCurrentRandomNumber() << endl;
	cout << r1.PrepareRandomNumber() << endl;
	cout << r1.GetCurrentRandomNumber() << endl;
	cout << r1.PrepareRandomNumber() << endl;
	cout << r1.GetCurrentRandomNumber() << endl;
	cout << endl;

	Randomizer r2(10, 20);
	cout << r2.GetCurrentRandomNumber() << endl;
	cout << r2.PrepareRandomNumber() << endl;
	cout << r2.GetCurrentRandomNumber() << endl;
	cout << r2.PrepareRandomNumber() << endl;
	cout << r2.GetCurrentRandomNumber() << endl;
	cout << endl;

	Randomizer r3(2, 2);
	cout << r3.GetCurrentRandomNumber() << endl;
	cout << r3.PrepareRandomNumber() << endl;
	cout << r3.GetCurrentRandomNumber() << endl;
	cout << r3.PrepareRandomNumber() << endl;
	cout << r3.GetCurrentRandomNumber() << endl;
	cout << endl;

	Randomizer r4(r2);
	cout << r4.GetCurrentRandomNumber() << endl;
	cout << r4.PrepareRandomNumber() << endl;
	cout << r4.GetCurrentRandomNumber() << endl;
	cout << r4.PrepareRandomNumber() << endl;
	cout << r4.GetCurrentRandomNumber() << endl;
	cout << endl;

	Randomizer r5(-10, -50);
	cout << r5.GetCurrentRandomNumber() << endl;
	cout << r5.PrepareRandomNumber() << endl;
	cout << r5.GetCurrentRandomNumber() << endl;
	cout << r5.PrepareRandomNumber() << endl;
	cout << r5.GetCurrentRandomNumber() << endl;
	cout << endl;

	system("Pause");
	return 1;
}