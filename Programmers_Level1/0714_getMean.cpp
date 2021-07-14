// Level 1. 평균 구하기
// https://programmers.co.kr/learn/courses/30/lessons/12944

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
  double answer = 0;

  for (int idx = 0; idx < arr.size(); idx++)
    answer += arr[idx];

  return answer /= arr.size();
}