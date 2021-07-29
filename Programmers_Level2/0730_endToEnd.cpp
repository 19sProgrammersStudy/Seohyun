// Level 2. 영어 끝말잇기
// https://programmers.co.kr/learn/courses/30/lessons/12981?language=cpp

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
  vector<int> answer(2, 0);
  set<string> list;

  list.insert(words[0]);
  for (int idx = 1; idx < words.size(); idx++)
  {
    if (words[idx][0] != words[idx - 1][words[idx - 1].size() - 1])
    {
      answer[0] = (idx % n) + 1;
      answer[1] = (idx / n) + 1;
      break;
    }

    if (list.find(words[idx]) != list.end())
    {
      answer[0] = (idx % n) + 1;
      answer[1] = (idx / n) + 1;
      break;
    }

    list.insert(words[idx]);
  }

  return answer;
}