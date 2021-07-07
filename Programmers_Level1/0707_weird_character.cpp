// Level 1. 이상한 문자 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12930

#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
  string answer = "";

  int w_idx = 0;

  for (int idx = 0; idx < s.size(); idx++)
  {
    if (isalpha(s[idx]))
    {
      (w_idx % 2) == 0 ? answer += toupper(s[idx]) : answer += tolower(s[idx]);
      w_idx++;
    }
    else
    {
      answer += s[idx];
      w_idx = 0;
    }
  }

  return answer;
}