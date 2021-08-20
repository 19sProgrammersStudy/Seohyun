// Level 2. [3차] n진수 게임
// https://programmers.co.kr/learn/courses/30/lessons/17687?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string changeNotation(int t, int number)
{
  if (!number)
    return "0";

  string result = "";
  while (number)
  {
    if (number % t >= 10)
    {
      char a = 'A' + (number % t) - 10;
      result += a;
    }
    else
      result += to_string(number % t);
    number /= t;
  }
  reverse(result.begin(), result.end());
  return result;
}

string solution(int n, int t, int m, int p)
{
  string answer = "";
  string talk = "";

  // 0. 말할 숫자 구하기
  int number = 0;
  while (talk.size() < t * m)
  {
    talk += changeNotation(n, number);
    number++;
  }

  // 1. 튜브가 말하는 숫자 구하기
  int idx = p - 1;
  while (answer.size() < t)
  {
    answer += talk[idx];
    idx += m;
  }

  return answer;
}