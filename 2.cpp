/*
	Задание 2.

	Создайте контейнерный класс, реализующий модель очереди. В нем должны быть методы:
	void push(int x); // добавить элемент х в конец очереди
	int size(); // узнать количество элементов в очереди
	int front(); // вернуть первый элемент в очереди
	int back(); // вернуть последний элемент в очереди
	void pop(); // удалить первый элемент в очереди
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "QueueInt.h"

using namespace std;

int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");
	
	QueueInt myQueue; // создаем пустую очередь

	// добавили в очередь несколько элементов
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	cout << "Количество элементов в очереди: " << myQueue.size();
	cout << "\nВот первый: " << myQueue.front() << "\nВот последний: " << myQueue.back();

	myQueue.pop();     // удаляем один элемент в очереди
	cout << "\nКоличество элементов в очереди: " << myQueue.size();
	cout << "\nВот первый: " << myQueue.front() << "\nВот последний: " << myQueue.back();

	cout << endl;

	system("Pause");
	return 1;
}