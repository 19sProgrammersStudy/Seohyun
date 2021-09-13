// 17144번. 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144

#include <iostream>

using namespace std;

#define DIR 4
#define DIV 5
#define MAX 50

struct cleaner
{
  int r = 0;
  int c = 0;
};

cleaner top, bottom;

int dr[DIR] = {-1, 1, 0, 0};
int dc[DIR] = {0, 0, 1, -1};

int R, C, T;
int cur, conf;
int map[2][MAX][MAX];

void diffusion()
{
  // 0. 미세먼지의 확산
  for (int row = 0; row < R; row++)
  {
    for (int col = 0; col < C; col++)
    {
      if (map[cur][row][col] > 0)
      { // 1. 미세먼지가 있는 경우
        int dust = map[cur][row][col];
        map[cur][row][col] = 0;

        int confDir = DIR;
        for (int d = 0; d < DIR; d++)
        {
          int r = row + dr[d];
          int c = col + dc[d];

          // 1-1. 확산이 가능한 경우
          if (r >= 0 && r < R && c >= 0 && c < C && map[conf][r][c] != -1)
            map[conf][r][c] += (dust / DIV);
          else
            confDir--;
        }

        // 1-2. 칸에 남는 양 계산
        map[conf][row][col] += dust - ((dust / DIV) * confDir);
      }
    }
  }
}

void airclean()
{
  // 0. 상단 공기청정기 동작
  for (int row = top.r - 1; row - 1 >= 0; row--)
    map[conf][row][0] = map[conf][row - 1][0];

  for (int col = 0; col + 1 <= C - 1; col++)
    map[conf][0][col] = map[conf][0][col + 1];

  for (int row = 0; row + 1 <= top.r; row++)
    map[conf][row][C - 1] = map[conf][row + 1][C - 1];

  for (int col = C - 1; col - 1 >= 1; col--)
    map[conf][top.r][col] = map[conf][top.r][col - 1];

  map[conf][top.r][top.c + 1] = 0;

  // 1. 하단 공기청정기 동작
  for (int row = bottom.r + 1; row + 1 <= R - 1; row++)
    map[conf][row][0] = map[conf][row + 1][0];

  for (int col = 0; col + 1 <= C - 1; col++)
    map[conf][R - 1][col] = map[conf][R - 1][col + 1];

  for (int row = R - 1; row - 1 >= bottom.r; row--)
    map[conf][row][C - 1] = map[conf][row - 1][C - 1];

  for (int col = C - 1; col - 1 >= 1; col--)
    map[conf][bottom.r][col] = map[conf][bottom.r][col - 1];

  map[conf][bottom.r][bottom.c + 1] = 0;
}

int main()
{
  // 0. 입력 및 초기화
  cin >> R >> C >> T;

  cur = 0;
  conf = 1 - cur;
  for (int row = 0; row < R; row++)
  {
    for (int col = 0; col < C; col++)
    {
      cin >> map[cur][row][col];

      // 0-1. 공기청정기인 경우 top, bottom 구분하여 입력
      if (map[cur][row][col] == -1)
      {
        map[conf][row][col] = -1;
        if (top.r == 0)
        {
          top.r = row;
          top.c = col;
        }
        else
        {
          bottom.r = row;
          bottom.c = col;
        }
      }
    }
  }

  // 1. T초 동안 동작
  for (int t = 0; t < T; t++)
  {
    // 1-1. 미세먼지 확산
    diffusion();

    // 1-2. 공기청정기 동작
    airclean();

    // 1-3. 지도 변경
    cur = conf;
    conf = 1 - cur;
  }

  // 2. 남은 미세먼지 양 구하기
  int answer = 0;
  for (int row = 0; row < R; row++)
  {
    for (int col = 0; col < C; col++)
    {
      if (map[cur][row][col] > 0)
        answer += map[cur][row][col];
    }
  }

  cout << answer << endl;
  return 0;
}