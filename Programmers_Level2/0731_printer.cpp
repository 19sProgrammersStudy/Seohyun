// Level 2. 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587?language=cpp

#include <string>
#include <vector>
#include <deque>
using namespace std;

#define MAX 10

struct doc
{
  int order;
  int priority;
};

int solution(vector<int> priorities, int location)
{
  int answer = 0;

  int max = 0;
  int nums[MAX] = {
      0,
  }; // 우선순위 수

  deque<doc> docs;

  for (int idx = 0; idx < priorities.size(); idx++)
  {
    doc temp;
    temp.order = idx;
    temp.priority = priorities[idx];

    nums[temp.priority]++;
    if (temp.priority > max)
      max = temp.priority;

    docs.push_back(temp);
  }

  bool flag = true;

  while (flag)
  {
    if (!nums[max])
      max--;

    if (docs.front().priority == max)
    {
      nums[docs.front().priority]--;
      answer++;

      if (docs.front().order == location)
        flag = false;
      docs.pop_front();
    }
    else
    {
      doc temp = docs.front();
      docs.pop_front();
      docs.push_back(temp);
    }
  }

  return answer;
}