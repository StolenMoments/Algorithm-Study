// Binary Search Tree
// 왼쪽 노드는 작은 거, 오른쪽 노드는 큰거
// 노드마다 key 값을 가지고 있다...중복이 없다


// Node Class
class node {
private:
	node* left, * right, * parent;
	int _value;

public:
	node* get_left() { return left; }
	node* get_right() { return right; }
	node* get_parent() { return parent; }

	void set_left(node* ptr) { 
		left = ptr;
		if (ptr) left->parent = this;
	}
	void set_right(node* ptr) { 
		right = ptr;
		if (ptr) right->parent = this;
	}

	void set_value(int val) { _value = val; }

	int value() { return _value; }
};


// Binary Search Tree Class
class bst {
private:
	node* root;

	void _inorder(node* now) {
		if (now == nullptr) return;
		_inorder(now->get_left());
		cout << now->value() << ' ';
		_inorder(now->get_right());
	}

	node* _find_node(int value) {
		node* now = root;

		while (true) {
			if (now->value() == value) return now;
			else if (now->value() < value && now->get_right() != nullptr) {
				now = now->get_right();
			}
			else if (value < now->value() && now->get_left() != nullptr) {
				now = now->get_left();
			}
			else break;
		}

		throw new exception("그럴리 없는 Exception");
	}

public:
	bst() {
		root = new node();
	}

	node* get_root() {
		return root;
	}


	void inorder() {
		_inorder(root);
	}


	bool find(int value) {
		node *now = root;

		while (true) {
			if (value == now->value()) {
				return true;
			}
			else if (value > now->value() && now->get_right() != nullptr) {
				now = now->get_right();
			}
			else if (value < now->value() && now->get_left() != nullptr) {
				now = now->get_left();
			}
			else return false;
		}
	}
	

	void insert(int value) {
		if (root->value() == NULL) {
			root->set_value(value);
			return;
		}
		
		node* now = root;
		counter++;

		while (true) {
			if (value == now->value()) {
				return;
			}
			else if (value > now->value() && now->get_right() != nullptr) {
				counter++;
				now = now->get_right();
			}
			else if (value < now->value() && now->get_left() != nullptr) {
				counter++;
				now = now->get_left();
			}
			else break;
		}

		if (now->value() > value) {
			now->set_left(new node());
			now = now->get_left();
			now->set_value(value);
			return;
		}

		now->set_right(new node());
		now = now->get_right();
		now->set_value(value);
	}


	void remove(int value) {
		if (!find(value)) return;

		node *find_node = _find_node(value);

		// 1. 자식이 없는 노드를 지울 때
		if (find_node->get_left() == nullptr && find_node->get_right() == nullptr) {
			if (find_node->get_parent()->get_left() == find_node) {
				find_node->get_parent()->set_left(nullptr);
			}
			else if (find_node->get_parent()->get_right() == find_node) {
				find_node->get_parent()->set_right(nullptr);
			}
		}
		// 2. 자식이 하나만 있는 노드를 지울 때 - 왼쪽만 있음
		else if (find_node->get_left() != nullptr && find_node->get_right() == nullptr) {
			//find_node가 부모의 왼쪽인지 오른쪽인지 알아야 할 듯
			if (find_node->get_parent()->get_left() == find_node) {
				find_node->get_parent()->set_left(find_node->get_left());
			}
			else if (find_node->get_parent()->get_right() == find_node) {
				find_node->get_parent()->set_right(find_node->get_left());
			}
		}
		// 2. 자식이 하나만 있는 노드를 지울 때 - 오른쪽만 있음
		else if (find_node->get_left() == nullptr && find_node->get_right() != nullptr) {
			if (find_node->get_parent()->get_left() == find_node) {
				find_node->get_parent()->set_left(find_node->get_right());
			}
			else if (find_node->get_parent()->get_right() == find_node) {
				find_node->get_parent()->set_right(find_node->get_right());
			}
		}
		// 3. 자식이 둘 다 있을 때... 오른쪽 서브트리 중에서 가장 작은 값을 삭제 노드로 옮긴다.
		else {
			node* now = find_node->get_right();

			while (now->get_left() != nullptr) {
				now = now->get_left();
			}

			// now의 parent와 now의 right를 연결시킨다.
			if (now->get_parent()->get_left() == now) {
				now->get_parent()->set_left(now->get_right());
			}
			else if (now->get_parent()->get_right() == now) {
				now->get_parent()->set_right(now->get_right());
			}
			// now를 find_node로 이동시켜 find_node의 left, right와 연결한다.
			now->set_left(find_node->get_left());
			now->set_right(find_node->get_right());
			
			if (find_node != root && find_node->get_parent()->get_left() == find_node) {
				find_node->get_parent()->set_left(now);
			}
			else if (find_node != root && find_node->get_parent()->get_right() == find_node) {
				find_node->get_parent()->set_right(now);
			}
		}
	}
};

