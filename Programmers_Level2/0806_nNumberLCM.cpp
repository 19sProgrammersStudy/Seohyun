// Level 2. N개의 최소공배수
// https://programmers.co.kr/learn/courses/30/lessons/12953?language=cpp#

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getLcm(int num1, int num2)
{
  int lcm = num2;
  while (true)
  {
    if (lcm % num1 == 0 && lcm % num2 == 0)
      break;
    else
      lcm++;
  }
  return lcm;
}

int solution(vector<int> arr)
{
  int answer = 1;
  deque<int> number;
  sort(arr.begin(), arr.end());

  for (int idx = 0; idx < arr.size(); idx++)
    number.push_back(arr[idx]);

  while (number.size() > 1)
  {
    int num1 = number.front();
    number.pop_front();
    int num2 = number.front();
    number.pop_front();

    number.push_front(getLcm(num1, num2));
  }

  answer = number.front();
  return answer;
}