// Level 1. 두 정수 사이의 합
// https://programmers.co.kr/learn/courses/30/lessons/12912?language=cpp

#include <string>
#include <vector>

using namespace std;

long long sum(int s, int e)
{
  long long result = 0;
  for (int idx = s; idx <= e; idx++)
    result += idx;
  return result;
}

long long solution(int a, int b)
{
  long long answer = 0;

  (a > b) ? answer = sum(b, a) : answer = sum(a, b);

  return answer;
}