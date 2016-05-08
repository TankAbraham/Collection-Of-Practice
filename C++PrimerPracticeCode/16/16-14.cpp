#include <iostream>

using namespace std;


template <typename T>
class Screen {
public:
	Screen(const T &h, const T &w) :height(h), width(w) {}
private:
	T height;
	T width;
};

int main() {
	Screen<int> s(1, 2);
	return 0;
}