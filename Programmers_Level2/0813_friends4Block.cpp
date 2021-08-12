// Level 2. [1차] 프렌즈4블록
// https://programmers.co.kr/learn/courses/30/lessons/17679?language=cpp

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<string> board)
{
  int answer = 0;
  int rowSize = board.size();
  int colSize = board[0].size();

  // 0. 삭제할 블록과 이동할 블록을 담을 자료구조 선언
  queue<pair<int, int>> delBlock;
  queue<char> movBlock;

  while (true)
  {
    // 1. 삭제할 블록 탐색
    for (int row = 0; row < rowSize - 1; row++)
    {
      for (int col = 0; col < colSize - 1; col++)
      {
        if (board[row][col] != ' ' &&
            board[row][col] == board[row][col + 1] &&
            board[row][col] == board[row + 1][col] &&
            board[row][col] == board[row + 1][col + 1])
        {
          delBlock.push(make_pair(row, col));
          delBlock.push(make_pair(row, col + 1));
          delBlock.push(make_pair(row + 1, col));
          delBlock.push(make_pair(row + 1, col + 1));
        }
      }
    }

    // 1-1. 삭제할 블록이 없으면 종료
    if (delBlock.empty())
      break;

    // 2. 블록 삭제
    while (!delBlock.empty())
    {
      // 2-1. 중복될 수 있으니 빈칸이 아닌 경우에만 증가
      if (board[delBlock.front().first][delBlock.front().second] != ' ')
      {
        board[delBlock.front().first][delBlock.front().second] = ' ';
        answer++;
      }
      delBlock.pop();
    }

    // 3. 블록 내리기
    for (int col = 0; col < colSize; col++)
    {
      int topRow = -1;
      for (int row = rowSize - 1; row >= 0; row--)
      {
        if (topRow == -1 && board[row][col] == ' ')
          topRow = row;
        if (topRow != -1 && board[row][col] != ' ')
        {
          movBlock.push(board[row][col]);
          board[row][col] = ' ';
        }
      }

      if (movBlock.empty())
        continue;
      while (!movBlock.empty())
      {
        board[topRow][col] = movBlock.front();
        topRow--;
        movBlock.pop();
      }
    }
  }
  return answer;
}