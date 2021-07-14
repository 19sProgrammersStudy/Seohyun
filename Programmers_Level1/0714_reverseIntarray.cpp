// Level 1. 자연수 뒤집어 배열로 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12932

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
  vector<int> answer;
  string number = to_string(n);

  for (int idx = number.size() - 1; idx >= 0; idx--)
    answer.push_back(number[idx] - '0');

  return answer;
}