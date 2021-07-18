// Level 1. 실패율
// https://programmers.co.kr/learn/courses/30/lessons/42889?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
  if (a.second == b.second)
    return a.first < b.first;
  else
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
  vector<int> answer;

  // 사용자 스테이지
  vector<int> user_stage(N, 0);
  for (int idx = 0; idx < stages.size(); idx++)
  {
    if (stages[idx] <= N)
      user_stage[stages[idx] - 1]++;
  }

  // 실패율 구하기
  double user = stages.size();
  vector<pair<int, double>> failureRate(N, {0, 0.0});

  for (int idx = 0; idx < N; idx++)
  {
    failureRate[idx].first = idx + 1;
    if (user && user_stage[idx])
    {
      failureRate[idx].second = user_stage[idx] / user;
    }
    user -= user_stage[idx];
  }

  // 정렬하기
  sort(failureRate.begin(), failureRate.end(), compare);

  for (int idx = 0; idx < N; idx++)
    answer.push_back(failureRate[idx].first);
  return answer;
}