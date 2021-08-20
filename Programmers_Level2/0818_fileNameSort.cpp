// Level 2. [3차] 파일명 정렬
// https://programmers.co.kr/learn/courses/30/lessons/17686?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct file
{
  string head = "";
  int number = 0;
  int idx = 0;
};

bool compare(file a, file b)
{
  if (a.head != b.head)
    return a.head < b.head;
  else
  {
    if (a.number != b.number)
      return a.number < b.number;
    else
    {
      return a.idx < b.idx;
    }
  }
}

vector<string> solution(vector<string> files)
{
  vector<string> answer;
  vector<file> fileName;

  // 1. HEAD, NUMBER 나누기
  for (int idx = 0; idx < files.size(); idx++)
  {
    string head = "";
    string number = "";

    int endIdx = 0;
    for (int nidx = 0; !isdigit(files[idx][nidx]); nidx++)
    {
      head += tolower(files[idx][nidx]);
      endIdx++;
    }

    for (int nidx = endIdx; isdigit(files[idx][nidx]); nidx++)
      number += files[idx][nidx];

    file newFile;
    newFile.head = head;
    newFile.number = stoi(number);
    newFile.idx = idx;
    fileName.push_back(newFile);
  }

  // 2. HEAD, NUMBER, idx 정보로 정렬
  sort(fileName.begin(), fileName.end(), compare);

  // 4. 정렬된 순대로 answer에 삽입
  for (int idx = 0; idx < fileName.size(); idx++)
    answer.push_back(files[fileName[idx].idx]);

  return answer;
}