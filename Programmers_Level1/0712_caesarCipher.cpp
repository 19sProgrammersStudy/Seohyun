// Level 1. 시저 암호
// https://programmers.co.kr/learn/courses/30/lessons/12926

// 코드 1
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
  string answer = "";

  // A = 65, Z = 90
  // a = 97, z = 122

  for (int idx = 0; idx < s.size(); idx++)
  {
    if (s[idx] >= 65 && s[idx] <= 90)
    {
      // 대문자인 경우
      if (s[idx] + n > 90)
        answer += (s[idx] + n - 26);
      else
        answer += (s[idx] + n);
    }
    else if (s[idx] >= 97 && s[idx] <= 122)
    {
      // 소문자인 경우
      if (s[idx] + n > 122)
        answer += (s[idx] + n - 26);
      else
        answer += (s[idx] + n);
    }
    else
      answer += s[idx];
  }

  return answer;
}

// 코드 2
#include <string>
#include <vector>

using namespace std;

#define UPPER_S 64
#define UPPER_E 90

#define LOWER_S 96
#define LOWER_E 122

string solution(string s, int n)
{
  string answer = "";

  // A : 65, Z : 90
  // a : 97, z : 122

  for (int idx = 0; idx < s.size(); idx++)
  {
    if (isalpha(s[idx]))
    {
      if (islower(s[idx]))
        (s[idx] + n > 'z') ? answer += LOWER_S + (s[idx] + n) % LOWER_E : answer += s[idx] + n;
      else
        (s[idx] + n > 'Z') ? answer += UPPER_S + (s[idx] + n) % UPPER_E : answer += s[idx] + n;
    }
    else
      answer += s[idx];
  }
  return answer;
}