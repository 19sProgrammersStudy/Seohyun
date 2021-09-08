// 14499번. 주사위 굴리기
// https://www.acmicpc.net/problem/14499

#include <iostream>

using namespace std;

#define DIR 5

#define DICE 6
#define TOP 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define FRONT 4
#define BOTTOM 5

#define MAX 20

int N, M, X, Y, K;
int dice[DICE] = {
		0,
};
int map[MAX][MAX];

int dx[DIR] = {0, 0, 0, -1, 1};
int dy[DIR] = {0, 1, -1, 0, 0};

int main()
{
	// 0. 입력 및 초기화
	cin >> N >> M >> X >> Y >> K;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> map[row][col];
		}
	}

	// 1. 주사위 굴리기
	int D;
	for (int test = 0; test < K; test++)
	{
		cin >> D;

		int nextX = X + dx[D];
		int nextY = Y + dy[D];

		// 1. 옮긴 위치가 지도 내이면
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
		{
			X = nextX;
			Y = nextY;
			int temp[DICE] = {
					0,
			};
			switch (D)
			{
			case 1:
				temp[FRONT] = dice[FRONT];
				temp[BACK] = dice[BACK];

				temp[TOP] = dice[LEFT];
				temp[RIGHT] = dice[TOP];
				temp[LEFT] = dice[BOTTOM];
				temp[BOTTOM] = dice[RIGHT];
				break;
			case 2:
				temp[FRONT] = dice[FRONT];
				temp[BACK] = dice[BACK];

				temp[TOP] = dice[RIGHT];
				temp[LEFT] = dice[TOP];
				temp[RIGHT] = dice[BOTTOM];
				temp[BOTTOM] = dice[LEFT];
				break;
			case 3:
				temp[LEFT] = dice[LEFT];
				temp[RIGHT] = dice[RIGHT];

				temp[TOP] = dice[BACK];
				temp[FRONT] = dice[TOP];
				temp[BOTTOM] = dice[FRONT];
				temp[BACK] = dice[BOTTOM];
				break;
			case 4:
				temp[LEFT] = dice[LEFT];
				temp[RIGHT] = dice[RIGHT];

				temp[TOP] = dice[FRONT];
				temp[BACK] = dice[TOP];
				temp[FRONT] = dice[BOTTOM];
				temp[BOTTOM] = dice[BACK];
				break;
			}

			if (map[X][Y] == 0)
			{
				map[X][Y] = temp[BOTTOM];
			}
			else
			{
				temp[BOTTOM] = map[X][Y];
				map[X][Y] = 0;
			}

			cout << temp[TOP] << endl;

			// 1-2. 이동한 값으로 업데이트
			for (int idx = 0; idx < DICE; idx++)
				dice[idx] = temp[idx];
		}
	}

	return 0;
}