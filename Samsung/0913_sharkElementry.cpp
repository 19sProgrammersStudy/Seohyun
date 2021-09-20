// 21608번. 상어 초등학교
// https://www.acmicpc.net/problem/21608

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define FAV 4
#define DIR 4
#define MAX 20

struct check
{
  int r, c;
  int favorite = 0;
  int empty = 0;
};

struct info
{
  int num;
  int r, c;
  set<int> favorite;
};

int N;

int map[MAX][MAX] = {
    0,
};
int dr[DIR] = {-1, 1, 0, 0};
int dc[DIR] = {0, 0, -1, 1};

check compare(check a, check b)
{
  if (a.favorite > b.favorite)
    return a;
  else if (a.favorite == b.favorite)
  {
    if (a.empty > b.empty)
      return a;
    else if (a.empty == b.empty)
    {
      if (a.r > b.r)
        return b;
      else if (a.r == b.r)
      {
        if (a.c > b.c)
          return b;
        else
          return a;
      }
      else
        return a;
    }
    else
      return b;
  }
  else
    return b;
}

int main()
{
  // 0. 입력
  cin >> N;

  // 1. 학생 정보 입력 받기
  int fav;

  vector<info> students(N * N + 1);
  for (int stu = 0; stu < N * N; stu++)
  {
    info cur;
    cin >> cur.num;

    // 1-1. 좋아하는 학생 입력받기
    for (int idx = 0; idx < FAV; idx++)
    {
      cin >> fav;
      cur.favorite.insert(fav);
    }

    // 1-2. 첫번째 학생인 경우, (1,1)에 배정
    if (!stu)
    {
      map[1][1] = cur.num;
      cur.r = cur.c = 1;
      students[cur.num] = cur;
    }
    else
    {
      // 1-3. 첫번째 학생이 아닌 경우, 인접한 칸을 탐색한다
      check best;
      best.r = best.c = N - 1;
      best.favorite = best.empty = 0;
      for (int row = 0; row < N; row++)
      {
        for (int col = 0; col < N; col++)
        {
          if (!map[row][col])
          { // 1-3-1. 칸이 빈 경우에만 탐색
            int nextR, nextC;
            check temp;
            temp.r = row;
            temp.c = col;

            // 1-3-2. 인접한 네 방향 탐색
            for (int d = 0; d < DIR; d++)
            {
              nextR = row + dr[d];
              nextC = col + dc[d];

              if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
              {
                if (!map[nextR][nextC])
                  temp.empty++;
                else if (map[nextR][nextC] && cur.favorite.find(map[nextR][nextC]) != cur.favorite.end())
                  temp.favorite++;
              }
            }

            // 1-3-3. 탐색한 자리와 현재 위치 비교
            best = compare(best, temp);
          }
        }
      }

      map[best.r][best.c] = cur.num;
      cur.r = best.r;
      cur.c = best.c;
    }
    students[cur.num] = cur;
  }

  int answer = 0;
  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
    {
      int cnt = 0;
      int nextR, nextC;
      for (int d = 0; d < DIR; d++)
      {
        nextR = row + dr[d];
        nextC = col + dc[d];

        if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N)
        {
          if (students[map[row][col]].favorite.find(map[nextR][nextC]) != students[map[row][col]].favorite.end())
          {
            cnt++;
          }
        }
      }

      switch (cnt)
      {
      case 0:
        break;
      case 1:
        answer += 1;
        break;
      case 2:
        answer += 10;
        break;
      case 3:
        answer += 100;
        break;
      case 4:
        answer += 1000;
        break;
      }
    }
  }

  cout << answer << endl;

  return 0;
}