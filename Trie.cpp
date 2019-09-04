#include <iostream>
using namespace std;

class Node {
public:
	char c;
	int use, finish; // 해당 노드 사용표시(초기화할 때 요긴하게 쓰임), 해당 알파벳이 단어의 끝인지 표시
	Node *child[26]; // 알파벳 소문자는 26개
};

Node heap[10000];
int heapidx;

void add(Node *node, char *str, int idx) {
	if (str[idx] == '\0') {
		node->finish = 1;
		return;
	}
	// 'a'는 아스키 코드값이 97 이므로..
	node->child[str[idx] - 97] = &heap[heapidx++];
	node->child[str[idx] - 97]->use = 1;
	node->child[str[idx] - 97]->c = str[idx];
	add(node->child[str[idx] - 97], str, idx + 1);	
}

bool find(Node *node, char *str, int idx) {
	while (str[idx] != '\0') { //입력받은 스트링의 끝까지 탐색
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
