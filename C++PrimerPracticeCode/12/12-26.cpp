#include memory
#include string
#include iostream

using namespace std;

int main()
{
	const int n = 3;

	allocatorstring alloc;
	
	auto const p = alloc.allocate(n);
	string s;
	string q = p;

	while (cin  s  &&  q != p + n)
		alloc.construct(q++, s);

	const size_t size = q - p;

	while( q != p )
		alloc.destroy(--q);

	alloc.deallocate(p, n);

	return 0;
}