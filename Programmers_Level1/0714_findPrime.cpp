// Level 1. 소수 찾기
// https://programmers.co.kr/learn/courses/30/lessons/12921

#include <string>
#include <vector>

using namespace std;

#define MAX 1000000

int solution(int n)
{
  int answer = 0;
  int prime[MAX + 1] = {
      0,
  };

  prime[0] = prime[1] = 1;

  // 에라토스테네스의 체. 소수인 숫자의 배수는 모두 지워버린다
  for (int idx = 2; idx <= n; idx++)
    if (!prime[idx])
    {
      answer++;
      for (int mul = 1; mul * idx <= n; mul++)
        prime[idx * mul] = 1;
    }

  return answer;
}