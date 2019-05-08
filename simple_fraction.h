#ifndef _SIMPLE_FRACTION_H
#define _SIMPLE_FRACTION_H

#include "fraction.h"

class SimpleFraction : public Fraction
{
public:
	SimpleFraction()
		: Fraction()
	{

	}

	SimpleFraction(int num, int den) : Fraction(num, den)
	{
		if (get_FractionValid())
		{
			//cout << "Simple fraction " << get_Numerator() << "/" << get_Denominator() << endl;
		}
		else
		{
			cout << "Wrong fraction!" << endl;
		}
	}
	string get_FractionString() const
	{
		if (get_FractionValid())
		{
			return (to_string(get_Numerator()) + '/' + to_string(get_Denominator()));
		}
		else
		{
			return "Fraction is incorrect!";
		}
	}
	SimpleFraction operator- ()
	{
		int newNumerator = -get_Numerator();
		int newDenominator = get_Denominator();

		return SimpleFraction(newNumerator, newDenominator);
	}

	friend istream& operator>> (istream& in, SimpleFraction& fract);
	friend ostream& operator<< (ostream& out, const SimpleFraction& fract);
};

istream& operator>> (istream& in, SimpleFraction& fract)
{
	string input, num, denum;
	getline(in, input);

	int i = 0;
	num = "";
	denum = "";
	while (input[i] != '/')
	{
		num += input[i++];
		if (i == input.length())
		{
			cout << "Inputed incorrected fraction!" << endl;
			return in;
		}
	}
	i++;
	while (i != input.length())
	{
		denum += input[i++];
	}

	if ((num.find_first_not_of("0123456789") != string::npos) || (denum.find_first_not_of("0123456789") != string::npos))
	{
		cout << "Inputed incorrected fraction!" << endl;
		return in;
	}

	SimpleFraction newfract(stoi(num), stoi(denum));

	fract = newfract;

	return in;
}
ostream& operator<< (ostream& out, const SimpleFraction& fract)
{
	out << fract.get_FractionString();

	return out;
}


SimpleFraction operator+ (const SimpleFraction sf1, const SimpleFraction sf2)
{
	if (sf1.get_FractionValid() && sf2.get_FractionValid())
	{
		int newNumerator = sf1.get_Numerator() * sf2.get_Denominator() + sf2.get_Numerator() * sf1.get_Denominator();
		int newDenominator = sf1.get_Denominator() * sf2.get_Denominator();

		return SimpleFraction(newNumerator, newDenominator);
	}
	else
	{
		return SimpleFraction();
	}
}
SimpleFraction operator- (const SimpleFraction sf1, const SimpleFraction sf2)
{
	if (sf1.get_FractionValid() && sf2.get_FractionValid())
	{
		int newNumerator = sf1.get_Numerator() * sf2.get_Denominator() - sf2.get_Numerator() * sf1.get_Denominator();
		int newDenominator = sf1.get_Denominator() * sf2.get_Denominator();

		return SimpleFraction(newNumerator, newDenominator);
	}
	else
	{
		return SimpleFraction();
	}
}
SimpleFraction operator* (const SimpleFraction sf1, const SimpleFraction sf2)
{
	if (sf1.get_FractionValid() && sf2.get_FractionValid())
	{
		int newNumerator = sf1.get_Numerator() * sf2.get_Numerator();
		int newDenominator = sf1.get_Denominator() * sf2.get_Denominator();

		return SimpleFraction(newNumerator, newDenominator);
	}
	else
	{
		return SimpleFraction();
	}
}
SimpleFraction operator/ (const SimpleFraction sf1, const SimpleFraction sf2)
{
	if (sf1.get_FractionValid() && sf2.get_FractionValid())
	{
		int newNumerator = sf1.get_Numerator() * sf2.get_Denominator();
		int newDenominator = sf1.get_Denominator() * sf2.get_Numerator();

		return SimpleFraction(newNumerator, newDenominator);
	}
	else
	{
		return SimpleFraction();
	}
}
bool operator== (const SimpleFraction sf1, const SimpleFraction sf2)
{
	float t1 = (float)sf1.get_Numerator() / (float)sf1.get_Denominator();
	float t2 = (float)sf2.get_Numerator() / (float)sf2.get_Denominator();

	if (t1 == t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!= (const SimpleFraction sf1, const SimpleFraction sf2)
{
	float t1 = (float)sf1.get_Numerator() / (float)sf1.get_Denominator();
	float t2 = (float)sf2.get_Numerator() / (float)sf2.get_Denominator();

	if (t1 != t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator< (const SimpleFraction sf1, const SimpleFraction sf2)
{
	float t1 = (float)sf1.get_Numerator() / (float)sf1.get_Denominator();
	float t2 = (float)sf2.get_Numerator() / (float)sf2.get_Denominator();

	if (t1 < t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>= (const SimpleFraction sf1, const SimpleFraction sf2)
{
	if (sf1 < sf2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>(const SimpleFraction sf1, const SimpleFraction sf2)
{
	float t1 = (float)sf1.get_Numerator() / (float)sf1.get_Denominator();
	float t2 = (float)sf2.get_Numerator() / (float)sf2.get_Denominator();

	if (t1 > t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<= (const SimpleFraction sf1, const SimpleFraction sf2)
{
	if (sf1 > sf2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

#endif
