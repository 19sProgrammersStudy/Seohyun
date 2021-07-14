// Level 1. 문자열 다루기 기본
// https://programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(string s)
{
  if (s.size() != 4 && s.size() != 6)
    return false;

  for (int idx = 0; idx < s.size(); idx++)
    if (!isdigit(s[idx]))
      return false;

  return true;
}