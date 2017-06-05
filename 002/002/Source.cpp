#include <iostream>
using namespace std;

/*  Реализовать класс Книга (название, год выпуска, кол-во страниц, автор, жанр). Класс Автор (имя, год рождения). Перечисление жанр.

В классах необходимо описать:
++конструкторы по умолчанию,
++с параметрами,
+методы-аксессоры,
++деструкторы.
-Проверить в main. */


class Autor {
private:
	char* _name;
	int _year;
public:
	Autor();
	Autor(const char* name);
	Autor(const char* name, const int& year);
	char* GetName() { return _name; }
	int  GetYear() { return _year; }
	void SetName(const char* name);
	void SetYear(const int& year);
	void SetAutor(const char* name, const int& year);
	~Autor();
};

Autor::Autor() : _name(nullptr), _year(0) {};
Autor::Autor(const char* name) {
	int lng = strlen(name) + 1;
	_name = new char[lng] {};
	strcat_s(_name, lng, name);
	_year = 0;
};
Autor::Autor(const char* name, const int& year) : Autor(name) {
	_year = year;
};


void Autor::SetName(const char* name) {
	int lng = strlen(name) + 1;
	if (_name == nullptr) {
		_name = new char[lng] {};
	}
	strcpy_s(_name, lng, name);
};
void Autor::SetYear(const int& year) {
	_year = year > 0 ? year : 0;
};
void Autor::SetAutor(const char* name, const int& year) {
	int lng = strlen(name) + 1;
	if (_name == nullptr) {
		_name = new char[lng] {};
	}
	strcpy_s(_name, lng, name);
	_year = year > 0 ? year : 0;
};

Autor::~Autor() {
	delete[] _name;
};






class Book {
public:
	enum GENRE { NONE, COMEDY, TRAGEDY, DETECTIVE };
	Book();
	Book(const char* title);
	Book(const char* title, const int& year);
	Book(const char* title, const int& year, const int& quant_page);
	Book(const char* title, const int& year, Autor* autor);
	Book(const char* title, const int& year, const int& quant_page, Autor* autor);
	Book(const char* title, const int& year, const int& quant_page, Autor* autor, GENRE genre);
	char* GetTitle() { return _title; }
	int GetYear() { return _year; }
	int GetGuantPage() { return _quant_page; }
	Autor* GetAutor() { return _autor; }
	GENRE GetGenre() { return _genre; }

	void SetTitle(const char* title);
	void SetYear(const int& year);
	void SetAutor(const char* name, const int& year);
	void SetGenre(const GENRE genre);
	~Book();

private:
	char* _title;
	int _year;
	int _quant_page;
	Autor* _autor;
	GENRE _genre;
};
void Book::SetTitle(const char* title) {
	int lng = strlen(title) + 1;
	if (_title == nullptr) {
		_title = new char[lng] {};
	}
	strcpy_s(_title, lng, title);
};

void Book::SetYear(const int& year) {
	_year = year > 0 ? year : 0;
}

void Book::SetAutor(const char* name, const int& year) {
	if (name != nullptr) { _autor->SetName(name); };
	_autor->SetYear(year);
}

void Book::SetGenre(const GENRE genre) {
	_genre = genre;
}


Book::Book() : _year(0), _quant_page(0), _genre(NONE) {
	_title = new char[1]{};
	strcat_s(_title, 1, "\0");
	_autor = new Autor();
}
Book::Book(const char* title) : Book() {
	int lng = strlen(title) + 1;
	strcpy_s(_title, lng, title);
}
Book::Book(const char* title, const int& year) : Book(title) {
	_year = year;
}
Book::Book(const char* title, const int& year, const int& quant_page) : Book(title, year) {
	_quant_page = quant_page;
}
Book::Book(const char* title, const int& year, const int& quant_page, Autor* autor) : Book(title, year) {
	_quant_page = quant_page;
	_autor->SetAutor(autor->GetName(), autor->GetYear());
}
Book::Book(const char* title, const int& year, Autor* autor) : Book(title, year) {
	_autor->SetAutor(autor->GetName(), autor->GetYear());
}
Book::Book(const char* title, const int& year, const int& quant_page, Autor* autor, GENRE genre) : Book(title, year) {
	_quant_page = quant_page;
	_autor->SetAutor(autor->GetName(), autor->GetYear());
	_genre = genre;
}

Book::~Book() {
	delete[] _title;
}


void main() {
	Autor Moon("MyAutor", 1985);
	cout << "Autor: " << Moon.GetName() << " (" << Moon.GetYear() << ")" << endl;
	Moon.SetName("MoonCasper");
	cout << "Autor: " << Moon.GetName() << " (" << Moon.GetYear() << ")" << endl;

	Autor* Tolstoy = new Autor("Tolstoy", 1589);
	Book book1("Bookmy", 1988, 150, Tolstoy, Book::GENRE::COMEDY);
	cout << "book1: " << book1.GetTitle() << " (" << book1.GetYear() << ")" << endl;
}


