// 16236번. 아기 상어
// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 20
#define SHARK 9

#define DIR 4

int dr[DIR] = { -1, 1, 0, 0 };
int dc[DIR] = { 0, 0, -1, 1 };

struct shark {
	int r, c;
	int size = 2;
	int cnt = 0;
};

struct fish {
	int r, c;
	int dist = 0;
};

struct compare {
	bool operator()(fish a, fish b) {
		if (a.dist != b.dist) return a.dist > b.dist;
		else if (a.dist == b.dist) {
			if (a.r != b.r) return a.r > b.r;
			else if (a.r == b.r) return a.c > b.c;
		}
	}
};

int N;
int map[MAX][MAX];

shark baby;
int remainFish = 0;

int bfs() {
	queue<fish> move;
	fish cur;
	cur.r = baby.r; cur.c = baby.c;
	move.push(cur);

	priority_queue<fish, vector<fish>, compare> get;

	int min_length = 100000;
	bool visit[MAX][MAX] = { false, };

	// 1. 이동 가능한 위치를 탐색
	while (!move.empty()) {
		int curR = move.front().r;
		int curC = move.front().c;
		int curD = move.front().dist;
		visit[curR][curC] = true;
		move.pop();

		if (curD > min_length) break;

		for (int d = 0; d < DIR; d++) {
			int nextR = curR + dr[d];
			int nextC = curC + dc[d];

			if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && !visit[nextR][nextC]) {
				visit[nextR][nextC] = true;

				// 1-1. 아기 상어보다 큰 물고기는 피해가기
				if (map[nextR][nextC] > baby.size) continue;

				// 1-2. 빈 칸이거나 크기가 같은 물고기가 있으면 이동
				else if (!map[nextR][nextC] || map[nextR][nextC] == baby.size) {
					fish temp;
					temp.r = nextR; temp.c = nextC;
					temp.dist = curD + 1;
					move.push(temp);
				}
				// 1-3. 아기상어보다 작은 물고기가 있으면 잡기
				else if(map[nextR][nextC] > 0 && map[nextR][nextC] < baby.size) {
					fish temp;
					temp.r = nextR; temp.c = nextC;
					temp.dist = min_length = curD + 1;
					get.push(temp);
				}
			}
		}
	}

	if (get.empty()) return -1;

	fish target = get.top();
	baby.r = target.r;
	baby.c = target.c;
	baby.cnt++;

	map[baby.r][baby.c] = 0;
	remainFish--;

	if (baby.cnt == baby.size) {
		baby.size++;
		baby.cnt = 0;
	}

	return target.dist;
}

int main() {
	// 0. 입력 및 초기화
	cin >> N;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> map[row][col];

			if (map[row][col] > 0 && map[row][col] < 9) {
				remainFish++;
			}
			else if (map[row][col] == 9) {
				baby.r = row; baby.c = col;
				map[row][col] = 0;
			}
		}
	}

	// 1. 이동
	int time = 0;
	while (remainFish) {
		int move = bfs();
		if (move != -1)
			time += move;
		else break;
	}
	
	cout << time << endl;
	
	return 0;
}