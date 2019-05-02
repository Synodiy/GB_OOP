#ifndef _PAIR_H
#define _PAIR_H

#include <string>

template <typename T>
class Pair1
{
private:
	T el1;
	T el2;
public:
	Pair1(T e1, T e2)
		: el1(e1), el2(e2)
	{

	}
	~Pair1()
	{

	}
	T first() const
	{
		return el1;
	}
	T second() const
	{
		return el2;
	}
};

template <typename T1, typename T2>
class Pair
{
private:
	T1 el1;
	T2 el2;
public:
	Pair(T1 e1, T2 e2)
		: el1(e1), el2(e2)
	{

	}
	~Pair()
	{

	}
	T1 first() const
	{
		return el1;
	}
	T2 second() const
	{
		return el2;
	}
};


template <typename T1, typename T2 = string>
class StringValuePair : public Pair<T2, T1>
{
public:
	StringValuePair(T2 el1, T1 el2)
		: Pair<T2, T1>(el1, el2)
	{

	}
};

/* 1й нерабочий вариант
template <typename T2>
class StringValuePair : public Pair<string, T2>
{
public:
	StringValuePair(string el1, T2 el2)
		: Pair<string, T2>(el1, el2)
	{

	}
};*/




/* 2й нерабочий вариант
template <typename T1, typename T2>
class StringValuePair: public Pair<T1, T2>
{

};
template <typename T2>
class StringValuePair<T2>: public Pair<string, T2>
{
public:
	StringValuePair(string el1, T2 el2)
		: Pair<string, T2>(el1, el2)
	{

	}
};*/


#endif 
