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
