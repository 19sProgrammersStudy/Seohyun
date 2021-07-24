// Level 2. JadenCase 문자열 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12951?language=cpp
// 다른 사람 풀이 너무 간단해서 충격

#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
  string answer = "";

  int wIdx = 0;
  for (int idx = 0; idx < s.size(); idx++)
  {
    if (!wIdx && isalpha(s[idx]))
    {
      answer += toupper(s[idx]);
      wIdx++;
    }
    else if (isalpha(s[idx]))
    {
      answer += tolower(s[idx]);
      wIdx++;
    }
    else if (s[idx] == ' ')
    {
      answer += s[idx];
      wIdx = 0;
    }
    else
    {
      answer += s[idx];
      wIdx++;
    }
  }
  return answer;
}