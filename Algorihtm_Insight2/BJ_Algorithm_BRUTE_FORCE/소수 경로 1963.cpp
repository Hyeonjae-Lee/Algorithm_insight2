/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

bool prime[10000];
bool check[10000];

int fun(int start, int end) {
	queue<pair<int,int>> qu;
	check[start] = true;
	qu.push(make_pair(start,0));

	while (!qu.empty()) {
		int temp = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		if (temp == end) {
			return cnt;
		}
		else {//이미 체크가 되어있을경우		
			for (int i = 0; i < 4; i++) {

				if (i == 0) {
					int tx = temp % 10;
					int temp2 = temp;
					temp2 -= tx;
					for (int j = 0; j < 10; j++) {
						if (j == tx) continue;
						else {
							if (!prime[temp2 + j] && !check[temp2+ j]) {//소수인 경우 큐에 추가
								qu.push(make_pair(temp2 + j, cnt+1));
								check[temp2 + j] = true;
							}
						}
					}
				}
				else if (i == 1) {
					int tx = temp % 100;
					int temp2 = temp;
					tx -= tx % 10;
					temp2 -= tx;
					for (int j = 0; j < 10; j++) {
						if (j*10 == tx) continue;
						else {
							if (!prime[temp2 + j*10] && !check[temp2 + j*10]) {//소수인 경우 큐에 추가
								qu.push(make_pair(temp2 + j*10, cnt+1));
								check[temp2 + j*10] = true;
							}
						}
					}
				}
				else if (i == 2) {
					int tx = temp % 1000;
					int temp2 = temp;
					tx -= tx % 100;
					temp2 -= tx;
					for (int j = 0; j < 10; j++) {
						if (j * 100 == tx) continue;
						else {
							if (!prime[temp2 + j * 100] && !check[temp2 + j*100]) {//소수인 경우 큐에 추가
								qu.push(make_pair(temp2 + j * 100,cnt+1));
								check[temp2 + j * 100] = true;
							}
						}
					}
				}
				else {
					int tx = temp - temp % 1000;
					int temp2 = temp - tx;
					for (int j = 1; j < 10; j++) {
						if (j * 1000 == tx) continue;
						else {
							if (!prime[j * 1000 + temp2] && !check[j * 1000 + temp2]) {//소수인 경우 큐에 추가
								qu.push(make_pair(j * 1000 + temp2, cnt + 1));
								check[j * 1000 + temp2] = true;
							}
						}
					}
				}

			}
		}

	}

	return -1;
}


int main() {
	int testcase, x,y;

	cin >> testcase;

	for (int i = 2; i <= 9999; i++) {
		if (prime[i] == false) {
			for (int j = i * 2; j <= 9999; j+=i) prime[j] = true;
		}
	}

	while (testcase--) {
		cin >> x >> y;

		memset(check, false, sizeof(check));

		int ans = fun(x, y);
		if (ans == -1) cout << "Impossible\n";
		else cout << ans<<'\n';
	}
}