#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ifstream ifile("data16.dat");
	vector<string> v;
	string s, word;

	while (getline(ifile, s))
	{
		istringstream line(s);
		
		while(line >> word)
			v.push_back(word);
	}
		

	for (auto e : v)
		cout << e << endl;

	return 0;
}