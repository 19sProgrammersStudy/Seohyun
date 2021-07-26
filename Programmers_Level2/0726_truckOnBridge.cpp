// Level 2. 다리를 지나는 트럭
// https://programmers.co.kr/learn/courses/30/lessons/42583?language=cpp#

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct truck
{
  int weight;
  int time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
  int answer = 1;

  // 1. waiting 큐 초기화
  queue<truck> waiting;
  for (int idx = 0; idx < truck_weights.size(); idx++)
  {
    truck temp;
    temp.weight = truck_weights[idx];
    waiting.push(temp);
  }

  // 2. 다리 지나기
  int total_weight = 0;
  int truckCnt = truck_weights.size();

  queue<truck> onbridge;
  while (truckCnt)
  {
    if (onbridge.empty())
    {
      // 2-1. 비어있으면 weight 내에서 다리 위에 올리기
      while (!waiting.empty() && onbridge.size() < bridge_length && total_weight + waiting.front().weight <= weight)
      {
        total_weight += waiting.front().weight;
        waiting.front().time = answer++;
        onbridge.push(waiting.front());
        waiting.pop();
      }
    }

    if (!onbridge.empty())
    {
      // 2-2. 비어있지않고 더 올라갈 수 없으면 가장 앞의 트럭 빼기
      // 현재 시간과 트럭이 빠지는 시간 중 큰 값으로 현재 시간 유지...... 한참 헤맴
      if (answer < onbridge.front().time + bridge_length)
        answer = onbridge.front().time + bridge_length;
      total_weight -= onbridge.front().weight;
      onbridge.pop();
      truckCnt--;

      // 2-3. 비어있지않고 더 올라갈 수 있으면 올리기
      while (!waiting.empty() && onbridge.size() < bridge_length && total_weight + waiting.front().weight <= weight)
      {
        total_weight += waiting.front().weight;
        waiting.front().time = answer++;
        onbridge.push(waiting.front());
        waiting.pop();
      }
    }
  }
  return answer;
}