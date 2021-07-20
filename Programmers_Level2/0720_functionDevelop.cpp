// Level 2. 기능개발
// https://programmers.co.kr/learn/courses/30/lessons/42586?language=cpp

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
  vector<int> answer;
  queue<int> remainDays;

  // 1. 각 기능의 배포까지 남은 작업일 계산
  for (int idx = 0; idx < progresses.size(); idx++)
  {
    int remain = 100 - progresses[idx];

    if (remain % speeds[idx] == 0)
      remainDays.push(remain / speeds[idx]);
    else
      remainDays.push((remain / speeds[idx]) + 1);
  }

  // 2. 남은 작업일이 누적 작업일보다 작으면 배포
  int today = 0;
  int curRelease;
  while (!remainDays.empty())
  {
    // 2-1. 누적 작업일과 이번 배포의 첫번째 기능 필요 작업일 중 큰 값으로 지정
    if (today < remainDays.front())
      today = remainDays.front();

    curRelease = 0;

    do
    {
      curRelease++;
      remainDays.pop();
      if (remainDays.empty())
        break;
    } while (remainDays.front() <= today);
    answer.push_back(curRelease);
  }

  return answer;
}