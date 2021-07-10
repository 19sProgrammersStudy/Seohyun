// Level 1. 체육복
// https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
  int answer = n;
  vector<int> students(n + 1, 1);

  for (int idx = 0; idx < lost.size(); idx++)
  {
    students[lost[idx]]--;
  }

  for (int idx = 0; idx < reserve.size(); idx++)
  {
    students[reserve[idx]]++;
  }

  for (int idx = 1; idx <= n; idx++)
  {
    if (students[idx])
      continue;

    if (idx - 1 >= 1 && students[idx - 1] == 2)
    {
      students[idx - 1]--;
    }
    else if (idx + 1 <= n && students[idx + 1] == 2)
    {
      students[idx + 1]--;
    }
    else
      answer--;
  }
  return answer;
}