// 1. 공급일에 일단 큐에 넣고 본다.
// 2. 밀가루가 없을 때 우선순위 큐에서 빼가지고 공급한다.
// 3. k-1 일 까지만 보면 된다.

#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int idx = 0;
    int ans = 0;
    priority_queue<int> q;
    for(int i = 0; i < k; i++){
        if (dates[idx] == i) q.push(supplies[idx++]);
        if (stock == 0){
            stock += q.top();
            q.pop();
            ans++;
        }
        stock--;
    }
    return ans;
}
