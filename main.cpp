/*
2. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date.
Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date,
а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. Затем переместите ресурс,
которым владеет укзаатель today в указатель date.
Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
3. По условию предыдущей задачи создайте два умных указателя date1 и date2.
** Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение происходит по датам).
Функция должна вернуть более позднюю дату.
** Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <assert.h>
#include <time.h>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date()
		: day (1), month(1), year(2000)
	{
		
	}
	Date(int d, int m, int y)
	{
		assert(d > 0 && d < 32);
		assert(m > 0 && m < 13);
		assert(y > 1900 && y < 2100);

		day = d;
		month = m;
		year = y;
	}

	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}

	friend ostream& operator<< (ostream& out, Date date);
};

ostream& operator<< (ostream& out, Date date)
{
	out << date.day << "." << date.month << "." << date.year;

	return out;
}

Date CompareDates(unique_ptr<Date> &d1, unique_ptr<Date> &d2)
{
	if (d1->getYear() > d2->getYear())
	{
		return *d1;
	}
	else if (d2->getYear() > d1->getYear())
	{
		return *d2;
	}
	else
	{
		if (d1->getMonth() > d2->getMonth())
		{
			return *d1;
		}
		else if (d2->getMonth() > d1->getMonth())
		{
			return *d2;
		}
		else
		{
			if (d1->getDay() > d2->getDay())
			{
				return *d1;
			}
			else 
			{
				return *d2;
			}
		}
	}
}

void ReplaceDates(unique_ptr<Date> &d1, unique_ptr<Date> &d2)
{
	unique_ptr<Date> temp;

	temp = move(d1);
	d1 = move(d2);
	d2 = move(temp);
}

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);	   	

	unique_ptr<Date> today(new Date(tim->tm_mday, tim->tm_mon + 1, tim->tm_year + 1900));
	unique_ptr<Date> date;

	cout << "today is " << today->getDay() << ":" << today->getMonth() << ":" << today->getYear() << endl;
	cout << "again " << *today << endl;

	date = move(today);

	if (today)
	{
		cout << "today is not empty" << endl;
		cout << "today = " << *today << endl;
	}
	else
	{
		cout << "today is empty" << endl;
	}

	if (date)
	{
		cout << "date is not empty" << endl;
		cout << "date = " << *date << endl;
	}
	else
	{
		cout << "date is empty" << endl;
	}

	cout << endl;

	unique_ptr<Date> date1(new Date(10, 6, 2010));
	unique_ptr<Date> date2(new Date(20, 2, 2010));

	cout << CompareDates(date1, date2) << " is latest from dates: " << *date1 << " and " << *date2 << endl;

	ReplaceDates(date1, date2);
	cout << "first date : " << *date1 << endl;
	cout << "second date : " << *date2 << endl;

	system("Pause");
	return 1;
}