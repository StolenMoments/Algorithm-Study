// BOJ 2042번 구간 합 구하기 코드 일부분
// https://www.acmicpc.net/source/18213537

int N, M, K;
ll tree[(1 << 21) + 1];
ll arr[1000002];

ll init(int idx, int left, int right) {
	if (left == right) tree[idx] = arr[left];
	else {
		int mid = (left + right) / 2;
		tree[idx] = init(idx * 2 + 1, left, mid) + init(idx * 2 + 2, mid + 1, right);
	}
	return tree[idx];
}

void update(int target, ll diff, int idx, int st, int ed) {
	if (target < st || target > ed) return;
	tree[idx] += diff; // diff = 새로운 값 - 기존의 값

	if (st != ed) {
		int mid = (st + ed) / 2;
		update(target, diff, idx * 2 + 1, st, mid);
		update(target, diff, idx * 2 + 2, mid + 1, ed);
	}
}

ll query(int idx, int st, int ed, int left, int right) { // 트리 idx, 트리 상의 start, end, 구할 구간의 left, right
	if (st > right || ed < left) return 0;
	if (st >= left && ed <= right) return tree[idx];
	int mid = (st + ed) / 2;
	return query(idx * 2 + 1, st, mid, left, right) + query(idx * 2 + 2, mid + 1, ed, left, right);
}
