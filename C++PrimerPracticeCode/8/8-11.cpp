#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo
{
	friend ostream& operator<<(ostream&, const PersonInfo&);
	string name;
	vector<string> phone;
};

ostream& operator<<(ostream &os, const PersonInfo& info)
{
	os << info.name << " ";

	for (auto &e : info.phone)
		os << e << " ";

	return os;
}

int main()
{
	ifstream ifile("data17.dat");
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while (getline(ifile, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		
		record >> info.name;

		while (record >> word)
			info.phone.push_back(word);

		people.push_back(info);
	}

	for (auto &e : people)
		cout << e << endl;

	return 0;
}