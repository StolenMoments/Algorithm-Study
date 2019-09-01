#include <iostream>
using namespace std;

class node {
public:
	int value;
	node *prev, *next;
};

int heap_idx;
node heap[200000]; // 힙 영역에서 할당하는 방식이 동적 할당보다 빠르다. 삼성 B형에서 주로 활용하는 방식.

class LIST {
public:
	node *head, *tail;

	LIST() {
		head = &heap[heap_idx++];
		tail = &heap[heap_idx++];
		head->next = tail;
		tail->prev = head;
	}

	void push_front(int value) {
		node *new_node = &heap[heap_idx++];
		new_node->value = value;

		head->next->prev = new_node;
		new_node->prev = head;
		new_node->next = head->next;
		head->next = new_node;
	}

	void push_back(int value) {
		node *new_node = &heap[heap_idx++];
		new_node->value = value;

		tail->prev->next = new_node;
		new_node->next = tail;
		new_node->prev = tail->prev;
		tail->prev = new_node;
	}

	void pop_front() {
		if (head->next == tail) {
			printf("리스트가 비었습니다.\n");
			return;
		}

		head->next->next->prev = head;
		head->next = head->next->next;
	}

	void pop_back() {
		if (tail->prev == head) {
			printf("리스트가 비었습니다.\n");
			return;
		}

		tail->prev->prev->next = tail;
		tail->prev = tail->prev->prev;
	}
	
	void print() {
		node *cur = head->next;

		while (cur != tail) {
			printf("%d ", cur->value);
			cur = cur->next;
		}
		printf("\n");
	}
};


int main() {
	LIST list;
	list.push_back(3);
	list.push_back(4);
	list.push_back(9);
	list.push_front(11);
	list.push_front(7);

	list.print(); // 7 11 3 4 9 출력

	list.pop_back();
	list.pop_front();

	list.print(); // 11 3 4 출력

	list.pop_front();
	list.pop_front();
	list.pop_front();
	list.pop_back(); // 비었다는 메시지

	list.print(); // 공백 출력
}
