// 17143번. 낚시왕
// https://www.acmicpc.net/problem/17143

#include <iostream>
#include <vector>

using namespace std;

#define DIR 4
#define MAX 100

int dr[DIR] = {-1, 1, 0, 0};
int dc[DIR] = {0, 0, 1, -1};

struct shark
{
  int r, c, s, d, z;
};

int R, C, M;
vector<shark> map[2][MAX][MAX];

int main()
{
  // 0. 입력 및 초기화
  cin >> R >> C >> M;

  int curMap = 0;
  int nextMap = 1;

  int r, c, s, d, z;
  for (int idx = 0; idx < M; idx++)
  {
    cin >> r >> c >> s >> d >> z;

    shark temp;
    temp.d = d - 1;
    temp.r = r - 1;
    temp.c = c - 1;
    temp.z = z;

    if (temp.d == 0 || temp.d == 1)
      temp.s = s % ((R - 1) * 2);
    else
      temp.s = s % ((C - 1) * 2);

    map[curMap][temp.r][temp.c].push_back(temp);
  }

  // 1. 낚시
  int get = 0;
  for (int pos = 0; pos < C; pos++)
  {
    if (!M)
      break;
    // 1-1. 현재 위치에서 가장 가까운 상어 잡기
    for (int row = 0; row < R; row++)
    {
      if (!map[curMap][row][pos].empty())
      {
        get += map[curMap][row][pos][0].z;
        map[curMap][row][pos].pop_back();
        M--;
        break;
      }
    }

    // 1-2. 상어 이동
    for (int row = 0; row < R; row++)
    {
      for (int col = 0; col < C; col++)
      {
        if (!map[curMap][row][col].empty())
        { // 1-2-0. 상어가 있으면
          shark cur = map[curMap][row][col][0];
          map[curMap][row][col].pop_back();

          // 1-2-1. 기존 방향을 따라 이동, 범위를 벗어나면 체크
          int len = cur.s;
          while (len)
          {
            switch (cur.d)
            {
            case 0:
              if (len > cur.r)
              {
                len -= cur.r;
                cur.r = 0;
                cur.d = 1;
              }
              else
              {
                cur.r -= len;
                len = 0;
              }
              break;
            case 1:
              if (len > (R - cur.r - 1))
              {
                len -= (R - cur.r - 1);
                cur.r = R - 1;
                cur.d = 0;
              }
              else
              {
                cur.r += len;
                len = 0;
              }
              break;
            case 2:
              if (len > (C - cur.c - 1))
              {
                len -= (C - cur.c - 1);
                cur.c = C - 1;
                cur.d = 3;
              }
              else
              {
                cur.c += len;
                len = 0;
              }
              break;
            case 3:
              if (len > cur.c)
              {
                len -= cur.c;
                cur.c = 0;
                cur.d = 2;
              }
              else
              {
                cur.c -= len;
                len = 0;
              }
              break;
            }
          }

          if (map[nextMap][cur.r][cur.c].empty()) // 1-2-2. 이동할 위치가 비어있으면
            map[nextMap][cur.r][cur.c].push_back(cur);
          else
          { // 1-2-3. 이동할 위치가 비어있지않으면 상어 수는 감소
            M--;
            if (cur.z > map[nextMap][cur.r][cur.c][0].z)
            { // 1-2-3-1. 현재 상어의 크기가 더 크면 변경
              map[nextMap][cur.r][cur.c].pop_back();
              map[nextMap][cur.r][cur.c].push_back(cur);
            }
          }
        } // 1-2-0. 위치한 상어 이동 완료
      }
    } // 1-2. 이동 완료

    // 1-3. 지도 변경
    curMap = nextMap;
    nextMap = 1 - curMap;
  }

  cout << get << endl;

  return 0;
}