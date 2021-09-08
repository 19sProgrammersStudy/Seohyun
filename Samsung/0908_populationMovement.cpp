// 16234번. 인구 이동
// https://www.acmicpc.net/problem/16234

#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;

#define CNT 2
#define DIR 4
#define MAX 50

int N, L, R;
int curMap, nextMap;
int map[CNT][MAX][MAX];
bool visit[MAX][MAX];

int dr[DIR] = {-1, 1, 0, 0};
int dc[DIR] = {0, 0, -1, 1};

int bfs(int r, int c)
{
  // 0. 자료 구조 생성
  vector<pair<int, int>> unions;
  int unionCount = map[curMap][r][c];
  unions.push_back(make_pair(r, c));

  queue<pair<int, int>> visiting;
  visiting.push(make_pair(r, c));

  // 1. 인접한 국가 방문
  while (!visiting.empty())
  {
    int curR = visiting.front().first;
    int curC = visiting.front().second;

    visiting.pop();

    for (int d = 0; d < DIR; d++)
    {
      int nextR = curR + dr[d];
      int nextC = curC + dc[d];

      // 1-1. 지도 안쪽이고 방문하지않았으면
      if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && !visit[nextR][nextC])
      {
        // 1-2. 인구 차이가 L이상 R이하이면
        if (abs(map[curMap][curR][curC] - map[curMap][nextR][nextC]) >= L && abs(map[curMap][curR][curC] - map[curMap][nextR][nextC]) <= R)
        {
          visit[nextR][nextC] = true;
          unionCount += map[curMap][nextR][nextC];
          visiting.push(make_pair(nextR, nextC));
          unions.push_back(make_pair(nextR, nextC));
        }
      }
    }
  }

  // 2. 연합을 구성하는 국가가 1개 이상이면 인구 이동
  if (unions.size() > 1)
  {
    for (int idx = 0; idx < unions.size(); idx++)
    {
      map[nextMap][unions[idx].first][unions[idx].second] = unionCount / unions.size();
    }
    return 1;
  }
  // 2-1. 연합을 구성하는 국가가 1개이면 인구 이동 없음
  else
    return 0;
}

int peopleMove()
{
  // 0. 초기화
  int count = 0;
  int moveCnt = 1;

  // 1. 인구 이동 실행. 인접한 국가를 방문하며 방문하지 않은 나라들에 대하여 체크
  while (moveCnt)
  {
    moveCnt = 0;
    memset(visit, false, sizeof(visit));

    for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
      {
        if (!visit[row][col])
        { // 1-1. 방문하지 않은 나라이면
          visit[row][col] = true;
          moveCnt += bfs(row, col);
        }
      }
    }

    if (moveCnt)
    {
      memcpy(map[curMap], map[nextMap], sizeof(map[curMap]));

      curMap = nextMap;
      nextMap = 1 - curMap;
      count++;
    }
  }

  return count;
}

int main()
{
  // 0. 입력 및 초기화
  cin >> N >> L >> R;

  curMap = 0;
  nextMap = 1 - curMap;
  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
    {
      cin >> map[curMap][row][col];
      map[nextMap][row][col] = map[curMap][row][col];
    }
  }

  // 1. 인구 이동
  int day = peopleMove();

  cout << day << endl;
  return 0;
}