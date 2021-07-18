// Level 1. 크레인 인형 뽑기
// https://programmers.co.kr/learn/courses/30/lessons/64061?language=cpp

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
  int answer = 0;
  int size = board.size();

  stack<int> bucket;
  stack<int> game_board[size];

  // 보드를 스택으로 저장
  for (int row = size - 1; row >= 0; row--)
  {
    for (int col = 0; col < size; col++)
      if (board[row][col])
        game_board[col].push(board[row][col]);
  }

  for (int idx = 0; idx < moves.size(); idx++)
  {
    int column = moves[idx] - 1;

    if (game_board[column].empty())
      continue; // 해당 열에 인형이 없으면 패스

    if (bucket.empty())
    {
      bucket.push(game_board[column].top());
      game_board[column].pop();
    }
    else if (bucket.top() == game_board[column].top())
    {
      bucket.pop();
      game_board[column].pop();
      answer += 2;
    }
    else
    {
      bucket.push(game_board[column].top());
      game_board[column].pop();
    }
  }

  return answer;
}