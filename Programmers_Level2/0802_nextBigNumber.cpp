// Level 2. 다음 큰 숫자
// https://programmers.co.kr/learn/courses/30/lessons/12911?language=cpp

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define MAX 1000000

bool oneInBinary(int number, int oneCount)
{
  int one = 0;
  while (number)
  {
    if (number % 2)
      one++;
    number /= 2;
  }

  if (one == oneCount)
    return true;
  else
    return false;
}

int solution(int n)
{
  int answer = 0;
  int minimum = n;

  // 1. n을 이진수로 변환하며 1의 개수 세기
  int oneCount = 0;

  while (n)
  {
    if (n % 2)
      oneCount++;
    n /= 2;
  }

  // 2. n+1부터 MAX까지 이진변환해보기
  for (int idx = minimum + 1; idx <= MAX; idx++)
    if (oneInBinary(idx, oneCount))
    {
      answer = idx;
      break;
    }

  return answer;
}