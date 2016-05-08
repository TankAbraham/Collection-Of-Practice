#include <vector>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>



using namespace std;

void lineToVector(vector<string> *pv, string& aline) {

	pv->clear();
	string word;
	for (string::size_type i = 0; i < aline.size(); i++) {
		if ((aline[i] >= 'A'  &&  aline[i] <= 'Z')
			|| (aline[i] >= 'a'  &&  aline[i] <= 'z')
			|| (aline[i] >= '0'  &&  aline[i] <= '9'))
		{
			word += aline[i];
		}
		else
		{
			pv->push_back(word);
			word = "";
		}
	}

	aline = "";

}

int main() {
	ifstream fin("data10.dat");
	multimap<string, vector<string>*> m;
	vector<string> *pv = new vector<string>();

	string lastName, firstName, aLine;
	while (getline(fin, lastName)){
		getline(fin, aLine);
		lineToVector(pv, aLine);
		
		//向map中插入元素
		m.insert(
			make_pair(lastName,
				new vector<string>(pv->cbegin(), pv->cend())));
	}

	// 打印 map
	for_each(m.cbegin(), m.cend(), 
		[](const pair<string, vector<string>*>& par)
	{
		cout << par.first << endl;
		for_each(par.second->cbegin(), par.second->cend(),
			[](const string& s)
		{
			cout << s << " ";
		});

		cout << endl;
	});
	

	return 0;
}