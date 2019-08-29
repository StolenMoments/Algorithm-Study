#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define p pair<double, int>
#define mp make_pair
using namespace std;

int reach[501];
int fail[501];

struct cmp {
	bool operator()(p a, p b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
};

vector<int> solution(int N, vector<int> stages) {
    reach[1] = stages.size();
    vector<p> v;
    for(int x : stages) fail[x]++;        
    for(int i = 2; i <= N; i++) reach[i] = reach[i - 1] - fail[i - 1];
    
    
    priority_queue<p, vector<p>, cmp> q;
    for (int i = 1; i <= N; i++) {
        if (reach[i] == 0) q.push(mp(0, i));
        else q.push(mp((double)fail[i] / reach[i], i));
    }
    
    vector<int> ans;
    while (!q.empty()) {
		ans.push_back(q.top().second);
        q.pop();
	}
    
    return ans;
}
