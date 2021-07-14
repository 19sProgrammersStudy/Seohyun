// Level 1. 제일 작은 수 제거하기
// https://programmers.co.kr/learn/courses/30/lessons/12935

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
  vector<int> answer = arr;

  int minIdx = min_element(answer.begin(), answer.end()) - answer.begin();
  answer.erase(answer.begin() + minIdx);

  if (!answer.empty())
    return answer;
  else
  {
    answer.push_back(-1);
    return answer;
  }
}