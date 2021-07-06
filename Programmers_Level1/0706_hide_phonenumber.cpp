// Level 1. 핸드폰 번호 가리기
// https://programmers.co.kr/learn/courses/30/lessons/12948

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
  string answer = "";

  for (int idx = 0; idx < phone_number.size() - 4; idx++)
  {
    if (idx < phone_number.size() - 4)
      phone_number[idx] = '*';
  }

  answer = phone_number;

  return answer;
}