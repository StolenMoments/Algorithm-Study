#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define pii pair<ll, ll>
#define ll long long
#define un unsigned
#define mp(a,b) make_pair(a,b)
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
#define MAX 10000000
#define x first
#define y second
using namespace std;

bool operator<(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int ccw(pii a, pii b, pii c) {
	ll ret = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
	
	return ret >= 0;
}

vector<pii> convex(vector<pii> v){
	vector<pii> up, down;
	for (pii p : v) { // 윗부분 만들기
		while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p)) up.pop_back();
		up.push_back(p);
	}

	reverse(v.begin(), v.end());

	for (pii p : v) { // 아랫부분 만들기
		while (down.size() >= 2 && ccw(down[down.size() - 2], down[down.size() - 1], p)) down.pop_back();
		down.push_back(p);
	}

	for (int i = 1; i < down.size() - 1; i++) up.push_back(down[i]); // 시작, 끝 좌표 제외하고 푸시
  
  return up;
}

int main() {
	sws;
	int N, a, b;
	while (N--) {
		cin >> a >> b;
		v.push_back(mp(a, b));
	}
	sort(v.begin(), v.end());
	v = convex(v); // 볼록 껍질 완성
}
