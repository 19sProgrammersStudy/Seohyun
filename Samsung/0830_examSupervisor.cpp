// 13458번. 시험 감독
// https://www.acmicpc.net/problem/13458

#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

int main()
{
  // 0. 입력
  int N;
  vector<int> student(MAX, 0);

  cin >> N;
  for (int idx = 0; idx < N; idx++)
    cin >> student[idx];

  long long answer = 0;

  int main, sub;
  cin >> main >> sub;

  for (int idx = 0; idx < N; idx++)
  {
    // 1. 총감독관 카운트. 총감독관이 감시할 수 있는 응시자 수 빼기
    answer++;
    student[idx] -= main;

    // 2. 부감독관 카운트. 남은 응시자 / 부감독관이 감시할 수 있는 응시자
    if (student[idx] > 0)
    {
      answer += (student[idx] % sub == 0) ? (student[idx] / sub) : (student[idx] / sub) + 1;
    }
  }

  cout << answer << endl;

  return 0;
}