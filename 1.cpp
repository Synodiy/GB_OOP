/*
	Задание 1.

	Добавить в контейнерный класс, который был написан в этом уроке,
	функцию для удаления последнего элемента массива (аналог функции pop_back() в векторах).
	Подсказка: сначала напишите функцию удаления любого элемента в массиве. 
	Также напишите функцию для добавления другого массива в любое место исходного. 
	Реализуйте функцию сортировки элементов массива.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "ArrayInt.h"

using namespace std;

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");
	ArrayInt arr(10);
	
	for (int i = 0; i < arr.GetLength(); i++)
	{
		arr[i] = i * 2;
	}

	arr.Print();
	cout << endl;

	arr.DeleteItem(8);
	arr.Print();
	cout << endl;

	arr.InsertBefore(100, 8);
	arr.Print();
	cout << endl;

	arr.PushBack(210); 
	arr.Print();
	cout << endl;

	arr.PopBack();
	arr.Print();
	cout << endl;

	int testArray[] = { 11, 22, 33, 44, 55 };
	arr.InsertArray(testArray, 5, arr.GetLength() - 2);
	arr.Print();
	cout << endl;

	arr.Sort();
	arr.Print();
	cout << endl;

	system("Pause");
	return 1;
}