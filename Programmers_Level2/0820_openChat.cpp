// Level 2. 오픈채팅방
// https://programmers.co.kr/learn/courses/30/lessons/42888?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
  vector<string> answer;
  map<string, string> user;

  // 0. record를 돌면서 유저 아이디, 닉네임 최신화 및 answer 초안 입력
  for (int idx = 0; idx < record.size(); idx++)
  {
    int blank;
    string tempR, tempU, tempN;
    switch (record[idx][0])
    {
    case 'E':
      // 1. 첫 단어 구분
      blank = record[idx].find(" ");
      record[idx] = record[idx].substr(blank + 1, record[idx].size() - blank);

      // 2. 유저 아이디, 닉네임 구분
      blank = record[idx].find(" ");
      tempU = record[idx].substr(0, blank);
      tempN = record[idx].substr(blank + 1, record[idx].size() - blank);

      // 3. 메시지 삽입
      answer.push_back(tempU + " 들어왔습니다.");

      if (user.find(tempU) != user.end())
        user[tempU] = tempN;
      else
        user.insert(make_pair(tempU, tempN));
      break;
    case 'L':
      // 1. 첫 단어 구분
      blank = record[idx].find(" ");
      record[idx] = record[idx].substr(blank + 1, record[idx].size() - blank);

      // 2. 유저 아이디, 닉네임 구분
      blank = record[idx].find(" ");
      tempU = record[idx].substr(0, blank);
      tempN = record[idx].substr(blank + 1, record[idx].size() - blank);

      // 3. 메시지 삽입
      answer.push_back(tempU + " 나갔습니다.");
      break;
    case 'C':
      // 1. 첫 단어 구분
      blank = record[idx].find(" ");
      record[idx] = record[idx].substr(blank + 1, record[idx].size() - blank);

      // 2. 유저 아이디, 닉네임 구분
      blank = record[idx].find(" ");
      tempU = record[idx].substr(0, blank);
      tempN = record[idx].substr(blank + 1, record[idx].size() - blank);

      // 3. 유저 아이디 변경
      user[tempU] = tempN;
      break;
    }
  }

  // 1. 삽입된 answer를 돌면서 유저 아이디를 닉네임으로 변경
  for (int idx = 0; idx < answer.size(); idx++)
  {
    int blank = answer[idx].find(" ");
    string cur = answer[idx].substr(0, blank);
    answer[idx].replace(0, blank, user[cur] + "님이");
  }

  return answer;
}