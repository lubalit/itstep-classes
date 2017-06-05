#include <iostream>
using namespace std;


/*
a. добавление студентов в группу;
b. удаление студента из группы;
c. модификаци€ данных студента;
d. печать академической группы;
e. сортировка списка студентов;
f. поиск студента по заданному критерию;
g. сохранение списка студентов в файл (при завершении работы
программы);
h. загрузка списка студентов из файла (при старте программы);
i. выход из программы.

ѕри разработке программы следует использовать
-двумерный динамический массив дл€ хранени€ списка студентов,
-одномерный динамический массив указателей на объекты класса Student


*/

class Student {
	char* _name;
	char* _surname;
	int _age;
	char _phone[12];
	double _average;
public:

	Student() : _name(nullptr), _surname(nullptr), _age(0), _phone("\0"), _average(0) {};
	Student(const char* name, const char* surname, int age, const char* phone, double average) : Student() {
		if (_name == nullptr) {
			int lng = strlen(name) + 1;
			_name = new char[lng];
			strcpy_s(_name, lng, name);
		}
		if (_surname == nullptr) {
			int lng = strlen(surname) + 1;
			_surname = new char[lng];
			strcpy_s(_surname, lng, surname);
		}
		_age = age > 0 ? age : 0;
		strcpy_s(_phone, 12, phone); //????
		_average = average;
	};
	~Student() {
		delete[] _name;
		delete[] _surname;
	};
	char* getName() {
		return _name;
	};
	char* getSurname() {
		return _surname;
	};
	int getAge() {
		return _age;
	}
	double getAverage() {
		return _average;
	};

	void setName(const char * name) {
		if (name != nullptr) {
			int lng = strlen(name) + 1;
			if (_name == nullptr) _name = new char[lng];
			strcpy_s(_name, lng, name);
		}
		else {
			delete[] _name;
			_name = nullptr;
		};
	};
	void setSurname(const char * surname) {
		if (surname != nullptr) {
			int lng = strlen(surname) + 1;
			if (_surname == nullptr) _surname = new char[lng];
			strcpy_s(_surname, lng, surname);
		}
		else {
			delete[] _surname;
			_surname = nullptr;
		};
	};

	void setPhone(const char* phone) {
		if (phone != nullptr) {
			strcpy_s(_phone, 12, phone);
		};
	};
	void setAge(int age) {
		_age = age > 0 ? age : 0;
	};

	void setAverage(double average) {
		_average = average;
	};

	/*
	+конструктор копировани€
	char * getPhone();
	*/
};


class AcademyGroup {
	Student** _pSt;
	int _count;

public:
	AcademyGroup() : _pSt(nullptr), _count(0) {};
	~AcademyGroup() {
		if (_pSt != nullptr) {
			delete[] * _pSt;
			delete[] _pSt;
		}
	};

	//void AddStudents();
	//void DeleteStudent();
	//void EditStudent();
	//void Print();
	//void FindStudent();
	//void Sort();
	//void Save();
	//void Load();
};

void main() {

}

