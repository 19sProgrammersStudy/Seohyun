// Level 1. 로또의 최고 순위와 최저 순위
// https://programmers.co.kr/learn/courses/30/lessons/77484?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define LEN 6

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
  vector<int> answer;

  int hit = 0;
  int unknown = 0;

  // 1. 구매한 로또에서 알 수 없는 번호 개수
  for (int idx = 0; idx < LEN; idx++)
    if (!lottos[idx])
    {
      unknown++;
    }

  // 2. 구매한 로또에서 당첨 번호와 일치하는 개수
  for (int idx = 0; idx < LEN; idx++)
    if (find(lottos.begin(), lottos.end(), win_nums[idx]) != lottos.end())
      hit++;

  // 3. 최고 순위는 1 + 2의 결과, 최저 순위는 2의 결과
  (hit + unknown <= 1) ? answer.push_back(6) : answer.push_back(LEN + 1 - hit - unknown);
  (hit <= 1) ? answer.push_back(6) : answer.push_back(LEN + 1 - hit);

  return answer;
}