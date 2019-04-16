/*
	Задание 2.

	Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
	std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
	Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
	Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
	Написать функцию print(), которая будет выводить значения переменных-членов.
*/

#include <iostream>
#include <cstdint>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class RGBA
{
private:
	uint8_t m_red = 0x00;
	uint8_t	m_green = 0x00;
	uint8_t	m_blue = 0x00;
	uint8_t	m_alpha = 0xFF;
public:
	RGBA()
	{

	}
	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
		:m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{

	}
	void print()
	{
		cout << "Red = " << static_cast<int>(m_red) << endl;
		cout << "Green = " << static_cast<int>(m_green) << endl;
		cout << "Blue = " << static_cast<int>(m_blue) << endl;
		cout << "Alpha = " << static_cast<int>(m_alpha) << endl;
	}
};


int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	RGBA standart;
	standart.print();
	cout << endl;

	RGBA red(0xFF, 0x00, 0x00, 0xFF);
	red.print();
	cout << endl;

	RGBA white(0xFF, 0xFF, 0xFF, 0xFF);
	white.print();
	cout << endl;

	system("Pause");
	return 1;
}