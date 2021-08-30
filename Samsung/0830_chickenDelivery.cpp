// 15686번. 치킨 배달
// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 50
#define HOME 100
#define CHIC 13

int N, M, answer;
int remain[CHIC] = {
    0,
};
int map[CHIC][HOME] = {
    0,
};

vector<pair<int, int>> homes;
vector<pair<int, int>> chicken;

void calculate()
{
  int min;
  int result = 0;

  for (int h = 0; h < homes.size(); h++)
  {
    min = 101;
    for (int r = 0; r < M; r++)
    {
      if (min > map[remain[r]][h])
        min = map[remain[r]][h];
    }
    result += min;
  }

  if (answer > result)
    answer = result;
}

void dfs(int start, int cnt)
{
  if (cnt == M)
  {
    calculate();
    return;
  }

  for (int idx = start; idx < chicken.size(); idx++)
  {
    remain[cnt] = idx;
    dfs(idx + 1, cnt + 1);
    remain[cnt] = 0;
  }
}

int main()
{
  // 0. 입력 및 초기화
  cin >> N >> M;

  int info;

  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
    {
      cin >> info;

      if (info == 1)
        homes.push_back(make_pair(row, col));
      else if (info == 2)
        chicken.push_back(make_pair(row, col));
    }
  }

  // 1. 집과 치킨집의 거리 계산
  answer = 9999;
  for (int c = 0; c < chicken.size(); c++)
  {
    for (int h = 0; h < homes.size(); h++)
    {
      map[c][h] = abs(homes[h].first - chicken[c].first) + abs(homes[h].second - chicken[c].second);
    }
  }

  // 2. M개의 치킨집 선택
  for (int c = 0; c < chicken.size(); c++)
  {
    remain[0] = c;
    dfs(1, 1);
    remain[0] = 0;
  }

  cout << answer << endl;
  return 0;
}