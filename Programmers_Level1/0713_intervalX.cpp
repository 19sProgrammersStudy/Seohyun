// Level 1. x만큼 간격이 있는 n개의 숫자
// https://programmers.co.kr/learn/courses/30/lessons/12954

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
  vector<long long> answer;

  answer.push_back(x);
  for (int idx = 1; idx < n; idx++)
  {
    answer.push_back(answer[idx - 1] + x);
  }
  return answer;
}