/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <queue>
#include <limits.h>
#include <cstdio>

using namespace std;
#define p_i pair<int, int> 
#define m_p(a,b) make_pair(a,b)

vector<int> dp(1002, 0);

int main() {
	int n, m, x, a, b, r, ans=0;

	cin >> n >> m >> x;
	vector<vector<p_i>> vec;
	vec.resize(n + 1);

	while (m--) {
		cin >> a >> b >> r;
		vec[a].push_back(m_p(b, r));
	}

	priority_queue<p_i> qu;

	for (int i = 1; i <= n; i++) {
		if (i != x) {
			qu.push(m_p(0, i));

			/*while (!qu.empty()) {

				p_i temp = qu.top();
				qu.pop();

				if (dp[temp.second] < -temp.first) continue;

				for (int j = 0; j < vec[temp.second].size(); j++) {

					if (dp[vec[temp.second][j].first] > -temp.first + vec[temp.second][j].second) {
						dp[vec[temp.second][j].first] = -temp.first + vec[temp.second][j].second;
						qu.push(m_p(temp.first - vec[temp.second][j].second, vec[temp.second][j].first));
					}

				}

			}*/
			while (!qu.empty()) {
				p_i temp = qu.top();
				qu.pop();

				if (dp[temp.second]) continue;
				dp[temp.second] = temp.first;

				for (int i = 0; i < vec[temp.second].size(); i++) {
					if (dp[vec[temp.second][i].first]) continue;
					qu.push(m_p(-vec[temp.second][i].second + temp.first, vec[temp.second][i].first));
				}
			}

			int ansx = dp[x];

			dp.clear();
			//dp.resize(1002, INT_MAX);
			dp.resize(1002, 0);
			qu.push(m_p(0, x));

			/*while (!qu.empty()) {

				p_i temp = qu.top();
				qu.pop();

				if (dp[temp.second] < -temp.first) continue;

				for (int j = 0; j < vec[temp.second].size(); j++) {

					if (dp[vec[temp.second][j].first] > -temp.first + vec[temp.second][j].second) {
						dp[vec[temp.second][j].first] = -temp.first + vec[temp.second][j].second;
						qu.push(m_p(temp.first - vec[temp.second][j].second, vec[temp.second][j].first));
					}

				}
			}*/
			while (!qu.empty()) {
				p_i temp = qu.top();
				qu.pop();

				if (dp[temp.second]) continue;
				dp[temp.second] = temp.first;

				for (int i = 0; i < vec[temp.second].size(); i++) {
					if (dp[vec[temp.second][i].first]) continue;
					qu.push(m_p(-vec[temp.second][i].second + temp.first, vec[temp.second][i].first));
				}
			}

			ans = max(ans, -ansx - dp[i]);

			dp.clear();
			//dp.resize(1002, INT_MAX);
			dp.resize(1002, 0);
		}
	}
	
	cout << ans;
}