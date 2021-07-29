// Level 2. 예상 대진표
// https://programmers.co.kr/learn/courses/30/lessons/12985?language=cpp

#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
  int answer = 0;
  int round = n / 2;
  while (a != b)
  {
    answer++;

    (a % 2 == 0) ? a /= 2 : a = (a / 2) + 1;
    (b % 2 == 0) ? b /= 2 : b = (b / 2) + 1;
  }

  return answer;
}