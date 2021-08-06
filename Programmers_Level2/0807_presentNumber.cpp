// Level 2. 숫자의 표현
// https://programmers.co.kr/learn/courses/30/lessons/12924?language=cpp

#include <string>
#include <vector>

using namespace std;

#define MAX 10001

int solution(int n)
{
  int answer = 0;
  int array[MAX] = {
      0,
  };

  int bar = 1;
  for (int num = 1; num <= n; num++)
  {
    for (int idx = bar; idx <= num; idx++)
    {
      array[idx] += num;
      if (array[idx] == n)
      {
        answer++;
        bar = idx;
      }
      else if (array[idx] > n)
        bar = idx;
    }
  }

  return answer;
}