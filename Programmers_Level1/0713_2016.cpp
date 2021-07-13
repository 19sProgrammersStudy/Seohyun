// Level 1. 2016년
// https://programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>

#define WEEK 7
#define MONTH 12
using namespace std;

string solution(int a, int b)
{
  int months[MONTH] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string days[WEEK] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

  int cnt = 0;
  for (int idx = 0; idx < a - 1; idx++)
    cnt += months[idx];

  return days[(cnt + b - 1) % WEEK];
}