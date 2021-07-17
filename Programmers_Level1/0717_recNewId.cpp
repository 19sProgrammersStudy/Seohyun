// Level 1. 신규 아이디 추천
// https://programmers.co.kr/learn/courses/30/lessons/72410?language=cpp

#include <string>
#include <vector>
using namespace std;

string solution(string new_id)
{
  string answer = "";

  // STEP 1. 모든 대문자를 대응되는 소문자로 치환
  // STEP 2. 알파벳 소문자, 문자, -_.를 제외한 문자 제거
  // STEP 3. .이 2개 이상 연속된 부분 제거
  for (int idx = 0; idx < new_id.size(); idx++)
  {
    if (isalpha(new_id[idx]))
      answer += tolower(new_id[idx]);
    else if (isdigit(new_id[idx]))
      answer += new_id[idx];
    else if (new_id[idx] == '-' || new_id[idx] == '_')
      answer += new_id[idx];
    else if (new_id[idx] == '.')
    {
      if (idx - 1 >= 0 && answer[answer.size() - 1] == '.')
        continue;
      else
        answer += '.';
    }
  }

  // STEP 4. .가 처음이나 끝에 위치하면 제거
  if (answer[0] == '.')
    answer.erase(answer.begin());
  if (answer[answer.size() - 1] == '.')
    answer.erase(answer.begin() + answer.size() - 1);

  // STEP 5. 빈 문자열이면 a를 대입
  if (answer.empty())
    answer = "a";

  // STEP 6. answer 길이가 16자 이상이면 15개 외의 문자 모두 제거
  while (answer.size() >= 16)
    answer.erase(answer.size() - 1);
  if (answer[answer.size() - 1] == '.')
    answer.erase(answer.size() - 1);

  // STEP 7. 길이가 2자 이하면 마지막 문자를 길이가 3이 될 때까지 반복
  while (answer.size() < 3)
    answer += answer[answer.size() - 1];

  return answer;
}