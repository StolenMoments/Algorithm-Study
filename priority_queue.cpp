#include <iostream>
#include <vector>
using namespace std;

#define MAX_HEAP 1000

template<typename T>
class heap {
private:
	T _heap[MAX_HEAP];
	int _size = 0;

public:
	void push(T x) {
		if (_size == MAX_HEAP) {
			cout << "최대 크기 도달\n";
			return;
		}
		_heap[_size] = x;
		int now = _size++;
		while (now != 0 && _heap[(now - 1) / 2] < _heap[now]) {
			swap(_heap[now / 2], _heap[now]);
			now = (now - 1) / 2;
		}
	}

	T pop() {
		if (_size == 0) {
			cout << "비어있음 ";
			return 0;
		}

		_size--;
		int now, ret = _heap[0];

		if (_heap[1] > _heap[2]) {
			_heap[0] = _heap[1];
			_heap[1] = 0;
			now = 1;
		}
		else {
			_heap[0] = _heap[2];
			_heap[2] = 0;
			now = 2;
		}

		while (now < _size) {
			if (_heap[now * 2 + 1] < _heap[now * 2 + 2]) {
				swap(_heap[now * 2 + 2], _heap[now]);
				now = now * 2 + 2;
			}
			else {
				swap(_heap[now * 2 + 1], _heap[now]);
				now = now * 2 + 1;
			}
		}

		return ret;
	}
};


int main() {

	heap<int> pq;
	pq.push(3);
	pq.push(4);
	pq.push(1);
	pq.push(11);
	pq.push(6);

	cout << pq.pop() << endl; // 11
	cout << pq.pop() << endl; // 6
	cout << pq.pop() << endl; // 4
	cout << pq.pop() << endl; // 3
	cout << pq.pop() << endl; // 1
	cout << pq.pop() << endl; // 비어있음 0


	pq.push(144);
	pq.push(1156);
	pq.push(77);
	pq.push(150);

	cout << pq.pop() << endl; // 1156
	cout << pq.pop() << endl; // 150
	cout << pq.pop() << endl; // 144
	cout << pq.pop() << endl; // 77
	cout << pq.pop() << endl; // 비어있음 0

}
