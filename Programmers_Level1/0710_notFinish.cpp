// Level 1. 완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";

  sort(participant.begin(), participant.end());
  sort(completion.begin(), completion.end());

  int idx = 0;
  while (participant[idx] == completion[idx])
    idx++;

  answer = participant[idx];

  return answer;
}