// 17822번. 원판 돌리기
// https://www.acmicpc.net/problem/17822

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define MAP 2
#define CUR 0
#define FUT 1
#define DIR 4
#define MAX 50

int N, M, T;
int circle[MAP][MAX][MAX];

int dr[DIR] = {-1, 1, 0, 0};
int dc[DIR] = {0, 0, -1, 1};

void rotation(int x, int d, int k)
{
	for (int row = x - 1; row < N; row += x)
	{
		int temp[MAX] = {
				0,
		};

		for (int col = 0; col < M; col++)
		{
			int idx = (col + (d * k)) % M;
			if (idx < 0)
				idx = M + idx;
			temp[idx] = circle[CUR][row][col];
		}

		for (int col = 0; col < M; col++)
		{
			circle[CUR][row][col] = circle[FUT][row][col] = temp[col];
		}
	}
}

void neighbor()
{
	// 인접한 위치에 같은 수가 있는지 확인
	bool visit[MAX][MAX] = {
			false,
	};

	float total = 0;
	int cnt = 0;
	bool isExist = false;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			// 0. 평균 구하기용
			if (circle[CUR][row][col])
			{
				total += circle[CUR][row][col];
				cnt++;
			}

			if (!visit[row][col])
			{ // 1. 방문하지 않았으면
				visit[row][col] = true;

				// 1-0. 값이 0이면 방문하고 지나간다
				if (circle[CUR][row][col] == 0)
					continue;

				queue<pair<int, int>> del;
				queue<pair<int, int>> check;
				del.push(make_pair(row, col));
				check.push(make_pair(row, col));

				while (!del.empty())
				{
					int r = del.front().first;
					int c = del.front().second;
					del.pop();

					for (int d = 0; d < DIR; d++)
					{
						int nr = r + dr[d];

						int nc = c + dc[d];
						if (nc < 0)
							nc = M + nc;
						if (nc >= M)
							nc = M - nc;

						if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visit[nr][nc])
						{
							if (circle[CUR][nr][nc] == circle[CUR][row][col])
							{
								visit[nr][nc] = true;
								del.push(make_pair(nr, nc));
								check.push(make_pair(nr, nc));
							}
						}
					}
				}

				if (check.size() > 1)
				{ // 1-3. 인접한 수가 있으면
					isExist = true;
					while (!check.empty())
					{
						int r = check.front().first;
						int c = check.front().second;
						check.pop();

						circle[FUT][r][c] = 0;
					}
				}
			}
		}
	}

	// 2. 인접한 수가 없었으면 원판의 합에서 평균보다 작은 수, 큰 수를 뺀다
	if (!isExist)
	{
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < M; col++)
			{
				if (circle[CUR][row][col] == 0)
					continue;
				else if (circle[CUR][row][col] > (total / cnt))
					circle[FUT][row][col] = circle[CUR][row][col] - 1;
				else if (circle[CUR][row][col] < (total / cnt))
					circle[FUT][row][col] = circle[CUR][row][col] + 1;
			}
		}
	}
}

int main()
{
	// 0. 입력 및 초기화
	cin >> N >> M >> T;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> circle[CUR][row][col];
			circle[FUT][row][col] = circle[CUR][row][col];
		}
	}

	// 1. 원판 T번 돌리기
	int x, d, k;
	for (int t = 1; t <= T; t++)
	{
		cin >> x >> d >> k;

		// 1-1. 원판 돌리기
		(d == 0) ? d = 1 : d = -1;
		rotation(x, d, k);

		// 1-2. 인접한 위치에 같은 수가 있는지 확인
		neighbor();

		// 1-3. 원판 복사
		memcpy(circle[CUR], circle[FUT], sizeof(circle[CUR]));
	}

	// 2. 정답 구하기
	int answer = 0;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			answer += circle[CUR][row][col];
		}
	}

	cout << answer << endl;

	return 0;
}