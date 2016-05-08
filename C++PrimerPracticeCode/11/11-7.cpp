#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	ifstream fin("data10.dat");

	map<string, vector<string*>* > familys;

	string s_family;
	string s_members;
	string::size_type pos;
	while (getline(fin, s_family)){
		getline(fin, s_members);

		//familys[s_family] = new vector<string*>();
		pos = 0;
		while ( (pos = s_members.find(' '))  !=  string::npos ){
			//familys[s_family]->push_back(new string(s_members, s_members[pos]));
			string *p = new string(s_members, s_members[pos]);
			cout << *p << " ";
			s_members.erase(pos);
		}
		
	}

	//for (auto &e : familys) {
	//	cout << e.first << endl;
	//}


	return 0;
}
