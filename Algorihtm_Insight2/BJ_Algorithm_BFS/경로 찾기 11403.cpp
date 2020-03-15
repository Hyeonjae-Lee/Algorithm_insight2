/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int arr[101][101];
int dp[101][101];
bool check[101][101];
int check1[101];
int N;

void fun(int start, int end, int depth) {

	if (!check[depth][end]) {//여기를 지나지 않았을경우
		check[depth][end] = true;
		check[start][end] = true;

		dp[depth][end] = 1;
		for (int i = 0; i < N; i++) {
			if (arr[end][i] == 1) {
				fun(end, i, depth);
			}
		}

	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				memset(check, false, sizeof(check));
				//memset(check1, -1, sizeof(check1));
				fun(i, j, i);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j] << " ";
		}cout << '\n';
	}
}