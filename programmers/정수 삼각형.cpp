// DP
// 현재 칸으로 이동할 수 있는 직전의 두 칸 중에서 최대값을 가져와 더하는 방식
// 첫번째 열과 마지막 열은 올 수 있는 경로가 하나 이므로 따로 처리

#include <vector>

using namespace std;

int D[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    D[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        int ed = triangle[i].size() - 1;
        D[i][0] = D[i - 1][0] + triangle[i][0];
        D[i][ed] = D[i - 1][ed - 1] + triangle[i][ed];
        for(int j = 1; j < ed; j++) D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + triangle[i][j];
    }
    
    int ed = triangle.size() - 1;
    for(int i = 0; i <= ed; i++) answer = max(answer, D[ed][i]);
    
    return answer;
}
