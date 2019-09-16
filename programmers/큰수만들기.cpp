/*
큰 수가 맨 앞에 오도록 하되, 문자열 길이와 제거할 수 있는 갯수를 고려해야함.

커스텀 테스트 케이스
"555545555", 4 = "55555"
"444454444", 4 = "54444"
*/



#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string solution(string number, int k) {
    int K = k;
    string answer = "";
    stack<char> stk;
    stk.push(number[0]);
    
    for(int i = 1; i < number.size(); i++){
        if(stk.size() < number.size() - K && (k == 0 || stk.top() >= number[i])) stk.push(number[i]);
        else if (stk.top() < number[i]){
            while(!stk.empty() && stk.top() < number[i] && k > 0 ){
                k--;
                stk.pop();
            }
            stk.push(number[i]);
        }
    }
    
    
    // 리턴할 문자열 만들기
    stack<char> q;
    while(!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
    while(!q.empty()){
        answer.push_back(q.top());
        q.pop();
    }
    
    return answer;
}
