#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Sales_data
{
	friend istream& operator>>(istringstream&, Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend bool operator<(const Sales_data&, const Sales_data&);

public:
	Sales_data() = default;
	bool operator==(const Sales_data&);
	void operator+=(const Sales_data&);
	void operator=(const Sales_data&);

private:
	string bookNo;
	unsigned unit_sold = 0;
	double revenue = 0.0;
};

istream& operator>>(istringstream &is, Sales_data &rhs)
{
	double price;
	
	is >> rhs.bookNo >> rhs.unit_sold >> price;

	rhs.revenue = price * rhs.unit_sold;

	return is;
}

ostream& operator<<(ostream& os, const Sales_data& rhs)
{
	os << rhs.bookNo << " " << rhs.unit_sold << " " << rhs.revenue << " " << rhs.revenue / rhs.unit_sold;
	return os;
}

inline bool 
Sales_data::operator==(const Sales_data &rhs)
{
	return this->bookNo == rhs.bookNo ? true : false;
}

inline void
Sales_data::operator+=(const Sales_data& rhs)
{
	this->unit_sold += rhs.unit_sold;
	this->revenue += rhs.revenue;
}

inline void
Sales_data::operator=(const Sales_data& rhs)
{
	this->bookNo = rhs.bookNo;
	this->revenue = rhs.revenue;
	this->unit_sold = rhs.unit_sold;
}

inline bool
operator<(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.bookNo < rhs.bookNo ? true : false;
}

int main(int argc, char *argv[])
{
    ifstream ifile;

    if(argc >= 1)
    	ifile.open(argv[1]);
    else
    {
        cout << "please input the name of .dat" << endl;
        return -1;
    }

	vector<Sales_data> v;
	string s;
	Sales_data sd;

	while (getline(ifile, s))
	{
		istringstream iss(s);
		iss >> sd;
		
		auto it = find(v.begin(), v.end(), sd);

		if (it == v.end())
			v.push_back(sd);
		else
			*it += sd;
	}

	for (auto &e : v)
	{
		cout << e << endl;
	}

	return 0;
}
