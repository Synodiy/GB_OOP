/*
	Задание 3.
	Написать класс «робот», моделирующий перемещения робота по сетке 10x10,
	у которого есть метод, означающий задание переместиться на соседнюю позицию.
	Эти методы должны запускать исключение OffTheField, если робот должен уйти с сетки,
	и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
	Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.

	Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,
	а также выводящую подробную информацию о всех возникающих ошибках.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Robot
{
private:
	int PosX;
	int PosY;
	const int MinX = 1;
	const int MinY = 1;
	const int MaxX = 10;
	const int MaxY = 10;
	void MoveUp()
	{
		if (PosY - 1 >= MinY)
		{
			PosY--;
		}
		else
		{
			throw "You have already reached the top of the field! Please try another direction.";
		}
	}
	void MoveDown()
	{
		if (PosY + 1 <= MaxY)
		{
			PosY++;
		}
		else
		{
			throw "You have already reached the bottom of the field! Please try another direction.";
		}
	}
	void MoveRight()
	{
		if (PosX + 1 <= MaxX)
		{
			PosX++;
		}
		else
		{
			throw "You have already reached the right side of the field! Please try another direction.";
		}
	}
	void MoveLeft()
	{
		if (PosX - 1 >= MinX)
		{
			PosX--;
		}
		else
		{
			throw "You have already reached the left side of the field! Please try another direction.";
		}
	}
public:
	Robot()
	{
		PosX = MinX;
		PosY = MinY;
	}
	string CurrentPosition() const
	{
		string Pos = "[";
		Pos += to_string(PosX);
		Pos += ", ";
		Pos += to_string(PosY);
		Pos += "]";

		return Pos;
	}
	void PrintField() const
	{
		cout << endl;

		for (int y = MinY; y <= MaxY; y++)		
		{
			for (int x = MinX; x <= MaxX; x++)
			{
				cout << "[";
				if (x == PosX && y == PosY)
				{
					cout << "R";
				}
				else
				{
					cout << " ";
				}
				cout << "]";
			}
			cout << endl;
		}

		cout << endl;
	}

	void Move(char com)
	{
		switch (com)
		{
		case 'U':
		case 'u':
			MoveUp();
			break;
		case 'D':
		case 'd':
			MoveDown();
			break;
		case 'L':
		case 'l':
			MoveLeft();
			break;
		case 'R':
		case 'r':
			MoveRight();
			break;
		case '0':
			break;
		default:
			throw "Inputed illegal command. Please try again.";
			break;
		}
	}

	
};

int main(int argc, char** args)
{
	Robot HellDriver;

	char Inp;

	cout << "Up = <U>" << endl;
	cout << "Down = <D>" << endl;
	cout << "Left = <L>" << endl;
	cout << "Right = <R>" << endl;
	cout << "Exit = <0>" << endl;

	do
	{
		HellDriver.PrintField();

		cout << "Input command (U/D/L/R/0): ";
		cin >> Inp;

		try 
		{
			HellDriver.Move(Inp);
		}
		catch (const char* ErrMessage)
		{
			cout << ErrMessage << endl;
		}

	} while (Inp != '0');

	system("Pause");
	return 1;
}