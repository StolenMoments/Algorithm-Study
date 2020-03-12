#include <iostream>
#include <algorithm>
#include <queue>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int N, M, a, b;
int deg[1002];
int ans[1002];
vector<int> edge[1002];
vector<int> topo;

int main() {
	sws;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		edge[a].push_back(b);
		deg[b]++; // 차수를 기록해둔다
	}

	queue<int> q;
	FOR(i, 1, N + 1) if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		topo.push_back(now);
		for (int next : edge[now]) {
			deg[next]--;
			if (deg[next] == 0) q.push(next); // 차수가 0이 됐으면 큐에 넣기
		}
	}

	FOR(i, 0, N) {
		int now = topo[i];
		ans[now]++;
		for (int next : edge[now]) ans[next] = max(ans[now], ans[next]); // 다음 노드에 가기 위한 시간을 갱신
	}

	FOR(i, 1, N + 1) cout << ans[i] << ' ';
}
