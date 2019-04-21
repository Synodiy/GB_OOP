/*
	Задание 3.

	Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
	У Fruit есть две переменные-члена: name (имя) и color (цвет). 
	Добавить новый класс GrannySmith, который наследует класс Apple.
*/

#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Fruit
{
protected:
	string Name;
	string Color;
public:
	Fruit(string name, string color)
		: Name(name), Color(color)
	{

	}
	string GetName()
	{
		return Name;
	}
	string GetColor()
	{
		return Color;
	}
};

class Banana : public Fruit
{
public:
	Banana(string color = "yellow")
		: Fruit("banana", color)
	{

	}
};

class Apple : public Fruit
{
public:
	Apple(string color = "yellow", string altName = "apple")
		: Fruit (altName, color)
	{

	}
};
class GrannySmith : public Apple
{
public:
	GrannySmith(string color = "green", string altName = "Granny Smith apple")
		: Apple(color, altName)
	{

	}
};




int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.GetName() << " is " << a.GetColor() << ".\n";
	std::cout << "My " << b.GetName() << " is " << b.GetColor() << ".\n";
	std::cout << "My " << c.GetName() << " is " << c.GetColor() << ".\n";

	
	system("Pause");
	return 1;
}