/*
O : 갈색, X : 빨간색

OOOOO
OXXXO
OXXXO
OOOOO

빨간색은 갈색으로 둘러싸여 있다.
그러므로 red = (가로 - 2) * (세로 - 2) 임을 그림으로 알 수 있다.
그리고 brown + red = 가로 * 세로 이므로 
두 식을 가지고 갈색 갯수의 식을 구하면 brown = 2 * (가로 + 세로) - 4

*/



#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> ans;
    int S = brown + red;
    
    //brown = 2(x + y) - 4
    //red = (x - 2)(y - 2)
    for(int i = 3; i <= S; i++){
        if (S % i == 0){
            if ( (i - 2) * (S / i - 2) == red && 2 * (i + S / i) - 4 == brown) {
                ans.push_back(S / i);
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}
