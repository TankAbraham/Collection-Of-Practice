#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>
#include <iostream>


using namespace std;

struct PrintMultimap{
	void operator() (const pair<string, string> par) {
		cout << par.first << " ";
		cout << par.second << endl;
	}
};

void booksToMultimap(const string& books, string& author, multimap<string, string>& m) {
	
	string bookName;
	for (string::size_type i = 0; i < books.size(); i++) {
		if (books[i] == ' ')
		{
			m.insert({ author, bookName });
			bookName = "";
		}
		else
			bookName += books[i];
	}

	m.insert({ author, bookName });

}

int main() {
	ifstream fin("data13.dat");

	multimap<string, string> authorBooksMap;
	string books, author;

	while (getline(fin, author)){
		getline(fin, books);
		booksToMultimap(books, author, authorBooksMap);
	}

	for_each(authorBooksMap.cbegin(), 
		authorBooksMap.cend(), 
		bind(PrintMultimap(), placeholders::_1));


	string key = "王平";	// 如果data13.dat中名字行中有空格会被一起读入map，所以查找时返回找不到
	multimap<string, string>::iterator it = authorBooksMap.find(key);
	auto numBooks = authorBooksMap.count(key);

	if (!numBooks)
		cout << "not found " << key << endl;

	while (numBooks) {
		cout << it->second << " ";
		++it;
		--numBooks;
	}
	

	return 0;
}