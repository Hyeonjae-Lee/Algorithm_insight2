/* 2015112119 ÀÌÇöÀç */

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int arr[102][102];
bool check[102][102];

int m, n, k;

int answer = 0;

int dfs(int a, int b) {
	check[a][b] = true;
	int ans = 1;

	if (a + 1 < m && arr[a+1][b] == 0 && !check[a + 1][b]) {
		check[a + 1][b] = true;
		ans += dfs(a + 1, b);
	}
	if (a - 1 >= 0 && arr[a - 1][b] == 0 && !check[a - 1][b]) {
		check[a - 1][b] = true;
		ans += dfs(a - 1, b);
	}
	if (b - 1 >= 0 && arr[a][b - 1] == 0 && !check[a][b - 1]) {
		check[a][b - 1] = true;
		ans += dfs(a, b - 1);
	}
	if (b + 1 < n && arr[a][b + 1] == 0 && !check[a][b + 1]) {
		check[a][b + 1] = true;
		ans += dfs(a, b + 1);
	}

	return ans;
}

int main() {
	int x1, y1, x2, y2;
	cin >> m >> n >> k;
	int Finalanswer = 0;

	while (k--) {
		cin >> y1 >> x1 >> y2 >> x2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				arr[i][j] = 1;
			}
		}
	}

	vector<int> vec;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && !arr[i][j]) {
				int temp = dfs(i, j);
				Finalanswer++;
				vec.push_back(temp);
				answer = 0;
			}
		}
	}

	cout << Finalanswer<<endl;
	sort(vec.begin(), vec.end());
	for (int a : vec) cout << a << " ";
}