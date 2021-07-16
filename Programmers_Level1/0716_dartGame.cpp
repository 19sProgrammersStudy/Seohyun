// Level 1. [1차] 다크 게임
// https://programmers.co.kr/learn/courses/30/lessons/17682?language=cpp

#include <string>
#include <cmath>

using namespace std;

#define MAX 3
int score[MAX] = {
    0,
};

void calculate(char opt, int trial)
{
  switch (opt)
  {
  case 'S':
    break;
  case 'D':
    score[trial] = pow(score[trial], 2);
    break;
  case 'T':
    score[trial] = pow(score[trial], 3);
    break;
  case '*':
    score[trial] *= 2;
    if (trial - 1 >= 0)
      score[trial - 1] *= 2;
    break;
  case '#':
    score[trial] *= -1;
    break;
  }
  return;
}

int solution(string dartResult)
{
  int answer = 0;
  int trial = -1;

  for (int idx = 0; idx < dartResult.size(); idx++)
  {
    if (isdigit(dartResult[idx]))
    {
      trial++;
      score[trial] = dartResult[idx] - '0';
      if (idx + 1 < dartResult.size() && isdigit(dartResult[idx + 1]))
      {
        score[trial] = 10;
        idx++;
      }
    }
    else
      calculate(dartResult[idx], trial);
  }

  for (int idx = 0; idx < MAX; idx++)
    answer += score[idx];

  return answer;
}