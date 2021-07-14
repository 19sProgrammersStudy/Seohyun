// Level 1. 문자열 내 p와 y의 개수
// https://programmers.co.kr/learn/courses/30/lessons/12916

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
  int countP = 0;
  int countY = 0;

  for (int idx = 0; idx < s.size(); idx++)
  {
    switch (s[idx])
    {
    case 'p':
    case 'P':
      countP++;
      break;
    case 'y':
    case 'Y':
      countY++;
    }
  }

  if (countP == countY)
    return true;
  else
    return false;
}