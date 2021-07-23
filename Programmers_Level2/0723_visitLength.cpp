// Level 2. 방문 길이
// https://programmers.co.kr/learn/courses/30/lessons/49994?language=cpp

#include <string>

using namespace std;

#define MAX 11

struct point
{
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
};

point map[MAX][MAX];

int solution(string dirs)
{
  int answer = 0;

  // 1. 게임 캐릭터의 초기 위치
  int x = 5;
  int y = 5;

  // 2. dirs 길이만큼 반복
  for (int idx = 0; idx < dirs.size(); idx++)
  {
    // 2-1. 다음 위치 계산
    // 현재 위치에서 이동하고자 하는 방향 방문 체크
    // 이동하는 위치에서 현재 위치로 이동하는 방향 방문 체크
    switch (dirs[idx])
    {
    case 'U':
      if (y - 1 >= 0)
      {
        if (!map[y][x].up && !map[y - 1][x].down)
        {
          map[y][x].up = map[y - 1][x].down = true;
          answer++;
        }
        y--;
      }
      break;
    case 'D':
      if (y + 1 < MAX)
      {
        if (!map[y][x].down && !map[y + 1][x].up)
        {
          map[y][x].down = map[y + 1][x].up = true;
          answer++;
        }
        y++;
      }
      break;
    case 'R':
      if (x + 1 < MAX)
      {
        if (!map[y][x].right && !map[y][x + 1].left)
        {
          map[y][x].right = map[y][x + 1].left = true;
          answer++;
        }
        x++;
      }
      break;
    case 'L':
      if (x - 1 >= 0)
      {
        if (!map[y][x].left && !map[y][x - 1].right)
        {
          map[y][x].left = map[y][x - 1].right = true;
          answer++;
        }
        x--;
      }
      break;
    }
  }
  return answer;
}