#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int compare(const string::size_type lhs, const string::size_type rhs) {
	return lhs < rhs; // ���ﲻ���ü�����-������Ȼֻ�����������������ʱ�ŷ���false��ֻ�в���Ⱦͷ���true
}

class CountStr {
public:
	CountStr(const string::size_type len):length(len) {}
	virtual void operator() (
		const string& s, 
			int (*cmp)( // ����ָ����������� int (*cmp)(int, int);   ע��һ���� (*cmp)
				const string::size_type, const string::size_type)) = 0;
	int times = 0;
	string::size_type length;
};

class CountStrBigger : public CountStr {
public:
	using CountStr::CountStr;
	virtual void operator() (
		const string& s,
		int (*cmp)(
			const string::size_type, const string::size_type)) override {
		if (cmp(length, s.size()))
			times++;
	}
};

class CountStrLesser : public CountStr {
public:
	using CountStr::CountStr;
	virtual void operator() (
		const string& s,
		int(*cmp)(
			const string::size_type, const string::size_type)) override {
		if (cmp(s.size(), length))
			times++;
	}
};

int main() {
	ifstream fin("data1.dat");

	vector<string> v;
	string s;
	while (fin >> s) 
		v.push_back(s);

	CountStrLesser csl(10);
	for (auto &e : v)
		csl(e, compare);
	cout << " 1~9���ȵ��ַ������� " << csl.times << endl;
	
	CountStrBigger csb(10);
	for (auto &e : v)
		csb(e, compare);
	cout << "���� > 10 ���ַ������� " << csb.times << endl;

	return 0;
}
