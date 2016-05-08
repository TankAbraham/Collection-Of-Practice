#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct MyData {
	friend ostream& operator<<(ostream&, MyData*);
	MyData(string s);
	MyData(int d, int m, int y) :day(d), month(m), year(y) {};
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

MyData::MyData(string s) {
	if (s[0] >= 'A'  &&  s[0] <= 'Z') {
		// 月份的文字表示
		auto spaceIndex = s.find(" ");
		if ("Jan" == s.substr(spaceIndex))
			this->month = 1;


	}
	else {
		// 数字

	}
}

inline ostream& operator<<(ostream& os, MyData* rhs) {
	os << "year: " << rhs->year << "  month: " << rhs->month << "  day: " << rhs->day;
	return os;
}

int main() {
	ifstream fin("data7.dat");

	vector<MyData*> v;
	string s;
	while (getline(fin, s))
		v.push_back(new MyData(s));

	for (auto &e : v)
		cout << e << endl;

	return 0;
}
