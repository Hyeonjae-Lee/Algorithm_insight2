#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

int n, m, arr[100003], x;

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	
	int right = n, left = 1, mid = right, answer = 0;

	while (left <= right) {
		vector<pair<int, int>> vec;

		for (int i = 0; i < m; i++) vec.push_back(make_pair(arr[i] - mid, arr[i] + mid));

		bool flag = false;

		if (vec.size() == 1) {
			if (vec[0].first > 0 || vec[0].second < n) flag = true;//거리가 짧은경우
		}
		else {
			for (int i = 0; i < vec.size(); i++) {

				if (i == 0) {
					if (vec[i].first > 0) {
						flag = true; break;
					}
				}
				if (i == vec.size() - 1) {
					if (vec[i].second < n || vec[i].first > vec[i - 1].second) {
						flag = true; break;
					}
				}
				else {
					if (vec[i].first > vec[i - 1].second) {
						flag = true; break;
					}
				}

			}
		}
		if (flag) {//거리가 짧은경우
			left = mid + 1;
		}
		else {//거리가 긴경우
			right = mid - 1;
			answer = mid;
		}
		mid = (right + left) / 2;
	}

	cout << answer;
}