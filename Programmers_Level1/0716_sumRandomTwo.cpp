// Level 1. 두 개 뽑아서 더하기
// https://programmers.co.kr/learn/courses/30/lessons/68644?language=cpp

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
  vector<int> answer;
  set<int> totals;
  set<int>::iterator iter;

  for (int idx = 0; idx < arr.size(); idx++)
    for (int jdx = idx + 1; jdx < arr.size(); jdx++)
      totals.insert(arr[idx] + arr[jdx]);

  for (iter = totals.begin(); iter != totals.end(); iter++)
    answer.push_back(*iter);

  return answer;
}