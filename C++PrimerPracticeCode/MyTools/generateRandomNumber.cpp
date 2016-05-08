#include <random>

int main() {
	ofstream fout("data6.dat");
	
	default_random_engine dre;
	uniform_real_distribution<double> dr(0, 10);
	for (int i = 0; i < 10; i++)
		fout << dr(dre) << " ";	

	return 0;
}