// 비트마스크, 완전 탐색
// 그냥 비트 갯수 세서 찾는 방식으로 풀이

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i <= 10; i++) if (n & (1 << i)) cnt++;
	for (int i = n + 1; i <= 1000000; i++) {
		int tmp = 0;
		for (int j = 0; j <= 10; j++) if (i & (1 << j)) tmp++;
		if (tmp == cnt) {
			ans = i;
			break;
		}
	}
	return ans;
}
