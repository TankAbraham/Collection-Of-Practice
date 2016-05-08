#include <iostream>

using namespace std;


template <typename T>
class Screen {
	friend istream& operator>> (istream& in, Screen<T>& s)
	{
		in >> s.width >> s.height;
		return in;
	}

	friend ostream& operator<< (ostream& out, Screen<T>& s)
	{
		out << s.width << " " << s.height;
		return out;
	}

public:
	Screen(const T &w, const T &h) :width(w), height(h) {}
private:
	T width;
	T height;
};

int main() 
{
	Screen<int> s(1, 2);
	
	cin >> s;
	cout << s;

	return 0;
}