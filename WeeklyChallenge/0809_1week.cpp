// 위클리 챌린지 : 1주차
// https://programmers.co.kr/learn/courses/30/lessons/82612?language=cpp

using namespace std;

long long solution(int price, int money, int count)
{
  long long answer = 0;
  int trial = 1;

  long long remain = money;

  while (trial <= count)
  {
    remain -= price * trial;
    trial++;
  }

  if (remain < 0)
    answer = -remain;
  return answer;
}