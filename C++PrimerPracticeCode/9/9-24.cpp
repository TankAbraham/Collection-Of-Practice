#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int > v;
	//v.at(0);	//abort() has been called
	//v[0];		//vector subscript out of range
	//v.front();	//vector iterator not dereferencable
	v.begin();	//�������� �Ż�ֵ���� v.end()
	return 0;
}