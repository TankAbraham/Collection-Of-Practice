#include <iostream>

int main()
{
	int a, b;
	while (std::cin >> a >> b)
	{
		int min = (a < b) ? a : b;
		int max = (a > b) ? a : b;
		
		while (min != max)
			std::cout << min++ << " ";

		std::cout << max << std::endl;
	}
	return 0;
}
