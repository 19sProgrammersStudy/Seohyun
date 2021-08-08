// Level 2. 점프와 순간이동
// https://programmers.co.kr/learn/courses/30/lessons/12980?language=cpp

using namespace std;

int solution(int n)
{
  int ans = 0;
  int cur = n;

  while (cur > 0)
  {
    if (cur % 2 == 0)
      cur /= 2;
    else
    {
      ans++;
      cur--;
    }
  }
  return ans;
}