/*
 * 网易云课堂 算法设计与实践 Queue with Max
 */

#include <iostream>
#include <queue>
#include <initializer_list>

using namespace std;

template<typename T>
class QueueWithMax {
public:
	QueueWithMax(initializer_list<T> il) {
		for (auto e : il)
			this->push(e);
	}

	void push(const T &val) {
		if (mq.empty() || mq.back() < val) {
			mq.push(val);
		}
		rq.push(val);
	}

	void pop() {
		if (rq.front() == mq.front()) {
			mq.pop();
		}
		rq.pop();
	}

	T max() {
		if (!mq.empty())
			return mq.back();
		else if (rq.empty())
			return rq.front();
		else
			return NULL;
	}

	T front() {
		return rq.front();
	}

private:
	queue<T> rq;
	queue<T> mq;
};

int main() {
	QueueWithMax<int> qwm = { 1,2,5,3,4 };

	cout << qwm.front() << endl;
	cout << qwm.max() << endl;

	return 0;
}