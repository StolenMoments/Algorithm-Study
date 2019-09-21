// DP
// 오른쪽, 아래, 대각으로 이동할 수 있다.
// 대각으로 한 번에 가는 것 보다 오른쪽, 아래를 거쳐서 가는게 이득일 경우가 많을 것. 
// 그래서 대각으로 한 번에 가는 경우는 고려하지 않음.
// 0행, 0열은 어차피 한 방향으로만 갈 수 있으므로 미리 처리를 해둔다.
// D[i][j] = max(D[i - 1][j], D[i][j - 1]) + arr[i][j]


#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int arr[1001][1001];
int D[1001][1001];
int main() {
  sws;
  int N, M;
  cin >> N >> M;
  FOR(i, 0, N) FOR(j, 0, M) cin >> arr[i][j];
  D[0][0] = arr[0][0];
  FOR(i, 1, N) D[i][0] = D[i - 1][0] + arr[i][0];
  FOR(i, 1, M) D[0][i] = D[0][i - 1] + arr[0][i];
  FOR(i, 1, N) FOR(j, 1, M) D[i][j] = max(D[i - 1][j], D[i][j - 1]) + arr[i][j];
  cout << D[N - 1][M - 1];
}
