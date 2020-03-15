/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

long long  arr[501][501];
long long dp[501][501];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

long long dfs(int a, int b) {

	if (a == n-1 && b == m-1) return 1;
	if (dp[a][b] >= 0) return dp[a][b];

	dp[a][b] = 0;
	for (int i = 0; i < 4; i++) {

		int nx = a + dx[i];
		int ny = b + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (arr[nx][ny] < arr[a][b]) dp[a][b] = dp[a][b] + dfs(nx, ny);
		}
	}

	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	
	cout << dfs(0, 0);
}
