/*
	Задание 2.
	Создать программу, которая бы запрашивала у пользователя строки до тех пор, 
	пока он не введет пустую строку. 
	После этого программа должна вывести список введенных строк в два столбца, 
	первый из которых выровнен по левому краю, а второй — по правому краю.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class TableString
{
private:
	vector<string> tsStrings;
	int tsMaxLength;			//для выравнивания полей
public:
	TableString()
	{
		tsStrings.clear();
	}
	~TableString()
	{
		tsStrings.clear();
	}

	void AddToTable(string str)
	{
		tsStrings.push_back(str);
		if (str.length() > tsMaxLength)
		{
			tsMaxLength = str.length();
		}
	}

	friend ostream& operator<< (ostream& out, TableString ts);
};

ostream& operator<< (ostream& out, TableString ts)
{
	if (ts.tsStrings.size() == 0)
	{
		out << "You don't input any strings :( ";
		return out;
	}

	for (int i = 0; i < ts.tsStrings.size(); i++)
	{
		if (i % 2 == 0)
		{
			out << setw(ts.tsMaxLength) << left << ts.tsStrings[i];
		}
		else
		{
			out << setw(ts.tsMaxLength) << right << ts.tsStrings[i] << endl;
		}		
	}

	return out;
}


int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	TableString ts;

	cout << "Input any number of strings: " << endl;

	string input;

	while (getline(cin, input) && (!input.empty()))
	{
		ts.AddToTable(input);
	}

	cout << ts << endl;

	system("Pause");
	return 1;
}