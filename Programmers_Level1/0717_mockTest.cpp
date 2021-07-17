// Level 1. 모의고사
// https://programmers.co.kr/learn/courses/30/lessons/42840?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define STU 3
#define SUPO1 5
#define SUPO2 8
#define SUPO3 10

vector<int> score(3, 0);
int supo1[SUPO1] = {1, 2, 3, 4, 5};
int supo2[SUPO2] = {2, 1, 2, 3, 2, 4, 2, 5};
int supo3[SUPO3] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers)
{
  vector<int> answer;

  for (int idx = 0; idx < answers.size(); idx++)
  {
    if (answers[idx] == supo1[idx % SUPO1])
      score[0]++;
    if (answers[idx] == supo2[idx % SUPO2])
      score[1]++;
    if (answers[idx] == supo3[idx % SUPO3])
      score[2]++;
  }

  int max = *max_element(score.begin(), score.end());

  for (int idx = 0; idx < STU; idx++)
    if (score[idx] == max)
      answer.push_back(idx + 1);

  sort(answer.begin(), answer.end());

  return answer;
}