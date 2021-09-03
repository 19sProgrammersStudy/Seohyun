// 14890번. 경사로
// https://www.acmicpc.net/problem/14890

#include <iostream>

using namespace std;

#define MAX 100

int N, L;
int map[MAX][MAX];

int main()
{
  // 0. 입력 및 초기화
  cin >> N >> L;

  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
      cin >> map[row][col];
  }

  // 1. 길 체크
  int answer = 0;

  // 1-1. 행방향 체크
  for (int row = 0; row < N; row++)
  {
    bool isRoad = true;

    int curHeight = map[row][0];
    int curCnt = 1;
    for (int col = 1; col < N; col++)
    {
      if (!isRoad)
        break;
      if (curHeight == map[row][col])
        curCnt++;
      else if (curHeight > map[row][col] && curHeight - map[row][col] == 1)
      { // 1-1-1. 이전 높이가 더 높은 경우
        curHeight = map[row][col];
        curCnt = 1;
        for (int len = 1; len < L; len++)
        {
          if (++col < N && map[row][col] == curHeight)
            curCnt++;
          else
          {
            isRoad = false;
            break;
          }
        }
        if (isRoad)
          curCnt -= L;
      }
      else if (curHeight < map[row][col] && map[row][col] - curHeight == 1)
      { // 1-1-2. 현재 높이가 더 높은 경우
        if (curCnt >= L)
        {
          curHeight = map[row][col];
          curCnt = 1;
        }
        else
        {
          isRoad = false;
          break;
        }
      }
      else
      {
        isRoad = false;
        break;
      }
    }
    if (isRoad)
      answer++;
  }

  // 1-2. 열방향 체크
  for (int col = 0; col < N; col++)
  {
    bool isRoad = true;

    int curHeight = map[0][col];
    int curCnt = 1;
    for (int row = 1; row < N; row++)
    {
      if (!isRoad)
        break;
      if (curHeight == map[row][col])
        curCnt++;
      else if (curHeight > map[row][col] && curHeight - map[row][col] == 1)
      { // 1-1-1. 이전 높이가 더 높은 경우
        curHeight = map[row][col];
        curCnt = 1;
        for (int len = 1; len < L; len++)
        {
          if (++row < N && map[row][col] == curHeight)
            curCnt++;
          else
          {
            isRoad = false;
            break;
          }
        }
        curCnt -= L;
      }
      else if (curHeight < map[row][col] && map[row][col] - curHeight == 1)
      { // 1-1-2. 현재 높이가 더 높은 경우
        if (curCnt >= L)
        {
          curHeight = map[row][col];
          curCnt = 1;
        }
        else
        {
          isRoad = false;
          break;
        }
      }
      else
      {
        isRoad = false;
        break;
      }
    }
    if (isRoad)
      answer++;
  }

  cout << answer << endl;
  return 0;
}