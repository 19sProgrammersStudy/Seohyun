// Level 1. 행렬의 덧셈
// https://programmers.co.kr/learn/courses/30/lessons/12950

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
  vector<vector<int>> answer = arr1;

  for (int row = 0; row < arr2.size(); row++)
    for (int col = 0; col < arr2[row].size(); col++)
      answer[row][col] += arr2[row][col];

  return answer;
}