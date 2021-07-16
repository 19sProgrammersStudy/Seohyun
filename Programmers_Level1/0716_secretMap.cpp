// Level 1. [1차] 비밀지도
// https://programmers.co.kr/learn/courses/30/lessons/17681?language=cpp

#include <string>
#include <vector>
#include <queue>

#include <iostream>

#define MAX 16
using namespace std;

int map[MAX][MAX] = {
    0,
};

void checkMap(int row, int col, int value)
{
  queue<int> binary;

  do
  {
    binary.push(value % 2);
    value /= 2;
  } while (value);

  int idx = col - 1;

  while (!binary.empty())
  {
    if (binary.front())
      map[row][idx] = binary.front();
    binary.pop();
    idx--;
  }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
  vector<string> answer;

  for (int idx = 0; idx < n; idx++)
  {
    checkMap(idx, n, arr1[idx]);
    checkMap(idx, n, arr2[idx]);
  }

  for (int idx = 0; idx < n; idx++)
  {
    string temp = "";
    for (int jdx = 0; jdx < n; jdx++)
    {
      if (map[idx][jdx])
        temp += "#";
      else
        temp += " ";
    }
    answer.push_back(temp);
  }

  return answer;
}