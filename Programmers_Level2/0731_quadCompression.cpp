// Level 2. 쿼드압축 후 개수 세기
// https://programmers.co.kr/learn/courses/30/lessons/68936?language=cpp

#include <string>
#include <vector>

using namespace std;

#define MAX 1024

int map[MAX][MAX];
vector<int> answer;

void isCompression(int r, int c, int len)
{
  if (len == 1)
  {
    answer[map[r][c]]++;
    return;
  }

  bool flag = true;
  int value = map[r][c];
  for (int row = r; row < r + len; row++)
  {
    for (int col = c; col < c + len; col++)
    {
      if (map[row][col] != value)
      {
        flag = false;
        break;
      }
    }
    if (!flag)
      break;
  }

  if (flag)
    answer[value]++;
  else
  {
    isCompression(r, c, len / 2);
    isCompression(r + (len / 2), c, len / 2);
    isCompression(r, c + (len / 2), len / 2);
    isCompression(r + (len / 2), c + (len / 2), len / 2);
  }
  return;
}

vector<int> solution(vector<vector<int>> arr)
{
  answer.assign(2, 0);

  for (int row = 0; row < arr.size(); row++)
    for (int col = 0; col < arr[0].size(); col++)
      map[row][col] = arr[row][col];

  int len = arr.size();
  isCompression(0, 0, len);

  return answer;
}