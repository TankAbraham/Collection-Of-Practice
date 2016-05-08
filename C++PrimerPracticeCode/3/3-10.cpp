#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data4.dat");
	
	string words;
	char c;
	while (fin >> c)
	{
		if ((c >= 'a'  &&  c <= 'z') || (c >= 'A'  &&  c <= 'Z'))
			words += c;
	}
	
	cout << words << endl;
	return 0;
}