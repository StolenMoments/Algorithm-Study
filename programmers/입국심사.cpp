// 이분 탐색
// long long 으로 안 되길래 unsigned 붙였더니 통과 -_-
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    unsigned long long answer = times.back() * n;
    unsigned long long left = 0;
    unsigned long long right = times.back() * n;

    while(left <= right){

        unsigned long long mid = (left + right) / 2;
        unsigned long long cnt = 0;
        for(int x : times) cnt += mid / x;

        if(cnt < n) left = mid + 1;
        else{
            answer = min(answer, mid);
            right = mid - 1;
        }
    }
    return answer;
}
