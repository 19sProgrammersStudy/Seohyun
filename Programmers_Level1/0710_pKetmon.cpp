// Level 1. 폰켓몬
// https://programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
  int answer = 0;
  set<int> distinct;

  for (int idx = 0; idx < nums.size(); idx++)
  {
    distinct.insert(nums[idx]);
  }

  if (distinct.size() > nums.size() / 2)
    answer = nums.size() / 2;
  else
    answer = distinct.size();

  return answer;
}