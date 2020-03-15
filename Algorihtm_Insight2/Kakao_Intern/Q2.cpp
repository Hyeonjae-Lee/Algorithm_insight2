
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

int arr[100001];

bool desc(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int, int>> vec;

	int a = 0, b = 0;

	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - 48 >= 0 && s[i] - 48 <= 9) {

			b = b * 10;
			a = s[i] - 48;
			b += a;

		}
		else {
			if (b > 0) {
				arr[b]++;
				a = 0; b = 0;
			}
			flag = false;
		}
	}

	for (int i = 0; i < 100000; i++) {
		if (arr[i] > 0) {
			vec.push_back(make_pair(arr[i], i));
		}
		else break;
	}

	sort(vec.begin(), vec.end(), desc);

	for (int i = 0; i < vec.size(); i++) {
		answer.push_back(vec[i].second);
	}

	return answer;
}

int main() {
	string s = "{{123}}";

	solution(s);
}