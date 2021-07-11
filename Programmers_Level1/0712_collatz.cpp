// Level 1. 콜라츠 추측
// https://programmers.co.kr/learn/courses/30/lessons/12943

#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
  int answer = 0;

  long long collatz = num;
  while (answer <= 500 && collatz != 1)
  {
    if (collatz % 2 == 0)
      collatz /= 2;
    else
      collatz = collatz * 3 + 1;
    answer++;
  }

  return (answer < 500) ? answer : -1;
}