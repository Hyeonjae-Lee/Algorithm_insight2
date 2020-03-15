/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
using namespace std;

int dp[30];

int main() {
	int n, x=28;

	while (x--) {
		cin >> n;
		dp[n-1] = n;
	}

	for (int i = 0; i < 30; i++) if (!dp[i]) cout << i + 1 << '\n';
}