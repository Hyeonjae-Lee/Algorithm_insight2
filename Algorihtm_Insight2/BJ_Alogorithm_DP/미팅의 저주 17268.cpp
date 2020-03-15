/* 2015112119 이현재 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

long long dp[10002], n;

int main() {
	//https://oeis.org/ 이 사이트를 잘 봐두어야한다.
	cin >> n;
	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;
	dp[6] = 5;

	for (int i = 8; i <= n; i += 2) {
		for (int j = 0; j < i; j += 2) {
			dp[i] += (dp[j] % 987654321) * (dp[i -2- j] % 987654321);
			dp[i] %= 987654321;
		}dp[i] %= 987654321;
	}

	cout << dp[n];
}