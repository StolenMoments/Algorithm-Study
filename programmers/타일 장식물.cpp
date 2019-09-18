// DP
// 타일 갯수에 따른 둘레를 보면 규칙이 보인다.
// 타일 1개 : 4, 타일 2개 : 6, 타일 3개 : 10, 타일 4개 : 16
// 타일 N개 둘레 = 타일 N - 1개 둘레 + 타일 N - 2개 둘레

#include <vector>
using namespace std;

long long D[90];
long long solution(int N) {
    D[1] = 4;
    D[2] = 6;
    for(int i = 3; i <= N; i++) D[i] = D[i - 1] + D[i - 2];
    return D[N];
}
