// Level 2. 가장 큰 정사각형 찾기
// https://programmers.co.kr/learn/courses/30/lessons/12905?language=cpp

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    
    int rowSize = board.size();
    int colSize = board[0].size();
    
    for(int row=1; row<rowSize; row++) {
        for(int col=1; col<colSize; col++) {
            if(board[row][col]) {
                board[row][col] = min({board[row-1][col-1], board[row-1][col], board[row][col-1]}) + 1;
                if(board[row][col] > answer) answer = board[row][col];
            }
        }
    }
    return answer * answer;
}