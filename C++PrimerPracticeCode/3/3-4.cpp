#include <iostream>
#include <string>

using namespace std;

int main()
{
	string w1, w2;
	cin >> w1 >> w2;
	cout << (w1.size() > w2.size() ? w1 : 
		((w1.size() == w2.size())? "equal" : w2)) << endl;

	return 0;
}