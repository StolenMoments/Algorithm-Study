// 스택 초초초기초
// 스택에 '(' 면 넣고 ')' 면 stk.pop() 해주면 끝

#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    for(char c: s){
        if(c == '(') stk.push(c);
        else if (!stk.empty() && stk.top() == '(') stk.pop();
        else return false;
    }
    return stk.empty();
}
