#include <iostream>
#include <cstring>
#include <string>


using namespace std;

template <typename T>
void print(const T &arr)
{
	for (auto e : arr)
		cout << e;
}

int main(){
	char str[] = "abcd";
	int arr[] = { 1, 2, 3, 4 };

	print(str);
	print(arr);

	return 0;
}