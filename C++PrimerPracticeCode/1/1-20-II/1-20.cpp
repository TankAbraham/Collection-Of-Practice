#include "Sales_data.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data2.dat");
	Sales_data item[2];
	fin >> item[0] >> item[1];
	cout << item[0] << endl;
	cout << item[1] << endl;
	return 0;
}