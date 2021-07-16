// Level 1. 같은 숫자는 싫어
// https://programmers.co.kr/learn/courses/30/lessons/12906?language=cpp

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
  vector<int> answer;

  answer.push_back(arr[0]);
  for (int idx = 1; idx < arr.size(); idx++)
  {
    if (arr[idx - 1] != arr[idx])
      answer.push_back(arr[idx]);
  }
  return answer;
}