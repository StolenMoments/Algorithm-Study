// 이분 탐색
// left를 budgets[0] 으로 잡으니 정확성 케이스 9번만 실패했다.
// left, right 때문에 해맸던 문제 -_-

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long D[100002];
int solution(vector<int> budgets, int M) {
    sort(budgets.begin(), budgets.end());
    D[1] = budgets[0];
    for (int i = 1; i < budgets.size(); i++) D[i + 1] = D[i] + budgets[i];
    long long left = 0;
    long long right = budgets.back();
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        int x = lower_bound(budgets.begin(), budgets.end(), mid) - budgets.begin(); // 상한액 이하의 갯수
        int y = budgets.size() - x; // 상한액 넘어가는 갯수

        long long S = y * mid + D[x];

        if (S > M) {
            right = mid - 1;
        }
        else {
            ans = max(ans, mid);
            left = mid + 1;
        }
    }
    return ans;
}
