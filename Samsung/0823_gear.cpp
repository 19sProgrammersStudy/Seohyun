// 14891번. 톱니바퀴
// https://www.acmicpc.net/problem/14891

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define GEAR 4
#define TOOTH 8

struct gear
{
  int tooth[TOOTH] = {
      0,
  };
  int rotate = 0;
};

gear gears[GEAR];

void turning()
{
  int current, next;

  for (int g = 0; g < GEAR; g++)
  {
    switch (gears[g].rotate)
    {
    case 0:
      break;
    case 1:
      gears[g].rotate = 0;

      current = gears[g].tooth[0];
      gears[g].tooth[0] = gears[g].tooth[TOOTH - 1];

      for (int idx = 1; idx < TOOTH; idx++)
      {
        next = gears[g].tooth[idx];
        gears[g].tooth[idx] = current;
        current = next;
      }
      break;
    case -1:
      gears[g].rotate = 0;

      current = gears[g].tooth[TOOTH - 1];
      gears[g].tooth[TOOTH - 1] = gears[g].tooth[0];

      for (int idx = TOOTH - 2; idx >= 0; idx--)
      {
        next = gears[g].tooth[idx];
        gears[g].tooth[idx] = current;
        current = next;
      }
      break;
    }
  }
}

int main()
{
  // 0. 톱니 정보 입력
  string inform;
  for (int g = 0; g < GEAR; g++)
  {
    inform = "";
    cin >> inform;
    for (int t = 0; t < TOOTH; t++)
      gears[g].tooth[t] = inform[t] - '0';
  }

  int K;
  cin >> K;

  int gNum, gDir;
  for (int r = 0; r < K; r++)
  {
    // 1. 회전할 톱니바퀴 정보 입력
    cin >> gNum >> gDir;
    gears[gNum - 1].rotate = gDir;

    // 2. 회전할 톱니바퀴의 왼쪽 탐색
    for (int g = gNum - 1; g >= 1; g--)
    {
      if (gears[g].tooth[6] != gears[g - 1].tooth[2])
        gears[g - 1].rotate = -1 * gears[g].rotate;
    }

    // 3. 회전할 톱니바퀴의 오른쪽 탐색
    for (int g = gNum - 1; g + 1 < GEAR; g++)
    {
      if (gears[g].tooth[2] != gears[g + 1].tooth[6])
        gears[g + 1].rotate = -1 * gears[g].rotate;
    }

    // 4. 회전
    turning();
  }

  int answer = 0;
  for (int g = 0; g < GEAR; g++)
  {
    if (gears[g].tooth[0])
      answer += pow(2, g);
  }

  cout << answer << endl;
  return 0;
}