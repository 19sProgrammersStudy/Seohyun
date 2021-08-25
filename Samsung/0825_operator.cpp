// 14888번. 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888

#include <iostream>

using namespace std;

#define OPE 4
#define NUM 11
#define VALUE 1000000001

int opeCnt[OPE];
int numbers[NUM], operators[NUM];

int N, minValue, maxValue;

void calculate()
{
  int answer = numbers[0];

  for (int idx = 0; idx < N - 1; idx++)
  {
    switch (operators[idx])
    {
    case 0:
      answer += numbers[idx + 1];
      break;
    case 1:
      answer -= numbers[idx + 1];
      break;
    case 2:
      answer *= numbers[idx + 1];
      break;
    case 3:
      answer /= numbers[idx + 1];
      break;
    }
  }

  if (minValue > answer)
    minValue = answer;
  if (answer > maxValue)
    maxValue = answer;

  return;
}

void dfs(int idx)
{
  if (idx == N - 1)
    return calculate();

  for (int ope = 0; ope < OPE; ope++)
  {
    if (!opeCnt[ope])
      continue;
    operators[idx] = ope;
    opeCnt[ope]--;
    dfs(idx + 1);
    opeCnt[ope]++;
  }
}

int main()
{
  cin >> N;

  for (int idx = 0; idx < N; idx++)
    cin >> numbers[idx];

  for (int ope = 0; ope < OPE; ope++)
    cin >> opeCnt[ope];

  minValue = VALUE;
  maxValue = -VALUE;

  for (int ope = 0; ope < OPE; ope++)
  {
    if (!opeCnt[ope])
      continue;
    operators[0] = ope;
    opeCnt[ope]--;
    dfs(1);
    opeCnt[ope]++;
  }

  cout << maxValue << endl
       << minValue << endl;

  return 0;
}