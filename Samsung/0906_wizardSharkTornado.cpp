// 20057번. 마법사 상어와 토네이도
// https://www.acmicpc.net/problem/20057

#include <iostream>
#include <cmath>

using namespace std;

#define DIR 4
#define MAX 499

int N, answer;
int map[MAX][MAX];

int dr[DIR] = {0, 1, 0, -1};
int dc[DIR] = {-1, 0, 1, 0};

struct tornado
{
  int r, c;
  int dir = 0;
};

tornado current;

bool isMap(int row, int col, int len)
{
  if (row + dr[current.dir] * len >= 0 && row + dr[current.dir] < N)
  {
    if (col + dc[current.dir] * len >= 0 && col + dc[current.dir] * N < N)
      return true;
    else
      return false;
  }
  else
    return false;
}

void spread(int startR, int startC)
{
  int spreadSand = 0;

  // 0. 기준값
  int originalSand = map[current.r][current.c];
  int moveDir[2] = {(current.dir + 1) % DIR, (current.dir + 3) % DIR};

  int nextR, nextC;
  // 1. 이전 위치에서 진행방향 기준 직각 방향으로 퍼짐
  for (int m = 0; m < 2; m++)
  {
    nextR = startR + dr[moveDir[m]];
    nextC = startC + dc[moveDir[m]];

    if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
    {
      map[nextR][nextC] += originalSand * 0.01;
      spreadSand += originalSand * 0.01;
    }
    else
    {
      answer += originalSand * 0.01;
      spreadSand += originalSand * 0.01;
    }
  }

  // 2. 현재 위치에서 두 칸만큼 진행방향 기준 직각 방향으로 퍼짐
  double add = 0.07;
  for (int len = 1; len <= 2; len++)
  {
    nextR = current.r + dr[moveDir[0]] * len;
    nextC = current.c + dc[moveDir[0]] * len;

    if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
    { // 2-1. 지도 내이면
      map[nextR][nextC] += originalSand * add;
      spreadSand += originalSand * add;
    }
    else
    { // 2-2. 지도 밖이면
      answer += originalSand * add;
      spreadSand += originalSand * add;
    }

    nextR = current.r + dr[moveDir[1]] * len;
    nextC = current.c + dc[moveDir[1]] * len;

    if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
    { // 2-1. 지도 내이면
      map[nextR][nextC] += originalSand * add;
      spreadSand += originalSand * add;
    }
    else
    {
      answer += originalSand * add;
      spreadSand += originalSand * add;
    }
    add -= 0.05;
  }

  // 3. 현재 위치에서 한 칸 진행한 방향에서 직각 방향으로 퍼짐
  for (int m = 0; m < 2; m++)
  {
    nextR = current.r + dr[current.dir] + dr[moveDir[m]];
    nextC = current.c + dc[current.dir] + dc[moveDir[m]];

    if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
    {
      map[nextR][nextC] += originalSand * 0.1;
      spreadSand += originalSand * 0.1;
    }
    else
    {
      answer += originalSand * 0.1;
      spreadSand += originalSand * 0.1;
    }
  }

  // 4. 현재 위치에서 두 칸 진행한 위치에 퍼짐
  nextR = current.r + dr[current.dir] * 2;
  nextC = current.c + dc[current.dir] * 2;
  if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
  {
    map[nextR][nextC] += originalSand * 0.05;
    spreadSand += originalSand * 0.05;
  }
  else
  {
    answer += originalSand * 0.05;
    spreadSand += originalSand * 0.05;
  }

  // 5. 비율이 적혀있는 칸으로 이동하지 않은 남은 모래 이동
  nextR = current.r + dr[current.dir];
  nextC = current.c + dc[current.dir];
  if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
  {
    map[nextR][nextC] += originalSand - spreadSand;
  }
  else
  {
    answer += originalSand - spreadSand;
  }

  // 6. 현재 위치의 모래는 사라짐
  map[current.r][current.c] = 0;
  return;
}

bool endCheck()
{
  if (current.r == 0 && current.c == 0)
    return true;
  else
    return false;
}

int main()
{
  // 0. 입력 및 초기화
  cin >> N;
  current.r = current.c = N / 2;

  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
    {
      cin >> map[row][col];
    }
  }

  // 1. 이동
  answer = 0;
  int cnt = 0;
  int distance = 1;
  int number = 1;

  while (!endCheck())
  {
    // 1-1. 거리만큼 이동하면서 모래 흩날리기
    for (int move = 0; move < distance; move++)
    {
      // 1-1-1. 다음 위치로 이동
      int prevR = current.r;
      int prevC = current.c;

      current.r += dr[current.dir];
      current.c += dc[current.dir];

      // 1-1-2. 흩날리기
      spread(prevR, prevC);

      if (endCheck())
        break;
    }

    // 1-2. 현재 길이의 이동 횟수 체크
    cnt++;
    if (cnt == 2)
    {
      distance++;
      cnt = 0;
    }

    // 1-3. 방향 전환
    current.dir = (current.dir + 1) % DIR;
  }

  cout << answer << endl;

  return 0;
}