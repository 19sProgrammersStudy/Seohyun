// Level 2. 주식가격
// https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
  // 1. prices 벡터 초기화
  int size = prices.size();
  vector<int> answer(size, 0);

  // 2. 스택 선언
  stack<int> price;
  price.push(0);

  int idx = 1;
  while (idx < size)
  {
    if (price.empty())
      price.push(idx);
    else if (prices[price.top()] <= prices[idx])
      // 현재 값이 큰 경우
      price.push(idx);
    else
    {
      // 이전 값이 큰 경우
      while (!price.empty() && prices[price.top()] > prices[idx])
      {
        answer[price.top()] = idx - price.top();
        price.pop();
      }
      price.push(idx);
    }
    idx++;
  }

  while (!price.empty())
  {
    answer[price.top()] = size - 1 - price.top();
    price.pop();
  }

  return answer;
}