#include <iostream>
#include <set>
#include <string>
#include <fstream>


using namespace std;

struct Sales_data{
	friend istream& operator>> (const istream&, Sales_data&);
	friend ostream& operator<< (ostream&, const Sales_data&);
	friend bool operator< (const Sales_data&, const Sales_data&);
	
	double price;
	unsigned unit_sold;
	string isbn;
};

ostream& operator<< (ostream& os, const Sales_data& rhs) {
	os << rhs.isbn << " " << rhs.unit_sold  << " " << rhs.price;
	return os;
}

istream& operator>> (istream& is, Sales_data& rhs) {
	is >> rhs.isbn >> rhs.unit_sold >> rhs.price;
	return is;
}

bool operator< (const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn < rhs.isbn;
}

int main() {
	ifstream fin("data2.dat");
	Sales_data temp;
	multiset<Sales_data> bookstore;

	while (fin >> temp){
		bookstore.insert(temp);
	}


	for (auto &e : bookstore)
		cout << e << endl;
	return 0;
}