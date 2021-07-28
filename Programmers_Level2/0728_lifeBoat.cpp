// Level 2. 구명보트
// https://programmers.co.kr/learn/courses/30/lessons/42885?language=cpp

// 왜 내림차순을 해야 통과가 될까...?
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
  return (a > b) ? true : false;
}

int solution(vector<int> people, int limit)
{
  int answer = 0;

  deque<int> wait;
  sort(people.begin(), people.end(), compare);

  for (int idx = 0; idx < people.size(); idx++)
    wait.push_back(people[idx]);

  while (!wait.empty())
  {
    int cur = wait.front();
    wait.pop_front();

    if (!wait.empty() && cur + wait.back() <= limit)
      wait.pop_back();
    else if (!wait.empty() && cur + wait.front() <= limit)
      wait.pop_front();

    answer++;
  }
  return answer;
}