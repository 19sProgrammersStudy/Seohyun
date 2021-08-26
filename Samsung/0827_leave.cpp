// 14501번. 퇴사
// https://www.acmicpc.net/problem/14501

#include <iostream>

using namespace std;

#define MAX 15
#define INFO 2

int N, maxEarn;
int counseling[MAX][INFO];

void dfs(int start, int curEarn) {
	if (start >= N) {
		if (curEarn > maxEarn) maxEarn = curEarn;
		return;
	}

	for (int idx = start + counseling[start][0]; idx <= N; idx++)
		dfs(idx, curEarn + counseling[start][1]);
}

int main()
{
	cin >> N;

	maxEarn = 0;
	for (int idx = 0; idx < N; idx++) {
		for (int info = 0; info < INFO; info++)
			cin >> counseling[idx][info];
	}

	for (int idx = 0; idx < N; idx++)
		dfs(idx, 0);

	cout << maxEarn << endl;

	return 0;
}