#include <iostream>
using namespace std;

class Gamer {
private:
	char* _name;
	int _age;
	int _totalFeeds;
	int _okFeeds;
	double _avgFeeds; //средний уровень успешных подач

	void UdpadeAvgFeeds() {} //обновление среднего уровня успешных подач
public:
	Gamer(const char* name, int& age, int& totafeeds, int& okfeeds);
	~Gamer() { delete[] _name; }

	void UpdateFeeds(const int& n);
	void UpdateOkFeeds(const int& n);
	double GetAvgFeelds() { return _avgFeeds; };
	void Print() {
		cout <<   " ( % successful feeds: " << _avgFeeds << ") \n";
	}
	void PrintALL() {
		cout <<   " (" << _age << ",	Successful feeds: " << _okFeeds << ", total feeds : " << _totalFeeds << " ) \n";
	}
};

Gamer::Gamer(const char* name, int& age, int& totafeeds, int&  okfeeds) {
	int lng = strlen(name) + 1;
	_name = new char[lng];
	strcpy_s(_name, lng, name);
	if (age > 0) { _age = age; };
	if (totafeeds > 0) { _totalFeeds = totafeeds; };
	if (okfeeds) { _okFeeds = okfeeds; }	
	if (okfeeds > 0 & totafeeds > 0) { _avgFeeds = (double)_okFeeds / _totalFeeds; }
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
	Gamer g1("Ivan", 35, 10, 5);
	Gamer g2("Fedya", 35, 0, 0);
	Gamer g3("Nanak", 35, 10, 5);

	g1.UpdateFeeds(10);
	g2.UpdateOkFeeds(3);

	g1.Print();
	g2.Print();
	g3.PrintALL();
}

