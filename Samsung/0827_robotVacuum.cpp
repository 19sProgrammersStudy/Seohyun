// 14503번. 로봇청소기
// https://www.acmicpc.net/problem/14503

#include <iostream>

using namespace std;

#define DIR 4
#define MAX 51

struct vacuum
{
  int r, c, d;
};

vacuum vac;

int R, C, answer;
int map[MAX][MAX] = {
    0,
};

int dr[DIR] = {-1, 0, 1, 0};
int dc[DIR] = {0, 1, 0, -1};

void cleaning()
{
  bool flag = false;

  while (!flag)
  {
    // 1. 현재 위치를 청소한다
    if (!map[vac.r][vac.c])
    {
      map[vac.r][vac.c] = 2;
      answer++;
    }

    // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색

    int nextDir = vac.d;
    bool cleanPossible = false;
    for (int d = 0; !cleanPossible && d < DIR; d++)
    {
      nextDir = (nextDir - 1 >= 0) ? nextDir - 1 : 3;

      int nextR = vac.r + dr[nextDir];
      int nextC = vac.c + dc[nextDir];

      if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C)
      {
        // 2-1. 왼쪽이 청소 가능 시
        if (!map[nextR][nextC])
        {
          vac.r = nextR;
          vac.c = nextC;
          vac.d = nextDir;
          cleanPossible = true;
          break;
        }
      }
    }

    if (!cleanPossible)
    {
      // 2-3. 네 방향 모두 청소 불가능하고 후진 가능
      int nextR = vac.r + dr[(vac.d + 2) % DIR];
      int nextC = vac.c + dc[(vac.d + 2) % DIR];

      if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && map[nextR][nextC] != 1)
      {
        vac.r = nextR;
        vac.c = nextC;
      }
      // 2-4. 네 방향 모두 청소 불가능하고 후진 불가능
      else
        flag = true;
    }
  }
  return;
}

int main()
{
  // 0. 입력
  cin >> R >> C;
  cin >> vac.r >> vac.c >> vac.d;

  for (int row = 0; row < R; row++)
    for (int col = 0; col < C; col++)
      cin >> map[row][col];

  // 1. 동작
  answer = 0;
  cleaning();

  cout << answer << endl;

  return 0;
}