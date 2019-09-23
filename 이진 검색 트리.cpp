#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int val;
	Node* left, * right;
};

Node heap[100000];
int idx;

Node* make_tree(vector<int>& v, int x, int y) {
	Node* now = &heap[idx++];
	int mid = (x + y) / 2;
	now->val = v[mid];
	if (x != mid) now->left = make_tree(v, x, mid);
	if (mid + 1 != y) now->right = make_tree(v, mid + 1, y);
	return now;
}

void preorder(Node* now) {
	cout << now->val << ' ';
	if (now->left != NULL) preorder(now->left);
	if (now->right != NULL) preorder(now->right);
}

int main() {
	vector<int> v = { 0,1,2,3,4,5,6,7 };
	int sz = v.size();

	Node* root = make_tree(v, 0, sz - 1);
	preorder(root); // 이진 검색 트리 전위 순회 결과 출력
}
