// Level 2. 피보나치 수
// https://programmers.co.kr/learn/courses/30/lessons/12945?language=cpp
// int.. 범위...

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 100001
#define DIV 1234567

int solution(int n)
{
  int fibonacci[MAX] = {
      0,
  };

  fibonacci[1] = 1;

  for (int idx = 2; idx <= n; idx++)
    fibonacci[idx] = (fibonacci[idx - 1] + fibonacci[idx - 2]) % DIV;

  return fibonacci[n];
}