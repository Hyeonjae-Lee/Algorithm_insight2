
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

vector<pair<int, int>> vec;

int main() {
	int n, l;
	int x, y;

	while (n--) {
		cin>> x>>y;
		vec.push_back({ x, y });
	}

	sort(vec.begin(), vec.end());

	int answer = 0;

	for (int i = 0; i < vec.size(); i++) {
		answer += (vec[i].second - vec[i].first + 1) / l + 1;

		if (i + 1 < vec.size()) {
			if(vec[i + 1].first )
		}
	}
}