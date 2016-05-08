#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct PrintString {
	string operator() (istream& is) {
		string s;
		if (getline(is, s))
			return s;
		else
			return "";
	}
};

int main() {
	ifstream fin("data7.dat");

	for (int i = 0; i < 4; i++) {
		auto callable = PrintString();
		cout << callable(fin) << endl;
		
	//	第二种表达方式
	//	PrintString ps = PrintString();
	//	cout << ps(fin) << endl;	
	}

	return 0;
}
