#ifndef __SALES_DATA__
#define __SALES_DATA__

#include <string>
#include <iostream>

class Sales_data
{
	friend std::istream& operator>> (std::istream& is, Sales_data& rhs);
	friend std::ostream& operator<< (std::ostream& os, const Sales_data& rhs);
public:
	Sales_data() = default;
	double avg_price() const;
private:
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0;
};

std::istream& operator>>(std::istream& is, Sales_data& rhs)
{
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	rhs.revenue = rhs.units_sold * price;
	return is;
}

std::ostream& operator<< (std::ostream& os, const Sales_data& rhs)
{
	os << rhs.bookNo << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price();
	return os;
}

inline double
Sales_data::avg_price() const
{
	if(units_sold)
		return revenue / units_sold;
	return 0;
}

#endif // __SALES_DATA__
