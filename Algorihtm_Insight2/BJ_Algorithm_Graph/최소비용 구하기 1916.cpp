/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <queue>
using namespace std;

#define p_i pair<int, int> 
#define m_p(a,b) make_pair(a,b)

int dp[1001];

int main() {
	int n, m, x, y, r, start, end;
	vector<vector<p_i>> vec;
	cin >> n >> m;

	vec.resize(n + 1);
	
	while (m--) {
		cin >> x >> y >> r;
		vec[x].push_back(m_p(y, r));
	}

	cin >> start >> end;

	priority_queue<p_i> qu;
	qu.push(m_p(0, start));

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

	cout << -dp[end];
}