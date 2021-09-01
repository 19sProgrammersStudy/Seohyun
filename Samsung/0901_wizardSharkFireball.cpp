// 20056번. 마법사 상어와 파이어볼
// https://www.acmicpc.net/problem/20056

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 51
#define DIR 8
#define DIV 4

int dr[DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fireball
{
  int m, d, s;
};

int N, M, K;
queue<fireball> map[MAX][MAX];

int main()
{
  // 0. 입력 및 초기화
  cin >> N >> M >> K;

  int r, c;
  for (int idx = 0; idx < M; idx++)
  {
    fireball input;
    cin >> r >> c >> input.m >> input.s >> input.d;
    map[r][c].push(input);
  }

  // 1. 이동 명령
  for (int command = 0; command < K; command++)
  {
    // 1-1. 하나씩 이동
    queue<fireball> moved[MAX][MAX];
    for (int row = 1; row <= N; row++)
    {
      for (int col = 1; col <= N; col++)
      {
        while (!map[row][col].empty())
        {
          fireball cur = map[row][col].front();
          map[row][col].pop();

          int nextR = row + (dr[cur.d] * cur.s);
          int nextC = col + (dc[cur.d] * cur.s);

          if (nextR > N)
            nextR = nextR % N;
          if (nextR < 1)
            nextR = N - (abs(nextR) % N);

          if (nextC > N)
            nextC = nextC % N;
          if (nextC < 1)
            nextC = N - (abs(nextC) % N);

          moved[nextR][nextC].push(cur);
        }
      }
    }

    // 1-2. 이동한 후 2개 이상의 파이어볼이 있는 곳에서 합치기
    for (int row = 1; row <= N; row++)
    {
      for (int col = 1; col <= N; col++)
      {
        if (moved[row][col].size() > 1)
        {
          bool isOdd = false;
          bool isEven = false;

          int totalM = 0;
          int totalS = 0;
          int cnt = 0;

          // 1-2-1. 파이어볼 합치기
          while (!moved[row][col].empty())
          {
            cnt++;
            totalM += moved[row][col].front().m;
            totalS += moved[row][col].front().s;

            if (moved[row][col].front().d % 2 == 0)
              isEven = true;
            else
              isOdd = true;

            moved[row][col].pop();
          }

          // 1-2-2. 파이어볼 나누기
          if (totalM / 5)
          {
            totalM /= 5;
            totalS /= cnt;

            if (isOdd && isEven)
            { // 1-2-2-1. 짝수, 홀수 방향이 섞여있으면
              for (int idx = 0; idx < DIV; idx++)
              {
                fireball temp;
                temp.m = totalM;
                temp.s = totalS;
                temp.d = (2 * idx) + 1;

                moved[row][col].push(temp);
              }
            }
            else
            { // 1-2-2-2. 모두 짝수 또는 홀수 방향이면
              for (int idx = 0; idx < DIV; idx++)
              {
                fireball temp;
                temp.m = totalM;
                temp.s = totalS;
                temp.d = 2 * idx;

                moved[row][col].push(temp);
              }
            }
          } // 1-2-2. 나누기 완료
        }
      }
    }

    // 1-3. 이동한 파이어볼 복사
    for (int row = 1; row <= N; row++)
    {
      for (int col = 1; col <= N; col++)
      {
        while (!moved[row][col].empty())
        {
          map[row][col].push(moved[row][col].front());
          moved[row][col].pop();
        }
      }
    }
  }

  // 2. 남은 파이어볼 합치기
  long long answer = 0;
  for (int row = 1; row <= N; row++)
  {
    for (int col = 1; col <= N; col++)
    {
      while (!map[row][col].empty())
      {
        answer += map[row][col].front().m;
        map[row][col].pop();
      }
    }
  }

  cout << answer << endl;

  return 0;
}
