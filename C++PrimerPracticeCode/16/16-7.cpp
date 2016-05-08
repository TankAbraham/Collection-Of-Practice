#include <iostream>


using namespace std;

template <typename T, unsigned size>
constexpr unsigned getSize(T (&)[size]) 
{
	return size;
}


int main(){
	char str[] = "abcd";
	int arr[] = { 1, 2, 3, 4 };

	cout << getSize(str);
	cout << getSize(arr);

	return 0;
}