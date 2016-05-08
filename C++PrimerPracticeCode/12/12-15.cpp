#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
	cout << "open connection" << endl;
	return connection();
}

void disconnection(connection c)
{
	cout << "close connection" << endl;
}

void end_connection(connection *pc)
{
	disconnection(*pc);
}

void foo(destination &d)
{
	cout << "used shared_ptr" << endl;

	connection c = connect(&d);

	//shared_ptr<connection> p(&c, end_connection);
	shared_ptr<connection> p(&c, 
		[](connection *pc) {disconnection(*pc); });

	// end_connection(&c); or not

	cout << endl;
}

int main()
{
	destination d;

	foo(d);

	return 0;
}