#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Fraction
{
private:
	int Numerator;		//числитель
	int Denominator;	//знаменатель
	bool FractionValid;
	int FindNod(int a, int b)
	{
		a = abs(a);
		b = abs(b);

		if (b == 0)
		{
			return a;
		}
		else
		{
			return FindNod(b, a%b);
		}
	}
	void CutFraction()
	{
		int nod = FindNod(Numerator, Denominator);

		Numerator /= nod;
		Denominator /= nod;
	}
public:
	Fraction()
	{
		FractionValid = false;
		Numerator = 1;
		Denominator = 1;
	}
	Fraction(int num, int den)
	{
		if (den == 0)
		{
			cout << "Denomerator must be > 0" << endl;
			FractionValid = false;
			return;
		}

		FractionValid = true;
		Numerator = num;
		Denominator = den;
		CutFraction();
	}
	int get_Numerator() const
	{
		if (FractionValid)
		{
			return Numerator;
		}
		else
		{
			return 0;
		}
	}
	int get_Denominator() const
	{
		if (FractionValid)
		{
			return Denominator;
		}
		else
		{
			return 0;
		}
	}
	bool get_FractionValid() const
	{
		return FractionValid;
	}

	virtual string get_FractionString() const = 0;
};





#endif
