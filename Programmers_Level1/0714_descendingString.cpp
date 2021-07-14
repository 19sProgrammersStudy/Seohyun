// Level 1. 문자열 내림차순으로 배치하기
// https://programmers.co.kr/learn/courses/30/lessons/12917

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// A ~ Z : 65 ~ 90
// a ~ z : 97 ~ 122
bool compare(char a, char b)
{
  return a > b;
}

string solution(string s)
{
  sort(s.begin(), s.end(), compare);
  return s;
}