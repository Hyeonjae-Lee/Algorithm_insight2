/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <queue>
using namespace std;

bool check[401][401];
bool check1[401];
vector<vector<int>> myvec;
int ans = 0;

void dfs(int start) {
	if (start == 2) {
		ans++;
		return;
	}

	/*for (int i = 0; i < myvec[start].size(); i++) {
		if (!check[start][myvec[start][i]]) {
			check[start][myvec[start][i]] = true;
			dfs(myvec[start][i]);
		}
	}*/
	for (int i = 0; i < myvec[start].size(); i++) {
		if (!check1[start]) {
			check1[start] = true;
			dfs(myvec[start][i]);
		}
	}
}

int main() {
	int n, p, x, y;

	cin >> n >> p;
	myvec.resize(n + 1);
	while (p--) {
		cin >> x >> y;
		myvec[x].push_back(y);
	}

	dfs(1);

	queue<int> qu;

	/*while (!qu.empty()) {
		int tempx = qu.front();
		qu.pop();

		if (tempx == 2) {
			ans++;
		}

		for (int i = 0; i < myvec[tempx].size(); i++) {
			
			if (!check[tempx][myvec[tempx][i]]) {
				check[tempx][myvec[tempx][i]] = true;
				qu.push(myvec[tempx][i]);
			}

			if (!check1[tempx]) {
				check1[tempx] = true;
				qu.push(myvec[tempx][i]);
			}

		}

	}*/

	cout << ans;
}