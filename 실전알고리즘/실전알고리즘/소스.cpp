#include <iostream>
using namespace std;

int cols[17];
int cnt = 0;
int N;

bool possi(int depth, int col) {
	for (int i = 1; i < depth; i++) {
		if (abs(i - depth) == abs(col - cols[i])) {
			return false;
		}
		if (cols[i] == col) {
			return false;
		}
	}
	return true;
}
void backtrack(int depth) {
	if (depth == N+1) {
		cnt++;
		return;
	}
	else {
		for (int i = 1; i <= N; i++) {
			cols[depth] = i;
			if (possi(depth, cols[depth])) {
				backtrack(depth + 1);
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		backtrack(1);
		printf("#%d %d\n", i, cnt);
		cnt = 0;
	}
	
}