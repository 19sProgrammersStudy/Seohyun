// Level 1. 키패드 누르기
// https://programmers.co.kr/learn/courses/30/lessons/67256?language=cpp

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int distance(int hand, int b)
{
  return (abs(hand - b) / 3) + (abs(hand - b) % 3);
}

string solution(vector<int> numbers, string hand)
{
  string answer = "";

  int left = 10;
  int right = 12;

  for (int idx = 0; idx < numbers.size(); idx++)
  {
    switch (numbers[idx])
    {
    case 1:
    case 4:
    case 7:
      answer += "L";
      left = numbers[idx];
      break;
    case 3:
    case 6:
    case 9:
      answer += "R";
      right = numbers[idx];
      break;
    case 2:
    case 5:
    case 8:
      if (distance(left, numbers[idx]) < distance(right, numbers[idx]))
      {
        answer += "L";
        left = numbers[idx];
      }
      else if (distance(right, numbers[idx]) < distance(left, numbers[idx]))
      {
        answer += "R";
        right = numbers[idx];
      }
      else
      {
        if (hand == "left")
        {
          answer += "L";
          left = numbers[idx];
        }
        else
        {
          answer += "R";
          right = numbers[idx];
        }
      }
      break;
    case 0:
      if (distance(left, 11) < distance(right, 11))
      {
        answer += "L";
        left = 11;
      }
      else if (distance(right, 11) < distance(left, 11))
      {
        answer += "R";
        right = 11;
      }
      else
      {
        if (hand == "left")
        {
          answer += "L";
          left = 11;
        }
        else
        {
          answer += "R";
          right = 11;
        }
      }
      break;
    }
  }
  return answer;
}