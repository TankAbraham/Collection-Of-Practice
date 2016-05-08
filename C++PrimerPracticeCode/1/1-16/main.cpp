#include <iostream>
#include <vector>
#include <numeric>


using namespace std;

int main()
{
	cout << "间隔用空格或者回车，输入结束用Ctrl + D" << endl;
	vector<int> arr;
	int temp;
	while(cin >> temp)
		arr.push_back(temp);
	
	cout << accumulate(arr.begin(), arr.end(), 0) << endl;
	return 0;
}