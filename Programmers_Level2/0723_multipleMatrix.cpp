// Level 2. 행렬의 곱셈
// https://programmers.co.kr/learn/courses/30/lessons/12949?language=cpp

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
  int aRow = arr1.size();
  int aCol = arr2[0].size();
  vector<vector<int>> answer(aRow, vector<int>(aCol, 0));

  for (int row = 0; row < aRow; row++)
  {
    for (int col = 0; col < aCol; col++)
    {
      for (int idx = 0; idx < arr1[row].size(); idx++)
      {
        answer[row][col] += arr1[row][idx] * arr2[idx][col];
      }
    }
  }

  return answer;
}