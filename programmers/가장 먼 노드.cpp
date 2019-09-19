// 다익스트라
// 노드에서 노드로 가는 비용을 1로 잡고 다익스트라 돌린다.
// 가장 비싼 곳이 가장 먼 곳이므로, 비용이 가장 많이 드는 곳을 세면 된다.

#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int D[20001];

struct cmp{
    bool operator()(pii a, pii b){
        return a.second > b.second;
    }

};

int solution(int n, vector<vector<int>> arr) {
    vector<int> edge[20001];
    for(int i = 2; i <= n; i++) D[i] = 20000000;
    D[1] = 0;
    for(int i = 0; i < arr.size(); i++){
        edge[arr[i][0]].push_back(arr[i][1]);
        edge[arr[i][1]].push_back(arr[i][0]);
    }
    
    priority_queue<pii, vector<pii>, cmp> q;
    q.push({1,0});
    int mx = 0;
    while(!q.empty()){
        int now = q.top().first;
        int cnt = q.top().second;
        q.pop();
        for(int next : edge[now]){
            if (D[next] > cnt + 1) {
                D[next] = cnt + 1;
                mx = max(D[next], mx);
                q.push({next, D[next]});
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i <= n; i++) if (D[i] == mx) cnt++;
    return cnt;
}
