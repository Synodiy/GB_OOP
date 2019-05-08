#ifndef _MIXED_FRACTION_H
#define _MIXED_FRACTION_H

#include "fraction.h"

class MixedFraction : public Fraction
{
private:
	int WholePart;
public:
	MixedFraction()
		: Fraction()
	{
		WholePart = 0;
	}
	MixedFraction(int whole, int num, int den) : WholePart(whole), Fraction(num, den)
	{
		if (get_FractionValid())
		{
			//cout << "Mixed fraction " << WholePart << " (" << get_Numerator() << "/" << get_Denominator() << ")" << endl;
		}
		else
		{
			cout << "Wrong fraction!" << endl;
		}
	}
	int get_WholePart() const
	{
		if (get_FractionValid())
		{
			return WholePart;
		}
		else
		{
			return 0;
		}
	}
	string get_FractionString() const
	{
		if (get_FractionValid())
		{
			return (to_string(WholePart) + ' ' + to_string(get_Numerator()) + '/' + to_string(get_Denominator()));
		}
		else
		{
			return "Fraction is incorrect!";
		}
	}
	MixedFraction operator- ()
	{
		int newWholePart = WholePart;
		int newNumerator = get_Numerator();

		if (WholePart == 0)
		{
			newNumerator = -newNumerator;
		}
		else
		{
			newWholePart = -newWholePart;
		}
		int newDenominator = get_Denominator();

		return MixedFraction(newWholePart, newNumerator, newDenominator);
	}

	friend istream& operator>> (istream& in, MixedFraction& fract);
	friend ostream& operator<< (ostream& out, const MixedFraction& fract);
};

istream& operator>> (istream& in, MixedFraction& fract)
{
	string input, num, denum, whole;
	getline(in, input);

	int i = 0;
	whole = "";
	num = "";
	denum = "";
	while (input[i] != ' ')
	{
		whole += input[i++];
		if (i == input.length())
		{
			cout << "Inputed incorrected fraction!" << endl;
			return in;
		}
	}
	i++;
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

	if ((whole.find_first_not_of("0123456789") != string::npos) || (num.find_first_not_of("0123456789") != string::npos) || (denum.find_first_not_of("0123456789") != string::npos))
	{
		cout << "Inputed incorrected fraction!" << endl;
		return in;
	}

	MixedFraction newfract(stoi(whole), stoi(num), stoi(denum));

	fract = newfract;

	return in;
}
ostream& operator<< (ostream& out, const MixedFraction& fract)
{
	out << fract.get_FractionString();

	return out;
}

MixedFraction operator+ (const MixedFraction mf1, const MixedFraction mf2)
{
	if (mf1.get_FractionValid() && mf2.get_FractionValid())
	{
		int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * mf2.get_Denominator()
			+ (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator()) * mf1.get_Denominator();
		int Denominator = mf1.get_Denominator() * mf2.get_Denominator();
		int WholePart = Numerator / Denominator;
		Numerator = Numerator % Denominator;

		return MixedFraction(WholePart, Numerator, Denominator);
	}
	else
	{
		return MixedFraction();
	}
}
MixedFraction operator- (const MixedFraction mf1, const MixedFraction mf2)
{
	if (mf1.get_FractionValid() && mf2.get_FractionValid())
	{
		int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * mf2.get_Denominator()
			- (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator()) * mf1.get_Denominator();
		int Denominator = mf1.get_Denominator() * mf2.get_Denominator();
		int WholePart = Numerator / Denominator;
		Numerator = Numerator % Denominator;

		return MixedFraction(WholePart, Numerator, Denominator);
	}
	else
	{
		return MixedFraction();
	}
}
MixedFraction operator* (const MixedFraction mf1, const MixedFraction mf2)
{
	if (mf1.get_FractionValid() && mf2.get_FractionValid())
	{
		int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator());
		int Denominator = mf1.get_Denominator() * mf2.get_Denominator();
		int WholePart = Numerator / Denominator;
		Numerator = Numerator % Denominator;

		return MixedFraction(WholePart, Numerator, Denominator);
	}
	else
	{
		return MixedFraction();
	}
}
MixedFraction operator/ (const MixedFraction mf1, const MixedFraction mf2)
{
	if (mf1.get_FractionValid() && mf2.get_FractionValid())
	{
		int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * mf2.get_Denominator();
		int Denominator = mf1.get_Denominator() *  (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator());
		int WholePart = Numerator / Denominator;
		Numerator = Numerator % Denominator;

		return MixedFraction(WholePart, Numerator, Denominator);
	}
	else
	{
		return MixedFraction();
	}	
}
bool operator== (const MixedFraction mf1, const MixedFraction mf2)
{
	float t1 = (float)mf1.get_WholePart() + (float)mf1.get_Numerator() / (float)mf1.get_Denominator();
	float t2 = (float)mf2.get_WholePart() + (float)mf2.get_Numerator() / (float)mf2.get_Denominator();

	if (t1 == t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!= (const MixedFraction mf1, const MixedFraction mf2)
{
	float t1 = (float)mf1.get_WholePart() + (float)mf1.get_Numerator() / (float)mf1.get_Denominator();
	float t2 = (float)mf2.get_WholePart() + (float)mf2.get_Numerator() / (float)mf2.get_Denominator();

	if (t1 != t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator< (const MixedFraction mf1, const MixedFraction mf2)
{
	float t1 = (float)mf1.get_WholePart() + (float)mf1.get_Numerator() / (float)mf1.get_Denominator();
	float t2 = (float)mf2.get_WholePart() + (float)mf2.get_Numerator() / (float)mf2.get_Denominator();

	if (t1 < t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>= (const MixedFraction mf1, const MixedFraction mf2)
{
	if (mf1 < mf2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>(const MixedFraction mf1, const MixedFraction mf2)
{
	float t1 = (float)mf1.get_WholePart() + (float)mf1.get_Numerator() / (float)mf1.get_Denominator();
	float t2 = (float)mf2.get_WholePart() + (float)mf2.get_Numerator() / (float)mf2.get_Denominator();

	if (t1 > t2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<= (const MixedFraction mf1, const MixedFraction mf2)
{
	if (mf1 > mf2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

#endif
