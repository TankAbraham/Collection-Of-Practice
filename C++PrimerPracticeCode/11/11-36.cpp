#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

template<typename T1, typename T2>
void PrintMap(const map<T1, T2>& m) {
	cout << "key" << "\t" << "value" << endl;
	for_each(m.cbegin(), m.cend(), 
		[](const pair<T1, T2> par)
	{
		cout << par.first << "->" << par.second << endl;
	});
}

template<typename T>
void printVector(const vector<T> v) {
	for_each(v.cbegin(), v.cend(), 
		[](const T& e) 
	{
		cout << e << "->"; 
	});
}

map<string, string> buildMap(ifstream& fin) {
	map<string, string> trans_map;
	string aLine;

	while (getline(fin, aLine)) {

		// 错误处理，考虑到了空行的情况
		if (aLine.size() == 0)
			continue;
		
		// 如果读到#在行首，说明这行是注释。放弃读取这一行，继续下一行
		if (aLine.find("#") == 0)
			continue;	 

		string::size_type blankPos = aLine.find(" ");
		
		//这里应该进行一下错误处理，比如keyword后面没有value

		trans_map[string(aLine, 0, blankPos)] = aLine.substr(blankPos + 1);

	}
	
	return trans_map;
}

vector<string> buildText(ifstream& fin) {

	vector<string> v;
	string aLine;
	string word;

	while (getline(fin, aLine)) {

		// 错误处理，考虑到了空行的情况
		if (aLine.size() == 0)
			continue;

		// 如果读到#在行首，说明这行是注释。放弃读取这一行，继续下一行
		if (aLine.find("#") == 0)
			continue;

		istringstream iss(aLine);
		while (iss >> word){
			v.push_back(word);
			v.push_back(" ");
		}

		v.push_back(string("\n"));
	}

	return v;
}

void transform(const map<string, string>& m, vector<string>& v) {
	for_each(v.begin(), v.end(), 
		[&m](string& word) mutable 
	{
		auto map_it = m.find(word);
		if (map_it != m.cend())
			word = map_it->second;
	});
}

int main() {
	ifstream fin("data14.dat");
	ifstream fin2("data15.dat");

	map<string, string> transMap = buildMap(fin);

	//PrintMap<string, string>(transMap);

	vector<string> v = buildText(fin2);

	//printVector<string>(v);

	transform(transMap, v);


	// 转换完毕，打印结果
	for_each(v.cbegin(), v.cend(), 
		[](const string& s)
	{
		cout << s ;
	});

	return 0;
}
