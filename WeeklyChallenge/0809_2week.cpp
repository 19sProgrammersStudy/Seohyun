// 위클리 챌린지 : 2주차
// https://programmers.co.kr/learn/courses/30/lessons/83201?language=cpp

#include <string>
#include <vector>

using namespace std;

string getScore(int sum, int num)
{
  float avg = (float)sum / num;

  if (avg >= 90)
    return "A";
  else if (avg >= 80)
    return "B";
  else if (avg >= 70)
    return "C";
  else if (avg >= 50)
    return "D";
  else
    return "F";
}

string solution(vector<vector<int>> scores)
{
  string answer = "";
  int student = scores.size();

  for (int idx = 0; idx < student; idx++)
  {
    int max = idx;
    int min = idx;
    int total = scores[idx][idx];

    for (int jdx = 0; jdx < student; jdx++)
    {
      if (jdx == idx)
        continue;
      if (scores[jdx][idx] >= scores[max][idx])
        max = jdx;
      if (scores[jdx][idx] <= scores[min][idx])
        min = jdx;
      total += scores[jdx][idx];
    }

    if (min == idx || max == idx)
      answer += getScore(total - scores[idx][idx], student - 1);
    else
      answer += getScore(total, student);
  }

  return answer;
}