// Level 2. 위장
// https://programmers.co.kr/learn/courses/30/lessons/42578?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
  int answer = 1;

  vector<string> keys;
  map<string, int> kinds;

  for (int idx = 0; idx < clothes.size(); idx++)
  {
    if (kinds.count(clothes[idx][1]))
      kinds[clothes[idx][1]] += 1;
    else
    {
      kinds[clothes[idx][1]] = 1;
      keys.push_back(clothes[idx][1]);
    }
  }

  for (int idx = 0; idx < keys.size(); idx++)
    answer *= (kinds[keys[idx]] + 1);

  return answer - 1;
}