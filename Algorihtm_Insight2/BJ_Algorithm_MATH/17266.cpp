#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

int n, m, arr[100000], x;
bool check[100000];

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		//arr[x] = 1;
	}

	int right = n, left = 1, mid = (right+left)/2;
	
	while (left <= right) {
		memset(check, false, sizeof(check));
		vector<pair<int, int>> vec;

		for (int i = 0; i < m; i++) {

			int tx;

			if (arr[i] - mid < 0) tx = 0;
			else ty = arr[i] - mid;
				
			vec.push_back(make_pair(tx, ty));
		}

		bool flag = false;

		for (int i = 0; i < vec.size(); i++) {

			if (i == 0) {
				if (vec[i].first != 0) {
					flag = true; break;
				}
			}
			else if (i == vec.size() - 1) {
				if (vec[i].second < n) {
					flag = true; break;
				}
			}
			else {
				if (vec[i].first > vec[i - 1].second) {
					flag = true; break;
				}
			}

		}

		if (flag) {//거리가 짧은경우
			left = mid + 1;
		}
		else {
			right = mid;
		}
		mid = (right + left) / 2;
	}

	cout << mid;
}