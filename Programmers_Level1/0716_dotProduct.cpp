// Level 1. 내적
// https://programmers.co.kr/learn/courses/30/lessons/70128?language=cpp

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
  int answer = 0;

  for (int idx = 0; idx < a.size(); idx++)
    answer += a[idx] * b[idx];

  return answer;
}