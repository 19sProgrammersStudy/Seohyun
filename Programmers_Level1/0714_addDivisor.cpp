// Level 1. 약수의 합
// https://programmers.co.kr/learn/courses/30/lessons/12928

#include <iostream>

using namespace std;

int solution(int n)
{
  int answer = n;

  for (int idx = 1; idx < n; idx++)
    if (n % idx == 0)
      answer += idx;

  return answer;
}