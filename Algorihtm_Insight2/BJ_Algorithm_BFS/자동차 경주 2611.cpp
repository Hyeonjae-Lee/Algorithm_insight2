/* 2015112119 이현재 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <bitset>
#include <queue>
using namespace std;

bool check[1001][1001];
int n, m, p, q, r;
int mmax = 0, checki = 0, tempx=0, tempsum =0;

vector<vector<pair<int, int>>> vec;
priority_queue <pair<int,int>> ans;
vector<int> myvec;
/*void dfs(int start, int sum) {

	if (start == 1 && ans.size() != 1) {
		myvec.push_back(ans);
		sumvec.push_back(sum);
		return;
	}

	for (int i = 0; i < vec[start].size(); i++) {
		if (!check[start][vec[start][i].first]) {//아직 지나지 못했을 경우
			check[start][vec[start][i].first] = true;

			ans.push_back(vec[start][i].first);

			dfs(vec[start][i].first, sum + vec[start][i].second);

			ans.pop_back();

			check[start][vec[start][i].first] = false;
		}
	}
}*/

int main() {
	cin >> n;
	cin >> m;

	vec.resize(n+1);
	while (m--) {
		cin >> p >> q >> r;
		vec[p].push_back(make_pair(q, r));
	}
	
	ans.push(make_pair(1,0));
	//dfs(1, 0);
	vector<int> cost(n+1, 0);
	myvec.resize(n + 1);
	bool check = false;

	while (!ans.empty()) {

		tempx = ans.top().first;
		tempsum = ans.top().second;
		ans.pop();

		if (tempx == 1) {
			if (!check) check = true;
			else continue;
		}

		for (int i = 0; i < vec[tempx].size(); i++) {

			if (tempsum + vec[tempx][i].second > cost[vec[tempx][i].first]) {
				cost[vec[tempx][i].first] = tempsum + vec[tempx][i].second;
				ans.push(make_pair(vec[tempx][i].first, tempsum + vec[tempx][i].second));
				myvec[vec[tempx][i].first] = tempx;
			}

		}
	}

	cout << cost[1] << '\n' << 1<<' ';
	deque<int> answer;
	int i= myvec[1];
	do {
		answer.push_front(i);
		i = myvec[i];
	} while (i != 1);

	for (auto ele : answer) cout << ele << ' ';
	cout << 1;
}