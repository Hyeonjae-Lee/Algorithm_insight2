#include <iostream>
#include <algorithm>
#include <vector>

#define pi pair<int ,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

long long dp[1500002];
vector<pi> vec;

int main() {
	int n;
	int t, p;

	cin >> n;

	vec.push_back(mp(0, 0));

	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		vec.push_back(mp(t, p));
	}
	vec.push_back(mp(0, 0));

	long long maxsum = 0;

	for (int i = 1; i <= n + 1; i++) {
		maxsum = (maxsum > dp[i] ? maxsum : dp[i]);
		if (i + vec[i].first > n + 1) continue;
		dp[i + vec[i].first] = (dp[i + vec[i].first] > (maxsum + vec[i].second) ? dp[i + vec[i].first] : (maxsum + vec[i].second));
	}

	cout << maxsum;
}