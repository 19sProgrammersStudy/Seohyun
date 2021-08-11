// Level 2. 전화번호 목록
// https://programmers.co.kr/learn/courses/30/lessons/42577?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
  bool answer = true;
  sort(phone_book.begin(), phone_book.end());

  int cur = 0;
  int start = phone_book[0][0] - '0';

  while (answer && cur < phone_book.size() - 1)
  {
    if (phone_book[cur][0] == phone_book[cur + 1][0] &&
        phone_book[cur + 1].find(phone_book[cur]) == 0)
      answer = false;
    else
      cur++;
  }

  return answer;
}