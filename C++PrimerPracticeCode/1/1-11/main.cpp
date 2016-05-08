#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	
	pair<int, int> minMaxPair;
	while(1)
	{
		int num1, num2;
		
		cout << "please give two numbers as the scope" << endl;
		cin >> num1 >> num2;
		
		minMaxPair.first = min(num1, num2);
		minMaxPair.second = max(num1, num2);
		
		//cout << minMaxPair.first << " " << minMaxPair.second << endl;
		
		while(minMaxPair.first != minMaxPair.second)
			cout << minMaxPair.first++ << "  ";
		
		cout << minMaxPair.second << endl;
	}
	
	return 0;
}
