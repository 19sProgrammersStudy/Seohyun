// Level 2. 짝지어 제거하기
// https://programmers.co.kr/learn/courses/30/lessons/12973?language=cpp

#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> pair;
    
    // 1. 첫문자 넣어주기
    pair.push(s[0]);
    
    // 2. stack의 top과 비교
    for(int idx=1; idx<s.size(); idx++) {
        if(pair.empty())
            pair.push(s[idx]);
        else if(pair.top() == s[idx]) {
            pair.pop();
        }
        else
            pair.push(s[idx]);
    }
    
    if(pair.empty())
        return 1;
    else
        return 0;
}