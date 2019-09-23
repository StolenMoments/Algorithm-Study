#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class NODE {
public:
	T x;
	NODE* prev, * next;
};

NODE<int> heap[500000];
int HEAP_IDX;

template<typename T>
class LIST {
private:
	NODE<T>* head, * tail;
	int _size = 0;

public:
	LIST() {
		head = &heap[HEAP_IDX++];
		tail = &heap[HEAP_IDX++];
		head->next = tail;
		tail->prev = head;
	}

	bool empty() {
		return head->next == tail;
	}

	int size() {
		return _size;
	}

	void push_front(T x) {
		_size++;
		NODE<T>* node = &heap[HEAP_IDX++];
		node->x = x;
		head->next->prev = node;
		node->next = head->next;
		node->prev = head;
		head->next = node;
	}

	void push_back(T x) {
		_size++;
		NODE<T>* node = &heap[HEAP_IDX++];
		node->x = x;
		tail->prev->next = node;
		node->next = tail;
		node->prev = tail->prev;
		tail->prev = node;
	}

	void pop_front() {
		if (_size > 0) {
			_size--;
			head->next->next->prev = head;
			head->next = head->next->next;
		}
		else throw out_of_range("list is empty\n");
	}

	void pop_back() {
		if (_size > 0) {
			_size--;
			tail->prev->prev->next = tail;
			tail->prev = tail->prev->prev;
		}
		else throw out_of_range("list is empty\n");
	}

	T front() {
		if (_size == 0) throw out_of_range("list is empty\n");
		return head->next->x;
	}

	T back() {
		if (_size == 0) throw out_of_range("list is empty\n");
		return tail->prev->x;
	}

	void print() {
		NODE<T>* ptr = head->next;
		while (ptr != tail) {
			cout << ptr->x << ' ';
			ptr = ptr->next;
		}
		cout << endl;
	}
};

int main() {
	LIST<int> list;
	list.push_back(3);
	list.push_back(4);
	list.push_back(9);
	list.push_front(11);
	list.push_front(7);

	list.print(); // 7 11 3 4 9 출력

	list.pop_back();
	list.pop_front();

	list.print(); // 11 3 4 출력

	printf("%d %d\n", list.front(), list.back()); // 11 4 출력


	list.pop_front();
	list.pop_front();
	list.pop_front();

	try {
		printf("%d %d\n", list.front(), list.back()); // 리스트가 비었으므로 throw error
	}
	catch (out_of_range e) {
		printf("%s\n", e.what()); // 에러 메시지 출력
	}

	printf("%d\n", list.empty()); // 1 출력

	list.print(); // 공백 출력
}
