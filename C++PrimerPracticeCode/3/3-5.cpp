#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word, str;
	while (cin >> word)
		str += word;
	cout << str << endl;
	
	str = "";
	while (cin >> word)
		str += word + " ";
	cout << str << endl;
	return 0;
}