// 3190번. 뱀
// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <queue>

using namespace std;

#define MAX 100
#define DIR 4

int map[MAX][MAX] = { 0, };

int dr[DIR] = { -1, 0, 1, 0 };
int dc[DIR] = { 0, 1, 0, -1 };

struct snake {
	deque<pair<int, int>> body;
	int dir = 1;
};

int main() {
	// 0. 입력 및 초기화
	int N, K, L;
	cin >> N >> K;

	int row, col;
	for (int apple = 0; apple < K; apple++) {
		cin >> row >> col;
		map[row - 1][col - 1] = 1;
	}

	cin >> L;
	queue<pair<int, char>> turning;
	for (int turn = 0; turn < L; turn++) {
		int time; char dir;
		cin >> time >> dir;
		turning.push(make_pair(time, dir));
	}
	
	// 1. 뱀 선언
	snake dummy;
	dummy.body.push_back(make_pair(0, 0));
	map[0][0] = 2;

	// 2. 뱀 이동
	int time = 0;
	bool isEnd = false;
	while (!isEnd) {
		time++;

		int nextR = dummy.body.front().first + dr[dummy.dir];
		int nextC = dummy.body.front().second + dc[dummy.dir];

		if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && map[nextR][nextC] != 2) { // 2-1. 뱀이 이동할 수 있으면
			// 2-1-1. 사과가 없으면 꼬리 비우기
			if(!map[nextR][nextC]) {
				map[dummy.body.back().first][dummy.body.back().second] = 0;
				dummy.body.pop_back();
			}
			dummy.body.push_front(make_pair(nextR, nextC));
			map[nextR][nextC] = 2;
		}
		else { // 2-2. 뱀이 이동할 수 없으면
			isEnd = true;
			break;
		}

		// 2-3. 방향을 바꿔야하는가?
 		if (!turning.empty() && time == turning.front().first) {
			switch (turning.front().second) {
			case 'L':
				(dummy.dir - 1 < 0) ? dummy.dir = 3 : dummy.dir -= 1;
				break;
			case 'D':
				(dummy.dir + 1 == DIR) ? dummy.dir = 0 : dummy.dir += 1;
				break;
			}
			turning.pop();
		}
	}

	cout << time << endl;

	return 0;
}