#ifndef __SALES_DATA__
#define __SALES_DATA__

#include <string>
#include <iostream>
#include <fstream>

class Sales_data
{
	friend std::ifstream& operator>>(std::ifstream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
public:
	Sales_data() = default;
	std::string isbn() const { return bookNo; };

private:
	std::string bookNo;
	unsigned int units_sold;
	float price;
	//double revenue;
};

inline std::ifstream& operator>>(std::ifstream& fin, Sales_data& rhs)
{
	fin >> rhs.bookNo >> rhs.units_sold >> rhs.price;
	return fin;
}

inline std::ostream& operator<<(std::ostream& os, const Sales_data& rhs)
{
	return os << rhs.bookNo << " " << rhs.units_sold << " " << rhs.price;
}

#endif // __SALES_DATA__