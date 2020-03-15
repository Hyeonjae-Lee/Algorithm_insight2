
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

int arr[101];
int dp[101];

int main() {
	int n, k, Min=-999999;

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n - k + 1; i++) {
		
		for (int j = i; j < i + k; j++) dp[i] += arr[j];	

		Min = max(Min, dp[i]);
	}

	cout << Min;
}