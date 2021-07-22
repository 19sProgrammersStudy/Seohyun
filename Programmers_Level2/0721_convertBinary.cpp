// Level 2. 이진 변환 반복하기
// https://programmers.co.kr/learn/courses/30/lessons/70129?language=cpp

#include <string>
#include <vector>

using namespace std;

string makeBinary(int length)
{
  string binary = "";

  while (length)
  {
    binary += to_string(length % 2);
    length /= 2;
  }

  return binary;
}

vector<int> solution(string s)
{
  vector<int> answer;

  string temp;
  int chgBinary = 0;
  int removeZero = 0;

  while (s != "1")
  {
    temp = "";
    for (int idx = 0; idx < s.size(); idx++)
      if (s[idx] == '1')
        temp += '1';

    removeZero += (s.size() - temp.size());
    chgBinary++;
    s = makeBinary(temp.size());
  }

  answer.push_back(chgBinary);
  answer.push_back(removeZero);

  return answer;
}