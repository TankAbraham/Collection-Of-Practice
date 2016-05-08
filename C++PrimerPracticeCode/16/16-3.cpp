#include <iostream>


using namespace std;

struct Sales_data {

};


template<typename T>
int compare(const T &lhs, const T &rhs)
{
	if (less<T>()(lhs, rhs))
		return 1;
	if (less<T>()(rhs, lhs))
		return -1;
}

int main(){
	Sales_data sd1, sd2;
	cout << compare(sd1, sd2);
	return 0;
}