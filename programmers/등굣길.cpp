// DP
// (1,1) 에서 가로 세로 경로 훝고 (2,2) 에서 가로 세로 경로 훑고 (3,3) 에서 가로 세로 경로 훑고...
// 고등학교에서 경로 셀 때 썼던 방식

#include <vector>

using namespace std;

long long D[102][102];
long long mod = 1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {

    for (int i = 0; i < puddles.size(); i++) D[puddles[i][0]][puddles[i][1]] = -1;
    D[1][1] = 1;
    for (int i = 1; i <= min(m, n); i++) {
        if (D[i][i] != -1 && D[i - 1][i] != -1) D[i][i] = (D[i][i] + D[i - 1][i]) % mod;
        if (D[i][i] != -1 && D[i][i - 1] != -1) D[i][i] = (D[i][i] + D[i][i - 1]) % mod;
        for (int j = i + 1; j <= n; j++) {
            if (D[i][j] == -1) continue;
            if (D[i - 1][j] != -1) D[i][j] = (D[i][j] + D[i - 1][j]) % mod;
            if (D[i][j - 1] != -1) D[i][j] = (D[i][j] + D[i][j - 1]) % mod;
        }

        for (int j = i + 1; j <= m; j++) {
            if (D[j][i] == -1) continue;
            if (D[j - 1][i] != -1) D[j][i] = (D[j][i] + D[j - 1][i]) % mod;
            if (D[j][i - 1] != -1) D[j][i] = (D[j][i] + D[j][i - 1]) % mod;
        }
    }

    return D[m][n];
}
