// Level 1. 소수 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12977

#include <vector>
#include <iostream>
#include <cmath>
#include <iostream>
using namespace std;

#define MAX 3

int answer = 0;
vector<int> numbers;

bool isPrime(int num)
{
  bool flag = true;
  for (int idx = 2; idx <= sqrt(num); idx++)
  {
    if (num % idx == 0)
    {
      flag = false;
      break;
    }
  }
  return flag;
}

void dfs(int cur, int cnt, int sum)
{
  if (cnt == 3)
  {
    if (isPrime(sum))
      answer++;
    return;
  }

  for (int idx = cur + 1; idx < numbers.size() - MAX + cnt + 1; idx++)
  {
    dfs(idx, cnt + 1, sum + numbers[idx]);
  }
}

int solution(vector<int> nums)
{
  numbers = nums;

  for (int idx = 0; idx < nums.size() - MAX + 1; idx++)
  {
    dfs(idx, 1, nums[idx]);
  }

  return answer;
}