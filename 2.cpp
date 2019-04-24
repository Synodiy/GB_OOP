/*
	Задание 2.
	
	Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
	Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
	От этих классов наследует класс Minivan (минивэн). 
	Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
	Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
	Обратить внимание на проблему «алмаз смерти».
*/

#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Car
{
private:
	string Company;
	string Model;
public:
	Car(string comp, string mod) : Company(comp), Model(mod)
	{
		cout << "Car " << Company << " " << Model << " created." << endl;
	}
};

class PassengerCar : virtual public Car
{
private:

public:
	PassengerCar(string comp, string mod) : Car(comp, mod)
	{
		cout << "This is also passenger car." << endl;
	}
};

class Bus : virtual public Car
{
private:

public:
	Bus(string comp, string mod) : Car(comp, mod)
	{
		cout << "This is also bus." << endl;
	}
};

class Minivan : public Bus, public PassengerCar
{
private:

public:
	Minivan(string comp, string mod) : PassengerCar(comp, mod), Bus(comp, mod), Car(comp, mod)
	{
		cout << "Unbelievable!! This is suddenly a minivan!!" << endl;
	}
};

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");
	
	Car tachlo1("Shmazda", "666");
	cout << endl;
	PassengerCar tachlo2("Taz", "2114");
	cout << endl;
	Bus tachlo3("Icarus", "777");
	cout << endl;
	Minivan tachlo4("Tesla", "Rx241");
	cout << endl;

	system("Pause");
	return 1;
}