#include <iostream>

using namespace std;

istream& foo(istream& is)
{
	int s;

	while (is >> s, !is.eof()) //只有在读入EOF时才结束，流发生错误不结束
	{
		if (is.fail()) 
		{
			//发生错误
			cout << "failed ! please input valid data" << endl;
			is.clear(); //流状态置位
			is.ignore(1, '\n'); //从流中读取并丢弃字符，直到读到 '\n' ；或者读1个字符
		}
		else
			cout << s << endl;
	}
		
	is.clear();

	return is;
}

int main()
{
	foo(cin);

	return 0;
}