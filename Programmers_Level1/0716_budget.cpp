// Level 1. 예산
// https://programmers.co.kr/learn/courses/30/lessons/12982?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
  sort(d.begin(), d.end());

  int sum = 0;
  int answer = 0;

  for (int idx = 0; idx < d.size(); idx++)
  {
    if (sum + d[idx] <= budget)
    {
      sum += d[idx];
      answer++;
    }
    else
      break;
  }

  return answer;
}