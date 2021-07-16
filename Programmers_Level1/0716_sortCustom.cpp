// Level 1. 문자열 내 마음대로 정렬하기
// https://programmers.co.kr/learn/courses/30/lessons/12915?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
  for (int idx = 0; idx < strings.size(); idx++)
  {
    strings[idx] = strings[idx][n] + strings[idx];
  }

  sort(strings.begin(), strings.end());

  for (int idx = 0; idx < strings.size(); idx++)
  {
    strings[idx] = strings[idx].substr(1, strings[idx].length());
  }
  return strings;
}