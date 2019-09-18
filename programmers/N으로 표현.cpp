// DP로 풀어보려다 실패해서 완전 탐색으로 풀이...ㅜ
// 1을 더하거나 빼는 경우를 생각해야했음.

#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<ll, int>
using namespace std;
vector<ll> v;
int solution(int N, int number) {
    for (int i = N; i < 100000000; i = i * 10 + N) v.push_back(i);
    int ans = 9;
    for (int i = 0; i < v.size(); i++) {
        queue<pii> q;
        q.push({ v[i], i + 1 });
        while (!q.empty()) {
            int now = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (now == number || cnt > 8) {
                if(now == number) ans = min(ans, cnt);
                continue;
            }           
            q.push({ now + 1, cnt + 2 });
            q.push({ now - 1, cnt + 2 });
            for (int k = 0; k + cnt + 1 < 9; k++) {
                q.push({ now + v[k], cnt + k + 1 });
                q.push({ now - v[k], cnt + k + 1 });
                q.push({ now / v[k], cnt + k + 1 });
                q.push({ now * v[k], cnt + k + 1 });
            }
        }
    }
    return ans >= 9 ? -1 : ans;
}
