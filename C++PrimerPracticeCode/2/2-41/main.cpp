#include <iostream>

using namespace std;

class Sales_data
{
public:
	Sales_data(string no = "", unsigned u = 0, double r = 0)
	:	bookNo(no), units_sold(u), revenue(r)
	{}
	
	ostream& operator>> const (const ostream& os)
	{
		bookNo = os;
		return os;
	}
	
	ostream& operator<< const (const ostream& os)
	{
		return os << bookNo;
	}
	
private:
	string bookNo;
	unsigned units_sold;
	double revenue;
}

int main()
{
	
	return 0;
}