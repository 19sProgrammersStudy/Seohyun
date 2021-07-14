// Level 1. 정수 내림차순으로 배치하기
// https://programmers.co.kr/learn/courses/30/lessons/12933

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool com(char a, char b)
{
  return a > b;
}

long long solution(long long n)
{
  string numbers = to_string(n);
  sort(numbers.begin(), numbers.end(), com);

  return stol(numbers);
}