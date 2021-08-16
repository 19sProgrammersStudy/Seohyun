// Level 2. 행렬 테두리 회전하기
// https://programmers.co.kr/learn/courses/30/lessons/77485?language=cpp

#include <string>
#include <vector>
#include <iostream>
#define MAX 101

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
  vector<int> answer;

  // 0. 행렬 초기화
  int map[MAX][MAX] = {
      0,
  };
  for (int row = 1; row <= rows; row++)
    for (int col = 1; col <= columns; col++)
      map[row][col] = ((row - 1) * columns) + col;

  // 1. 행렬 테두리 회전
  int startX, startY, endX, endY;
  for (int idx = 0; idx < queries.size(); idx++)
  {
    startY = queries[idx][0];
    startX = queries[idx][1];
    endY = queries[idx][2];
    endX = queries[idx][3];

    int min = map[startY + 1][startX];
    int nextDirection = map[startY + 1][startX];

    // 1-1. 왼쪽 상단 > 오른쪽 상단 회전
    for (int col = startX; col <= endX; col++)
    {
      int temp = map[startY][col];
      map[startY][col] = nextDirection;
      nextDirection = temp;
      if (min > nextDirection)
        min = nextDirection;
    }

    // 1-2. 오른쪽 상단 > 오른쪽 하단 회전
    for (int row = startY + 1; row <= endY; row++)
    {
      int temp = map[row][endX];
      map[row][endX] = nextDirection;
      nextDirection = temp;
      if (min > nextDirection)
        min = nextDirection;
    }

    // 1-3. 오른쪽 하단 > 왼쪽 하단 회전
    for (int col = endX - 1; col >= startX; col--)
    {
      int temp = map[endY][col];
      map[endY][col] = nextDirection;
      nextDirection = temp;
      if (min > nextDirection)
        min = nextDirection;
    }

    // 1-4. 왼쪽 하단 > 왼쪽 상단 회전
    for (int row = endY - 1; row >= startY; row--)
    {
      int temp = map[row][startX];
      map[row][startX] = nextDirection;
      nextDirection = temp;
      if (min > nextDirection)
        min = nextDirection;
    }

    // 1-5. 최소값 push
    answer.push_back(min);
  }
  return answer;
}