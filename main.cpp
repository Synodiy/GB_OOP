/*
		1) ����������� ������ ������ Pair1, ������� ��������� ������������ ���������� ������ ������ ���� ������.
		2) ����������� ����� Pair, ������� ��������� ������������ ������ ���� ������ � ������������ �����.
		3) �������� ������ ������ StringValuePair, � ������� ������ �������� ������ ���� string, 
		� ������ � ������ ����. ���� ������ ������ ������ ����������� �������� ������������������ ����� Pair, 
		� ������� ������ �������� � string, � ������ � ������ ���� ������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <string>
#include "pair.h"
using namespace std;

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	cout << endl;

	Pair<int, double> p11(6, 7.8);
	cout << "Pair: " << p11.first() << ' ' << p11.second() << '\n';

	const Pair<double, int> p22(3.4, 5);
	cout << "Pair: " << p22.first() << ' ' << p22.second() << '\n';

	cout << endl;
	
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';	

	system("Pause");
	return 1;
}