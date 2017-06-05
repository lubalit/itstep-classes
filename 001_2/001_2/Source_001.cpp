#include <iostream>
using namespace std;


class Gamer {
private:
	char* _name;
	int _age;
	int _totalFeeds;
	int _okFeeds;
	double _avgFeeds; //средний уровень успешных подач

	void UdpadeAvgFeeds(); //обновление среднего уровня успешных подач
public:
	Gamer(const char* name, const int& age, const int& totafeeds, const int& okfeeds);
	~Gamer() { delete[] _name; }

	void UpdateFeeds(const int& n);
	void UpdateOkFeeds(const int& n);

	double GetAvgFeelds() { return _avgFeeds; };
	void Print() { 
		cout << _name  << " ( % successful feeds: " << _avgFeeds << ") \n";
	}
	void PrintALL() {
		cout << _name << " (" << _age << ",	Successful feeds: " << _okFeeds << ", total feeds : " << _totalFeeds << " ) \n";
	}
};

Gamer::Gamer(const char* name, const int& age, const int& totalfeeds, const int& okfeeds) : _age(0), _totalFeeds(0), _okFeeds(0), _avgFeeds(0){
	int lng = strlen(name) + 1;
	_name = new char[lng];
	strcpy_s(_name, lng, name);

	_age = age;
	_totalFeeds = totalfeeds;
	_okFeeds = okfeeds;
	if (_totalFeeds > 0 && _okFeeds > 0) {
		_avgFeeds = (double)_okFeeds / _totalFeeds;
	}
	_age = age;
	_totalFeeds = totalfeeds;
	_okFeeds = okfeeds;
	if (_okFeeds > 0 && _totalFeeds > 0) { _avgFeeds = (double)_okFeeds / _totalFeeds; }
}

void Gamer::UdpadeAvgFeeds() {
	if (_totalFeeds > 0 & _okFeeds > 0) {
		_avgFeeds = (double)_okFeeds / _totalFeeds;
	}
	else {
		_avgFeeds = 0;
	}
}
void Gamer::UpdateFeeds(const int& n) {
	_totalFeeds = n;
	UdpadeAvgFeeds();
}
void Gamer::UpdateOkFeeds(const int& n) {
	_okFeeds = n;
	UdpadeAvgFeeds();
}



void main() {

	Gamer g1("Name", 35, 10, 5);
	Gamer g2("Name2", 15, 10, 3);
	g2.UpdateFeeds(11);
	g2.UpdateOkFeeds(4);

	g1.Print();
	g2.Print();
	g1.PrintALL();	
	g2.PrintALL();
}