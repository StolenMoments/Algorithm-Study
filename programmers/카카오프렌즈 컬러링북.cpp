// DFS 완전 탐색
// 현재 칸과 이동할 칸의 값이 같고 방문하지 않았으면 카운트
// 코드 입력창에 주석으로 달려있듯이 전역 변수를 초기화 해줘야 한다...
// 백준이 그립다


#include <algorithm>
#include <vector>
using namespace std;

int visit[102][102];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxArea = 0;
int cntArea = 0;
int area = 0;
void dfs(int x, int y, vector<vector<int>>& pic) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= pic.size() || yy >= pic[0].size() || xx < 0 || yy < 0) continue;
        if (pic[x][y] == pic[xx][yy] && visit[xx][yy] == 0) {
            visit[xx][yy] = 1;
            area++;
            dfs(xx, yy, pic);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    cntArea = 0;
    maxArea = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        if (picture[i][j] != 0 && visit[i][j] == 0) {
            visit[i][j] = 1;
            cntArea++;
            area = 1;
            dfs(i, j, picture);
            maxArea = max(maxArea, area);
        }
    }
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) visit[i][j] = 0;
    return { cntArea, maxArea };
}
