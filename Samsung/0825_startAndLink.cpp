// 14889번. 스타트와 링크
// https://www.acmicpc.net/problem/14889

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 20

int N, answer;
int player[MAX][MAX] = {
    0,
};
int team[MAX] = {
    0,
};

void getScore()
{
  int sFirst = -1;
  int lFirst = -1;

  for (int idx = 0; sFirst == -1 || lFirst == -1; idx++)
  {
    if (team[idx] == 1)
      sFirst = idx;
    if (team[idx] == 0)
      lFirst = idx;
  }

  int sScore = 0;
  int lScore = 0;
  for (int idx = 0; idx < N; idx++)
  {
    if (team[idx] == 1)
      sScore += player[sFirst][idx];
    if (team[idx] == 0)
      lScore += player[lFirst][idx];
  }

  if (abs(sScore - lScore) < answer)
    answer = abs(sScore - lScore);
  return;
}

void dfs(int start, int cnt)
{
  if (cnt == N / 2)
  {
    getScore();
    return;
  }

  if (cnt != N / 2 && start == N)
    return;

  for (int idx = start; idx < N; idx++)
  {
    team[idx] = 1;
    dfs(idx + 1, cnt + 1);
    team[idx] = 0;
  }
}

int main()
{
  cin >> N;

  // 0. 초기화
  answer = 0;
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++)
      cin >> player[row][col];

  // 1. 스타트 팀 구하기
  for (int idx = 0; idx < N; idx++)
  {
    team[idx] = 1;
    dfs(idx + 1, 1);
    team[idx] = 0;
  }

  cout << answer << endl;
  return 0;
}