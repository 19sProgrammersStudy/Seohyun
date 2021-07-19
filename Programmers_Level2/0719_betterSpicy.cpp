// Level 2. 더 맵게
// https://programmers.co.kr/learn/courses/30/lessons/42626?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K)
{
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> mix;

  // 1. 우선순위 큐에 집어넣기
  for (int idx = 0; idx < scoville.size(); idx++)
    mix.push(scoville[idx]);

  // 2. 가장 앞의 값이 K보다 작은 동안 반복
  // 2-1. 남은 스코빌 지수가 하나면 -1
  while (mix.top() < K)
  {
    if (mix.size() == 1)
    {
      answer = -1;
      break;
    }

    answer++;

    int newScoville = mix.top();
    mix.pop();
    newScoville += (mix.top() * 2);
    mix.pop();

    // 2-2. 세번째로 작은 스코빌 지수, 새 스코빌 지수가 모두 K이상이면 while문 종료
    if (mix.top() >= K && newScoville >= K)
      break;
    mix.push(newScoville);
  }

  return answer;
}