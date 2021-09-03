// 21610번. 마법사 상어와 비바라기
// https://www.acmicpc.net/problem/21610

#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;

#define CNT 2
#define DIR 8
#define MAX 50

int dr[DIR] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[DIR] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int map[CNT][MAX][MAX];


int main() {
	// 0. 입력 및 초기화
	int N, M;
	cin >> N >> M;

	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++) {
			cin >> map[0][row][col];
			map[1][row][col] = map[0][row][col];
		}

	// 1. 초기 구름 생성
	queue<pair<int, int>> cloud;
	cloud.push(make_pair(N - 1, 0));
	cloud.push(make_pair(N - 1, 1));
	cloud.push(make_pair(N - 2, 0));
	cloud.push(make_pair(N - 2, 1));

	// 2. 방향 지시
	int cur = 0;
	int dir, distance;
	for (int move = 0; move < M; move++) {
		cin >> dir >> distance;

		// 2-1. 모든 구름의 이동 위치에 물의 양을 증가 a/다음 지도
		queue<pair<int, int>> newCloud;

		while (!cloud.empty()) {
			int nextR = (cloud.front().first + dr[dir - 1] * distance) % N;
			int nextC = (cloud.front().second + dc[dir - 1] * distance) % N;
			cloud.pop();

			if (nextR < 0) nextR = N - abs(nextR);
			if (nextC < 0) nextC = N - abs(nextC);

			map[(cur + 1) % CNT][nextR][nextC]++;
			map[cur][nextR][nextC] = -1; // 2-1-1. 구름이 있었음을 표시
			newCloud.push(make_pair(nextR, nextC));
		}

		// 2-2. 물의 양이 증가한 곳에서 물복사 시전
		while (!newCloud.empty()) {
			int r = newCloud.front().first;
			int c = newCloud.front().second;
			newCloud.pop();

			int water = 0;
			for (int idx = 1; idx < DIR; idx+=2) {
				int nextR = r + dr[idx];
				int nextC = c + dc[idx];

				if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && map[(cur + 1) % CNT][nextR][nextC])
					water++;
			}

			map[(cur + 1) % CNT][r][c] += water;
		}

		// 2-3. 물의 양이 2 이상인 모든 칸에 구름 생성
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (map[(cur + 1) % CNT][row][col] >= 2 && map[cur][row][col] != -1) {
					cloud.push(make_pair(row, col));
					map[(cur + 1) % CNT][row][col] -= 2;
				}
			}
		}

		memcpy(map[cur], map[(cur + 1) % CNT], sizeof(map[cur])); // 3. 맵 복사
		cur = (cur + 1) % CNT;
	}
	
	
	int answer = 0;
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			answer += map[cur][row][col];

	cout << answer << endl;

	return 0;
}