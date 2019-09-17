// DP
// 왼쪽, 위쪽, 대각쪽 칸의 정사각형의 길이를 확인해서 현재 칸의 정사각형 길이를 정하는 방식

#include <vector>
#include <algorithm>
using namespace std;

int D[1002][1002];
int solution(vector<vector<int>> board){
	int ans = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (i == 0 || j == 0 || board[i][j] == 0) D[i][j] = board[i][j]; // 0행 또는 0열은 무조건 0 아니면 1
			else D[i][j] = 1 + min(D[i - 1][j], min(D[i][j - 1], D[i - 1][j - 1]));
            		ans = max(ans, D[i][j]);
		}
	}
  	return ans * ans;
}
