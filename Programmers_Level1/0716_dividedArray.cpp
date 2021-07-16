// Level 1. 나누어 떨어지는 숫자 배열
// https://programmers.co.kr/learn/courses/30/lessons/12910?language=cpp

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
  vector<int> answer;

  for (int idx = 0; idx < arr.size(); idx++)
  {
    if (arr[idx] % divisor)
      continue;
    else
      answer.push_back(arr[idx]);
  }

  if (answer.empty())
    answer.push_back(-1);
  else
    sort(answer.begin(), answer.end());

  return answer;
}