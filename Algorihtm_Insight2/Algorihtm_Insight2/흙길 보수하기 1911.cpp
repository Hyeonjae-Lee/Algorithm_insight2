
/* 2015112119 이현재 */

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

vector<pair<int, int>> vec;

int main() {
	int n, l;
	int x, y;

	cin >> n >> l;

	while (n--) {
		cin>> x>>y;
		vec.push_back({ x, y });
	}

	sort(vec.begin(), vec.end());

	int answer = 0;
	int index = 0;

	for (int i = 0; i < vec.size(); i++) {
		
		index = max(index, vec[i].first);
		answer += (vec[i].second - index + l - 1) / l;
		index += ((vec[i].second - index + l - 1) / l) * l; // 인덱스는 
	}

	cout << answer;
}