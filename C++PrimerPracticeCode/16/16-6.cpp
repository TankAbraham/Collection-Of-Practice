#include <iostream>


using namespace std;

template <typename T, unsigned size>
T* begin(const T (&arr)[size])
{
	return arr;
}

template<typename T, unsigned size>
T* end(const T (&arr)[size])
{
	return arr + size;
}

int main(){
	char str[] = "abcd";
	int arr[] = { 1, 2, 3, 4 };

	cout << *begin(str);
	cout << *(end(arr) - 1);

	return 0;
}