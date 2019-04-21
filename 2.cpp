/*
	Задание 2.

	Создать класс Person (человек) с полями: имя, возраст, пол и вес.
	Определить методы переназначения имени, изменения возраста и веса.
	Создать производный класс Student (студент), имеющий поле года обучения.
	Определить методы переназначения и увеличения этого значения.
*/

#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Person
{
protected:
	string Name;
	string Gender;
	int Age;
	int Weight;
public:
	Person(string name, string gend, int age, int weight)
		: Name(name), Gender(gend), Age(age), Weight(weight)
	{

	}
	void ReName(string newName)
	{
		Name = newName;
	}
	void ReAge(int newAge)
	{
		Age = newAge;
	}
	void ReWeight(int newWeight)
	{
		Weight = newWeight;
	}

	string GetName()
	{
		return Name;
	}
	string GetGender()
	{
		return Gender;
	}
	int GetAge()
	{
		return Age;
	}
	int GetWeight()
	{
		return Weight;
	}
};

class Student : public Person
{
private:
	int EducationStartYear;
	int CurrentCourse;
public:
	Student(string name, string gend, int age, int weight, int startYear, int course)
		: Person(name, gend, age, weight), EducationStartYear(startYear), CurrentCourse(course)
	{

	}
	void ChangeStartYear(int newStartYear)
	{
		EducationStartYear = newStartYear;
	}
	void GoToNextCourse()
	{
		CurrentCourse++;		
	}

	int GetStartYear()
	{
		return EducationStartYear;
	}
	int GetCourse()
	{
		return CurrentCourse;
	}
};




int main(int argc, char** args)
{
	setlocale(LC_ALL, "Rus");

	Student VasiaLobotryas("Vas`ka", "Male", 19, 50, 2010, 1);

	VasiaLobotryas.GoToNextCourse();
	cout << "Congradulations, " << VasiaLobotryas.GetName() << ", you moved to the next course " << VasiaLobotryas.GetCourse() << "!" << endl;

	VasiaLobotryas.ReName("Vasiliy");
	VasiaLobotryas.GoToNextCourse();
	cout << "Congradulations, " << VasiaLobotryas.GetName() << ", you moved to the next course " << VasiaLobotryas.GetCourse() << "!" << endl;
	
	system("Pause");
	return 1;
}