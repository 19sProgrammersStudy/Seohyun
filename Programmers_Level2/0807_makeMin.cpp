// Level 2. 최솟값 만들기
// https://programmers.co.kr/learn/courses/30/lessons/12941?language=cpp

#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
  return a > b;
}

int solution(vector<int> A, vector<int> B)
{
  int answer = 0;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end(), compare);

  for (int idx = 0; idx < A.size(); idx++)
    answer += A[idx] * B[idx];

  return answer;
}