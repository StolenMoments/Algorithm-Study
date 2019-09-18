// DFS
// 탐색하고 체크해주고 새로운 네트워크를 찾기 시작할 때 카운트 해주면 된다.

#include <vector>
using namespace std;


int visit[201];
int sz;
void dfs(int x, vector<vector<int>>& com){
    for(int i = 0; i < sz; i++){
        if(com[x][i] == 1 && visit[i] == 0){
            visit[i] = 1;
            dfs(i, com);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    sz = n;
    int answer = 0;
    for(int i = 0; i < sz; i++){
        if(visit[i] == 0) {
            answer++;
            visit[i] = 1;
            dfs(i, computers);
        }
    }
    return answer;
}
