// 풀어도 썩 기분좋지 않은 문제. 설명이 부실함 -_-
// H-index의 최대값을 구하면 통과됨 -_-

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> v) {
   	sort(v.begin(), v.end());
	int ans = -1;
	int mn = v.front();
	int mx = v.back();
	for (int i = 0; i <= 1000; i++) {
		int x = lower_bound(v.begin(), v.end(), i) - v.begin();
		if (v.size() - x >= i && x <= i) ans = i;
	}
    return ans;
}
