// Level 2. 124 나라의 숫자
// https://programmers.co.kr/learn/courses/30/lessons/12899?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define DIV 3

string solution(int n)
{
  string answer = "";

  if (n == 1)
    answer = "1";
  if (n == 2)
    answer = "2";
  if (n == 3)
    answer = "4";

  // 1. 자리수는 3의 제곱 간격. pow(3, 1)까지는 1자리, 이후 pow(3, 1)부터 pow(3, 2)까지는 2자리..
  // 대략 최대 19자리
  int len = 0;
  int num = n;
  while (num > 0)
  {
    len++;
    num -= pow(3, len);
  }

  while (n && answer.size() < len)
  {
    if (n % DIV == 0)
    {
      answer += "4";
      n--;
    }
    else
      answer += to_string(n % DIV);
    n /= DIV;
  }

  reverse(answer.begin(), answer.end());
  return answer;
}