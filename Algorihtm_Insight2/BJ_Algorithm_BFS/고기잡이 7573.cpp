
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <queue>
#include <set>

using namespace std;

int dp[201][201];
bool check[201][201];

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < computers[i].size(); i++) {
			dp[i][j] = computers[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] != 0 && !check[i][j]) {

				queue<pair<int,int>> qu;
				qu.push(make_pair(i, j));
				while (!qu.empty()) {
					pair<int, int> temp = qu.front();
					qu.pop();

					for(int k=0;k<n;k++)

				}

			}
		}
	}

	return answer;
}

int main() {

}