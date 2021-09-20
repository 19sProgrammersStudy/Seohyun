// 20058번. 마법사 상어와 파이어스톰
// https://www.acmicpc.net/problem/20058

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define CNT 2
#define DIR 4
#define MAX 64

int N, Q, L;
int map[CNT][MAX][MAX];

int dr[DIR] = { -1, 1, 0, 0 };
int dc[DIR] = { 0, 0, -1, 1 };

int cur, fut;

void rotation(int r, int c, int len) {
	// 격자를 90도 방향으로 회전(row -> col)
	int rEnd = r + len;
	int cEnd = c + len;

	int curC = c;
	for (int row = r; row < rEnd; row++) {
		int curR = rEnd - 1;
		for (int col = c; col < cEnd; col++) {
			map[fut][row][col] = map[cur][curR--][curC];
		}
		curC++;
	}
}

vector<int> getAnswer() {
	int answer = 0;
	int max = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (map[cur][row][col] > 0) {
				int size = 1;
				answer += map[cur][row][col];
				map[cur][row][col] = -1;

				queue<pair<int, int>> visit;
				visit.push(make_pair(row, col));

				while (!visit.empty()) {
					int r = visit.front().first;
					int c = visit.front().second;
					visit.pop();

					for (int d = 0; d < DIR; d++) {
						int nR = r + dr[d];
						int nC = c + dc[d];

						if (nR >= 0 && nR < N && nC >= 0 && nC < N && map[cur][nR][nC] >= 1) {
							answer += map[cur][nR][nC];
							map[cur][nR][nC] = -1;
							size++;
							visit.push(make_pair(nR, nC));
						}
					}
				}

				if (size > max) max = size;
			}
		}
	}

	vector<int> result;
	result.push_back(answer);
	result.push_back(max);

	return result;
}

int main() {
	// 0. 입력 및 초기화
	cin >> N >> Q;

	N = pow(2, N);
	cur = 0;
	fut = 1 - cur;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> map[cur][row][col];
		}
	}

	// 1. Q번 반복
	for (int t = 0; t < Q; t++) {
		cin >> L;

		// 1-1. 모든 격자를 시계 방향으로 90도 회전
		for (int row = 0; row + pow(2, L) <= N; row += pow(2, L)) {
			for (int col = 0; col + pow(2, L) <= N; col += pow(2, L)) {
				rotation(row, col, pow(2, L));
			}
		}

		// 1-2. 인접한 칸에 얼음이 2개 이하인 경우 얼음 양 줄이기
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				int cnt = DIR;

				for (int d = 0; d < DIR; d++) {
					int nRow = row + dr[d];
					int nCol = col + dc[d];

					if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < N) {
						if (map[fut][nRow][nCol] == 0) cnt--;
					}
					else
						cnt--;
				}

				if (cnt < 3 && map[fut][row][col] > 0)
					map[cur][row][col] = map[fut][row][col] - 1;
				else
					map[cur][row][col] = map[fut][row][col];
			}
		}

	}

	// 2. 정답 구하기
	vector<int> answer = getAnswer();
	cout << answer[0] << endl << answer[1] << endl;

	return 0;
}