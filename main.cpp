#include <iostream>
#include <string>

#include "simple_fraction.h"
#include "mixed_fraction.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	
	SimpleFraction f1;
	cout << "Enter fraction 1: ";
	cin >> f1;
	SimpleFraction f2;
	cout << "Enter fraction 2: ";
	cin >> f2;

	cout << f1 << " * " << f2 << " is " << f1 * f2 << endl;
	
	MixedFraction m1;
	cout << "Enter fraction 1: ";
	cin >> m1;
	MixedFraction m2;
	cout << "Enter fraction 2: ";
	cin >> m2;

	cout << m1 << " * " << m2 << " is " << m1 * m2 << endl;


	system("Pause");
	return 1;
}
