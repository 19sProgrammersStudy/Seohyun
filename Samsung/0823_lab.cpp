// 14592번. 연구소
// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

#define MAX 8
#define DIR 4

// virus
int R, C, answer;
int map[MAX][MAX] = {
    0,
};
int map_copy[MAX][MAX];

vector<pair<int, int>> wall;
queue<pair<int, int>> virus;

// diffusion
int dc[DIR] = {1, -1, 0, 0};
int dr[DIR] = {0, 0, 1, -1};

void diffusion()
{
  memcpy(map_copy, map, sizeof(map_copy));
  queue<pair<int, int>> virus_copy = virus;

  while (!virus_copy.empty())
  {
    int row = virus_copy.front().first;
    int col = virus_copy.front().second;

    virus_copy.pop();

    for (int d = 0; d < DIR; d++)
    {
      int nRow = row + dr[d];
      int nCol = col + dc[d];

      if (nRow >= 0 && nRow < R && nCol >= 0 && nCol < C && !map_copy[nRow][nCol])
      {
        map_copy[nRow][nCol] = 2;
        virus_copy.push(make_pair(nRow, nCol));
      }
    }
  }

  int safe = 0;
  for (int row = 0; row < R; row++)
    for (int col = 0; col < C; col++)
      if (map_copy[row][col] == 0)
      {
        safe++;
      }

  if (safe > answer)
    answer = safe;
  return;
}

void dfs(int cIdx, int cnt)
{
  if (cnt == 3)
    return diffusion();

  if (cnt != 3 && cIdx == wall.size())
    return;

  for (int idx = cIdx; idx < wall.size(); idx++)
  {
    map[wall[idx].first][wall[idx].second] = 1;
    dfs(idx + 1, cnt + 1);
    map[wall[idx].first][wall[idx].second] = 0;
  }
}

int main()
{
  cin >> R >> C;

  // 0. 초기화
  answer = 0;
  for (int row = 0; row < R; row++)
  {
    for (int col = 0; col < C; col++)
    {
      cin >> map[row][col];

      if (map[row][col] == 2)
        virus.push(make_pair(row, col));
      else if (map[row][col] == 0)
        wall.push_back(make_pair(row, col));
    }
  }

  // 2. 빈 벽 조합
  for (int idx = 0; idx <= wall.size() - 3; idx++)
  {
    map[wall[idx].first][wall[idx].second] = 1;

    dfs(idx + 1, 1);

    map[wall[idx].first][wall[idx].second] = 0;
  }

  cout << answer << endl;
  return 0;
}