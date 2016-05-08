#include <iostream>
#include <functional>
#include <vector>

using namespace std;

struct CompareStrategy {
	virtual void operator() (const string& s, const unsigned int val, unsigned int& times) = 0;
	virtual ~CompareStrategy() {};
};

struct EqualStrategy : public CompareStrategy {
	virtual void operator() (const string& s, const unsigned int val, unsigned int& times) {
		if (s.size() == val)
			times++;
	}
};

struct GreaterStrategy : public CompareStrategy {
	virtual void operator() (const string& s, const unsigned int val, unsigned int& times) {
		if (s.size() > val)
			times++;
	}
};

struct LesserStrategy : public CompareStrategy {
	virtual void operator() (const string& s, const unsigned int val, unsigned int& times) {
		if (s.size() < val)
			times++;
	}
};

struct Context {
	CompareStrategy *strategy;
	unsigned int times = 0;
	unsigned int val = 0;
	void operator() (const string& s) {
		strategy->operator() (s, val, times);
	}
	Context(char type, int v) : val(v) {  
		switch (type)	// 简单工厂模式
		{
		case 'e': // equal
			strategy = new EqualStrategy();
			break;
		case 'g': // greater
			strategy = new GreaterStrategy();
			break;
		case 'l': // lesser
			strategy = new LesserStrategy();
			break;
		default:
			cout << "不存在该方法" << endl;
			exit(-1);
			break;
		}
	}
};

int main() {
	vector<string> v{ "1", "12", "123", "1234" };

	Context c1('e', 3);
	Context c2('g', 3);
	Context c3('l', 3);

	for (auto &e : v) {
		c1(e);
		c2(e);
		c3(e);
	}

	cout << c1.times << endl;
	cout << c2.times << endl;
	cout << c3.times << endl;
	return 0;
}