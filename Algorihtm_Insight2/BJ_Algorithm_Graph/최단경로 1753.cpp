/* 2015112119 ������ */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <queue>
using namespace std;
int dp[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int v, e, k, x, y, r, sum = 0;

	cin >> v >> e;
	cin >> k;

	vector<vector<pair<int, int>>> vec;

	vec.resize(v + 1);

	while (e--) {
		cin >> x >> y >> r;
		vec[x].push_back( make_pair(y, r) );
	}

	priority_queue<pair<int, int>> qu;
	qu.push(make_pair(0, k));

	while (!qu.empty()) {
		int tempx = qu.top().second;//���� ���� ��ȣ�� ����.
		int tempsum = qu.top().first;//�Ÿ��� ����
		qu.pop();

		if (dp[tempx]) continue;
		dp[tempx] = tempsum;

		for (int i = 0; i < vec[tempx].size(); i++) {
			
			if (dp[vec[tempx][i].first] || vec[tempx][i].first == k) continue;
			qu.push(make_pair((tempsum - vec[tempx][i].second), vec[tempx][i].first));//�Ÿ��� ���

		}

	}

	for (int i = 1; i <= v; i++) {
		if (dp[i] == 0 && i != k) cout << "INF" << '\n';
		else cout << -dp[i] << '\n';
	}
}