#ifndef __MY__RANDOM__
#define __MY__RANDOM__

#include <random>

template <typename T>
class MyRandom {
public:
	T operator() (const T &start, const T &end) {
		if (dre) {
			return di(dre);
		}
		else {
			dre = uniform_int_distribution<T> di(start, end);
		}
	}
private:
	static default_random_engine dre;
};

#endif //__MY__RANDOM__