/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

std::string addSrr(string arr, string brr) {
	string answer = "";
	string temp = "";
	int temp4 = 0;

	while (!arr.empty() && !brr.empty()) {//두개 중 하나가 빌때

		int temp1 = arr.back() - '0';
		arr.pop_back();
		int temp2 = brr.back() - '0';
		brr.pop_back();
		int temp3 = temp1 + temp2 + temp4;
		if (temp3 > 9) {
			temp4 = 1;
			temp3 -= 10;
		}
		else {
			temp4 = 0;
		}
		answer += temp3 + '0';
	}
	if (!arr.empty()) {
		while (!arr.empty()) {
			int temp1 = arr.back() - '0';
			arr.pop_back();
			int temp3 = temp1 + temp4;
			if (temp3 > 9) {
				temp4 = 1;
				temp3 -= 10;
			}
			else {
				temp4 = 0;
			}
			answer += temp3 + '0';
		}
	}
	else if (!brr.empty()) {
		while (!brr.empty()) {
			int temp1 = brr.back() - '0';
			brr.pop_back();
			int temp3 = temp1 + temp4;
			if (temp3 > 9) {
				temp4 = 1;
				temp3 -= 10;
			}
			else {
				temp4 = 0;
			}
			answer += temp3 + '0';
		}
	}

	if (temp4 == 1) answer += 1 + '0';

	reverse(answer.begin(), answer.end());
	return answer;
}

string dp[101][102];

string solve(long long n, long long r) {
	r = min(r, n - r);
	if (dp[n][r] != "" ) { return dp[n][r]; }
	if (r == 1) {
		dp[n][r] = to_string(n);
		return dp[n][r];
	}
	if (n == r) return "1";

	dp[n][r] = addSrr(solve(n - 1, r), solve(n - 1, r - 1));

	return dp[n][r];
}

int main() {
	int n, r;

	cin >> n >> r;

	cout << solve(n, r);
}