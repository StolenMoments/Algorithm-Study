#include <iostream>
using namespace std;

class Node {
public:
	char c;
	int use, finish;
	Node *child[26];
};

Node heap[10000];
int heapidx;

void add(Node *node, char *str, int idx) {
	if (str[idx] == '\0') {
		node->finish = 1;
		return;
	}
	node->child[str[idx] - 97] = &heap[heapidx++];
	node->child[str[idx] - 97]->use = 1;
	node->child[str[idx] - 97]->c = str[idx];
	add(node->child[str[idx] - 97], str, idx + 1);	
}

bool find(Node *node, char *str, int idx) {
	while (str[idx] != '\0') {
		if (node->child[str[idx] - 97] == nullptr) return false;
		node = node->child[str[idx] - 97];
		idx++;
	}
	return node->finish == 1;
}


int main() {
	Node *head = &heap[heapidx++];
	char str[10];
	cin >> str;
	add(head, str, 0);

	cin >> str;
	cout << find(head, str, 0);

}
