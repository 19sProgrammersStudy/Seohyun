// D4. 장훈이의 높은 선반
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b7Yf6ABcBBASw

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, B, answer;
vector<int> height;

void dfs(int start, int sum)
{
  if (sum >= B)
  {
    if (answer > sum)
      answer = sum;
    return;
  }

  for (int idx = start + 1; idx < N; idx++)
  {
    dfs(idx, sum + height[idx]);
  }
}

int main(int argc, char **argv)
{
  int test_case;
  int T;
  int temp;

  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case)
  {
    cin >> N >> B;

    height.clear();
    for (int idx = 0; idx < N; idx++)
    {
      cin >> temp;
      height.push_back(temp);
    }

    answer = 200001;
    for (int idx = 0; idx < N; idx++)
      dfs(idx, height[idx]);

    printf("#%d %d\n", test_case, abs(B - answer));
  }
  return 0;
}