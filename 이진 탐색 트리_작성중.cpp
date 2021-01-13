// Binary Search Tree
// 왼쪽 노드는 작은 거, 오른쪽 노드는 큰거
// 노드마다 key 값을 가지고 있다...중복이 없다


// Node Class
template<typename T>
class node {
	// 왼쪽 노드, 오른쪽 노드
private:
	node<T> *left, *right;
	T _value;

public:
	node(T val) {
		_value = val;
	}

	node* get_left() {	return left; }
	node* get_right() { return right; }

	void set_left(node *ptr) {	left = ptr; }
	void set_right(node *ptr) { right = ptr; }
	void set_value(T val) { _value = val; }

	T value() { return _value; }
};


// Binary Search Tree Class
template <typename T>
class bst {
	// root 노드의 정보
private:
	node<T> * root;

	// 삽입 메서드 - 쉬움

	// 탐색 메서드 - 쉬움



	// 삭제 메서드 - 어려움

	// 1. 자식이 없는 노드를 지울 때 - 간단
	// 2. 자식이 하나만 있는 노드를 지울 때 - 간단
	// 3. 자식이 두개 다 있는 노드를 지울 때 - 어려움
	// 3-1. 오른쪽 자식 중에서 가장 작은 값을 삭제 노드로 옮긴다. 이걸 많이 사용한다.
	// 3-2. 왼쪽 자식 중에서 가장 큰 값을 삭제 노드로 옮기낟?

};
