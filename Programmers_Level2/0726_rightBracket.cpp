// Level 2. 올바른 괄호
// https://programmers.co.kr/learn/courses/30/lessons/12909?language=cpp

#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
  stack<char> bracket;

  for (int idx = 0; idx < s.size(); idx++)
  {
    if (s[idx] == '(')
      bracket.push(s[idx]);
    else
    {
      if (!bracket.empty() && bracket.top() == '(')
        bracket.pop();
      else
        bracket.push(s[idx]);
    }
  }

  if (bracket.empty())
    return true;
  else
    return false;
}