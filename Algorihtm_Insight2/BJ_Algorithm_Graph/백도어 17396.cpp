
/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

#define lli long long
#define pi pair<lli,int> 
#define mp(a,b) make_pair(a,b) 

int arr[100001];
bool visited[100001];
vector<pi> vec[100001];
lli dp[100001];

const lli lnf = (1LL << 60);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	int n, m, start, end, value;

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	arr[n - 1] = 0;

	while (m--) {
		cin >> start >> end >> value;
		vec[start].push_back(mp(end, -value));
		vec[end].push_back(mp(start, -value));
	}

	priority_queue<pi>qu;
	qu.push(mp(0, 0));// 그 시간과 분기점
	
	for (int i = 0; i < n; i++) dp[i] = lnf;
	dp[0] = 0;

	while (!qu.empty()) {
		pi temp = qu.top();
		qu.pop();

		if (!visited[temp.second]) {
			
			for (int i = 0; i < vec[temp.second].size(); i++) {

				if ( arr[vec[temp.second][i].first] == 0 && !visited[vec[temp.second][i].first] ) {

					if (dp[vec[temp.second][i].first] > (dp[temp.second] - vec[temp.second][i].second)) {
						dp[vec[temp.second][i].first] = (dp[temp.second] - vec[temp.second][i].second);
						qu.push(mp(-dp[vec[temp.second][i].first], vec[temp.second][i].first));
					}
				}
			}
			
			visited[temp.second] = true;
		}
	}

	if (dp[n - 1] != lnf) cout << dp[n - 1];
	else cout << -1;

}