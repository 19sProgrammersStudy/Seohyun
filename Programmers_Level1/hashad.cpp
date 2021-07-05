// Level 1. 하샤드 수
// https://programmers.co.kr/learn/courses/30/lessons/12947

#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{

  string hashad = to_string(x);
  int sum = 0;
  for (int idx = 0; idx < hashad.size(); idx++)
    sum += hashad[idx] - 48;

  if (x % sum)
    return false;
  else
    return true;
}