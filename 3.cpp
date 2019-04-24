/*
	Задание 3.

	Создать абстрактный класс Fraction (дробь).
	От него наследуют два класса: SimpleFraction (обыкновенная дробь) и MixedFraction (смешанная дробь).
	Обыкновенная дробь имеет только числитель и знаменатель (например, 3/7 или 9/2), а смешанная — еще и целую часть (например, 312 ).
	Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить математические бинарные операторы (+, -, *, /) для выполнения действий с дробями,
	а также унарный оператор (-). Перегрузить логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
	Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.

	*/

#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Fraction
{
private:
	int Numerator;		//числитель
	int Denominator;	//знаменатель
	bool FractionValid;
public:
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
	virtual string get_FractionString() = 0;
};

class SimpleFraction : public Fraction
{
private:

public:
	SimpleFraction(int num, int den) : Fraction(num, den)
	{
		if (get_FractionValid())
		{
			cout << "Simple fraction " << get_Numerator() << "/" << get_Denominator() << endl;
		}
		else
		{
			cout << "Wrong fraction!" << endl;
		}
	}
	string get_FractionString()
	{
		return (to_string(get_Numerator()) + '/' + to_string(get_Denominator()));
	}
	SimpleFraction operator- ()
	{
		int newNumerator = -get_Numerator();
		int newDenominator = get_Denominator();

		return SimpleFraction(newNumerator, newDenominator);
	}
};

class MixedFraction : public Fraction
{
private:
	int WholePart;
public:
	MixedFraction(int whole, int num, int den) : WholePart(whole), Fraction(num, den)
	{
		if (get_FractionValid())
		{
			cout << "Mixed fraction " << WholePart << " (" << get_Numerator() << "/" << get_Denominator() << ")" << endl;
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
	string get_FractionString()
	{
		return (to_string(WholePart) + ' ' + to_string(get_Numerator()) + '/' + to_string(get_Denominator()));
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
};

SimpleFraction operator+ (const SimpleFraction sf1, const SimpleFraction sf2)
{
	int newNumerator = sf1.get_Numerator() * sf2.get_Denominator() + sf2.get_Numerator() * sf1.get_Denominator();
	int newDenominator = sf1.get_Denominator() * sf2.get_Denominator();

	return SimpleFraction(newNumerator, newDenominator);
}
SimpleFraction operator- (const SimpleFraction sf1, const SimpleFraction sf2)
{
	int newNumerator = sf1.get_Numerator() * sf2.get_Denominator() - sf2.get_Numerator() * sf1.get_Denominator();
	int newDenominator = sf1.get_Denominator() * sf2.get_Denominator();

	return SimpleFraction(newNumerator, newDenominator);
}
SimpleFraction operator* (const SimpleFraction sf1, const SimpleFraction sf2)
{
	int newNumerator = sf1.get_Numerator() * sf2.get_Numerator();
	int newDenominator = sf1.get_Denominator() * sf2.get_Denominator();

	return SimpleFraction(newNumerator, newDenominator);
}
SimpleFraction operator/ (const SimpleFraction sf1, const SimpleFraction sf2)
{
	int newNumerator = sf1.get_Numerator() * sf2.get_Denominator();
	int newDenominator = sf1.get_Denominator() * sf2.get_Numerator();

	return SimpleFraction(newNumerator, newDenominator);
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

MixedFraction operator+ (const MixedFraction mf1, const MixedFraction mf2)
{
	int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * mf2.get_Denominator()
		+ (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator()) * mf1.get_Denominator();
	int Denominator = mf1.get_Denominator() * mf2.get_Denominator();
	int WholePart = Numerator / Denominator;
	Numerator = Numerator % Denominator;

	return MixedFraction(WholePart, Numerator, Denominator);
}
MixedFraction operator- (const MixedFraction mf1, const MixedFraction mf2)
{
	int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * mf2.get_Denominator()
		- (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator()) * mf1.get_Denominator();
	int Denominator = mf1.get_Denominator() * mf2.get_Denominator();
	int WholePart = Numerator / Denominator;
	Numerator = Numerator % Denominator;

	return MixedFraction(WholePart, Numerator, Denominator);
}
MixedFraction operator* (const MixedFraction mf1, const MixedFraction mf2)
{
	int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator());
	int Denominator = mf1.get_Denominator() * mf2.get_Denominator();
	int WholePart = Numerator / Denominator;
	Numerator = Numerator % Denominator;

	return MixedFraction(WholePart, Numerator, Denominator);
}
MixedFraction operator/ (const MixedFraction mf1, const MixedFraction mf2)
{
	int Numerator = (mf1.get_WholePart() * mf1.get_Denominator() + mf1.get_Numerator()) * mf2.get_Denominator();
	int Denominator = mf1.get_Denominator() *  (mf2.get_WholePart() * mf2.get_Denominator() + mf2.get_Numerator());
	int WholePart = Numerator / Denominator;
	Numerator = Numerator % Denominator;

	return MixedFraction(WholePart, Numerator, Denominator);
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




int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	SimpleFraction sf1(2, 3);
	SimpleFraction sf2(2, 5);
	SimpleFraction sf3 = sf1 + sf2;
	cout << sf1.get_FractionString() << " + " << sf2.get_FractionString() << " = " << sf3.get_FractionString() << endl;
	sf3 = sf1 - sf2;
	cout << sf1.get_FractionString() << " - " << sf2.get_FractionString() << " = " << sf3.get_FractionString() << endl;
	sf3 = sf1 * sf2;
	cout << sf1.get_FractionString() << " * " << sf2.get_FractionString() << " = " << sf3.get_FractionString() << endl;
	sf3 = sf1 / sf2;
	cout << sf1.get_FractionString() << " / " << sf2.get_FractionString() << " = " << sf3.get_FractionString() << endl;
	sf3 = -sf3;
	cout << sf3.get_FractionString() << endl;

	SimpleFraction sf4(2, 3);
	SimpleFraction sf5(2, 3);
	SimpleFraction sf6(4, 6);
	SimpleFraction sf7(2, 5);
	if (sf4 == sf5)
	{
		cout << sf4.get_FractionString() << " = " << sf5.get_FractionString() << endl;
	}
	if (sf4 == sf6)
	{
		cout << sf4.get_FractionString() << " = " << sf6.get_FractionString() << endl;
	}
	if (sf4 == sf7)
	{
		cout << sf4.get_FractionString() << " = " << sf7.get_FractionString() << endl;
	}

	if (sf4 != sf5)
	{
		cout << sf4.get_FractionString() << " != " << sf5.get_FractionString() << endl;
	}
	if (sf4 != sf6)
	{
		cout << sf4.get_FractionString() << " != " << sf6.get_FractionString() << endl;
	}
	if (sf4 != sf7)
	{
		cout << sf4.get_FractionString() << " != " << sf7.get_FractionString() << endl;
	}

	if (sf4 < sf7)
	{
		cout << sf4.get_FractionString() << " < " << sf7.get_FractionString() << endl;
	}
	if (sf4 > sf7)
	{
		cout << sf4.get_FractionString() << " > " << sf7.get_FractionString() << endl;
	}
	if (sf4 <= sf7)
	{
		cout << sf4.get_FractionString() << " <= " << sf7.get_FractionString() << endl;
	}
	if (sf4 >= sf7)
	{
		cout << sf4.get_FractionString() << " >= " << sf7.get_FractionString() << endl;
	}

	if (sf4 < sf6)
	{
		cout << sf4.get_FractionString() << " < " << sf6.get_FractionString() << endl;
	}
	if (sf4 > sf6)
	{
		cout << sf4.get_FractionString() << " > " << sf6.get_FractionString() << endl;
	}
	if (sf4 <= sf6)
	{
		cout << sf4.get_FractionString() << " <= " << sf6.get_FractionString() << endl;
	}
	if (sf4 >= sf6)
	{
		cout << sf4.get_FractionString() << " >= " << sf6.get_FractionString() << endl;
	}

	if (sf7 < sf6)
	{
		cout << sf7.get_FractionString() << " < " << sf6.get_FractionString() << endl;
	}
	if (sf7 > sf6)
	{
		cout << sf7.get_FractionString() << " > " << sf6.get_FractionString() << endl;
	}
	if (sf7 <= sf6)
	{
		cout << sf7.get_FractionString() << " <= " << sf6.get_FractionString() << endl;
	}
	if (sf7 >= sf6)
	{
		cout << sf7.get_FractionString() << " >= " << sf6.get_FractionString() << endl;
	}

	cout << endl;
	//***********************************************************************************************

	MixedFraction mf1(5, 2, 3);
	MixedFraction mf2(6, 3, 5);
	MixedFraction mf3 = mf1 + mf2;
	cout << mf1.get_FractionString() << " + " << mf2.get_FractionString() << " = " << mf3.get_FractionString() << endl;
	mf3 = mf1 - mf2;
	cout << mf1.get_FractionString() << " - " << mf2.get_FractionString() << " = " << mf3.get_FractionString() << endl;
	mf3 = mf1 * mf2;
	cout << mf1.get_FractionString() << " * " << mf2.get_FractionString() << " = " << mf3.get_FractionString() << endl;
	mf3 = mf1 / mf2;
	cout << mf1.get_FractionString() << " / " << mf2.get_FractionString() << " = " << mf3.get_FractionString() << endl;
	mf3 = -mf3;
	cout << mf3.get_FractionString() << endl;

	MixedFraction mf4(3, 2, 3);
	MixedFraction mf5(3, 2, 3);
	MixedFraction mf6(3, 4, 6);
	MixedFraction mf7(3, 3, 5);
	if (mf4 == mf5)
	{
		cout << mf4.get_FractionString() << " = " << mf5.get_FractionString() << endl;
	}
	if (mf4 == mf6)
	{
		cout << mf4.get_FractionString() << " = " << mf6.get_FractionString() << endl;
	}
	if (mf4 == mf7)
	{
		cout << mf4.get_FractionString() << " = " << mf7.get_FractionString() << endl;
	}

	if (mf4 != mf5)
	{
		cout << mf4.get_FractionString() << " != " << mf5.get_FractionString() << endl;
	}
	if (mf4 != mf6)
	{
		cout << mf4.get_FractionString() << " != " << mf6.get_FractionString() << endl;
	}
	if (mf4 != mf7)
	{
		cout << mf4.get_FractionString() << " != " << mf7.get_FractionString() << endl;
	}

	if (mf4 < mf7)
	{
		cout << mf4.get_FractionString() << " < " << mf7.get_FractionString() << endl;
	}
	if (mf4 > mf7)
	{
		cout << mf4.get_FractionString() << " > " << mf7.get_FractionString() << endl;
	}
	if (mf4 <= mf7)
	{
		cout << mf4.get_FractionString() << " <= " << mf7.get_FractionString() << endl;
	}
	if (mf4 >= mf7)
	{
		cout << mf4.get_FractionString() << " >= " << mf7.get_FractionString() << endl;
	}

	if (mf4 < mf6)
	{
		cout << mf4.get_FractionString() << " < " << mf6.get_FractionString() << endl;
	}
	if (mf4 > mf6)
	{
		cout << mf4.get_FractionString() << " > " << mf6.get_FractionString() << endl;
	}
	if (mf4 <= mf6)
	{
		cout << mf4.get_FractionString() << " <= " << mf6.get_FractionString() << endl;
	}
	if (mf4 >= mf6)
	{
		cout << mf4.get_FractionString() << " >= " << mf6.get_FractionString() << endl;
	}

	if (mf7 < mf6)
	{
		cout << mf7.get_FractionString() << " < " << mf6.get_FractionString() << endl;
	}
	if (mf7 > mf6)
	{
		cout << mf7.get_FractionString() << " > " << mf6.get_FractionString() << endl;
	}
	if (mf7 <= mf6)
	{
		cout << mf7.get_FractionString() << " <= " << mf6.get_FractionString() << endl;
	}
	if (mf7 >= mf6)
	{
		cout << mf7.get_FractionString() << " >= " << mf6.get_FractionString() << endl;
	}

	cout << endl;

	system("Pause");
	return 1;
}