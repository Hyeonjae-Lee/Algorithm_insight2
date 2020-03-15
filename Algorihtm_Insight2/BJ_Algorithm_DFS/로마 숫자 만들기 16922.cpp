/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

int arr[4] = { 1,5,10,50 };
int n;

set<int> vec;
int dp[10001];

void fundfs(int start, int sum) {

	if (sum > 1000) return;

	if (start == n) {
		vec.insert(sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		fundfs(start + 1, sum + arr[i]);
	}
}

int Count = 0;

vector<int> vec2;

void funbfs(int a) {
	queue<int> qu;

	qu.push({ 1});
	qu.push({ 5 });
	qu.push({ 10 });
	qu.push({ 50 });

	for (int k = 0; k < n-1; k++) {

		memset(dp, 0, sizeof(dp));

		int templength = qu.size();

		for (int i = 0; i < templength; i++) {

			int temp = qu.front();
			qu.pop();

			for (int j = 0; j < 4; j++) {
				if (dp[temp + arr[j]] == 0) {
					qu.push(temp + arr[j]);
					dp[temp + arr[j]] = 1;
				}
			}

		}
	}

	Count = qu.size();
}

int main() {
	cin >> n;
	//fundfs(0, 0);
	//cout << vec.size();

	funbfs(0);
	cout << Count;

	//for (auto ele : vec2) cout << ele << " ";
	//cout << endl;

	//cout << vec2.size();
}