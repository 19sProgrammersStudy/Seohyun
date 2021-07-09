// Level 1. 숫자 문자열과 영단어
// https://programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
  string answer = "";

  for (int idx = 0; idx < s.size(); idx++)
  {
    switch (s[idx])
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      answer += s[idx];
      break;
    case 'z':
      answer += '0';
      idx += 3;
      break;
    case 'o':
      answer += '1';
      idx += 2;
      break;
    case 't':
      if (s[idx + 1] == 'w')
      {
        answer += '2';
        idx += 2;
      }
      else
      {
        answer += '3';
        idx += 4;
      }
      break;
    case 'f':
      if (s[idx + 1] == 'o')
      {
        answer += '4';
        idx += 3;
      }
      else
      {
        answer += '5';
        idx += 3;
      }
      break;
    case 's':
      if (s[idx + 1] == 'i')
      {
        answer += '6';
        idx += 2;
      }
      else
      {
        answer += '7';
        idx += 4;
      }
      break;
    case 'e':
      answer += '8';
      idx += 4;
      break;
    case 'n':
      answer += '9';
      idx += 3;
      break;
    }
  }

  return stoi(answer);
}