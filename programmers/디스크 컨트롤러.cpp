// 우선 순위 큐, 연결 리스트
// 작업 시간이 최소인 것을 우선적으로 하되, 경과 시간 안에 있는 것을 우선적으로 작업하는 방식.
// 리스트 중간에 있는 작업을 지워야 하므로 연결 리스트 사용

#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#define pii pair<int, int>
using namespace std;

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<pii, vector<pii>, cmp> q;
    list<pii> lst;
    for (int i = 0; i < jobs.size(); i++) q.push({ jobs[i][0], jobs[i][1] });

    while (!q.empty()) {
        lst.push_back(q.top());
        q.pop();
    }

    list<pii>::iterator it = lst.begin();
    int time = 0;
    int total = 0;
    while (!lst.empty()) {
        list<pii>::iterator it = lst.begin();       
        for (; it != lst.end(); it++) {
            if (it->first <= time) { // 경과 시간 안에 있으면 작업 수행
                total += (time - it->first) + it->second;
                time += it->second;
                lst.remove({ it->first, it->second });
                break;
            }
            if (it->first == lst.back().first && it->second == lst.back().second) time++; // 만족하는 작업이 없으면 시간 증가
        }
    }
    return total / jobs.size();
}
