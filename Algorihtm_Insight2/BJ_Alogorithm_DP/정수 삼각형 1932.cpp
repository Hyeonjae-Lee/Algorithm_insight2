#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[502][502];
int arr[502][502];

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j] = max(arr[i][j] + dp[i - 1][j], dp[i][j]);
			dp[i][j + 1] = arr[i][j+1] + dp[i - 1][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer = max(answer, dp[n - 1][i]);
	}
	cout << answer;
}