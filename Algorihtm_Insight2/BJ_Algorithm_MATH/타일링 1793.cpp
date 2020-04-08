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

string dp[255];

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

int main() {
	int n;

	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";

	for (int i = 3; i < 253; i++) {
		dp[i] = addSrr(dp[i - 1], addSrr(dp[i - 2], dp[i - 2]));
	}

	while (cin >> n) {
		cout << dp[n] << "\n";
	}

}