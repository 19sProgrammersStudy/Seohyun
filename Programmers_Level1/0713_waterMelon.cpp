// Level 1. 수박수박수박수박수박수?
// https://programmers.co.kr/learn/courses/30/lessons/12922

#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
  string answer = "";

  for (int idx = 0; idx < n / 2; idx++)
    answer += "수박";

  if (n % 2)
    answer += "수";

  return answer;
}