## 그냥 완전 탐색 해보리기~

#include <string>
#include <vector>

using namespace std;

int ans;
int sz;
int tg;
void solve(int now, int idx, vector<int>& numbers){
    if(idx == sz) {
        if(now == tg) ans++;
        return;
    }
    solve(now + numbers[idx], idx + 1, numbers);
    solve(now - numbers[idx], idx + 1, numbers);
}

int solution(vector<int> numbers, int target) {
    tg = target;
    sz = numbers.size();
    solve(0, 0, numbers);
    return ans;
}
