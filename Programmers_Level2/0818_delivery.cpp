// Level 2. 배달
// https://programmers.co.kr/learn/courses/30/lessons/12978?language=cpp

#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

#define MAX 51

int map[MAX][MAX];
int dist[MAX];

queue<pair<int, int>> village;

void getDistance(int N)
{
  while (!village.empty())
  {
    int from = village.front().first;
    int len = village.front().second;
    village.pop();

    for (int to = 1; to <= N; to++)
    {
      if (from == to)
        continue;

      // 1. 갈 수 있는 경우
      if (map[from][to] != -1)
      {
        if (dist[to] == -1)
        {
          // 1-1. 방문하지 않은 경우
          dist[to] = len + map[from][to];
          village.push(make_pair(to, dist[to]));
        }
        else if (dist[to] != -1 && dist[to] > len + map[from][to])
        {
          // 1-2. 방문했으나 길이가 더 긴 경우
          dist[to] = len + map[from][to];
          village.push(make_pair(to, dist[to]));
        }
      }
    }
  }
}

int solution(int N, vector<vector<int>> road, int K)
{
  int answer = 0;

  // 0. 초기화
  memset(map, -1, sizeof(map));
  memset(dist, -1, sizeof(dist));

  // 1. map 입력
  for (int vil = 0; vil < road.size(); vil++)
  {
    if (map[road[vil][0]][road[vil][1]] == -1)
    {
      // 1-1. 도로가 없으면 바로 업데이트
      map[road[vil][0]][road[vil][1]] = map[road[vil][1]][road[vil][0]] = road[vil][2];
    }
    else if (map[road[vil][0]][road[vil][1]] > road[vil][2])
    {
      // 1-2. 도로가 있으면 짧은 길이로 업데이트
      map[road[vil][0]][road[vil][1]] = map[road[vil][1]][road[vil][0]] = road[vil][2];
    }
  }

  // 2. 자기 마을의 거리는 0!
  for (int from = 1; from <= N; from++)
    map[from][from] = 0;

  // 3. 마을 1부터 BFS로 거리 구하기
  map[1][1] = dist[1] = 0;
  village.push(make_pair(1, 0));
  getDistance(N);

  // 4. 구한 마을 거리 중 K 시간 이하인 마을 수 구하기
  for (int vil = 1; vil <= N; vil++)
    if (dist[vil] != -1 && dist[vil] <= K)
      answer++;

  return answer;
}