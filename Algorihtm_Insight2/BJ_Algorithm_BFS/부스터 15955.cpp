/* 2015112119 이현재 */

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

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)

bool dp[250001];
vector<pi> vec;
int n, q, x, y, a, b;

bool flag = false;

bool calculate(int x, pi a, pi b) {

	return pow(x,2) >= pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

void fun(int start) {

	if (start == b) {
		flag = true;
		return;
	}

	if (!dp[start]) {

		for (int i = 0; i < vec.size(); i++) {
			if (i + 1 == a) continue;//체크포인트가 같은 경우는 제외

			if (calculate(x, vec[start - 1], vec[i])) {
				//체력 내에 거리로 갈 수 있는경우
				dp[start] = true;
				fun(i + 1);
				dp[start] = false;
			}
			else if ((vec[start - 1].first == vec[i].first) || (vec[start - 1].second == vec[i].second)) {
				//체력 내 갈수없는 경우 체크포인트 중 x,y가 같은 포인트로 이동하게 큐에 삽입한다.
				//x나 y의 좌표가 같으면 부스터 이동이 가능하다. 이때 dp를 체크해주어 중복이 없도록 체크
				dp[start] = true;
				fun(i + 1);
				dp[start] = false;
			}
			else {
				for (int j = 0; j < vec.size(); j++) {
					if (j + 1 == start) continue;
					int tempx = min(abs(vec[i].first - vec[start - 1].first), abs(vec[i].second - vec[start -1].second));
	
					if (tempx > x) continue;
					else {
						dp[start] = true;
						fun(j + 1);
						dp[start] = false;
					}

				}
			}
		}
	}
}

int main() {

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		vec.push_back(mp(x, y));
	}

	while (q--) {
		cin >> a >> b >> x;

		fun(a);

		if (flag) cout << "YES\n";
		else cout << "NO\n";

		flag = false;
		memset(dp, false, sizeof(dp));
	}
}