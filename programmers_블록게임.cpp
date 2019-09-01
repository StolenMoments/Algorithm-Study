#include <string>
#include <vector>
#define FOR(i,a,b) for(int i = a; i < b; i++)
using namespace std;

bool check_line(vector<vector<int>> &bod, int x, int y) { //y 까지 장애물이 없나?
	FOR(i, 0, x) if (bod[i][y] != 0) return false;
	return true;
}

bool check(vector<vector<int>> &bod, int x, int y) {
	if (x + 1 < bod.size() && y + 2 < bod.size() && bod[x][y + 1] == 0 && bod[x][y + 2] == 0 && bod[x][y] == bod[x + 1][y] && bod[x + 1][y] == bod[x + 1][y + 1] && bod[x + 1][y + 1] == bod[x + 1][y + 2] && check_line(bod, x, y + 1) && check_line(bod, x, y + 2)) { //type 1
		bod[x][y] = bod[x + 1][y] = bod[x + 1][y + 1] = bod[x + 1][y + 2] = 0;
		return true;
	}

	if (y - 1 >= 0 && y + 1 < bod.size() && x + 1 < bod.size() && bod[x][y - 1] == 0 && bod[x][y + 1] == 0 && bod[x][y] == bod[x + 1][y - 1] && bod[x + 1][y - 1] == bod[x + 1][y] && bod[x + 1][y] == bod[x + 1][y + 1] && check_line(bod, x, y - 1) && check_line(bod, x, y + 1)) { //type 1
		bod[x][y] = bod[x + 1][y - 1] = bod[x + 1][y] = bod[x + 1][y + 1] = 0;
		return true;
	}

	if (y - 2 >= 0 && x + 1 < bod.size() && bod[x][y - 2] == 0 && bod[x][y - 1] == 0 && bod[x][y] == bod[x + 1][y] && bod[x + 1][y] == bod[x + 1][y - 1] && bod[x + 1][y - 1] == bod[x + 1][y - 2] && check_line(bod, x, y - 2) && check_line(bod, x, y - 1)) { //type 3
		bod[x][y] = bod[x + 1][y] = bod[x + 1][y - 1] = bod[x + 1][y - 2] = 0;
		return true;
	}

	if (x + 2 < bod.size() && y + 1 < bod.size() && bod[x][y + 1] == 0 && bod[x + 1][y + 1] == 0 && bod[x][y] == bod[x + 1][y] && bod[x + 1][y] == bod[x + 2][y] && bod[x + 2][y] == bod[x + 2][y + 1] && check_line(bod, x, y + 1)) {
		bod[x][y] = bod[x + 1][y] = bod[x + 2][y] = bod[x + 2][y + 1] = 0;
		return true;
	}

	if (x + 2 < bod.size() && y - 1 >= 0 && bod[x][y - 1] == 0 && bod[x + 1][y - 1] == 0 && bod[x][y] == bod[x + 1][y] && bod[x + 1][y] == bod[x + 2][y] && bod[x + 2][y] == bod[x + 2][y - 1] && check_line(bod, x, y - 1)) {
		bod[x][y] = bod[x + 1][y] = bod[x + 2][y] = bod[x + 2][y - 1] = 0;
		return true;
	}

	return false;
}


int solution(vector<vector<int>> board) {
	int ans = 0;
  int cnt = 3;
  while(cnt--) FOR(i, 0, board.size()) FOR(j, 0, board[0].size()) if (board[i][j] != 0) ans += check(board, i, j);
  return ans;
}
