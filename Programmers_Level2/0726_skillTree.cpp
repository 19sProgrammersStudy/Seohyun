// Level 2. 스킬트리
// https://programmers.co.kr/learn/courses/30/lessons/49993?language=cpp

#include <string>
#include <vector>

using namespace std;

bool isPossible(string skill, string user)
{
  int skillIdx = 0;
  for (int idx = 0; idx < user.size(); idx++)
  {
    int userIdx = skill.find(user[idx]);
    if (userIdx != -1)
    {
      if (user[idx] == skill[skillIdx])
        skillIdx++;
      else
        return false;
    }
  }
  return true;
}

int solution(string skill, vector<string> skill_trees)
{
  int answer = 0;

  for (int idx = 0; idx < skill_trees.size(); idx++)
  {
    if (isPossible(skill, skill_trees[idx]))
      answer++;
  }

  return answer;
}