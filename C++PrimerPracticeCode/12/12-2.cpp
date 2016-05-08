#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class StrBlob{
public:
	typedef vector<string>::size_type size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	string& front() const;
	string& back() const;
	size_type size() const { return this->data->size(); }	
	//添加和删除元素
	void push_back(string s) { this->data->push_back(s); }
	void pop_back() { this->data->pop_back(); }
private:
	shared_ptr<vector<string>> data;
	void check(size_type, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const {
	if (i >= this->size())
		throw out_of_range(msg);
}

string& StrBlob::front() const {
	check(0, "在空的StrBlob上取首元素");
	return this->data->front(); 
}

string& StrBlob::back() const {
	check(0, "在空的StrBlob上取尾元素");
	return this->data->back(); 
}

int main(){
	StrBlob a({ "a", "ab", "abc" });

	a.push_back("abcd");
	cout << a.front() << a.back() << a.size();
	
	a.pop_back();
	cout << a.back() << a.size();
	
	return 0;
}