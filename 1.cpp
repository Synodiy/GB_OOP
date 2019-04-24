/*
	Задание 1.

	Создать абстрактный класс Figure (фигура). 
	Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
	Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
	Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
	Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/


#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Figure
{
private:
public:
	Figure()
	{

	}
	virtual float area() = 0;
};

class Parallelogram : public Figure
{
private:
	float Height;
	float Base;
public:
	Parallelogram(float h, float b) : Height(h), Base(b)
	{

	}
	float area()
	{
		return Height * Base;
	}
};

class Rectangle : public Parallelogram
{
private:
public:
	Rectangle(float a, float b) : Parallelogram(a, b)
	{

	}
	float area()
	{
		return Parallelogram::area();
	}
};

class Square : public Parallelogram
{
private:
public:
	Square(float b) : Parallelogram(b, b)
	{

	}
	float area()
	{
		return Parallelogram::area();
	}
};

class Rhombus : public Parallelogram
{
private:
public:
	Rhombus(float h, float b) : Parallelogram(h, b)
	{

	}
	float area()
	{
		return Parallelogram::area();
	}
};

class Circle : public Figure
{
private:
	float Rad;
public:
	Circle(float r) : Rad(r)
	{

	}
	float area()
	{
		return 3.14 * Rad * Rad;
	}
};


int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	Rectangle rec(10.1, 2.2);
	Square sq(2.7);
	Rhombus rh(11, 8.2);
	Circle cr(13.4);

	Figure *f1 = &rec;
	Figure *f2 = &sq;
	Figure *f3 = &rh;
	Figure *f4 = &cr;

	cout << "Area of rectangle is " << f1->area() << endl;
	cout << "Area of square is " << f2->area() << endl;
	cout << "Area of rhombus is " << f3->area() << endl;
	cout << "Area of circle is " << f4->area() << endl;

	system("Pause");
	return 1;
}