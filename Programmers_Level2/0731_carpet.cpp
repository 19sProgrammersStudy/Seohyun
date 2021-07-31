// Level 2. 카펫
// https://programmers.co.kr/learn/courses/30/lessons/42842?language=cpp

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
  vector<int> answer;

  int sum = brown + yellow;

  bool flag = false;
  for (int height = sqrt(sum); height >= 0; height--)
  {
    int width = sum / height;
    if (width * 2 + (height - 2) * 2 == brown)
    {
      answer.push_back(width);
      answer.push_back(height);
      break;
    }
  }
  return answer;
}