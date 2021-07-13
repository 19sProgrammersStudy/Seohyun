// Level 1. 정수 제곱근 판별
// https://programmers.co.kr/learn/courses/30/lessons/12934

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n)
{
  long long temp = sqrt(n);

  if (temp * temp == n)
    return pow(temp + 1, 2);
  else
    return -1;
}