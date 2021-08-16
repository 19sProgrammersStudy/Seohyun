// Level 2. [3차] 압축
// https://programmers.co.kr/learn/courses/30/lessons/17684?language=cpp

#include <string>
#include <vector>
#include <map>

#define ALPHA 26
#define UPPER 65
using namespace std;

vector<int> solution(string msg)
{
  vector<int> answer;
  map<string, int> dict;

  // 0. 길이가 1인 사전 초기화
  int value = 1;
  for (int idx = 0; idx < ALPHA; idx++)
  {
    char alpha = UPPER + idx;
    string current;
    current += alpha;
    dict.insert(pair<string, int>(current, value++));
  }

  // 1. msg 탐색
  int cur = 0;
  string word;
  while (cur < msg.size())
  {
    word = msg[cur];

    // 1-1. 사전에 색인 번호가 있는 동안 반복
    int len = 1;
    while (dict.find(word) != dict.end())
    {
      word += msg[cur + len];
      len++;
    }

    // 1-2. 색인 번호가 없는 경우, 존재하는 색인 번호 push
    string exist = word.substr(0, word.size() - 1);
    answer.push_back(dict[exist]);

    // 1-3. 색인 번호 추가
    dict.insert(make_pair(word, value++));
    cur += len - 1;
  }
  return answer;
}