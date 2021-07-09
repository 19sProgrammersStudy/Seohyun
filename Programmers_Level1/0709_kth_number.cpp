// Level 1. K번째 수
// https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
  vector<int> answer;

  for (int idx = 0; idx < commands.size(); idx++)
  {
    vector<int> temp;
    int start = commands[idx][0] - 1;
    int end = commands[idx][1] - 1;
    int k = commands[idx][2] - 1;

    for (int jdx = start; jdx <= end; jdx++)
      temp.push_back(array[jdx]);

    sort(temp.begin(), temp.end());

    answer.push_back(temp[k]);
  }
  return answer;
}