// Level 1. 삼진법 뒤집기
// https://programmers.co.kr/learn/courses/30/lessons/68935

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
  int answer = 0;

  // STEP 1. 3진법으로 변경
  string convert = "";

  while (n)
  {
    convert += to_string(n % 3);
    n /= 3;
  }

  // STEP 2. 10진법으로 변경
  long long mul = 1;
  for (long long idx = convert.size() - 1; idx >= 0; idx--)
  {
    answer += (convert[idx] - '0') * mul;
    mul *= 3;
  }

  return answer;
}