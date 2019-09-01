#include <iostream>
using namespace std;
#define MAX_TABLE 50000

unsigned long hash_func(const char *str) // hash function reference : swexpertacademy.com
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

void cpy(char *str, char *dest) {
	int i = 0;
	while (str[i] != '\0') dest[i] = str[i++];
}

bool cmp(char *str, char *dest) {
	int i = 0;
	while (str[i] != '\0') if (str[i] != dest[i++]) return false;
	return true;
}

class Node {
public:
	char data[10];
	Node *prev, *next;
};

int heapidx;
Node heap[500000];

class List {
public:
	Node *head, *tail;
	List() {
		head = &heap[heapidx++];
		tail = &heap[heapidx++];
		
		head->next = tail;
		tail->prev = head;
	}

	void add(char *str) {
		Node *newnode = &heap[heapidx++];
		cpy(str, newnode->data);

		head->next->prev = newnode;
		newnode->next = head->next;
		newnode->prev = head;
		head->next = newnode;
	}

	bool find(char *str) {
		Node *ptr = head->next;
		while (ptr != tail) {
			if (cmp(str, ptr->data)) return true;
			ptr = ptr->next;
		}
		return false;
	}

};

List table[50000];

int main() {
	char A[10], B[10];
	cin >> A;
	table[hash_func(A)].add(A);

	cin >> B;
	cout << table[hash_func(B)].find(B); //존재하면 1, 없으면 0
}
