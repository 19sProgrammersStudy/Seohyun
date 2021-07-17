// Level 1. 약수의 개수와 덧셈
// https://programmers.co.kr/learn/courses/30/lessons/77884?language=cpp

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right)
{
  int answer = 0;

  int count;
  for (int idx = left; idx <= right; idx++)
  {
    if (idx > 1)
      count = 2;
    else
      count = 1;

    for (int cnt = 2; cnt < idx; cnt++)
      if (idx % cnt == 0)
        count++;

    (count % 2 == 0) ? answer += idx : answer -= idx;
  }
  return answer;
}