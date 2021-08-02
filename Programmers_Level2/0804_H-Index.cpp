// Level 2. H-Index
// https://programmers.co.kr/learn/courses/30/lessons/42747?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
  return a > b;
}

int solution(vector<int> citations)
{
  int answer = 0;
  sort(citations.begin(), citations.end(), comp);

  int idx = 0;
  while (citations[idx] >= idx + 1)
    idx++;

  answer = idx;
  return answer;
}