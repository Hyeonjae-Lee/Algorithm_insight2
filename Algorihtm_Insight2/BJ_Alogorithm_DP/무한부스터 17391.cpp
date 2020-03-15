
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <queue>
#include <set>

using namespace std;

int arr[301][301];
int dp[301][301];
bool check[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	queue<pair<int, int>> qu;
	qu.push(make_pair(0, 0));

	for (int i = 0; i <= n; i++) {
		fill_n(dp[i], n + 1, 305);
	}

	dp[0][0] = 0;

	while (!qu.empty()) {
		pair<int, int> temp = qu.front();
		qu.pop();

		if (temp == make_pair(n - 1, m - 1)) {
			break;
		}

		for (int i = 1; i <= arr[temp.first][temp.second]; i++) {

			if (!check[temp.first][temp.second + i] && temp.second + i < m) {

				dp[temp.first][temp.second + i] = dp[temp.first][temp.second] + 1;
				qu.push(make_pair(temp.first, temp.second + i));
				check[temp.first][temp.second + i] = true;

			}
			if (!check[temp.first + i][temp.second] && temp.first + i < n) {

				dp[temp.first + i][temp.second] = dp[temp.first][temp.second] + 1;
				qu.push(make_pair(temp.first + i, temp.second));
				check[temp.first + i][temp.second] = true;

			}

		}

	}

	cout << dp[n - 1][m - 1];

}