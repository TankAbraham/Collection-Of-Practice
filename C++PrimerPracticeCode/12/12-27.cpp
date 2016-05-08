//Data structure
#include <string>
#include <set>
#include <unordered_map>
#include <map>

//stream support
#include <sstream>

//io support
#include <iostream>
#include <fstream>

using namespace std;

class ResultSet
{
	friend ostream& operator<<(ostream& os, ResultSet& rs)
	{
		os << rs.word << endl;

		for (auto &e : rs.line)
			cout << "[" << e.first << "] " << e.second << endl;

		return os;
	}

public:
	ResultSet(const string& s)
	{
		word = s;
	}

	void setLine(const unsigned i, const string& s)
	{
		line[i] = s;
	}

private:
	string word;
	map<unsigned, string> line;
};

class TextQuery
{
public:
	void addWord(const string& word, const unsigned lineNumber)
	{
		 table[word].insert(lineNumber);
	}

	void addLine(const string& line, const unsigned lineNumber)
	{
		lines[lineNumber] = line;
	}

	ResultSet* query(const string& word)
	{
		ResultSet *p = new ResultSet(word);

		set<unsigned> &t = table[word];

		for (auto &e : t)
		{
			string &s = lines[e];
			p->setLine(e, s);
		}

		return p;
	}

private:
	unordered_map<string, set<unsigned>> table;
	unordered_map<unsigned, string> lines;
};

void text2Word(istream& is, TextQuery& tq)
{
	unsigned i = 0;
	string word;
	string line;
	istringstream iss;

	while (getline(is, line))
	{
		iss.clear();
		iss.str(line);

		i++;

		if (!iss.str().size())
			continue;

		tq.addLine(iss.str(), i);

		while (iss >> word)
			tq.addWord(word, i);
	}
}

int main(int argc, char *atgv[])
{
	ifstream ifile("data16.dat");

	TextQuery tq;

	text2Word(ifile, tq);

	ResultSet* p = tq.query("Valgrind");

	cout << *p << endl;

	delete p;

	return 0;
}